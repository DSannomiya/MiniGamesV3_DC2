#pragma once
#include "GAME10_GAME.h"
class BULLETS :public GAME_OBJECT10
{
public:
	struct DATA {
		int BulletSmx;//�e���v���C���[�̑O����o�����߂ɏ����ړ�������ׂ̒l
		int totalNum;
		int curNum;
		int img;
		int imgShadow;
		int Bmy;//�e�ۂ̈ʒu
		int RightX;//�摜�̉E��
		int LaneMax;
		float speed;
		float upSpeed;//���x�㏸
		float maxSpeed;//�ő�X�s�[�h
		int upFlame;
		int nowFlame;
		float cRadius;
		int ImgHalf;
		int bulletShadowMy;
		int BulletNum;
		int EPGap;//�G�ƃv���C���[�̉摜�̑傫���̍�
		int shotSound;
	};
protected:
	void SetBullets(const BULLETS::DATA& data);
	//���ʃf�[�^
	DATA Bullet;
private:
	//�P�̃f�[�^�z��
	struct BULLET {
		VECTOR2 pos;
		VECTOR2 vec;
		int Lane;
		//MISSILE�̈ړ��p�̂��
		float my;
		int nearLane;
		float nearEy;//�߂��G�̍���
	};
protected:
	BULLET* Bullets;
public:
	BULLETS(class GAME10_GAME* game);
	~BULLETS();
	void init();
	virtual void create() {};
	virtual void launch(const VECTOR2& pos,float speed,int lane);
	virtual void update();
	void kill(int i);
	void AllKill();
	virtual void draw(int bulletKind);
	void BulletPMove(float PlayerSpeed);
	int BulletNum() { return Bullet.curNum; }
	float bulletLeft(int i) { return Bullets[i].pos.x; }
	float BulletRight(int i) { return Bullets[i].pos.x + Bullet.RightX; }
	int bulletLane(int i) { return Bullets[i].Lane; }
};

