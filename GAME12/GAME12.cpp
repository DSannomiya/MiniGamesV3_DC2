#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME12.h"
namespace GAME12
{
	int GAME::create()
	{
		return 0;
	}

	void GAME::destroy()
	{

	}

	void GAME::proc()
	{
		//�V�[���؂�ւ�
		if (State == TITLE)title();
		else if (State == INIT)init();
		else if (State == WAIT)wait();
		else if (State == PLAY1)play1();
		else if (State == PLAY2)play2();
		else if (State == PLAY3)play3();
		else if (State == PLAY4)play4();
		else if (State == OVER)over();
		else if (State == END)end();
	}
	void GAME::randomnum() {
		rnum = 0;
		srand((unsigned)time(NULL));
		for (int i = 0; i < 15; i++) {
			rnum = rand() % Qnumber;
			num[i] = rnum;
			for (int j = 0; j < i; j++) {
				if (num[j] == rnum) {
					i--;
					break;
				}
			}
		}
	}
	
	INPUT_CODE GAME::gettriggerkeycode() {
		for (int i = (int)KEY_A; i <= (int)KEY_ENTER; i++) {
			if (isTrigger((INPUT_CODE)i)) {
				return (INPUT_CODE)i;
			}
		}
		return (INPUT_CODE)0;
	}
	std::map<INPUT_CODE, std::string>KeytoAlphabet = {
		{KEY_Q, "q"},{KEY_W, "w"},{KEY_E, "e"},
		{KEY_R, "r"},{KEY_T, "t"},{KEY_Y, "y"},
		{KEY_U, "u"},{KEY_I, "i"},{KEY_O, "o"},
		{KEY_P, "p"},{KEY_A, "a"},{KEY_S, "s"},
		{KEY_D, "d"},{KEY_F, "f"},{KEY_G, "g"},
		{KEY_H, "h"},{KEY_J, "j"},{KEY_K, "k"},
		{KEY_L, "l"},{KEY_Z, "z"},{KEY_X, "x"},
		{KEY_C, "c"},{KEY_V, "v"},{KEY_B, "b"},
		{KEY_N, "n"},{KEY_M, "m"},{KEY_SPACE, " "},
		{KEY_ENTER, "@"},
	};
	
	std::map<std::string, std::string> wardmap = {
		{"ka", "��"},{"ki", "��"},{"ku", "��"},
		{"ke", "��" }, {"ko", "��" },{"sa", "��" }, 
		{"si", "��"},{"shi", "��"} ,{"su", "��"},
		{"se", "��"}, {"so", "��"},{"ta", "��"},
		{"ti", "��"},{"chi", "��"}, {"tu", "��"},
		{"tsu", "��"}, {"te", "��"},{"to", "��"},
		{"na", "��"}, {"ni", "��"},{"nu", "��"},
		{"ne", "��"},{"no", "��"},{"ha", "��"},
		{"hi", "��"},{"fu", "��"}, {"hu", "��"},
		{"he", "��"}, {"ho", "��"},{"ma", "��"},
		{"mi", "��"},{"mu", "��"}, {"me", "��"},
		{"mo", "��"},{"ya", "��"}, {"yu", "��"},
		{"yo", "��"},{"ra", "��"}, {"ri", "��"},
		{"ru", "��"}, {"re", "��"},{"ro", "��"},
		{"wa", "��"}, {"wo", "��"},{"nn", "��"},
		{"nn", "��"},{"ga", "��"}, {"gi", "��"},
		{"gu", "��"}, {"ge", "��"},{"go", "��"},
		{"za", "��"}, {"ji", "��"},{"zi", "��"},
		{"zu", "��"},{"ze", "��"}, {"zo", "��"},
		{"da", "��"}, {"di", "��"},{"du", "��"},
		{"de", "��"},{"do", "��"},{"ba", "��"},
		{"bi", "��"},{"bu", "��"}, {"be", "��"},
		{"bo", "��"},{"pa", "��"}, {"pi", "��"},
		{"pu", "��"}, {"pe", "��"},{"po", "��"},
		{"kya", "����"}, {"kyu", "����"},{"kyo", "����"},
		{"sya", "����"}, {"sha", "����"},{"syu", "����"},
		{"shu", "����"},{"syo", "����"}, {"sho", "����"},
		{"tya", "����"}, {"cya", "����"},{"cha", "����"}, 
		{"tyu", "����"},{"cyu", "����"}, {"chu", "����"},
		{"tyo", "����"},{"cyo", "����"},{"cho", "����"},
		{"nya", "�ɂ�"}, {"nyu", "�ɂ�"},{"nyo", "�ɂ�"},
		{"hya", "�Ђ�"}, {"hyu", "�Ђ�"},{"hyo", "�Ђ�"},
		{"mya", "�݂�"}, {"myu", "�݂�"},{"myo", "�݂�"},
		{"rya", "���"}, {"ryu", "���"},{"ryo", "���"},
		{"gya", "����"}, {"gyu", "����"},{"gyo", "����"},
		{"ja", "����"}, {"jya", "����"},{"zya", "����"},
		{"ju", "����"},{"jyu", "����"}, {"zyu", "����"},
		{"jo", "����"}, {"jyo", "����"},{"zyo", "����"},
		{"bya", "�т�"}, {"byu", "�т�"},{"byo", "�т�"},
		{"pya", "�҂�"}, {"pyu", "�҂�"},{"pyo", "�҂�"},
		{"xtsu", "��"}, {"ltsu", "��"},{"xa", "��"},
		{"la", "��"},{"xi", "��"}, {"li", "��"},
		{"xu", "��"}, {"lu", "��"},{"xe", "��"},
		{"le", "��"},{"xo", "��"}, {"lo", "��"},
		{"xya", "��"}, {"lya", "��"},{"xyu", "��"},
		{"lyu", "��"},{"xyo", "��"}, {"lyo", "��"},
		{"xwa", "��"}, {"lwa", "��"},

		{"kka", "����"}, {"kki", "����"},
		{"kku", "����"}, {"kke", "����"},
		{"kko", "����"},
		{"ssa", "����"}, {"ssi", "����"},
		{"sshi","����"}, {"ssu", "����"},
		{"sse", "����"}, {"sso", "����"},
		{"tta", "����"}, {"tti", "����"},
		{"cchi", "����"}, {"ttu", "����"},
		{"ttsu", "����"}, {"tte", "����"},
		{"tto", "����"},
		{"nna", "����"}, {"nni", "����"},
		{"nnu", "����"}, {"nne", "����"},
		{"nno", "����"},
		{"hha", "����"}, {"hhi", "����"},
		{"ffu", "����"}, {"hhu", "����"},
		{"hhe", "����"}, {"hho", "����"},
		{"mma", "����"}, {"mmi", "����"},
		{"mmu", "����"}, {"mme", "����"},
		{"mmo", "����"},
		{"yya", "����"}, {"yyu", "����"},
		{"yyo", "����"},
		{ "rra", "����" }, { "rri", "����" },
		{ "rru", "����" }, { "rre", "����" },
		{ "rro", "����" },
		{ "wwa", "����" }, { "wwo", "����" },
		{ "gga", "����" }, { "ggi", "����" },
		{ "ggu", "����" }, { "gge", "����" },
		{ "ggo", "����" },
		{ "zza", "����" }, { "jji", "����" },
		{ "zzi", "����" }, { "zzu", "����" },
		{ "zze", "����" }, { "zzo", "����" },
		{ "dda", "����" }, { "ddi", "����" },
		{ "ddu", "����" }, { "dde", "����" },
		{ "ddo", "����" },
		{ "bba", "����" }, { "bbi", "����" },
		{ "bbu", "����" }, { "bbe", "����" },
		{ "bbo", "����" },
		{ "ppa", "����" }, { "ppi", "����" },
		{ "ppu", "����" }, { "ppe", "����" },
		{ "ppo", "����" },
		{ "kkya", "������" }, { "kkyu", "������" },
		{ "kkyo", "������" },
		{ "ssya", "������" }, { "ssha", "������" },
		{ "ssyu", "������" }, { "sshu", "������" },
		{ "ssyo", "������" }, { "ssho", "������" },
		{ "ttya", "������" }, { "ccya", "������" },
		{ "ccha", "������" }, { "ttyu", "������" },
		{ "ccyu", "������" }, { "cchu", "������" },
		{ "ttyo", "������" }, { "ccyo", "������" },
		{ "ccho", "������" },
		{ "hhya", "���Ђ�" }, { "hhyu", "���Ђ�" },
		{ "hhyo", "���Ђ�" },
		{ "mmya", "���݂�" }, { "mmyu", "���݂�" },
		{ "mmyo", "���݂�" },
		{ "rrya", "�����" }, { "rryu", "�����" },
		{ "rryo", "�����" },
		{ "ggya", "������" }, { "ggyu", "������" },
		{ "ggyo", "������" },
		{ "jja", "������" }, { "jjya", "������" },
		{ "zzya", "������" }, { "jju", "������" },
		{ "jjyu", "������" }, { "zzyu", "������" },
		{ "jjo", "������" }, { "jjyo", "������" },
		{ "zzyo", "������" },
		{ "bbya", "���т�" }, { "bbyu", "���т�" },
		{ "bbyo", "���т�" },
		{ "ppya", "���҂�" }, { "ppyu", "���҂�" },
		{ "ppyo", "���҂�" },
		{ "xtsu", "��" }, { "ltsu", "��" },
		{ "xxa", "����" }, { "lla", "����" },
		{ "xxi", "����" }, { "lli", "����" },
		{ "xxu", "����" }, { "llu", "����" },
		{ "xxe", "����" }, { "lle", "����" },
		{ "xxo", "����" }, { "llo", "����" },
		{ "xxya", "����" }, { "llya", "����" },
		{ "xxyu", "����" }, { "llyu", "����" },
		{ "xxyo", "����" }, { "llyo", "����" },
		{ "xxwa", "����" }, { "llwa", "����" },
		{ "a", "��" }, { "i", "��" }, { "u", "��" },
		{ "e", "��" }, { "o", "��" },
	};

	void GAME::recordInputToKana() {

		INPUT_CODE code = gettriggerkeycode();

		if (code == (INPUT_CODE)0) {
			return;
		}

		if (KeytoAlphabet.find(code) != KeytoAlphabet.end()) {
			std::string keyStr = KeytoAlphabet[code];
			stop = 1;
			if (keyStr != "@" && stop == 1) {
				
				currentInput += keyStr;
				stop = 0;
				if (!currentInput.empty()) {

					if (wardmap.find(currentInput) != wardmap.end()) {
						ch += wardmap[currentInput];
						currentInput.clear();
					}
				}
			}

			else if (keyStr == "@") {
				flag = 1;
				return;
			}
		}
	}
	
	void GAME::title() {
		//�`��--------------------------------------------------
		clear(120);
		//�e�L�X�g���
		fill(0, 255, 0);
		textSize(100);
		text("��������", 600, 450);
		fill(0, 0, 0);
		textSize(40);
		text("�N���b�N�ŃQ�[���X�^�[�g", 750, 500);
		text("Enter�Ń��j���[�ɖ߂�", 750, 550);
		//�V�[���؂�ւ�-----------------------------------------

		if (isTrigger(MOUSE_LBUTTON)) {
			//���̃V�[�P���X
			State = INIT;
			return;
		}
		//���j���[�ɖ߂�-----------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}

	void GAME::init() {
		clear(120);
		flag = 0;
		number = 0;
		set = 0;
		curtime = 30.0;
		stop = 0;
		count = 0;
		ch.clear();
		currentInput.clear();
		fill(0, 0, 0);
		textSize(60);
		text("�\�����ꂽ�����̓ǂ݂�30�b�ȓ��œ��Ă�", 525, 200);
		text("���͊m��or������ENTER", 525, 300);
		text("Q�@��2��", 575, 400);
		text("W�@2��", 575, 500);
		text("E�@��1��", 575, 600);
		text("R�@1��", 575, 700);
		if (isTrigger(KEY_Q)) {
			set = 1;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_W)) {
			set = 2;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_E)) {
			set = 3;
			State = WAIT;
			return;
		}
		else if (isTrigger(KEY_R)) {
			set = 4;
			State = WAIT;
			return;
		}
	}

	void GAME::wait() {
		clear(200);
		textSize(60);
		if (set == 1) {
			text("��2���ŊJ�n", 525, 600);
		}
		else if (set == 2) {
			text("2���ŊJ�n", 525, 600);
		}
		else if (set == 3) {
			text("��1���ŊJ�n", 525, 600);
		}
		else if (set == 4) {
			text("1���ŊJ�n", 525, 600);
		}
		text("�G���^�[�L�[�ŃX�^�[�g", 625, 400);
		text("�X�y�[�X�L�[�Ŗ߂�", 675, 500);
		if (isTrigger(KEY_ENTER) && set == 1) {
			clear(200);
			randomnum();
			State = PLAY1;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 2) {
			clear(200);
			randomnum();
			State = PLAY2;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 3) {
			clear(200);
			randomnum();
			State = PLAY3;
			return;
		}
		else if (isTrigger(KEY_ENTER) && set == 4) {
			clear(200);
			randomnum();
			State = PLAY4;
			return;
		}
		else if (isTrigger(KEY_SPACE)) {
			clear(200);
			State = INIT;
			return;
		}
	}

	void GAME::draw1(int snum) {
		fill(100);
		textSize(200);
		text((let)+pretwoWard[snum][0], 550, 300);
		textSize(50);
		if(ch.empty()){ 
			text(currentInput.c_str(), 600, 800); 
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("�Q�[���I���@���N���b�N", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw2(int snum) {
		fill(100);
		textSize(200);
		text((let)+twoWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("�Q�[���I���@���N���b�N", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw3(int snum) {
		fill(100);
		textSize(200);
		text((let)+preoneWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("�Q�[���I���@���N���b�N", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}
	void GAME::draw4(int snum) {
		fill(100);
		textSize(200);
		text((let)+oneWard[snum][0], 550, 300);
		textSize(50);
		if (ch.empty()) {
			text(currentInput.c_str(), 600, 800);
		}
		else if (!ch.empty()) {
			text(ch.c_str(), 600, 800);
			text(currentInput.c_str(), 600, 900);
		}
		textSize(60);
		text("�Q�[���I���@���N���b�N", 950, 200);
		print(curtime);
		text((let)+count, 100, 100);
	}

	void GAME::play1() {
		clear(200);
		curtime -= delta;
		draw1(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == pretwoWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != pretwoWard[num[number]][1]) {
			textSize(500);
			text("�~", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {

			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}

	void GAME::play2() {
		clear(200);

		curtime -= delta;
		draw2(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == twoWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != twoWard[num[number]][1]) {
			textSize(120);
			text("�~", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}
	void GAME::play3() {
		clear(200);
		curtime -= delta;
		draw3(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == preoneWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();

		}
		else if (flag == 1 && ch != preoneWard[num[number]][1]) {
			textSize(120);
			text("�~", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			State = OVER;
		}
		if (count == 15) {
			State = END;
		}
	}
	void GAME::play4() {
		clear(200);

		curtime -= delta;
		draw4(num[number]);
		recordInputToKana();
		if (flag == 1 && ch == oneWard[num[number]][1]) {
			number++;
			curtime = 30.0;
			count++;
			flag = 0;
			ch.clear();
			currentInput.clear();
		}
		else if (flag == 1 && ch != oneWard[num[number]][1]) {
			textSize(120);
			text("�~", 525, 500);
			ch.clear();
			currentInput.clear();
			flag = 0;
		}
		if (curtime <= 0 || isTrigger(MOUSE_LBUTTON)) {
			ch.clear();
			State = OVER;
		}
		if (count == 15) {
			ch.clear();
			State = END;
		}
	}

	void GAME::over() {
		clear(200);
		fill(0);
		//�Q�[���I�[�o�[�e�L�X�g 
		textSize(80);
		text("GAMEOVER", 650, 450);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 550);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
		}
	}

	void GAME::end() {
		clear(0, 255, 0);
		fill(0, 0, 255);
		//�Q�[���N���A�e�L�X�g
		textSize(80);
		text("���߂łƂ�", 650, 450);
		text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500, 550);
		if (isTrigger(KEY_SPACE)) {
			State = TITLE;
		}
	}


	void GAME::gmain() {
		window(1920, 1080, full);

	}
}
