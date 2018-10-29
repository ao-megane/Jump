#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"

int DrawnStand[3];
int DrawnTurn[2];//中身ないかも

int haveSTankStand[4];
int haveSTankTurn[2];
int haveSTankBroken[4];

int noSTankStand[4];
int noSTankTurn[2];
int noSTankBroken[4];

int JunkStand1;

int BriStand1;

int Enemy::Initialize() {
	isExist = false;
	isRight = false;
	bodyClock = 0;
	image.SquareMng::Initialize();
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
	HP = 0;
	stateFlag = 0;
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
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
	search.Add(serchLUx, serchLUy, serchRDx, serchRDy);
	HP = hp;
	stateFlag = 0;
	return 0;
}
int Enemy::Set(int x, int y) {
	isExist = true;
	center.Set(x, y);
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
	stateFlag = 0;
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
	stateFlag = 0;
	return 0;
}
int Drawn::Updata(int count, Dot Pcenter,SquareMng walls) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->Delete();
	Enemy::GetimageMngAd()->Delete();

	/*---imageに大きさを渡す---*/
	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0, 0);

	/*-------状態セット系-------*/
	if (Enemy::stateFlag == 3 || stateFlag == 4) {//被ダメ中(他を受け付けない)
		//printfDx("ダメージ！\n");
	}else if ((search & Pcenter)) {//見つかって
		if ((center.Getx() - Pcenter.Getx()) < 0) {//右にいる
			if (isRight) {//右向いてれば
				if (stateFlag != 0) {//立ち状態でなければ
					SetStand(count);
				}
			}
			else {//左向いてれば
				if (stateFlag != 1) {//振り向き中でなければ
					SetTurn(count);
				}
			}
		}
		if ((center.Getx() - Pcenter.Getx()) > 0) {//左にいる
			if (!isRight) {//左向いてれば
				if (stateFlag != 0) {//立ち状態でなければ
					SetStand(count);
				}
			}
			else {//右向いてれば
				if (stateFlag != 1) {//振り向き中でなければ
					SetTurn(count);
				}
			}
		}
	}else {//みつからない
		if (stateFlag != 0) {//立ち状態でなければ
			SetStand(count);
		}
		//printfDx("mitukaranai");
	}

	/*------状態アップデート系-----------*/
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock,Pcenter);
		break;
	case 1:
		UpdataTurn(count - bodyClock);
		break;
	case 2:
		//なし
		break;
	case 3:
		UpdataDamage(count - bodyClock);
		break;
	default:
		printfDx("DRAWN_STATE_ERROR");
		break;
	}
	/*--------状態アップデート終わったら移動系-----------*/
	
	velocity.Move(acceleration.Getx(),acceleration.Gety());
	if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);

	JudgeWall(walls, DRAWN_SPEED);//center更新
	Enemy::GetweakMngAd()->SquareMng::Delete();

	if (stateFlag != 4) {//壊れたら攻撃判定をなくす
		Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_A_HEIGHT / 2.0,
			Enemy::GetcenterAd()->Getx() + DRAWN_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_A_HEIGHT / 2.0, 10);
	}
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0);
	
	
	return *Enemy::GetattackMngAd() & Pcenter;
}
int Drawn::SetStand(int count) {
	bodyClock = count;
	stateFlag = 0;
	return 0;
}
int Drawn::UpdataStand(int count, Dot Pcenter) {
	image.Setimage(0, DrawnStand[0]);
	for (int i = 0; i < 3; i++) {
		//printfDx("%d", i);
		if (count < i) {
			image.Setimage(0, DrawnStand[i]);
		}
	}
	if (count >= 3) {
		bodyClock += 3;
	}

	if (search & Pcenter) {//見つかれば
		velocity.Set(DRAWN_SPEED * cos(CalcDir(center, Pcenter)), DRAWN_SPEED * -sin(CalcDir(center, Pcenter)));//移動
	}
	else {
		velocity.Set(0, 0);
		//printfDx("見つからない");
	}

	return 0;
}
int Drawn::SetTurn(int count) {
	bodyClock = count;
	stateFlag = 1;
	return 0;
}
int Drawn::UpdataTurn(int count) {
	image.Setimage(0, 0);
	for (int i = 0; i < 2; i++) {
		if (count < 5*(i+1)) {
			image.Setimage(0, DrawnTurn[i]);
		}
	}
	if (count > 10) {
		isRight = !isRight;
		stateFlag = 0;
	}

	return 0;
}
int Drawn::SetDamage(int damage, int count) {
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	HP -= damage;
	if (HP <= 0) {
		Enemy::isExist = false;
		ExprosionMngBorn(count, center);
		DebriMngBorn(count, center);
		DebriMngBorn(count, center);
		RedDebriMngBorn(count, center);
		RedDebriMngBorn(count, center);
		Drawn_disappearMngBorn(count, center);
		return 0;
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
		image.Setimage(0, DrawnStand[1]);
	}

	if (count > 30) stateFlag = 0;
	return 0;
}

int Tank::Set(int x, int y, bool haveS, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int HP) {
	Enemy::Set(x, y, serchLUx, serchLUy, serchRDx, serchRDy,HP);
	haveShield = haveS;
	return 0;
}
int Tank::SetTurn(int count) {
	Enemy::bodyClock = count;
	Enemy::stateFlag = 1;
	return 0;
}
int Tank::UpdataTurn(int count) {
	image.Setimage(0, 0);
	for (int i = 0; i < 2; i++) {
		if (count < 15 * (i + 1)) {
			if(haveShield)
				image.Setimage(0, haveSTankTurn[i]);
			else
				image.Setimage(0, noSTankTurn[i]);
		}
	}
	if (count > 30) {
		isRight =! isRight;
		stateFlag = 0;
	}
	return 0;
}
int Tank::Updata(int count, Dot Pcenter,SquareMng walls) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->Delete();
	Enemy::GetimageMngAd()->Delete();

	/*---imageに大きさを渡す---*/
	Enemy::GetimageMngAd()->Add(Enemy::GetcenterAd()->Getx() - DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - DRAWN_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + DRAWN_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + DRAWN_W_HEIGHT / 2.0, 0);

	/*-------状態セット系-------*/
	if (Enemy::stateFlag == 3 || stateFlag == 4) {//被ダメ中(他を受け付けない)
		//printfDx("ダメージ！\n");
	}
	else if ((search & Pcenter)) {//見つかって
		if ((center.Getx() - Pcenter.Getx()) < 0) {//右にいる
			if (isRight) {//右向いてれば
				if (stateFlag != 0) {//立ち状態でなければ
					SetStand(count);
				}
			}
			else {//左向いてれば
				if (stateFlag != 1) {//振り向き中でなければ
					SetTurn(count);
				}
			}
		}
		if ((center.Getx() - Pcenter.Getx()) > 0) {//左にいる
			if (!isRight) {//左向いてれば
				if (stateFlag != 0) {//立ち状態でなければ
					SetStand(count);
				}
			}
			else {//右向いてれば
				if (stateFlag != 1) {//振り向き中でなければ
					SetTurn(count);
				}
			}
		}
	}
	else {//みつからない
		if (stateFlag != 0) {//立ち状態でなければ
			SetStand(count);
		}
		//printfDx("mitukaranai");
	}

	/*------状態アップデート系-----------*/
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock, Pcenter);
		break;
	case 1:
		UpdataTurn(count - bodyClock);
		break;
	case 2:
		//なし
		break;
	case 3:
		UpdataDamage(count - Enemy::bodyClock);
		break;
	default:
		printfDx("DRAWN_STATE_ERROR");
		break;
	}
	/*--------状態アップデート終わったら移動系-----------*/

	velocity.Move(acceleration.Getx(), acceleration.Gety());
	if (velocity.Gety() > TANK_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0);

	JudgeWall(walls, TANK_SPEED);//center更新
	Enemy::GetweakMngAd()->SquareMng::Delete();

	if (stateFlag != 4) {
		Enemy::GetattackMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_A_HEIGHT / 2.0,
			Enemy::GetcenterAd()->Getx() + TANK_A_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_A_HEIGHT / 2.0, 10);
	}
	Enemy::GetweakMngAd()->Add(Enemy::GetcenterAd()->Getx() - TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() - TANK_W_HEIGHT / 2.0,
		Enemy::GetcenterAd()->Getx() + TANK_W_WIDTH / 2.0, Enemy::GetcenterAd()->Gety() + TANK_W_HEIGHT / 2.0);


	return *Enemy::GetattackMngAd() & Pcenter;
}
int Tank::SetStand(int count) {
	bodyClock = count;
	stateFlag = 0;
	return 0;
}
int Tank::UpdataStand(int count, Dot Pcenter) {
	if(haveShield)
		image.Setimage(0, haveSTankStand[0]);
	else
		image.Setimage(0, noSTankStand[0]);
	for (int i = 0; i < 4; i++) {
		//printfDx("%d", i);
		if (count < i) {
			if(haveShield)
				image.Setimage(0, haveSTankStand[i]);
			else
				image.Setimage(0, noSTankStand[i]);
		}
	}
	if (count >= 4) {
		bodyClock += 4;
	}

	if (search & Pcenter) {//見つかれば
		if((Pcenter.Getx() - center.Getx()) <= 0)
			velocity.Set(-TANK_SPEED,0);//移動
		else
			velocity.Set(TANK_SPEED, 0);//移動
	}
	else {
		velocity.Set(0, 0);
		//printfDx("見つからない");
	}

	return 0;
}
int Tank::SetDamage(int damage, int count,Dot Pcenter) {
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	if (haveShield) {
		if (Pcenter.Getx() - center.Getx() <= 0) {
			if (!isRight) return 0;
		}
		else {
			if (isRight) return 0;
		}
	}
	HP -= damage;
	if (HP <= 0) {
		Enemy::isExist = false;
		//SetExposion(count);
		Tank_disappearMngBorn(count, center);
		return 0;
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
			image.Setimage(0, haveSTankStand[1]);
		}
		else {
			image.Setimage(0, noSTankStand[1]);
		}
	}

	if (count > 30) stateFlag = 0;
	return 0;
}

int Junk::Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy, int HP) {
	Enemy::Set(x, y, serchLUx, serchLUy, serchRDx, serchRDy, HP);
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

int BrittleWall::Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy, int HP) {
	Enemy::Set(x, y, serchLUx, serchLUy, serchRDx, serchRDy, HP);
	return 0;
}
int BrittleWall::Updata(int count, Dot Pcenter) {
	Enemy::GetattackMngAd()->Delete();
	Enemy::GetweakMngAd()->Delete();
	Enemy::GetimageMngAd()->Delete();

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

Drawn drawn[DRAWN_NUM];
Junk junk[JUNK_NUM];
Tank tank[TANK_NUM];
BrittleWall briWall[BRI_WALL_NUM];
int EnemyMngInitialize() {
	for (int i = 0; i < 3; i++) {
		std::string a = "images/enemies/drawn/stand/";
		a += std::to_string(i + 1);
		a += ".png";
		DrawnStand[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 2; i++) {
		std::string a = "images/enemies/drawn/turn/";
		a += std::to_string(i + 1);
		a += ".png";
		DrawnTurn[i] = LoadGraph(a.c_str());
	}

	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/tank/shield/stand/";
		a += std::to_string(i + 1);
		a += ".png";
		haveSTankStand[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 2; i++) {
		std::string a = "images/enemies/tank/shield/turn/";
		a += std::to_string(i + 1);
		a += ".png";
		haveSTankTurn[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/tank/shield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		haveSTankBroken[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/tank/noshield/stand/";
		a += std::to_string(i + 1);
		a += ".png";
		noSTankStand[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 2; i++) {
		std::string a = "images/enemies/tank/noshield/turn/";
		a += std::to_string(i + 1);
		a += ".png";
		noSTankTurn[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/tank/noshield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		noSTankBroken[i] = LoadGraph(a.c_str());
	}

	JunkStand1 = LoadGraph("images/enemies/junk/1.png");
	BriStand1 = LoadGraph("images/enemies/briwall/1.png");
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
		tank[0].Set(1350, 690, false, 480, 540, 1440, 780, 90);
		break;
	case 2:
		drawn[0].Set(1470, 330, 60, 0, 1860, 660, 90);
		briWall[0].Set(1710, 930, 0, 0, 0, 0, 10);
		break;
	case 3:
		junk[0].Set(270, 990, 0, 0, 0, 0, 10);
		junk[1].Set(570, 990, 0, 0, 0, 0, 10);
		junk[0].Set(690, 990, 0, 0, 0, 0, 10);
		junk[0].Set(930, 270, 0, 0, 0, 0, 10);

		break;
	case 4:
		tank[0].Set(1350, 270, true, 600, 0, 1440, 360, 90);
		tank[1].Set(690, 630, false, 600, 420, 1440, 720, 90);
		tank[2].Set(1530, 930, true, 600, 780, 1620, 1020, 90);
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
			damage += junk[i].Updata(count, Pcenter);
		}
	}
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].Enemy::GetisExist()) {
			damage += briWall[i].Updata(count, Pcenter);
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
	//DrawGraph(100, 100, DrawnStand[0], true);
	//DrawBox(180, 300, 840, 420, BLUE, 0);
	for (int i = 0; i < DRAWN_NUM; i++) {
		if (drawn[i].Enemy::GetisExist()) {
			drawn[i].Draw();
			//printfDx("bbbbbb");
		}
	}
	for (int i = 0; i < JUNK_NUM; i++) {
		if (junk[i].Enemy::GetisExist()) {
			junk[i].Draw();
		}
	}
	for (int i = 0; i < BRI_WALL_NUM; i++) {
		if (briWall[i].Enemy::GetisExist()) {
			//printfDx("aaaaaaaaaaaaaa");
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