#include "CONTAINER.h"
#include "GAME09.h"
#include "LOADCHART.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include <thread>

namespace GAME09 {
	LOADCHART::LOADCHART(class GAME* game) :
		SCENE(game) {

	}
	LOADCHART::~LOADCHART() {

	}
	void LOADCHART::create() {
		LoadChart = game()->container()->data().loadChart;
	}
	void LOADCHART::init() {

	}
	void LOADCHART::update() {
		bool stopFlag = false;
		SONGINFO& songInfo = game()->songs()[game()->banner()->curNum()];
		NumRow = game()->chartMNG()->cntRows(songInfo);
		CurRow = 0;
		// �����o�֐����X���b�h�ŌĂяo���ۂ�this�|�C���^��n��
		// ChatGPT�͐_�@�݂�Ȏg����
		std::thread msg(&LOADCHART::loadingMsg, this, std::ref(stopFlag));

		//���ʃt�@�C���̓ǂݍ��ݏ���
		//std::this_thread::sleep_for(std::chrono::milliseconds(300));
		game()->chartMNG()->loadChart(songInfo, CurRow);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		//�X���b�h���~�߂�
		stopFlag = true;
		msg.join();
	}
	void LOADCHART::loadingMsg(bool& stopFlag) {
		rectMode(CENTER);
		while (!stopFlag) {
			clear();

			int percent = (CurRow * 100) / NumRow;
			char str[128];
			sprintf_s(str, 128, "%3d��", percent);

			textSize((float)LoadChart.msgSize);
			fill(255);
			text("NowLoading...", LoadChart.msgPos.x, LoadChart.msgPos.y);
			text(str, LoadChart.percentPos.x, LoadChart.percentPos.y);
			fill(100);
			rect(LoadChart.barPos.x, LoadChart.barPos.y, LoadChart.barSize.x, LoadChart.barSize.y);
			fill(0, 200, 255);
			rect(LoadChart.barPos.x - LoadChart.barSize.x / 200 * (100 - percent), LoadChart.barPos.y,
				LoadChart.barSize.x / 100 * percent, LoadChart.barSize.y);
			present();
		}
	}
	void LOADCHART::draw() {

	}
	void LOADCHART::nextScene() {
		//�t���[�Y���Ă����Ԃ�����
		setDeltaTime();
		setDeltaTime();
		game()->changeScene(GAME::STAGE_ID);
	}
}