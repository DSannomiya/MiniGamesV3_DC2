#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/sound.h"
#include "../../libOne/inc/window.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"FADE.h"
#include "VOLUME.h"
namespace GAME03 {
	void VOLUME::create() {
		Volume = game()->container()->data().volume;
	}
	void VOLUME::init() {
		game()->fade()->inTrigger();
		Volume.select = 2;
		Volume.fileOnce = true;
		Volume.cntVolume = 0;
	}
	void VOLUME::draw() {

		clear(250);
		image(game()->container()->data().stage.backImg, 0, 0);
		if (Volume.fileOnce) {
			fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
			if (fp != NULL) {
				fscanf_s(fp, "%f\n%f\n", &Volume.volume1, &Volume.volume2);
				fclose(fp);
			}
			playLoopSound(Volume.Snd_C);
			Volume.fileOnce = false;
		}
		if (isPress(KEY_W) || (isPress(MOUSE_LBUTTON) && mouseY > 290 && mouseY < 377)) {
			Volume.select = 0;
		}
		else if (isPress(KEY_S) || (isPress(MOUSE_LBUTTON) && mouseY > 609 && mouseY < 691)) {
			Volume.select = 1;
		}
		if (isPress(MOUSE_LBUTTON) &&
			((Volume.select == 1) && (mouseY < 609 || mouseY > 691) && !isPress(KEY_S)) ||
			((Volume.select == 0) && (mouseY < 290 || mouseY > 377) && !isPress(KEY_W))) {
			Volume.select = 2;
		}
		if ((isRelease(KEY_W) || isRelease(KEY_S) || isRelease(MOUSE_LBUTTON)) &&
			(!isPress(KEY_W) || !isPress(KEY_S) || !isPress(MOUSE_LBUTTON))) {
			Volume.select = 2;
		}
		for (int i = 0; i < 10; i++) {
			if (i == 8) {
				fill(255, 255, 255, 150);
				textSize(60);
				text("‚a‚f‚l", width / 5.2f, height / 2.89f - (float)i * 1.0f);
				text("‚r‚d", width / 4.5f, height / 1.57f - (float)i * 1.0f);
				textSize(50);
				text((let)(int)Volume.volume1, width / 1.4f, height / 3.0f - (float)i * 1.0f);
				text((let)(int)Volume.volume2, width / 1.4f, height / 1.6f - (float)i * 1.0f);
				textSize(40);
				text("‰ŠúÝ’è", width / 2.2f, height / 1.1f - (float)i * 1.0f);
				text("EscƒL[‚Åƒ^ƒCƒgƒ‹‚É–ß‚é", width / 1.5f, height / 1.00625f - (float)i * 1.0f);
			}
			else {
				fill(50.0f + (float)i * 10.0f, 100, (float)i * 10, 30);
				strokeWeight(10.0f);
				stroke(140.0f + (float)i * 10.0f, 90, 160, 120 - (float)i * 10);
				line(width / 3.5f, height / 3.15f, width / 3.5f + 800.0f, height / 3.15f - (float)i * 2.0f);
				line(width / 3.5f, height / 1.65f, width / 3.5f + 800.0f, height / 1.65f - (float)i * 2.0f);
				textSize(60);
				text("‚a‚f‚l", width / 5.2f, height / 2.89f - (float)i * 1.0f);
				text("‚r‚d", width / 4.5f, height / 1.57f - (float)i * 1.0f);
				textSize(50);
				text((let)(int)Volume.volume1, width / 1.4f, height / 3.0f - (float)i * 1.0f);
				text((let)(int)Volume.volume2, width / 1.4f, height / 1.6f - (float)i * 1.0f);
				textSize(40);
				text("‰ŠúÝ’è", width / 2.2f, height / 1.1f - (float)i * 1.0f);
				//text((let)mouseX, 10, height / 2.0f);
				//text((let)mouseY, 10, height / 2.0f + 50);
				text("EscƒL[‚Åƒ^ƒCƒgƒ‹‚É–ß‚é", width / 1.5f, height / 1.00625f - (float)i * 1.0f);
			}
		}
		strokeWeight(5.0f);
		stroke(100);
		if (Volume.select == 0) {
			Volume.cntVolume++;
			if (Volume.cntVolume % 4 == 0) {
				if (Volume.volume1 >= 0 && Volume.volume1 <= 100) {
					if (isPress(KEY_A)) {
						Volume.volume1 += -(3.4f * 60) * delta;
						if (Volume.volume1 < 0) {
							Volume.volume1 = 0;
						}
					}
					if (isPress(KEY_D)) {
						Volume.volume1 += 3.4f * 60 * delta;
						if (Volume.volume1 > 100) {
							Volume.volume1 = 100;
						}

					}
				}
				Volume.cntVolume = 0;
			}
			if (isPress(MOUSE_LBUTTON)) {
				Volume.volume1 = (float)(mouseX - width / 3.5f) / 8.0f;
				if (Volume.volume1 < 0) {
					Volume.volume1 = 0;
				}
				if (Volume.volume1 > 100) {
					Volume.volume1 = 100;
				}
				fill(255);
				circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 25.0f);
				fill(255, 50, 50);
				circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 35.0f);
			}
			else {
				fill(255);
				circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 25.0f);
				fill(255, 50, 50);
				circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 35.0f);
			}
		}

		else if (Volume.select == 1) {
			Volume.cntVolume++;
			if (Volume.cntVolume % 4 == 0) {
				if (Volume.volume2 >= 0 && Volume.volume2 <= 100) {
					if (isPress(KEY_A)) {
						Volume.volume2 += -(3.4f * 60) * delta;
						if (Volume.volume2 < 0) {
							Volume.volume2 = 0;
						}
					}
					if (isPress(KEY_D)) {
						Volume.volume2 += 3.4f * 60 * delta;
						if (Volume.volume2 > 100) {
							Volume.volume2 = 100;
						}
					}
				}
				Volume.cntVolume = 0;
			}
			if (isPress(MOUSE_LBUTTON)) {
				Volume.volume2 = (float)(mouseX - width / 3.5f) / 8.0f;
				if (Volume.volume2 < 0) {
					Volume.volume2 = 0;
				}
				if (Volume.volume2 > 100) {
					Volume.volume2 = 100;
				}
				fill(255);
				circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 25.0f);
				fill(255, 50, 50);
				circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 35.0f);
			}
			else {
				fill(255);
				circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 25.0f);
				fill(255, 50, 50);
				circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 35.0f);
			}
		}

		else if (Volume.select == 2) {
			fill(255);
			circle(width / 3.5f + Volume.volume1 * 8.0f, height / 3.15f, 25.0f);
			circle(width / 3.5f + Volume.volume2 * 8.0f, height / 1.65f, 25.0f);
		}

		setVolume(Volume.Snd_A, -(100 - (int)Volume.volume1) * (100 - (int)Volume.volume1));
		setVolume(Volume.Snd_B, -(100 - (int)Volume.volume1) * (100 - (int)Volume.volume1));
		setVolume(Volume.Snd_C, -(100 - (int)Volume.volume1) * (100 - (int)Volume.volume1));
		setVolume(Volume.Snd_D, -(100 - (int)Volume.volume1) * (100 - (int)Volume.volume1));
		setVolume(Volume.Se_A, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_B, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_C, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_D, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));
		setVolume(Volume.Se_E, -(100 - (int)Volume.volume2) * (100 - (int)Volume.volume2));

		if (isPress(KEY_SPACE) || (isPress(MOUSE_LBUTTON) && mouseY < 971 && mouseX > 871 && mouseY > 931 && mouseX < 1011)) {
			fill(255, 155, 0);
			text("‰ŠúÝ’è", width / 2.2f, height / 1.1f - 9.0f);
			Volume.volume1 = 80;
			Volume.volume2 = 80;
		}
		if (isTrigger(KEY_P)) {
			playSound(Volume.Se_A);
		}
		noStroke();
		game()->fade()->draw();
	}

	void VOLUME::BackGround() const {
		clear();
		rectMode(CORNER);
		imageColor(Volume.backColor);
	}

	void VOLUME::nextScene() {
		if (isTrigger(KEY_ESCAPE)) {
			fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
			if (fp != NULL) {
				fprintf_s(fp, "%d\n", (int)Volume.volume1);
				fprintf_s(fp, "%d\n", (int)Volume.volume2);
				fclose(fp);
			}
			stopSound(Volume.Snd_C);
			game()->fade()->outTrigger();
			playSound(game()->container()->data().volume.Se_D);
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->title());
		}
	}
}