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
	image.SquareMng::Initialize();
	attackMng.Initialize();
	weakMng.Initialize();
	search.Initialize();
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
	return &image;
}
SquareMng* Enemy::GetweakMngAd() {
	return &weakMng;
}

int Enemy::Set(int x, int y, double serchLUx, double serchLUy, double serchRDx, double serchRDy,int hp) {
	isExist = true;
	center.Set(x, y);
	search.Add(serchLUx, serchLUy, serchRDx, serchRDy);
	HP = hp;
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
int Enemy::JudgeWall(SquareMng walls,double speed) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (walls.GetSquare(i).GetisExist()) {//四角ごとに判定
			switch (weakMng.GetSquare(0).isHitSquare(walls.GetSquare(i), velocity))//ここできちんとめり込みまで判定できれば問題ない
			{
			case 0://ぶつかってない
				break;
			case 2://U
				center.Sety(walls.GetUpLanding(weakMng.GetSquare(0), speed) + DRAWN_W_HEIGHT / 2.0);
				//printfDx("U");
				break;
			case 4://R
				center.Setx(walls.GetRightLanding(weakMng.GetSquare(0), speed) - DRAWN_W_HEIGHT / 2.0);
				//printfDx("R");
				break;
			case 6://D
				center.Sety(walls.GetLanding(weakMng.GetSquare(0), speed) - DRAWN_W_WIDTH / 2.0);
				//printfDx("D");
				break;
			case 8://L
				center.Setx(walls.GetLeftLanding(weakMng.GetSquare(0), speed) + DRAWN_W_WIDTH / 2.0);
				//printfDx("L");
				break;
			default:
				break;
			}
		}
	}
	return 0;
}
int Enemy::Draw() {
	search.testDraw(BLUE);
	image.Draw(isRight);
	attackMng.testDraw(RED);
	//printfDx("%f,%f\n", search.GetSquare(0).GetLU().Getx(), search.GetSquare(0).GetLU().Gety());
	return 0;
}

int Drawn::Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy, int HP) {
	Enemy::Set(x, y, serchLUx, serchLUy, serchRDx, serchRDy, HP);
	return 0;
}
int Drawn::Updata(int count, Dot Pcenter,SquareMng walls) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->Delete();
	Enemy::GetimageMngAd()->Delete();

	/*---とりあえずノーマルの画像を入れる---*/
	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0, DrawnStand1);

	/*-------状態セット系-------*/
	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	/*--------状態セット終わったら移動系-----------*/
	if ((search & Pcenter) && stateFlag != 3) {
		velocity.Set(DRAWN_SPEED * cos(CalcDir(center, Pcenter)), DRAWN_SPEED * -sin(CalcDir(center, Pcenter)));
		if (Pcenter.Getx() - center.Getx() <= 0) {
			isRight = false;
		}
		else {
			isRight = true;
		}
	}
	else {
		velocity.Set(0, 0);
	}
	Enemy::GetcenterAd()->Move(velocity.Getx(), velocity.Gety());
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	JudgeWall(walls, DRAWN_SPEED);//center更新

	Enemy::GetweakMngAd()->SquareMng::Delete();

	Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_A_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_A_HEIGHT / 2.0, 10);
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);
	
	
	return *Enemy::GetattackMngAd() & Pcenter;
}
int Drawn::SetDamage(int damage, int count) {
	if (stateFlag == 3) return 0;

	HP -= damage;
	if (HP <= 0) {
		Enemy::isExist = false;
		//SetExposion(count);
	}
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	return 0;
}
int Drawn::UpdataDamage(int count) {
	if (count % 4 < 2) {
		image.Setimage(0, 0);
	}
	else {
		image.Setimage(0, DrawnStand1);
	}

	if (count > 30) stateFlag = 0;
	return 0;
}

//int Drawn::Draw() {
//	Enemy::GetimageMngAd()->Draw();
//	Enemy::GetweakMngAd()->testDraw(BLUE);
//	Enemy::GetattackMngAd()->testDraw(RED);
//
//	return 0;
//}

int Tank::Set(int x, int y, bool haveS, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int HP) {
	Enemy::Set(x, y, serchLUx, serchLUy, serchRDx, serchRDy,HP);
	haveShield = haveS;
	return 0;
}
int Tank::Updata(int count, Dot Pcenter,SquareMng walls) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->Delete();
	Enemy::GetimageMngAd()->Delete();

	/*-----とりあえずノーマル-------*/
	if (haveShield) {
		Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
			Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0, haveSTankStand1);
	}
	else {
		Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
			Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0, noSTankStand1);
	}

	/*-------状態セット系-------*/
	if (Enemy::stateFlag == 3) {
		//printfDx("ダメージ！\n");
		UpdataDamage(count - Enemy::bodyClock);
	}

	/*--------状態セット終わったら移動系-----------*/
	if (search & Pcenter && stateFlag != 3) {
		if (Pcenter.Getx() - center.Getx() <= 0) {
			velocity.Set(-TANK_SPEED, TANK_SPEED);
			isRight = false;
		}
		else {
			velocity.Set(TANK_SPEED, TANK_SPEED);
			isRight = true;
		}
	}
	else {
		velocity.Set(0, TANK_SPEED);
	}

	Enemy::GetcenterAd()->Move(velocity.Getx(), velocity.Gety());
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0);

	JudgeWall(walls, TANK_SPEED);//center更新

	Enemy::GetweakMngAd()->SquareMng::Delete();

	Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_A_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + TANK_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_A_HEIGHT / 2.0, 10);
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0);

	return *Enemy::GetattackMngAd() & Pcenter;
}
int Tank::SetDamage(int damage, int count,Dot Pcenter) {
	if (stateFlag == 3) return 0;
	if (Pcenter.Getx() - center.Getx() <= 0) {
		if (!isRight) return 0;
	}
	else {
		if (isRight) return 0;
	}
	HP -= damage;
	if (HP <= 0) {
		Enemy::isExist = false;
		//SetExposion(count);
	}
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	return 0;
}
int Tank::UpdataDamage(int count) {
	if (count % 4 < 2) {
		image.Setimage(0, 0);
	}
	else {
		if (haveShield) {
			image.Setimage(0, haveSTankStand1);
		}
		else {
			image.Setimage(0, noSTankStand1);
		}
	}

	if (count > 30) stateFlag = 0;
	return 0;
}
//int Tank::Draw() {
//
//	Enemy::GetimageMngAd()->Draw(isRight);
//	Enemy::GetweakMngAd()->testDraw(BLUE);
//	Enemy::GetattackMngAd()->testDraw(RED);
//	search.testDraw(BLUE);
//
//	return 0;
//}

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
	//Enemy::HP -= damage;
	Enemy::bodyClock = count;
	Enemy::stateFlag = 3;
	
	return 0;
}
int Junk::UpdataDamage(int count) {
	if (count % 4 < 2) {
		image.Setimage(0, 0);
	}
	else {
		image.Setimage(0, JunkStand1);
	}

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
Tank tank[TANK_NUM];
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
	for (int i = 0; i < TANK_NUM; i++) {
		tank[i].Enemy::Initialize();
	}
	switch (stageFlag)
	{
	case 0://敵なし
		break;
	case 1://
		drawn[0].Set(180, 300, 180, 300, 840, 420,30);
		briWall[0].Set(1770, DISP_HEIGHT - 130, 0, 0, 0, 0,1);
		break;
	case 2://テレポチュートリアル
		junk[0].Set(90, 570, 0, 0, 0, 0,1);
		junk[1].Set(330, 990, 0, 0, 0, 0,1);
		tank[0].Set(1200, 360, true, 420, 300, 1200, 480,30);
		tank[1].Set(800, 660, false, 600, 600, 1600, 780,30);
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
	for (int i = 0; i < TANK_NUM; i++) {
		if (tank[i].Enemy::GetisExist()) {
			damage += tank[i].Updata(count, Pcenter, walls);;
		}
	}

	return damage;
}

int EnemyMngDamage(intSquareMng pattack,int count,Dot Pcenter) {
	int edamage = 0;
	bool ishit = false;
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			edamage = pattack.isHitSquareMng(*drawn[i].Enemy::GetweakMngAd());
			if (edamage) {
				drawn[i].SetDamage(edamage,count);
				//printfDx("DRAWN DAMAGE!!!!\n");
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
	for (int i = 0; i < TANK_NUM; i++) {
		if (tank[i].Enemy::GetisExist()) {
			edamage = pattack.isHitSquareMng(*tank[i].Enemy::GetweakMngAd());
			if (edamage) {
				tank[i].SetDamage(edamage, count,Pcenter);
				ishit = true;
			}
		}
	}
	return ishit;
}

int EnemyMngDraw() {
	//DrawBox(180, 300, 840, 420, BLUE, 0);
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
	for (int i = 0; i < TANK_NUM; i++) {
		if (tank[i].Enemy::GetisExist()) {
			tank[i].Draw();
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