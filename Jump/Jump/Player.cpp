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

int Attack_w;
int Attack_s;
int PJump;
int PGet;

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

	/*
	Attack_s = LoadSoundMem("music/knife2.wav");
	Attack_l = LoadSoundMem("music/knife.wav");
	Attack_w = LoadSoundMem("music/knife3.wav");
	PJump = LoadSoundMem("music/jump1.wav");
	PGet = LoadSoundMem("music/choice1.wav");*/

	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	center.Set(50, GROUND_HEIGHT);
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
	//attack = 0;
	telepoGauge = TLP_MAX;
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


bool isFirstJump;
int Player::Set(int stageflag) {
	image.Delete();
	//if(levelFlag = 1)
	//center.Set(100, GROUND_HEIGHT - P_HEIGHT / 2);
	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	//attack = 0;
	telepoGauge = TLP_MAX;
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
		if (isRightFlag) attackAreaMng.Add(center.Getx() - 50, center.Gety() - 100, center.Getx() + 180, center.Gety() + 60, 10);
		else attackAreaMng.Add(center.Getx() - 180, center.Gety() - 100, center.Getx() + 50, center.Gety() + 60, 10);
		//DrawBox(center.Getx() - 90, center.Gety() - 210, center.Getx() + 210, center.Gety() + 30, RED, true);
	}

	if (count >= 8) {
		acceptFlag = true;
		SetStand(0);
	}
	if (count == 5)
		PlayAttack_w();
	return 0;
}

int Player::SetAttack_air(int count) {
	bodyClock = count;
	stateFlag = 5;
	acceptFlag = false;
	//acceleration.Set(0, 0);
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
		if (isRightFlag) attackAreaMng.Add(center.Getx() - 90, center.Gety() - 120, center.Getx() + 240-60, center.Gety() + 120, 10);
		else attackAreaMng.Add(center.Getx() - 240+60, center.Gety() - 120, center.Getx() + 90, center.Gety() + 120, 10);
		//DrawBox(center.Getx() - 90, center.Gety() - 210, center.Getx() + 210, center.Gety() + 30, RED, true);
	}

	if (count >= 8) {
		acceptFlag = true;
		//SetJump(0);
		image.Setimage(0, PisAir[3]);
		isFirstJump = false;
	}
	if (count == 5)
		PlayAttack_w();
	return 0;
}
int Player::SetAttack_s(int count) {
	bodyClock = count;
	stateFlag = 3;
	acceptFlag = false;
	acceleration.Set(0, 0);
	velocity.Set(0, 0);
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
		center.Move(6.4, 0);
	}
	if (count >= 40 && count <= 46) {
		center.Move(-10.67, 0);
	}

	if (count == 41) {
		if(isRightFlag) attackAreaMng.Add(center.Getx() - 0, center.Gety() - 60, center.Getx() + 170, center.Gety() + 30, 100);
		else attackAreaMng.Add(center.Getx() - 170, center.Gety() - 60, center.Getx() + 0, center.Gety() + 30, 100);
	}
	if (count >= 46) {
		acceptFlag = true;
		SetStand(0);
	}

	return 0;
}

int Player::SetTelepo(int count) {
	bodyClock = count;
	stateFlag = 6;
	acceptFlag = false;
	//acceleration.Set(0, 0);
	//velocity.Set(0, 0);
	//attack = 0;
	return 0;
}
int Player::UpdateTelepo(int count) {//
	for (int i = 0; i < 4; i++) {
		if (count < i) {
			if(telepoGauge < 100)
				image.Setimage(2, PTlp_targ1[i]);
			else
				image.Setimage(2, PTlp_targ2[i]);
			//printfDx("aaaaaa");
			break;
		}
	}
	UpdateStand(count);

	if (count >= 4) {
		bodyClock += 4;
	}

	return 0;
}

int Player::SetDamage(int count) {
	bodyClock = count;
	stateFlag = 7;
	acceptFlag = 0;
	acceleration.Set(0, 0);//要検討
	velocity.Set(0, 0);
	//attack = 0;
	return 0;
}
int Player::UpdateDamage(int count) {

	if (count < 17) {//待機
		acceptFlag = 0;
	}
	else if (count < 20) {//攻撃
		//attack = 40;
		//attackArea.Set(LU, RD);
	}
	else if (count < 40) {//余韻
		//attack = 0;
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

int Player::Update1(int count,int key[]) {//状態回り
	image.Delete();
	weakAreaMng.Delete();
	attackAreaMng.Delete();

	if (count % 30 == 0) {
		telepoGauge += 1;
	}
	if (LEFT == 1 && telepoGauge >= 100) {
		SetTelepo(count);
	}
	if (LEFT > 0 && telepoGauge >= 100) {
		telepo.Set(center.Getx() + P_TLP_RANGE * cos(CalcDir(THUMB_X, THUMB_Y)), center.Gety() + P_TLP_RANGE * -sin(CalcDir(THUMB_X, THUMB_Y)));
		isTelepo = true;
	}
	if (isTelepo && !LEFT) {//テレポ！！
		Tlp_appearMngBorn(count, center);
		center = telepo;
		telepoGauge -= 100;
		if (acceleration.Gety() >= 0) {
			acceleration.Sety(-P_JUMP_POWER/4.0);
			if(velocity.Gety() >= 0) velocity.Sety(0);
		}
		isAir = true;
		isTelepo = false;
		acceptFlag = true;
		//stateFlag = 2;
		image.Setimage(2, 0);
		Tlp_disappearMngBorn(count, center);
	}

	if (acceptFlag) {//入力受付時

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
			if (B == 1) {
				SetAttack_air(count);
			}
		}
		else {//地上なら
			if (stateFlag != 6) {//テレポ中横移動はしない
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
			}
			else {
				velocity.Set(0, 0);
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
	//入力受付に関係しない
	if (!isTelepo) {//テレポ中でなければ(通常状態なら)

	}
	else {//テレポ中なら(品定め中なら)
		velocity.Setx(0);
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
		UpdateAttack_air(count - bodyClock);
		break;
	case 6:
		UpdateTelepo(count - bodyClock);
		break;
	case 7:
		UpdateDamage(count - bodyClock);
		break;
	default:
		break;
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
		telepo = a.SetTelepo(center, telepo);
		
		//telepo(壁内)ゲット
		//テレポ先について，壁判定
		//Square tlpSquare;//壁内テレポを四角にした
		//tlpSquare.Set(telepo.Getx() - P_WEAK_LU_X, telepo.Gety() - P_WEAK_LU_Y, telepo.Getx() + P_WEAK_LU_X, telepo.Gety() + P_WEAK_LU_Y);
		//Dot tlpVel;
		//tlpVel.Set(50* cos(CalcDir(center, telepo)), 50 * -sin(CalcDir(center, telepo)));
		////tlpVel.Set(15 * cos(CalcDir(center, telepo)), 15 * -sin(CalcDir(center, telepo)));//現テレポの一歩前(velocity)

		//tlpSquare.Set(-tlpVel.Getx() + telepo.Getx() - P_WEAK_LU_X, -tlpVel.Gety() + telepo.Gety() - P_WEAK_LU_Y, -tlpVel.Getx() + telepo.Getx() + P_WEAK_LU_X, -tlpVel.Gety() + telepo.Gety() + P_WEAK_LU_Y);
		////tlpVel.Set(15 * cos(CalcDir(center, telepo)), 15 * -sin(CalcDir(center, telepo)));//現テレポの一歩前(velocity)
		////tlpSquare.testDraw(BLUE);
		//
		//for (int i = 0; i < SQU_NUM; i++) {
		//	if (a.GetSquare(i).GetisExist()) {//四角ごとに判定
		//		switch (tlpSquare.isHitSquare(a.GetSquare(i), tlpVel))//ここできちんとめり込みまで判定できれば問題ない
		//		//switch (tlpSquare.isHitSquare_tlp(a.GetSquare(i), telepo, center,tlpVel))
		//		{
		//		case 0://ぶつかってない
		//			break;
		//		case 2://U//直すべきはこのあたりか
		//			telepo.Sety(a.GetUpLanding_tlp(tlpSquare) + P_WEAK_LU_Y);
		//			//telepo.Sety(a.GetUpLanding_tlp(Dot center, Dot telepo));
		//			//printfDx("U:%d\n", i);
		//			break;
		//		case 4://R
		//			telepo.Setx(a.GetRightLanding_tlp(tlpSquare) - P_WEAK_LU_X);
		//			//printfDx("RIGHT!!!\n");
		//			//printfDx("R!\n");
		//			break;
		//		case 6://D
		//			telepo.Sety(a.GetLanding_tlp(tlpSquare) - P_WEAK_LU_Y);
		//			//printfDx("D!\n");
		//			break;
		//		case 8://L
		//			telepo.Setx(a.GetLeftLanding_tlp(tlpSquare) + P_WEAK_LU_X);
		//			//printfDx("L:%d\n", i);
		//			break;
		//		default:
		//			break;
		//		}
		//	}
		//}
		//if (CalcDistance(telepo - center) > P_TLP_RANGE+30) {
		//	telepo = center;
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

	if (isAir && stateFlag != 5)
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
	a += 20;
	if (a > 100) a = 100;
	telepoGauge += a;

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

int Player::Draw() {

	image.Draw(isRightFlag);

	DrawCircle(center.Getx(), center.Gety(), P_TLP_RANGE, RED, 0);

	attackAreaMng.testDraw(RED);

	return 0;
}