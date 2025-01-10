#include"../../libOne/inc/window.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"REEL_MAP.h"
#include "REEL.h"
namespace GAME14 {
    REEL::REEL(class GAME* game):
        GAME_OBJECT(game){}
    REEL::~REEL(){
        delete[] Reel;
    }
    void REEL::create(){
        Reels = game()->container()->data().reel;
        Reel = new REELS[Reels.cellNum];
        init();
    }
    void REEL::init(){
        for (int i = 0; i < Reels.reelNum; i++) {
            Reel[i].reelId = i;
            Reel[i].beforeNum = 0;
            Reel[i].afterNum = 0;
            Reel[i].curNum = 0.0f;
            Reel[i].animeFlag = false;
            Reel[i].stopFlag = false;
            Reel[i].setAfter = false;
        }


    }
    void REEL::update(){

        //���I���I������炩�E�F�C�g���Ԃ𖞂����Ă������]������
        if (MoveFlag) {
            for (int i = 0; i < Reels.reelNum;i++) {
                Reel[i].animeFlag = true;
            }
            AnimeTime = 0.0f;
            MoveFlag = false;
            Reels.animeFlag = true;
        }
        if (Reels.animeFlag) {
            AnimeTime += delta;
            for (int i = 0; i < Reels.reelNum; i++) {
                if (Reel[i].animeFlag) {//���̃��[���������Ă��邩
                                                           //�i�񂾃R�}��//
                    Reel[i].curNum = Reel[i].beforeNum + AnimeTime / Reels.NeedTime;
                    
                    if (Reel[i].stopFlag) {//�~�܂�Ƃ��̏���
                        if (!Reel[i].setAfter) {//�~�܂�ꏊ�̎w��
                            StopCunt++;
                            StopCell = ceil(Reel[i].curNum);
                            StopCell = StopCell % Reels.cellNum;
                            
                            Reel[i].afterNum = StopCell+game()->reelMap()->tellStopCell(StopCell,Reel[i].reelId);
                            Reel[i].setAfter = true;
                        }
                        else {
                            if (Reel[i].curNum > Reel[i].afterNum) {//�~�܂�ꏊ�܂ŗ������̏���
                                Reel[i].beforeNum = Reel[i].afterNum % Reels.cellNum;
                                Reel[i].curNum = Reel[i].beforeNum;
                                Reel[i].setAfter = false;
                                Reel[i].animeFlag = false;
                                Reel[i].stopFlag = false;
                                if (StopCunt >= Reels.reelNum) {
                                    Reels.animeFlag = false;
                                    StopCunt = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    }
    void REEL::draw(){
        fill(0);
        textSize(50);
        for (int i = 0; i <  Reels.reelNum; i++) {
            int startIdx = round(Reel[i].curNum) -1;//�\�����n�߂�R�}curNum�͉��i
            for (int j = 0; j <  Reels.drawNum; j++) {
                float dist = Reel[i].curNum - startIdx - j;//�\�����n�߂�R�}����ǂꂭ�炢����Ă��邩
                int cellNum = (startIdx + j + Reels.cellNum) % Reels.cellNum;//0����20�Ɏ��܂�悤��
                VECTOR2 pos = VECTOR2(Reels.imgPos.x+(Reels.reelSize.x*i), Reels.imgPos.y);//�\���ʒu�̌���
                pos.y += Reels.cellSize.y * dist;//y���̒���
                int imgIdx = game()->reelMap()->textureNum(Reel[i].reelId, cellNum);//(reelId)�s(cellNum)��ڂ̉摜�C���f�b�N�X���擾
                image(Reels.img[imgIdx], pos.x,pos.y,0,Reels.imgSize);
            }
        }
    }
    void REEL::debagDraw() {
        print("�~�߂��R�}��");
        print(StopCell);
        print("���݂̃R�}��");
        print(StopCell);
    }
}