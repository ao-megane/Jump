#include"EnemyMng.h"
#include"Value.h"

//intSquareMng AttackArea;

int DrawnStand1;

int JunkStand1;

int Enemy::Initialize() {
	isExist = false;
	isRight = false;
	imageMng.SquareMng::Initialize();
	attackMng.Initialize();
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
int Enemy::SetHP(int a) {
	HP = a;
	return 0;
}

int Drawn::Updata(int count, Dot Pcener) {
	//center動いたりする
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetimageMngAd()->SquareMng::Delete();
	
	//center.Move();
	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_A_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_A_HEIGHT / 2.0, 10);

	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0,DrawnStand1);
	
	return *Enemy::GetattackMngAd() & Pcener;
}

int Drawn::SetDamage(int damage, int count) {
	HP -= damage;
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	return 0;
}
int Drawn::UpdataDamage(int count) {
	if (count > 30) stateFlag = 0;
	return 0;
}


int Drawn::Draw() {
	Enemy::GetimageMngAd()->Draw();
	Enemy::GetweakMngAd()->testDraw(BLUE);
	Enemy::GetattackMngAd()->testDraw(RED);

	return 0;
}

int Junk::Updata(int count, Dot Pcenter) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetimageMngAd()->SquareMng::Delete();

	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - JUNK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - JUNK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + JUNK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + JUNK_W_HEIGHT / 2.0);

	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - JUNK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - JUNK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + JUNK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + JUNK_W_HEIGHT / 2.0, JunkStand1);

	return *Enemy::GetattackMngAd() & Pcenter;
}

int Junk::SetDamage(int damage, int count) {
	HP -= damage;
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	return 0;
}
int Junk::UpdataDamage(int count) {
	if (count > 30) stateFlag = 0;
	return 0;
}

int Junk::Draw() {
	Enemy::GetimageMngAd()->Draw();
	return 0;
}

Drawn drawn[DRAWN_NUM];
Junk junk[JUNK_NUM];
int EnemyMngInitialize() {
	DrawnStand1 = LoadGraph("images/enemies/drawn/stand/1.png");
	JunkStand1 = LoadGraph("images/enemies/junk/1.png");
	return 0;
}

int EnemyMngSet(int stageFlag) {
	for (int i = 0; i < DRAWN_NUM; i++) {
		drawn[i].Enemy::Initialize();
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		junk[i].Enemy::Initialize();
	}
	switch (stageFlag)
	{
	case 0://敵なし
		break;
	case 1://
		drawn[0].Set(180, 300, 0, 0, 0, 0);
		break;
	case 2://テレポチュートリアル
		junk[0].Set(90, 570, 0, 0, 0, 0);
		junk[1].Set(330, 990, 0, 0, 0, 0);
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
	for (int i = 0; i < JUNK_NUM; i++) {
		if (junk[i].Enemy::GetisExist()) {
			damage += junk[i].Updata(count, Pcenter);
		}
	}

	return damage;
}

int EnemyMngDamage(intSquareMng pattack,int count) {
	int edamage = 0;
	bool ishit = false;
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			edamage = pattack.isHitSquareMng(*drawn[i].Enemy::GetweakMngAd());
			if (edamage) {
				drawn[i].SetDamage(edamage,count);
				ishit = true;
			}
		}
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		if (junk[i].Enemy::GetisExist()) {
			edamage = pattack.isHitSquareMng(*junk[i].Enemy::GetweakMngAd());
			if (edamage) {
				junk[i].SetDamage(edamage, count);
				ishit = true;
			}
		}
	}
	return ishit;
}

int EnemyMngDraw() {
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			drawn[i].Draw();
		}
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		if (junk[i].Enemy::GetisExist()) {
			junk[i].Draw();
		}
	}
	return 0;
}