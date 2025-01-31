#pragma once
#include "GAME_OBJECT.h"
#include "NOTE.h"
#include "SONGINFO.h"
#include <vector>
#include <string>

namespace GAME09 {
    class RHYTHM_GAME_CONTROLLER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            float rawSpeed;
            float BeforePlayTime;
            float detailViewTime;
            float detailViewDisappearTime;
        };
        enum STATE {
            DETAIL_VIEW,
            BEFORE_PLAY,
            PLAY,
            AFTER_PLAY
        };
    private:
        DATA RGCont;
        SONGINFO SongInfo;

        double BPM;
        VECTOR2 Measure;
        double Offset;
        double TempTime;       //bpm�Ȃǂ��ς�����Ƃ��ɂ��̎��_�̎��Ԃ��L�^���Ă���
        double CurTime;        //���݂̎���
        double TempVisualBeat; //bpm�Ȃǂ��ς�����Ƃ��ɂ��̎��_�̌����ڏ�̔������L�^���Ă���
        double VisualBeat;     //���݂̌����ڏ�̔���
        double EndTime;        //�Ō�̃m�[�c�̎���

        STATE State;
        bool Finish = false;
        float AnimeTime;

        float* Speed = nullptr;
    public:
        RHYTHM_GAME_CONTROLLER(class GAME* game);
        ~RHYTHM_GAME_CONTROLLER();
        void create();
        void init();
        void update();
        void draw();

        double curTime() { return CurTime; }
        double visualBeat() { return VisualBeat; }
        float speed() { return *Speed; }
        float rawSpeed() { return RGCont.rawSpeed; }
        bool isChangeScene() { return Finish; }
        bool isPlay() { return State == PLAY; }

        void setEndTime(double endTime) { EndTime = endTime; }
    };
}