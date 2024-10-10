#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "EXPLANACHION.h"
#include"GAME03.h"
#include"CONTAINER.h"
namespace GAME03 {
	void EXPLANACHION::create(){
		Explan = game()->container()->data().explan;

	}
	void EXPLANACHION::init(){
		game()->fade()->inTrigger();
	}
	void EXPLANACHION::draw(){
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);
		game()->fade()->draw();
	}
	void EXPLANACHION::nextScene(){
		if (isTrigger(KEY_ESCAPE)) {
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}

	}
}