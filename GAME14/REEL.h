#pragma once
#include"../../libOne//inc//VECTOR2.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{//���[���̓����A�\��,���̐�������
    public:
        enum IMG_ID {
            BONUS_A,
            BONUS_B,
            BAR_A,
            BAR_B,
            REPLAY,
            WATERMELON_A,
            WATERMELON_B,
            CHERRY,
            BELL_A,
            BELL_B,
            NUM_IMG
        };
        enum STOP_NUMBER {
            FIRST=1,
            SECOND,
            THIRD
        };
        enum REEL_ID {
            LEFT,
            MIDDLE,
            RIGHT,
            NUM_REEL
        };
        struct DATA {//�S�̋��ʃf�[�^
            const char* combinationFileName;
            const char* bonusCombinationFileName;
            std::string separator;
            int reelNum = 0;
            int img[NUM_IMG] = { 0 };
            int BBAdjustImgId = 0;;//BB���̖��������p�̐擪�摜ID
            int cellNum = 0;
            int checkLineNum = 0;
            VECTOR2 bacePos = 0.0f;//���[���̊�ʒu
            VECTOR2 reelSize = 0.0f;
            VECTOR2 imgPos = 0.0f;//�摜��ʒu
            float imgSize = 0.0f;//�摜�{��
            VECTOR2 offsetPos = 0.0f;//�摜�C���ʒu
            VECTOR2 cellSize = 0.0f;//��R�}�̃T�C�Y
            float offset = 0.0f;//��̃��[���̊Ԋu
            int drawNum = 0;//�\���R�}��
            float RPM = 0.0f;//RotateParMinits
            float NeedTime = 0.0f;//��R�}�����̂ɕK�v�Ȏ���
            bool animeFlag = false;
            int maxMoveRange = 0;
        };
        struct COMBI_DATA {
            int resultId = -1;
            int combiImg[NUM_REEL];
            int& operator[](int id) {
                return combiImg[id];
            }
        };
        struct BONUS_COMBI_DATA {
            int bonusId = 0;
            int combiImg[NUM_REEL];
            int& operator[](int id) {
                return combiImg[id];
            }
        };
    private:
        struct REELS {//���[�����Ƃ̃f�[�^
            int reelId = -1;
            int beforeNum = 0;//�����O�̃R�}�ԍ�
            int afterNum = 0;//�~�܂�R�}�ԍ�
            float curNum = 0.0f;//���݉��i�ɕ\�����Ă���R�}�ԍ�
            bool animeFlag = false;//�S���[���������Ă��邩
            bool stopFlag = false;//���[�����~�܂�Ƃ��̃t���O
            bool setAfter = false;//afterNum����x�����ݒ肷��t���O
        };
        DATA Reels;
        REELS* Reel = 0;
        std::vector<COMBI_DATA> Combi;
        std::vector<BONUS_COMBI_DATA> BonusCombi;
        bool MoveFlag = false;//���[���S�̂𓮂����X�C�b�`
        float AnimeTime = 0.0f;//�����n�߂Ă���̎���
        int StopCunt = 0;//�~�߂����[���̃J�E���g
        int StopCell;//�~�߂����[���̃R�}�ԍ�
        //int AfterNum;
        //int DrawCellId;
        //float CurCell;
        //int Result;
        //int Bonus;
        //int moveCell;
        std::vector<COMBI_DATA> Buffer;
        void initresultcombination();
        void initbonuscombination();
        int I = 0;
        int J = 0;
    public:
        REEL(class GAME* game);
        ~REEL();
        void create();
        void init();
        void update();
        void initcombination();
        bool checkresultexist();//�����������Ă��邩
        bool checkbonusexist();//�{�[�i�X���������Ă��邩
        bool checkresultexist(int moveCell,int reelId);//�o�ڂɖ�������������т����邩
        bool checkbonusexist(int moveCell, int reelId);//�o�ڂɃ{�[�i�X������������т����邩
        int tellresultexistcell(int resultId,int reelId);//�o�ڂɎw�肵����������������т܂ŉ��R�}���邩
        int tellbonusexistcell(int bonusId, int reelId);//�o�ڂɎw�肵���{�[�i�X������������т܂ŉ��R�}���邩
        void draw();
        void debagDraw();
        void stop(int i) { Reel[i].stopFlag = true; }
        void move() { MoveFlag = true; }
        bool tellmovereel() { return Reels.animeFlag; }
        bool tellmovereel(int i){return Reel[i].animeFlag;}
        int maxMoveRange() { return Reels.maxMoveRange; }
    };
}

