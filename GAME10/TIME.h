#pragma once
#include "GAME10_GAME.h"
class TIME :public GAME_OBJECT10
{
public:
	struct DATA {
		int time = 0;
		int frame = 0;
		int rewindTime = 0;//�A�C�e�����Ƃ������̉񕜎���
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
	void rewind();//�A�C�e���𓾂��Ƃ��Ɏ��ԉ�
	void draw();
};

