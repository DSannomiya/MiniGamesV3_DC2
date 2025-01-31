#pragma once
#include "GAME_OBJECT.h"
#include"LOTTERY.h"
namespace GAME14{
class CREDIT :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* payoutFileName;
        std::string separator;

        VECTOR2 drawPayoutPos;
        COLOR drawPayoutColor;
        float drawPayoutSize;

        float onePayoutTime;//�ꖇ�����o���̂ɂ����鎞��

        int BBPayoutMaxNum;//�����o�����������̖����𒴂�����BIG�{�[�i�X�I��
        int REGPlayMaxTime;//REG�̍ő�Q�[����
        int REGPayoutMaxTime;//REG���̍ő啥���o���� �����o������������1�Q�[�����炷
    };
    struct RESULT_DATA {
        int resultId = 0;
        int numPayout;//�������̕����o��
        int numMissPayout;//�񐬗����̕����o��
    };
private:
    DATA Credit;
    RESULT_DATA Result[LOTTERY::NUM_RESULT-1];
    int Payout;//�����o������
    int CurPayout;//�������略�������ꂽ��
    float CurTime;
    int BBPayoutCurNum;//BIG�{�[�i�X�������略���o������
    int REGPlayCurTime;//REG���̉񂵂��Q�[����
public:
    CREDIT(class GAME* game);
    ~CREDIT();
    void create();
    void init();
    void initResult();
    void update();
    void resultPayout(bool flag);
    void resultBonus(bool flag);
    void draw();
    void debagdraw();
    void clearCurPayout() { CurPayout = 0; }
};
}

