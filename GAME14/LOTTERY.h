#pragma once
#include "GAME_OBJECT.h"
#include<vector>
#include<string>
#include<map>
#include<random>
namespace GAME14 {
    class LOTTERY ://�t���O���I�N���X
        public GAME_OBJECT{
    public:
        enum PROB_ID {//�m���pID
            REPLAY,
            BELL_A,
            BB_BELL_A,//BB���̒��i�����x��
            BELL_B,//�P��
            BELL_B_BB,//B_BB�t��BELL_B
            BB_BELL_B,//BB���̎΂ߑ����x��
            BB_EX_BELL,//BB���̃o���P��
            WATERMELON_A,
            WATERMELON_B,
            CHERRY_A1,//�P��
            CHERRY_A1_RB,//R_BB�t��THERRY_A1
            CHERRY_A2,
            CHERRY_B,//�P��
            CHERRY_B_RB,//R_BB�t��THERRY_B
            CHERRY_B_BB,//B_BB�t��THERRY_B
            CHERRY_B_REG,//REG�t��THERRY_B
            EX_A_RB,//R_BB�Ή��ꖇ��EX_A
            EX_A_BB,//B_BB�Ή��ꖇ��EX_A
            EX_B_BB,//B_BB�Ή��ꖇ��EX_B
            EX_B_REG,//REG�Ή��ꖇ��EX_B
            EX_C_RB,//R_BB�Ή��ꖇ��EX_C
            EX_D_RB,
            EX_D_BB,
            EX_E_BB,//B_BB�Ή��ꖇ��EX_D
            EX_E_REG,//REG�Ή��ꖇ��EX_D
            EX_F_RB,//R_BB�Ή��ꖇ��EX_E
            EX_F_BB,//B_BB�Ή��ꖇ��EX_E
            EX_F_REG,//REG�Ή��ꖇ��EX_E
            R_BB,//�P��
            B_BB,//�P��
            REG,//�P��
            CHALLENGE,//REG���Z�p����� ���s: 4�� ����:15��
            LUCKY,      //REG���Z�p����� ���s:4�� ����:15��
            NUM_PROB
        };
        
        enum RESULT_ID {//�����̎�ނ܂��̓��[������̎��
            Hazure,
            Replay,
            Bell_A,
            Bell_B,
            Watermelon_A,
            Watermelon_B,
            Cherry_A1,
            Cherry_A2,
            Cherry_B,
            Ex_A,
            Ex_B,
            Ex_C,
            Ex_D,
            Ex_E,
            Ex_F,
            BB_Bell_A,
            BB_Bell_B,
            Ex_Bell,//�{�i/�x��/�x��
            Challenge,
            Lucky,//��z/�x��/�x��//challenge��Lucky�̊m��������
            NUM_RESULT
        };
        enum BONUS_ID {//�{�[�i�X�̎��
            
            NO_BONUS,
            RED_BB,
            BLUE_BB,
            REGULAR,
            NUM_BONUS,
            
        };
        enum STATE_ID {//�Q�[���t���[�̂ǂ��ɂ��邩
            ALL,//�{�[�i�X���ȊO
            NORMAL,
            BONUS,
            BB,
            RG
        };

        enum LEVEL {
            LEVEL_1 = 1,
            LEVEL_2,
            LEVEL_3,
            LEVEL_4,
            LEVEL_5,
            LEVEL_6,
            NUM_LEVEL
        };
        struct DATA {

            const char* fileName = nullptr;

            int  probFlagMax = 0;

            int levelFlagMax = 0;//���x�������߂闐���̍ő�l
            int levelWaite[NUM_LEVEL];//�e���x���̏d��(�o�₷��)

            std::string separator;


        };
        struct PROB_DATA {
            int stateId = 0;

            int level1 = 0;
            int level2 = 0;
            int level5 = 0;
            int level6 = 0;
            int& operator [](int level) {
                switch (level) {
                    case 1:
                        return level1;
                    case 2:
                        return level2;
                    case 5:
                        return level5;
                    case 6:
                        return level6;
                }
            }

        };
    private:
        PROB_DATA Prob[NUM_PROB];
        DATA Lottery;
        std::map<std::string,PROB_ID> ProbId;
        std::map<std::string, STATE_ID> StateId;
        std::map<std::string, RESULT_ID> ResultId;
        std::map<std::string, BONUS_ID> BonusId;
        std::mt19937 Mt;
        std::uniform_int_distribution<int>Dist;
        int Level;
        int Result;//������������
        int BonusResult;//�������̃{�[�i�X
        int State;//���݂̃Q�[���̏��
    public:
        LOTTERY(class GAME* game) :
            GAME_OBJECT(game) {}
        ~LOTTERY();
        void create();
        void init();
        void initProb();
        void createLevel();
        void proc();
        void debugdraw();
        void playlottery();
        void initProbId();
        void initStateId();
        void initResultId();
        void initBonusId();
        void deletResult() { Result = -1; }
        int result() { return Result ; }
        int bonusResult(){ return BonusResult ; }
        void clearBonusResult() { BonusResult = NO_BONUS; }
        void setResult(int id);
        int resultId(std::string str) { return ResultId[str]; }
        int bonusId(std::string str) { return BonusId[str]; }
        int state() { return State; }
        bool stateBonus() {
            if (State > BONUS) { return true; }
            else { return false; }
        }
        void changeStateBB() { State = BB; }
        void changeStateREG() { State = RG; }
        void changeStateNORMAL() { State = NORMAL; }
    };
}

