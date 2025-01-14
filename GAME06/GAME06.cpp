#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../MAIN//MAIN.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMY.h"
#include "GAME06.h"
//�d�l
//�^�C�g���u�ˌ�(��)�v
//�X�e�[�W
//��
//�v���C���[�@�u�㉺�̈ړ��v�Ɓu�e�̔��ˁv
//�G(�I) �@�u�㉺�̈ړ��v�Ɓu���x�̕ω���1�v�Ɓu�����̋}�ȕύX��2�v��1�͗����ŁA��2�̓^�C�}�[��if���Ŏ�������
//�������ԁ@30�b
//��
//���U���g�@�I�ɓ����������ɉ�����C�`S�����N�𓖂��������ƈꏏ�ɕ\������

namespace GAME06
{
	int GAME::create()
	{
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[GAME_OVER_ID] = new GAME_OVER(this);
		CurSceneId = TITLE_ID;
		Player = new PLAYER(this);
		Enemy = new ENEMY(this);
		Container->load();
		Scenes[TITLE_ID]->create();
		Scenes[STAGE_ID]->create();
		Scenes[GAME_CLEAR_ID]->create();
		Scenes[GAME_OVER_ID]->create();
		Player->create();
		Enemy->create();
		return 0;
	}

	void GAME::destroy()
	{
		delete Enemy;
		delete Player;
		for (int i = 0; i < TOTAL_SCENES_ID; ++i) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::changeScene(SCENE_ID nextSceneId) {
		CurSceneId = nextSceneId;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
