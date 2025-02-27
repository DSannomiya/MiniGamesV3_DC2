#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"
namespace GAME06
{
    class JUDGE_LIST :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            COLOR textColor;
            float textSize = 0.0f;
            VECTOR2 textPos1;
            VECTOR2 textPos2;
            VECTOR2 textPos3;
            VECTOR2 textPos4;
            const char* str1 = nullptr;
            const char* str2 = nullptr;
            const char* str3 = nullptr;
            const char* str4 = nullptr;
        };
    private:
        DATA JudgeList;
    public:
        JUDGE_LIST(class GAME* game) :GAME_OBJECT(game) {}
        ~JUDGE_LIST() {}
        void create();
        void draw();
    };
}

