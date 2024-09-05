#pragma once
#include"../MAIN/GAME_BASE.h"
#include"../MAIN/MAIN.h"
namespace GAME03 {
    class GAME :public GAME_BASE {
    private:
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    private:
        class TITLE* Title = nullptr;
        //class STAGE* Stage = nullptr;
        class SCENE* CurScene = nullptr;
        class FADE* Fade = nullptr;
        class VOLUME* Volume = nullptr;
        //class OPERATION_INSTRUCTIONS* OpInstructions = nullptr;
    public:
        class TITLE* title() { return Title; }
        //class STAGE* stage() { return Stage; }
        class FADE* fade() { return Fade; }
        class VOLUME* volume() { return Volume; }
        //class OPERATION_INSTRUCTIONS* operation() { return OpInstructions; }
        void setCurScene(SCENE* scene);
    private:
        //class MAP* Map = nullptr;
       // class CHARACTER_MANAGER* CharacterManager = nullptr;
    public:
        //class MAP* map() { return Map; }
        //class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void backToMenu();
        void destroy();
        void proc();
    };
}
