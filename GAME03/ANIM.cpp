#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#if _MSC_VER > 1922 && !defined(_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#endif
#include <experimental/filesystem>
#include "ANIM.h"
namespace GAME03 {
    ANIM::ANIM() {
    }
    ANIM::ANIM(const char* pathName) {
        load(pathName);
    }
    ANIM::~ANIM() {
        delete[] Imgs;
    }
    void ANIM::load(const char* path) {
        namespace fs = std::experimental::filesystem;
        NumImgs = 0;
        for (const auto& e : fs::directory_iterator(path)) {
            NumImgs++;
        }
        Imgs = new int[NumImgs + 2];
        int i = 0;
        for (const auto& e : fs::directory_iterator(path)) {
            Imgs[i] = loadImage(e.path().string().c_str());
            i++;
        }
    }
    void ANIM::divideRow(int imgIdx, int row, int cols, int w, int h) {
        NumImgs = cols;
        Imgs = new int[NumImgs];
        for (int i = 0; i < NumImgs; i++) {
            Imgs[i] = cutImage(imgIdx, w * i, row * h, w, h);
        }
    }
    void ANIM::divide(const char* fileName, int cols, int rows, int w, int h) {
        NumImgs = cols * rows;
        Imgs = new int[NumImgs];
        int img = loadImage(fileName);
        divideImage(img, cols, rows, w, h, Imgs);
    }
    void ANIM::draw(ANIM_DATA* ad, float px, float py, float angle, float scale) {
        if (LoopFlag) {
            ad->elapsedTime += delta;
            if (ad->elapsedTime >= ad->interval) {
                ad->elapsedTime -= ad->interval;
                ++(ad->imgIdx);
                if (ad->imgIdx >= NumImgs) {
                    ad->imgIdx = 0;
                }
            }
            image(Imgs[ad->imgIdx], px, py, angle, scale);
        }
        else {
            if (ad->imgIdx >= NumImgs) {
                return;
            }
            ad->elapsedTime += delta;
            if (ad->elapsedTime >= ad->interval) {
                ad->elapsedTime -= ad->interval;
                ++(ad->imgIdx);
            }
            if (ad->imgIdx < NumImgs) {
                image(Imgs[ad->imgIdx], px, py, angle, scale);
            }
        }
    }
}
