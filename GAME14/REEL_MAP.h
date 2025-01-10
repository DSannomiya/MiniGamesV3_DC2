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
        
        struct DATA {
            const char* reelMapFile = nullptr;//���[���z��̃t�@�C����
            const char* leftControlFile = nullptr;//Bonus�ɓ����ĂȂ����̍�����~���̃��[������t�@�C����
            int* reelData;//�}�b�v�f�[�^
            char* leftControlData = nullptr;//������~���̃��[������f�[�^
            int rows = 0;//���[���z��f�[�^�̍s��
            int cols = 0;//���[���z��f�[�^�̗�
            std::string separator;
        };

        struct CONTROL_DATA {
            int startId;//���ł��̃��[�����䂩
            //int resultId;//�Ȃ�̖��̃��[�����䂩
            //int bonusResultId;//�Ȃ�̃{�[�i�X���̃��[�����䂩
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
    private:
        DATA Map;
        int reelDataSize;
        std::string Str;
        int ID;
        int rowLength = 0;
        int StopCell = -1;
        CONTROL_DATA Control_Data [LOTTERY::NUM_NORMAL_RESULT] ;//�Ƃ肠���������[���̂�
    public:
        REEL_MAP(class GAME* game);
        ~REEL_MAP();
        void create();
        void init();
        int tellStopCell(int cellId,int reelId);
        void debagDraw();
        int textureNum(int reelId,int cellNum);
    };
}