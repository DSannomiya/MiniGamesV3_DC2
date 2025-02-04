#pragma once
#include "HP_GAUGE.h"
class ENEMY_HPGAUGE :public HP_GAUGE
{
public:
	struct DATA {
		int curHp = 0;//�\�������HP�̌�
		int MaxNumHp = 0;//�\�������ő吔
		int My;//�G�̉��̂ق��ɏ������炷���߂̒l
		float increaseHp = 0;//HP�̑����镝
		float hpWidth = 0;
		float hpHeight = 0;
	};
private:
	DATA EnemyGauge;
	float* NowHp;
	float* baseHp;
public:
	ENEMY_HPGAUGE(class GAME10_GAME* game);
	~ENEMY_HPGAUGE();
	void init();
	void appear(int hp, int Level);
	void create();
	void getDamage(float damage, int enemyKind,int weaponKind);
	void death(int i);
	void allDeath();
	void draw(VECTOR2 pos,int enemyKind);
	int GetHp(int i) { return NowHp[i]; }
};

