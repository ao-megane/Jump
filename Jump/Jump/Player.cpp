#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"
#include<math.h>

int PDash1;
int PDash2;
int PDash3;
int PDash4;
int PDash5;

int PJump1;
int PJump2;
int PJump3;
int PJump4;

int PStand1;

int PAttacks1;
int PAttacks2;
int PAttacks3;

int PAttackw1;
int PAttackw2;
int PAttackw3;

int Attack_w;
int Attack_s;
int PJump;
int PGet;

int Player::Initialize() {
	PStand1 = LoadGraph("images/200.png");
	/*PDash1 = LoadGraph("images/player/dash/1.png");
	PDash2 = LoadGraph("images/player/dash/2.png");
	PDash3 = LoadGraph("images/player/dash/3.png");
	PDash4 = LoadGraph("images/player/dash/4.png");
	PDash5 = LoadGraph("images/player/dash/5.png");

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
	//image = PStand1;
	return 0;
}

int Player::UpdateStand(int count) {
	//center.Set(center.Get_x() - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	return 0;
}

int Player::SetDash(int count) {
	bodyClock = count;
	stateFlag = 1;
	//image = PStand1;
	acceptFlag = 1;
	return 0;
}
int Player::UpdateDash(int count) {

	int sum = 19;	//一周のフレーム数
	int num = 8;	//一周の画像数
	if (count % sum <= sum / num * 1) {
		//image = PDash1;
	}
	else if (count % sum <= sum / num * 2) {
		//image = PDash2;
	}
	else if (count % sum <= sum / num * 3) {
		//image = PDash3;
	}
	else if (count % sum <= sum / num * 4) {
		//image = PDash4;
	}
	else if (count % sum <= sum / num * 5) {
		//image = PDash5;
	}
	else if (count % sum <= sum / num * 6) {
		//image = PDash4;
	}
	else if (count % sum <= sum / num * 7) {
		//image = PDash3;
	}
	else if (count % sum <= sum / num * 8) {
		//image = PDash2;
	}
	return 0;
}

int Player::SetJump(int count) {
	stateFlag = 2;
	//image = PStand1;
	bodyClock = count;
	acceleration.Sety(-P_JUMP_POWER);
	//isAir = true;
	PlayJump();
	return 0;
}
int Player::UpdateJump(int count) {
	//printfDx("JUMPING");
	//center.Sety(-sin((count / P_JUMP_NUM)*PI) * P_JUMP_HEIGHT + GROUND_HEIGHT);

	//switch (flag)
	//{
	//case 0://右ダッシュ
	//	center.Set((center.Get_x()) - GROUND_SPEED + 2*2, -sin((count / PLAYER_JUMP_SUM)*PI) * PLAYER_JUMP_HEIGHT + GROUND_HEIGHT - P_HEIGHT / 2);
	//	break;
	//case 1://右歩き
	//	center.Set((center.Get_x()) - GROUND_SPEED + 1*2, -sin((count / PLAYER_JUMP_SUM)*PI) * PLAYER_JUMP_HEIGHT + GROUND_HEIGHT - P_HEIGHT / 2);
	//	break; 
	//case 2://左ダッシュ
	//	center.Set((center.Get_x()) - GROUND_SPEED - 2*2, -sin((count / PLAYER_JUMP_SUM)*PI) * PLAYER_JUMP_HEIGHT + GROUND_HEIGHT - P_HEIGHT / 2);
	//	break;
	//case 3://左歩き
	//	center.Set((center.Get_x()) - GROUND_SPEED - 1*2, -sin((count / PLAYER_JUMP_SUM)*PI) * PLAYER_JUMP_HEIGHT + GROUND_HEIGHT - P_HEIGHT / 2);
	//	break;
	//case 4://立ち
	//	center.Set((center.Get_x()) - GROUND_SPEED + 0, -sin((count / PLAYER_JUMP_SUM)*PI) * PLAYER_JUMP_HEIGHT + GROUND_HEIGHT - P_HEIGHT / 2);
	//	break;
	//default:
	//	break;
	//}

	/*if (count % PLAYER_JUMP_SUMI <= 1 / P_JUMP_NUM) {
		image = PJump1;
	}
	else if (count % PLAYER_JUMP_SUMI <= 2 / P_JUMP_NUM) {
		image = PJump2;
	}
	else if (count % PLAYER_JUMP_SUMI <= 3 / P_JUMP_NUM) {
		image = PJump3;
	}
	else if (count % PLAYER_JUMP_SUMI <= P_JUMP_NUM) {
		image = PJump4;
	}*/
	
	if (count >= P_JUMP_NUM) {
		//stateFlag = 0;
		acceptFlag = true;
		bodyClock = count;
	}
	return 0;
}

int Player::SetAttack_w(int count) {
	bodyClock = count;
	stateFlag = 4;
	//image = PStand1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdateAttack_w(int count) {
	/*if (isRightFlag) {
		LU.Set(center.Get_x() - P_WIDTH*2.0/3, center.Get_y() - P_HEIGHT*2.0/2);
		RD.Set(center.Get_x() + P_WIDTH*1.5, center.Get_y() + P_HEIGHT / 2);
	}
	else {
		LU.Set(center.Get_x() - P_WIDTH*1.5, center.Get_y() - P_HEIGHT*2.0 / 2);
		RD.Set(center.Get_x() + P_WIDTH*2.0 / 3, center.Get_y() + P_HEIGHT / 2);
	}*/

	if (count < 2) {
		acceptFlag = 0;
	}
	else if (count < 7) {//15は強すぎ
		attack = 10;
		//attackArea.Set(LU, RD);
	}
	else if (count < 17) {
		attack = 0;
	}
	else if (count >= 17) {//モーション終わり
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

	/*if (count == 0) image = PAttackw1;
	if (count == 2) {
		image = PAttackw2;
		PlayAttack_w();
	}
	if (count == 5) image = PAttackw3;*/
	return 0;
}

int Player::SetAttack_s(int count) {
	bodyClock = count;
	stateFlag = 3;
	//image = PStand1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdateAttack_s(int count) {
	/*if (isRightFlag) {
		LU.Set(center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 4);
		RD.Set(center.Get_x() + P_WIDTH *3/2, center.Get_y() + P_HEIGHT / 4);
	}
	else {
		LU.Set(center.Get_x() - P_WIDTH * 3 / 2, center.Get_y() - P_HEIGHT/4);
		RD.Set(center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 4);
	}*/

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
	return 0;
}
int Player::SetDamage(int count) {
	bodyClock = count;
	stateFlag = 7;
	//image = PStand1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdateDamage(int count) {
	/*if (isRightFlag) {
	LU.Set(center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 4);
	RD.Set(center.Get_x() + P_WIDTH *3/2, center.Get_y() + P_HEIGHT / 4);
	}
	else {
	LU.Set(center.Get_x() - P_WIDTH * 3 / 2, center.Get_y() - P_HEIGHT/4);
	RD.Set(center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 4);
	}*/

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
		/*if (telepo_back.Getx() == 0 && telepo_back.Gety() == 0) {
			telepo_back = center;
		}
		else {
			center = telepo_back;
			telepo_back.Set(0, 0);
		}*/
		//telepo.Set(center.Getx() + P_TLP_RANGE * cos(CalcDir(R_THUMB_X, R_THUMB_Y)), center.Gety() + P_TLP_RANGE * -sin(CalcDir(R_THUMB_X, R_THUMB_Y)));
		telepo.Set(center.Getx() + P_TLP_RANGE * cos(CalcDir(THUMB_X, THUMB_Y)), center.Gety() + P_TLP_RANGE * -sin(CalcDir(THUMB_X, THUMB_Y)));
		isTelepo = true;
	}
	if (isTelepo && !LEFT) {
		center = telepo;
		isAir = true;
		isTelepo = false;
	}

	if (acceptFlag) {//入力受付時
		if (!isTelepo) {
			if (THUMB_X > 0) {
				if (isAir)
					velocity.Setx(P_SPEED / 1.5 /** THUMB_X / 100.0*/);
				else
					velocity.Setx(P_SPEED);
				isRightFlag = true;
			}
			else if (THUMB_X < 0) {
				if (isAir)
					velocity.Setx(-P_SPEED / 1.5 /** THUMB_X / 100.0*/);
				else
					velocity.Setx(-P_SPEED);
				isRightFlag = false;
			}
			else {
				velocity.Setx(0);
			}
		}
		else {
			velocity.Setx(0);
		}

		if (isAir) {//空中なら
			//if (B == 1) SetAirAttack();
			//printfDx("isAir\n");
		}
		else {//地上なら
			if (Y == 1) {
				SetJump(count);
				//printfDx("JUMP!");
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

int Player::Update2(SquareMng a) {//壁まわりの処理
	//DrawFormatString(40, 80, RED, "%d", weakAreaMng.isHitSquareMng(a));

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
					 SetStand(0);
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

	/*-----------テレポ処理---------------*/
	if (isTelepo) {
		for (int i = P_TLP_RANGE; i > 0; i--) {
			if (!a.isAbleTelepo(center, telepo)) {//テレポできなければ
				telepo.Set(center.Getx() + (double)(i) * cos(CalcDir(center, telepo)), center.Gety() + (double)(i) * -sin(CalcDir(center, telepo)));//もっと狭いとこに更新
				//telepo.Move(cos(CalcDir(center, telepo)), sin(-cos(CalcDir(center, telepo))));	
			}
		}
	}

	weakAreaMng.Delete();
	weakAreaMng.Add(center.Getx() - P_WEAK_LU_X, center.Gety() - P_WEAK_LU_Y, center.Getx() + P_WEAK_RD_X, center.Gety() + P_WEAK_RD_Y);

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
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		image,true);
	//else
	//	DrawModiGraph(
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		image, true);

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

	DrawFormatString(0, 120, RED, "P_state:%d ,a:%f",stateFlag,acceleration.Gety());
	//DrawFormatString(0, 0, RED, "P_state:%d,weaponFlag:%d,accept:%d", stateFlag, WeaponFlag,acceptFlag);
	

	return 0;
}