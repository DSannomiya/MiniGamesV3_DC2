#include"GAME03.h"
#include "GAME_OBJECT.h"
namespace GAME03 {
    GAME_OBJECT::GAME_OBJECT(class GAME* game) {
        Game = game;
    }
    GAME_OBJECT::~GAME_OBJECT() {
        Game = nullptr;
    }
}
