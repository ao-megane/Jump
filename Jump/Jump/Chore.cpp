#include"Chore.h"

int Result;
int GameOver;
int Loading;
int Credit;
int Tytle;
int RedLightning[3];
int GreenLightning[3];
int Selectbase;
int Selectfact;
imageSquare Baseicon;
imageSquare Facticon;
imageSquare Facticon2;
int Logo;
int Pause;
int Manual[2];
int Prologue[6];

int descri[12];

double HighScore[STAGE_NUM];

int UIBack;
int UIIcon;
int White;

int Keeper;	//透過用カウントキーパー
int flag;	//現状態フラグ 0 normal 1 ending 2 bord
int damagecount;	//ダメージ表示用フラグキーパー
int damagedecoi;	//ダメージ表示用値キーパー

int TytleBGM;
int playBGM;
int Move;
int Choice;

int proFlag;
int manFlag;

int Score;

//int lemagne;
//int slemagne;
int makinas;
int smakinas;
int vsmakinas;
int dmakinas;
int SystemInitialize() {
	Result = LoadGraph("images/system/result.png");
	GameOver = LoadGraph("images/system/gameover.png");
	Pause = LoadGraph("images/system/pause.png");
	Credit = LoadGraph("images/system/credit.png");
	Tytle = LoadGraph("images/system/opening/tytle.png");
	Selectbase = LoadGraph("images/system/select/baseback.png");
	Selectfact = LoadGraph("images/system/select/factoryback.png");
	Baseicon.Set(DISP_WIDTH / 4.0 - ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 - ICON_HEIGHT / 2.0, DISP_WIDTH / 4.0 + ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 + ICON_HEIGHT / 2.0);
	Baseicon.Setimage(LoadGraph("images/system/select/baseicon.png"));
	Facticon.Set(DISP_WIDTH / 4.0 * 2 - ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 - ICON_HEIGHT / 2.0, DISP_WIDTH / 4.0 * 2 + ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 + ICON_HEIGHT / 2.0);
	Facticon.Setimage(LoadGraph("images/system/select/factoryicon.png"));
	Facticon2.Set(DISP_WIDTH / 4.0 * 3 - ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 - ICON_HEIGHT / 2.0, DISP_WIDTH / 4.0 * 3 + ICON_WIDTH / 2.0, DISP_HEIGHT / 2.0 + ICON_HEIGHT / 2.0);
	Facticon2.Setimage(LoadGraph("images/system/select/factoryicon2.png"));
	White = LoadGraph("images/system/white.png");
	Manual[0] = LoadGraph("images/system/manual1.png");
	Manual[1] = LoadGraph("images/system/manual2.png");
	RedLightning[0] = LoadGraph("images/system/redlightning/1.png");
	RedLightning[1] = LoadGraph("images/system/redlightning/2.png");
	RedLightning[2] = LoadGraph("images/system/redlightning/3.png");

	GreenLightning[0] = LoadGraph("images/system/greenlightning/1.png");
	GreenLightning[1] = LoadGraph("images/system/greenlightning/2.png");
	GreenLightning[2] = LoadGraph("images/system/greenlightning/3.png");

	for (int i = 0; i < 12; i++) {
		std::string a = "images/system/descri/";
		a += std::to_string(i + 1);
		a += ".png";
		descri[i] = LoadGraph(a.c_str());
	}

	Prologue[0] = LoadGraph("images/system/prologue/1.png");
	Prologue[1] = LoadGraph("images/system/prologue/2.png");
	Prologue[2] = LoadGraph("images/system/prologue/3.png");
	Prologue[3] = LoadGraph("images/system/prologue/4.png");
	Prologue[4] = LoadGraph("images/system/prologue/5.png");
	Prologue[5] = LoadGraph("images/system/prologue/6.png");

	Choice = LoadSoundMem("sounds/system/decide.wav");
	Move = LoadSoundMem("sounds/system/select.wav");
	TytleBGM = LoadSoundMem("sounds/system/tytle.wav");
	//ChaseBGM = LoadSoundMem("sounds/system/chase.wav");
	//beLooked = LoadSoundMem("sounds/system/discovery.wav");
	playBGM = LoadSoundMem("sounds/system/playing.wav");

	//if (AddFontResourceEx("font/Charlemagne.ttf", FR_PRIVATE, NULL) == 0) {
	//	//printfDx("AddFontResourceEx失敗\n");
	//}
	//lemagne = CreateFontToHandle("Charlemagne", 60, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	//if (lemagne == -1) {
	//	//printfDx("CreateFontToHandle失敗\n");
	//}
	//slemagne = CreateFontToHandle("Charlemagne", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	//if (lemagne == -1) {
	//	//printfDx("CreateFontToHandle失敗\n");
	//}
	if (AddFontResourceEx("font/Makinas-Scrap-5.otf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResourceEx失敗\n");
	}
	makinas = CreateFontToHandle("マキナス Scrap 5", 60, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (makinas == -1) {
		printfDx("CreateFontToHandle失敗\n");
	}
	smakinas = CreateFontToHandle("マキナス Scrap 5", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (smakinas == -1) {
		printfDx("CreateFontToHandle失敗\n");
	}
	vsmakinas = CreateFontToHandle("マキナス Scrap 5", 110, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (smakinas == -1) {
		printfDx("CreateFontToHandle失敗\n");
	}
	dmakinas = CreateFontToHandle("マキナス Scrap 5", 90, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (smakinas == -1) {
		printfDx("CreateFontToHandle失敗\n");
	}
	Keeper = 0;
	flag = 0;
	proFlag = 0;
	manFlag = 0;

	return 0;
}

int SystemSet() {
	damagecount = -1000;	//ダメージ表示用フラグキーパー
	damagedecoi = 0;	//ダメージ表示用値キーパー

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

int* ScorePass() {
	return &Score;
}

int PlayTytleBGM() {
	StopSoundMem(TytleBGM);
	StopSoundMem(playBGM);
	PlaySoundMem(TytleBGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int PlayplayBGM() {
	StopSoundMem(TytleBGM);
	StopSoundMem(playBGM);
	//PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP);
	return 0;
}

int clockcount;
int DrawOP(int count) {
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle, true);

	clockcount = count % (30 * 7 * 2);
	/*DrawModiGraph(
		-clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		-clockcount / (20.0 * 60 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		Tytle, true
	);
	DrawModiGraph(
		DISP_WIDTH * 2 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 4 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, 0,
		DISP_WIDTH * 4 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		DISP_WIDTH * 2 - clockcount / (20.0 * 60.0 * 2) * DISP_WIDTH * 2, DISP_HEIGHT,
		Tytle[1], true
	);*/

	//if ((count - Keeper) <= 180) {
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper) / 60.0 * 255);		//ブレンドモードを設定
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	//}
	//else if (count >= 90) {
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
	//	return 1;
	//}

	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[0], true);
	if (clockcount < 6.4 * 30) {

	}
	else if (clockcount < 6.4 * 30 + 2) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GreenLightning[0], true);
	}
	else if (clockcount < 6.4 * 30 + 2 + 3) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GreenLightning[1], true);
	}
	else if (clockcount < 6.4 * 30 + 2 + 3 + 1) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GreenLightning[2], true);
	}
	else if (clockcount < 6.4 * 30 + 6 + 2) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GreenLightning[1], true);
	}
	else if (clockcount < 6.4 * 30 + 6 + 2 + 1) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GreenLightning[0], true);
	}//稲妻一個目
	else if (clockcount < 13.4 * 30) {

	}
	else if (clockcount < 13.4 * 30 + 2) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[0], true);
	}
	else if (clockcount < 13.4 * 30 + 2 + 3) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[1], true);
	}
	else if (clockcount < 13.4 * 30 + 2 + 3 + 1) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[2], true);
	}
	else if (clockcount < 13.4 * 30 + 6 + 3) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[1], true);
	}
	else if (clockcount < 13.4 * 30 + 6 + 3 + 2) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, RedLightning[0], true);
	}
	
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle, true);
	DrawStringToHandle(DISP_WIDTH / 3.0, DISP_HEIGHT - 300, "左スティック上下で選択\nBで決定", WHITE, smakinas);
	//DrawFormatString(0, 0, RED, "%d", clockcount);
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
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Selectfact, true);
		DrawBox(Facticon2.Square::GetLU().Getx(), Facticon2.Square::GetLU().Gety(), Facticon2.Square::GetRD().Getx(), Facticon2.Square::GetRD().Gety(), RED, 0);

		break;
	default:
		break;
	}
	Facticon2.Draw();
	Facticon.Draw();
	Baseicon.Draw();

	return 0;
}

bool StageBeforeDescription(int stage, int key[]) {
	/*switch (stage)
	{
	case 0:
	DrawFormatString(300, 300, RED, "STAGE1_BEFORE_DESCRIPTION!");
	break;
	case 1:
	DrawFormatString(300, 300, RED, "STAGE2_BEFORE_DESCRIPTION!");
	break;
	case 2:
	DrawFormatString(300, 300, RED, "STAGE3_BEFORE_DESCRIPTION!");
	break;
	case 3:
	DrawFormatString(300, 300, RED, "STAGE4_BEFORE_DESCRIPTION!");
	break;
	case 4:
	DrawFormatString(300, 300, RED, "STAGE5_BEFORE_DESCRIPTION!");
	break;
	default:
	break;
	}*/
	if (stage < 5) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Selectbase, true);
	}
	else {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Selectfact, true);
	}
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, descri[stage], true);

	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, descri[0], true);

	if (B == 1)
		return true;
	else
		return false;
}


int DrawTitleSentence(int flag) {
	//DrawFormatStringToHandle(1575, 880, GRAY, lemagne, "");
	switch (flag)
	{
	case 0://play
		//DrawStringtoHandle(0, 30, RED, "→PLAY!!");
		DrawFormatStringToHandle(1575, 900, WHITE, smakinas, "PLAY");
		break;
	case 1://manual
		//DrawFormatString(0, 30, RED, "→MANUAL!!");
		DrawFormatStringToHandle(1500, 900, WHITE, smakinas, "MANUAL");
		break;
	case 2://credit
		//DrawFormatString(0, 30, RED, "→CREDIT!!");
		DrawFormatStringToHandle(1530, 900, WHITE, smakinas, "CREDIT");
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
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual[0], true);
	switch (manFlag)
	{
	case 0:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual[0], true);
		//DrawFormatString(20, 20, RED, "MANUAL");
		break;
	case 1:
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Manual[1], true);
		//DrawFormatString(20, 20, RED, "3");
		break;
	}

	if (b == 1) {
		manFlag++;
		if (manFlag == 2) {
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
	//DrawFormatString(DISP_WIDTH - 50, 50, WHITE, "%d", count / 30);
	DrawFormatStringToHandle(DISP_WIDTH - 170-20, 10, WHITE, vsmakinas, "%3d", count / 30);
	return 0;
}
int DrawUIDamage(int damage,int count) {
	if (damage != 0) {//ダメージがあれば
		damagecount = count;
		damagedecoi += damage;
		//printfDx("decoing\n");
	}
	else {//ダメージがなければ
		//printfDx("aaaaaa\n");
	}
	if (count - damagecount <= 45) {//ダメージから一定時間たつまで
		if(damagedecoi != 0)
			DrawFormatStringToHandle(DISP_WIDTH - 150 + 0, 10 + 50, RED, dmakinas, "-%2d", damagedecoi);
	}
	else {//ダメージから一定時間たったら
		damagedecoi = 0;
	}

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

	//DrawFormatString(0, 20, RED, "Draw BackGround");
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

//int NumofPlayers;
//int NumofWinner;
//int HighScore;

int InputFile() {
	std::ifstream fin("data.txt"); // ファイルを開く
	//NumofPlayers = 0;
	//NumofWinner = 0;
	//HighScore = 0;
	if (fin.fail()) {  // if(!fin)でもよい。
		//std::cout << "入力ファイルをオープンできません" << std:: endl;
		printfDx("入力ファイルをオープンできません");
		return 1;
	}
	//fin >> NumofPlayers >> NumofWinner >> HighScore;
	for (int i = 0; i < STAGE_NUM; i++) {
		fin >> HighScore[i];
		//HighScore[i] = 999;
	}

	for (int i = 0; i < STAGE_NUM; i++) {
		//printfDx("%f\n", HighScore[i]);
	}

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

int UpdataFile(int stage, int score) {

	if (HighScore[stage] < score) {
		HighScore[stage] = score;
	}
	return 0;
}

int OutputFile() {
	std::ofstream fout("data.txt");
	if (fout.fail()) {  // if(!fin)でもよい。
		std::cout << "出力ファイルをオープンできません" << std::endl;
		return 1;
	}
	for (int i = 0; i < STAGE_NUM; i++) {
		fout << HighScore[i] << "\n";
		//printfDx("%f\n", HighScore[i]);
	}
	return 0;
}

//int SetWinner(int levelFlag, int count,int* score) {
//	Keeper = count;
//	NumofPlayers++;
//	NumofWinner++;
//	if (HighScore < *score) HighScore = *score;
//	flag = 1;
//	return 0;
//}
//int SetLoser(int levelFlag, int count) {
//	Keeper = count;
//	NumofPlayers++;
//	flag = 1;
//	return 0;
//}
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
int DrawResult(int keepcount,int stage) {
	//if (count <= 180) {
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper2) / 60.0 * 255.0);		//ブレンドモードを設定
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Result, true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	//}
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Result, true);
	DrawFormatStringToHandle(640-30-10, 560, WHITE, vsmakinas, "%3.3f", keepcount/30.0);
	DrawFormatStringToHandle(640 + 400, 560 + 300, WHITE, smakinas, "HIGH_SCORE : %3.3f", HighScore[stage]/30.0);
	switch (stage)
	{
	case 0:
		if(STAGE1_COUNT - keepcount < 10*30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE1_COUNT - keepcount < 20*30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE1_COUNT - keepcount < 30*30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE1_COUNT - keepcount < 40*30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 1:
		if (STAGE2_COUNT - keepcount < 10 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE2_COUNT - keepcount < 20 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE2_COUNT - keepcount < 30 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE2_COUNT - keepcount < 40 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 2:
		if (STAGE3_COUNT - keepcount < 10 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE3_COUNT - keepcount < 20 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE3_COUNT - keepcount < 30 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE3_COUNT - keepcount < 40 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 3:
		if (STAGE4_COUNT - keepcount < 10 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE4_COUNT - keepcount < 20 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE4_COUNT - keepcount < 30 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE4_COUNT - keepcount < 40 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 4:
		if (STAGE5_COUNT - keepcount < 15 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE5_COUNT - keepcount < 25 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE5_COUNT - keepcount < 35 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE5_COUNT - keepcount < 45 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 5:
		if (STAGE6_COUNT - keepcount < 15 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE6_COUNT - keepcount < 25 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE6_COUNT - keepcount < 35 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE6_COUNT - keepcount < 45 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 6:
		if (STAGE7_COUNT - keepcount < 12 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE7_COUNT - keepcount < 22 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE7_COUNT - keepcount < 32 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE7_COUNT - keepcount < 42 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 7:
		if (STAGE8_COUNT - keepcount < 13 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE8_COUNT - keepcount < 23 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE8_COUNT - keepcount < 33 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE8_COUNT - keepcount < 43 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 8:
		if (STAGE9_COUNT - keepcount < 12 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE9_COUNT - keepcount < 22 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE9_COUNT - keepcount < 32 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE9_COUNT - keepcount < 42 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 9:
		if (STAGE10_COUNT - keepcount < 12 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE10_COUNT - keepcount < 22 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE10_COUNT - keepcount < 32 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE10_COUNT - keepcount < 42 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 10:
		if (STAGE11_COUNT - keepcount < 15 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE11_COUNT - keepcount < 25 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE11_COUNT - keepcount < 35 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE11_COUNT - keepcount < 45 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	case 11:
		if (STAGE12_COUNT - keepcount < 14 * 30) DrawFormatStringToHandle(1380, 560, RED, vsmakinas, "S", keepcount / 30);
		else if (STAGE12_COUNT - keepcount < 24 * 30) DrawFormatStringToHandle(1380, 560, ORANGE, vsmakinas, "A", keepcount / 30);
		else if (STAGE12_COUNT - keepcount < 34 * 30) DrawFormatStringToHandle(1380, 560, GREEN, vsmakinas, "B", keepcount / 30);
		else if (STAGE12_COUNT - keepcount < 44 * 30) DrawFormatStringToHandle(1380, 560, WHITE, vsmakinas, "C", keepcount / 30);
		else  DrawFormatStringToHandle(1380, 560, BLUE, vsmakinas, "D", keepcount / 30);
		break;
	default:
		break;
	}
	
	return 0;
}
int DrawGameOverBord(int count) {
	//if ((count - Keeper) <= 180) {
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper) / 60.0 * 255);		//ブレンドモードを設定
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	//}
	//else if (count >= 90) {
	//	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
	//	return 1;
	//}

	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);

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