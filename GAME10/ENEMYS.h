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
		int rightMx;//�摜�̉E��
		int my;//�o���ʒu�����߂邽�߂�Y���ړ���
		int callIntervalDist;
		int initIntervalDist;//�����l
		int sumTime;
		int hitDamage;
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
	void draw(int EnemyKind);
	DATA& uniEnemy() { return Enemy; }//���ʃf�[�^
	int EnemiesHitDamage() { return Enemy.hitDamage; }
	int EnemiesLaneKind(int i) { return Enemies[i].lane; }
	float& EnemiesLeft(int i) { return Enemies[i].pos.x; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	float EnemiesRight(int i) { return Enemies[i].pos.x + (float)Enemy.rightMx; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	int& EnemiesLane(int i) { return Enemies[i].lane; }//�G�ЂƂ�ЂƂ��lane�f�[�^
};

