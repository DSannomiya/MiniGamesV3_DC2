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
		int destroy;//�|���ꂽ��
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
	const DATA& uniEnemy() { return Enemy; }//���ʃf�[�^
	const int EnemiesHitDamage() { return Enemy.hitDamage; }
	const int EnemiesLaneKind(int i) { return Enemies[i].lane; }
	const float& EnemiesLeft(int i) { return Enemies[i].pos.x; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	const float EnemiesRight(int i) { return Enemies[i].pos.x + (float)Enemy.rightMx; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	const int& EnemiesLane(int i) { return Enemies[i].lane; }//�G�ЂƂ�ЂƂ��lane�f�[�^
};

