#include"Stages.h"
#include"DxLib.h"
#include"Value.h"
#include"Obj.h"

int BackGround;
int Limit;

SquareMng Walls_judge;
imageSquareMng Walls_view;
imageSquare Door;

int Tutorial_back[3];
int Tutorial_wall_1;
int Tutorial_wall_2;
int Tutorial_wall_3;
int Tutorial_wall_4;
int Factory_back;
int Factory_wall_1;
int Factory_wall_2;
int Factory_wall_3;
int Factory_wall_4;
int Factory_wall_5;
int Factory_wall_6;

int factory_door;
int base_door;

//int _back;
//int _wall;


int StagesInitialize() {
	Walls_view.Initialize();
	Walls_judge.Initialize();
	Tutorial_back[0] = LoadGraph("images/maps/base/background/1.png");
	Tutorial_back[1] = LoadGraph("images/maps/base/background/2.png");
	Tutorial_back[2] = LoadGraph("images/maps/base/background/3.png");
	Tutorial_wall_1 = LoadGraph("images/maps/base/wall/120_60.png");
	Tutorial_wall_2 = LoadGraph("images/maps/base/wall/60_600.png");
	Tutorial_wall_3 = LoadGraph("images/maps/base/wall/840_60.png");
	Tutorial_wall_4 = LoadGraph("images/maps/base/wall/600_60.png");
	Factory_back = LoadGraph("images/maps/factory/background/1.png");
	Factory_wall_1 = LoadGraph("images/maps/factory/wall/120_60.png");
	Factory_wall_2 = 0;
	Factory_wall_3 = 0;
	Factory_wall_4 = 0;
	Factory_wall_5 = LoadGraph("images/maps/factory/wall/480_60.png");
	Factory_wall_6 = LoadGraph("images/maps/factory/wall/60_300.png");
	base_door = LoadGraph("images/maps/base/door.png");
	factory_door = LoadGraph("images/maps/factory/door.png");
	return 0;
}

int StageLoad(int stagenum) {
	Door.Delete();
	Walls_view.Delete();
	Walls_judge.Delete();

	Door.Set(DOOR_CENTER[stagenum * 2] - 30, DOOR_CENTER[stagenum * 2 + 1] - 60, DOOR_CENTER[stagenum * 2] + 30, DOOR_CENTER[stagenum * 2 + 1] + 60);

	switch (stagenum)
	{
	case 0:	//stage1
		BackGround = Tutorial_back[0];
		Walls_judge.Add(STAGE1_judge, STAGE1_judge_NUM);
		Walls_view.SetWalls(STAGE1_view, STAGE1_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4, 0,0);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		
		Door.Setimage(base_door);
		break;
	case 1:
		BackGround = Tutorial_back[1];
		Walls_judge.Add(STAGE2_judge, STAGE2_judge_NUM);
		Walls_view.SetWalls(STAGE2_view, STAGE2_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4, 0,0);
		//dynamicWall.Born();
		Limit = STAGE2_COUNT;
		Door.Setimage(base_door);
		break;
	case 2:
		BackGround = Tutorial_back[2];
		Walls_judge.Add(STAGE3_judge, STAGE3_judge_NUM);
		Walls_view.SetWalls(STAGE3_view, STAGE3_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4, 0,0);
		//dynamicWall.Born();
		Limit = STAGE3_COUNT;
		Door.Setimage(base_door);
		break;
	case 3:
		BackGround = Tutorial_back[2];
		Walls_judge.Add(STAGE4_judge, STAGE4_judge_NUM);
		Walls_view.SetWalls(STAGE4_view, STAGE4_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4, 0,0);
		//dynamicWall.Born();
		//printfDx("aaaaaaaaaa");
		Limit = STAGE4_COUNT;
		Door.Setimage(base_door);
		break;
	case 4:
		BackGround = Tutorial_back[2];
		Walls_judge.Add(STAGE5_judge, STAGE5_judge_NUM);
		Walls_view.SetWalls(STAGE5_view, STAGE5_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4, 0,0);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(base_door);
		Limit = STAGE5_COUNT;
		break;
	case 5:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE6_judge, STAGE6_judge_NUM);
		Walls_view.SetWalls(STAGE6_view, STAGE6_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 6:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE7_judge, STAGE7_judge_NUM);
		Walls_view.SetWalls(STAGE7_view, STAGE7_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 7:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE8_judge, STAGE8_judge_NUM);
		Walls_view.SetWalls(STAGE8_view, STAGE8_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 8:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE9_judge, STAGE9_judge_NUM);
		Walls_view.SetWalls(STAGE9_view, STAGE9_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 9:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE10_judge, STAGE10_judge_NUM);
		Walls_view.SetWalls(STAGE10_view, STAGE10_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 10:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE11_judge, STAGE11_judge_NUM);
		Walls_view.SetWalls(STAGE11_view, STAGE11_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
		Limit = STAGE5_COUNT;
		break;
	case 11:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE12_judge, STAGE12_judge_NUM);
		Walls_view.SetWalls(STAGE12_view, STAGE12_view_NUM, stagenum, Factory_wall_1, Factory_wall_2, Factory_wall_3, Factory_wall_4, Factory_wall_5, Factory_wall_6);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Setimage(factory_door);
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

SquareMng GetStageWalls_judge() {
	return Walls_judge;
}
SquareMng GetStageWalls_view() {
	printfDx("いらないはず");
	return Walls_view.GetSquareMng();
}
int GetStageLimit() {
	return Limit;
}

int DrawStage(int count) {//count渡す必要ないかも
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, BackGround, true);
	//staticWalls.testDraw(GREEN);
	Walls_view.Draw();
	Walls_judge.testDraw(GREEN);
	Door.Draw();
	//DrawGraph(0, 0, Tutorial_wall_1, true);
	return 0;
}