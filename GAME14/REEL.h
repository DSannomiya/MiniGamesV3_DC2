#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class REEL :
        public GAME_OBJECT{
    public:
        struct DATA {
            VECTOR2 pos = 0.0f;
            VECTOR2 cellSize = 0.0f;
            COLOR color = COLOR(0, 0, 0);
            int cellId[21] = { 0 };

        };
    protected:
        int ReelId = -1;//��~�{�^���Ƃ̎Q��
        int brank = -1;
        int MaxNum = 21;//�R�}��
        int DrawNum = 5;//�\���R�}��
        float RPM = 78.0f;//RotateParMinits
        int BeforeNum = 0;//�����O�̃R�}�ԍ�
        int AfterNum = 0;//�~�܂�R�}�ԍ�
        float CurNum = 0;//���ݒ��i�ɕ\�����Ă���R�}�ԍ�
        float AnimeTime = 0;//�����o���Ă���̎���
        float NeedTime = 0;//�P�R�}�����̂ɕK�v�Ȏ���
        bool AnimeFlag = false;//���[���������Ă��邩
        bool Stop = false;//���[�����~�܂�Ƃ��̃t���O
        bool SetAfter = false;//AfterNum����x�����ݒ肷��t���O
        bool Move = false;//���[���𓮂����X�C�b�`
        DATA Reel;
    public:
        REEL(class GAME* game):
            GAME_OBJECT(game){}
        ~REEL();
        virtual void create();
        void init(int reelId);
        virtual void update();
        void draw();
        void stop() { Stop = true; }
        void move() { Move = true; }
    };
}

