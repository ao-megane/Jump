#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"
#include"Effect.h"
#include<math.h>

int PDash[16];
int PDashStart[8];
int PisAir[3];
int PJumpE[4];
int PStand[3];
int PAttacks[46];
int PAttackw[8];
int PAttackair[8];

int PTlp_targ1[4];
int PTlp_targ2[4];
int PTlp_targ3[4];

int Attackw;
int Attacks;
int Attackair;
int Telepo;
int PJump;


int Player::Initialize() {
	for (int i = 0; i < 3; i++) {
		std::string a = "images/player/stand/";
		a += std::to_string(i+1);
		a += ".png";
		PStand[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 16; i++) {
		std::string a = "images/player/dash/";
		a += std::to_string(i+1);
		a += ".png";
		PDash[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/player/dash_start/";
		a += std::to_string(i+1);
		a += ".png";
		PDashStart[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/jump/";
		a += std::to_string(i+1);
		a += ".png";
		PJumpE[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 3; i++) {
		std::string a = "images/player/air_free/";
		a += std::to_string(i+1);
		a += ".png";
		PisAir[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 46; i++) {
		std::string a = "images/player/attack_s/";
		a += std::to_string(i+1);
		a += ".png";
		PAttacks[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/player/attack_w/";
		a += std::to_string(i+1);
		a += ".png";
		PAttackw[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/player/attack_air/";
		a += std::to_string(i + 1);
		a += ".png";
		PAttackair[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/telepo_targ/left1/";
		a += std::to_string(i + 1);
		a += ".png";
		PTlp_targ1[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/telepo_targ/left2/";
		a += std::to_string(i + 1);
		a += ".png";
		PTlp_targ2[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/telepo_targ/left3/";
		a += std::to_string(i + 1);
		a += ".png";
		PTlp_targ3[i] = LoadGraph(a.c_str());
	}

	
	Attacks = LoadSoundMem("sounds/player/attacks.wav");
	Attackair = LoadSoundMem("sounds/player/attackair.wav");
	Attackw = LoadSoundMem("sounds/player/attackw.wav");
	PJump = LoadSoundMem("sounds/player/attack.wav");
	Telepo = LoadSoundMem("sounds/player/telepo.wav");

	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	center.Set(50, GROUND_HEIGHT);
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	//attack = 0;
	telepoGauge = TLP_MAX - 20;
	//image = PStand1;
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, PStand[0]);
	acceptFlag = 1;
	isRightFlag = 1;
	//isAir = false;
	isTelepo = false;
	stateFlag = 0;
	bodyClock = 0;
	return 0;
}

int Player::PlayAttacks() {
	PlaySoundMem(Attacks, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayAttackair() {
	PlaySoundMem(Attackair, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayJump() {
	PlaySoundMem(PJump, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayAttackw() {
	PlaySoundMem(Attackw, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayTelepo() {
	PlaySoundMem(Telepo, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::StopAll() {
	StopSoundMem(Attacks);
	StopSoundMem(Attackw);
	StopSoundMem(Attackair);
	StopSoundMem(Telepo);
	return 0;
}

int Player::GetIsRightFlag() {
	return isRightFlag;
}
Dot Player::GetCenter() {
	return center;
}


bool isFirstJump;
int Player::Set(int stageflag) {
	image.Delete();
	//if(levelFlag = 1)
	//center.Set(100, GROUND_HEIGHT - P_HEIGHT / 2);
	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	//attack = 0;
	telepoGauge = TLP_MAX - 20;
	//image = PStand1;
	acceptFlag = 1;
	bodyClock = 0;
	isRightFlag = 1;
	//SetStand(0);
	center.Set(P_START_POINT[2 * stageflag], P_START_POINT[2 * stageflag + 1]);
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, PStand[0]);
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, 0);
	image.Add(telepo.Getx() - TELEPO_DRAW_WIDTH / 2.0, telepo.Gety() - TELEPO_DRAW_HEIGHT / 2.0, telepo.Getx() + TELEPO_DRAW_WIDTH / 2.0, telepo.Gety() + TELEPO_DRAW_HEIGHT / 2.0, 0);
	attackAreaMng.Initialize();
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
	//telepo_back.Set(0, 0);
	isTelepo = false;
	isFirstJump = true;
	mutekiClock = -1000;
	return 0;
}

int Player::SetStand(int count) {
	bodyClock = count;
	stateFlag = 0;
	acceptFlag = 1;
	acceleration.Set(0, 0);
	//velocity.Set(0, 0);	//0,0だからstandに入った
	image.Setimage(0, PStand[0]);
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	return 0;
}

int Player::UpdateStand(int count) {
	for (int i = 0; i < 3; i++) {
		if (count < 2 * (i + 1)) {
			image.Setimage(0, PStand[i]);
			image.Setimage(1, 0);
			image.Setimage(2, 0);
			break;
		}
	}
	if (count > 8) {
		bodyClock += 7;
	}
	return 0;
}

bool isFirstDash;
int Player::SetDash(int count) {
	bodyClock = count;
	stateFlag = 1;
	//image = PStand1;
	isFirstDash = true;
	acceptFlag = 1;
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	return 0;
}
int Player::UpdateDash(int count) {
	image.Setimage(0, PDash[0]);
	for (int i = 0; i < 16; i++) {
		if (count < i) {
			image.Setimage(0, PDash[i]);
			if (isFirstDash && count < 8)
				image.Setimage(1, PDashStart[i]);
			else
				image.Setimage(1, 0);
			break;
		}
	}
	if (count >= 16) {
		bodyClock += 16;
		isFirstDash = false;
	}
	
	return 0;
}

int Player::SetJump(int count) {
	stateFlag = 2;
	bodyClock = count;
	if(isFirstJump)
	 acceleration.Sety(-P_JUMP_POWER);
	image.Setimage(0, PisAir[0]);
	isFirstJump = true;
	PlayJump();
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	return 0;
}
int Player::UpdateJump(int count) {

	if (count < 2) {
		image.Setimage(0, PisAir[0]);
		if (isFirstJump) image.Setimage(1, PJumpE[0]);
	}
	else if (count < 4) {
		image.Setimage(0, PisAir[1]);
		if (isFirstJump) image.Setimage(1, PJumpE[1]);
	}
	else if (count < 6) {
		image.Setimage(0, PisAir[2]);
		if (isFirstJump) image.Setimage(1, PJumpE[2]);
	}
	else if (count < 8) {
		image.Setimage(0, PisAir[1]);
		if (isFirstJump) image.Setimage(1, PJumpE[3]);
	}
	else {
		image.Setimage(1, 0);
		isFirstJump = false;
		bodyClock += 8;
	}
	return 0;
}

int Player::SetAttack_w(int count) {
	bodyClock = count;
	stateFlag = 4;
	acceptFlag = false;
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	//attack = 0;
	return 0;
}
int Player::UpdateAttack_w(int count) {
	for (int i = 0; i < 8; i++) {
		if (count < i) {
			image.Setimage(0, PAttackw[i]);
			break;
		}
	}

	if (count == 3 || count == 4) {
		//if(isRightFlag) attackAreaMng.Add(center.Getx() - 90, center.Gety() - 210, center.Getx() + 210, center.Gety() + 30, 10);
		if (isRightFlag) attackAreaMng.Add(center.Getx() - 50, center.Gety() - 100, center.Getx() + 180, center.Gety() + 60, 40);
		else attackAreaMng.Add(center.Getx() - 180, center.Gety() - 100, center.Getx() + 50, center.Gety() + 60, 40);
		//DrawBox(center.Getx() - 90, center.Gety() - 210, center.Getx() + 210, center.Gety() + 30, RED, true);
	}

	if (count >= 8) {
		acceptFlag = true;
		SetStand(0);
	}
	if (count == 3)
		PlayAttackw();
	return 0;
}

int Player::SetAttack_air(int count) {
	bodyClock = count;
	stateFlag = 5;
	acceptFlag = false;
	//acceleration.Set(0, 0);
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	velocity.Set(0, 0);
	//attack = 0;
	return 0;
}
int Player::UpdateAttack_air(int count) {
	for (int i = 0; i < 8; i++) {
		if (count < i) {
			image.Setimage(0, PAttackair[i]);
			break;
		}
	}

	if (count == 3 || count == 4) {
		if (isRightFlag) attackAreaMng.Add(center.Getx() - 90, center.Gety() - 120, center.Getx() + 240-60, center.Gety() + 120, 40);
		else attackAreaMng.Add(center.Getx() - 240+60, center.Gety() - 120, center.Getx() + 90, center.Gety() + 120, 40);
		//DrawBox(center.Getx() - 90, center.Gety() - 210, center.Getx() + 210, center.Gety() + 30, RED, true);
	}

	if (count >= 8) {
		acceptFlag = true;
		//SetJump(0);
		image.Setimage(0, PisAir[3]);
		isFirstJump = false;
	}
	if (count == 3)
		PlayAttackair();
	return 0;
}
int Player::SetAttack_s(int count) {
	bodyClock = count;
	stateFlag = 3;
	acceptFlag = false;
	acceleration.Set(0, 0);
	image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	velocity.Set(0, 0);
	PlayAttacks();
	//attack = 0;
	return 0;
}
int Player::UpdateAttack_s(int count) {//40-1-5
	for (int i = 0; i < 46; i++) {
		if (count < i) {
			image.Setimage(0, PAttacks[i]);
			break;
		}
	}

	if (count >= 28 && count <= 38) {
		if(isRightFlag) center.Move(6.4 / 2, 0);
		else center.Move(-6.4 / 2, 0);
	}
	if (count >= 40 && count <= 46) {
		if(isRightFlag) center.Move(-10.67 / 2, 0);
		else center.Move(10.67 / 2, 0);
	}

	if (count == 41) {
		if(isRightFlag) attackAreaMng.Add(center.Getx() - 0, center.Gety() - 60, center.Getx() + 170, center.Gety() + 30, 150);
		else attackAreaMng.Add(center.Getx() - 170, center.Gety() - 60, center.Getx() + 0, center.Gety() + 30, 150);
	}
	if (count >= 46) {
		acceptFlag = true;
		SetStand(0);
	}

	return 0;
}
int targcount;
int Player::SetTelepo(int count) {
	targcount = count;
	isTelepo = true;
	//if (isAir) SetJump(count);
	//else SetStand(count);
	//acceptFlag = false;
	//image.Setimage(1, 0);
	image.Setimage(2, 0);
	image.Setimage(3, 0);
	//acceleration.Set(0, 0);
	velocity.Setx(0);
	//attack = 0;
	return 0;
}
int Player::UpdateTelepo(int count) {//

	for (int i = 0; i < 4*3; i++) {//5f更新
		if (count - targcount < i) {
			if (telepoGauge < 100) {//0回
			}
			else if (telepoGauge < 200) {//1回
				image.Setimage(2, PTlp_targ1[i / 3]);
			}
			else if (telepoGauge < 300) {//2回
				image.Setimage(2, PTlp_targ2[i / 3]);
			}
			else if (telepoGauge == 300) {//3回
				image.Setimage(2, PTlp_targ3[i / 3]);
			}
			//printfDx("aaaaaa");
			break;
		}
	}

	/*if (stateFlag == 2 || stateFlag == 0) {
		UpdateStand(count);
	}*/
	if (isAir) {
		//UpdateJump(count);
	}
	else {
		//UpdateStand(count);
	}

	if (count - targcount >= 4*3) {
		targcount += 4*3;
	}

	return 0;
}

int Player::SetDamage(int count) {
	if (count - mutekiClock <= 30) {
		return 0;
	}
	bodyClock = count;
	stateFlag = 7;
	acceptFlag = 0;
	acceleration.Set(0, 0);//要検討
	velocity.Set(0, 0);
	StopAll();
	mutekiClock = count;
	//attack = 0;
	return 1;
}
int Player::UpdateDamage(int count) {
	if (count % 4 < 2) {
		image.Setimage(0, 0);
	}
	else {
		image.Setimage(0, PStand[0]);
	}
	if (isRightFlag) {
		velocity.Setx(-P_SPEED);
	}
	else {
		velocity.Setx(P_SPEED);
	}

	if (count == 10) {
		acceptFlag = true;
		stateFlag = 0;
	}
	return 0;
}

int Player::Update1(int count,int key[]) {//状態回り
	image.Delete();
	weakAreaMng.Delete();
	attackAreaMng.Delete();

	/*if (count % 10 == 0) {
		telepoGauge += 1;
	}*/
	if (LEFT == 1 && telepoGauge >= 100) {
		SetTelepo(count);
		isTelepo = true;
	}
	if (LEFT > 0 && telepoGauge >= 100) {
		telepo.Set(center.Getx() + P_TLP_RANGE * cos(CalcDir(THUMB_X, THUMB_Y)), center.Gety() + P_TLP_RANGE * -sin(CalcDir(THUMB_X, THUMB_Y)));
	}
	if (isTelepo && LEFT == 0 && telepoGauge >= 100) {//テレポ！！
		Tlp_appearMngBorn(count, center);
		center = telepo;
		telepoGauge -= 100;
		PlayTelepo();
		if (acceleration.Gety() >= 0) {
			acceleration.Sety(-P_JUMP_POWER/4.0);
			if(velocity.Gety() >= 0) velocity.Sety(0);
		}
		isAir = true;
		isTelepo = false;
		//acceptFlag = true;
		//stateFlag = 2;
		image.Setimage(1, 0);
		image.Setimage(2, 0);
		Tlp_disappearMngBorn(count, center);
	}

	if (acceptFlag) {//入力受付時

		if (isAir) {//空中なら
			//if (B == 1) SetAirAttack();
			//printfDx("isAir\n");
			if (!isTelepo) {
				if (THUMB_X > 0) {
					velocity.Setx(P_SPEED / 1.5 /** THUMB_X / 100.0*/);
					if (!isTelepo)
						isRightFlag = true;
				}
				else if (THUMB_X < 0) {
					velocity.Setx(-P_SPEED / 1.5 /** THUMB_X / 100.0*/);
					if (!isTelepo)
						isRightFlag = false;
				}
				else {
					velocity.Setx(0);
				}
			}
			else {
				velocity.Setx(0);
			}
			stateFlag = 2;
			if (B == 1) {
				SetAttack_air(count);
			}
			
		}
		else {//地上なら
			if (!isTelepo) {
				if (THUMB_X > 0) {
					if (stateFlag != 1) {
						SetDash(count);
					}
					velocity.Setx(P_SPEED);
					if (!isTelepo)
						isRightFlag = true;
				}
				else if (THUMB_X < 0) {
					if (stateFlag != 1) {
						SetDash(count);
					}
					velocity.Setx(-P_SPEED);
					if (!isTelepo)
						isRightFlag = false;
				}
				else {
					if (stateFlag != 0) {
						SetStand(count);
					}
					velocity.Setx(0);
				}
			}else{
				velocity.Setx(0);
			}
			if (B == 1) {
				SetAttack_w(count);
			}

			if (Y > 1) {
				SetJump(count);
			}
		}
		
		if (A == 1) {
			SetAttack_s(count);
		}
	}
	//入力受付に関係しない
	if (!isTelepo) {//テレポ中でなければ(通常状態なら)

	}
	else {//テレポ中なら(品定め中なら)
		if(velocity.Gety() > 0)
			velocity.Set(0,0);
	}

	switch (stateFlag)
	{
	case 0:
		UpdateStand(count - bodyClock);
		acceptFlag = true;
		break;
	case 1:
		UpdateDash(count - bodyClock);
		acceptFlag = true;
		break;
	case 2:
		UpdateJump(count - bodyClock);
		acceptFlag = true;
		break;
	case 3:
		UpdateAttack_s(count - bodyClock);
		break;
	case 4:
		UpdateAttack_w(count - bodyClock);
		break;
	case 5:
		UpdateAttack_air(count - bodyClock);
		break;
	case 7:
		UpdateDamage(count - bodyClock);
		break;
	default:
		acceptFlag = true;
		break;
	}
	if (isTelepo) {
		UpdateTelepo(count);
	}

	if (stateFlag != 5) {//空中攻撃中は移動しない
		velocity.Move(acceleration.Getx(), acceleration.Gety());
		center.Move(velocity.Getx(), velocity.Gety());
	}
	weakAreaMng.Add(center.Getx() - P_WEAK_LU_X, center.Gety() - P_WEAK_LU_Y, center.Getx() + P_WEAK_RD_X, center.Gety() + P_WEAK_RD_Y);	

	return 0;
}

int Player::Update2(SquareMng a,int count) {//壁まわりの処理
	//DrawFormatString(40, 80, RED, "%d", weakAreaMng.isHitSquareMng(a));
	Square telepoSqu;
	telepoSqu.Set(telepo.Getx() - P_WEAK_LU_X, telepo.Gety() - P_WEAK_LU_Y, telepo.Getx() + P_WEAK_RD_X, telepo.Gety() + P_WEAK_RD_Y);
	a.testDraw(GREEN);
	/*-----------テレポ処理---------------*/
	if (isTelepo) {	//テレポ中
		for (int i = P_TLP_RANGE; i > 0; i--) {
			if (!a.isAbleTelepo(center, telepo)) {//テレポできなければ
				telepo.Set(center.Getx() + (double)(i)* cos(CalcDir(center, telepo)), center.Gety() + (double)(i) * -sin(CalcDir(center, telepo)));//もっと狭いとこに更新
				//telepo.Move(cos(CalcDir(center, telepo)), sin(-cos(CalcDir(center, telepo))));	
				//printfDx("TLP");
			}
		}
		telepoSqu.Set(telepo.Getx() - P_WEAK_LU_X, telepo.Gety() - P_WEAK_LU_Y, telepo.Getx() + P_WEAK_RD_X, telepo.Gety() + P_WEAK_RD_Y);
		telepo = a.SetTelepo(center, telepo, telepoSqu);
		telepoSqu.Set(telepo.Getx() - P_WEAK_LU_X, telepo.Gety() - P_WEAK_LU_Y, telepo.Getx() + P_WEAK_RD_X, telepo.Gety() + P_WEAK_RD_Y);//二回やると壁抜けバグが治る(”当たらなかった四角が当たるようになったりするため”)
		telepo = a.SetTelepo(center, telepo, telepoSqu);
	}
	
	//プレイヤーの位置について，壁判定
	isAir = true;//足に何かが触れなければ空中にいる
	double decoi;
	for (int i = 0; i < SQU_NUM; i++) {
		if (a.GetSquare(i).GetisExist()) {//四角ごとに判定
			switch (weakAreaMng.GetSquare(0).isHitSquare(a.GetSquare(i),velocity))//ここできちんとめり込みまで判定できれば問題ない
			{
			case 0://ぶつかってない
				break;
			case 2://U
				if (acceleration.Gety() < 0) {
					acceleration.Sety(0);
				}
				if (velocity.Gety() < 0) {
					velocity.Sety(0);
				}
				decoi = a.GetUpLanding(weakAreaMng.GetSquare(0), P_SPEED) + P_WEAK_LU_Y;
				if(fabs(decoi - center.Gety()) < P_SPEED*2)
					center.Sety(decoi);
				//printfDx("U:%d\n", i);
				break;
			case 4://R
				if (velocity.Getx() > 0) velocity.Setx(0);
				decoi = a.GetRightLanding(weakAreaMng.GetSquare(0), P_SPEED) - P_WEAK_LU_X;
				if(fabs(decoi - center.Getx()) < P_SPEED*2)
					center.Setx(decoi);
				//printfDx("R:%d\n", i);
				//printfDx("R!\n");
				break;
			case 6://D
				if (velocity.Gety() < 0) break;//上昇中は接地しない
				if (acceleration.Gety() > 0) {
					acceleration.Sety(0);
				}
				if (velocity.Gety() > 0) {
					velocity.Sety(0);
				}
				decoi = a.GetLanding(weakAreaMng.GetSquare(0), 60) - P_WEAK_LU_Y;
				if (fabs(decoi - center.Gety()) < P_SPEED * 4)
					center.Sety(decoi);
				if (stateFlag == 2) {//
					SetStand(count);
				}
				/*if(i == 0)
					printfDx("D:%d\n", i);*/
				isAir = false;
				break;
			case 8://L
				if (velocity.Getx() < 0) velocity.Setx(0);
				decoi = a.GetLeftLanding(weakAreaMng.GetSquare(0), P_SPEED) + P_WEAK_LU_X;
				if (fabs(decoi - center.Getx()) < P_SPEED * 2)
					center.Setx(decoi);
				//printfDx("L:%d\n", i);
				break;
			default:
				break;
			}
		}
	}
	//printfDx("\n");

	if (isAir && stateFlag != 5)
		acceleration.Move(0, GRAVITY);

	if (velocity.Gety() > 50) velocity.Sety(50);

	if (center.Gety() > DISP_HEIGHT) {//エラー処理
		center.Sety(DISP_HEIGHT - 60 - P_WEAK_LU_Y);
		velocity.Sety(0);
		acceleration.Sety(0);
		isAir = false;
		SetStand(0);
	}

	
	/*if ((telepo - center).Getx() >= 0 && (telepo - center).Getx() >= 0) telepo.Move(-60, -60);
	if ((telepo - center).Getx() <= 0 && (telepo - center).Getx() >= 0) telepo.Move(+60, -60);
	if ((telepo - center).Getx() <= 0 && (telepo - center).Getx() <= 0) telepo.Move(+60, +60);
	if ((telepo - center).Getx() >= 0 && (telepo - center).Getx() <= 0) telepo.Move(-60, +60);*/

	weakAreaMng.Delete();
	weakAreaMng.Add(center.Getx() - P_WEAK_LU_X, center.Gety() - P_WEAK_LU_Y, center.Getx() + P_WEAK_RD_X, center.Gety() + P_WEAK_RD_Y);

	image.SetPosi(0, center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0);
	image.SetPosi(1, center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0);
	image.SetPosi(2, telepo.Getx() - TELEPO_DRAW_WIDTH / 2.0, telepo.Gety() - TELEPO_DRAW_HEIGHT / 2.0, telepo.Getx() + TELEPO_DRAW_WIDTH / 2.0, telepo.Gety() + TELEPO_DRAW_HEIGHT / 2.0);

	return 0;
}

int Player::Addtelepo() {
	int a = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (attackAreaMng.GetintSquare(i).GetisExist()) {
			if (a < attackAreaMng.GetintSquare(i).GetValue())
				a = attackAreaMng.GetintSquare(i).GetValue();
		}
	}
	//a += 20;
	if (a > 100) a = 100;
	telepoGauge += a;
	if (telepoGauge > TLP_MAX) telepoGauge = TLP_MAX;

	return 0;
}

int Player::GetStateFlag() {
	return stateFlag;
}
intSquareMng Player::GetAttackAreaMng() {
	return attackAreaMng;
}
SquareMng Player::GetWeakAreaMng() {
	return weakAreaMng;
}
int Player::GetAttack() {
	//return attack;
	return 0;
}
bool Player::Getismuteki(int count) {
	if (count - mutekiClock <= 30) {
		return true;
	}
	else {
		return false;
	}
}

int Player::Draw() {

	image.Draw(isRightFlag);
	if (telepoGauge < 100)//0回
		;//DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, RED, 0);
	else if (telepoGauge < 200)//1回
		DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, RED, 0);
	else if (telepoGauge < 300)//2回
		DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, PURPLE, 0);
	if(telepoGauge == 300)//3回
		DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, BLUE, 0);

	attackAreaMng.testDraw(RED);

	return 0;
}