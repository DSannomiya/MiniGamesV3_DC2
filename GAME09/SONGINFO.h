#pragma once
#include "../../libOne/inc/VECTOR2.h"
#include <string>
#include <vector>
#include "CHARTMANAGER.h"

namespace GAME09 {
    struct SONGINFO {
        std::string fileName = ".txt";
        std::string scorePath = ".txt";
        std::string title = "???";
        std::string artist = "???";
        std::string credit = "???";
        std::string music = "???";
        std::string banner = "???";
        std::string backGround = "???";
        int difficulty[CHARTMANAGER::NUM_DIFFICULTY]{};
        double offset = 0;
        double offsetB = 0;
        double bpm = 120;
        VECTOR2 measure = VECTOR2(4, 4);
        std::vector<int> lanes;
        int musicIdx = 0;
        int backImageIdx = 0;
        VECTOR2 backImageSize = VECTOR2(1920, 1080);
        int jacketImageIdx = 0;
        VECTOR2 jacketImageSize = VECTOR2(1920, 1080);
        float volume = -5000;
        int highScore[CHARTMANAGER::NUM_DIFFICULTY]{};
        int achievement[CHARTMANAGER::NUM_DIFFICULTY]{};
    };
}