#pragma once
#include"../../libOne/inc/COLOR.h"
#include"SCENE.h"
#include"../MAIN/GAME_BASE.h"
#include"../MAIN/MAIN.h"
extern bool EscapeKeyValid;
namespace GAME03 {
	class TITLE :public SCENE {
	private:
		FILE* fp{};
	public:
		TITLE(class GAME* game) :SCENE(game) {}
		void init();
		void draw();
		void nextScene();
		int loopBgm = true;
		int delibe = 0;
		int f1 = 0, f2 = 0, f3 = 0;
		int reset = false;
	};
}