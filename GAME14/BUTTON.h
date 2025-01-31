#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class BUTTON :
        public GAME_OBJECT {
    public:
        struct DATA {
            int img = 0;
            float imgSize = 0.0f;
            VECTOR2 basePos = 0.0f;//��{�ʒu
            COLOR areaColor = 0.0f;//�����蔻��p�F
            float r = 0.0f;//���a�����蔻��p
            VECTOR2 areaSize = 0.0f;//�����蔻��p
            COLOR filter = 0.0f;//�����F
            bool sistemFlag = false;//���������p(Trigger)
            bool drawFlag = false;//�`�揈���p(Press)
            bool filterFlag = false;
        };
    protected:
        DATA Button;
    public:
        BUTTON(class GAME* game):
            GAME_OBJECT(game){}
        virtual void create();
        virtual void init();
        virtual void update();
        virtual void draw();
        bool collisionCheck(VECTOR2 pos, float r);//�~�̓����蔻��
        bool collisionCheck(VECTOR2 pos, VECTOR2 size);//�l�p�̓����蔻��
        virtual bool sistemFlag() { return Button.sistemFlag; }
        virtual bool sistemFlag(int buttonId) { return 0; }
        //void setSistemFlag(bool flag) { Button.sistemFlag = flag; }
    };
}

