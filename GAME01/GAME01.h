
#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME01
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    private:
    enum STATE { TITLE, INIT, PLAY, OVER };
    STATE State = TITLE;
    void title();
    void init();
    void hsbToRgb(float h, float s, float v, int& r, int& g, int& b);
    void drawStage();
    void setPtnPosition();
    void setPtnNoToStage();
    void delPtnNoFromStage();
    int collision();
    void complete();
    void play();
    void over();
    void gmain();
    void drawNextBlock();
    void saveRanking();
    void  adjustFallSpeed();
    void updateDropSpeed();  // �X�R�A�ɉ����ė����X�s�[�h��ύX
    void loadHighScore();
    void saveHighScore();
    void intToStr(int num, char* buffer);

    //�F
    struct COLOR2 {
        float hue;
        float satu;
        float value;
        float alpha;
        COLOR2(float h, float s, float v, float a) {
            hue = h;
            satu = s;
            value = v;
            alpha = a;
        }
    };
    float Satu = 200;
    float Value = 255;
    float Alpha = 255;
    struct COLOR2 Color[9] = {
    COLOR2(0,Satu,Value,Alpha),
    COLOR2(30,Satu,Value,Alpha),
    COLOR2(60,Satu,Value,Alpha),
    COLOR2(120,Satu,Value,Alpha),
    COLOR2(180,Satu,Value,Alpha),
    COLOR2(220,Satu,Value,Alpha),
    COLOR2(300,Satu,Value,Alpha),
    COLOR2(200,44,88,Alpha),
    COLOR2(0,0,20,Alpha),
    };
    //�ǂƔw�i�̐F�ԍ�
    const int WALL = 7;
    const int BACK = 8;
    //�X�e�[�W�i�F�ԍ����L������j
    static const int ROWS = 20;
    static const int COLS = 12;
    int Stage[ROWS][COLS];
    float Size = 50;
    //��u���b�N�ʒu�Ɖ�]��
    int X, Y, R;
    //�u���b�N�p�^�[���̈ʒu
    int Px[4], Py[4];
    //�u���b�N�ړ�����
    int FallFlag = 0;
    int LoopCnt = 0;
    //�u���b�N�p�^�[���ԍ�  �� ���F�ԍ� ��
    int PtnNo;

    int offsetX = 650; // �������̃I�t�Z�b�g
    int offsetY = 90; // �c�����̃I�t�Z�b�g

    int NextPtnNo = 0;

    int previewX = -4; // �X�e�[�W�����ɔz�u
    int previewY = 4;  // �������ɔz�u
    int size = Size;   // �\���T�C�Y��ʏ�̃u���b�N�Ɠ�����

    int FallSpeed = 30; // �����������x
    int  Level = 1;       // �������x��
    bool showLevelUpMessage = false; // ���x���A�b�v�ʒm�t���O
    int messageTimer = 0;

    static const int RANKING_SIZE = 5; // �����L���O�̍ő匏��
    int rankings[RANKING_SIZE];       // �����L���O�z��
    
    // �����̃����o�[�ϐ��ɒǉ�
    float dropSpeed;  // �����X�s�[�h
    const float INITIAL_DROP_SPEED = 1.0f; // �����̗����X�s�[�h

    int highScore = 0;

    int bgmSnd = 0;
    int aaaSnd = 0;

    bool isBgmPlaying = false;

    int haikeiImg = 0;
    int haikei2Img = 0;
    int overImg = 0;
    


    

    
};




}
