#pragma once
#include"ANIM.h"
namespace GAME03 {
    class ANIMS {
    private:
        int NumAnims = 0;
        class ANIM** Anims = 0;
    public:
        ANIMS();
        ANIMS(const char* path);
        ANIMS(const char* fileName, int cols, int rows, int w, int h);
        ~ANIMS();
        void load(const char* path);
        void load(const char* fileName, int cols, int rows, int w, int h);
        class ANIM* anim(int animIdx);
    };
}

