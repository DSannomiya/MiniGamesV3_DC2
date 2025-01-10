#pragma once
#include"../../libOne//inc//VECTOR2.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{//���[���̓����A�\��,���̐�������
    public:
        enum PATTERN_ID {
            BONUS_A,
            BONUS_B,
            BAR,
            REPLAY,
            WATERMELON_A,
            WATERMELON_B,
            CHERRY,
            BELL_A,
            BELL_B,
            NUM_PATTERN
        };
        struct DATA {//�S�̋��ʃf�[�^
            int reelNum = 0;
            int img[NUM_PATTERN] = { 0 };
            int cellNum = 0;
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
        };
    private:
        struct REELS {//���[�����Ƃ̃f�[�^
            int reelId = -1;
            int beforeNum = 0;//�����O�̃R�}�ԍ�
            int afterNum = 0;//�~�܂�R�}�ԍ�
            float curNum = 0.0f;//���݉��i�ɕ\�����Ă���R�}�ԍ�
            bool animeFlag = false;//���[���������Ă��邩
            bool stopFlag = false;//���[�����~�܂�Ƃ��̃t���O
            bool setAfter = false;//afterNum����x�����ݒ肷��t���O
        };
        DATA Reels;
        REELS* Reel = 0;
        bool MoveFlag = false;//���[���S�̂𓮂����X�C�b�`
        float AnimeTime = 0.0f;//�����n�߂Ă���̎���
        int StopCunt = 0;//�~�߂����[���̃J�E���g
        int StopCell;
    public:
        REEL(class GAME* game);
        ~REEL();
        void create();
        void init();
        void update();
        void draw();
        void debagDraw();
        void stop(int i) { Reel[i].stopFlag = true; }
        void move() { MoveFlag = true; }
    };
}

