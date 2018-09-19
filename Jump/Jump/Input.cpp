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
void InputUpdata(XINPUT_STATE input, int Key[]) {

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
	}

	//-----------------------------------------------------------------
	else {
		if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = 55;
		else if (CheckHitKey(KEY_INPUT_RIGHT)) THUMB_X = 100;
		else if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = -55;
		else if (CheckHitKey(KEY_INPUT_LEFT)) THUMB_X = -100;
		else THUMB_X = 0;
		if (CheckHitKey(KEY_INPUT_UP) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_Y = -55;
		else if (CheckHitKey(KEY_INPUT_UP)) THUMB_Y = -100;
		else if (CheckHitKey(KEY_INPUT_DOWN) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_Y = 55;
		else if (CheckHitKey(KEY_INPUT_DOWN)) THUMB_Y = 100;
		else THUMB_Y = 0;
		if (CheckHitKey(KEY_INPUT_D)) B++; else B = 0;
		if (CheckHitKey(KEY_INPUT_S)) A++; else A = 0;
		if (CheckHitKey(KEY_INPUT_W)) Y++; else Y = 0;
		if (CheckHitKey(KEY_INPUT_A)) X++; else X = 0;
		if (CheckHitKey(KEY_INPUT_LSHIFT)) LEFT++; else LEFT = 0;

		if (CheckHitKey(KEY_INPUT_P)) PAUSE++; else PAUSE = 0;

		if (fabs(THUMB_X) == 100 && fabs(THUMB_Y) == 100) {
			THUMB_X /= 1.41421356;
			THUMB_Y /= 1.41421356;
		}
	}

}

void InputUpdata(int Key[]) {

		 if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = 55; 
	else if (CheckHitKey(KEY_INPUT_RIGHT)) THUMB_X = 100;
	else if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = -55;
	else if (CheckHitKey(KEY_INPUT_LEFT)) THUMB_X = -100;
	else THUMB_X = 0;
		 if (CheckHitKey(KEY_INPUT_UP)) THUMB_Y = -100;	//�Ȃ���80������
	else if (CheckHitKey(KEY_INPUT_DOWN)) THUMB_Y = 100;	//�Ȃ���80������
	else THUMB_Y = 0;
	if (CheckHitKey(KEY_INPUT_D)) B++; else B = 0;
	if (CheckHitKey(KEY_INPUT_S)) A++; else A = 0;
	if (CheckHitKey(KEY_INPUT_W)) Y++; else Y = 0;
	if (CheckHitKey(KEY_INPUT_A)) X++; else X = 0;

	if (CheckHitKey(KEY_INPUT_P)) PAUSE++; else PAUSE = 0;
	
}

void PrintInput(int Key[]) {

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
	DrawFormatString(0, 400, RED, "1:%d", Key[10]);
	DrawFormatString(0, 440, RED, "2:%d", Key[11]);
	DrawFormatString(0, 480, RED, "3:%d", Key[12]);
	DrawFormatString(0, 520, RED, "4:%d", Key[13]);
	DrawFormatString(0, 560, RED, "5:%d", Key[14]);
	DrawFormatString(0, 600, RED, "6:%d", Key[15]);
	DrawFormatString(0, 640, RED, "7:%d", Key[16]);
	DrawFormatString(0, 680, RED, "8:%d", Key[17]);
	DrawFormatString(0, 720, RED, "9:%d", Key[18]);
	DrawFormatString(0, 760, RED, "10:%d", Key[19]);

}