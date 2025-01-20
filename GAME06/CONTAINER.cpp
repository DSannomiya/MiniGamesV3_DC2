#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
namespace GAME06{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}

	void CONTAINER::setData() {
		//�^�C�g���f�[�^
		Data.title.backgroundColor = { 128,128,128 };
		Data.title.nameSize = 150;
		Data.title.nameColor = { 0,0,0 };
		Data.title.namePos = { 650,550 };
		Data.title.name = "�X�i�C�p�[";
		Data.title.guidanceSize = 50;
		Data.title.guidanceColor = { 0,0,0 };
		Data.title.guidancePos = { 550,750 };
		Data.title.guidance = "SPACE�L�[�ŃX�^�[�g";
		//�X�e�[�W�f�[�^
		Data.stage.backgroundColor = { 128,128,128 };
		Data.stage.curTimer = 0.0f;
		Data.stage.initTimer = 30.0f;
		Data.stage.hitCounter = 0;
		//���U���g�f�[�^
		//CRank
		Data.rank_C.backgroundColor = { 128,128,128 };
		Data.rank_C.nameSize = 150;
		Data.rank_C.nameColor = { 0,225,225 };
		Data.rank_C.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rank_C.name = "C";
		Data.rank_C.guidanceSize = 50;
		Data.rank_C.guidanceColor = { 0,0,0 };
		Data.rank_C.guidancePos = { 550,750 };
		Data.rank_C.guidance = "SPACE�L�[�Ń^�C�g���ɖ߂�";
		//BRank
		Data.rank_B.backgroundColor = { 128,128,128 };
		Data.rank_B.nameSize = 150;
		Data.rank_B.nameColor = { 0,60,240 };
		Data.rank_B.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rank_B.name = "B";
		Data.rank_B.guidanceSize = 50;
		Data.rank_B.guidanceColor = { 0,0,0 };
		Data.rank_B.guidancePos = { 550,750 };
		Data.rank_B.guidance = "SPACE�L�[�Ń^�C�g���ɖ߂�";
		//ARank
		Data.rank_A.backgroundColor = { 128,128,128 };
		Data.rank_A.nameSize = 150;
		Data.rank_A.nameColor = { 235,0,0 };
		Data.rank_A.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rank_A.name = "A";
		Data.rank_A.guidanceSize = 50;
		Data.rank_A.guidanceColor = { 0,0,0 };
		Data.rank_A.guidancePos = { 550,750 };
		Data.rank_A.guidance = "SPACE�L�[�Ń^�C�g���ɖ߂�";
		//SRank
		Data.rank_S.backgroundColor = { 128,128,128 };
		Data.rank_S.nameSize = 150;
		Data.rank_S.nameColor = { 220,0,110 };
		Data.rank_S.namePos = { width / 2 - 75,height / 2 + 75 };
		Data.rank_S.name = "S";
		Data.rank_S.guidanceSize = 50;
		Data.rank_S.guidanceColor = { 0,0,0 };
		Data.rank_S.guidancePos = { 550,750 };
		Data.rank_S.guidance = "SPACE�L�[�Ń^�C�g���ɖ߂�";
		//�����f�[�^
		Data.judgeList.textColor = { 0,0,0 };
		Data.judgeList.textSize = 40;
		Data.judgeList.pos_S = { 0,40 };
		Data.judgeList.str_S = "S:15���ȏ�";
		Data.judgeList.pos_A = { 0,80 };
		Data.judgeList.str_A = "A:10�`14��";
		Data.judgeList.pos_B = { 0,120 };
		Data.judgeList.str_B = "B:5�`9��";
		Data.judgeList.pos_C = { 0,160 };
		Data.judgeList.str_C = "C:0�`4��";
		//�v���C���[�f�[�^
		Data.player.pos = { 100,height / 2 };
		Data.player.radius = 50;
		Data.player.advSpeed = 120;
		Data.player.fillColor = { 0,225,0 };
		Data.player.hp = 100;
		//�G�l�~�[�f�[�^
		Data.enemy.pos = { width - 150,height / 2 };
		Data.enemy.radius = 100;
		Data.enemy.fillColor = { 235,0,185 };
		Data.enemy.hp = 150;
	}

	void CONTAINER::loadGraphic() {

	}
}