#include"TITLE.h"
#include"GAME06.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME06 
{
	void TITLE::create() {
		Title = game()->container()->data().title;
	}

	void TITLE::draw() {
		clear(Title.backScreenColor);
		fill(Title.textColor1);
		textSize(Title.textSize1);
		text(Title.str1, Title.textPos1.x, Title.textPos1.y);
		fill(Title.textColor2);
		textSize(Title.textSize2);
		text(Title.str2, Title.textPos2.x, Title.textPos2.y);
		rectMode(CORNER);	
		fill(128,128,128);
		rect(0, 0, Size * 10, Size * 4.5f);
		fill(0);
		textSize(Size);
		text("������@", 0, Size);
		text("��Ɉړ�����FW�L�[", 0, Size * 2);
		text("���Ɉړ�����FS�L�[", 0, Size * 3);
		text("�e�𔭎˂���FK�L�[", 0, Size * 4);
		fill(0);
		textSize(30);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, height);
	}

	void TITLE::nextScene() {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::STAGE_ID);
			game()->stage()->init();
		}
	}
}