#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09 {
    class COLOR_PICKER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 areaSize;   //�w�i�̃T�C�Y
            float size;		    //�J���[�s�b�J�[�̃T�C�Y(���a)
            float swRate;	    //�T�C�Y�ɑ΂���Sw�̔䗦
            float innerSize;	//�T�C�Y�ɑ΂�������̉~�̔��a
            float rectSize;	    //�T�C�Y�ɑ΂���l�p�`�̃T�C�Y

            float hPointerSize;
            float svPointerSize;
        };
    private:
        DATA ColorPicker;
        VECTOR2 CornerPos = { 500,500 };
        VECTOR2 Pos;
        float Sw;
        int Hue = 0;
        int Satu = 255;
        int Value = 255;
        bool IsMoveH = false;
        bool IsMoveSV = false;
    public:
        COLOR_PICKER(class GAME* game);
        ~COLOR_PICKER();
        void create();
        void init();
        void update();
        void draw();
    };
}