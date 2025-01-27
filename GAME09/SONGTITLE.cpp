#include "SONGTITLE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "textFunc.h"

namespace GAME09 {
	SONGTITLE::SONGTITLE(GAME* game) :
		GAME_OBJECT(game) {
	}
	SONGTITLE::~SONGTITLE() {
	}

	void SONGTITLE::create() {
		SongTitle = game()->container()->data().songTitle;
	}

	void SONGTITLE::init() {

	}

	void SONGTITLE::update() {

	}

	void SONGTITLE::draw(SONGINFO& songInfo, VECTOR2 pos, float size) {
		//�w�i
		image(SongTitle.bannerImg, pos.x, pos.y, 0, SongTitle.bannerImgSize * size);
		//�t���[��
		VECTOR2 framePos = pos + SongTitle.difficultyFrameOfst * size;
		imageColor(game()->difficultySelect()->getColor());
		image(SongTitle.difficultyFrameImg, framePos.x,
			framePos.y, 0, SongTitle.difficultyFrameImgSize * size);
		imageColor(255);
		//��Փx
		framePos.y += SongTitle.numStrSize.y / 2;
		font("�l�r ����");
		textfMode(M_CENTER);
		textfStrokeSize(2);
		fill(0);
		textfStroke(std::to_string(songInfo.difficulty[game()->difficultySelect()->curDifficulty()]),
			framePos, SongTitle.numStrSize);
		fill(255);
		textf(std::to_string(songInfo.difficulty[game()->difficultySelect()->curDifficulty()]),
			framePos, SongTitle.numStrSize);
		font("Arial");
		//�^�C�g��
		fill(0);
		textfMode(M_LEFT);
		VECTOR2 textPos = pos + SongTitle.titlePosOfst * size;
		textf(songInfo.title, textPos, SongTitle.titleStrSize * size);
		//�A�[�e�B�X�g
		textPos = pos + SongTitle.artistPosOfst * size;
		textf(songInfo.artist, textPos, SongTitle.artistStrSize * size);
	}
}