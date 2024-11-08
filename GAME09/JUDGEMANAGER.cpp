#include "JUDGEMANAGER.h"
#include "SOUNDMANAGER.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "LONGNOTE.h"
#include "TAPNOTE.h"
//#include "BEAM.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09 {
	JUDGEMANAGER::JUDGEMANAGER(GAME* game) :
		GAME_OBJECT(game) {
	}
	JUDGEMANAGER::~JUDGEMANAGER() {

	}

	void JUDGEMANAGER::create() {
		JudgeMNG = game()->container()->data().judge;
		Cont = game()->rgCont();
		Sound = game()->soundMNG();
		KeyCon = game()->keyConfig();
	}

	void JUDGEMANAGER::init() {
		AnimeTime = JudgeMNG.activeTime;
		for (int i = 0; i < NUM_JUDGE; i++) {
			JudgeResult[i] = 0;
		}
		for (int i = 0; i < NUM_ACCURACY; i++) {
			Accuracy[i] = 0;
		}
		Combo = 0;
		MaxCombo = 0;
	}

	void JUDGEMANAGER::update() {
		if (AnimeTime < JudgeMNG.activeTime) {
			AnimeTime += delta;
		}
		game()->keyConfig()->update();

		autoPlay();
		//judgeNotes();
	}

	void JUDGEMANAGER::draw() {
		rectMode(CENTER);
		float ratio = AnimeTime / JudgeMNG.appearAnimeTime;
		if (ratio > 1) ratio = 1;

		//����̕���
		if (AnimeTime < JudgeMNG.activeTime) {
			float size = JudgeMNG.imgSizeMin + (JudgeMNG.imgSize - JudgeMNG.imgSizeMin) * ratio;
			image(JudgeMNG.judge[Judge].img, JudgeMNG.pos.x, JudgeMNG.pos.y, 0, size);
			size *= JudgeMNG.accImgSizeRate;
			VECTOR2 pos = JudgeMNG.pos + JudgeMNG.accOfst;
			if (Acc == FAST) {
				image(JudgeMNG.fastImg, pos.x, pos.y, 0, size);
			}
			else if (Acc == SLOW) {
				image(JudgeMNG.slowImg, pos.x, pos.y, 0, size);
			}
		}

		//debug
		fill(0);
		print(JudgeResult[0]);
		print(JudgeResult[1]);
		print(JudgeResult[2]);

		//�R���{
		//if (Combo >= 5) {
		//	float comboAnimeRatio = JudgeMNG.comboSizeMinRate + (1 - JudgeMNG.comboSizeMinRate) * ratio;
		//	game()->combo()->draw(Combo, JudgeMNG.comboPos, comboAnimeRatio);
		//}
	}

	void JUDGEMANAGER::resetCombo() {
		if (Combo > MaxCombo) {
			MaxCombo = Combo;
		}
		Combo = 0;
	}

	void JUDGEMANAGER::AccCnt(ACCURACY acc) {
		Acc = acc;
		Accuracy[acc] ++;
	}

	
	void JUDGEMANAGER::judgeNotes() {
		std::vector<NOTE*>& notes = game()->notes();
		//�m�[�c���ׂĂ����[�v
		for (auto it = notes.begin(); it != notes.end();) {
			//�^�b�v�m�[�c�Ȃ�
			if ((*it)->noteName() == NOTE::TAP) {
				//���̃m�[�c���u����Ă郌�[���������ꂽ�u�ԂȂ�
				if (KeyCon->keyTrigger((*it)->getKey().main) ||
					KeyCon->keyTrigger((*it)->getKey().sub)) {
					bool isJudge = false;
					//��ʂ̔��肩�珇�Ԃɔ���͈͓̔����m�F
					for (int i = 0; i < NUM_JUDGE; i++) {
						if (Abs((float)((*it)->getTime() - Cont->curTime())) < JudgeMNG.judge[i].time) {
							Judge = (JUDGE)i;
							if (Judge == GREAT) {
								if ((*it)->getTime() - Cont->curTime() > 0) {
									AccCnt(FAST);
								}
								else {
									AccCnt(SLOW);
								}
							}
							else {
								AccCnt(NONE);
							}
							if (Judge == MISS) {
								resetCombo();
							}
							else {
								Combo++;
							}
							JudgeResult[i]++;
							Sound->tapSound();
							AnimeTime = 0;
							//�������[����2�ȏ�̃m�[�c�������ɔ������Ȃ��悤�Ɉ�񔻒肵���牟���ĂȂ����Ƃɂ���
							if (KeyCon->keyTrigger((*it)->getKey().main)) {
								KeyCon->setTrigger((*it)->getKey().main, false);
							}
							else {
								KeyCon->setTrigger((*it)->getKey().sub, false);
							}
							delete (*it);
							it = notes.erase(it);
							isJudge = true;
							break;
						}
					}
					//��ԉ��̔���͈̔͂ɂ������Ă��Ȃ����
					if (!isJudge) {
						//���胉�C�������Ȃ�~�X
						if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							JudgeResult[MISS]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						//��O�Ȃ�X���[
						else {
							it++;
						}
					}
				}
				//�m�[�c��������ĂȂ����
				else {
					//��ԉ��̔���͈̔͂ɂ������ĂȂ��A���胉�C���̌��Ȃ�~�X
					if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
						Judge = MISS;
						AccCnt(NONE);
						resetCombo();
						JudgeResult[MISS]++;
						AnimeTime = 0;
						delete (*it);
						it = notes.erase(it);
					}
					//����ȊO�Ȃ�X���[
					else {
						it++;
					}
				}
			}
			//�����O�m�[�c�Ȃ�
			else if ((*it)->noteName() == NOTE::LONG) {
				//�n�_��������ĂȂ����
				if (!((LONGNOTE*)*it)->getPress()) {
					//�����ꂽ�u�ԂȂ�
					if (KeyCon->keyTrigger((*it)->getKey().main) ||
						KeyCon->keyTrigger((*it)->getKey().sub)) {
						bool isJudge = false;
						//��ʂ̔��肩�珇�Ԃɔ���͈͓̔����m�F
						for (int i = 0; i < NUM_JUDGE; i++) {
							if (Abs((float)((*it)->getTime() - Cont->curTime())) < JudgeMNG.judge[i].time) {
								Judge = (JUDGE)i;
								if (Judge == GREAT) {
									if ((*it)->getTime() - Cont->curTime() > 0) {
										AccCnt(FAST);
									}
									else {
										AccCnt(SLOW);
									}
								}
								else {
									AccCnt(NONE);
								}
								JudgeResult[i]++;
								//�������[����2�ȏ�̃m�[�c�������ɔ������Ȃ��悤�Ɉ�񔻒肵���牟���ĂȂ����Ƃɂ���
								if (KeyCon->keyTrigger((*it)->getKey().main)) {
									KeyCon->setTrigger((*it)->getKey().main, false);
								}
								else {
									KeyCon->setTrigger((*it)->getKey().sub, false);
								}
								isJudge = true;
								AnimeTime = 0;
								//���肪�~�X�̏ꍇ
								if (Judge == MISS) {
									delete (*it);
									it = notes.erase(it);
									//�I�_���~�X�Ȃ̂Ń~�X�̃J�E���g�𑝂₷
									JudgeResult[i]++;
									resetCombo();
									break;
								}
								//����ȊO
								else {
									Combo++;
									//�n�_�͉�����Ă܂���t���O�𗧂Ă�
									((LONGNOTE*)*it)->setPress(true);
									Sound->tapSound();
									break;
								}
							}
						}
						//���肳��ĂȂ����
						if (!isJudge) {
							//�߂��������m�[�c���~�X�ɂ���
							if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
								Judge = MISS;
								AccCnt(NONE);
								resetCombo();
								//�I�_���~�X�Ȃ̂Ń~�X�J�E���g��2���₷
								JudgeResult[MISS] += 2;
								AnimeTime = 0;
								delete (*it);
								it = notes.erase(it);
							}
							else {
								it++;
							}
						}
					}
					//�����ꂽ�u�Ԃ���Ȃ��Ȃ�
					else {
						//�߂��������m�[�c���~�X�ɂ���
						if ((*it)->getTime() - Cont->curTime() < -JudgeMNG.judge[MISS].time) {
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							//�I�_���~�X�Ȃ̂Ń~�X�J�E���g��2���₷
							JudgeResult[MISS] += 2;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						else {
							it++;
						}
					}
				}
				//�n�_��������Ă�Ƃ�
				else {
					//����������Ă�Ƃ�
					if (KeyCon->keyPress((*it)->getKey().main) ||
						KeyCon->keyPress((*it)->getKey().sub)) {
						//�I�_���߂��ĉ�����Ă�����PERFECT
						if ((*it)->getTimeE() - Cont->curTime() < 0) {
							Judge = PERFECT;
							AccCnt(NONE);
							Combo++;
							JudgeResult[PERFECT]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
						else {
							it++;
						}
					}
					//����������ĂȂ���(�����ŕK�����ł���̂Ŏ����I�ɂ͗����ꂽ�u��)
					else {
						bool isJudge = false;
						//��ʂ��画��
						for (int i = 0; i < NUM_JUDGE; i++) {
							if (Abs((float)((*it)->getTimeE() - Cont->curTime())) < JudgeMNG.judge[i].time) {
								Judge = (JUDGE)i;
								AccCnt(NONE);
								if (Judge == MISS) {
									resetCombo();
								}
								else {
									Combo++;
								}
								JudgeResult[i]++;
								AnimeTime = 0;
								delete (*it);
								it = notes.erase(it);
								isJudge = true;
								break;
							}
						}
						//����͈̔͊O(�܂�Ƃ�ł��Ȃ������������Ƃ�)
						if (!isJudge) {
							//���R�~�X
							Judge = MISS;
							AccCnt(NONE);
							resetCombo();
							JudgeResult[MISS]++;
							AnimeTime = 0;
							delete (*it);
							it = notes.erase(it);
						}
					}
				}
			}
			//����ȊO�̃m�[�c(���͂Ȃ�)
			else {
				it++;
			}
		}
	}
	

	void JUDGEMANAGER::autoPlay() {
		std::vector<NOTE*>& notes = game()->notes();
		//�m�[�c���ׂĂ����[�v
		for (auto it = notes.begin(); it != notes.end();) {
			//�^�b�v�m�[�c�Ȃ�
			if ((*it)->noteName() == NOTE::TAP) {
				//���胉�C�����z������
				if ((*it)->getTime() - Cont->curTime() < 0) {
					Judge = PERFECT;
					Combo++;
					JudgeResult[PERFECT]++;
					Sound->tapSound();
					AnimeTime = 0;
					delete (*it);
					it = notes.erase(it);
				}
				else {
					it++;
				}
			}
			//�����O�m�[�c�Ȃ�
			else if ((*it)->noteName() == NOTE::LONG) {
				//�n�_��������ĂȂ����
				if (!((LONGNOTE*)*it)->getPress()) {
					//�n�_�����胉�C�����z������
					if ((*it)->getTime() - Cont->curTime() < 0) {
						Judge = PERFECT;
						Combo++;
						JudgeResult[PERFECT]++;
						Sound->tapSound();
						AnimeTime = 0;
						//�n�_�͉�����Ă܂���t���O�𗧂Ă�
						((LONGNOTE*)*it)->setPress(true);
					}
					else {
						it++;
					}
				}
				//�n�_��������Ă�Ƃ�
				else {
					//�I�_���߂�����
					if ((*it)->getTimeE() - Cont->curTime() < 0) {
						Judge = PERFECT;
						Combo++;
						JudgeResult[PERFECT]++;
						AnimeTime = 0;
						delete (*it);
						it = notes.erase(it);
					}
					else {
						it++;
					}
				}
			}
			//����ȊO�̃m�[�c(���͂Ȃ�)
			else {
				it++;
			}
		}
	}
}