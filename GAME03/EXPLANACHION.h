#pragma once
#include"SCENE.h"
namespace GAME03 {
	class EXPLANACHION :public SCENE {
	public:
		struct DATA {

		};
	private:
		DATA Explan;
	public:
		EXPLANACHION(class GAME* game) :SCENE(game) {}
		void create();
		void init();
		void draw();
		void nextScene();
	};
}

