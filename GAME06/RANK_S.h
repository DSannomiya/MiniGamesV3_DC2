#pragma once
#include "SCENE.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class RANK_S :
        public SCENE
    {
    public:
        struct DATA {
            COLOR backScreenColor;
            COLOR textColor1;
            float textSize1 = 0.0f;
            VECTOR2 textPos1;
            const char* str1 = nullptr;
            COLOR textColor2;
            float textSize2 = 0.0f;
            VECTOR2 textPos2;
            const char* str2 = nullptr;
            COLOR textColor3;
            float textSize3 = 0.0f;
            VECTOR2 textPos3;
        };
    private:
        DATA RankS;
    public:
        RANK_S(class GAME* game) :SCENE(game) {}
        ~RANK_S() {}
        void create();
        void draw();
        void nextScene();
    };
}

