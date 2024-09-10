#pragma once
#include "GAME_OBJECT.h"
//#include "NOTE.h"
//#include "RHYTHM_GAME_CONTROLLER.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>
#include <string>

namespace GAME09 {
    class CHARTMANAGER :
        public GAME_OBJECT
    {
    public:
        enum INFONAME {
            TITLE,
            ARTIST,
            CREDIT,
            MUSIC,
            BANNER,
            BACKGROUND,
            OFFSET,
            BASEBPM,
            MEASURE,
            VOLUME,
            LANES,
            NOTES,
            NUM_INFOS
        };
        enum COMMANDNAME {
            BPMCHANGE,
            MEASURECHANGE,
            NUM_COMMANDS
        };
        enum SCORE_DATAS {
            SCORE,
            ACHIEVEMENT,
            NUM_SCORE_DATAS
        };
        struct DATA {
            std::string infoStartStr[NUM_INFOS];
            std::string commandStr[NUM_COMMANDS];
            std::string scoreDataStr[NUM_SCORE_DATAS];
            std::string chartPath;
        };
    private:
        DATA ChartMNG;
        float AudioOffset = 0;  //�v���X�ɂ���ƋȂ�葁�������
        float VisualOffset = 0; //�v���X�ɂ���Ǝ�O�A�}�C�i�X�ɂ���Ɖ��ɓ���
        int Score = 0;
        int Achievement = -1;

    public:
        CHARTMANAGER(class GAME* game);
        ~CHARTMANAGER();
        void create();
        void init();

        //�Ԃ�l�͍Ō�̃m�[�c�̎���
        //double loadChart(const char* fileName, std::vector<NOTE*>& notes,
        //    std::vector<RHYTHM_GAME_CONTROLLER::CHANGEDATA>& changeDatas, RHYTHM_GAME_CONTROLLER::SONGINFO& songInfo);
        
        void loadCharts();
        void loadChartInfo(std::string fileName, struct SONGINFO& songInfo);
        void loadHiscore(std::string fileName);
        void loadChartImage(std::string chartPath, std::string fileName, int& idx, VECTOR2& size);

        float* audioOffsetPtr() { return &AudioOffset; }
        float* visualOffsetPtr() { return &VisualOffset; }
    };
}