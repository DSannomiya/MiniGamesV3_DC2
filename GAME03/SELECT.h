#pragma once
#include"SCENE.h"
namespace GAME03 {
	class SELECT:public SCENE{
	public:
		struct DATA {

		};
	private:
		DATA Select;
	public:
		SELECT(class GAME* game):SCENE(game){}
		void create();
		void init();
		void draw();
		void nextScene();
	};
}

