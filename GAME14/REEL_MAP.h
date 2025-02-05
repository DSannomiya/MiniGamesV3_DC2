#pragma once
#include "GAME_OBJECT.h"
#include"LOTTERY.h"

namespace GAME14 {
    class REEL_MAP :
        public GAME_OBJECT {//���[���l�`�o�擾�A����
    public:
        enum START_REEL_ID {
            LEFT,
            MIDDLE,
            RIGHT,
            NUM_REEL
        };
        enum STOP_ID {
            TOP=1,
            MID,
            BOT,
            NO_POS,
            NUM_POS=4
        };
        enum FILE_ID {
            LEFT_NO_BB,
            LEFT_RED_BB,
            LEFT_BLUE_BB,
            LEFT_REG,
            NUM_FILE
        };
        enum BONUS_FILE_ID {
            BB_LEFT,
            REG_LEFT,
            NUM_BONUS_FILE
        };
        enum SECOND_REEL_FILE_ID {
            TOP_TIME_NO_BB,
            TOP_TIME_RED_BB,
            TOP_TIME_BLUE_BB,
            TOP_TIME_REG,
            ONE_FILES,
            MIDDLE_TIME_NO_BB = ONE_FILES,
            MIDDLE_TIME_RED_BB,
            MIDDLE_TIME_BLUE_BB,
            MIDDLE_TIME_REG,
            BOTTOM_TIME_NO_BB,
            BOTTOM_TIME_RED_BB,
            BOTTOM_TIME_BLUE_BB,
            BOTTOM_TIME_REG,
            NO_TIME_NO_BB,
            NO_TIME_RED_BB,
            NO_TIME_BLUE_BB,
            NO_TIME_REG,
            NUM_SECOND_FILE
        };
        struct DATA {
            const char* reelMapFile = nullptr;//���[���z��̃t�@�C����
            const char* controlFile[NUM_FILE] ;//Bonus�ɓ����ĂȂ����̍�����~���̃��[������t�@�C����
            const char* secondControlFile[NUM_SECOND_FILE];//����~�̃��[������
            const char* distinction_NO_BonusFile = nullptr;
            const char* distinction_BonusFile = nullptr ;

            int* reelData;//�}�b�v�f�[�^
            char* leftControlData = nullptr;//������~���̃��[������f�[�^
            int rows = 0;//���[���z��f�[�^�̍s��
            int cols = 0;//���[���z��f�[�^�̗�
            int cellnum = 0;
            std::string separator;
        };

        struct CONTROL_DATA {
            int* normalBuffer;//�{�[�i�X���������Ă��Ȃ����̊���R�}���̔z��
            int* R_BB_Buffer;//��BB���������Ă��鎞��
            int* B_BB_Buffer;//��BB���������Ă��鎞��
            int* REG_Buffer;//REG���������Ă��鎞��
            
            int* operator[](int Id) {
                switch (Id) {
                   case LOTTERY::NO_BONUS:
                       return normalBuffer;
                   case LOTTERY::RED_BB:
                       return R_BB_Buffer;
                   case LOTTERY::BLUE_BB:
                       return B_BB_Buffer;
                   case LOTTERY::REGULAR:
                       return REG_Buffer;
                }
            }
        };

        struct DISTINCTION_DATA {
            std::map<int, STOP_ID> stop;
            STOP_ID operator[](int cellNum) {
                return stop[cellNum];
            }

        };
    private:
        DATA Map;
        CONTROL_DATA Control_Data [LOTTERY::NUM_RESULT] ;//�����[���̃��[������
        CONTROL_DATA Second_Control_Data[LOTTERY::NUM_RESULT * NUM_POS];//�E���[���̃��[������

        DISTINCTION_DATA StopPos_NO_Bonus[LOTTERY::NUM_RESULT];
        DISTINCTION_DATA StopPos_Bonus[LOTTERY::NUM_BONUS];

        std::map<std::string, STOP_ID> StopId;
public:
        REEL_MAP(class GAME* game);
        ~REEL_MAP();
        void create();  
        void destroy();
        void ControlDatacreate();
        void init();
        void initmap();
        void initreelMap();
        void initfirstreelControl();
        void initsecondreelControl();
        void initStopPos_NO_Bonus();
        void initStopPos_Bonus();
        int tellTableStopCell(int cellId,int reelId);
        int tellSecondTableStopCell(int cellId, int reelId,int leftCellId);
        int tellStopCell(int cellId,int reelId);
        void debagDraw();
        int textureNum(int reelId,int cellNum);
        int tellStopPos(int resultId, int cellNum) { return StopPos_NO_Bonus[resultId][cellNum]; }
    };
}