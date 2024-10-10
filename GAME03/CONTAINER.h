#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"SELECT.h"
#include"MAP.h"
#include"PLAYER.h"
#include"ENEMY.h"
#include"VOLUME.h"
#include"FADE.h"
#include"VOLUME.h"
#include"CHARACTER_MANAGER.h"
#include"EXPLANACHION.h"
namespace GAME03 {
    class CONTAINER
    {
    private:
        struct DATA {
            STAGE::DATA stage;
            EXPLANACHION::DATA explan;
            SELECT::DATA select;
            FADE::DATA fade;
            MAP::DATA map;
            CHARACTER::DATA playerChara1;
            CHARACTER::DATA playerChara2;
            CHARACTER::DATA playerChara3;
            CHARACTER::DATA playerChara4;
            CHARACTER::DATA playerChara5;
            PLAYER::DATA player;
            ENEMY::DATA enemy;
            VOLUME::DATA volume;
            CHARACTER_MANAGER::DATA charaMng;
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
