#pragma once
#include"CHARACTER.h"
#include<time.h>
namespace GAME03 {
    class ENEMY :public CHARACTER {
    public:
        struct DATA {
            int rightAnimId = 0;
            int leftAnimId = 1;
            int jumpFlag = 0;
            int score = 0;
            int newscore = 0;
            int upDate = false;
            float curWx = 0;
            float initVecUp = 0;
            float initVecDown = 0;
            float gravity = 0;
            time_t s_time = 0, e_time = 0, n_time = 0;
        };
    private:
        DATA Enemy;
        enum class STATE { STRUGGLING, SURVIVED, DIED };
        STATE State = STATE::STRUGGLING;
        FILE* fp{};
    public:
        ENEMY(class GAME* game) :CHARACTER(game) {}
        void create();
        void appear(float wx, float wy, float vx, float vy);
        void update();
    private:
        void Move();
        void CollisionWithMap();
        void CheckState();
    public:
        bool died();
        float overCenterVx();
        int timeCnt = 0;
    };
}
