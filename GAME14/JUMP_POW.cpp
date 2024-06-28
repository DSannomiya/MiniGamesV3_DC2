#include "JUMP_POW.h"
#include"GAME14.h"
#include"CONTAINER.h"
namespace GAME14 {
	JUMP_POW::JUMP_POW(class GAME* game):
		GAME_OBJECT(game){}
	JUMP_POW::~JUMP_POW() {}
	void JUMP_POW::create() {
		JumpPow = game()->container()->data().jumpPow;
		init();
	}
	void JUMP_POW::init() {
		CurState = X_DIRECTION;
		JumpPow.curPowX = 0;
		JumpPow.curPowY = 0;
		JumpPow.curTime = 0;
		JumpPow.endFlag = false;
	}
	void JUMP_POW::draw(VECTOR2 playerPos, float offsetRight,float vecX) {
		float underGaugeStartPosX = playerPos.x + offsetRight * ((1 - vecX) / 2);
		float sideGaugeStartPosX = playerPos.x + (-JumpPow.offsetX * vecX) + offsetRight * ((1 - vecX) / 2);
		//パワーゲージの枠
		strokeWeight(JumpPow.yardstickSize);

		fill(JumpPow.gaugeColor.r,JumpPow.gaugeColor.g,JumpPow.gaugeColor.b,JumpPow.gaugeColor.a);
		rect(underGaugeStartPosX, playerPos.y + JumpPow.offsetY,JumpPow.gaugeSizeW * vecX, JumpPow.gaugeSizeH);
		rect(sideGaugeStartPosX, playerPos.y+JumpPow.offsetY, JumpPow.gaugeSizeH, -JumpPow.gaugeSizeW);
		//パワーゲージ
		fill(JumpPow.curGaugeColor);
		rect(playerPos.x + offsetRight * ((1 - vecX) / 2), playerPos.y + JumpPow.offsetY,
			JumpPow.gaugeSizeW*JumpPow.curPowX*vecX, JumpPow.gaugeSizeH);
		rect(playerPos.x + (-JumpPow.offsetX * vecX) + offsetRight * ((1 - vecX) / 2), playerPos.y+JumpPow.offsetY, JumpPow.gaugeSizeH, -JumpPow.gaugeSizeW*JumpPow.curPowY);

		float lineOffset = JumpPow.gaugeSizeW / JumpPow.numEqual;
		for (int i = 1; i < JumpPow.numEqual; i++) {
			float underLineX = underGaugeStartPosX + lineOffset * vecX * i;
			float sideLineY = playerPos.y + JumpPow.offsetY - lineOffset * i;
			line(underLineX, playerPos.y + JumpPow.offsetY, underLineX, playerPos.y + JumpPow.offsetY + JumpPow.gaugeSizeH);
			line(sideGaugeStartPosX, sideLineY, sideGaugeStartPosX + JumpPow.gaugeSizeH, sideLineY);
		}
		strokeWeight(0);
	}
	void JUMP_POW::update() {
		if (isTrigger(MOUSE_LBUTTON)&&JumpPow.curTime>=JumpPow.startDirectionTime) {
			CurState = Y_DIRECTION;
		}
		JumpPow.curTime += delta;
		switch (CurState) {
		case X_DIRECTION:
			if (JumpPow.curPowX >= JumpPow.limitPow)JumpPow.curPowX -= JumpPow.limitPow;
				JumpPow.curPowX = JumpPow.curPowX + JumpPow.powSpeed*delta;
			break;
		case Y_DIRECTION:
			if (JumpPow.curPowY >= JumpPow.limitPow)JumpPow.curPowY -= JumpPow.limitPow;
			JumpPow.curPowY = JumpPow.curPowY + JumpPow.powSpeed*delta;
			JumpPow.endFlag = true;
			break;
		}
		
	}
}
