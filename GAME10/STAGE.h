#pragma once
#include "SCENE.h"
#include "../../libOne/inc/libOne.h"
class STAGE:public SCENE
{
public:
	struct DATA {
		//�w�i�Ƃ��̂������̃f�[�^
		VECTOR2 imgPos;
		int stageImg = 0;
		VECTOR2 frontPos;
		int fImgNum = 4;
		int frontImg = 0;
		VECTOR2 backPos;
		int backImg = 0;
		float ImgLen = 0.0f;
		int bImgNum = 0;
		float backMx = 0.0f;
		float frontMx = 0.0f;
		//�����X�N���[���p�̕ϐ�
		float bworldX = 0;
		float fworldX = 0;
		float stopFlag = false;
		int frontImgNumber;//�摜�̑O��
		int NofrontImg;

		//lane�֘A
		int opy = 0;
		int opx = 0;
		struct LANE {
			int LaneImg = 0;
			VECTOR2 Pos = 0;
			int LaneNumber = 0;
		};
		LANE* Lanes = 0;
		int LaneNum = 0;
		int LaneLenNum = 0;//lane�̒��������߂����
		int My = 0;
		//goaltape�֘A
		int GoalImg = 0;
		int GoalBoardImg = 0;
		VECTOR2 gPos = 0;//goal�̈ʒu
		VECTOR2 bPos = 0;//�Ŕ̈ʒu
	};
private:
	DATA Stage;
public:
	STAGE(class GAME10_GAME* game);
	~STAGE();
	void init();
	void goalStage();
	void appear();
	void update();
	void create();
	void draw();
	void layer(int drawLane);
	void nextScene();
	int speed() { return Stage.frontMx; }
};

