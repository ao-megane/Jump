#include"EnemyMng.h"
#include"Value.h"

intSquareMng AttackArea;

int Enemy::Initialize() {
	isExist = false;
	isRight = false;
	imageMng.SquareMng::Initialize();
	attackMng.SquareMng::Initialize();
	weakMng.Initialize();
	searchArea.Initialize();
	return 0;
}

bool Enemy::GetisExist() {
	return isExist;
}
intSquareMng* Enemy::GetAttackMngAd() {
	return &attackMng;
}
Dot* Enemy::GetcenterAd() {
	return &center;
}

int Drawn::Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy) {
	isExist = true;
	center.Set(x, y);
	return 0;
}
int Drawn::Updata(int count, Dot Pcener) {
	//center“®‚¢‚½‚è‚·‚é
	attackMng.SquareMng::Delete();
	weakMng.Delete();
	imageMng.SquareMng::Delete();
	
	//center.Move();

	attackMng.Add(center.Getx() - DRAWN_A_WIDTH / 2.0, center.Gety() - DRAWN_A_HEIGHT / 2.0, center.Getx() + DRAWN_A_WIDTH / 2.0, center.Gety() + DRAWN_A_HEIGHT / 2.0, 10);
	weakMng.Add(center.Getx() - DRAWN_W_WIDTH / 2.0, center.Gety() - DRAWN_W_HEIGHT / 2.0, center.Getx() + DRAWN_W_WIDTH / 2.0, center.Gety() + DRAWN_W_HEIGHT / 2.0);
	imageMng.SquareMng::Add(center.Getx() - DRAWN_W_WIDTH / 2.0-10, center.Gety() - DRAWN_W_HEIGHT / 2.0 - 10, center.Getx() + DRAWN_W_WIDTH / 2.0 - 10, center.Gety() + DRAWN_W_HEIGHT / 2.0 - 10);
	
	return 0;
}
int Drawn::Draw() {
	imageMng.Draw();
	attackMng.SquareMng::testDraw(RED);
	weakMng.testDraw(BLUE);
	return 0;
}

Drawn drawn[DRAWN_NUM];
int EnemyMngInitialize() {
	for (int i = 0; i < DRAWN_NUM; i++) {
		drawn[i].Enemy::Initialize();
	}
	return 0;
}

int EnemyMngSet(int stageFlag) {
	switch (stageFlag)
	{
	case 0://“G‚È‚µ
		break;
	case 1://
		drawn[0].Set(180, 300, 0, 0, 0, 0);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}

	return 0;
}

int EnemyMngUpdata(int count, Dot Pcenter) {
	AttackArea.SquareMng::Delete();
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			drawn[i].Updata(count, Pcenter);
			AttackArea.Add(drawn[i].GetAttackMng());
		}
	}
	return 0;
}

int EnemyMngDraw() {
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			drawn[i].Draw();
			//printfDx("DRAW!!\n");
		}
	}
	return 0;
}