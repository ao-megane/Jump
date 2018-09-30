#include"EnemyMng.h"
#include"Value.h"

//intSquareMng AttackArea;

int DrawnStand1;

int Enemy::Initialize() {
	isExist = false;
	isRight = false;
	imageMng.SquareMng::Initialize();
	attackMng.SquareMng::Initialize();
	weakMng.Initialize();
	//searchArea.Initialize();
	return 0;
}
bool Enemy::GetisExist() {
	return isExist;
}
intSquareMng* Enemy::GetattackMngAd() {
	return &attackMng;
}
Dot* Enemy::GetcenterAd() {
	return &center;
}
imageSquareMng* Enemy::GetimageMngAd() {
	return &imageMng;
}
SquareMng* Enemy::GetweakMngAd() {
	return &weakMng;
}

int Enemy::Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy) {
	isExist = true;
	center.Set(x, y);
	return 0;
}
int Enemy::Set(int x, int y) {
	isExist = true;
	center.Set(x, y);
	return 0;
}

int Drawn::Updata(int count, Dot Pcener) {
	//center“®‚¢‚½‚è‚·‚é
	Enemy::GetattackMngAd()->SquareMng::Delete();
	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetimageMngAd()->SquareMng::Delete();
	
	//center.Move();

	Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_A_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_A_HEIGHT / 2.0, 10);

	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0,DrawnStand1);
	
	
	return *Enemy::GetattackMngAd() & Pcener;
}

int Drawn::Draw() {
	Enemy::GetimageMngAd()->Draw();
	Enemy::GetweakMngAd()->testDraw(BLUE);
	Enemy::GetattackMngAd()->testDraw(RED);

	return 0;
}

Drawn drawn[DRAWN_NUM];
int EnemyMngInitialize() {
	DrawnStand1 = LoadGraph("images/enemies/drawn/stand/1.png");
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
	int damage = 0;
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			damage += drawn[i].Updata(count, Pcenter);
		}
	}

	return damage;
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