#include"Stages.h"
#include"DxLib.h"
#include"Value.h"
#include"Obj.h"

int BackGround;
int Limit;

SquareMng staticWalls;
imageSquareMng Walls;
imageSquare Door;

int Tutorial_back;
int Tutorial_wall_1;
int Tutorial_wall_2;
//int Tutorial_wall_1;
int Factory_back;
int Factory_wall_1;
int Factory_wall_2;

int Doorimage;

//int _back;
//int _wall;


int StagesInitialize() {
	Walls.Initialize();
	Tutorial_back = LoadGraph("images/maps/base/background.png");
	Tutorial_wall_1 = LoadGraph("images/maps/base/wall/120_60.png");
	Tutorial_wall_2 = LoadGraph("images/maps/base/wall/600_60.png");
	Factory_back = LoadGraph("images/maps/factory/background.png");
	Factory_wall_1 = LoadGraph("images/maps/factory/wall/120_60.png");
	Factory_wall_2 = LoadGraph("images/maps/factory/wall/600_60.png");
	Doorimage = LoadGraph("images/maps/base/door.png");
	return 0;
}

int StageLoad(int stagenum) {
	Door.Delete();
	switch (stagenum)
	{
	case 0:	//stage1
		BackGround = Tutorial_back;
		staticWalls.Add(STATICWALLS, STATICWALLS_NUM);
		Walls.SetWalls(STAGE1,STAGE1_NUM,stagenum,Tutorial_wall_1,Tutorial_wall_2,0);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 1:
		BackGround = Tutorial_back;
		staticWalls.Add(STATICWALLS, STATICWALLS_NUM);
		Walls.SetWalls(STAGE2, STAGE2_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, 0);
		//dynamicWall.Born();
		Limit = STAGE2_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 2:
		BackGround = Tutorial_back;
		staticWalls.Add(STATICWALLS, STATICWALLS_NUM);
		Walls.SetWalls(STAGE3, STAGE3_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, 0);
		//dynamicWall.Born();
		Limit = STAGE3_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 3:
		BackGround = Factory_back;
		staticWalls.Add(STATICWALLS, STATICWALLS_NUM);
		Walls.SetWalls(STAGE4, STAGE4_NUM, stagenum, Factory_wall_1, Factory_wall_2, 0);
		//dynamicWall.Born();
		Limit = STAGE4_COUNT;
		break;
	case 4:
		BackGround = Factory_back;
		staticWalls.Add(STATICWALLS, STATICWALLS_NUM);
		Walls.SetWalls(STAGE5, STAGE5_NUM, stagenum, Factory_wall_1, Factory_wall_2, 0);
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

int StageUpdata(int stagenum, int count, int flag,Dot pcenter) {//大体のステージでいらないかも
	switch (stagenum)
	{
	case 0:
		break;
	default:
		break;
	}
	if (Door & pcenter) {
		return 1;
	}
	return 0;
}

SquareMng GetStageStaticWalls() {
	return staticWalls;
}
SquareMng GetStageWalls() {
	return Walls.GetSquareMng();
}
int GetStageLimit() {
	return Limit;
}

int DrawStage(int count) {//count渡す必要ないかも
	//DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, BackGround, true);
	staticWalls.testDraw(GREEN);
	Walls.Draw();
	Walls.testDraw(GREEN);
	Door.Draw();
	//DrawGraph(0, 0, Tutorial_wall_1, true);
	return 0;
}