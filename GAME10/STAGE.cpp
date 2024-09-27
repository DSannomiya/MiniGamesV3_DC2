#include "STAGE.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
#include"GAME10_GAME.h"
#include"WEAPONS.h"
STAGE::STAGE(GAME10_GAME* game) :SCENE(game) {}
STAGE::~STAGE() {
}
void STAGE::init() {
	Stage = game()->container()->stage();
	game()->player()->init();
}
void STAGE::goalStage() {
	Stage.bworldX = NULL;
	Stage.fworldX = NULL;
	game()->player()->stageGoal();
}
void STAGE::update() {
	//�X�e�[�W�̋����X�N���[���i�X�s�[�h�̓v���C���[�̃X�s�[�h�̈ˑ�����j
	if (Stage.gPos.x - Stage.fworldX > width / 2 
		&& (int)game()->player()->playerData().Opos.x == (int)game()->player()->playerData().Pos.x) {
		Stage.fworldX += game()->player()->playerData().speed;
		if (game()->player()->playerData().speed >= Stage.backMx) {
			Stage.bworldX += game()->player()->playerData().speed - Stage.backMx;
		}
	}
	//�S�[���e�[�v����ʂ̒����ɗ������A�v���C���[���������悤�ɂ��邽�߂ɏ��������v���C���[�𓮂����B
	else if(game()->player()->playerData().Opos.x == game()->player()->playerData().Pos.x){
		game()->player()->playerMove();
	}

	//�v���C���[��goal�����Ƃ��̏���
	if (game()->player()->playerData().Pos.x > width) {
		goalStage();
	}
	game()->player()->update();
}
void STAGE::create() {
	Stage = game()->container()->stage();
	game()->player()->create();
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
	game()->player()->draw();
	fill(255);
}
void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME10_GAME::RESULT_ID);
	}
}
