#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class ENEMYS :public GAME_OBJECT10
{
public:
	//���ʃf�[�^
	struct DATA
	{
		int Img[3];
		int totalNum;//�G�̍ő吔
		int nowNum;
		int speed;//�X�e�[�W���x�Ɉˑ�
		int ohp;//Hp
		int my;//�o���ʒu�����߂邽�߂�Y���ړ���
		int callIntervalDist;
		int initIntervalDist;//�����l
		int sumTime;
		int shortTime;//�Z�����鎞��
		int level;
		VECTOR2 opos;
	};
private:
	DATA Enemy;
public:
	//�P�̃f�[�^
	struct ENEMY {
		VECTOR2 pos;
		int Img;
		int hp;
		int level;
		int lane;
	};
private:
	ENEMY* Enemies;
public:
	ENEMYS(class GAME10_GAME* game);
	~ENEMYS();
	void init();
	void create();
	void update();
		void appear();//�o�������邽�߂̂��
		void move();
		void collision();
	void kill(int i);
	void AllKill();
	void draw();
	DATA& uniEnemy() { return Enemy; }
};

