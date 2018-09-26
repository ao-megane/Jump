#include"Stages.h"
#include"DxLib.h"
#include"Value.h"
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
	Tutorial_back = LoadGraph("images/maps/base/background.png");

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

bool StageBeforeDescription(int stage, int key[]) {
	switch (stage)
	{
	case 0:
		DrawFormatString(300, 300, RED, "STAGE1_BEFORE_DESCRIPTION!");
		break;
	case 1:
		DrawFormatString(300, 300, RED, "STAGE2_BEFORE_DESCRIPTION!");
		break;
	case 2:
		DrawFormatString(300, 300, RED, "STAGE3_BEFORE_DESCRIPTION!");
		break;
	case 3:
		DrawFormatString(300, 300, RED, "STAGE4_BEFORE_DESCRIPTION!");
		break;
	case 4:
		DrawFormatString(300, 300, RED, "STAGE5_BEFORE_DESCRIPTION!");
		break;
	default:
		break;
	}
	if (B == 1)
		return true;
	else
		return false;
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
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, BackGround, true);
	staticWall.testDraw(GREEN);
	dynamicWall.testDraw(ORANGE);
	return 0;
}