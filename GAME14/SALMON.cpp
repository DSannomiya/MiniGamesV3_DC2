#include"GAME14.h"
#include"CONTAINER.h"
#include "SALMON.h"
namespace GAME14 {
    SALMON::SALMON(class GAME* game):
        CHARACTER(game){}
    void SALMON::create(){
        Chara = game()->container()->data().salmonChara;
        Salmon = game()->container()->data().salmon;
    }
    void SALMON::init(){
        Chara.hp = 0;
        Salmon.pos = VECTOR2(width, height);
    }
    void SALMON::appear(float wx, float wy) {
            Chara.hp = 1;
            Salmon.pos = VECTOR2(wx, wy);
    }
    void SALMON::update(){
        Move();
    }
    void SALMON::Move(){
        Salmon.pos.y -= Chara.speed * delta+(game()->characterManager()->player()->overWindowCenter() -
            game()->characterManager()->player()->overWindowBottom());
        PLAYER* player = game()->characterManager()->player();
        MAP* map = game()->map();
        if (Salmon.pos.x + Chara.offsetLeft< player->Right() &&
            Salmon.pos.x + Chara.offsetRight>player->Left() &&
            Salmon.pos.y + Chara.offsetBottom > player->Top() &&
            Salmon.pos.y + Chara.offsetTop < player->Bottom()
            ) {
            Chara.hp = 0;
            if (player->stacSalmon() <=player->limitSalmon()) {
                player->countSalmon();
            }
        }
        if (Salmon.pos.y + Chara.offsetBottom < 0) Chara.hp = 0;
    }
    void SALMON::draw() {
        Salmon.animTime += delta;
        image(Salmon.img[Salmon.animCunt], Salmon.pos.x, Salmon.pos.y, 0, Salmon.imgSize);
        if (Salmon.animTime > Salmon.interval) {
            if(Salmon.animCunt){
                Salmon.animCunt %=1;
            }
            else {
            Salmon.animCunt ++;

            }
            Salmon.animTime -= Salmon.interval;
        }
   }

}