#include "../../libOne/inc/libOne.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include "TITLE.h"
#include "FADE.h"
#include "VOLUME.h"
#include "CONTAINER.h"
#include"GAME03.h"
namespace GAME03
{
	int GAME::create() {
		Container = new CONTAINER();
		Title = new TITLE(this);
		Select = new SELECT(this);
		Stage = new STAGE(this);
		Fade = new FADE(this);
		Volume = new VOLUME(this);

		Container->load();
		Title->create();
		Select->create();
		Stage->create();
		Fade->create();
		Volume->create();

		CurScene = Title;
		CurScene->init();

		return 0;
	}

	void GAME::destroy() {
		delete Volume;
		delete Fade;
		delete Title;
		delete Select;
		delete Stage;
		delete Container;
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
