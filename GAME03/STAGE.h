#pragma once
#include"SCENE.h"
namespace GAME03 {
	class STAGE :public SCENE {
	public:
		struct DATA {
			int backImg = 0;
			int stageClearImg = 0;
			int gameOverImg = 0;
			float backToTitleTime = 0;
			COLOR backColor;
			COLOR gameOverColor;
			COLOR stageClearColor;
			float logoPx = 0;
			float logoPy = 0;
			time_t time = 0;
			time_t s_time = 0, e_time = 0, n_time = 0;
		};
	private:
		DATA Stage;
		void BackGround() const;
		void Logo(int img, const COLOR& color);
	public:
		STAGE(class GAME* game) :SCENE(game) {}
		void create();
		void init();
		void update();
		void draw();
		void nextScene();
		int loopBgm = true;
	};
}