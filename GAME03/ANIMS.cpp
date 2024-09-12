#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#if _MSC_VER > 1922 && !defined(_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#endif
#include <experimental/filesystem>
#include "ANIMS.h"
namespace GAME03 {
    ANIMS::ANIMS() {
    }
    ANIMS::ANIMS(const char* path) {
        load(path);
    }
    ANIMS::ANIMS(const char* fileName, int cols, int rows, int w, int h) {
        load(fileName, cols, rows, w, h);
    }
    ANIMS::~ANIMS() {
        for (int i = 0; i < NumAnims; i++) {
            delete Anims[i];
        }
        delete[] Anims;
    }
    void ANIMS::load(const char* path) {
        namespace fs = std::experimental::filesystem;
        NumAnims = 0;
        for (const auto& e : fs::directory_iterator(path)) {
            NumAnims++;
        }
        Anims = new ANIM * [NumAnims + 2];
        int i = 0;
        for (const auto& e : fs::directory_iterator(path)) {
            Anims[i] = new ANIM(e.path().string().c_str());
            i++;
        }
    }
    void ANIMS::load(const char* fileName, int cols, int rows, int w, int h) {
        NumAnims = rows;
        int img = loadImage(fileName);
        Anims = new ANIM * [NumAnims];
        for (int i = 0; i < NumAnims; i++) {
            Anims[i] = new ANIM;
            Anims[i]->divideRow(img, i, cols, w, h);
        }
    }
    ANIM* ANIMS::anim(int animIdx) {
        if (animIdx >= NumAnims) {
            return Anims[NumAnims - 1];
        }
        return Anims[animIdx];
    }
}
