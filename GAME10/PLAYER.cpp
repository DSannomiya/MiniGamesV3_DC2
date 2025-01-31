#include "PLAYER.h"
#include"GAME10_GAME.h"
#include"STAGE.h"
#include"CONTAINER.h"
PLAYER::PLAYER(class GAME10_GAME* game):GAME_OBJECT10(game){
}
PLAYER::~PLAYER(){}
void PLAYER::init(){
	Player = game()->container()->player();
	game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->setHp(Player.hp);
}

void PLAYER::stageGoal() {
	Player.Pos.x = NULL;
}

void PLAYER::create(){
	Player = game()->container()->player();
}

void PLAYER::update() {
	if ((int)Player.Pos.x != (int)Player.Opos.x) {//�v���C���[���S�[���t�߂ɋ߂Â�����A�v���C���[�������o��
		playerMove();
		for (int bulletsKind = GAME10_GAME::HANDGUNBULLET_ID; bulletsKind < Player.weaponHaveNum; bulletsKind++) {
			game()->bullets(Player.weaponKind[bulletsKind])->BulletPMove(Player.speed);
		}
	}
	else if (Player.Pos.x > Player.Opos.x) {
		Player.Pos.x = Player.Opos.x;
	}
	Player.hp = game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->GetHp(NULL);

	//�v���C���[�̐i�񂾋���
	if (game()->distance()->sumDist() < game()->distance()->NSCDist()) {
		game()->distance()->distcnt();
	}
	else {
		if ((int)Player.Pos.x == (int)Player.Opos.x) {
			game()->distance()->loopCnt();
		}
		game()->distance()->errorCorrection();
	}

	//����֘A
	if (isPress(KEY_A) && Player.speed >= Player.minSpeed && Player.Pos.x == Player.Opos.x) {
		Player.speed -= Player.gearSpeed;
	}
	else if (Player.speed <= Player.maxSpeed) {
		Player.speed += Player.gearSpeed;
	}
	if (isTrigger(KEY_W) && Player.nowLane > 0 && Player.Pos.x == Player.Opos.x) {
		Player.nowLane--;
		Player.Pos.y -= Player.Pmy;
	}
	if (isTrigger(KEY_S) && Player.nowLane < Player.LaneMax-1 && Player.Pos.x == Player.Opos.x) {
		Player.nowLane++;
		Player.Pos.y += Player.Pmy;
	}
	for (int i = 0; Player.weaponHaveNum> i; i++) {
		game()->bullets(Player.weaponKind[i])->update();
	}

	launch();
	collision();
}

void PLAYER::getWeapons(int weaponKind) {
	Player.weaponKind[Player.weaponHaveNum] = weaponKind;
	Player.weaponHaveNum++;
}

void PLAYER::collision() {
	if (Player.invisibleTime <= 0) {
		for (int i = 0; game()->enemies()->EnemiesNum() > i; i++) {
			if (Player.Pos.x + Player.ImgRight >= game()->enemies()->EnemiesLeft(i)
				&& Player.Pos.x <= game()->enemies()->EnemiesRight(i)
				&& Player.nowLane == game()->enemies()->EnemiesLane(i)) {
				game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->getDamage(game()->enemies()->EnemiesHitDamage());
				Player.invisibleTime = Player.initInvisibleTime;
			}
		}
		for (int i = 0; game()->objects()->objectNum() > i; i++) {
			if (Player.Pos.x + Player.ImgRight > game()->objects()->ObjectsLeft(i)
				&& Player.Pos.x <= game()->objects()->ObjectsRight(i)
				&& Player.nowLane == game()->objects()->ObjectsLane(i)) {
				game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->getDamage(game()->objects()->objectsHitDamage());
				Player.invisibleTime = Player.initInvisibleTime;
			}
		}
	}
	else {
		Player.invisibleTime -= delta;
	}
}

void PLAYER::playerMove() {
	Player.Pos.x += Player.speed;
}

void PLAYER::levelUp() {
	Player.level++;
}

void PLAYER::launch(){
	for (int i = 0; i < Player.weaponHaveNum; i++) {
		game()->weapons(Player.weaponKind[i])->launch(Player.Pos, Player.nowLane);
	}
}

void PLAYER::draw(){
	Player.nowImage = Player.nowFlame / Player.nextFlame;
	if (Player.invisibleTime <= 0
		|| 0 != Player.invisibleTime % 20) {
		image(Player.pImg[Player.nowImage], Player.Pos.x, Player.Pos.y);
	}
	Player.nowFlame++;
	if (Player.nowFlame >= Player.nextFlame * Player.imgNum) {
		Player.nowFlame = false;
	}
	image(Player.timeImage, Player.Tpos.x, Player.Tpos.y);
	fill(255);
	textSize(40);
	game()->Hp_gauge(GAME10_GAME::PLAYERHP_ID)->draw();
	for (int i = 0; i < Player.weaponHaveNum; i++) {
		game()->weapons(Player.weaponKind[i])->draw();
	}
}