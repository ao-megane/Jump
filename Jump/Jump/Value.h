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
const int PURPLE = GetColor(122, 0, 122);

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

const int ICON_WIDTH = 240;
const int ICON_HEIGHT = 240;

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
const int TLP_MAX = 300;
const double P_SPEED = 15;
const int P_DASH_CLOCK = 40;//P_CLOCK/2 フレームに一回足音

const double P_JUMP_NUM = 30.0*3.0;//ジャンプの総フレーム
const int P_TLP_RANGE = 270 + 60;
const double P_JUMP_POWER = GRAVITY * 14.0;//ジャンプの高さ

/*-----------------------*/
const int DRAWN_NUM = 10;
const double DRAWN_SPEED = P_SPEED - 10;
const int DRAWN_W_WIDTH = 180;
const int DRAWN_W_HEIGHT = 180;
const int DRAWN_A_WIDTH = 120;
const int DRAWN_A_HEIGHT = 120;
/*-----------------------*/
const int TANK_NUM = 10;
const double TANK_SPEED = P_SPEED - 12;
const int TANK_W_WIDTH = 180;
const int TANK_W_HEIGHT = 180;
const int TANK_A_WIDTH = 120;
const int TANK_A_HEIGHT = 120;
/*------------------------*/
const int JUNK_NUM = 10;
const int JUNK_W_WIDTH = 60;
const int JUNK_W_HEIGHT = 60;
const int JUNK_A_WIDTH = 0;
const int JUNK_A_HEIGHT = 0;
/*------------------------*/
const int BRI_WALL_NUM = 5;
const int BRI_WALL_W_WIDTH = 60;
const int BRI_WALL_W_HEIGHT = 180;
const int BRI_WALL_A_WIDTH = 0;
const int BRI_WALL_A_HEIGHT = 0;
/*------------------------*/
const int DAMAGE_WALL_NUM = 10;
const int DAMAGE_WALL_W_WIDTH = 300;
const int DAMAGE_WALL_W_HEIGHT = 60;
const int DAMAGE_WALL_A_WIDTH = 400;
const int DAMAGE_WALL_A_HEIGHT = 160;

/*------システム--------*/
const int STAGE_NUM = 12;
const double P_START_POINT[STAGE_NUM * 2] = {
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 100,
	150,GROUND_HEIGHT - 160,
};
const double DOOR_CENTER[STAGE_NUM * 2] = {
	1830,960,
	1830,960,
	1830,960,
	1830,960,
	1830,960,//5
	90,180,
	1830,960,
	1830,960,
	1830,960,
	1830,960,
	1830,960,
	1830,420,
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
const int SQUARE5_WIDTH = 480;//8:1
const int SQUARE5_HEIGHT = 60;
const int SQUARE6_WIDTH = 60;//1:5
const int SQUARE6_HEIGHT = 300;
/*------stage1(チュートリアル1)-----*/
const int STAGE1_view_NUM = 15;
static int STAGE1_view[STAGE1_view_NUM * 3] = {//左上,四角の種類
	300,360,1,
	480,180,1,
	480,540,1,
	660,720,1,
	780,360,1,
	900,660,1,
	960,180,1,
	1080,840,1,
	1380,300,1,
	1500,300,1,
	1560,300,1,
	1500,300,2,
	1500,500,2,
	1680,600,1,
	1800,600,1
};
const int STAGE1_judge_NUM = 14+1;
static double STAGE1_judge[STAGE1_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	300,360,120,60,
	480,180,120,60,
	480,540,120,60,
	660,720,120,60,
	780,360,120,60,
	900,660,120,60,
	960,180,120,60,
	1080,840,120,60,
	1380,300,300,60,
	1500,301,60,13 * 60,
	1680,600,180,60
};
const int STAGE1_COUNT = 30 * 120;//30fps

/*------stage2(チュートリアル1)-----*/
const int STAGE2_view_NUM = 22;
static int STAGE2_view[STAGE2_view_NUM * 3] = {//左上,四角の種類
	120,120,1,
	180,180,1,
	240,240,1,
	300,300,1,
	360,360,1,
	420,420,1,
	480,480,4,
	840,480,4,
	300,960,1,
	360,900,1,
	420,840,1,
	480,780,4,
	840,780,4,
	1380,840,1,
	1440,900,1,
	1500,960,1,
	1360,420,1,
	1420,360,1,
	1480,300,1,
	1560,240,1,
	1620,180,1,
	1680,120,1,
};
const int STAGE2_judge_NUM = 23+1;
static double STAGE2_judge[STAGE2_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	120,120,120,60,
	180,180,120,60,
	240,240,120,60,
	300,300,120,60,
	360,360,120,60,
	420,420,120,60,
	480,480,16*60,60,
	300,960,120,60,
	360,900,120,60,
	420,840,120,60,
	480,780,16*60,60,
	1380,840,120,60,
	1440,900,120,60,
	1500,960,120,60,
	1360,420,120,60,
	1420,360,120,60,
	1480,300,120,60,
	1560,240,120,60,
	1620,180,120,60,
	1680,120,120,60,
};
const int STAGE2_COUNT = 30 * 120;//30fps

/*------stage3(チュートリアル3)-----*/
const int STAGE3_view_NUM = 19;
static int STAGE3_view[STAGE3_view_NUM * 3] = {//左上,四角の種類
	300,960,1,
	360,900,1,
	420,840,1,
	480,780,1,
	540,720,1,
	300,360,1,
	390,540,1,
	600,300,1,
	600,660,4,
	1140,720,1,
	1200,780,1,
	1260,840,1,
	1320,900,1,
	1380,960,1,
	1140,600,1,
	1200,540,1,
	1260,480,1,
	1320,420,1,
	1740,840,1
};
const int STAGE3_judge_NUM = 22+1;
static double STAGE3_judge[STAGE3_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	300,960,120,60,
	360,900,120,60,
	420,840,120,60,
	480,780,120,60,
	540,720,120,60,
	300,360,120,60,
	390,540,120,60,
	600,300,120,60,
	600,660,600,60,
	1140,720,120,60,
	1200,780,120,60,
	1260,840,120,60,
	1320,900,120,60,
	1380,960,120,60,
	1140,600,120,60,
	1200,540,120,60,
	1260,480,120,60,
	1320,420,120,60,
	1740,840,120,60
};
const int STAGE3_COUNT = 30 * 120;//30fps

/*------stage4(チュートリアル1)-----*/
const int STAGE4_view_NUM = 6;
static int STAGE4_view[STAGE4_view_NUM * 3] = {//左上,四角の種類
	300,780,2,
	600,420,2,
	660,420,1,
	1140,180,4,
	1600,240,2,
	1600,600,2,
};
const int STAGE4_judge_NUM = 8 + 1;
static double STAGE4_judge[STAGE4_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	300,780,60,300,
	600,420,60,10*60,
	600,419,180,60,
	1140,180,10*60-1,60,
	1600,240,55,60*15
};
const int STAGE4_COUNT = 30 * 120;//30fps

/*------stage5(チュートリアル1)-----*/
const int STAGE5_view_NUM = 11;
static int STAGE5_view[STAGE5_view_NUM * 3] = {//左上,四角の種類
	300,420,2,
	360,0,1,
	420,60,1,
	360,420,1,
	420,360,3,
	840,360,4,
	480,660,1,
	540,720,3,
	1020,720,4,
	1620,0,2,
	1620,300,2
};
const int STAGE5_judge_NUM = 12 + 1;
static double STAGE5_judge[STAGE5_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	300,421,60,60*10,
	360,0,120,60,
	420,60,120,60,
	300,420,180,60,
	420,360,17*60,60,
	480,660,120,60,
	540,720,18*60,60,
	1620,0,60,15*60
};
const int STAGE5_COUNT = 30 * 90;//30fps

/*------stage6-----*/
const int STAGE6_view_NUM = 11;
static int STAGE6_view[STAGE6_view_NUM * 3] = {//左上,四角の種類
	60,240,5,
	540,240,6,
	540,540,1,
	660,540,1,
	240,960,1,
	300,900,1,
	360,840,1,
	900,660,1,
	1260,660,1,
	1620,660,1,
	1740,840,1
};
const int STAGE6_judge_NUM = 13 + 1;
static double STAGE6_judge[STAGE6_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	60,240,9*60-1,60,
	540,240+10,60,6*60-10,
	540+10,540,4*60-10,60,
	240,960,120,60,
	300,900,120,60,
	360,840,120,60,
	900,660,120,60,
	1260,660,120,60,
	1620,660,120,60,
	1740,840,120,60
};
const int STAGE6_COUNT = 30 * 90;//30fps

/*------stage7-----*/
const int STAGE7_view_NUM = 6;
static int STAGE7_view[STAGE7_view_NUM * 3] = {//左上,四角の種類
	720,900-30,1,
	1140,540,1,
	960,360,1,
	1080,180,1,
	1560,420,6,
	1560,720,6
};
const int STAGE7_judge_NUM = 8 + 1;
static double STAGE7_judge[STAGE7_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	720,900-30,120,60,
	1140,540,120,60,
	960,360,120,60,
	1080,180,120,60,
	1560,420,60,10*60
};
const int STAGE7_COUNT = 30 * 90;//30fps

/*------stage8-----*/
const int STAGE8_view_NUM = 11;
static int STAGE8_view[STAGE8_view_NUM * 3] = {//左上,四角の種類
	240,960,1,
	1380-60,960,1,
	660,0,6,
	660,300,6,
	660,540,6,
	1680,0,6,
	1680,300,6,
	1680,540,6,
	1140,0,6,
	1140,300,6,
	1140,540,6,
};
const int STAGE8_judge_NUM = 8 + 1;
static double STAGE8_judge[STAGE8_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	240,960,120,60,
	1380-60,960,120,60,
	660,0,60,14*60,
	1680,0,60,14*60,
	1140,0,60,14*60
};
const int STAGE8_COUNT = 30 * 90;//30fps

/*------stage9------*/
const int STAGE9_view_NUM = 1;
static int STAGE9_view[STAGE9_view_NUM * 3] = {//左上,四角の種類
	0,0,-1
};
const int STAGE9_judge_NUM = 3 + 1;
static double STAGE9_judge[STAGE9_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
};
const int STAGE9_COUNT = 30 * 60;//30fps

 /*------stage10----*/
const int STAGE10_view_NUM = 8;
static int STAGE10_view[STAGE10_view_NUM * 3] = {//左上,四角の種類
	420,900,1,
	540,0,6,
	540,300,6,
	540,780,6,
	1260,300,1,
	1560,180,6,
	1560,450,6,
	1560,660,6
};
const int STAGE10_judge_NUM = 8 + 1;
static double STAGE10_judge[STAGE10_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	420,900,120,60,
	540,0,60,10 * 60,
	540,780,60,4 * 60,
	1260,300,120,60,
	1560,180,60,13 * 60
};
const int STAGE10_COUNT = 30 * 60;//30fps
/*------stage11-----*/
const int STAGE11_view_NUM = 1;
static int STAGE11_view[STAGE11_view_NUM * 3] = {//左上,四角の種類
	0,0,-1
};
const int STAGE11_judge_NUM = 3 + 1;
static double STAGE11_judge[STAGE11_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
};
const int STAGE11_COUNT = 30 * 60;//30fps

/*------stage12-----*/
const int STAGE12_view_NUM = 4;
static int STAGE12_view[STAGE12_view_NUM * 3] = {//左上,四角の種類
	840,360,6,
	840,600,6,
	840,720,6,
	60,960,1
};
const int STAGE12_judge_NUM = 5 + 1;
static double STAGE12_judge[STAGE12_judge_NUM * 4]{//壁，画像は別で用意か(床抜け防止),左上，W,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	0,-60,DISP_WIDTH,60,
	840,360,60,11*60,
	60,960,120,60
};
const int STAGE12_COUNT = 30 * 60;//30fps


#endif // !VALUE_H
