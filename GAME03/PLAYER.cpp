#include "../../libOne/inc/libOne.h"
#include "ANIMS.h"
#include "CONTAINER.h"
#include "GAME03.h"
#include "MAP.h"
#include "PLAYER.h"
#include "VOLUME.h"
#include <time.h>
namespace GAME03 {
	void PLAYER::create() {
		DeterPlayer = game()->container()->data().select.deterPlayer;
		Chara = game()->container()->data().playerChara1;
		Player = game()->container()->data().player;
	}
	void PLAYER::appear(float wx, float wy, float vx, float vy) {
		Chara.hp = game()->container()->data().playerChara1.hp;
		Chara.wx = wx;
		Chara.wy = wy;
		Chara.animId = Player.rightAnimId;
		Chara.speed = 3.4f * 100;
		time(&Player.s_time);
		Player.e_time = Player.s_time + 200;
		time(&Player.n_time);
		State = STATE::STRUGGLING;
		timeCnt = 0;
	}
	void PLAYER::update() {
		Move();
		CollisionWithMap();
		CheckState();
	}
	void PLAYER::Move() {
		if (State != STATE::DIED) {
			Chara.vx = 0.0f;
			Chara.vy = 0.0f;
			if (isPress(KEY_A)) {
				Chara.vx = -Chara.speed * delta;
				Chara.animId = Player.leftAnimId;
			}
			if (isPress(KEY_D)) {
				Chara.vx = Chara.speed * delta;
				Chara.animId = Player.rightAnimId;
			}
			if (isPress(KEY_W)) {
				Chara.vy = -Chara.speed * delta;
				Chara.animId;
			}
			if (isPress(KEY_S)) {
				Chara.vy = Chara.speed * delta;
				Chara.animId;
			}
		}
		Player.curWx = Chara.wx;
		if (Chara.vx != 0.0f || Chara.vy != 0.0f) {
			Chara.wx += Chara.vx;
			Chara.wy += Chara.vy;
		}
		else {
			Chara.animData.imgIdx = 0;
			Chara.animData.elapsedTime = -delta;
		}
		if (Player.e_time <= Player.n_time) {
			Chara.speed = 0.0f;
		}
		if (isPress(KEY_C) && isPress(KEY_V) && isPress(KEY_B)) {
			Chara.wx = 0.1f;
			Chara.wy = 250.0f;
		}//debug
	}
	void PLAYER::CollisionWithMap() {
		MAP* map = game()->map();
		if (Chara.animId == Player.rightAnimId) {
			if (map->collisionCharaRight(Chara.wx, Chara.wy)) {
				Chara.wx = Player.curWx;
			}
		}
		else {
			if (map->collisionCharaLeft(Chara.wx, Chara.wy) || Chara.wx < map->wx()) {
				Chara.wx = Player.curWx;
			}
		}
		if (map->collisionCharaTop(Chara.wx, Chara.wy)) {
			Chara.vy = Player.initVecDown;
		}
		if (map->collisionCharaBottom(Player.curWx, Chara.wy)) {
			Chara.vy = 0.0f;
			Chara.wy = (int)(Chara.wy / map->chipSize()) * (float)map->chipSize();
		}
		else {
		}
	}
	void PLAYER::CheckState() {
		time(&Player.n_time);
		if (isPress(KEY_SHIFT) && isPress(KEY_ENTER) && timeCnt == 0) {
			Player.e_time = Player.n_time;
			timeCnt++;
		}//debug
		if (Player.e_time == Player.n_time) {
			State = STATE::DIED;
			playSound(game()->container()->data().volume.Se_C);
		}
		if (Chara.wx < 0.0f && Chara.wy >= 250.0f) {
			Player.newscore = (int)(Player.e_time - Player.n_time) * 5000;
			fopen_s(&fp, "assets/game03/data/score.txt", "r");
			if (fp != NULL) {
				fscanf_s(fp, "%d", &Player.score);
				fclose(fp);
				if (Player.score < Player.newscore) {
					Player.score = Player.newscore;
					Player.upDate = true;
				}
			}
			fopen_s(&fp, "assets/game03/data/score.txt", "w");
			if (fp != NULL) {
				fprintf_s(fp, "%d", Player.score);
				fclose(fp);
			}
			State = STATE::SURVIVED;
			playSound(game()->container()->data().volume.Se_B);
			Chara.hp = 0;
		}
	}
	bool PLAYER::died() {
		if (State == STATE::DIED) {
			draw();
			return true;
		}
		return false;
	}
	bool PLAYER::survived() const {
		return State == STATE::SURVIVED;
	}
	float PLAYER::overCenterVx() {
		float centerWx = (game()->map()->wx() + width / 2.0f - game()->map()->chipSize() / 2.0f);
		float overCenterVx = Chara.wx - centerWx;
		//if (overCenterVx < 0 )overCenterVx = 0.0f;
		if (Chara.hp == 0)overCenterVx = 0;
		return overCenterVx;
	}
}
