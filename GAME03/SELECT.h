#pragma once
#include"SCENE.h"
#if _MSC_VER > 1922 && !defined(_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#endif
#include <experimental/filesystem>
namespace GAME03 {
	namespace fs = std::experimental::filesystem;
	class SELECT:public SCENE{
	public:
		struct DATA {
			int select_cfream = 0;
			int select_chara = 0;
			int chara_img[5]{};
			int select_sfream = 0;
			int select_stage = 0;
			int numPlayer = false;
			int numStage = 0;
			int deterPlayer = 0;
			int deterStage = 0;
			int next_scene = 0;
			int Confirm_selection = false;
			int click_cnt = 0;
			int a = 0;
			int b = 0;
			fs::path targetPath;
		};
	private:
		DATA Select;
	public:
		SELECT(class GAME* game):SCENE(game){}
		int countFolders(const fs::path& path);
		void create();
		void init();
		void draw();
		void nextScene();
	};
}

