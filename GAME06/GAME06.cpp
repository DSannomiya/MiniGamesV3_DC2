#include "../../libOne/inc/input.h"
#include "../MAIN//MAIN.h"
#include "TITLE.h"
#include "STAGE.h"
#include "RANK_C.h"
#include "RANK_B.h"
#include "RANK_A.h"
#include "RANK_S.h"
#include "JUDGE_LIST.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "GAME06.h"
//�d�l
//�^�C�g���u�X�i�C�p�[�v
//�X�e�[�W
//�@�v���C���[�@�u�㉺�̈ړ��v�Ɓu�e�̔��ˁv�e�͈ꔭ���˂����炻�̒e��������܂Ŕ��˕s�\�ɂ���@���˂��ꂽ�e�͓I�ɓ����邩��ʊO�ɏo�������
//�@�G(�I) �@�u�㉺�̈ړ��v�Ɓu���x�̕ω��v
//�@�������ԁ@30�b
//���U���g�@�I�ɓ����������ɉ�����C�`S�����N��\������@C�`S�����N�̔���������ɕ\������

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[RANK_C_ID] = new RANK_C(this);
		Scenes[RANK_B_ID] = new RANK_B(this);
		Scenes[RANK_A_ID] = new RANK_A(this);
		Scenes[RANK_S_ID] = new RANK_S(this);
		JudgeList = new JUDGE_LIST(this);
		CurSceneId = TITLE_ID;
		Player = new PLAYER(this);
		Enemy = new ENEMY(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[RANK_C_ID]->create();
		Scenes[RANK_B_ID]->create();
		Scenes[RANK_A_ID]->create();
		Scenes[RANK_S_ID]->create();
		JudgeList->create();
		Player->create();
		Enemy->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Enemy;
		delete Player;
		delete JudgeList;
		for (int i = 0; i < TOTAL_SCENES_ID; ++i) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::changeScene(SCENE_ID nextSceneId) {
		CurSceneId = nextSceneId;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
