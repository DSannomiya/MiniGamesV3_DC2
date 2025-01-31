#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME04
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
        void Init(struct DATA* d);
    private:
        //�V�[������
        enum STATE { TITLE, PLAY,CLEAR,OVER };
        STATE State = TITLE;
        void Title(struct DATA* d);
        void Play(struct DATA* d);
        void Clear(struct DATA* d);
        void Over(struct DATA* d);
        int Collision(struct CHARA* c, struct BULLET* b);
        void Draw(struct DATA* d);
        void HpGauge(struct CHARA* c);
        int FireSoundP;
        int FireSoundPBOM;
        int FireSoundE;
        int FireSoundB;

        int DamageSndP;
        int DamageSndE;
        int DamageSndB;

        int BgmSound;
        
        int GAMECSound;
        int GAMEOSound;

        int PBulletsnd = 0;
        //int PBOMsnd = 0;
        int EBulletsnd = 0;
        //int BBulletsnd = 0;

        float hpWarning = 0.0f;
        float hpDanger = 0.0f;

        bool PBHitFlag = false;
        bool PBOMHitFlag = false;
        bool EBHitFlag = false;
        bool BBHitFlag = false;
        bool EHpGaugeFlag = true;

        struct DATA* d = 0;
        struct CHARA* c = 0;
        struct BULLET* b = 0;  
    };
    struct CHARA {
        //�e�摜�ԍ�
        int normalImg;
        int damageImg;
        int Imghp;
        //���݂̉摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�ړ������x�N�g��
        float vx;
        float vy;
        //�e���˃I�t�Z�b�g�ʒu
        float bulletOfsY;
        float bulletOfsX;

        //�̗�
        int hp;
        //MaxHp
        int MaxHp;
        //�g�o�Q�[�W�\���I�t�Z�b�g�ʒu
        float hpGaugeOfsY;
        //�����蔻��p�A�����̕��ƍ���
        float halfW;
        float halfH;
        //�G�l�~�[�̓|���ꂽ��
        int totalCnt = 0;
    };
    //�v���C���[�̒e��NPC�̒e�p�\���̌^
    struct BULLET {
        //�摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�����x�N�g��
        float vx;
        float vy;
        //�̗́H�i�E�B���h�E������ł��邩���Ӗ�����j
        int hp;
        //�����蔻��p�A�����̕��ƍ���
        float halfW;
        float halfH;
        int cnt = 0;
    };
    //�S�f�[�^���Ǘ�����\���̌^
    struct DATA {
        //----------------------------------------
        //RESULT�̎��A�L�[���͂𖳌�������t���[����
        int frameRestrictInput;
        int frameCnt;
        //----------------------------------------
        //�L�����N�^�f�[�^
        struct CHARA Player;
        struct CHARA Enemy;
        struct CHARA BOSS;
        struct BULLET PBullet;
        struct BULLET PBOM;
        struct BULLET EBullet;
        struct BULLET BBullet;
        int titleImg;
        int backImg;
    };
}
