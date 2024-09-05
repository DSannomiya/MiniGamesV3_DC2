#pragma once
#include"TITLE.h"
#include"FADE.h"
#include"VOLUME.h"
namespace GAME03 {
    class CONTAINER
    {
    private:
        struct DATA {
            FADE::DATA fade;
            VOLUME::DATA volume;
        };
        DATA Data;
        void CreateData();
        void LoadGraphics();
        void LoadBgms();
    public:
        ~CONTAINER();
        void load();
        const DATA& data() { return Data; }
    };
}
