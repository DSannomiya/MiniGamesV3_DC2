#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME03.h"
#include"MAP.h"
#include "CHARACTER.h"
namespace GAME03 {
    CHARACTER::CHARACTER(GAME* game) :
        GAME_OBJECT(game) {
    }
    void CHARACTER::create() {
    }
    void CHARACTER::init() {
        Chara.hp = 0;
    }
    void CHARACTER::appear(float wx, float wy, float vx, float vy) {
        Chara.wx = wx;
        Chara.wy = wy;
        Chara.hp = 1;
    }
    void CHARACTER::update() {
        float px = Chara.wx - game()->map()->wx();
        if (px < -game()->map()->chipSize()) {
            Chara.hp = 0;
        }
    }
    void CHARACTER::draw() {
        imageColor(Chara.color);
        float px = Chara.wx - game()->map()->wx();
        float py = Chara.wy - game()->map()->wy();
        if (Chara.anims) {
            Chara.anims->anim(Chara.animId)->draw(&Chara.animData,
                px, py, Chara.angle, Chara.scale);
        }
        else if (Chara.anim) {
            Chara.anim->draw(&Chara.animData,
                px, py, Chara.angle, Chara.scale);
        }
        else {
            image(Chara.img, px, py, Chara.angle, Chara.scale);
        }
        image(Chara.shadowImg, px - 3440, py - 2050);
        if (isPress(KEY_P)) {
            fill(255);
            print((let)game()->map()->wDispRight());
            print((let)game()->map()->wDispLeft());
            print((let)Chara.wx);
            print((let)Chara.wy);
        }
    }
}
