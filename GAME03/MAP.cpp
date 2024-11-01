#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#include"GAME03.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include "MAP.h"
namespace GAME03 {
    MAP::MAP(class GAME* game) : GAME_OBJECT(game) {
    }
    MAP::~MAP() {
        if (Map.data) { delete[] Map.data; Map.data = 0; }
    }
    void MAP::create() {
        Map = game()->container()->data().map;
    }
    void MAP::init() {
        Map.wx = 0.0f;
    }
    void MAP::update() {
        Map.wx += game()->characterManager()->player()->overCenterVx();
        Map.wy += game()->characterManager()->player()->overCenterVy();
        //if (Map.wy > Map.endWorldY) {
        //    Map.wy = Map.endWorldY;
        //}
        //if (Map.wx > Map.endWorldX) {
        //    Map.wx = Map.endWorldX;
        //}
    }
    void MAP::draw() {
        float wx = game()->characterManager()->player()->overCenterVx();
        float wy = game()->characterManager()->player()->overCenterVy();
        game()->characterManager()->appear('a', wx, wy);
    }
    bool MAP::collisionCheck(float wx, float wy) const {
        return false;
    }
    bool MAP::collisionCharaLeft(float wx, float wy) const {
        bool leftTop = collisionCheck(wx, wy);
        bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
        return leftTop || leftBottom;
    }
    bool MAP::collisionCharaRight(float wx, float wy) const {
        bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
        bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
        return rightTop || rightBottom;
    }
    bool MAP::collisionCharaTop(float wx, float wy) const {
        bool topLeft = collisionCheck(wx, wy);
        bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
        return topLeft || topRight;
    }
    bool MAP::collisionCharaBottom(float wx, float wy) const {
        bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);
        bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);
        return bottomLeft || bottomRight;
    }
    float MAP::wDispLeft() const {
        return Map.wx - Map.chipSize;
    }
    float MAP::wDispRight() const {
        return Map.wx + width;
    }
}
