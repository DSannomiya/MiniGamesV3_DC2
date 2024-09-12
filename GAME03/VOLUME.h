#pragma once
#include"SCENE.h"
namespace GAME03 {
	class VOLUME :public SCENE {
	public:
		struct DATA {
			int Snd_A = 0;
			int Snd_B = 0;
			int Snd_C = 0;
			int Snd_D = 0;
			int Se_A = 0;
			int Se_B = 0;
			int Se_C = 0;
			int Se_D = 0;
			int Se_E = 0;
			float volume1 = 0.0f;
			float volume2 = 0.0f;
			int cntVolume = 0;
			float select = 2;
			float fileOnce = true;
			COLOR backColor;
		};
	private:
		DATA Volume;
		FILE* fp{};
		void BackGround() const;
	public:
		VOLUME(class GAME* game) : SCENE(game) {}
		void create();
		void init();
		void draw();
		void nextScene();
	};
}

