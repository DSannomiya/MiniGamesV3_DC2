#include <string>
#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME15.h"
#include <iomanip>
#include <sstream>
namespace GAME15
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{
	}

	void GAME::play()
	{
	}

	void GAME::move()
	{
	}

	void GAME::draw()
	{
		//string�ŕ�����+���������_��(��DeltaTime��float�Ȃ̂ŏ����_�ȉ�6�����f�t�H)
		print((std::string("�t���[���^�C��:") + std::to_string(DeltaTime)).c_str());

		//ostringstream�ŕ�����+���������_��(��cout�ގ��Ȃ̂ŏ����_���̖���0�̂̓J�b�g�����)
		std::ostringstream sss; //#include <stringstream>�Bsss��cout���ۂ����������\�ɂȂ�B
		sss << "�t���[���^�C��:" << DeltaTime;
		print(sss.str().c_str()); //ostringstream��str()��std::string�^�ɏo����Bstd::string�^��c_str()��const char*�ɏo����B

		//ostringstream��0�t20���̐���(�X�R�A��)
		sss.str(""); //sss�̍ė��p
		sss << std::setfill('0') << std::setw(20) << 999999999999999999i64;
		print(sss.str().c_str());

		//��ostringstream�ŉ��s�t��������(�Z���t��)�͂��܂������Ȃ�!!!
		//sss.str(""); //sss�̍ė��p
		//sss << "1�s��\n2�s��"; //����PEND; \n���E�ɂȂ�Btext()�͔�Ή��A�A�A
		//print(sss.str().c_str());
	}

	void GAME::proc()
	{
		clear(0, 0, 64);

		play();
		move();
		draw();

		fill(255);
		text("ENTER�L�[�Ń��j���[�ɖ߂�", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
