#include "STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
#include"GAME10_GAME.h"
#include"HANDGUN_BULLETS.h"
#include"ENEMYS.h"
#include"WEAPONS.h"
STAGE::STAGE(GAME10_GAME* game) :SCENE(game) {}
STAGE::~STAGE() {
}
void STAGE::init() {
	Stage = game()->container()->stage();
	game()->player()->init();
	game()->time()->init();
	game()->handgunBullets()->init();
}
void STAGE::goalStage() {
	Stage.bworldX = NULL;
	Stage.fworldX = NULL;
	game()->handgunBullets()->AllKill();//�e�ۂ�S������
	game()->enemies()->AllKill();//�G��S������
	game()->player()->stageGoal();
}
void STAGE::update() {
	//�X�e�[�W�̋����X�N���[���i�X�s�[�h�̓v���C���[�̃X�s�[�h�̈ˑ�����j
	if (Stage.gPos.x - Stage.fworldX > width / 2 
		&& (int)game()->player()->playerData().Opos.x == (int)game()->player()->playerData().Pos.x) {
		Stage.frontMx = game()->player()->playerData().speed;
		Stage.fworldX += Stage.frontMx;
		if (game()->player()->playerData().speed >= Stage.backMx) {
			Stage.bworldX += game()->player()->playerData().speed - Stage.backMx;
		}
		game()->time()->timeCount();//�����X�N���[�����̂ݎ��Ԃ��i��
	}
	//�S�[���e�[�v����ʂ̒����ɗ������A�v���C���[���������悤�ɂ��邽�߂ɏ��������v���C���[�𓮂����B
	else if(game()->player()->playerData().Opos.x == game()->player()->playerData().Pos.x){
		game()->player()->playerMove();
	}

	//�v���C���[��goal�����Ƃ��̏���
	if (game()->player()->playerData().Pos.x > width) {
		goalStage();
	}
	//�G�l�~�[�̃X�s�[�h��ς���i�v���C���[�̑��x�ˑ��̂��߁j
	game()->player()->update();
	game()->enemies()->update();
	game()->handgunBullets()->update();
}
void STAGE::create() {
	Stage = game()->container()->stage();
	game()->player()->create();
	game()->enemies()->create();
	game()->PlayerHp_gauge()->create();
}
void STAGE::draw() {
	clear(255);
	printSize(200);
	image(Stage.stageImg, Stage.imgPos.x, Stage.imgPos.y);
	for (int i = 0; i < Stage.bImgNum; i++) {
		image(Stage.backImg, (Stage.backPos.x + Stage.ImgLen * i) - Stage.bworldX, Stage.backPos.y);
	}
	for (int i = 0; i < Stage.fImgNum; i++) {
		image(Stage.frontImg, (Stage.frontPos.x + Stage.ImgLen * i) - Stage.fworldX, Stage.frontPos.y);
	}
	for (int j = 0; j < Stage.LaneLenNum; j++) {
		for (int i = 0; i < Stage.LaneNum; i++) {
			image(Stage.Lanes[i].LaneImg, (Stage.Lanes[i].Pos.x + width * j) - Stage.fworldX, Stage.Lanes[i].Pos.y);
		}
	}
	image(Stage.GoalImg, Stage.gPos.x - Stage.fworldX, Stage.gPos.y);
	game()->enemies()->draw();
	game()->player()->draw();
	game()->time()->draw();
	game()->handgunBullets()->draw();
	fill(255);
}
void STAGE::nextScene() {
	if (game()->time()->nowTime() <= NULL) {
		game()->changeScene(GAME10_GAME::RESULT_ID);
	}
}
