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
	playSound(Stage.sound);
	Stage = game()->container()->stage();
	game()->player()->init();
	game()->time()->init();
	game()->distance()->init();
	game()->enemies()->init();
	game()->objects()->init();
	game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->init();
	game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->init();
	game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->init();
}
void STAGE::goalStage() {
	Stage.bworldX = NULL;
	Stage.fworldX = NULL;
	game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->AllKill();//�e�ۂ�S������
	game()->bullets(GAME10_GAME::SHOTGUN_ID)->AllKill();//�e�ۂ�S������
	game()->enemies()->AllKill();//�G��S������
	game()->objects()->AllKill();//�I�u�W�F�N�g��S������
	game()->player()->stageGoal();
}
void STAGE::appear() {
	game()->enemies()->appear();
	game()->objects()->appear();
}
void STAGE::update() {
	//�X�e�[�W�̋����X�N���[���i�X�s�[�h�̓v���C���[�̃X�s�[�h�̈ˑ�����j
	if (Stage.gPos.x - Stage.fworldX > width / 2 
		&& (int)game()->player()->playerOpos().x == (int)game()->player()->playerPos().x) {
		Stage.frontMx = game()->player()->playerSpeed();
		Stage.fworldX += Stage.frontMx;
		if (game()->player()->playerSpeed() >= Stage.backMx) {
			Stage.bworldX += game()->player()->playerSpeed() - Stage.backMx;
		}
		game()->time()->timeCount();//�����X�N���[�����̂ݎ��Ԃ��i��
		if(Stage.gPos.x - Stage.fworldX > width ){
			appear();//�G�̏o��������������
		}
	}
	//�S�[���e�[�v����ʂ̒����ɗ������A�v���C���[���������悤�ɂ��邽�߂ɏ��������v���C���[�𓮂����B
	else if(game()->player()->playerOpos().x == game()->player()->playerPos().x){
		game()->player()->playerMove();
	}
	
	//�v���C���[��goal�����Ƃ��̏���
	if (game()->player()->playerPos().x > width) {
		goalStage();
	}
	//�G�l�~�[�̃X�s�[�h��ς���i�v���C���[�̑��x�ˑ��̂��߁j
	game()->enemies()->update();
	game()->player()->update();
	game()->objects()->update();
}
void STAGE::create() {
	Stage = game()->container()->stage();
	game()->player()->create();
	game()->enemies()->create();
	game()->objects()->create();
	game()->distance()->create();
	game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->create();
	game()->Hp_gauge(GAME10_GAME::ENEMYHP_ID)->create();
	game()->Hp_gauge(GAME10_GAME::OBJECTHP_ID)->create();
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
	if (Stage.gPos.x - Stage.fworldX < width) {
		image(Stage.GoalImg, Stage.gPos.x - Stage.fworldX, Stage.gPos.y);
	}

	for (int LNum = 0; Stage.LaneNum > LNum; LNum++) {//�`��̑O��
		layer(LNum);
	}

	game()->time()->draw();
	Stage.DestNum = game()->player()->levelUpBorder() - (game()->enemies()->sumDestroy() + game()->objects()->sumDestroy());
	game()->distance()->draw();
	fill(255);
	textSize(Stage.DestTextSize);
	text("LEVEL UP�܂ł���" +(let)Stage.DestNum +(let)"��", Stage.DestPos.x, Stage.DestPos.y);
}
void STAGE::sound() {
	playSound(Stage.sound);
}
void STAGE::layer(int drawLane) {
	for (int ENum = 0; ENum < game()->enemies()->EnemiesNum(); ENum++) {
		if (drawLane == game()->enemies()->EnemiesLane(ENum)) {
			game()->enemies()->draw(ENum);
		}
	}	

	for (int Onum = 0; Onum < game()->objects()->objectNum(); Onum++) {
		if (drawLane == game()->objects()->ObjectsLane(Onum)) {
			game()->objects()->draw(Onum);
		}
	}

	for (int HBNum = 0; game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->BulletNum() > HBNum;HBNum++) {
		if (drawLane == game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->bulletLane(HBNum)) {
			game()->bullets(GAME10_GAME::HANDGUNBULLET_ID)->draw(HBNum);
		}
	}

	for (int SBNum = 0; game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->BulletNum() > SBNum; SBNum++) {
		if (drawLane == game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->bulletLane(SBNum)) {
			game()->bullets(GAME10_GAME::SHOTGUNBULLET_ID)->draw(SBNum);
		}
	}

	for(int MBNum = 0;game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->BulletNum()> MBNum;MBNum++){
		if (drawLane == game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->bulletLane(MBNum)) {
			game()->bullets(GAME10_GAME::MISSILEBULLET_ID)->draw(MBNum);
		}
	}

	if (game()->player()->playerNowLane() == drawLane) {
		game()->player()->draw();
	}
}
void STAGE::nextScene() {
	//���x���A�b�v�����ꍇ�Aselect��
	if (game()->enemies()->sumDestroy() + game()->objects()->sumDestroy() >= game()->player()->levelUpBorder()) {
		game()->scenes(GAME10_GAME::SELECT_ID)->sound();
		game()->changeScene(GAME10_GAME::SELECT_ID);
	}
	//���U���g��
	if (game()->time()->nowTime() - game()->time()->timeFlame() <= NULL - 1
		|| game()->player()->playerHp()<= NULL
		|| (game()->distance()->clearDist() <= game()->distance()->sumDist()
		&& game()->player()->playerPos().x>=width)) {
		stopSound(Stage.sound);
		game()->changeScene(GAME10_GAME::RESULT_ID);
		game()->scenes(GAME10_GAME::RESULT_ID)->sound();
	}
}
