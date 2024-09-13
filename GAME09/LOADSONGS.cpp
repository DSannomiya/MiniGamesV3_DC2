#include "CONTAINER.h"
#include "GAME09.h"
#include "LOADSONGS.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include <thread>

namespace GAME09 {
	LOADSONGS::LOADSONGS(class GAME* game) :
		SCENE(game) {

	}
	LOADSONGS::~LOADSONGS() {

	}
	void LOADSONGS::create() {
		//LoadSongs = game()->container()->data().title;
	}
	void LOADSONGS::init() {

	}
	void LOADSONGS::update() {
		bool stopFlag = false;
		// �����o�֐����X���b�h�ŌĂяo���ۂ�this�|�C���^��n��
		// ChatGPT�͐_�@�݂�Ȏg����
		std::thread msg(&LOADSONGS::loadingMsg, this, std::ref(stopFlag));

		//���ʃt�@�C���̓ǂݍ��ݏ���
		game()->chartMNG()->loadCharts();
		//std::this_thread::sleep_for(std::chrono::seconds(3));

		//�X���b�h���~�߂�
		stopFlag = true;
		msg.join();
	}
	void LOADSONGS::loadingMsg(bool& stopFlag) {
		float angle = 0;
		rectMode(CENTER);
		angleMode(DEGREES);
		while (!stopFlag) {
			angle += 1;
			clear();
			fill(100, 100, 100);
			rect(width / 2, height / 2, 200, 200, angle);
			fill(255);
			textSize(100);
			text("NowLoding...", width / 2, height / 2);
			present();
		}
	}
	void LOADSONGS::draw() {
		
	}
	void LOADSONGS::nextScene() {
		//�t���[�Y���Ă����Ԃ�����
		setDeltaTime();
		setDeltaTime();
		game()->changeScene(GAME::SELECT_ID);
	}
}