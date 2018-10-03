#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"
#include<math.h>

int PDash[8];
int PDashStart[4];

int PisAir[3];
int PJumpE[4];

int PStand[3];

int PAttacks[21];
int PAttackw[4];

int PAttackw1;
int PAttackw2;
int PAttackw3;

int Attack_w;
int Attack_s;
int PJump;
int PGet;

int Player::Initialize() {
	for (int i = 0; i < 3; i++) {
		std::string a = "images/player/stand/";
		a += std::to_string(i);
		a += ".png";
		PStand[i] = LoadGraph(a.c_str());
	}
	
	PDash[0] = LoadGraph("images/player/dash/1.png");
	PDash[1] = LoadGraph("images/player/dash/2.png");
	PDash[2] = LoadGraph("images/player/dash/3.png");
	PDash[3] = LoadGraph("images/player/dash/4.png");
	PDash[4] = LoadGraph("images/player/dash/5.png");
	PDash[5] = LoadGraph("images/player/dash/6.png");
	PDash[6] = LoadGraph("images/player/dash/7.png");
	PDash[7] = LoadGraph("images/player/dash/8.png");

	PDashStart[0] = LoadGraph("images/player/dash_start/1.png");
	PDashStart[1] = LoadGraph("images/player/dash_start/2.png");
	PDashStart[2] = LoadGraph("images/player/dash_start/3.png");
	PDashStart[3] = LoadGraph("images/player/dash_start/4.png");

	PJumpE[0] = LoadGraph("images/player/jump/1.png");
	PJumpE[1] = LoadGraph("images/player/jump/2.png");
	PJumpE[2] = LoadGraph("images/player/jump/3.png");
	PJumpE[3] = LoadGraph("images/player/jump/4.png");

	PisAir[0] = LoadGraph("images/player/air_free/1.png");
	PisAir[1] = LoadGraph("images/player/air_free/2.png");
	PisAir[2] = LoadGraph("images/player/air_free/3.png");

	for (int i = 0; i < 22; i++) {
		std::string a = "images/player/attack_s/";
		a += std::to_string(i);
		a += ".png";
		PAttacks[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/attack_w/";
		a += std::to_string(i);
		a += ".png";
		PAttackw[i] = LoadGraph(a.c_str());
	}
	/*
	PJump1 = LoadGraph("images/player/Jump/1.png");
	PJump2 = LoadGraph("images/player/Jump/2.png");
	PJump3 = LoadGraph("images/player/Jump/3.png");
	PJump4 = LoadGraph("images/player/Jump/4.png");

	PAttacks1 = LoadGraph("images/player/Attacks/1.png");
	PAttacks2 = LoadGraph("images/player/Attacks/2.png");
	PAttacks3 = LoadGraph("images/player/Attacks/3.png");

	PAttackw1 = LoadGraph("images/player/Attackw/1.png");
	PAttackw2 = LoadGraph("images/player/Attackw/2.png");
	PAttackw3 = LoadGraph("images/player/Attackw/3.png");

	Attack_s = LoadSoundMem("music/knife2.wav");
	Attack_l = LoadSoundMem("music/knife.wav");
	Attack_w = LoadSoundMem("music/knife3.wav");
	PJump = LoadSoundMem("music/jump1.wav");
	PGet = LoadSoundMem("music/choice1.wav");*/

	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	center.Set(50, GROUND_HEIGHT);
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	attack = 0;
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

int Player::PlayAttack_s() {
	PlaySoundMem(Attack_s, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayJump() {
	PlaySoundMem(PJump, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayAttack_w() {
	PlaySoundMem(Attack_w, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayGet() {
	PlaySoundMem(PGet, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::GetIsRightFlag() {
	return isRightFlag;
}
Dot Player::GetCenter() {
	return center;
}



int Player::Set(int stageflag) {
	image.Delete();
	//if(levelFlag = 1)
	//center.Set(100, GROUND_HEIGHT - P_HEIGHT / 2);
	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	attack = 0;
	//image = PStand1;
	acceptFlag = 1;
	bodyClock = 0;
	isRightFlag = 1;
	SetStand(0);
	center.Set(P_START_POINT[2 * stageflag], P_START_POINT[2 * stageflag + 1]);
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, PStand[0]);
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, 0);
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
	telepo_back.Set(0, 0);
	isTelepo = false;
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
	return 0;
}

int Player::UpdateStand(int count) {
	for (int i = 0; i < 3; i++) {
		if (count < 2 * (i + 1)) {
			image.Setimage(0, PStand[i]);
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
	return 0;
}
int Player::UpdateDash(int count) {

	if (count < 2) {
		image.Setimage(0, PDash[0]);
		if (isFirstDash) image.Setimage(1, PDashStart[0]);
	}
	else if (count < 4) {
		image.Setimage(0, PDash[1]);
		if (isFirstDash) image.Setimage(1, PDashStart[1]);
	}
	else if (count < 6) {
		image.Setimage(0, PDash[2]);
		if (isFirstDash) image.Setimage(1, PDashStart[2]);
	}
	else if (count < 8) {
		image.Setimage(0, PDash[3]);
		if (isFirstDash) image.Setimage(1, PDashStart[3]);
	}
	else if (count < 10) {
		image.Setimage(0, PDash[4]);
		if (isFirstDash) image.Setimage(1, 0);
	}
	else if (count < 12) {
		image.Setimage(0, PDash[5]);
	}
	else if (count < 14) {
		image.Setimage(0, PDash[6]);
	}
	else if (count < 16) {
		image.Setimage(0, PDash[7]);
	}
	else {
		bodyClock += 16;
		isFirstDash = false;
	}
	return 0;
}

bool isFirstJump;
int Player::SetJump(int count) {
	stateFlag = 2;
	bodyClock = count;
	acceleration.Sety(-P_JUMP_POWER);
	isFirstJump = true;
	PlayJump();
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
	attack = 0;
	return 0;
}
int Player::UpdateAttack_w(int count) {
	for (int i = 0; i < 4; i++) {
		if (count < 2 * (i + 1)) {
			image.Setimage(0, PAttackw[i]);
			break;
		}
	}
	if (count > 8) {
		acceptFlag = true;
		SetStand(0);
	}
	if (count == 5)
		PlayAttack_w();
	return 0;
	return 0;
}

int Player::SetAttack_s(int count) {
	bodyClock = count;
	stateFlag = 3;
	acceptFlag = false;
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	attack = 0;
	return 0;
}
int Player::UpdateAttack_s(int count) {
	for (int i = 0; i < 21; i++) {
		if (count < 2 * (i + 1)) {
			image.Setimage(0, PAttacks[i]);
			break;
		}
	}
	if (count > 42) {
		acceptFlag = true;
		SetStand(0);
	}
	if (count == 17)
		PlayAttack_s();
	return 0;
}
int Player::SetDamage(int count) {
	bodyClock = count;
	stateFlag = 7;
	acceptFlag = 0;
	acceleration.Set(0, 0);//要検討
	velocity.Set(0, 0);
	attack = 0;
	return 0;
}
int Player::UpdateDamage(int count) {

	if (count < 17) {//待機
		acceptFlag = 0;
	}
	else if (count < 20) {//攻撃
		attack = 40;
		//attackArea.Set(LU, RD);
	}
	else if (count < 40) {//余韻
		attack = 0;
	}
	else if (count >= 40) {//モーション終わり
		acceptFlag = 1;
		//if (isAir != 0) {
		//	isAir = 0;
		//	stateFlag = 4;//戻す
		//}
		//else {
		//	SetStand(count);
		//	//printfDx("SETSTAND!\n");
		//}
	}
	/*if (count == 0) image = PAttacks1;
	if (count == 17) image = PAttacks2;
	if (count == 19) image = PAttacks3;*/
	if (count == 17)
		PlayAttack_s();
	if (count == 10) {
		acceptFlag = true;
		stateFlag = 0;
	}
	return 0;
}

int dirKeeper;
int Player::Update1(int count,int key[]) {//状態回り
	weakAreaMng.Delete();

	if (LEFT > 0) {
		telepo.Set(center.Getx() + P_TLP_RANGE * cos(CalcDir(THUMB_X, THUMB_Y)), center.Gety() + P_TLP_RANGE * -sin(CalcDir(THUMB_X, THUMB_Y)));
		isTelepo = true;
	}
	if (isTelepo && !LEFT) {
		center = telepo;
		isAir = true;
		isTelepo = false;
	}

	if (acceptFlag) {//入力受付時
		if (!isTelepo) {//テレポ中でなければ(通常状態なら)
			
		}
		else {//テレポ中なら(品定め中なら)
			velocity.Setx(0);
		}

		if (isAir) {//空中なら
			//if (B == 1) SetAirAttack();
			//printfDx("isAir\n");
			if (THUMB_X > 0) {
				velocity.Setx(P_SPEED / 1.5 /** THUMB_X / 100.0*/);
				isRightFlag = true;
			}
			else if (THUMB_X < 0) {
				velocity.Setx(-P_SPEED / 1.5 /** THUMB_X / 100.0*/);
				isRightFlag = false;
			}
			else {
				velocity.Setx(0);
			}
			stateFlag = 2;
		}
		else {//地上なら
			if (THUMB_X > 0) {
				if (stateFlag != 1) {
					SetDash(count);
				}
				velocity.Setx(P_SPEED);
				isRightFlag = true;
			}
			else if (THUMB_X < 0) {
				if (stateFlag != 1) {
					SetDash(count);
				}
				velocity.Setx(-P_SPEED);
				isRightFlag = false;
			}
			else {
				if (stateFlag != 0) SetStand(count);
				velocity.Setx(0);
			}
			if (B == 1) {
				SetAttack_w(count);
			}
			if (A == 1) {
				SetAttack_s(count);
			}
			if (Y > 0) {
				SetJump(count);
			}
		}
	}

	switch (stateFlag)
	{
	case 0:
		UpdateStand(count - bodyClock);
		break;
	case 1:
		UpdateDash(count - bodyClock);
		break;
	case 2:
		UpdateJump(count - bodyClock);
		break;
	case 3:
		UpdateAttack_s(count - bodyClock);
		break;
	case 4:
		UpdateAttack_w(count - bodyClock);
		break;
	case 5:
		//UpdateAttack_air(count - bodyClock);
		break;
	case 6:
		//UpdateAttack_air(count - bodyClock);
		break;
	case 7:
		UpdateDamage(count - bodyClock);
		break;
	default:
		break;
	}

	velocity.Move(acceleration.Getx(), acceleration.Gety());
	center.Move(velocity.Getx(), velocity.Gety());
	weakAreaMng.Add(center.Getx() - P_WEAK_LU_X, center.Gety() - P_WEAK_LU_Y, center.Getx() + P_WEAK_RD_X, center.Gety() + P_WEAK_RD_Y);	

	return 0;
}

int Player::Update2(SquareMng a,int count) {//壁まわりの処理
	//DrawFormatString(40, 80, RED, "%d", weakAreaMng.isHitSquareMng(a));

	/*-----------テレポ処理---------------*/
	if (isTelepo) {	//テレポ中
		for (int i = P_TLP_RANGE; i > 0; i--) {
			if (!a.isAbleTelepo(center, telepo)) {//テレポできなければ
				telepo.Set(center.Getx() + (double)(i)* cos(CalcDir(center, telepo)), center.Gety() + (double)(i) * -sin(CalcDir(center, telepo)));//もっと狭いとこに更新
				//telepo.Move(cos(CalcDir(center, telepo)), sin(-cos(CalcDir(center, telepo))));	
			}
		}

		//テレポ先について，壁判定

		//Square telepoSqu;
		//telepoSqu.Set(telepo.Getx() - P_WEAK_LU_X, telepo.Gety() - P_WEAK_LU_Y, telepo.Getx() + P_WEAK_LU_X, telepo.Gety() + P_WEAK_LU_Y);
		//Dot telepoVel;	//プレイヤーとテレポの間の変位(速度)を表すドット(下でいうvelocity)
		//telepoVel.Set(center.Getx() + CalcDistance(center, telepo) * 0.99 * cos(CalcDir(center, telepo)), center.Gety() + CalcDistance(center, telepo) * 0.99 * -sin(CalcDir(center, telepo)));
		//for (int i = 0; i < SQU_NUM; i++) {
		//	if (a.GetSquare(i).GetisExist()) {//四角ごとに判定
		//		switch (telepoSqu.isHitSquare(a.GetSquare(i), telepoVel))//ここできちんとめり込みまで判定できれば問題ない
		//		{
		//		case 0://ぶつかってない
		//			break;
		//		case 2://U
		//			telepo.Sety(a.GetUpLanding(telepoSqu) + P_WEAK_LU_Y);
		//			break;
		//		case 4://R
		//			telepo.Setx(a.GetRightLanding(telepoSqu) - P_WEAK_LU_X);
		//			break;
		//		case 6://D
		//			telepo.Sety(a.GetLanding(telepoSqu) - P_WEAK_LU_Y);
		//			break;
		//		case 8://L
		//			telepo.Setx(a.GetLeftLanding(telepoSqu) + P_WEAK_LU_X);
		//			break;
		//		default:
		//			break;
		//		}
		//	}
		//}

	}
	

	//プレイヤーの位置について，壁判定
	isAir = true;//足に何かが触れなければ空中にいる
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
				center.Sety(a.GetUpLanding(weakAreaMng.GetSquare(0)) + P_WEAK_LU_Y);
				//printfDx("U:%d\n", i);
				break;
			case 4://R
				if (velocity.Getx() > 0) velocity.Setx(0);
				center.Setx(a.GetRightLanding(weakAreaMng.GetSquare(0)) - P_WEAK_LU_X);
				//printfDx("R:%d\n", i);
				//printfDx("R!\n");
				break;
			case 6://D
				if (acceleration.Gety() > 0) {
					acceleration.Sety(0);
				}
				if (velocity.Gety() > 0) {
					velocity.Sety(0);
				}
				center.Sety(a.GetLanding(weakAreaMng.GetSquare(0)) - P_WEAK_LU_Y);
				if (stateFlag == 2) {//
					SetStand(count);
				}
				/*if(i == 0)
					printfDx("D:%d\n", i);*/
				isAir = false;
				break;
			case 8://L
				if (velocity.Getx() < 0) velocity.Setx(0);
				center.Setx(a.GetLeftLanding(weakAreaMng.GetSquare(0)) + P_WEAK_LU_X);
				//printfDx("L:%d\n", i);
				break;
			default:
				break;
			}
		}
	}

	if (isAir)
		acceleration.Move(0, GRAVITY);

	if (velocity.Gety() > 50) velocity.Sety(50);

	if (center.Gety() > DISP_HEIGHT) {
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

	return 0;
}

int Player::GetStateFlag() {
	return stateFlag;
}
SquareMng Player::GetAttackAreaMng() {
	return attackAreaMng;
}
SquareMng Player::GetWeakAreaMng() {
	return weakAreaMng;
}
int Player::GetAttack() {
	return attack;
}

int Player::Draw() {

	weakAreaMng.testDraw(BLUE);

	//if (isRightFlag)
	//	DrawModiGraph(//描画を少しずらす
	//		center.Getx() - P_DRAW_WIDTH / 2, center.Gety() - P_DRAW_HEIGHT / 2,
	//		center.Getx() + P_DRAW_WIDTH / 2, center.Gety() - P_DRAW_HEIGHT / 2,
	//		center.Getx() + P_DRAW_WIDTH / 2, center.Gety() + P_DRAW_HEIGHT / 2,
	//		center.Getx() - P_DRAW_WIDTH / 2, center.Gety() + P_DRAW_HEIGHT / 2,
	//		image,true);
	//else
	//	DrawModiGraph(
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		image, true);
	image.Draw(isRightFlag);

	//if(isRightFlag)
	/*DrawModiGraph(
		center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0,
		center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0,
		center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0,
		center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0,
		image, true
	);*/
	DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, RED, 0);
	DrawCircle(telepo.Getx(), telepo.Gety(), 30, RED, 1);

	if (attack > 0)
		attackAreaMng.testDraw(RED);

	//DrawBox(telepo_back.Getx() - 30, telepo_back.Gety() - 30, telepo_back.Getx() + 30, telepo_back.Gety() + 30, WHITE, false);

	//DrawBox(center.Getx() - 96, center.Gety() - 96, center.Getx() + 96, center.Gety() + 96, BLUE, false);
	//DrawBox(center.Getx() - 96*2, center.Gety() - 96 * 2, center.Getx() + 96 * 2, center.Gety() + 96 * 2, BLUE, false);

	//DrawFormatString(0, 120, RED, "P_state:%d ,a:%f",stateFlag,acceleration.Gety());
	//DrawFormatString(0, 0, RED, "P_state:%d,weaponFlag:%d,accept:%d", stateFlag, WeaponFlag,acceptFlag);
	

	return 0;
}