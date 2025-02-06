#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class STOP_BUTTON :
        public BUTTON{
    public:
        enum ID {
            LEFT_BUTTON,
            MIDDLE_BUTTON,
            RIGHT_BUTTON,
            NUM_BUTTON
        };
        struct DATA {
            int numButton = 0;
            float offset = 0.0f;
            float imgAlterSize = 0.0f;//�����Ă���Ƃ��̃T�C�Y
            float waiteTime;//���[���������Ăǂꂭ�炢�ŉ�����悤�ɂȂ邩
        };
    private:
        struct STOP_BUTTONS {
            int buttonId = 0;
            VECTOR2 pos = 0.0f;
            bool sistemFlag = false;//���������p(Trigger)
            bool drawFlag = false;//�`�揈���p(Press)
            bool filterFlag = false;
        };
        DATA StopButtons;
        STOP_BUTTONS* StopButton = nullptr;
        int CurStopButtonState;
        float CurTime;
    public:
        STOP_BUTTON(class GAME* game):
            BUTTON(game){}
        ~STOP_BUTTON();
        void create();
        void init();
        void update();
        void draw();
       // bool sistemFlag(int buttonId);//�Q�b�^�[
        
    };
}

