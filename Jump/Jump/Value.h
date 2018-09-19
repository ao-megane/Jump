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

#define A (Key[0])
#define B (Key[1])
#define X (Key[2])
#define Y (Key[3])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trig������Z���n�߂�
#define L_TRIG (Key[7]) //Trig������Z���n�߂�
#define THUMB_Y (Key[8])//-100�`+100 100���ő�l
#define THUMB_X (Key[9]) //-100�`+100 100���ő�l
#define PAUSE (Key[10])

const int Trig = 200; //R2L2�̃J�E���g���n�߂邵�����l
const int ThumbTrig = 16383; //thumb�̖�������͈� �`32767

const int DISP_WIDTH = 1920;	//��ʂ̑傫��(HD)
const int DISP_HEIGHT = 1080;

const double P_RATIO = 0.1;
const double P_WEEK_HEIGHT = 1200 * P_RATIO;	//
const double P_WEEK_WIDTH = 800 * P_RATIO;	//
const double P_DRAW_HEIGHT = 2480 * P_RATIO;
const double P_DRAW_WIDTH = 2480 * P_RATIO;
//const int P_REBORN_X = 145;
//const int P_REBORN_Y = 1450;
const double P_SPEED = 30;
const int P_DASH_CLOCK = 40;//P_CLOCK/2 �t���[���Ɉ�񑫉�


/*------�V�X�e��--------*/
const int COUNT = 30*60*6;//30*60*3//3m

#endif // !VALUE_H
