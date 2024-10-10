#include"../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include"../MAIN/MAIN.h"
#include"TITLE.h"
#include"FADE.h"
#include"VOLUME.h"
#include "MAP.h"
#include"CONTAINER.h"
#include"EXPLANACHION.h"
#include "CHARACTER_MANAGER.h"
#include"GAME03.h"
namespace GAME03
{
	int GAME::create() {
		Container = new CONTAINER();
		Title = new TITLE(this);
		Select = new SELECT(this);
		Stage = new STAGE(this);
		Map = new MAP(this);
		Fade = new FADE(this);
		Volume = new VOLUME(this);
		Explan = new EXPLANACHION(this);
		CharacterManager = new CHARACTER_MANAGER(this);

		Container->load();
		Title->create();
		Select->create();
		Stage->create();
		Map->create();
		Fade->create();
		Volume->create();
		Explan->create();
		CharacterManager->create();

		CurScene = Title;
		CurScene->init();

		return 0;
	}

	void GAME::destroy() {
		delete CharacterManager;
		delete Volume;
		delete Fade;
		delete Title;
		delete Map;
		delete Select;
		delete Stage;
		delete Container;
		delete Explan;
	}

	void GAME::setCurScene(SCENE* scene) {
		CurScene = scene;
		CurScene->init();
	}

	void GAME::proc() {
		clear();
		CurScene->proc();
	}

	void GAME::backToMenu() {
		main()->backToMenu();
		stopSound(container()->data().volume.Snd_A);
	}
}
