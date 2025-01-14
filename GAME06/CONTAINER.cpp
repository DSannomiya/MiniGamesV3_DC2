#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
namespace GAME06{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}

	void CONTAINER::setData() {
		//�^�C�g���f�[�^
		Data.title.bgColor = { 128,128,128 };
		Data.title.textSize = 150;
		Data.title.textColor = { 0,0,0 };
		Data.title.pos.x = 650;
		Data.title.pos.y = 550;
		Data.title.str = "�ˌ��̒B�l";
		Data.title.textSize2 = 50;
		Data.title.textColor2 = { 0,0,0 };
		Data.title.pos2.x = 550;
		Data.title.pos2.y = 720;
		Data.title.str2 = "SPACE�L�[�ŃX�e�[�W�֐i��";
		//�X�e�[�W�f�[�^
		Data.stage.bgColor = { 128,128,128 };
		//�Q�[���N���A�f�[�^
		Data.gameClear.bgColor = { 128,128,128 };
		Data.gameClear.textSize = 150;
		Data.gameClear.textColor = { 0,255,0 };
		Data.gameClear.pos.x = 500;
		Data.gameClear.pos.y = 650;
		Data.gameClear.str = "��������";
		//�Q�[���I�[�o�[�f�[�^
		Data.gameOver.bgColor = { 128,128,128 };
		Data.gameOver.textSize = 150;
		Data.gameOver.textColor = { 255,0,0 };
		Data.gameOver.pos.x = 500;
		Data.gameOver.pos.y = 650;
		Data.gameOver.str = "�������s";
		//�v���C���[�f�[�^
		Data.player.pos = { 100,height / 2 };
		Data.player.radius = 50;
		Data.player.advSpeed = 120;
		Data.player.fillColor = { 0,225,0 };
		Data.player.hp = 100;
		//�G�l�~�[�f�[�^
		Data.enemy.pos = { width - 150,height / 2 };
		Data.enemy.radius = 100;
		Data.enemy.fillColor = { 235,0,185 };
		Data.enemy.hp = 150;
	}

	void CONTAINER::loadGraphic() {

	}
}