#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include "SELECT.h"
namespace GAME03 {
	void SELECT::create() {
		Select = game()->container()->data().select;
	}
	void SELECT::init() {
		game()->fade()->inTrigger();

	}
	void SELECT::draw() {
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);

	}
	void SELECT::nextScene() {
		if (isTrigger(KEY_ESCAPE)) {
			game()->setCurScene(game()->title());
		}

	}
}
