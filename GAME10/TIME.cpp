#include "TIME.h"
#include"GAME10_GAME.h"
#include"CONTAINER.h"
#include "../../libOne/inc/libOne.h"
TIME::TIME(class GAME10_GAME* game):GAME_OBJECT10(game){
}
TIME::~TIME(){
}

void TIME::create() {
	Time = game()->container()->time();
}

void TIME::init(){
	Time = game()->container()->time();
}

void TIME::timeCount(){
	if (isPress(KEY_A)) {
		Time.time--;
		Time.time--;
		Time.time--;//�O�{�̑��x�Ői��
	}
	else {
		Time.time--;
	}
}

void TIME::goalRewind() {
	Time.time += 
}

void TIME::rewind(int Enemytype){
	if (Enemytype == GAME10_GAME::ENEMY_ID) {//�G��|�����ꍇ�Q�b�{
		Time.time += Time.rewindTimeE;
	}
	else if (Enemytype == GAME10_GAME::OBJECT_ID) {//�I�u�W�F�N�g��|�����ꍇ3�b�{
		Time.time += Time.rewindTimeO;
	}
}

void TIME::draw() {
	textSize(70);
	if (isPress(KEY_A)) {
		fill(Time.dengerRed);
	}
	else {
		fill(255);
	}
		text(Time.time/Time.frame,Time.Pos.x,Time.Pos.y);
}