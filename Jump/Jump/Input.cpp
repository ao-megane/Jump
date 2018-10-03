#include"DxLib.h"
#include"Value.h"
#include"Chore.h"
//#include"math.h"

//#pragma(push)
//#pragma warning ( disable : 4789 )
// unused code that generates compiler warning C4789
//#pragma(pop)

void InputInitialize(int key[]) {
	for (int i = 0; i < 20; i++)
		key[i] = 0;
}

double idir;
void InputUpdata(XINPUT_STATE input, int key[]) {

	if (GetJoypadXInputState(DX_INPUT_PAD1, &input) == 0) {
		if (input.Buttons[12]) A++; else A = 0;
		if (input.Buttons[13]) B++; else B = 0;
		if (input.Buttons[14]) X++; else X = 0;
		if (input.Buttons[15]) Y++; else Y = 0;
		if (input.Buttons[9]) RIGHT++; else RIGHT = 0;
		if (input.Buttons[8]) LEFT++; else LEFT = 0;
		if (input.Buttons[4]) PAUSE++; else PAUSE = 0;
		if (input.LeftTrigger > Trig) L_TRIG++; else L_TRIG = 0;
		if (input.RightTrigger > Trig) R_TRIG++; else R_TRIG = 0;

		if ((input.ThumbLY * input.ThumbLY + input.ThumbLX * input.ThumbLX) < ThumbTrig * ThumbTrig) {
			THUMB_Y = 0;
			THUMB_X = 0;
		}
		else {
			/*THUMB_Y = (-1) * input.ThumbLY / 32767.0 * 100;
			THUMB_X = input.ThumbLX / 32767.0 * 100;*/
			THUMB_Y = (1) * input.ThumbLY;
			THUMB_X = input.ThumbLX;
			idir = CalcDir(THUMB_X, THUMB_Y);
			THUMB_X = 100.0 * cos(idir);
			THUMB_Y = 100.0 * sin(idir);
		}

		if ((input.ThumbRY * input.ThumbRY + input.ThumbRX * input.ThumbRX) < ThumbTrig * ThumbTrig) {
			R_THUMB_Y = 0;
			R_THUMB_X = 0;
		}
		else {
			/*THUMB_Y = (-1) * input.ThumbLY / 32767.0 * 100;
			THUMB_X = input.ThumbLX / 32767.0 * 100;*/
			R_THUMB_Y = (1) * input.ThumbRY;
			R_THUMB_X = input.ThumbRX;
			idir = CalcDir(R_THUMB_X, R_THUMB_Y);
			R_THUMB_X = 100.0 * cos(idir);
			R_THUMB_Y = 100.0 * sin(idir);
		}
	}

	//-----------------------------------------------------------------
	else {
		if (CheckHitKey(KEY_INPUT_D) && CheckHitKey(KEY_INPUT_LSHIFT)) THUMB_X = 55;
		else if (CheckHitKey(KEY_INPUT_D)) THUMB_X = 100;
		else if (CheckHitKey(KEY_INPUT_A) && CheckHitKey(KEY_INPUT_LSHIFT)) THUMB_X = -55;
		else if (CheckHitKey(KEY_INPUT_A)) THUMB_X = -100;
		else THUMB_X = 0;
		if (CheckHitKey(KEY_INPUT_W) && CheckHitKey(KEY_INPUT_LSHIFT)) THUMB_Y = -55;
		else if (CheckHitKey(KEY_INPUT_W)) THUMB_Y = -100;
		else if (CheckHitKey(KEY_INPUT_S) && CheckHitKey(KEY_INPUT_LSHIFT)) THUMB_Y = 55;
		else if (CheckHitKey(KEY_INPUT_S)) THUMB_Y = 100;
		else THUMB_Y = 0;
		if (CheckHitKey(KEY_INPUT_RIGHT)) B++; else B = 0;
		if (CheckHitKey(KEY_INPUT_DOWN)) A++; else A = 0;
		if (CheckHitKey(KEY_INPUT_UP)) Y++; else Y = 0;
		if (CheckHitKey(KEY_INPUT_LEFT)) X++; else X = 0;
		//if (CheckHitKey(KEY_INPUT_LSHIFT)) LEFT++; else LEFT = 0;

		if (CheckHitKey(KEY_INPUT_P)) PAUSE++; else PAUSE = 0;

		if (fabs(THUMB_X) == 100 && fabs(THUMB_Y) == 100) {
			THUMB_X /= 1.41421356;
			THUMB_Y /= 1.41421356;
		}
	}

	/*for (int i = 0; i < 30; i++) {
		DrawFormatString(100, 100 + i * 20, RED, "%d:%d", i, input.Buttons[i]);
	}*/

}

void InputUpdata(int key[]) {

		 if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = 55; 
	else if (CheckHitKey(KEY_INPUT_RIGHT)) THUMB_X = 100;
	else if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = -55;
	else if (CheckHitKey(KEY_INPUT_LEFT)) THUMB_X = -100;
	else THUMB_X = 0;
		 if (CheckHitKey(KEY_INPUT_UP)) THUMB_Y = -100;	//‚È‚º‚©80‚¾‚Á‚½
	else if (CheckHitKey(KEY_INPUT_DOWN)) THUMB_Y = 100;	//‚È‚º‚©80‚¾‚Á‚½
	else THUMB_Y = 0;
	if (CheckHitKey(KEY_INPUT_D)) B++; else B = 0;
	if (CheckHitKey(KEY_INPUT_S)) A++; else A = 0;
	if (CheckHitKey(KEY_INPUT_W)) Y++; else Y = 0;
	if (CheckHitKey(KEY_INPUT_A)) X++; else X = 0;

	if (CheckHitKey(KEY_INPUT_P)) PAUSE++; else PAUSE = 0;
	
}

void PrintInput(int key[]) {

	DrawFormatString(0, 0, RED, "A:%d", A);
	DrawFormatString(0, 40, RED, "B:%d", B);
	DrawFormatString(0, 80, RED, "X:%d", X);
	DrawFormatString(0, 120, RED, "Y:%d", Y);
	DrawFormatString(0, 160, RED, "R1:%d", RIGHT);
	DrawFormatString(0, 200, RED, "L1:%d", LEFT);
	DrawFormatString(0, 240, RED, "R_TRIG:%d", R_TRIG);
	DrawFormatString(0, 280, RED, "L_TRIG:%d", L_TRIG);
	DrawFormatString(0, 320, RED, "RATIO_X:%d", THUMB_X);
	DrawFormatString(0, 360, RED, "RATIO_Y:%d", THUMB_Y);
	DrawFormatString(0, 400, RED, "R_RATIO_X:%d", R_THUMB_X);
	DrawFormatString(0, 440, RED, "R_RATIO_Y:%d", R_THUMB_Y);
	/*DrawFormatString(0, 400, RED, "1:%d", key[10]);
	DrawFormatString(0, 440, RED, "2:%d", key[11]);*/
	DrawFormatString(0, 480, RED, "3:%d", key[12]);
	DrawFormatString(0, 520, RED, "4:%d", key[13]);
	DrawFormatString(0, 560, RED, "5:%d", key[14]);
	DrawFormatString(0, 600, RED, "6:%d", key[15]);
	DrawFormatString(0, 640, RED, "7:%d", key[16]);
	DrawFormatString(0, 680, RED, "8:%d", key[17]);
	DrawFormatString(0, 720, RED, "9:%d", key[18]);
	DrawFormatString(0, 760, RED, "10:%d", key[19]);

}