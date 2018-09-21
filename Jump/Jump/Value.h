#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"
//#include"Color.h"

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

const int Trig = 200; //R2L2�̃J�E���g���n�߂邵�����l
const int ThumbTrig = 16383; //thumb�̖�������͈� �`32767

const int DISP_WIDTH = 1920;	//��ʂ̑傫��(HD)
const int DISP_HEIGHT = 1080;

const int GROUND_HEIGHT = DISP_HEIGHT - 50;

const int GRAVITY = 30;

const int SQU_NUM = 10;

/*-----------------------------*/
const double P_RATIO = 1.0;
//const double P_WEEK_HEIGHT = 1200 * P_RATIO;
//const double P_WEEK_WIDTH = 800 * P_RATIO;
//const double P_DRAW_HEIGHT = 2480 * P_RATIO;
//const double P_DRAW_WIDTH = 2480 * P_RATIO;
const double P_DRAW_HEIGHT = 400.0 * P_RATIO;
const double P_DRAW_WIDTH = 400.0 * P_RATIO;
const double P_HEIGHT = 64.0;
const double P_WIDTH = 64.0;
//const int P_REBORN_X = 145;
//const int P_REBORN_Y = 1450;
const double P_SPEED = 30;
const int P_DASH_CLOCK = 40;//P_CLOCK/2 �t���[���Ɉ�񑫉�

const double P_JUMP_NUM = 30.0*3.0;//�W�����v�̑��t���[��
const double P_JUMP_HEIGHT = 64.0*3.0;//�W�����v�̍���

/*------�V�X�e��--------*/
const int COUNT = 30*60*6;//30*60*3//3m

#endif // !VALUE_H
