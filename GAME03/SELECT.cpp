#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "../../libOne/inc/sound.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include "SELECT.h"
namespace GAME03 {
	void SELECT::create() {
		Select = game()->container()->data().select;
	}
	void SELECT::init() {
		game()->fade()->inTrigger();
		Select.targetPath = "..\\main\\assets\\game03\\data\\player";
		Select.numPlayer = countFolders(Select.targetPath);
		Select.targetPath = "..\\main\\assets\\game03\\data\\stage";
		Select.numStage = countFolders(Select.targetPath);
		Select.deterPlayer = 0;
		Select.Confirm_selection = false;
		Select.click_cnt = 0;
		Select.a = 0;
		Select.b = 0;
		Select.next_scene = false;
	}
	int SELECT::countFolders(const fs::path& path) {
		int cnt = 0;
		for (const auto& entry : fs::directory_iterator(path)) {
			if (fs::is_directory(entry.status())) {
				++cnt;
			}
		}
		return cnt;
	}
	void SELECT::draw() {
		imageColor(240);
		image(game()->container()->data().stage.backImg, 0, 0);
		if (!Select.Confirm_selection) {
			image(Select.select_cfream, 0, 0);
			if (isTrigger(KEY_DOWN) || isTrigger(KEY_S)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0 && Select.b == 0) {
					Select.click_cnt = 1;
					Select.a = 1;
					Select.b = 1;
				}
				else if (Select.a < Select.numPlayer / 4 + 1) {
					if (Select.numPlayer >= Select.a * 4 + Select.b) {
						Select.a += 1;
					}
				}
			}
			else if (isTrigger(KEY_UP) || isTrigger(KEY_W)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0 && Select.b == 0) {
					Select.click_cnt = 1;
					Select.a = 1;
					Select.b = 1;
				}
				else if (Select.a > 1) {
					Select.a -= 1;
				}
			}
			else if (isTrigger(KEY_LEFT) || isTrigger(KEY_A)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0 && Select.b == 0) {
					Select.click_cnt = 1;
					Select.a = 1;
					Select.b = 1;
				}
				else if (Select.b > 1) {
					Select.b -= 1;
				}
			}
			else if (isTrigger(KEY_RIGHT) || isTrigger(KEY_D)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0 && Select.b == 0) {
					Select.click_cnt =1;
					Select.a = 1;
					Select.b = 1;
				}
				else if (Select.b < 4) {
					if (Select.numPlayer >= (Select.a - 1) * 4 + Select.b + 1) {
						Select.b += 1;
					}
				}
			}
			if (Select.click_cnt != 0) {
				stroke(255);
				strokeWeight(10);
				noFill();
				rect(width / 5.1f + 200 * Select.b, height / 11.0f + 200 * Select.a, 148, 158);
				if (isTrigger(KEY_ENTER)) { 
					playSound(game()->container()->data().volume.Se_C);
					Select.deterPlayer = (Select.a - 1) * 4 + Select.b;
					Select.Confirm_selection = true;
				}
			}
			for (int i = 1; i <= Select.numPlayer / 4 + 1; i++) {
				for (int j = 1; j <= 4; j++) {
					if ((i - 1) * 4 + j > Select.numPlayer) {
						break;
					}
					imageColor(190);
					if (mouseX >= width / 5.1f + 200 * j &&
						mouseX <= width / 5.1f + 200 * j + 148 &&
						mouseY >= height / 11.0f + 200 * i &&
						mouseY <= height / 11.0f + 200 * i + 158) {
						imageColor(240);
						if (isTrigger(MOUSE_LBUTTON)) {
							playSound(game()->container()->data().volume.Se_C);
							if (Select.a != i || Select.b != j) {
								Select.click_cnt = 0;
							}
							if (Select.click_cnt >= 1) {
								Select.deterPlayer = (Select.a - 1) * 4 + Select.b;
								Select.a = 0;
								Select.click_cnt = 0;
								Select.Confirm_selection = true;
								break;
							}
							Select.a = i;
							Select.b = j;
							Select.click_cnt++;
						}
					}
					image(Select.select_chara, width / 5.1f + 200 * j, height / 11.0f + 200 * i);
					imageColor(240);
					image(Select.chara_img[i], width / 4.3f + 200 * j, height / 6.5f + 200 * i , 0 , 1.5f);
				}
			}
		}
		else if (Select.Confirm_selection) {
			image(Select.select_sfream, 0, 0);
			if (isTrigger(KEY_DOWN) || isTrigger(KEY_S)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0) {
					Select.click_cnt = 1;
					Select.a = 1;
				}
				else if (Select.a < Select.numStage) {
					Select.a += 1;
				}
			}
			else if (isTrigger(KEY_UP) || isTrigger(KEY_W)) {
				playSound(game()->container()->data().volume.Se_C);
				if (Select.a == 0) {
					Select.click_cnt = 1;
					Select.a = 1;
				}
				else if (Select.a > 1) {
					Select.a -= 1;
				}
			}
			if (Select.click_cnt != 0) {
				stroke(255);
				strokeWeight(10);
				noFill();
				rect(width / 16.1f + 200, height / 12.0f + 180 * Select.a, 1301, 169);
				if (isTrigger(KEY_ENTER)) {
					playSound(game()->container()->data().volume.Se_C);
					Select.deterStage = Select.a;
					Select.next_scene = true;
				}
			}
			for (int i = 1; i <= Select.numStage; i++) {
				imageColor(190);
				if (mouseX >= width / 16.1f + 200 &&
					mouseX <= width / 16.1f + 200 +  1301&&
					mouseY >= height / 12.0f + 180 * i &&
					mouseY <= height / 12.0f + 180 * i + 169) {
					imageColor(240);
					if (isTrigger(MOUSE_LBUTTON)) {
						playSound(game()->container()->data().volume.Se_C);
						if (Select.a != i) {
							Select.click_cnt = 0;
						}
						if (Select.click_cnt >= 1) {
							Select.deterStage = Select.a;
							Select.next_scene = true;
							break;
						}
						Select.a = i;
						Select.click_cnt++;
					}
				}
				image(Select.select_stage, width / 16.1f + 200, height / 12.0f + 180 * i);
			}
			if (isRelease(KEY_ESCAPE)) {
				playSound(game()->container()->data().volume.Se_D);
				Select.click_cnt = 0;
				Select.a = 0;
				Select.b = 0;
				Select.Confirm_selection = false;
			}
		}

		noStroke();
		game()->fade()->draw();

	}
	void SELECT::nextScene() {
		if (Select.next_scene) {
			Select.next_scene = false;
			game()->fade()->outTrigger();
		}
		if (game()->fade()->outEndFlag()) {
			game()->setCurScene(game()->stage());
		}
		if (!Select.Confirm_selection && isTrigger(KEY_ESCAPE)) {
			playSound(game()->container()->data().volume.Se_D);
			game()->setCurScene(game()->title());
		}

	}
}
