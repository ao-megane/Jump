#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"

//intSquareMng AttackArea;

int DrawnStand1;

int haveSTankStand1;

int noSTankStand1;

int JunkStand1;

int BriStand1;

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
	//printfDx("%d,%d\n", center.Getx(), center.Gety());
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

int Drawn::Updata(int count, Dot Pcenter,SquareMng walls) {
	Dot velocity;
	velocity.Set(DRAWN_SPEED * cos(CalcDir(center, Pcenter)), DRAWN_SPEED * -sin(CalcDir(center, Pcenter)));
	//center動いたりする
	Enemy::GetcenterAd()->Move(velocity.Getx(), velocity.Gety());

	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	for (int i = 0; i < SQU_NUM; i++) {
		if (walls.GetSquare(i).GetisExist()) {//四角ごとに判定
			switch (Enemy::GetweakMngAd()->GetSquare(0).isHitSquare(walls.GetSquare(i), velocity))//ここできちんとめり込みまで判定できれば問題ない
			{
			case 0://ぶつかってない
				break;
			case 2://U
				Enemy::GetcenterAd()->Sety(walls.GetUpLanding(Enemy::GetweakMngAd()->GetSquare(0), DRAWN_SPEED) + DRAWN_W_HEIGHT / 2.0);
				break;
			case 4://R
				Enemy::GetcenterAd()->Setx(walls.GetRightLanding(Enemy::GetweakMngAd()->GetSquare(0), DRAWN_SPEED) - DRAWN_W_HEIGHT / 2.0);
				break;
			case 6://D
				Enemy::GetcenterAd()->Sety(walls.GetLanding(Enemy::GetweakMngAd()->GetSquare(0), DRAWN_SPEED) - DRAWN_W_WIDTH / 2.0);
				break;
			case 8://L
				Enemy::GetcenterAd()->Setx(walls.GetLeftLanding(Enemy::GetweakMngAd()->GetSquare(0), DRAWN_SPEED) + DRAWN_W_WIDTH / 2.0);
				break;
			default:
				break;
			}
		}
	}

	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetimageMngAd()->Delete();

	Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_A_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_A_HEIGHT / 2.0, 10);

	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0,DrawnStand1);
	
	return *Enemy::GetattackMngAd() & Pcenter;
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

int Tank::Set(int x, int y, bool haveS) {
	isExist = true;
	center.Set(x, y);
	haveShield = haveS;
	return 0;
}
int Tank::Updata(int count, Dot Pcenter) {
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
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0, DrawnStand1);

	return *Enemy::GetattackMngAd() & Pcenter;
}
int Tank::SetDamage(int damage, int count) {
	HP -= damage;
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	return 0;
}
int Tank::UpdataDamage(int count) {
	if (count > 30) stateFlag = 0;
	return 0;
}
int Tank::Draw() {
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

int BrittleWall::Updata(int count, Dot Pcenter) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->SquareMng::Delete();
	Enemy::GetimageMngAd()->SquareMng::Delete();

	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - BRI_WALL_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - BRI_WALL_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + BRI_WALL_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + BRI_WALL_W_HEIGHT / 2.0);

	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - BRI_WALL_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - BRI_WALL_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + BRI_WALL_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + BRI_WALL_W_HEIGHT / 2.0, BriStand1);

	return *Enemy::GetattackMngAd() & Pcenter;
}
int BrittleWall::SetDamage(int damage, int count) {
	if (damage >= 30) {
		Enemy::isExist = false;
	}

	//Enemy::bodyClock = count;
	//Enemy::stateFlag = 3;
	return 0;
}
int BrittleWall::UpdataDamage(int count) {
	if (count > 30) stateFlag = 0;
	return 0;
}
int BrittleWall::Draw() {
	Enemy::GetimageMngAd()->Draw();
	return 0;
}



Drawn drawn[DRAWN_NUM];
Junk junk[JUNK_NUM];
BrittleWall briWall[BRI_WALL_NUM];
int EnemyMngInitialize() {
	DrawnStand1 = LoadGraph("images/enemies/drawn/stand/1.png");
	haveSTankStand1 = LoadGraph("images/enemies/tank/shield/stand/1.png");
	noSTankStand1 = LoadGraph("images/enemies/tank/noshield/stand/1.png");
	JunkStand1 = LoadGraph("images/enemies/junk/1.png");
	BriStand1 = LoadGraph("images/enemies/wall/1.png");
	return 0;
}

int EnemyMngSet(int stageFlag) {
	for (int i = 0; i < DRAWN_NUM; i++) {
		drawn[i].Enemy::Initialize();
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		junk[i].Enemy::Initialize();
	}
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		briWall[i].Enemy::Initialize();
	}
	switch (stageFlag)
	{
	case 0://敵なし
		break;
	case 1://
		drawn[0].Set(180, 300, 0, 0, 0, 0);
		briWall[0].Set(1770, DISP_HEIGHT - 130, 0, 0, 0, 0);
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

int EnemyMngUpdata(int count, Dot Pcenter, SquareMng walls) {
	int damage = 0;
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			damage += drawn[i].Updata(count, Pcenter, walls);
		}
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		if (junk[i].Enemy::GetisExist()) {
			//damage += junk[i].Updata(count, Pcenter, walls);
		}
	}
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].Enemy::GetisExist()) {
			//damage += briWall[i].Updata(count, Pcenter, walls);;
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
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].Enemy::GetisExist()) {
			edamage = pattack.isHitSquareMng(*briWall[i].Enemy::GetweakMngAd());
			if (edamage) {
				briWall[i].SetDamage(edamage, count);
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
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].Enemy::GetisExist()) {
			briWall[i].Draw();
		}
	}
	return 0;
}

SquareMng GetBriWall() {
	SquareMng decoi;
	decoi.Initialize();
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].GetisExist())
			decoi = decoi + briWall[i].GetimageMngAd()->GetSquareMng();
	}
	return decoi;
}