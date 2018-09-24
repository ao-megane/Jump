#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);
const int BROWN = GetColor(46, 33, 13);

#define A (key[0])
#define B (key[1])
#define X (key[2])
#define Y (key[3])
#define RIGHT (key[4])
#define LEFT (key[5])
#define R_TRIG (key[6]) //Trigから加算を始める
#define L_TRIG (key[7]) //Trigから加算を始める
#define THUMB_Y (key[8])//-100〜+100 100が最大値
#define THUMB_X (key[9]) //-100〜+100 100が最大値
#define PAUSE (key[10])

const int Trig = 200; //R2L2のカウントを始めるしきい値
const int ThumbTrig = 16383; //thumbの無視する範囲 〜32767

const int DISP_WIDTH = 1920;	//画面の大きさ(HD)
const int DISP_HEIGHT = 1080;

const int GROUND_HEIGHT = DISP_HEIGHT - 50;

const double GRAVITY = 0.1;

const int SQU_NUM = 10;

/*-----------------------------*/
const double P_RATIO = 1.0;
const double P_WEAK_LU_X = 32;
const double P_WEAK_LU_Y = 32;
const double P_WEAK_RD_X = 32;
const double P_WEAK_RD_Y = 32;
//const double P_DRAW_HEIGHT = 2480 * P_RATIO;
//const double P_DRAW_WIDTH = 2480 * P_RATIO;
const double P_DRAW_HEIGHT = 400.0 * P_RATIO;
const double P_DRAW_WIDTH = 400.0 * P_RATIO;
const double P_HEIGHT = 64.0;
const double P_WIDTH = 64.0;
//const int P_REBORN_X = 145;
//const int P_REBORN_Y = 1450;
const double P_SPEED = 15;
const int P_DASH_CLOCK = 40;//P_CLOCK/2 フレームに一回足音

const double P_JUMP_NUM = 30.0*3.0;//ジャンプの総フレーム
const double P_JUMP_POWER = GRAVITY * 15.0;//ジャンプの高さ

/*------システム--------*/
const int COUNT = 30*60*6;//30*60*3//3m
const int STAGE_NUM = 10;
const double P_START_POINT[STAGE_NUM * 2] = {
	100,GROUND_HEIGHT - 100,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0
};

/*------stage1(チュートリアル1)-----*/
const int STAGE1_NUM = 6;
static double STAGE1[STAGE1_NUM * 4] = {
	0, GROUND_HEIGHT, DISP_WIDTH, DISP_HEIGHT * 2,
	DISP_WIDTH / 2.0, GROUND_HEIGHT - 100, DISP_WIDTH, GROUND_HEIGHT - 10,
	0,0,10,GROUND_HEIGHT,
	0,0,DISP_WIDTH,10,
	DISP_WIDTH - 10,0,DISP_WIDTH,GROUND_HEIGHT,
	0,GROUND_HEIGHT - 600,DISP_WIDTH / 2.0,GROUND_HEIGHT - 510
};

#endif // !VALUE_H
