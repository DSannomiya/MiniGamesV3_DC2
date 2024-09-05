#pragma once
#include"GAME_OBJECT.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME03 {
    class FADE :public GAME_OBJECT {
    public:
        struct DATA {
            COLOR color;
            float speed = 0;
        };
    private:
        DATA Fade;
        enum class STATE {
            IN_TRIGGER, IN_NOW, IN_END,
            OUT_TRIGGER, OUT_NOW, OUT_END
        };
        STATE State = STATE::OUT_END;
    public:
        FADE(class GAME* game) : GAME_OBJECT(game) {}
        void create();
        void inTrigger();
        void outTrigger();
        void draw();
        int outEndFlag() const;
        int inEndFlag() const;
        void setSpeed(float speed);
        void setColor(const COLOR& color);
    };
}
