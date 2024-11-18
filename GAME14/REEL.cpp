#include "REEL.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/mathUtil.h"
#include"GAME14.h"
#include"LEVER.h"
#include"BUTTON.h"
#include"STOP_BUTTON.h"
#include<math.h>
namespace GAME14 {
    REEL::~REEL(){}
    void REEL::create(){
    }
    void REEL::init(int reelId){
        ReelId = reelId;
        NeedTime = (60.0f/ RPM) / MaxNum;
    }
    void REEL::update(){
        //���I���I������炩�E�F�C�g���Ԃ𖞂����Ă������]������
         if (Move) {
             AnimeFlag = true;
             AnimeTime = 0;
             Move = false;
         }
        if (AnimeFlag) {
            AnimeTime += delta;
            CurNum = BeforeNum + AnimeTime / NeedTime;
            if (Stop) {//�~�܂�Ƃ��̏���
                if (!SetAfter) {//�~�܂�ꏊ�̎w��
                    AfterNum = ceil(CurNum);
                    SetAfter = true;
                }
                else {
                    if (CurNum > AfterNum) {//�~�܂�ꏊ�܂ŗ������̏���
                        BeforeNum = AfterNum%MaxNum;
                        CurNum = AfterNum%MaxNum;
                        SetAfter = false;
                        AnimeFlag = false;
                        Stop = false;
                    }
                }
            }
        }


    }
    void REEL::draw(){
        fill(0);
        textSize(50);
        rectMode(CENTER);
        int startIdx = round(CurNum) - (DrawNum / 2);//�\�����n�߂�R�}�ԍ�
        for (int i = 0; i < DrawNum; i++) {
            float dist = CurNum - startIdx - i;
            int cellNum = (startIdx + i+MaxNum) % MaxNum;
            VECTOR2 pos = VECTOR2(width / 2 - 25, height / 2 +25);
            pos.y += 120 * dist;
            text(cellNum, Reel.pos.x, pos.y);
        }
        rectMode(CORNER);
        rect(Reel.pos.x, Reel.pos.y, 60, -30);
        rect(Reel.pos.x, Reel.pos.y+400, 60, 30);
    }

}