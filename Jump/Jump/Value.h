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
#define R_TRIG (key[6]) //Trig������Z���n�߂�
#define L_TRIG (key[7]) //Trig������Z���n�߂�
#define THUMB_Y (key[8])//-100�`+100 100���ő�l
#define THUMB_X (key[9]) //-100�`+100 100���ő�l
#define PAUSE (key[10])
#define R_THUMB_Y (key[11])//-100�`+100 100���ő�l
#define R_THUMB_X (key[12]) //-100�`+100 100���ő�l

const int Trig = 200; //R2L2�̃J�E���g���n�߂邵�����l
const int ThumbTrig = 16383; //thumb�̖�������͈� �`32767

const int DISP_WIDTH = 1920;	//��ʂ̑傫��(HD)
const int DISP_HEIGHT = 1080;

const int GROUND_HEIGHT = DISP_HEIGHT - 50;

const double GRAVITY = 0.1;

const int SQU_NUM = 20*2;

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
const int P_DASH_CLOCK = 40;//P_CLOCK/2 �t���[���Ɉ�񑫉�

const double P_JUMP_NUM = 30.0*3.0;//�W�����v�̑��t���[��
const int P_TLP_RANGE = 270 + 60;
const double P_JUMP_POWER = GRAVITY * 14.0;//�W�����v�̍���

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

/*------�V�X�e��--------*/
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
const int SQUARE5_WIDTH = 180;//�X�e�[�W1�p�̈����|����h�~
const int SQUARE5_HEIGHT = 60;
const int SQUARE6_WIDTH = 66;//�X�e�[�W3�p�̕ǔ����h�~
const int SQUARE6_HEIGHT = 1000;
/*------stage1(�`���[�g���A��1)-----*/
const int STAGE1_view_NUM = 13;
static int STAGE1_view[STAGE1_view_NUM * 3] = {//����,�l�p�̎��
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
static double STAGE1_judge[STAGE1_judge_NUM * 4]{//�ǁC�摜�͕ʂŗp�ӂ�(�������h�~),����CW,H
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

/*------stage2(�`���[�g���A��1)-----*/
const int STAGE2_view_NUM = 4;
static int STAGE2_view[STAGE2_view_NUM * 3] = {//����,�l�p�̎��
	540,840,1,
	780,660,1,
	1020,540,1,
	60,420,4
};
const int STAGE2_judge_NUM = 7;
static double STAGE2_judge[STAGE2_judge_NUM * 4]{//�ǁC�摜�͕ʂŗp�ӂ�(�������h�~),����CW,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	540,840,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	780,660,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	1020,540,SQUARE1_WIDTH,SQUARE1_HEIGHT,
	60,420,SQUARE4_WIDTH,SQUARE4_HEIGHT
};
const int STAGE2_COUNT = 30 * 60;//30fps

/*------stage3(�`���[�g���A��3)-----*/
const int STAGE3_view_NUM = 6;
static int STAGE3_view[STAGE3_view_NUM * 3] = {//����,�l�p�̎��
	360,240,2,
	360,660,2,
	420,480,3,
	600+60*4,780,3,
	1660,0,2,
	1660,300,2
};
const int STAGE3_judge_NUM = 7;
static double STAGE3_judge[STAGE3_judge_NUM * 4]{//�ǁC�摜�͕ʂŗp�ӂ�(�������h�~),����CW,H
	0,0,60,DISP_HEIGHT,
	0,DISP_HEIGHT - 60,DISP_WIDTH,70,
	DISP_WIDTH - 60,0,60,DISP_HEIGHT,
	360,240,60,60*13,
	420,480,SQUARE3_WIDTH,SQUARE3_HEIGHT,
	600 + 60 * 4,780,SQUARE3_WIDTH,SQUARE3_HEIGHT,
	1660,-500,60,500+15*60
};
const int STAGE3_COUNT = 30 * 60;//30fps

/*------stage4(�`���[�g���A��1)-----*/
const int STAGE4_NUM = 15;
//static double STAGE4[STAGE4_NUM * 4] = {
//	0, GROUND_HEIGHT, DISP_WIDTH, DISP_HEIGHT * 2,
//	DISP_WIDTH / 2.0, GROUND_HEIGHT - 100, DISP_WIDTH, GROUND_HEIGHT - 10,
//	0,0,10,GROUND_HEIGHT,
//	0,0,DISP_WIDTH,10,
//	DISP_WIDTH - 10,0,DISP_WIDTH,GROUND_HEIGHT,
//	0,GROUND_HEIGHT - 600,DISP_WIDTH / 2.0,GROUND_HEIGHT - 510
//};
static int STAGE4[STAGE4_NUM * 3] = {//����,�l�p�̎��
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
	1500,420,2
};
const int STAGE4_COUNT = 30 * 60;//30fps

/*------stage5(�`���[�g���A��1)-----*/
const int STAGE5_NUM = 15;
//static double STAGE5[STAGE5_NUM * 4] = {
//	0, GROUND_HEIGHT, DISP_WIDTH, DISP_HEIGHT * 2,
//	DISP_WIDTH / 2.0, GROUND_HEIGHT - 100, DISP_WIDTH, GROUND_HEIGHT - 10,
//	0,0,10,GROUND_HEIGHT,
//	0,0,DISP_WIDTH,10,
//	DISP_WIDTH - 10,0,DISP_WIDTH,GROUND_HEIGHT,
//	0,GROUND_HEIGHT - 600,DISP_WIDTH / 2.0,GROUND_HEIGHT - 510
//};
static int STAGE5[STAGE5_NUM * 3] = {//����,�l�p�̎��
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
	1500,420,2
};
const int STAGE5_COUNT = 30 * 60;//30fps




#endif // !VALUE_H
