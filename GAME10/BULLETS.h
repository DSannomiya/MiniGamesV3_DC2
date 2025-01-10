#pragma once
#include "GAME10_GAME.h"
class BULLETS :public GAME_OBJECT10
{
public:
	struct DATA {
		int totalNum;
		int curNum;
		int img;
		int imgShadow;
		int Bmy;//�e�ۂ̈ʒu
		int RightX;//�摜�̉E��
		int LaneMax;
		float speed;
		float cRadius;
		int ImgHalf;
		int BulletNum;
	};
protected:
	void SetBullets(const BULLETS::DATA& data);
private:
	//���ʃf�[�^
	DATA Bullet;
	//�P�̃f�[�^�z��
	struct BULLET {
		VECTOR2 pos;
		VECTOR2 vec;
		int Lane;
	};
	BULLET* Bullets;
public:
	BULLETS(class GAME10_GAME* game);
	~BULLETS();
	void init();
	virtual void create() {};
	virtual void launch(const VECTOR2& pos,int speed,int lane);
	void update();
	void kill(int i);
	void AllKill();
	virtual void draw(int bulletKind);
	int BulletNum() { return Bullet.curNum; }
	float bulletLeft(int i) { return Bullets[i].pos.x; }
	float BulletRight(int i) { return Bullets[i].pos.x + Bullet.RightX; }
	int bulletLane(int i) { return Bullets[i].Lane; }
};

