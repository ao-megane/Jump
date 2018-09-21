#include"Stages.h"
#include"DxLib.h"
#include"Obj.h"

int BackGround;
int Wall;
SquareMng staticWall;
SquareMng dynamicWall;

int Tutorial_back;
int Tutorial_wall;

//int _back;
//int _wall;


int StagesInitialize() {
	staticWall.Initialize();
	dynamicWall.Initialize();
	Tutorial_back = LoadGraph("images/maps/.png");

	return 0;
}

int StageLoad(int stagenum) {
	switch (stagenum)
	{
	case 0:	//stage1
		BackGround = Tutorial_back;
		Wall = Tutorial_wall;
		staticWall.Born(STAGE1,STAGE1_NUM);
		//dynamicWall.Born();
		break;
	case 1:
		break;
	default:
		break;
	}
	return 0;
}

int StageUpdata(int stagenum, int count, int flag) {//大体のステージでいらないかも
	switch (stagenum)
	{
	case 0:
		break;
	default:
		break;
	}
	return 0;
}

int DrawStage(int count) {//count渡す必要ないかも
	staticWall.testDraw(GREEN);
	dynamicWall.testDraw(ORANGE);
	return 0;
}