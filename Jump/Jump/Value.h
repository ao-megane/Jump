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
#define THUMB_Y (key[8])//-100～+100 100が最大値
#define THUMB_X (key[9]) //-100～+100 100が最大値
#define PAUSE (key[10])
#define R_THUMB_Y (key[11])//-100～+100 100が最大値
#define R_THUMB_X (key[12]) //-100～+100 100が最大値

const int Trig = 200; //R2L2のカウントを始めるしきい値
const int ThumbTrig = 16383; //thumbの無視する範囲 ～32767

const int DISP_WIDTH = 1920;	//画面の大きさ(HD)
const int DISP_HEIGHT = 1080;

const int GROUND_HEIGHT = DISP_HEIGHT - 50;

const double GRAVITY = 0.1;

const int SQU_NUM = 20*2;

const double TELEPO_DRAW_HEIGHT = 96.0;
const double TELEPO_DRAW_WIDTH = 96.0;
/*-----------------------------*/
const double P_RATIO = 1.0;
const double P_WEAK_LU_X = 32;
const double P_WEAK_LU_Y = 32;
const double P_WEAK_RD_X = 32;
const double P_WEAK_RD_Y = 32;
//const double P_DRAW_HEIGHT = 2480 * P_RATIO;
//const double P_DRAW_WIDTH = 2480 * P_RATIO;
const double P_DRAW_HEIGHT = 384.0 * P_RATIO;
const double P_DRAW_WIDTH = 384.0* P_RATIO;
const double P_HEIGHT = 64.0;
const double P_WIDTH = 64.0;
//const int P_REBORN_X = 145;
//const int P_REBORN_Y = 1450;
const int TLP_MAX = 290;
const double P_SPEED = 15;
const int P_DASH_CLOCK = 40;//P_CLOCK/2 フレームに一回足音

const double P_JUMP_NUM = 30.0*3.0;//ジャンプの総フレーム
const int P_TLP_RANGE = 270 + 60;
const double P_JUMP_POWER = GRAVITY * 14.0;//ジャンプの高さ

/*-----------------------*/
const int DRAWN_NUM = 10;
const int DRAWN_W_WIDTH = 180;
const int DRAWN_W_HEIGHT = 180;
const int DRAWN_A_WIDTH = 120;
const int DRAWN_A_HEIGHT = 120;
/*------------------------*/
const int JUNK_NUM = 10;
const int JUNK_W_WIDTH = 60;
const int JUNK_W_HEIGHT = 60;
const int JUNK_A_WIDTH = 0;
const int JUNK_A_HEIGHT = 0;

/*------システム--------*/
const int STAGE_NUM = 10;
const double P_START_POINT[STAGE_NUM * 2] = {
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100,
	100,GROUND_HEIGHT - 100
};

//1:2
const int SQUARE1_WIDTH = 120;//1:2
const int SQUARE1_HEIGHT = 60;
const int SQUARE2_WIDTH = 60;//1:10
const int SQUARE2_HEIGHT = 600;
const int SQUARE3_WIDTH = 840;//14:1
const int SQUARE3_HEIGHT = 60;
const int SQUARE4_WIDTH = 600;//10:1
const int SQUARE4_HEIGHT = 60;
const int SQUARE5_WIDTH = 180;//ステージ1用の引っ掛かり防止
const int SQUARE5_HEIGHT = 60;
const int SQUARE6_WIDTH = 66;//ステージ3用の壁抜け防止
const int SQUARE6_HEIGHT = 1000;
/*------stage1(チュートリアル1)-----*/
const int STAGE1_view_NUM = 13;
static int STAGE1_view[STAGE1_view_NUM * 3] = {//左上,四角の種類
	300,600,1,
	420,420,1,
	480,720,1,
	600,300,1,
	720,600,1,
	780,180,1,
	900,720,1,
	960,60,1,
	1080,840,1,
	1560,420,1,
	1740,720,1,
	1500,420,2,
};
const int STAGE1_judge_NUM = 17;
static double STAGE1_judge[STAGE1_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	300,600,120,60,
	420,420,120,60,
	480,720,120,60,
	600,300,120,60,
	720,600,120,60,
	780,180,120,60,
	900,720,120,60,
	960,60,120,60,
	1080,840,120,60,
	1560,420,120,60,
	1740,720,120,60,
	1500,419,180,60,
	1500,419,60,600,
};
const int STAGE1_COUNT = 30 * 60;//30fps

/*------stage2(チュートリアル1)-----*/
const int STAGE2_view_NUM = 4;
static int STAGE2_view[STAGE2_view_NUM * 3] = {//左上,四角の種類
	540,840,1,
	780,660,1,
	1020,540,1,
	60,420,4
};
const int STAGE2_judge_NUM = 7;
static double STAGE2_judge[STAGE2_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	540,840,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	780,660,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	1020,540,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	60,420,SQUARE4_WIDTH,SQUARE4_HEIGHT
};
const int STAGE2_COUNT = 30 * 60;//30fps

/*------stage3(チュートリアル3)-----*/
const int STAGE3_view_NUM = 6;
static int STAGE3_view[STAGE3_view_NUM * 3] = {//左上,四角の種類
	360,240,2,
	360,660,2,
	420,480,3,
	600+60*4,780,3,
	1660,0,2,
	1660,300,2
};
const int STAGE3_judge_NUM = 7;
static double STAGE3_judge[STAGE3_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	360,240,60,60*13,
	420,480,SQUARE3_WIDTH,SQUARE3_HEIGHT,
	600 + 60 * 4,780,SQUARE3_WIDTH,SQUARE3_HEIGHT,
	1660,-500,60,500+15*60
};
const int STAGE3_COUNT = 30 * 60;//30fps

/*------stage4(チュートリアル1)-----*/
const int STAGE4_view_NUM = 3;
static int STAGE4_view[STAGE4_view_NUM * 3] = {//左上,四角の種類
	420,480,3,
	1300,240,1,
	1360,660,1
};
const int STAGE4_judge_NUM = 6;
static double STAGE4_judge[STAGE4_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	420,480,SQUARE3_WIDTH,SQUARE3_HEIGHT,
	1300,240,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	1360,660,SQUARE1_WIDTH,SQUARE1_HEIGHT,
};
const int STAGE4_COUNT = 30 * 60;//30fps

/*------stage5(チュートリアル1)-----*/
const int STAGE5_view_NUM = 4;
static int STAGE5_view[STAGE5_view_NUM * 3] = {//左上,四角の種類
	240,300,1,
	13*60,0,2,
	13*60,120,2,
	DISP_WIDTH - 240,600,2
};
const int STAGE5_judge_NUM = 7;
static double STAGE5_judge[STAGE5_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,240,70,
	DISP_WIDTH-180,DISP_HEIGHT - 60,180,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	240,300,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	13 * 60,-10000,60,10000+12*60,
	DISP_WIDTH - 240,600,SQUARE2_WIDTH,SQUARE2_HEIGHT
};
const int STAGE5_COUNT = 30 * 60;//30fps




#endif // !VALUE_H
