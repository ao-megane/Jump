#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Stages.h"
#include"EnemyMng.h"
#include"Effect.h"
#include"Value.h"
#include"Chore.h"
#include"fps.h"
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
	Fps fps;
	int key[20] = { 0 };
	int flag = 0;
	int selectFlag = 0;	//0:play,1:manual,2:credit
	int stageFlag = 0;	//stage選択フラグ
	int count = 0;
	int keepCount = 0;
	Player player;
	
	InputInitialize(key);
	EnemyMngInitialize();
	player.Initialize();
	EffectMngInitialize();
	StagesInitialize();
	SystemInitialize();
	SetRand();
	
	//EnemyMngInitialize();
	//ColorMngInitialize();
	//InputFile("kanuma2017.txt");

	PlayTitleBGM();

	flag = 0;
	int damage = 0;
	int sumdamage = 0;
	int Winner[STAGE_NUM] = { 0 };
	int Loser[STAGE_NUM] = { 0 };
	int down = 0;
	int up = 0;
	int right = 0;
	int left = 0;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		InputUpdata(input, key);
		fps.Update();

		if (THUMB_Y >= 80) down++; else down = 0;
		if (THUMB_Y <= -80) up++; else up = 0;
		if (THUMB_X >= 80) right++; else right = 0;
		if (THUMB_X <= -80) left++; else left = 0;

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
					flag = 7;
					break;
				case 2://credit
					flag = 8;
					break;
				default:
					break;
				}
			}
			break;
		case 1://ステージ選択画面
			DrawFormatString(0, 0, WHITE, "selecting");
			DrawFormatString(0, 40, WHITE, "STAGE%d",stageFlag+1);
			if (right == 1) {
				PlayMove();
				if (stageFlag == 4) stageFlag = 0;
				else stageFlag++;
			}
			if (left == 1) {
				PlayMove();
				if (stageFlag == 0) stageFlag = 4;
				else stageFlag--;
			}
			if (B == 1) {
				flag = 2;
			}
			break;
		case 2://loading
			DrawFormatString(0, 0, WHITE, "loading");
			count = 0;
			sumdamage = 0;
			StageLoad(stageFlag);
			player.Set(stageFlag);
			EnemyMngSet(stageFlag);
			//SetKeyPosi();
			//EnemyMngSet();
			flag = 3;
			break;
		case 3://beforeDescription
			if (StageBeforeDescription(stageFlag, key)) {
				flag = 4;
				count = 0;
			}
			break;
		case 4://playing
			DrawFormatString(0, 0, WHITE, "playing");
			player.Update1(count,key);
			if (StageUpdata(stageFlag, count, 0,player.GetCenter())) {
				keepCount = count;
				flag = 6;
			}
			player.Update2(GetStageWalls_judge(),count);
			damage = EnemyMngUpdata(count, player.GetCenter());
			if (player.GetStateFlag() != 7 && damage) {//ダメージが返ってくる
				//count += damage * 30.0;
				sumdamage += damage;
				player.SetDamage(count);
				toUIDamage(damage, count);
			}
			if (EnemyMngDamage(player.GetAttackAreaMng(),count)) {
				player.Addtelepo();
			}

			if (player.GetStateFlag() != 7) {//被ダメ中でなければ
				//player.GetWeakAreaMng().isDamageSquareMng(GetEnemyMngAttackArea)
			}

			if (count + sumdamage*30 > GetStageLimit()) {
				flag = 5;
				keepCount = count;
			}
			if (PAUSE == 1) {
				flag = 9;
			}
			EffectMngUpdate(count);

			DrawStage(stageFlag);
			EnemyMngDraw();
			player.Draw();
			EffectMngDraw();
			DrawUI(GetStageLimit() - sumdamage*30 - count);
			DrawFormatString(DISP_WIDTH - 100, 100, RED, "%2d", sumdamage);
			break;
		case 5://gameover
			DrawFormatString(100, 100, WHITE, "gameover");
			DrawGameOverBord(count - keepCount);
			if (count - keepCount > 180) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 6://result
			DrawFormatString(100, 100, WHITE, "gameclear");
			DrawClearBord(count - keepCount);
			if (B == 1) {
				flag = 1;
				PlayTitleBGM();
			}
			break;
		case 7://マニュアル
			DrawFormatString(0, 0, WHITE, "manual1");
			if (B == 1)
				PlayChoice();
			if (DrawManual(B)) {
				flag = 0;
				count = 0;
			}
			break;
		case 8://クレジット
			DrawFormatString(0, 0, WHITE, "credit");
			DrawCredit();
			if (B == 1) {
				PlayChoice();
				flag = 0;
			}
			break;
		case 9://ポーズ
			DrawFormatString(0, 0, WHITE, "pause");
			DrawPause();
			//player.UIDraw(count);
			count--;
			if (B == 1) flag = 4;
			if (A == 1) {
				flag = 1;
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
		//fps.Draw();
		ScreenFlip();
		fps.Wait();
	}

	//UpdataFile("kanuma2017.txt", 0, 0);
	DxLib_End();

	return 0;
}