#pragma once
#include"SCENE.h"
#include"WEAPONS.h"
#include"PLAYER.h"
#include"HP_GAUGE.h"
class GAME10_GAME
{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
public:
	//�V�[���̐�
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		RESULT_ID,
		NUM_SCENES
	};
	//�����ID
	enum WEAPON_ID {
		HANDGUN_ID,
		NUM_WEAPON
	};
	//HP��ID
	enum HP_ID {
		PLAYERHP_ID,
		ENEMYHP_ID,
		NUM_HP
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	//�L�����֘A
	class PLAYER* Player;
	class HP_GAUGE* HpGauge[NUM_HP];
	class HANDGUN_BULLETS* HandgunBullets;

	class ENEMYS* Enemies;
	
	class TIME* Time;
	class WEAPONS* Weapons[NUM_WEAPON];
	WEAPON_ID CurWeaponId;
public:
	GAME10_GAME();
	~GAME10_GAME();
	void run();
	void changeScene(SCENE_ID SceneId);
	class SCENE* scenes(int i) { return Scenes[i]; }
	class HP_GAUGE* Hp_gauge(int i) { return HpGauge[i]; }
	class PLAYER* player() { return Player; }
	class WEAPONS* weapons(int Weaponkind) { return Weapons[Weaponkind]; }
	class TIME* time() { return Time; }
	class HANDGUN_BULLETS* handgunBullets() { return HandgunBullets; };
	class ENEMYS* enemies() { return Enemies; }
};

