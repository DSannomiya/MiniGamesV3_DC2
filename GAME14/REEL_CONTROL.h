#pragma once
#include"GAME_OBJECT.h"
#include<vector>
namespace GAME14{
	class REEL_CONTROL ://�}���z�u�ǂݍ��݁A���[������
		public GAME_OBJECT{
	public:
		struct DATA {
			int img[10]{ 0 };
			const char* ControlFILEName;

		};
	private:
		DATA Information;
	public:
		REEL_CONTROL(class GAME* game):
			GAME_OBJECT(game){}
		~REEL_CONTROL();
		void create();
		void proc();//�}���̔z�u�A���[������̏��A�ǂݍ���
		
	};
}

