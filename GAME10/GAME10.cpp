#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME10.h"
namespace GAME10
{
	int GAME::create()
	{

		STATE = TITLE;
		buttonCnt = STutorial;
		TutorialButton.SelectFlag = true;
		TutorialButton.core.x = 360 - 175;
		TutorialButton.core.y = Height / 2 + 100;
		ProductionButton.core.x = width / 2 - 175;
		ProductionButton.core.y = Height / 2 + 100;
		OperationButton.core.x = 1620 - 175;
		OperationButton.core.y = Height / 2 + 100;
		//fileスキャン
		fileName = "..\\main\\assets\\game10\\map.txt";
		CfileName = "..\\main\\assets\\game10\\tutorial.txt";
		//効果音
		FindSound = loadSound("..\\main\\assets\\game10\\findSound.wav");
		MoveSound = loadSound("..\\main\\assets\\game10\\MoveSound.wav");
		//画像スキャン
		TitleImg = loadImage("..\\main\\assets\\game10\\title.png");
		TutorialClearImg = loadImage("..\\main\\assets\\game10\\tutorialClear.png");
		PageImg[0] = loadImage("..\\main\\assets\\game10\\sousa1.png");
		PageImg[1] = loadImage("..\\main\\assets\\game10\\sousa2.png");
		TutorialPage[0] = loadImage("..\\main\\assets\\game10\\tutorialPage1.png");
		TutorialPage[1] = loadImage("..\\main\\assets\\game10\\tutorialPage2.png");
		ClearImg = loadImage("..\\main\\assets\\game10\\Clear.png");
		OverImg = loadImage("..\\main\\assets\\game10\\Over.png");
		TButtonImg = loadImage("..\\main\\assets\\game10\\tutorialButton.png");
		PbuttonImg = loadImage("..\\main\\assets\\game10\\playButton.png");
		ObuttonImg = loadImage("..\\main\\assets\\game10\\operationButton.png");
		STButtonImg = loadImage("..\\main\\assets\\game10\\shadeTutorial.png");
		SPbuttonImg = loadImage("..\\main\\assets\\game10\\shadePlay.png");
		SObuttonImg = loadImage("..\\main\\assets\\game10\\shadeOperation.png");
		//壁の情報
		WallImg = loadImage("..\\main\\assets\\game10\\wall.png");
		goalImg = loadImage("..\\main\\assets\\game10\\goal.png");
		LockImg = loadImage("..\\main\\assets\\game10\\LockGoal.png");
		KeyImg = loadImage("..\\main\\assets\\game10\\Key.png");
		FlagImg = loadImage("..\\main\\assets\\game10\\Flag.png");
		WallUpImg = loadImage("..\\main\\assets\\game10\\up.png");
		WallUnderImg = loadImage("..\\main\\assets\\game10\\under.png");
		WallRightImg = loadImage("..\\main\\assets\\game10\\right.png");
		WallLeftImg = loadImage("..\\main\\assets\\game10\\left.png");
		WallUpLeftCornerImg = loadImage("..\\main\\assets\\game10\\upLeftCorner.png");
		WallUnderLeftCornerImg = loadImage("..\\main\\assets\\game10\\underLeftCorner.png");
		WallUpRightCornerImg = loadImage("..\\main\\assets\\game10\\upRightCorner.png");
		WallUnderRightCornerImg = loadImage("..\\main\\assets\\game10\\underRightCorner.png");
		fopen_s(&fp, fileName, "rb");
		fopen_s(&Cfp, CfileName, "rb");

		fseek(fp,0,SEEK_END);
		fseek(Cfp, 0, SEEK_END);

		fileSize = ftell(fp);
		CfileSize = ftell(Cfp);

		fseek(fp, 0, SEEK_SET);
		fseek(Cfp, 0, SEEK_SET);

		map = new char[fileSize];
		Tmap = new char[CfileSize];

		fread(map,sizeof(char),fileSize,fp);
		fread(Tmap, sizeof(char), CfileSize, Cfp);

		fclose(fp);
		fclose(Cfp);

		//行列の計算・マップの記号の数(本番用)
		for (int i = 0; i < fileSize; i++) {
			Production.cnt++;
			if (map[i] == 'g') {
				Production.GoalCnt ++;
			}
			else if (map[i] == 'a') {
				Production.WallCnt++;
			}
			else if (map[i] == '1') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '2') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '3') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '4') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '5') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '6') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '7') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == '8') {
				Production.InvisibleWallCnt++;
			}
			else if (map[i] == 's' || map[i] == 'h' || map[i] == 'e') {
				Production.EnemyCnt++;
			}
			else if (map[i] == 'k') {
				Production.KeyCnt++;
			}
			else if (map[i] == '\n') {
				if (Production.row == 0) {
					Production.col = Production.cnt;
				}
				Production.row++;
			}
		}

		//行列の計算・マップの記号の数（tutorial用）
		for (int i = 0; i < CfileSize; i++) {
			Tutorial.cnt++;
			if (Tmap[i] == 'g') {
				Tutorial.GoalCnt++;
			}
			else if (Tmap[i] == 'a') {
				Tutorial.WallCnt++;
			}
			else if (Tmap[i] == 'f') {
				Tutorial.FlagCnt++;
			}
			else if (Tmap[i] == 'k') {
				Tutorial.KeyCnt++;
			}
			else if (Tmap[i] == '\n') {
				if (Tutorial.row == 0) {
					Tutorial.col = Tutorial.cnt;
				}
				Tutorial.row++;
			}
		}

		//壁・goal・見えない壁・敵の動的確保(本番用)
		ProductionMap.Wall = new wall[Production.WallCnt];
		ProductionMap.WallCorner = new wall[Production.InvisibleWallCnt];
		ProductionMap.Goal = new wall[Production.GoalCnt ];
		ProductionMap.Key = new Item[Production.KeyCnt];
		Enemys = new character[Production.EnemyCnt];
		//壁・goal・フラッグ・見えない壁の動的確保(tutorial用)
		TutorialMap.Wall = new wall[Tutorial.WallCnt];
		TutorialMap.WallCorner = new wall[Tutorial.InvisibleWallCnt];
		TutorialMap.Goal = new wall[Tutorial.GoalCnt];
		TutorialMap.Key = new Item[Tutorial.KeyCnt];
		TutorialMap.Flag = new Item[Tutorial.FlagCnt];
		return 0;
	}

	void GAME::destroy()
	{
		delete[] map;
		delete[] Tmap;
		delete[] ProductionMap.Wall;
		delete[] ProductionMap.WallCorner;
		delete[] ProductionMap.Goal;
		delete[] ProductionMap.Key;
		delete[] Enemys;
		delete[] TutorialMap.Wall;
		delete[] TutorialMap.WallCorner;
		delete[] TutorialMap.Goal;
		delete[] TutorialMap.Key;
	}

	void GAME::proc()
	{	
		if (STATE == TITLE) { title(); }
		else if (STATE == TUTORIAL) { tutorial(); }
		else if (STATE == OPERATER) { operater(); }
		else if (STATE == PLAY) { play(); }
		else if (STATE == RESULT) { result(); }

	}

	void GAME::title() {
		draw();
		buttonCol();
		text("ENTERキーでメニューに戻る", 0, 1080);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
		if (isTrigger(KEY_SPACE)) {
			if (TutorialButton.SelectFlag == true) {
				STATE = TUTORIAL;
				init();
			}
			if (ProductionButton.SelectFlag == true) {
				STATE = PLAY;
				init();
			}
			if (OperationButton.SelectFlag == true) {
				STATE = OPERATER;
				init();
			}
		}
	}

	void GAME::buttonCol() {
		if (isTrigger(KEY_D)) {
			switch (buttonCnt)
			{
			case STutorial:
				TutorialButton.SelectFlag = false;
				break;
			case SProduction:
				ProductionButton.SelectFlag = false;
				break;
			case SOperation:
				OperationButton.SelectFlag = false;
				break;
			}
			buttonCnt = (buttonCnt + 1)% SButtonSum;
			switch (buttonCnt)
			{
			case STutorial:
				TutorialButton.SelectFlag = true;
				break;
			case SProduction:
				ProductionButton.SelectFlag = true;
				break;
			case SOperation:
				OperationButton.SelectFlag = true;
				break;
			}
		}
		if (isTrigger(KEY_A)) {
			switch (buttonCnt)
			{
			case STutorial:
				TutorialButton.SelectFlag = false;
				break;
			case SProduction:
				ProductionButton.SelectFlag = false;
				break;
			case SOperation:
				OperationButton.SelectFlag = false;
				break;
			}
			buttonCnt = buttonCnt - 1;
			if (buttonCnt < 0) {
				buttonCnt = SButtonSum - 1;
			}
			switch (buttonCnt)
			{
			case STutorial:
				TutorialButton.SelectFlag = true;
				break;
			case SProduction:
				ProductionButton.SelectFlag = true;
				break;
			case SOperation:
				OperationButton.SelectFlag = true;
				break;
			}
		}
	}

	void GAME::init() {
		if (STATE == TUTORIAL) {
			//配列の数を抑制するための数
			int Wcnt = 0;
			int Gcnt = 0;
			int WCcnt = 0;
			int Fcnt = 0;
			TutorialClearFlag = false;
			pauseFlag = true;
			GetFlagCnt = 0;
			TutorialMap.Wmap.worldX = 0;
			TutorialMap.Wmap.worldY = 0;
			Tutorial.KeyCnt = 0;
			for (int g = 0; g < Tutorial.GoalCnt; g++) {
				TutorialMap.Goal[g].LockFlag = true;
			}
			//プレイヤーと敵の初期位置設定・壁の情報の保存
			for (int c = 0; c < Tutorial.col; c++) {
				TutorialMap.Wmap.px = c * TutorialMap.Wmap.Xsize;
				for (int r = 0; r < Tutorial.row; r++) {
					TutorialMap.Wmap.py = r * TutorialMap.Wmap.Ysize;
					TutorialMap.Wmap.mIdx = r * Tutorial.col + c;
					//壁
					if (Tmap[TutorialMap.Wmap.mIdx] == 'a') {
						TutorialMap.Wall[Wcnt].WaPx = TutorialMap.Wmap.px;//実際にはオーバーランしていない
						TutorialMap.Wall[Wcnt].WaPy = TutorialMap.Wmap.py;
						Wcnt++;
					}
					//ゴール
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'g') {
						TutorialMap.Goal[Gcnt].WaPx = TutorialMap.Wmap.px;//実際にはオーバーランしていない
						TutorialMap.Goal[Gcnt].WaPy = TutorialMap.Wmap.py;
						Gcnt++;
					}
					//プレイヤー
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'p') {
						player.Cpx = TutorialMap.Wmap.px + TutorialMap.Wmap.XharfSize;
						player.Cpy = TutorialMap.Wmap.py + TutorialMap.Wmap.YharfSize;
					}
					//フラッグー
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'f') {
						TutorialMap.Flag[Fcnt].ItemCore.x = TutorialMap.Wmap.px + TutorialMap.Wmap.XharfSize;
						TutorialMap.Flag[Fcnt].ItemCore.y = TutorialMap.Wmap.py + TutorialMap.Wmap.YharfSize;
						Fcnt++;
					}
					//鍵
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'k') {
						TutorialMap.Key[Tutorial.KeyCnt].ItemCore.x = TutorialMap.Wmap.px + TutorialMap.Wmap.XharfSize;
						TutorialMap.Key[Tutorial.KeyCnt].ItemCore.y = TutorialMap.Wmap.py + TutorialMap.Wmap.YharfSize;
						Tutorial.KeyCnt++;
					}
				}
			}
			//プレイヤーの位置調整
			while (player.Cpy + TutorialMap.Wmap.worldY > height) {
				TutorialMap.Wmap.worldY -= height;
			}
			while (player.Cpx + TutorialMap.Wmap.worldX > width) {
				TutorialMap.Wmap.worldX -= width;
			}
			player.Cpy += TutorialMap.Wmap.worldY;
			player.Cpx += TutorialMap.Wmap.worldX;
			//鍵取得の初期化
			player.KeyFlag = false;
			GoalFlag = false;
			TutorialMap.Key[0].Substance = true;
			//旗の状態を初期化
			for (int i = 0; i < Tutorial.FlagCnt; i++) {
				TutorialMap.Flag[i].Substance = false;
			}
			int cnt = 0;
			while (notQuit) {
				if (random() % Tutorial.FlagCnt == 1) {
					TutorialMap.Flag[cnt].Substance = true;
					Ftemp = cnt;
					break;
				}
				cnt = (cnt + 1) % Tutorial.FlagCnt;
			}
		}
		if(STATE == OPERATER){
			PageCnt = 0;
		}
		if (STATE == PLAY) {
			//配列の数を抑制するための数
			int Wcnt = 0;
			int Gcnt = 0;
			int WCcnt = 0;
			FindFlag = false;
			ProductionMap.Wmap.worldX = 0;
			ProductionMap.Wmap.worldY = 0;
			Ecnt = 0;
			Production.KeyCnt = 0;
			//ゴールのロック
			for (int g = 0; g < Production.GoalCnt; g++) {
				ProductionMap.Goal[g].LockFlag = true;
			}
			//ムーブの初期化と視界の初期化
			for (int e = 0; e < Production.EnemyCnt; e++) {
				Enemys[e].Mx = 5;
				Enemys[e].My = 5;
				Enemys[e].FindLen = 400;
				Enemys[e].WallHitFlag = false;
			}
			//プレイヤーと敵の初期位置設定・壁の情報の保存
			for (int c = 0; c < Production.col; c++) {
				ProductionMap.Wmap.px = c * ProductionMap.Wmap.Xsize;
				for (int r = 0; r < Production.row; r++) {
					ProductionMap.Wmap.py = r * ProductionMap.Wmap.Ysize;
					ProductionMap.Wmap.mIdx = r * Production.col + c;
					//壁
					if (map[ProductionMap.Wmap.mIdx] == 'a') {
						ProductionMap.Wall[Wcnt].WaPx = ProductionMap.Wmap.px;//実際にはオーバーランしていない
						ProductionMap.Wall[Wcnt].WaPy = ProductionMap.Wmap.py;
						Wcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '1') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '2') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '3') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '4') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '5') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '6') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '7') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					else if (map[ProductionMap.Wmap.mIdx] == '8') {
						ProductionMap.WallCorner[WCcnt].WaPx = ProductionMap.Wmap.px;
						ProductionMap.WallCorner[WCcnt].WaPy = ProductionMap.Wmap.py;
						WCcnt++;
					}
					//ゴール
					else if (map[ProductionMap.Wmap.mIdx] == 'g') {
						ProductionMap.Goal[Gcnt].WaPx = ProductionMap.Wmap.px;//実際にはオーバーランしていない
						ProductionMap.Goal[Gcnt].WaPy = ProductionMap.Wmap.py;
						Gcnt++;
					}
					//プレイヤー
					else if (map[ProductionMap.Wmap.mIdx] == 'p') {
						player.Cpx = ProductionMap.Wmap.px + ProductionMap.Wmap.XharfSize;
						player.Cpy = ProductionMap.Wmap.py + ProductionMap.Wmap.YharfSize;
					}
					//敵
					else if (map[ProductionMap.Wmap.mIdx] == 's' || map[ProductionMap.Wmap.mIdx] == 'h' || map[ProductionMap.Wmap.mIdx] == 'e') {
						Enemys[Ecnt].Cpx = ProductionMap.Wmap.px + ProductionMap.Wmap.XharfSize;;
						Enemys[Ecnt].Cpy = ProductionMap.Wmap.py + ProductionMap.Wmap.YharfSize;
						//動きの種類を決定
						if (map[ProductionMap.Wmap.mIdx] == 's') {
							Enemys[Ecnt].Mkind = RightLeft;
						}
						else if (map[ProductionMap.Wmap.mIdx] == 'h') {
							Enemys[Ecnt].Mkind = UpDown;
						}
						else if (map[ProductionMap.Wmap.mIdx] == 'e') {
							Enemys[Ecnt].Mkind = NoMove;
							Enemys[Ecnt].View = random() % 4;
						}
						Enemys[Ecnt].Frieze = 0;
						Ecnt++;
					}
					//鍵
					else if (map[ProductionMap.Wmap.mIdx] == 'k') {
						ProductionMap.Key[Production.KeyCnt].ItemCore.x = ProductionMap.Wmap.px + ProductionMap.Wmap.XharfSize;
						ProductionMap.Key[Production.KeyCnt].ItemCore.y = ProductionMap.Wmap.py + ProductionMap.Wmap.YharfSize;
						Production.KeyCnt++;
					}
				}
			}
			//エネミーの動きを決める
			for (int e = 0; e < Production.EnemyCnt; e++) {
				switch (Enemys[e].Mkind)
				{
				case RightLeft:
					if (random() % 2) {
						Enemys[e].Mx *= -1;
						Enemys[e].View = Left;
					}
					else {
						Enemys[e].View = Right;
					}
					break;
				case UpDown:
					if (random() % 2) {
						Enemys[e].My *= -1;
						Enemys[e].View = Up;
					}
					else {
						Enemys[e].View = Under;
					}
					break;
				case NoMove:
					Enemys[e].View = random() % 4;
					break;
				}
			}
			//初期表示位置をプレイヤーに変更
			while (player.Cpy + ProductionMap.Wmap.worldY > height) {
				ProductionMap.Wmap.worldY -= height;
			}
			while (player.Cpx + ProductionMap.Wmap.worldX > width) {
				ProductionMap.Wmap.worldX -= width;
			}
			player.Cpy += ProductionMap.Wmap.worldY;
			player.Cpx += ProductionMap.Wmap.worldX;
			//鍵取得の初期化
			player.KeyFlag = false;
			GoalFlag = false;
			int cnt = 0;
			for (int i = 0; i < Production.KeyCnt; i++) {
				ProductionMap.Key[i].Substance = false;
			}
			while (notQuit) {
				if (random() % 5 == 1) {
					ProductionMap.Key[cnt].Substance = true;
					break;
				}
				cnt = (cnt + 1) % Production.KeyCnt;
			}
		}
	}

	void GAME::tutorial() {
		if(pauseFlag == true){
			stopSound(MoveSound);
			if (GetFlagCnt < GetFlagLimit) {
				draw();
				if (isTrigger(KEY_SPACE)) {
					pauseFlag = false;
				}
				image(TutorialPage[0], 0, 0);
			}
			else {
				draw();
				if (isTrigger(KEY_SPACE)) {
					pauseFlag = false;
				}
				image(TutorialPage[1], 0, 0);
			}
		}
		else {
			draw();
			Pmove();
			collision();
			if (TutorialClearFlag == true && isTrigger(KEY_SPACE)) {
				STATE = TITLE;
			}
		}
	}
	
	void GAME::operater() {
		if (PageCnt >= PageSum) {
			STATE = TITLE;
		}
		if (isTrigger(KEY_D)) {
			PageCnt++;
		}
		if (isTrigger(KEY_A) && PageCnt != 0) {
			PageCnt--;
		}
		draw();
	}

	void GAME::play() {
		draw();
		Pmove();
		Emove();
		collision();
		stageChange();
	}

	void GAME::result() {
		clear(255);
		draw();
	}

	void GAME::Pmove() {
		if (isPress(KEY_D)) {
			player.Cpx += player.Mx;
			Cmx = -player.Mx;
		}
		if (isPress(KEY_A)) {
			player.Cpx -= player.Mx;
			Cmx = player.Mx;
		}
		if (isPress(KEY_A) == false && isPress(KEY_D) == false) {
			Cmx = 0;
		}

		if (isPress(KEY_S)) {
			player.Cpy += player.My;
			Cmy = -player.My;
		}
		if (isPress(KEY_W)) {
			player.Cpy -= player.My;
			Cmy = player.My;
		}
		if (isPress(KEY_S) == false && isPress(KEY_W) == false) {
			Cmy = 0;
		}

		if ((isPress(KEY_S) != false || isPress(KEY_W) != false || isPress(KEY_A) != false || isPress(KEY_D) != false) && SoundFlag == false) {
			playSound(MoveSound);
			SoundFlag = true;
		}

		if (isPress(KEY_S) == false && isPress(KEY_W) == false && isPress(KEY_A) == false && isPress(KEY_D) == false) {
			SoundFlag = false;
			stopSound(MoveSound);
		}

	}

	void GAME::Emove() {
		for (int enemy = 0; enemy < Production.EnemyCnt; enemy++) {
			if (Enemys[enemy].Cpx + ProductionMap.Wmap.worldX > 0
				&& Enemys[enemy].Cpx + ProductionMap.Wmap.worldX < width
				&& Enemys[enemy].Cpy + ProductionMap.Wmap.worldY > 0
				&& Enemys[enemy].Cpy + ProductionMap.Wmap.worldY < height) {
				switch (Enemys[enemy].Mkind) {
				case RightLeft:
					if (Enemys[enemy].WallHitFlag == false) {
						Enemys[enemy].Cpx += Enemys[enemy].Mx;
					}
					break;
				case UpDown:
					if (Enemys[enemy].WallHitFlag == false) {
						Enemys[enemy].Cpy += Enemys[enemy].My;
					}
					break;
				case NoMove:
					if (Enemys[enemy].Frieze == FrieseTime) {
						Enemys[enemy].View = (Enemys[enemy].View + 1) % 4;
						Enemys[enemy].Frieze = 0;
					}
					else {
						Enemys[enemy].Frieze++;
					}
					break;
				}
			}
		}
	}

	void GAME::stageChange() {
		if (STATE == TUTORIAL) {
			if (player.Cpx > width) {
				clear(0);
				TutorialMap.Wmap.worldX -= width;
				player.Cpx = TutorialMap.Wmap.YharfSize;
			}
			if (player.Cpx < 0) {
				clear(0);
				TutorialMap.Wmap.worldX += width;
				player.Cpx = width - TutorialMap.Wmap.YharfSize;
			}
			if (player.Cpy > height) {
				clear(0);
				TutorialMap.Wmap.worldY -= height;
				player.Cpy = TutorialMap.Wmap.YharfSize;
			}
			if (player.Cpy < 0) {
				clear(0);
				TutorialMap.Wmap.worldY += height;
				player.Cpy = height;
			}
		}

		if (STATE == PLAY) {
			if (player.Cpx > width) {
				clear(0);
				ProductionMap.Wmap.worldX -= width;
				player.Cpx = ProductionMap.Wmap.YharfSize;
			}
			if (player.Cpx < 0) {
				clear(0);
				ProductionMap.Wmap.worldX += width;
				player.Cpx = width - ProductionMap.Wmap.YharfSize;
			}

			if (player.Cpy > height) {
				clear(0);
				ProductionMap.Wmap.worldY -= height;
				player.Cpy = ProductionMap.Wmap.YharfSize;
			}
			if (player.Cpy < 0) {
				clear(0);
				ProductionMap.Wmap.worldY += height;
				player.Cpy = height;
			}
		}
	}
	
	void GAME::collision() {
		if (STATE == TUTORIAL) {
			for (int w = 0; w < Tutorial.WallCnt; w++) {
				if (TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.worldX >= -TutorialMap.Wmap.Xsize
					&& TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.worldX < width + TutorialMap.Wmap.Xsize
					&& TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.worldY >= -TutorialMap.Wmap.Ysize
					&& TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.worldY < height + TutorialMap.Wmap.Ysize) {
					hitbox(w);
				}
			}

			if (GetFlagCnt > GetFlagLimit) {
				for (int k = 0; k < Production.KeyCnt; k++) {
				if (TutorialMap.Key[k].Substance == true) {
					float KDist = sqrt(abs((player.Cpx - (TutorialMap.Key[k].ItemCore.x + TutorialMap.Wmap.worldX)) * abs(player.Cpx - (TutorialMap.Key[k].ItemCore.x + TutorialMap.Wmap.worldX))) + abs((player.Cpy - (TutorialMap.Key[k].ItemCore.y + TutorialMap.Wmap.worldY)) * abs(player.Cpy - (TutorialMap.Key[k].ItemCore.y + TutorialMap.Wmap.worldY))));
					if (KDist < player.Hradius + TutorialMap.Key[k].Iradius) {
						TutorialMap.Key[k].Substance = false;
						player.KeyFlag = true;
					}
				}
			}
			}

			for (int g = 0; g < Tutorial.GoalCnt; g++) {
				if (TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX >= 0
					&& TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX < width
					&& TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY >= 0
					&& TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY < height) {
					playerHitBox();
					if (PlayerBox.right.x >= TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX
						&& PlayerBox.right.x <= TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX + TutorialMap.Wmap.Xsize
						&& PlayerBox.up.y <= TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY + TutorialMap.Wmap.Ysize
						&& PlayerBox.under.y >= TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY
						&& player.KeyFlag == true) {
						stopSound(MoveSound);
						TutorialClearFlag = true;
					}
					else if (PlayerBox.right.x >= TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX
						&& PlayerBox.right.x <= TutorialMap.Goal[g].WaPx + TutorialMap.Wmap.worldX + TutorialMap.Wmap.Xsize
						&& PlayerBox.up.y <= TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY + TutorialMap.Wmap.Ysize
						&& PlayerBox.under.y >= TutorialMap.Goal[g].WaPy + TutorialMap.Wmap.worldY
						&& player.KeyFlag == false) {
						player.Cpx -= player.Mx;
					}
				}
			}
			//旗の判定（最大まで取ったら消える）
			if (GetFlagCnt < GetFlagLimit) {
				for (int f = 0; f < Tutorial.FlagCnt; f++) {
					if (TutorialMap.Flag[f].Substance == true) {
						float FDist = sqrt(abs((player.Cpx - (TutorialMap.Flag[f].ItemCore.x + TutorialMap.Wmap.worldX)) * abs(player.Cpx - (TutorialMap.Flag[f].ItemCore.x + TutorialMap.Wmap.worldX))) + abs((player.Cpy - (TutorialMap.Flag[f].ItemCore.y + TutorialMap.Wmap.worldY)) * abs(player.Cpy - (TutorialMap.Flag[f].ItemCore.y + TutorialMap.Wmap.worldY))));
						if (FDist < player.Hradius + TutorialMap.Flag[f].Iradius) {
							TutorialMap.Flag[f].Substance = false;
							TutorialMap.Flag[(f + 1) % Tutorial.FlagCnt].Substance = true;
							GetFlagCnt++;
						}
					}
				}
			}
			else if(GetFlagCnt == GetFlagLimit){
				
				pauseFlag = true;
				GetFlagCnt++;
			}
		}

		if (STATE == PLAY) {
			//壁の当たり判定
			for (int w = 0; w < Production.WallCnt; w++) {
				if (ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.worldX >= -ProductionMap.Wmap.Xsize
					&& ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.worldX < width + ProductionMap.Wmap.Xsize
					&& ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.worldY >= -ProductionMap.Wmap.Ysize
					&& ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.worldY < height + ProductionMap.Wmap.Ysize) {
					hitbox(w);
					//敵と壁の当たり判定
					for (int e = 0; e < Production.EnemyCnt; e++) {
						if (Enemys[e].Cpx + ProductionMap.Wmap.worldX >= 0
							&& Enemys[e].Cpx + ProductionMap.Wmap.worldX <= width
							&& Enemys[e].Cpy + ProductionMap.Wmap.worldY >= 0
							&& Enemys[e].Cpy + ProductionMap.Wmap.worldY <= height) {
							hitbox(w, e);
							if (Enemys[e].WallHitFlag == true && Enemys[e].Frieze == FriezeTime) {
								Enemys[e].WallHitFlag = false;
								Enemys[e].FindLen = 400;
								Enemys[e].View = (Enemys[e].View + 2) % 4;
								Enemys[e].Frieze = 0;
							}
							else if (Enemys[e].WallHitFlag == true) {
								Enemys[e].Frieze++;
							}
						}
					}
				}

			}

			//視界判定
			for (int e = 0; e < Production.EnemyCnt; e++) {
				if (Enemys[e].Cpx + ProductionMap.Wmap.worldX >= 0
					&& Enemys[e].Cpx + ProductionMap.Wmap.worldX <= width
					&& Enemys[e].Cpy + ProductionMap.Wmap.worldY >= 0
					&& Enemys[e].Cpy + ProductionMap.Wmap.worldY <= height) {
					viewCollision(e);

				}
			}

			for (int k = 0; k < Production.KeyCnt; k++) {
				if (ProductionMap.Key[k].Substance == true) {
					float KDist = sqrt(abs((player.Cpx - (ProductionMap.Key[k].ItemCore.x + ProductionMap.Wmap.worldX)) * abs(player.Cpx - (ProductionMap.Key[k].ItemCore.x + ProductionMap.Wmap.worldX))) + abs((player.Cpy - (ProductionMap.Key[k].ItemCore.y + ProductionMap.Wmap.worldY)) * abs(player.Cpy - (ProductionMap.Key[k].ItemCore.y + ProductionMap.Wmap.worldY))));
					if (KDist < player.Hradius + ProductionMap.Key[k].Iradius) {
						ProductionMap.Key[k].Substance = false;
						player.KeyFlag = true;
					}
				}
			}

			for (int g = 0; g < Production.GoalCnt; g++) {
				if (ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX >= 0
					&& ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX < width
					&& ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY >= 0
					&& ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY < height) {
					playerHitBox();
					if (PlayerBox.up.y >= ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY
						&& PlayerBox.up.y <= ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY + ProductionMap.Wmap.Ysize
						&& PlayerBox.left.x <= ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX + ProductionMap.Wmap.Xsize
						&& PlayerBox.right.x >= ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX
						&& player.KeyFlag == true) {
						GoalFlag = true;
						STATE = RESULT;
					}
					else if (PlayerBox.up.y >= ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY
						&& PlayerBox.up.y <= ProductionMap.Goal[g].WaPy + ProductionMap.Wmap.worldY + ProductionMap.Wmap.Ysize
						&& PlayerBox.left.x <= ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX + ProductionMap.Wmap.Xsize
						&& PlayerBox.right.x >= ProductionMap.Goal[g].WaPx + ProductionMap.Wmap.worldX
						&& player.KeyFlag == false) {
						player.Cpy += player.My;
					}
				}
			}
		}
	}

	void GAME::viewCollision(int e) {
		float Xdist = 0;
		float Ydist = 0;
		switch (Enemys[e].View)
		{
		case Up:
			Enemys[e].ViewRight = Enemys[e].Cpx + ProductionMap.Wall->XharfSize + ProductionMap.Wmap.worldX;
			Enemys[e].ViewLeft = Enemys[e].Cpx - ProductionMap.Wall->XharfSize + ProductionMap.Wmap.worldX;
			Ydist = player.Cpy - (Enemys[e].Cpy + ProductionMap.Wmap.worldY);
			if (Enemys[e].ViewRight > player.Cpx
				&& Enemys[e].ViewLeft < player.Cpx
				&& Ydist > Enemys[e].FindLen * -1
				&& Ydist < 0) {
				FindFlag = true;
			}
			else {
				FindFlag = false;
			}
		break;
		case Under:
			Enemys[e].ViewRight = Enemys[e].Cpx + ProductionMap.Wall->XharfSize + ProductionMap.Wmap.worldX;
			Enemys[e].ViewLeft = Enemys[e].Cpx - ProductionMap.Wall->XharfSize + ProductionMap.Wmap.worldX;
			Ydist = player.Cpy - (Enemys[e].Cpy + ProductionMap.Wmap.worldY);
			if (Enemys[e].ViewRight > player.Cpx
				&& Enemys[e].ViewLeft < player.Cpx
				&& Ydist < Enemys[e].FindLen
				&& Ydist > 0) {
				FindFlag = true;
			}
			else {
				FindFlag = false;
			}
			break;
		case Left:
			Enemys[e].ViewUp = Enemys[e].Cpy - ProductionMap.Wall->YharfSize + ProductionMap.Wmap.worldY;
			Enemys[e].ViewUnder = Enemys[e].Cpy + ProductionMap.Wall->YharfSize + ProductionMap.Wmap.worldY;
			Xdist = player.Cpx - (Enemys[e].Cpx + ProductionMap.Wmap.worldX);
			if (Enemys[e].ViewUp <= player.Cpy
				&& Enemys[e].ViewUnder >= player.Cpy
				&& Xdist > Enemys[e].FindLen * -1
				&& Xdist < 0) {
				FindFlag = true;
			}
			else {
				FindFlag = false;
			}
			break;
		case Right:
			Enemys[e].ViewUp = Enemys[e].Cpy - ProductionMap.Wall->YharfSize + ProductionMap.Wmap.worldY;
			Enemys[e].ViewUnder = Enemys[e].Cpy + ProductionMap.Wall->YharfSize + ProductionMap.Wmap.worldY;
			Xdist = player.Cpx - (Enemys[e].Cpx + ProductionMap.Wmap.worldX);
			if (Enemys[e].ViewUp <= player.Cpy
				&& Enemys[e].ViewUnder >= player.Cpy
				&& Xdist < Enemys[e].FindLen
				&& Xdist >= 0) {
				FindFlag = true;
			}
			else {
				FindFlag = false;
			}
			break;
		}
		if (FindFlag == true) {
			stopSound(MoveSound);
			STATE = RESULT;
		}
	}

	void GAME::hitbox(int w) {
		wallHitBox(w);
		playerHitBox();
		PDist.UpDist = Sqrt(Abs((WallBox.core.x - PlayerBox.under.x) * (WallBox.core.x - PlayerBox.under.x)) + Abs((WallBox.core.y - PlayerBox.under.y) * (WallBox.core.y - PlayerBox.under.y)));
		PDist.UnderDist = Sqrt(Abs((WallBox.core.x - PlayerBox.up.x) * (WallBox.core.x - PlayerBox.up.x)) + Abs((WallBox.core.y - PlayerBox.up.y) * (WallBox.core.y - PlayerBox.up.y)));
		PDist.LeftDist = Sqrt(Abs((WallBox.core.x - PlayerBox.right.x) * (WallBox.core.x - PlayerBox.right.x)) + Abs((WallBox.core.y - PlayerBox.right.y) * (WallBox.core.y - PlayerBox.right.y)));
		PDist.RightDist = Sqrt(Abs((WallBox.core.x - PlayerBox.left.x) * (WallBox.core.x - PlayerBox.left.x)) + Abs((WallBox.core.y - PlayerBox.left.y) * (WallBox.core.y - PlayerBox.left.y)));
		if (PDist.UpDist < PDist.LeftDist && PDist.UpDist < PDist.RightDist && PDist.UpDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Up;
		}
		else if (PDist.UnderDist < PDist.UpDist && PDist.UnderDist < PDist.RightDist && PDist.UnderDist < PDist.LeftDist) {
			PDist.PointFlag = PDist.Under;
		}
		else if (PDist.LeftDist < PDist.UpDist && PDist.LeftDist < PDist.RightDist && PDist.LeftDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Left;
		}
		else if (PDist.RightDist < PDist.UpDist && PDist.RightDist < PDist.LeftDist && PDist.RightDist < PDist.UnderDist) {
			PDist.PointFlag = PDist.Right;
		}
		switch (PDist.PointFlag) {
		case PDist.Up://壁から見て上側の判定
			if (WallBox.up.y <= PlayerBox.under.y
				&& WallBox.under.y >= PlayerBox.under.y
				&& WallBox.right.x >= PlayerBox.left.x + Cmx
				&& WallBox.left.x <= PlayerBox.right.x + Cmx) {
				player.Cpy -= player.My;
			}
			break;
		case PDist.Under://壁から見て下側の判定
			if (WallBox.under.y >= PlayerBox.up.y
				&& WallBox.up.y <= PlayerBox.up.y
				&& WallBox.right.x >= PlayerBox.left.x + Cmx
				&& WallBox.left.x <= PlayerBox.right.x + Cmx) {
				player.Cpy += player.My;
			}
			break;
		case PDist.Left://壁から見て左側の判定
			if (WallBox.left.x <= PlayerBox.right.x
				&& WallBox.right.x >= PlayerBox.right.x
				&& WallBox.up.y <= PlayerBox.under.y + Cmy
				&& WallBox.under.y >= PlayerBox.up.y + Cmy) {
				player.Cpx -= player.Mx;
			}
			break;
		case PDist.Right://壁から見て右側の判定
			if (WallBox.left.x <= PlayerBox.left.x
				&& WallBox.right.x >= PlayerBox.left.x
				&& WallBox.up.y <= PlayerBox.under.y + Cmy
				&& WallBox.under.y >= PlayerBox.up.y + Cmy) {
				player.Cpx += player.Mx;
			}
			break;
		}
	}

	void GAME::hitbox(int w, int e) {
		wallHitBox(w);
		enemyHitBox(e);
		EDist.PointFlag = -1;//リセット
		EDist.UpDist = Sqrt(Abs((WallBox.core.x - EnemyBox.under.x) * (WallBox.core.x - EnemyBox.under.x)) + Abs((WallBox.core.y - EnemyBox.under.y) * (WallBox.core.y - EnemyBox.under.y)));
		EDist.UnderDist = Sqrt(Abs((WallBox.core.x - EnemyBox.up.x) * (WallBox.core.x - EnemyBox.up.x)) + Abs((WallBox.core.y - EnemyBox.up.y) * (WallBox.core.y - EnemyBox.up.y)));
		EDist.LeftDist = Sqrt(Abs((WallBox.core.x - EnemyBox.right.x) * (WallBox.core.x - EnemyBox.right.x)) + Abs((WallBox.core.y - EnemyBox.right.y) * (WallBox.core.y - EnemyBox.right.y)));
		EDist.RightDist = Sqrt(Abs((WallBox.core.x - EnemyBox.left.x) * (WallBox.core.x - EnemyBox.left.x)) + Abs((WallBox.core.y - EnemyBox.left.y) * (WallBox.core.y - EnemyBox.left.y)));

		if (Enemys[e].Mkind == UpDown) {
			if (EDist.UpDist < EDist.LeftDist && EDist.UpDist < EDist.RightDist && EDist.UpDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Up;
			}
			else if (EDist.UnderDist < EDist.UpDist && EDist.UnderDist < EDist.RightDist && EDist.UnderDist < EDist.LeftDist) {
				EDist.PointFlag = EDist.Under;
			}
		}
		else if (Enemys[e].Mkind == RightLeft) {
			if (EDist.LeftDist < EDist.UpDist && EDist.LeftDist < EDist.RightDist && EDist.LeftDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Left;
			}
			else if (EDist.RightDist < EDist.UpDist && EDist.RightDist < EDist.LeftDist && EDist.RightDist < EDist.UnderDist) {
				EDist.PointFlag = EDist.Right;
			}
		}

		switch (EDist.PointFlag) {
		case EDist.Up:
			//視界判定の縮小
			if (WallBox.up.y <= EnemyBox.under.y + Enemys[e].FindLen - Enemys[e].radius
				&& WallBox.under.y >= EnemyBox.under.y + Enemys[e].FindLen - Enemys[e].radius
				&& WallBox.right.x >= EnemyBox.left.x
				&& WallBox.left.x <= EnemyBox.right.x
				&& Enemys[e].Mkind == UpDown
				&& Enemys[e].View == Under) {
				Enemys[e].FindLen -= Enemys[e].My;
			}
			//壁から見て上側の判定
			if (WallBox.up.y <= EnemyBox.under.y + ProductionMap.Wall[w].YharfSize
				&& WallBox.under.y >= EnemyBox.under.y + ProductionMap.Wall[w].YharfSize
				&& WallBox.right.x >= EnemyBox.left.x
				&& WallBox.left.x <= EnemyBox.right.x
				&& Enemys[e].View == Under) {
				Enemys[e].My *= -1;
				Enemys[e].Cpy += Enemys[e].My;
				Enemys[e].WallHitFlag = true;
			}
			break;
		case EDist.Under:
			if (WallBox.under.y >= EnemyBox.up.y - Enemys[e].FindLen + Enemys[e].radius
				&& WallBox.up.y <= EnemyBox.up.y - Enemys[e].FindLen + Enemys[e].radius
				&& WallBox.right.x >= EnemyBox.left.x
				&& WallBox.left.x <= EnemyBox.right.x
				&& Enemys[e].Mkind == UpDown
				&& Enemys[e].View == Up) {
				Enemys[e].FindLen -= Enemys[e].My;
			}
				//壁から見て下側の判定
				if (WallBox.under.y >= EnemyBox.up.y - ProductionMap.Wall[w].YharfSize
					&& WallBox.up.y <= EnemyBox.up.y - ProductionMap.Wall[w].YharfSize
					&& WallBox.right.x >= EnemyBox.left.x
					&& WallBox.left.x <= EnemyBox.right.x
					&& Enemys[e].View == Up) {
					Enemys[e].My *= -1;
					Enemys[e].Cpy += Enemys[e].My;
					Enemys[e].WallHitFlag = true;
				}
				break;
			case EDist.Left:
				if (WallBox.left.x <= EnemyBox.right.x + Enemys[e].FindLen - Enemys[e].radius
					&& WallBox.right.x >= EnemyBox.right.x + Enemys[e].FindLen - Enemys[e].radius
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y
					&& Enemys[e].Mkind == RightLeft
					&& Enemys[e].View == Right) {
					Enemys[e].FindLen -= Enemys[e].My;
				}
				//壁から見て左側の判定
				if (WallBox.left.x <= EnemyBox.right.x + ProductionMap.Wall[e].XharfSize
					&& WallBox.right.x >= EnemyBox.right.x + ProductionMap.Wall[e].XharfSize
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y
					&& Enemys[e].View == Right) {
					Enemys[e].Mx *= -1;
					Enemys[e].Cpx += Enemys[e].Mx;
					Enemys[e].WallHitFlag = true;
				}
				break;
			case EDist.Right:
				if (WallBox.left.x <= EnemyBox.right.x - Enemys[e].FindLen
					&& WallBox.right.x >= EnemyBox.right.x - Enemys[e].FindLen
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y
					&& Enemys[e].Mkind == RightLeft
					&& Enemys[e].View == Left) {
					Enemys[e].FindLen -= Enemys[e].My;
				}
				//壁から見て右側の判定
				if (WallBox.left.x <= EnemyBox.left.x - ProductionMap.Wall[e].XharfSize
					&& WallBox.right.x >= EnemyBox.left.x - ProductionMap.Wall[e].XharfSize
					&& WallBox.up.y <= EnemyBox.under.y
					&& WallBox.under.y >= EnemyBox.up.y
					&& Enemys[e].View == Left) {
					Enemys[e].Mx *= -1;
					Enemys[e].Cpx += Enemys[e].Mx;
					Enemys[e].WallHitFlag = true;
				}
				break;
			}
	}

	void GAME::wallHitBox(int w) {
		if (STATE == TUTORIAL) {
			//壁のコア
			WallBox.core.x = TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.XharfSize + TutorialMap.Wmap.worldX;
			WallBox.core.y = TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.YharfSize + TutorialMap.Wmap.worldY;
			//壁の上下左右の当たり判定
			WallBox.up.x = TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.worldX;
			WallBox.up.y = TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.worldY;

			WallBox.under.x = TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.worldX;
			WallBox.under.y = TutorialMap.Wall[w].WaPy + TutorialMap.Wall[w].Ysize + TutorialMap.Wmap.worldY;

			WallBox.left.x = TutorialMap.Wall[w].WaPx + TutorialMap.Wmap.worldX;
			WallBox.left.y = TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.worldY;

			WallBox.right.x = TutorialMap.Wall[w].WaPx + TutorialMap.Wall[w].Xsize + TutorialMap.Wmap.worldX;
			WallBox.right.y = TutorialMap.Wall[w].WaPy + TutorialMap.Wmap.worldY;
		}
		if (STATE == PLAY) {
			//壁のコア
			WallBox.core.x = ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.XharfSize + ProductionMap.Wmap.worldX;
			WallBox.core.y = ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.YharfSize + ProductionMap.Wmap.worldY;
			//壁の上下左右の当たり判定
			WallBox.up.x = ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.worldX;
			WallBox.up.y = ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.worldY;

			WallBox.under.x = ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.worldX;
			WallBox.under.y = ProductionMap.Wall[w].WaPy + ProductionMap.Wall[w].Ysize + ProductionMap.Wmap.worldY;

			WallBox.left.x = ProductionMap.Wall[w].WaPx + ProductionMap.Wmap.worldX;
			WallBox.left.y = ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.worldY;

			WallBox.right.x = ProductionMap.Wall[w].WaPx + ProductionMap.Wall[w].Xsize + ProductionMap.Wmap.worldX;
			WallBox.right.y = ProductionMap.Wall[w].WaPy + ProductionMap.Wmap.worldY;
		}
	}

	void GAME::playerHitBox() {
		//プレイヤーの上下左右の当たり判定
		PlayerBox.up.x = player.Cpx;
		PlayerBox.up.y = player.Cpy - player.Hradius;

		PlayerBox.under.x = player.Cpx;
		PlayerBox.under.y = player.Cpy + player.Hradius;

		PlayerBox.left.x = player.Cpx - player.Hradius;
		PlayerBox.left.y = player.Cpy;

		PlayerBox.right.x = player.Cpx + player.Hradius;
		PlayerBox.right.y = player.Cpy;
	}

	void GAME::enemyHitBox(int e) {
		EnemyBox.up.x = Enemys[e].Cpx + ProductionMap.Wmap.worldX;
		EnemyBox.up.y = Enemys[e].Cpy - Enemys[e].Hradius + ProductionMap.Wmap.worldY;

		EnemyBox.under.x = Enemys[e].Cpx + ProductionMap.Wmap.worldX;
		EnemyBox.under.y = Enemys[e].Cpy + Enemys[e].Hradius + ProductionMap.Wmap.worldY;

		EnemyBox.left.x = Enemys[e].Cpx - Enemys[e].Hradius + ProductionMap.Wmap.worldX;
		EnemyBox.left.y = Enemys[e].Cpy + ProductionMap.Wmap.worldY;

		EnemyBox.right.x = Enemys[e].Cpx + Enemys[e].Hradius + ProductionMap.Wmap.worldX;
		EnemyBox.right.y = Enemys[e].Cpy + ProductionMap.Wmap.worldY;
	}

	void GAME::draw() {
		if (STATE == TITLE) {
			fill(255);
			clear(255);
			image(TitleImg, 0, 0);
			if(TutorialButton.SelectFlag == true){
				image(TButtonImg, TutorialButton.core.x, TutorialButton.core.y);
			}
			else if (ProductionButton.SelectFlag == true) {
				image(PbuttonImg, ProductionButton.core.x, ProductionButton.core.y);
			}
			else if (OperationButton.SelectFlag == true) {
				image(ObuttonImg, OperationButton.core.x, OperationButton.core.y);
			}

			if (TutorialButton.SelectFlag == false) {
				image(STButtonImg, TutorialButton.core.x, TutorialButton.core.y);
			}
			if (ProductionButton.SelectFlag == false) {
				image(SPbuttonImg, ProductionButton.core.x, ProductionButton.core.y);
			}
			if (OperationButton.SelectFlag == false) {
				image(SObuttonImg, OperationButton.core.x, OperationButton.core.y);
			}
		}
		if (STATE == TUTORIAL) {
			if (TutorialClearFlag == false) {
				clear(255);
				//それぞれの座標にイメージを書き込んでいる
				for (int c = 0; c < Tutorial.col; c++) {
				TutorialMap.Wmap.px = TutorialMap.Wmap.worldX + c * TutorialMap.Wmap.Xsize;
				for (int r = 0; r < Tutorial.row; r++) {
					TutorialMap.Wmap.py = TutorialMap.Wmap.worldY + r * TutorialMap.Wmap.Ysize;
					TutorialMap.Wmap.mIdx = r * Tutorial.col + c;
					if (Tmap[TutorialMap.Wmap.mIdx] == 'a') {
						image(WallImg, TutorialMap.Wmap.px, TutorialMap.Wmap.py);
					}
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'g') {
						if (player.KeyFlag == true) {
							image(goalImg, TutorialMap.Wmap.px, TutorialMap.Wmap.py);
						}
						else {
							image(LockImg, TutorialMap.Wmap.px, TutorialMap.Wmap.py);
						}
					}
					else if (Tmap[TutorialMap.Wmap.mIdx] == 'k') {
					}
				}
			}
				if (GetFlagCnt >= GetFlagLimit) {
					for (int Icnt = 0; Icnt < Tutorial.KeyCnt; Icnt++) {
				if (TutorialMap.Key[Icnt].Substance == true) {
					image(KeyImg, TutorialMap.Key[Icnt].ItemCore.x + TutorialMap.Wmap.worldX - TutorialMap.Wmap.XharfSize, TutorialMap.Key[Icnt].ItemCore.y + TutorialMap.Wmap.worldY - TutorialMap.Wmap.YharfSize);
				}
			}
				}
				if (GetFlagCnt < GetFlagLimit) {
				for (int Fcnt = 0; Fcnt < Tutorial.FlagCnt; Fcnt++) {
				if (TutorialMap.Flag[Fcnt].Substance == true) {
					image(FlagImg,TutorialMap.Flag[Fcnt].ItemCore.x + TutorialMap.Wmap.worldX - TutorialMap.Wmap.XharfSize, TutorialMap.Flag[Fcnt].ItemCore.y + TutorialMap.Wmap.worldY - TutorialMap.Wmap.YharfSize);
				}
			}
			}
				fill(0);
				circle(player.Cpx, player.Cpy, player.radius);
				if (player.KeyFlag == true) {
				fill(255, 255, 0);
				circle(player.Cpx, player.Cpy, TutorialMap.Key->Iradius / 2);
			}
			}
			else {
				image(TutorialClearImg, 0, 0);
			}
		}
		if (STATE == OPERATER) {
			clear(255);
			image(PageImg[PageCnt], 0, 0);
		}
		if (STATE == PLAY) {
			rectMode(CORNER);
			clear(255);
			fill(0);
			for (int enemy = 0; enemy < Ecnt; enemy++) {
				fill(0, 0, 255);
				circle(Enemys[enemy].Cpx + ProductionMap.Wmap.worldX, Enemys[enemy].Cpy + ProductionMap.Wmap.worldY, Enemys[enemy].radius);
				fill(255, 0, 0, 128);
				if (Enemys[enemy].Cpx + ProductionMap.Wmap.worldX > 0
					&& Enemys[enemy].Cpx + ProductionMap.Wmap.worldX < width
					&& Enemys[enemy].Cpy + ProductionMap.Wmap.worldY > 0
					&& Enemys[enemy].Cpy + ProductionMap.Wmap.worldY < height) {
					switch (Enemys[enemy].View)
					{
					case Up:
						rect(Enemys[enemy].Cpx - ProductionMap.Wmap.XharfSize + ProductionMap.Wmap.worldX, Enemys[enemy].Cpy - Enemys[enemy].FindLen + ProductionMap.Wmap.worldY, ProductionMap.Wmap.Xsize, Enemys[enemy].FindLen);
						break;
					case Under:
						rect(Enemys[enemy].Cpx - ProductionMap.Wmap.XharfSize + ProductionMap.Wmap.worldX, Enemys[enemy].Cpy + ProductionMap.Wmap.worldY, ProductionMap.Wmap.Xsize, Enemys[enemy].FindLen);
						break;
					case Left:
						rect(Enemys[enemy].Cpx + ProductionMap.Wmap.worldX - Enemys[enemy].FindLen, Enemys[enemy].Cpy - ProductionMap.Wmap.YharfSize + ProductionMap.Wmap.worldY, Enemys[enemy].FindLen, ProductionMap.Wmap.Ysize);
						break;
					case Right:
						rect(Enemys[enemy].Cpx + ProductionMap.Wmap.worldX, Enemys[enemy].Cpy - ProductionMap.Wmap.YharfSize + ProductionMap.Wmap.worldY, Enemys[enemy].FindLen, ProductionMap.Wmap.Ysize);
						break;
					}
				}
			}
			//それぞれの座標にイメージを書き込んでいる
			for (int c = 0; c < Production.col; c++) {
				ProductionMap.Wmap.px = ProductionMap.Wmap.worldX + c * ProductionMap.Wmap.Xsize;
				for (int r = 0; r < Production.row; r++) {
					ProductionMap.Wmap.py = ProductionMap.Wmap.worldY + r * ProductionMap.Wmap.Ysize;
					ProductionMap.Wmap.mIdx = r * Production.col + c;
					if (map[ProductionMap.Wmap.mIdx] == 'a') {
						image(WallImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '1') {
						image(WallUpImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '2') {
						image(WallUnderImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '3') {
						image(WallLeftImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '4') {
						image(WallRightImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '5') {
						image(WallUpLeftCornerImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '6') {
						image(WallUnderLeftCornerImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '7') {
						image(WallUnderRightCornerImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
					}
					else if (map[ProductionMap.Wmap.mIdx] == '8') {
						image(WallUpRightCornerImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);

					}
					else if (map[ProductionMap.Wmap.mIdx] == 'g') {
						if(player.KeyFlag == true){
							image(goalImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
						}
						else {
							image(LockImg, ProductionMap.Wmap.px, ProductionMap.Wmap.py);
						}
					}
				}
			}
			fill(0);
			for (int Icnt = 0; Icnt < Production.KeyCnt; Icnt++) {
				if (ProductionMap.Key[Icnt].Substance == true) {
					image(KeyImg, ProductionMap.Key[Icnt].ItemCore.x + ProductionMap.Wmap.worldX - ProductionMap.Wmap.XharfSize, ProductionMap.Key[Icnt].ItemCore.y + ProductionMap.Wmap.worldY - ProductionMap.Wmap.YharfSize);
				}
			}
			fill(0);
			circle(player.Cpx, player.Cpy, player.radius);
			if (player.KeyFlag == true) {
				fill(255, 255, 0);
				circle(player.Cpx, player.Cpy, ProductionMap.Key->Iradius / 2);
			}
		}
		if (STATE == RESULT) {
			fill(0);
			if (GoalFlag == true) {
				image(ClearImg, 0, 0);
				if (isTrigger(KEY_K)){
					STATE = TITLE;
				}
			}
			else {
				image(OverImg, 0, 0);
				if (isTrigger(KEY_K)) {
					STATE = TITLE;
				}
			}
		}
	}
}
