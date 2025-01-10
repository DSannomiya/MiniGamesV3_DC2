#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"
#include <cstdlib> 
#include <ctime>   
#include <string>  

namespace GAME13 {

    int GAME::create() {
        return 0;
    }

    void GAME::proc() {
        if (State == TITLE)Title();
        else if (State == PLAY)Play();
        else if (State == SUCCESS)Success();
        else if (State == OVER)Over();
    }

    void GAME::destroy() {
    }

    void GAME::Init() {
        half = random() % 2;
    }

    void GAME::Title() {
        clear(255);
        fill(0);
        textSize(200);
        text("�^�Q�[��", 500, 500);
        textSize(100);
        text("S�L�[:GAME START", 500, 900);

        if (isTrigger(KEY_S)) {
            Init();
            State = PLAY;
        }

        textSize(50);
        text("ENTER�L�[�Ń��j���[�ɖ߂�", 50, 1080);
        // ENTER�L�[�Ń��j���[�ɖ߂�
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::Play() {
        clear(100);
        fill(255);
        textSize(300);
        text("��", 0, 650);
        text("�E", 1600, 650);
        textSize(150);
        text("L��R��", 500, 400);
        text("�I��ł�������", 450, 600);

        if (isPress(KEY_L)&& half == 1 || isPress(KEY_R)&& half == 1) {
            fill(255, 0, 0);
            textSize(300);
            text("��", 0, 650);
            fill(255, 0, 0);
            textSize(300);
            text("�E", 1600, 650);
            State = SUCCESS;
            Sleep(800);
            State = SUCCESS;
            
        }
        else if (isPress(KEY_L)&& half == 0 || isPress(KEY_R)&& half == 0) {
            fill(255, 0, 0);
            textSize(300);
            text("��", 0, 650);
            fill(255, 0, 0);
            textSize(300);
            text("�E", 1600, 650);
            Sleep(800);
            State = OVER;
            
        }
    }
    void GAME::Success()
    {
        clear(255, 255, 0);
        fill(0);
        textSize(300);
        text("����", 600, 600);
        textSize(100);
        text("�X�y�[�X�ł�����x", 500, 700);
        if(isTrigger(KEY_SPACE)) {
            Init();
            State = PLAY;
        }
    }
    void GAME::Over()
    {
        clear(255);
        fill(0);
        textSize(300);
        text("���s", 600, 600);
        textSize(100);
        text("ENTER�L�[�Ń��j���[�ɖ߂�", 50, 1080);
        if (isTrigger(KEY_ENTER)) {
            State = TITLE;
        }
    }
}
