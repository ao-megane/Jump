#include"Chore.h"

int Result;
int GameOver;
int Loading;
int Credit;
int Tytle[3];
int Selectbase;
int Selectfact;
imageSquare Baseicon;
imageSquare Facticon;
int Logo;
int Pause;
int Manual[2];
int Prologue[6];
int UIBack;
int UIIcon;
int White;

int Keeper;	//透過用カウントキーパー
int flag;	//現状態フラグ 0 normal 1 ending 2 bord

int TitleBGM;
int ChaseBGM;
int beLooked;
int normalBGM;
int Move;
int Choice;

int proFlag;
int manFlag;

int Score;

int lemagne;
int slemagne;
int SystemInitialize() {
	Result = LoadGraph("images/system/result.png");
	GameOver = LoadGraph("images/system/gameover.png");
	Pause = LoadGraph("images/system/pause.png");
	Credit = LoadGraph("images/system/credit.png");
	Tytle[0] = LoadGraph("images/system/opening/tytle.png");
	Tytle[1] = LoadGraph("images/system/title2.png");
	Tytle[2] = LoadGraph("images/system/title3.png");
	Selectbase = LoadGraph("images/system/select/baseback.png");
	Selectfact = LoadGraph("images/system/select/factoryback.png");
	Baseicon.Set(DISP_WIDTH / 4.0 - ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 - ICON_HEIGHT / 2.0, DISP_WIDTH / 4.0 + ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 + ICON_HEIGHT / 2.0);
	Baseicon.Setimage(LoadGraph("images/system/select/baseicon.png"));
	Facticon.Set(DISP_WIDTH / 4.0 * 2 - ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 - ICON_HEIGHT / 2.0, DISP_WIDTH / 4.0 * 2 + ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 + ICON_HEIGHT / 2.0);
	Facticon.Setimage(LoadGraph("images/system/select/factoryicon.png"));
	White = LoadGraph("images/system/white.png");
	Manual[0] = LoadGraph("images/system/manual1.png");
	Manual[1] = LoadGraph("images/system/manual2.png");

	Prologue[0] = LoadGraph("images/system/prologue/1.png");
	Prologue[1] = LoadGraph("images/system/prologue/2.png");
	Prologue[2] = LoadGraph("images/system/prologue/3.png");
	Prologue[3] = LoadGraph("images/system/prologue/4.png");
	Prologue[4] = LoadGraph("images/system/prologue/5.png");
	Prologue[5] = LoadGraph("images/system/prologue/6.png");

	Choice = LoadSoundMem("sounds/system/choice/2.wav");
	Move = LoadSoundMem("sounds/system/choice/1.wav");
	TitleBGM = LoadSoundMem("sounds/system/title.wav");
	ChaseBGM = LoadSoundMem("sounds/system/chase.wav");
	beLooked = LoadSoundMem("sounds/system/discovery.wav");
	normalBGM = LoadSoundMem("sounds/system/normal.wav");

	if (AddFontResourceEx("font/Charlemagne.ttf", FR_PRIVATE, NULL) == 0) {
		//printfDx("AddFontResourceEx失敗\n");
	}
	lemagne = CreateFontToHandle("Charlemagne", 60, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (lemagne == -1) {
		//printfDx("CreateFontToHandle失敗\n");
	}
	slemagne = CreateFontToHandle("Charlemagne", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (lemagne == -1) {
		//printfDx("CreateFontToHandle失敗\n");
	}
	Keeper = 0;
	flag = 0;
	proFlag = 0;
	manFlag = 0;

	return 0;
}

int PlayMove() {
	PlaySoundMem(Move, DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}

int PlayChoice() {
	PlaySoundMem(Choice, DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}

int PlaybeLooked() {
	PlaySoundMem(beLooked, DX_PLAYTYPE_BACK);
	return 0;
}

int* ScorePass() {
	return &Score;
}

int PlayTitleBGM() {
	StopSoundMem(TitleBGM);
	StopSoundMem(normalBGM);
	StopSoundMem(ChaseBGM);
	PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int PlaynormalBGM() {
	StopSoundMem(TitleBGM);
	StopSoundMem(normalBGM);
	StopSoundMem(ChaseBGM);
	PlaySoundMem(normalBGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int PlayChaseBGM() {
	//StopSoundMem(ChaseBGM);
	PlaySoundMem(ChaseBGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int StopChaseBGM() {
	StopSoundMem(ChaseBGM);;
	return 0;
}
int clockcount;
int DrawOP(int count) {
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle[0], true);

	clockcount = count % (20 * 60 * 2);
	DrawModiGraph(
		-clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		-clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		Tytle[1], true
	);
	DrawModiGraph(
		DISP_WIDTH * 2 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 4 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 4 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		Tytle[1], true
	);

	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle[2], true);
	return 0;
}
int DrawSelect(int local) {
	switch (local+1)
	{
	case 1:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Selectbase, true);
		DrawBox(Baseicon.Square::GetLU().Getx(), Baseicon.Square::GetLU().Gety(), Baseicon.Square::GetRD().Getx(), Baseicon.Square::GetRD().Gety(), RED, 0);
		break;
	case 2:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Selectfact, true);
		DrawBox(Facticon.Square::GetLU().Getx(), Facticon.Square::GetLU().Gety(), Facticon.Square::GetRD().Getx(), Facticon.Square::GetRD().Gety(), RED, 0);
		
		break;
	case 3:
		DrawFormatString(500, 500, RED, "工場地下！！");
		break;
	default:
		break;
	}
	Facticon.Draw();
	Baseicon.Draw();

	return 0;
}
int DrawTitleSentence(int flag) {
	//DrawFormatStringToHandle(1575, 880, GRAY, lemagne, "");
	switch (flag)
	{
	case 0://play
		DrawFormatString(0, 30, RED, "→PLAY!!");
		//DrawFormatStringToHandle(1575, 900, BLACK, lemagne, "PLAY");
		break;
	case 1://manual
		DrawFormatString(0, 30, RED, "→MANUAL!!");
		//DrawFormatStringToHandle(1500, 900, BLACK, lemagne, "MANUAL");
		break;
	case 2://credit
		DrawFormatString(0, 30, RED, "→CREDIT!!");
		//DrawFormatStringToHandle(1530, 900, BLACK, lemagne, "CREDIT");
		break;
	default:
		break;
	}
	//DrawFormatStringToHandle(1350, 960, GRAY, slemagne, "Choose by UP or DOWN");
	//DrawFormatStringToHandle(1350, 1010, GRAY, slemagne, "Select by B");
	//DrawFormatStringToHandle(1250, 1080, GRAY, lemagne, "Select by B");
	//DrawFormatStringToHandle(1350, 1060, GRAY, slemagne, "PLEASE READ MANUAL");
	return 0;
}

int DrawPrologue(int b) {
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, ProBack, true);
	switch (proFlag)
	{
	case 0:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[1], true);
		DrawFormatString(0, 20, RED, "PROLOGUE1");
		break;
	case 1:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[2], true);
		DrawFormatString(0, 40, RED, "PROLOGUE2");
		break;
	case 2:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[3], true);
		DrawFormatString(0, 80, RED, "PROLOGUE3");
		break;
	case 3:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Prologue[4], true);
		DrawFormatString(0, 120, RED, "PROLOGUE4");
		break;
	default:
		break;
	}
	if (b == 1) {
		proFlag++;
		if (proFlag == 4) {
			proFlag = 0;
			return 1;
		}
	}
	return 0;
}

int DrawPause() {
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Pause, true);
	//DrawFormatString(0, 0, RED, "PAUSE");
	return 0;
}

int DrawManual(int b) {
	switch (manFlag)
	{
	case 0:
		//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual[0], true);
		DrawFormatString(20, 20, RED, "MANUAL");
		break;
	case 1:
		//DrawModiGraph(20, 20, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual[1], true);
		DrawFormatString(20, 20, RED, "3");
		break;
	case 2:
		//DrawModiGraph(20, 20, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Floor1Image, true);
		//DrawModiGraph(20, 20, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Floor1WallsImage, true);
		//DrawFormatStringToHandle(52, 52, BLACK, lemagne, "floor1");
		//DrawFormatStringToHandle(50, 50, ORANGE, lemagne, "floor1");
		DrawFormatString(20, 20, RED, "2");
		break;
	case 3:
		//DrawModiGraph(20, 20, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Floor2Image, true);
		//DrawModiGraph(20, 20, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Floor2WallsImage, true);
		//DrawFormatStringToHandle(52, 52, BLACK, lemagne, "floor2");
		//DrawFormatStringToHandle(50, 50, ORANGE, lemagne, "floor2");
		DrawFormatString(20, 20, RED, "1");
		break;
	}

	if (b == 1) {
		manFlag++;
		if (manFlag == 4) {
			manFlag = 0;
			return 1;
		}
	}
	return 0;
}

int DrawCredit() {
	//DrawFormatStringFToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, RED, nishiki, "CREDIT!");
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Credit, true);
	return 0;
}

int DrawUI(int count) {
	DrawFormatString(DISP_WIDTH - 50, 50, WHITE, "%d", count / 30);
	return 0;
}
int toUIDamage(int damage,int count) {
	return 0;
}


void DrawChore() {
	//DrawFormatString(0, 0, RED, "UI?");
	//if (count < NORMAL_COUNT) {
	//	DrawModiGraph(
	//		UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT,
	//		UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT, UIBack, true);

	//DrawFormatStringFToHandle(DISP_WIDTH - 500, 10, BROWN, nishiki, "SCORE : %5d", Score);
}

int UpdataBack(int count) {//count使わなくてもできる(?)
	return 0;
}

int DrawBack(int floor,Dot player) {

	DrawFormatString(0, 20, RED, "Draw BackGround");
	/*if (floor == 1) {
		DrawModiGraph(
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			Floor1Image, true);
	}
	else if (floor == 2) {
		DrawModiGraph(
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			StepImage, true);
	}
	else if (floor == 3) {
		DrawModiGraph(
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			StepImage, true);
	}
	else if (floor == 4) {
		DrawModiGraph(
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety(),
			DISP_WIDTH / 2.0 - player.Getx() + MAP_WIDTH, DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			DISP_WIDTH / 2.0 - player.Getx(), DISP_HEIGHT / 2.0 - player.Gety() + MAP_HEIGHT,
			Floor2Image, true);
	}*/
	return 0;
}


int DrawWalls(int floor,Dot player) {
	return 0;
}

/*---------------------------------------------------------------------------*/

int NumofPlayers;
int NumofWinner;
int HighScore;

int InputFile(std::string file) {
	std::ifstream fin("kanuma2017.txt"); // ファイルを開く
	NumofPlayers = 0;
	NumofWinner = 0;
	HighScore = 0;
	if (fin.fail()) {  // if(!fin)でもよい。
		std::cout << "入力ファイルをオープンできません" << std:: endl;
		return 1;
	}
	fin >> NumofPlayers >> NumofWinner >> HighScore;

	return 0;
}

int DrawData() {
	/*DrawFormatStringToHandle(DISP_WIDTH / 2 - 500, 50, BROWN, nishiki, "プレイ人数:%3d", NumofPlayers);
	DrawFormatStringToHandle(DISP_WIDTH / 2 + 0, 50, BROWN, nishiki, "クリア率:%5.2f%%", (double)(NumofWinner)/(double)(NumofPlayers) * 100.0);
	DrawFormatStringToHandle(DISP_WIDTH / 2 + 500, 50, BROWN, nishiki, "ハイスコア:%5d", HighScore);
	*/
	DrawFormatString(0, 100, RED, "DATA!");
	return 0;
}

int UpdataFile(std::string file, int levelFlag, int score) {
	std::ofstream fout("kanuma2017.txt");
	if (fout.fail()) {  // if(!fin)でもよい。
		std::cout << "出力ファイルをオープンできません" << std::endl;
		return 1;
	}
	fout << NumofPlayers << "\n" << NumofWinner << "\n" << HighScore << "\n";

	return 0;
}

int SetWinner(int levelFlag, int count,int* score) {
	Keeper = count;
	NumofPlayers++;
	NumofWinner++;
	if (HighScore < *score) HighScore = *score;
	flag = 1;
	return 0;
}
int SetLoser(int levelFlag, int count) {
	Keeper = count;
	NumofPlayers++;
	flag = 1;
	return 0;
}
int Keeper2;
int WinnerUpdata(int count) {
	/*DrawModiGraph(
		DISP_WIDTH - (count - Keeper) * 4, 300,
		DISP_WIDTH + 700 - (count - Keeper) * 4, 300,
		DISP_WIDTH + 700 - (count - Keeper) * 4, 700 + 300,
		DISP_WIDTH - (count - Keeper) * 4, 700 + 300,
		Credit, true);
	if ((DISP_WIDTH - 750 - (count - Keeper) * 4 + 300) < DISP_WIDTH * 0 / 4 && (flag == 1)) {
		Keeper2 = count;
		flag = 2;
		return 1;
	}
	else if (flag == 2) {
		DrawClearBord(count);
		return 1;
	}
	else return 0;*/
	return 0;
}
int LoserUpdata(int count) {
	//DrawLoseBord(count);
	return 1;
}
int DrawClearBord(int count) {
	if (count <= 180) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper2) / 60.0 * 255.0);		//ブレンドモードを設定
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Result, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Clear, true);
	//DrawFormatString(1000, 1000, RED, "CLEAR!!");
	return 0;
}
int DrawGameOverBord(int count) {
	if ((count - Keeper) <= 180) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper) / 60.0 * 255);		//ブレンドモードを設定
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	else if (count >= 90) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
		return 1;
	}
	return 0;
}

int DrawWhite(int count,int keeper) {
	if (keeper != 0) {
		if ((count - keeper) <= 40 && (count - keeper) > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (count - keeper) / 60.0 * 255);		//ブレンドモードを設定
			DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, White, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
		}
		else {
			//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, White, true);
			return 1;
		}
	}
	return 0;
}

int yesBGM() {
	ChangeVolumeSoundMem(255, normalBGM);
	ChangeVolumeSoundMem(255, ChaseBGM);
	ChangeVolumeSoundMem(255, beLooked);
	return 0;
}

int noBGM() {
	ChangeVolumeSoundMem(0, normalBGM);
	ChangeVolumeSoundMem(0, ChaseBGM);
	//ChangeVolumeSoundMem(0, beLooked);
	return 0;
}

//bool IsHitColorCtoAll(Circle x, int a, int softimage) {
//	//半径の正方形作って，その中で円内の点を判定
//	if (softimage == 0)
//		return false;
//	for (double i = x.Getx() - x.GetRadius(); i < x.Getx() + x.GetRadius(); i++) {
//		for (double j = x.Gety() - x.GetRadius(); j < x.Gety() + x.GetRadius(); j++) {
//			if (((i - x.Getx())*(i - x.Getx()) + (j - x.Gety())*(j - x.Gety())) <= x.GetRadius()*x.GetRadius())
//				if (a == GetPixelPalCodeSoftImage(softimage, x.Getx(), x.Gety()))
//					return true;
//		}
//	}
//	return false;
//}
//
//bool IsHitColorDot(Dot x, int a, int image) {
//	if (a == GetPixelPalCodeSoftImage(image, x.Getx(), x.Gety()))
//		return true;
//	else
//		return false;
//}


/*-------------------------------------------------------------*/
double dir;
double CalcDir(Dot c, Dot a) {

	if (a.Getx() - c.Getx() < 0) dir = atan(-(a.Gety() - c.Gety()) / (a.Getx() - c.Getx())) + PI;
	else if (a.Getx() - c.Getx() == 0 && (a.Gety() - c.Gety()) >= 0)
		dir = 1.0 / 2.0 * PI;
	else if (a.Getx() - c.Getx() == 0 && (a.Gety() - c.Gety()) <= 0)
		dir = 3.0 / 2.0 * PI;
	else if (a.Getx() - c.Getx() > 0) dir = atan(-(a.Gety() - c.Gety()) / (a.Getx() - c.Getx()));

	while (dir < 0) dir += 2 * PI;

	return dir;
}
double CalcDir(Dot a) {//無入力は計算しない
	if (a.Getx() == 0 && a.Gety() > 0) {
		return  3.0 / 2.0 * PI;
	}
	else if (a.Getx() == 0 && a.Gety() < 0) {
		return 1.0 / 2.0* PI;
	}
	else if (a.Gety() == 0 && a.Getx() > 0) {
		return 0;
	}
	else if (a.Gety() == 0 && a.Getx() < 0) {
		return PI;
	}
	else if (a.Getx() < 0) {
		return atan(-a.Gety() / a.Getx()) + PI;
	}
	else if (a.Getx() > 0) {
		dir = atan(-a.Gety() / a.Getx());
		while (dir < 0) dir += 2 * PI;
		return dir;
	}
}
double CalcDir(double x, double y) {
	if (x == 0 && y > 0) {
		return  3.0 / 2.0 * PI;
	}
	else if (x == 0 && y < 0) {
		return 1.0 / 2.0* PI;
	}
	else if (y == 0 && x > 0) {
		return 0;
	}
	else if (y == 0 && x < 0) {
		return PI;
	}
	else if (x < 0) {
		return atan(-y / x) + PI;
	}
	else if (x > 0) {
		dir = atan(-y / x);
		while (dir < 0) dir += 2 * PI;
		return dir;
	}
}

double CalcDistance(Dot a, Dot b) {
	return sqrt(
		(a.Getx() - b.Getx())*(a.Getx() - b.Getx()) + (a.Gety() - b.Gety())*(a.Gety() - b.Gety())
			);
}
double CalcDistance(Dot a) {
	return sqrt(
		(a.Getx())*(a.Getx()) + (a.Gety())*(a.Gety())
	);
}

double CalcDirDiff(double dir1, double dir2) {
	if (dir2 - dir1 < 0) dir2 += 2 * PI;
	if (dir2 - dir1 <= PI) return dir2 - dir1;
	else return 2 * PI - dir2 + dir1;
}

Dot RotateDot(double thita, Dot x, Dot c) {
	Dot ans;
	ans.Setx((x.Getx() - c.Getx())*cos(-thita) - (x.Gety() - c.Gety())*sin(-thita) + c.Getx());
	ans.Sety((x.Getx() - c.Getx())*sin(-thita) + (x.Gety() - c.Gety())*cos(-thita) + c.Gety());
	return ans;
}

Dot RotateDot(double thita, Dot x) {
	Dot ans;
	ans.Setx((x.Getx())*cos(-thita) - (x.Gety())*sin(-thita));
	ans.Sety((x.Getx())*sin(-thita) + (x.Gety())*cos(-thita));
	return ans;
}

int SetRand() {
	srand((unsigned int)time(NULL));
	return 0;
}

int GetRand() {
	return rand();
}

int DrawLineByDot(Dot a,Dot b,int handle) {
	DrawLine(a.Getx(), a.Gety(), b.Getx(), b.Gety(), handle, 0);
	return 0;
}

/*----------------------------------------------------------------------------------------------*/

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.0;
char Key[256];
void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(DISP_WIDTH-200, DISP_HEIGHT-40, WHITE, "FPS %.1f", Fps); //fpsを表示
	return;
}