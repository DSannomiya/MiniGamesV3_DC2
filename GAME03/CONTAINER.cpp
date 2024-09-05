#include"../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include "CONTAINER.h"
#include<time.h>
namespace GAME03 {
    CONTAINER::~CONTAINER() {
    }
    void CONTAINER::load() {
        CreateData();
        LoadGraphics();
        LoadBgms();
    }
    void CONTAINER::CreateData() {


        Data.fade.color = COLOR(60, 60, 60);
        Data.fade.speed = 255 * 2;



        //Data.volume.backColor = COLOR(255, 255, 255, 255);


    }
    void CONTAINER::LoadGraphics() {

        //Data.volume.backImg = loadImage("..\\main\\assets\\game03\\data\\音量設定_背景.png");

    }

    void CONTAINER::LoadBgms() {
        //Data.volume.Snd_A = loadSound("..\\main\\assets\\game03\\sounds\\BGM_A.wav");
        //Data.volume.Snd_B = loadSound("..\\main\\assets\\game03\\sounds\\BGM_B.wav");
        //Data.volume.Snd_C = loadSound("..\\main\\assets\\game03\\sounds\\BGM_C.wav");
        //Data.volume.Snd_D = loadSound("..\\main\\assets\\game03\\sounds\\BGM_D.wav");
        //Data.volume.Se_A = loadSound("..\\main\\assets\\game03\\sounds\\ジャンプ.wav");
        //Data.volume.Se_B = loadSound("..\\main\\assets\\game03\\sounds\\歓声と拍手.wav");
        //Data.volume.Se_C = loadSound("..\\main\\assets\\game03\\sounds\\間抜け7.wav");
        //Data.volume.Se_D = loadSound("..\\main\\assets\\game03\\sounds\\決定ボタンを押す50.wav");
        //Data.volume.Se_E = loadSound("..\\main\\assets\\game03\\sounds\\キャンセル9.wav");
        //Data.volume.volume1 = 80.0f;
        //Data.volume.volume2 = 80.0f;
        //setVolume(Data.volume.Snd_A, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        //setVolume(Data.volume.Snd_B, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        //setVolume(Data.volume.Snd_C, -(100 - (int)Data.volume.volume1) * (100 - (int)Data.volume.volume1));
        //setVolume(Data.volume.Se_A, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        //setVolume(Data.volume.Se_B, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
        //setVolume(Data.volume.Se_C, -(100 - (int)Data.volume.volume2) * (100 - (int)Data.volume.volume2));
    }
}