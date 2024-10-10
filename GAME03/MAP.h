#pragma once
#include"GAME_OBJECT.h"
namespace GAME03 {
    class MAP :public GAME_OBJECT {
    public:
        struct DATA {
            const char* fileName = 0;
            int blockImg = 0;
            int goalImg = 0;
            int chipSize = 0;//正方形マップチップ画像の一辺のドット数
            char* data = 0;  //データ配列のポインタ
            int cols = 0;    //データの列数
            int rows = 0;    //データの行数
            int dispCols = 0;
            int dispRows = 0;
            float wx = 0;    //world position x
            float wy = 0;    //world position y
            float worldWidth = 0;
            float worldHeight = 0;
            float endWorldX = 0;
            float endWorldY = 0;
            float centerX = 0;
        };
        enum CHARA_ID {
            PLAYER1_ID = 'a',
            PLAYER2_ID = 'a',
            PLAYER3_ID = 'a',
            PLAYER4_ID = 'a',
            PLAYER5_ID = 'a',
        };
    private:
        DATA Map;
    public:
        MAP(class GAME* game);
        ~MAP();
        void create();
        void init();
        void update();
        void draw();
        float wx() const { return Map.wx; }
        float wy() const { return Map.wy; }
        int chipSize() const { return Map.chipSize; }
        bool collisionCheck(float wx, float wy) const;
        bool collisionCharaLeft(float wx, float wy) const;
        bool collisionCharaRight(float wx, float wy) const;
        bool collisionCharaTop(float wx, float wy) const;
        bool collisionCharaBottom(float wx, float wy) const;
        float wDispLeft() const;
        float wDispRight() const;
    };
}