#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/framework.h"
#include "../../libOne/inc/sound.h"
#include"../MAIN/GAME_BASE.h"
#include "../MAIN/MAIN.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"VOLUME.h"
#include"FADE.h"
#include"SELECT.h"
#include "TITLE.h"
namespace GAME03 {
	void TITLE::init() {
		game()->fade()->inTrigger();
		EscapeKeyValid = false;
		delibe = 0;
		loopBgm = true;
		master = false;
	}
	void TITLE::draw() {
		clear(255);
		rectMode(CORNER);
		if (loopBgm) {
			playLoopSound(game()->container()->data().volume.Snd_A);
			fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
			if (fp != NULL) {
				fscanf_s(fp, "%d\n%d\n", &f1, &f2);
				fclose(fp);
				setVolume(game()->container()->data().volume.Snd_A, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_B, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_C, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Snd_D, -(100 - f1) * (100 - f1));
				setVolume(game()->container()->data().volume.Se_A, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_B, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_C, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_D, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_E, -(100 - f2) * (100 - f2));
				setVolume(game()->container()->data().volume.Se_F, -(100 - f2) * (100 - f2));
			}
			fopen_s(&fp, "assets/game03/data/achievements/achievements.txt", "r");
			if (fp != 0) {
				fscanf_s(fp,"%s", achievements,(unsigned)_countof(achievements));
				if (achievements[0] == '3') {
					master = true;
				}
				fclose(fp);
			}
			loopBgm = false;
		}
		if (!reset) {
			imageColor(240);
			image(game()->container()->data().stage.backImg, 0, 0);
			float size;
			font("UD デジタル 教科書体 N"); 
			for (int i = 0; i < 10; i++) {
				size = 100;
				textSize(size);
				if (i == 8) {
					fill(255, 255, 255, 150);
					text("Eternal Survivors", width / 3.3f - 3.0f, height / 2.0f - (float)i * 1.0f - 1.0f);
					size = 45;
					textSize(size);
					text("〜異形の夜明け〜", width / 2.4f - 3.0f, height / 1.8f - (float)i * 1.0f - 1.0f);
					size = 40;
					textSize(size);
					text("press space key to select", width / 2.6f - 2.0f, height / 1.45f - (float)i * 1.0f - 0.1f);
					text("Ｏキー:オプション", width / 20.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Ｒキー:リセット", width / 3.5f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Ｐキー:操作説明", width / 2.0f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
					text("Escキーでメニューに戻る", width / 1.4f - 2.0f, height / 1.00625f - (float)i * 1.0f - 0.1f);
				}
				else {
					fill(100, 50.0f + (float)i * 10.0f, (float)i * 10.0f, 30);
					text("Eternal Survivors", width / 3.3f, height / 2.0f - (float)i * 1.0f);
					size = 45;
					textSize(size);
					text("〜異形の夜明け〜", width / 2.4f, height / 1.8f - (float)i * 1.0f);
					size = 40;
					textSize(size);
					text("press space key to select", width / 2.6f, height / 1.45f - (float)i * 1.0f);
					text("Ｏキー:オプション", width / 20.0f, height / 1.00625f - (float)i * 1.0f);
					text("Ｒキー:リセット", width / 3.5f, height / 1.00625f - (float)i * 1.0f);
					text("Ｐキー:操作説明", width / 2.0f, height / 1.00625f - (float)i * 1.0f);
					text("Escキーでメニューに戻る", width / 1.4f, height / 1.00625f - (float)i * 1.0f);
				}
			}
		}
		if (master) {
			image(game()->container()->data().stage.masterImg, 0, 0);
		}
		if (isTrigger(KEY_R)) {
			playSound(game()->container()->data().volume.Se_D);
			reset = true;
		}
		if (reset) {
			imageColor(200);
			image(game()->container()->data().stage.backImg, 0, 0);
			fill(255);
			textSize(100);
			text("本当にリセットしますか？Y / N", width / 5.0f - 20.0f, height / 2.0f);
			if (isTrigger(KEY_Y)) {
				playSound(game()->container()->data().volume.Se_D);
				if (fp != NULL) {
					fprintf_s(fp, "0");
					fclose(fp);
				}
				fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "w");
				if (fp != NULL) {
					f1 = 80;
					f2 = 80;
					fprintf_s(fp, "%d\n", f1);
					fprintf_s(fp, "%d\n", f2);
					fclose(fp);
				}
				fopen_s(&fp, "assets/game03/data/sounds/volume.txt", "r");
				if (fp != NULL) {
					fscanf_s(fp, "%d\n%d\n", &f1, &f2);
					fclose(fp);
					setVolume(game()->container()->data().volume.Snd_A, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_B, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_C, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Snd_D, -(100 - f1) * (100 - f1));
					setVolume(game()->container()->data().volume.Se_A, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_B, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_C, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_D, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_E, -(100 - f2) * (100 - f2));
					setVolume(game()->container()->data().volume.Se_F, -(100 - f2) * (100 - f2));
				}
				reset = false;
			}
			else if (isTrigger(KEY_N)) {
				playSound(game()->container()->data().volume.Se_E);
				reset = false;
			}
		}
		game()->fade()->draw();
	}
	void TITLE::nextScene() {
		if (!reset) {
			if (isTrigger(KEY_SPACE)) {
				playSound(game()->container()->data().volume.Se_E);
				game()->setCurScene(game()->select());
			}
			if (isTrigger(KEY_O)) {
				game()->fade()->outTrigger();
				delibe = 1;
				playSound(game()->container()->data().volume.Se_E);
			}
			if (isTrigger(KEY_P)) {
				game()->fade()->outTrigger();
				delibe = 2;
				playSound(game()->container()->data().volume.Se_E);
			}
			if (isTrigger(KEY_ESCAPE)) {
				game()->backToMenu();
				EscapeKeyValid = true;
				playSound(game()->container()->data().volume.Se_D);
			}
			if (game()->fade()->outEndFlag() && delibe == 1) {
				//stopSound(game()->container()->data().volume.Snd_A);
				game()->setCurScene(game()->volume());
			}
			if (game()->fade()->outEndFlag() && delibe == 2) {
				//stopSound(game()->container()->data().volume.Snd_A);
				game()->setCurScene(game()->explan());
			}
		}
	}
}