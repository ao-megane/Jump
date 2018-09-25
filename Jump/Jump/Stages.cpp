#include"Stages.h"
#include"DxLib.h"
#include"Obj.h"

int BackGround;
int Limit;
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
		staticWall.Born(STAGE1,STAGE1_NUM);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		break;
	case 1:
		BackGround = Tutorial_back;
		staticWall.Born(STAGE2, STAGE2_NUM);
		//dynamicWall.Born();
		Limit = STAGE2_COUNT;
		break;
	case 2:
		BackGround = Tutorial_back;
		staticWall.Born(STAGE3, STAGE3_NUM);
		//dynamicWall.Born();
		Limit = STAGE3_COUNT;
		break;
	case 3:
		BackGround = Tutorial_back;
		staticWall.Born(STAGE4, STAGE4_NUM);
		//dynamicWall.Born();
		Limit = STAGE4_COUNT;
		break;
	case 4:
		BackGround = Tutorial_back;
		staticWall.Born(STAGE5, STAGE5_NUM);
		//dynamicWall.Born();
		Limit = STAGE5_COUNT;
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

SquareMng GetStageStaticSquareMng() {
	return staticWall;
}
int GetStageLimit() {
	return Limit;
}

int DrawStage(int count) {//count渡す必要ないかも
	staticWall.testDraw(GREEN);
	dynamicWall.testDraw(ORANGE);
	return 0;
}