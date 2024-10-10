#include "../../libOne/inc/libOne.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
#include<time.h>

namespace GAME03 {
	void STAGE::create() {
		Stage = game()->container()->data().stage;
	}
	void STAGE::init() {
		Stage.backToTitleTime = game()->container()->data().stage.backToTitleTime;
		game()->map()->init();
		game()->characterManager()->init();
		game()->fade()->inTrigger();
		time(&Stage.s_time);
		Stage.e_time = Stage.s_time + 200;
		time(&Stage.n_time);
		loopBgm = true;
	}
	void STAGE::update() {
		game()->characterManager()->update();
		game()->map()->update();
	}
	void STAGE::draw() {
		if (loopBgm) {
			//playLoopSound(game()->container()->data().volume.Snd_B);
			loopBgm = false;
		}
		BackGround();
		game()->map()->draw();
		game()->characterManager()->draw();
		if (game()->characterManager()->player()->died()) {
			//Logo(Stage.gameOverImg, Stage.gameOverColor);
		}
		else if (game()->characterManager()->player()->survived()) {
			//image(game()->container()->data().playerChara.shadowImg, -2500, -1800);
			//Logo(Stage.stageClearImg, Stage.stageClearColor);
		}
		else {
			time(&Stage.n_time);
			Stage.time = Stage.e_time - Stage.n_time;
			if (Stage.time > 30) { fill(255); }
			else if (Stage.time <= 30 && Stage.time > 10) { fill(255, 255, 0); }
			else if (Stage.time <= 10 && Stage.time > 0) { fill(255, 0, 0); }
			textSize(90);
			text((let)(int)Stage.time, width / 2.0f, height / 10.0f);
		}
		fill(0);
		game()->fade()->draw();
	}
	void STAGE::BackGround() const {
		clear();
		rectMode(CORNER);
		imageColor(Stage.backColor);
		image(Stage.backImg, 0, 0);
	}
	void STAGE::Logo(int img, const COLOR& color) {
		//imageColor(color);
		//image(img, Stage.logoPx, Stage.logoPy);
		Stage.backToTitleTime -= delta;
	}
	void STAGE::nextScene() {
		//if (Stage.backToTitleTime <= 0) {
		if (isTrigger(KEY_ENTER)) {
			//stopSound(game()->container()->data().volume.Snd_B);
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}
	}
}
