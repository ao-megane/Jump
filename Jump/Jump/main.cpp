#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Stages.h"
//#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"
//#include"Key.h"
//#include"Color.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(DISP_WIDTH, DISP_HEIGHT, 32);
	{
		SetWindowSizeChangeEnableFlag(TRUE);
		SetWindowSizeExtendRate(0.8);
		ChangeWindowMode(TRUE);
		SetBackgroundColor(0, 0, 0);
	}
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	XINPUT_STATE input;
	int key[20] = { 0 };
	int flag = 0;
	int selectFlag = 0;	//0:play,1:manual,2:credit
	int stageFlag = 0;	//stage選択フラグ
	int count = 0;
	int keepCount = 0;
	Player player;
	
	InputInitialize(key);
	player.Initialize();
	StagesInitialize();
	SystemInitialize();
	SetRand();
	
	//EnemyMngInitialize();
	//ColorMngInitialize();
	//InputFile("kanuma2017.txt");

	PlayTitleBGM();

	flag = 0;
	int Winner[STAGE_NUM] = { 0 };
	int Loser[STAGE_NUM] = { 0 };
	int down = 0;
	int up = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		InputUpdata(input, key);

		if (THUMB_Y >= 80) down++; else down = 0;
		if (THUMB_Y <= -80) up++; else up = 0;

		switch (flag) {
		case 0://OP
			DrawOP(count);
			//if (Y > 0) DrawData();
			//if (Y > 0) DrawFormatString(0, 0, BLACK, "ClearRate:%f,Winner:%d,Loser:%d", (double)Winner / (double)(Winner + Loser), Winner, Loser);

			if (down == 1) {
				PlayMove();
				if (selectFlag == 2) selectFlag = 0;
				else selectFlag++;
			}
			if (up == 1) {
				PlayMove();
				if (selectFlag == 0) selectFlag = 2;
				else selectFlag--;
			}
			DrawTitleSentence(selectFlag);
			if (B == 1) {
				PlayChoice();
				switch (selectFlag)
				{
				case 0://play
					flag = 1;
					break;
				case 1://manual
					flag = 5;
					break;
				case 2://credit
					flag = 6;
					break;
				default:
					break;
				}
			}
			break;
		case 1://ステージ選択画面
			DrawFormatString(0, 0, WHITE, "selecting");
			DrawFormatString(0, 40, WHITE, "STAGE%d",stageFlag);
			if (down == 1) {
				PlayMove();
				if (stageFlag == 2) stageFlag = 0;
				else stageFlag++;
			}
			if (up == 1) {
				PlayMove();
				if (stageFlag == 0) stageFlag = 2;
				else stageFlag--;
			}
			if (B == 1) {
				flag = 2;
			}
			break;
		case 2://loading
			DrawFormatString(0, 0, WHITE, "loading");
			count = 0;
			StageLoad(stageFlag);
			//player.Set();
			//SetKeyPosi();
			//EnemyMngSet();
			flag = 3;
			break;
		case 3://playing
			DrawFormatString(0, 0, WHITE, "playing");
			player.Update(count,key);
			StageUpdata(stageFlag,count,0);
			DrawStage(stageFlag);
			player.Draw();
			break;
		case 4://gameover
			DrawFormatString(0, 0, WHITE, "gameover");
			DrawGameOverBord(count - keepCount);
			if (count - keepCount > 180) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 5://gameclear
			DrawFormatString(0, 0, WHITE, "gameclear");
			DrawClearBord(count - keepCount);
			if (count - keepCount > 180) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 6://マニュアル
			DrawFormatString(0, 0, WHITE, "manual1");
			if (B == 1)
				PlayChoice();
			if (DrawManual(B)) {
				flag = 0;
				count = 0;
			}
			break;
		case 7://クレジット
			DrawFormatString(0, 0, WHITE, "credit");
			DrawCredit();
			if (B == 1) {
				PlayChoice();
				flag = 0;
			}
			break;
		case 8://ポーズ
			DrawFormatString(0, 0, WHITE, "pause");
			DrawPause();
			//player.UIDraw(count);
			count--;
			if (B == 1) flag = 2;
			if (A == 1) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		//case 9://ゲーム開始前のマニュアル
		//	DrawFormatString(0, 0, WHITE, "manual2");
		//	if (B == 1)
		//		PlayChoice();
		//	if (DrawManual(B)) {
		//		flag = 2;
		//		count = 0;
		//		PlaynormalBGM();
		//	}
		//	break;

		default:
			break;
		}

		count++;
		if (CheckHitKey(KEY_INPUT_DELETE)) break;

		//PrintInput(key);
		FpsTimeFanction();
		ScreenFlip();
	}

	//UpdataFile("kanuma2017.txt", 0, 0);
	DxLib_End();

	return 0;
}