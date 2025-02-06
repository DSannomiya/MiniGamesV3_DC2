#pragma once
#include "GAME10_GAME.h"
class TIME :public GAME_OBJECT10
{
public:
	struct DATA {
		int time = 0;
		int frame = 0;
		int rewindTimeE = 0;//�G��|�������̉񕜎���(�X�g���X)
		int rewindTimeO = 0;//�I�u�W�F�N�g��|�������̉񕜎���
		int rewindTimeG = 0;//goal�����Ƃ��̎��ԉ��Z
		COLOR dengerRed;
		VECTOR2 Pos;
	};
private:
	DATA Time;
public:
	TIME(class GAME10_GAME* game);
	~TIME();
	void create();
	void init();
	void timeCount();
	void goalRewind();
	void rewind(int Enemytype);//�G��|�������Ɏ��ԉ�
	void draw();
	int timeFlame() { return Time.frame; }
	int nowTime() { return Time.time; }
};

