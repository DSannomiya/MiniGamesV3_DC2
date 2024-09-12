#include"../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include "CONTAINER.h"
#include"ANIMS.h"
#include<time.h>
namespace GAME03 {
    CONTAINER::~CONTAINER() {
        delete Data.playerChara.anims;
    }
    void CONTAINER::load() {
        CreateData();
        LoadGraphics();
        LoadBgms();
    }
    void CONTAINER::CreateData() {


        Data.fade.color = COLOR(60, 60, 60);
        Data.fade.speed = 255 * 2;



        Data.volume.backColor = COLOR(255, 255, 255, 255);


    }
    void CONTAINER::LoadGraphics(){

        Data.stage.backImg = loadImage("..\\main\\assets\\game03\\data\\back_Img.png");

    }

    void CONTAINER::LoadBgms() {
        Data.volume.Snd_A;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Snd_B;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Snd_C;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Snd_D;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Se_A;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Se_B;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Se_C;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Se_D;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.Se_E;//= loadSound("..\\main\\assets\\game03\\sounds\\.wav");
        Data.volume.volume1 = 80.0f;
        Data.volume.volume2 = 80.0f;
        setVolume(Data.volume.Snd_A, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_B, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Snd_C, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        setVolume(Data.volume.Se_A, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_B, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        setVolume(Data.volume.Se_C, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
    }
}