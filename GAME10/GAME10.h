#pragma once
#include "../../libOne/inc/libOne.h"
#include "../MAIN/GAME_BASE.h"
namespace GAME10
{
    class GAME :
        public GAME_BASE
    {
    private:
        enum {
            TITLE,
            TUTORIAL,
            OPERATER,
            PLAY,
            RESULT
        };
        int STATE;
        struct button {
            VECTOR2 core;
            float radius = 100;
            float Hradius = radius / 2;
            bool SelectFlag = false;
        };
        struct button TutorialButton;
        struct button ProductionButton;
        struct button OperationButton;
        int buttonCnt = 0;
        enum ButtonState {
            STutorial,
            SProduction,
            SOperation,
            SButtonSum
        };
        //本番用マップ
        const char* fileName;
        FILE* fp;
        int fileSize;
        char* map;
        //チュートリアル用
        const char* CfileName;
        FILE* Cfp;
        int CfileSize;
        char* Tmap;
        //行列カウント用（本番用）
        struct matrix {
        int row = 0;//行
        int col = 0;//列
        int cnt = 0;
        int WallCnt = 0;
        int GoalCnt = 0;
        int InvisibleWallCnt = 0;
        int EnemyCnt = 0;
        int KeyCnt = 0;
        int FlagCnt = 0;
        };
        matrix Production;
        matrix Tutorial;
        //効果音
            int FindSound = 0;
            int MoveSound = 0;
            bool SoundFlag = false;
        //画像
            //タイトル画面・リザルト画面
            int TitleImg = 0;
            int TutorialClearImg = 0;
            int PageCnt = 0;
            int PageImg[2] = {0,0};
            int TutorialPage[2] = { 0,0 };
            const int PageSum = 2;
            int ClearImg = 0;
            int OverImg = 0;
            //button関連
            int TButtonImg = 0;
            int PbuttonImg = 0;
            int ObuttonImg = 0;
            //陰に隠れた画像
            int STButtonImg = 0;
            int SPbuttonImg = 0;
            int SObuttonImg = 0;
            //壁関連
            int WallImg = 0;
            int WallLeftImg = 0;
            int WallRightImg = 0;
            int WallUpImg = 0;
            int WallUnderImg = 0;
            int WallUpLeftCornerImg = 0;
            int WallUnderLeftCornerImg = 0;
            int WallUpRightCornerImg = 0;
            int WallUnderRightCornerImg = 0;
            //ゴール関連
            int goalImg = 0;
            int LockImg = 0;
            int KeyImg = 0;
            //フラッグ
            int FlagImg = 0;
        //当たり判定用
        struct HITBOX {
            VECTOR2 up;
            VECTOR2 under;
            VECTOR2 left;
            VECTOR2 right;
            VECTOR2 core;
        };
        struct DISTANCE {
            //各判定からの距離
            float UpDist;
            float UnderDist;
            float RightDist;
            float LeftDist;
            int PointFlag;
            enum {
                Up,
                Under,
                Left,
                Right
            };
        };
        struct Map {
            //画面関連
            int Xsize = 192;
            int XharfSize = Xsize / 2;
            int Ysize = 216;
            int YharfSize = Ysize / 2;
            int mIdx = 0;
            //マップの座標
            float px = 0;
            float py = 0;
            float worldX = 0;
            float worldY = 0;
        };
        struct wall {
            //壁関連のデータ
            float WaPx = 0;
            float WaPy = 0;
            int Xsize = 192;
            int XharfSize = Xsize / 2;
            int Ysize = 216;
            int YharfSize = Ysize / 2;
            bool LockFlag = false;
        };
        struct Item {
            VECTOR2 ItemCore;
            float Iradius = 30;
            int ItemKind = 0;
            bool Substance = false;
        };
        bool pauseFlag = true;
        int GetFlagCnt = 0;
        const int GetFlagLimit = 5;
        bool TutorialClearFlag = false;
        int Ftemp = 0;
        //当たり判定関係
        HITBOX HitBox;
        HITBOX WallBox;
        HITBOX PlayerBox;
        HITBOX EnemyBox;
        DISTANCE PDist;
        DISTANCE EDist;
        int Cmx = 0;//もし動いていた場合、引き戻す値（ｘ）
        int Cmy = 0;//もし動いていた場合、引き戻す値（ｙ）
        //goal関連
        bool GoalFlag = false;
        struct character {
            //移動関連
            float Cpx = 0;
            float Cpy = 0;
            float Mx = 5;
            float My = 5;
            //視界(敵のみが使用)
            float length = 300;
            float radius = 50;
            float Hradius = radius / 2;
            int View;
            //視界範囲
            float ViewUp;
            float  ViewUnder;
            float  ViewRight;
            float  ViewLeft;
            float ViewLen;
            //敵の動きの種類
            int Mkind = 0;
            //プレイヤーのみ使用する
            bool KeyFlag = false;
            //敵が壁にぶつかったか
            bool WallHitFlag = false;
            int Frieze = 0;
            int FindLen = 400;
            int WarningLen = 500;
        };
        //見ている位置の種類
        enum {
                Up,
                Right,
                Under,
                Left
            };
        int FriezeTime = 1500;
        enum  {
            UpDown,
            RightLeft,
            NoMove
        };
        //発見関連
        bool FindFlag = false;
        //動的確保用の変数
        struct STAGE {
            Map Wmap;
            wall* Wall;
            wall* WallCorner;
            wall* Goal;
            Item* Flag;
            Item* Key;
        };
        //動的確保する変数のステージ種類
        STAGE ProductionMap;
        STAGE TutorialMap;
        //敵
        character* Enemys;
        int Ecnt = 0;
        const int FrieseTime = 240;
        //プレイヤー
        character player;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void title();
        void buttonCol();
        void init();
        void tutorial();
        void operater();
        void play();
        void result();
            void Pmove();
            void Emove();
            void stageChange();
            void collision();
            void viewCollision(int e);
                void hitbox(int w);//プレイヤーと壁
                void hitbox(int w, int e);//敵と壁
                void wallHitBox(int w);
                    void playerHitBox();
                    void enemyHitBox(int e);
            void draw();
        void destroy();
    };
}
