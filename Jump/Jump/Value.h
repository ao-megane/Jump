#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"
#include"Color.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);
const int BROWN = GetColor(46, 33, 13);

#define A (Key[0])
#define B (Key[1])
#define X (Key[2])
#define Y (Key[3])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trigから加算を始める
#define L_TRIG (Key[7]) //Trigから加算を始める
#define THUMB_Y (Key[8])//-100～+100 100が最大値
#define THUMB_X (Key[9]) //-100～+100 100が最大値
#define PAUSE (Key[10])

const int Trig = 200; //R2L2のカウントを始めるしきい値
const int ThumbTrig = 16383; //thumbの無視する範囲 ～32767

const int DISP_WIDTH = 2160;	//画面の大きさ(Surfacepro3)
const int DISP_HEIGHT = 1440;

const int MAP_WIDTH = 5500;		//判定用画像の大きさ
const int MAP_HEIGHT = 3700;

const int MASK_WIDTH = 2600;

const double JUDGE_MARGIN = 1.0;	//プレイヤーと壁の追突について，埋め込まれないために

const int P_SIZE = 80;	//プレイヤーの半径
const int P_REBORN_X = 145;
const int P_REBORN_Y = 1450;
const double P_FULL_SPEED = 30;
const double P_HALF_SPEED = 15;
const double P_L_FULL_SPEED = 28;
const int P_CLOCK = 40;//P_CLOCK/2 フレームに一回足音
const int P_SOUND_LIFESPAN = 15;

/*--------主人--------*/
const int HUSBAND_RANGE = P_SIZE;
const int HUSBAND_FULL_SPEED = P_L_FULL_SPEED - 0.5;
const int HUSBAND_HALF_SPEED = P_HALF_SPEED - 3.0;
const int HUSBAND_SOUND_LIFESPAN = 25;

const int SERCH_WIDTH = 1100;
const int SERCH_HEIGHT = 150;

/*--------夫人--------*/
const int MADAM_RANGE = P_SIZE;
const int MADAM_FULL_SPEED = P_L_FULL_SPEED + 0.5;
const int MADAM_HALF_SPEED = P_HALF_SPEED - 3.0;
const int MADAM_SOUND_LIFESPAN = 5;

const int ONPOINT = P_FULL_SPEED * 1.4;	//敵の塁上判定
/*------１階の敵用静点-----*/
const double ENEPOSI_1[27 * 2] = {
	300.0,2200.0,//1
	300.0,3000.0,//2
	300.0,3500.0,//3
	1600.0,3500.0,//4
	1600.0,3000.0,//5
	1600.0,2205.0,//6
	1100.0,1300.0,//7
	1100.0,600.0,//8
	2100.0,650.0,//9
	2200.0,1300.0,//10
	2200.0,2250.0,//11
	2200.0,2650.0,//12
	3450.0,2650.0,//13
	3450.0,2050.0,//14
	3530.0,1300.0,//15
	2760.0,1300.0,//16
	2760.0,650.0,//17
	3530.0,650.0,//18
	4320.0,650.0,//19
	4320.0,1300.0,//20
	3900.0,2050.0,//21
	3900.0,1900.0,//22
	5100.0,1900.0,//23
	5100.0,2650.0,//24
	3900.0,2650.0,//25
	5100.0,3400.0,//26
	3900.0,3400.0//27
};
const double ENEPOSI_2[20 * 2] = {
	1100.0,2000.0,//1
	1100.0,440.0,//2
	1100.0,2550.0,//3
	330.0,2550.0,//4
	1560.0,2550.0,//5
	1873.0,2000.0,//6
	1873.0,1100.0,//7
	2750.0,2550.0,//8
	2750.0,2000.0,//9
	2750.0,1100.0,//10
	3600.0,1100.0,//11
	3600.0,2550.0,//12
	3600.0,3400.0,//13
	2800.0,3400.0,//14
	4800.0,3400.0,//15
	4350.0,2550.0,//16
	4350.0,1745.0,//17
	5100.0,1745.0,//18
	4350.0,430.0,//19
	330.0,3330.0,//20
};


/*--------長男--------*/
const int SON_RANGE = P_SIZE;
const double SON_FULL_SPEED = P_L_FULL_SPEED + 1.0;
const double SON_HALF_SPEED = P_HALF_SPEED - 3.0;
const int SON_SOUND_LIFESPAN = 20;

/*--------長女--------*/
const int DAUGHTER_RANGE = P_SIZE;
const int DAUGHTER_FULL_SPEED = P_L_FULL_SPEED + 0.5;
const int DAUGHTER_HALF_SPEED = P_HALF_SPEED - 3.0;
const int DAUGHTER_SOUND_LIFESPAN = 10;

/*------システム--------*/
const int COUNT = 30*60*6;//30*60*3//3m

/*---------鍵---------*/

const int KEYPOSI_1[9 * 2] = {
	109,1841,
	101,3593,
	1805,3593,
	1461,425,
	1669,417,
	3245,421,
	3937,429,
	3773,2833,
	3773,3585
};
const int KEYPOSI_2[7 * 2] = {
	1180,3600,
	2025,3590,
	5257,3597,
	1541,957,
	2473,921,
	3985,933,
	5377,1481
};
const int KEY_SIZE = 60;
/*-----------------------*/

const int BATSU_SIZE = 30;
const int KEY_WIDTH = 60 * 1;
const int KEY_HEIGHT = 80 * 1;
const int UI_HEIGHT = 400;
const int UI_WIDTH = 300;
const int UI_MARGIN_HEIGHT = 20;
const int UI_MARGIN_WIDTH = 20;
//const int UI_POSI[2 * 9] = {
//	1970,100,	//rEye
//	2000,100,	//lEye
//	1950,110,	//rEar
//	2020,110,	//lEar
//	1950,160,	//rArm
//	2020,160,	//lArm
//	1970,240,	//rLeg
//	2000,240,	//lLeg
//	1850,150,	//Key
//};
const int UI_KEYPOSI[2] = {
	1900,125,
};

const int SOUND_SPEED = 20;	//音の広がる速度　＝　寿命

//const int HPBAR_WIDTH = 900 * 0.75;
//const int HPBAR_HEIGHT = 150 * 0.75;
//const int HPBAR_MARGIN_HEIGHT = 130;
//const int HPBAR_MARGIN_WIDTH = 10 * 3;

//const int HPSQU_WIDTH = 610 * 0.75 + 10;
//const int HPSQU_HEIGHT = 50 * 0.75;
//const int HPSQU_MARGIN_WIDTH = 190 * 0.75;
//const int HPSQU_MARGIN_HEIGHT = 50 * 0.75 + 5;

#endif // !VALUE_H
