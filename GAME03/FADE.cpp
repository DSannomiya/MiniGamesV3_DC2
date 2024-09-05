#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/window.h"
#include"CONTAINER.h"
#include"GAME03.h"
#include "FADE.h"
namespace GAME03 {
    void FADE::create() {
        Fade = game()->container()->data().fade;
    }
    void FADE::inTrigger() {
        if (State == STATE::OUT_END) {
            State = STATE::IN_TRIGGER;
        }
    }
    void FADE::outTrigger() {
        if (State == STATE::IN_END) {
            State = STATE::OUT_TRIGGER;
        }
    }
    void FADE::draw() {
        if (State == STATE::IN_END ||
            State == STATE::OUT_END) {
            return;
        }
        rectMode(CORNER);
        colorMode(RGB, 255);
        switch (State) {
        case STATE::IN_TRIGGER:
            Fade.color.a = 255;
            fill(Fade.color);
            rect(0, 0, width, height);
            State = STATE::IN_NOW;
            break;
        case STATE::IN_NOW:
            fill(Fade.color);
            rect(0, 0, width, height);
            Fade.color.a += -Fade.speed * delta;
            if (Fade.color.a < 0.0) {
                Fade.color.a = 0.0f;
                State = STATE::IN_END;
            }
            break;
        case STATE::OUT_TRIGGER:
            Fade.color.a = 0.0f;
            State = STATE::OUT_NOW;
            break;
        case STATE::OUT_NOW:
            fill(Fade.color);
            rect(0, 0, width, height);
            Fade.color.a += Fade.speed * delta;
            if (Fade.color.a >= 255.0f) {
                Fade.color.a = 255.0f;
                State = STATE::OUT_END;
            }
            break;
        }
    }
    int FADE::inEndFlag() const {
        return (State == STATE::IN_END);
    }
    int FADE::outEndFlag() const {
        return (State == STATE::OUT_END);
    }
    void FADE::setColor(const COLOR& color) {
        Fade.color = color;
    }
    void FADE::setSpeed(float speed) {
        Fade.speed = speed;
    }
}