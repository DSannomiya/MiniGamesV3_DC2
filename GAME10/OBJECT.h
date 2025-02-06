#pragma once
#include "GAME_OBJECT10.h"
#include "../../libOne/inc/libOne.h"
class OBJECT :public GAME_OBJECT10
{
public:
	//���ʃf�[�^
	struct DATA
	{
		int hitSound;
		int Img[3];
		int totalNum;//�G�̍ő吔
		int nowNum;
		int speed;//�X�e�[�W���x�Ɉˑ�
		int ohp;//Hp
		int upHp;//���x�����ƂɃA�b�v����Hp
		int rightMx;//�摜�̉E��
		int my;//�o���ʒu�����߂邽�߂�Y���ړ���
		int callIntervalDist;
		int initIntervalDist;//�����l
		int sumTime;
		int hitDamage;
		int shortTime;//�Z�����鎞��
		int level;
		int sumDestroy;//�|������
		int downSound;
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
	void levelUp();
	void kill(int i);
	void AllKill();
	void draw(int ObjectKind);
	int objectNum() { return Object.nowNum; }
	const int objectsHitDamage() { return Object.hitDamage; }
	VECTOR2 objectPos(int i) { return Objects[i].pos; }
	float& ObjectsLeft(int i) { return Objects[i].pos.x; }//��Q���ЂƂ��̈ʒu�f�[�^(��)
	float ObjectsRight(int i) { return Objects[i].pos.x + (float)Object.rightMx; }//��Q���ЂƂ��̈ʒu�f�[�^(��)
	int& ObjectsLane(int i) { return Objects[i].lane; }//��Q���ЂƂ���lane�f�[�^
	const int& sumDestroy() { return Object.sumDestroy; }
	void DestroyReset() { Object.sumDestroy = 0; }
};

