#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class OBJECT :public GAME_OBJECT10
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
		int shortTime;//�Z�����鎞��
		int level;
		int sumDestroy;//�|������
		VECTOR2 opos;
	};
private:
	DATA Object;
public:
	//�P�̃f�[�^
	struct OBJECTS {
		VECTOR2 pos;
		int Img;
		int hp;
		int level;
		int lane;
	};
private:
	OBJECTS* Objects;
public:
	OBJECT(class GAME10_GAME* game);
	~OBJECT();
	void init();
	void create();
	void update();
	void appear();//�o�������邽�߂̂��
	void move();
	void collision();
	void kill(int i);
	void AllKill();
	void draw(int ObjectKind);
	DATA& uniObject() { return Object; }//���ʃf�[�^
	float& ObjectsLeft(int i) { return Objects[i].pos.x; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	float ObjectsRight(int i) { return Objects[i].pos.x + (float)Object.rightMx; }//�G�ЂƂ�ЂƂ�̈ʒu�f�[�^(��)
	int& ObjectsLane(int i) { return Objects[i].lane; }//�G�ЂƂ�ЂƂ��lane�f�[�^
};

