#pragma once
#include "HP_GAUGE.h"
class OBJECT_HP :public HP_GAUGE
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
		DATA ObjectGauge;
		float* NowHp;
		float* baseHp;
	public:
		OBJECT_HP(class GAME10_GAME* game);
		~OBJECT_HP();
		void appear(int hp, int Level);
		void create();
		void getDamage(float damage, int enemyKind,int weaponKind);
		void death(int i);
		void draw(VECTOR2 pos, int enemyKind);
		int GetHp(int i) { return NowHp[i]; }
};

