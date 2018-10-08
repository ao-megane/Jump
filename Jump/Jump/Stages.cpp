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

int Doorimage;

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
	Factory_back = LoadGraph("images/maps/factory/background.png");
	Factory_wall_1 = LoadGraph("images/maps/factory/wall/120_60.png");
	Factory_wall_2 = LoadGraph("images/maps/factory/wall/600_60.png");
	Doorimage = LoadGraph("images/maps/base/door.png");
	return 0;
}

int StageLoad(int stagenum) {
	Door.Delete();
	Walls_view.Delete();
	Walls_judge.Delete();

	switch (stagenum)
	{
	case 0:	//stage1
		BackGround = Tutorial_back[0];
		Walls_judge.Add(STAGE1_judge, STAGE1_judge_NUM);
		Walls_view.SetWalls(STAGE1_view,STAGE1_view_NUM,stagenum,Tutorial_wall_1,Tutorial_wall_2,Tutorial_wall_3, Tutorial_wall_4);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 1:
		BackGround = Tutorial_back[1];
		Walls_judge.Add(STAGE2_judge, STAGE2_judge_NUM);
		Walls_view.SetWalls(STAGE2_view, STAGE2_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4);
		//dynamicWall.Born();
		Limit = STAGE2_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 2:
		BackGround = Tutorial_back[2];
		Walls_judge.Add(STAGE3_judge, STAGE3_judge_NUM);
		Walls_view.SetWalls(STAGE3_view, STAGE3_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4);
		//dynamicWall.Born();
		Limit = STAGE3_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 3:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE1_judge, STAGE1_judge_NUM);
		Walls_view.SetWalls(STAGE1_view, STAGE1_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
		break;
	case 4:
		BackGround = Factory_back;
		Walls_judge.Add(STAGE1_judge, STAGE1_judge_NUM);
		Walls_view.SetWalls(STAGE1_view, STAGE1_view_NUM, stagenum, Tutorial_wall_1, Tutorial_wall_2, Tutorial_wall_3, Tutorial_wall_4);
		//dynamicWall.Born();
		Limit = STAGE1_COUNT;
		Door.Set(DISP_WIDTH - 120, DISP_HEIGHT - 180, DISP_WIDTH - 60, DISP_HEIGHT - 60);
		Door.Setimage(Doorimage);
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