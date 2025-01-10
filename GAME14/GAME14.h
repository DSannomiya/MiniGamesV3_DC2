#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME14
{
    class GAME :
        public GAME_BASE
    {
    public:
        enum SCENE_ID {
            TITLE_ID,
            HOME_ID,
            STAGE_ID,
            RESULT_ID,
            NUM_SCENES
        };
    private://�R���e�i
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    private:
        //�V�[��
        class SCENE* Scenes[NUM_SCENES]{ nullptr };
        SCENE_ID CurSceneId = TITLE_ID;
    public:
        void changeScene(SCENE_ID sceneId);
    private://�L�����N�^
        class BUTTON* StopButton = nullptr;
        class LEVER* Lever = nullptr;
        class LOTTERY* Lottery = nullptr;
        class REEL* Reel = nullptr;
        class REEL_MAP* ReelMap = nullptr;
    public:
        class BUTTON* stopButton() { return StopButton; }
        class LEVER* lever() { return Lever; }
        class LOTTERY* lottery() { return Lottery; }
        class REEL* reel() { return Reel; }
        class REEL_MAP* reelMap() { return ReelMap; }
        void charaInit();
        void charaUpdate();
        void charaDraw();
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
