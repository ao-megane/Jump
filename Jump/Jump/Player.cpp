#include"Player.h"
#include"DxLib.h"
#include"Value.h"
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

void Player::Initialize() {
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
	image = PStand1;
	acceptFlag = 1;
	isRightFlag = 1;
	isAir = false;
	stateFlag = 0;
	bodyClock = 0;
	WeaponFlag = 1;
}

void Player::PlayAttack_s() {
	PlaySoundMem(Attack_s, DX_PLAYTYPE_BACK);
}
void Player::PlayJump() {
	PlaySoundMem(PJump, DX_PLAYTYPE_BACK);
}
void Player::PlayAttack_w() {
	PlaySoundMem(Attack_w, DX_PLAYTYPE_BACK);
}
void Player::PlayGet() {
	PlaySoundMem(PGet, DX_PLAYTYPE_BACK);
}
int Player::GetIsRightFlag() {
	return isRightFlag;
}
Dot Player::GetCenter() {
	return center;
}

void Player::Set(int levelFlag) {
	//if(levelFlag = 1)
	//center.Set(100, GROUND_HEIGHT - P_HEIGHT / 2);
	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	attack = 0;
	image = PStand1;
	acceptFlag = 1;
	IsJumping = 0;
	bodyClock = 0;
	isRightFlag = 1;
	WeaponFlag = 1;
	SetStand();
}

void Player::SetStand() {
	stateFlag = 0;
	acceptFlag = 1;
	image = PStand1;
}

void Player::UpdataStand(int count) {
	//center.Set(center.Get_x() - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
}

void Player::SetWalk() {
	stateFlag = 1;
	acceptFlag = 1;
	image = PStand1;
}
void Player::UpdataWalk(int count) {
	int sum = 40;	//一周のフレーム数
	int num = 8;	//一周の画像数
	/*if (count % sum <= sum / num * 1) {
		image = PStand1;
	}
	else if (count % sum <= sum / num * 2) {
		image = PWalk2;
	}
	else if (count % sum <= sum / num * 3) {
		image = PWalk3;
	}
	else if (count % sum <= sum / num * 4) {
		image = PWalk4;
	}
	else if (count % sum <= sum / num * 5) {
		image = PWalk5;
	}
	else if (count % sum <= sum / num * 6) {
		image = PWalk4;
	}
	else if (count % sum <= sum / num * 7) {
		image = PWalk3;
	}
	else if (count % sum <= sum / num * 8) {
		image = PWalk2;
	}*/
}

void Player::SetDash() {
	stateFlag = 2;
	image = PStand1;
	acceptFlag = 1;
}
void Player::UpdataDash(int count) {
	/*int speed = GROUND_SPEED + 9;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);*/
	int sum = 19;	//一周のフレーム数
	int num = 8;	//一周の画像数
	if (WeaponFlag == 0) {
		if (count % sum <= sum / num * 1) {
			image = PDash1;
		}
		else if (count % sum <= sum / num * 2) {
			image = PDash2;
		}
		else if (count % sum <= sum / num * 3) {
			image = PDash3;
		}
		else if (count % sum <= sum / num * 4) {
			image = PDash4;
		}
		else if (count % sum <= sum / num * 5) {
			image = PDash5;
		}
		else if (count % sum <= sum / num * 6) {
			image = PDash4;
		}
		else if (count % sum <= sum / num * 7) {
			image = PDash3;
		}
		else if (count % sum <= sum / num * 8) {
			image = PDash2;
		}
	}
}

void Player::SetJump(int count) {
	stateFlag = 4;
	image = PStand1;
	bodyClock = count;
	isAir = true;
	PlayJump();
}
void Player::UpdataJump(int count) {
	//printfDx("JUMPING");
	center.Sety(-sin((count / P_JUMP_NUM)*PI) * P_JUMP_HEIGHT + GROUND_HEIGHT);

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
		stateFlag = 0;
		acceptFlag = true;
		bodyClock = count;
		isAir = false;
	}
}

void Player::SetAttack_w() {
	stateFlag = 6;
	image = PStand1;
	acceptFlag = 0;
	attack = 0;
}
void Player::UpdataAttack_w(int count) {
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
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//戻す
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}

	if (count == 0) image = PAttackw1;
	if (count == 2) {
		image = PAttackw2;
		PlayAttack_w();
	}
	if (count == 5) image = PAttackw3;
}

void Player::SetAttack_s() {
	stateFlag = 5;
	image = PStand1;
	acceptFlag = 0;
	attack = 0;
}
void Player::UpdataAttack_s(int count) {
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
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//戻す
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	if (count == 0) image = PAttacks1;
	if (count == 17) image = PAttacks2;
	if (count == 19) image = PAttacks3;
	if (count == 17)
		PlayAttack_s();
}

int dirKeeper;
void Player::Updata(int count,int key[]) {
	//int flag = 4;//空中制御用フラグ
	//if (WeaponFlag == 0 && attack == 0) {
	//	weapon.Set(weapon.Get_x() - GROUND_SPEED, weapon.Get_y());
	//	Splayer.Set(center, P_WIDTH, P_HEIGHT);
	//	Sweapon.Set(weapon, STUKSWORD_WIDTH, STUKSWORD_HEIGHT);
	//	if (Splayer & Sweapon) {
	//		//printfDx("PICK!");
	//		PlayGet();
	//		WeaponFlag = 1;
	//	}
	//}

	//if (center.Gety() >= GROUND_HEIGHT) {//床
	//	isAir = false;
	//}
	//else {//空中
	//	isAir = true;
	//}

	if (acceptFlag) {//入力受付時
		if (isAir) {//空中なら
			//if (B == 1) SetAirAttack();
		}
		else {//地上なら
			if (Y == 1) {
				SetJump(count);
				printfDx("JUMP!");
			}
		}
	}
	/*
	if (acceptFlag) {//入力受付時の処理
		//だぶりありみたいなのはupdataでやるのが無難か
		if (A) {//遠距離攻撃
			if (WeaponFlag == 1) {
				if (stateFlag == 4) {
					IsJumping = bodyClock + 60;
				}
				else {
					IsJumping = 0;
				}
				if (stateFlag != 7)
					bodyClock = count;
				SetAttack_l();
			}
		}
		else if (B == 1) {//低威力広範囲攻撃
			if (WeaponFlag == 1) {
				if (stateFlag == 4) {
					IsJumping = bodyClock + 17;
				}
				else {
					IsJumping = 0;
				}
				if (stateFlag != 6)
					bodyClock = count;
				SetAttack_w();
			}
		}
		else if (Y) {//高威力小範囲攻撃
			if (WeaponFlag == 1) {
				if (stateFlag == 4) {
					IsJumping = bodyClock + 40;
				}
				else {
					IsJumping = 0;
				}
				if (stateFlag != 5)
					bodyClock = count;
				SetAttack_s();
			}
		}
		else if (abs(THUMB_Y) == 0 && abs(THUMB_X) == 0) {//立ち
			if (stateFlag != 0 && stateFlag != 4)bodyClock = count;
			flag = 4;
			if (stateFlag != 4)//ジャンプ中でなければ
				SetStand();
		}
		else {//攻撃はなくて移動なら
			if (THUMB_Y <= -80) {//ジャンプ
				if (stateFlag != 4) {
					bodyClock = count;
					IsJumping = count;
					SetJump();
					//printfDx("SETJUMP!!");
				}
			}
			//else if (THUMB_Y >= 80) {//ガード
			//	if (stateFlag != 3 && stateFlag != 4)bodyClock = count;
			//	//SetGuard();
			//}
			if (THUMB_X >= 80) {//右ダッシュ
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count;
					SetDash();
				}
				flag = 0;
				isRightFlag = 1;
				//if (stateFlag != 4)
					//SetDash();
			}
			else if (THUMB_X > 0) {//右歩き
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 1;
				isRightFlag = 1;
				//if (stateFlag != 4)
					//SetWalk();
			}
			if (THUMB_X <= -80) {//左ダッシュ
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count;
					SetDash();
				}
				flag = 2;
				isRightFlag = 0;
				//if (stateFlag != 4)
				//	SetDash();
			}
			else if (THUMB_X < 0) {//左歩き
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 3;
				isRightFlag = 0;
				//if (stateFlag != 4)
				//	SetWalk();
			}
		}
	}
	*/
	//printfDx("INN!!!!!");
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock);
		break;
	case 1:
		UpdataWalk(count - bodyClock);
		break;
	case 2:
		UpdataDash(count - bodyClock);
		break;
	case 3:
		//UpdataGuard(count - bodyClock);
		break;
	case 4:
		UpdataJump(count - bodyClock);
		break;
	case 5:
		UpdataAttack_s(count - bodyClock);
		break;
	case 6:
		UpdataAttack_w(count - bodyClock);
		break;
	default:
		break;
	}

	//if (center.Gety() >= DISP_HEIGHT - 50) {//床
	//	if (acceleration.Gety() > 0) acceleration.Sety(0);
	//	if (velocity.Gety() > 0) velocity.Sety(0);
	//	isAir = false;
	//}
	//else {//空中
	//	isAir = true;
	//	acceleration.Sety(acceleration.Gety() + GRAVITY);
	//}
	//velocity.Set(velocity.Getx() + acceleration.Getx(), velocity.Gety() + acceleration.Gety());
	//if (center.Gety() + velocity.Gety() >= DISP_HEIGHT - 50) {//着地
	//	center.Set(center.Getx() + velocity.Getx(), DISP_HEIGHT - 50);
	//}
	//else {
	//	center.Set(center.Getx() + velocity.Getx(), center.Gety() + velocity.Gety());
	//}
	

	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
}

int Player::GetStateFlag() {
	return stateFlag;
}
Square Player::GetAttackArea() {
	return attackArea;
}
int Player::GetAttack() {
	return attack;
}

int Player::Draw() {

	/*DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GREEN, false);*/
	/*DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GREEN, false);
	DrawBox(
		weakArea.Get_LU().Get_x(), weakArea.Get_LU().Get_y(),
		weakArea.Get_RD().Get_x(), weakArea.Get_RD().Get_y(),
		BLUE, false);*/

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

	DrawModiGraph(
		center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0,
		center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0,
		center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0,
		center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0,
		image, true
	);

	/*if(attack > 0)
		DrawBox(
			attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
			attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
			RED, false);*/

	//if (WeaponFlag == 0) {//武器を手放していたら剣を描画
	//	if(weapon.Get_y() >= GROUND_HEIGHT - SWORD_HEIGHT / 2)//刺さってるなら
	//		if(dirKeeper)
	//			DrawModiGraph(
	//				weapon.Get_x() - STUKSWORD_WIDTH / 2, weapon.Get_y() - STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + STUKSWORD_WIDTH / 2, weapon.Get_y() - STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + STUKSWORD_WIDTH / 2, weapon.Get_y() + STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - STUKSWORD_WIDTH / 2, weapon.Get_y() + STUKSWORD_HEIGHT / 2 + 0,
	//				StuckingSword, true);
	//		else
	//			DrawModiGraph(
	//				weapon.Get_x() + STUKSWORD_WIDTH / 2, weapon.Get_y() - STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - STUKSWORD_WIDTH / 2, weapon.Get_y() - STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - STUKSWORD_WIDTH / 2, weapon.Get_y() + STUKSWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + STUKSWORD_WIDTH / 2, weapon.Get_y() + STUKSWORD_HEIGHT / 2 + 0,
	//				StuckingSword, true);
	//	else
	//		if (dirKeeper)
	//			DrawModiGraph(
	//				weapon.Get_x() - SWORD_WIDTH / 2, weapon.Get_y() - SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + SWORD_WIDTH / 2, weapon.Get_y() - SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + SWORD_WIDTH / 2, weapon.Get_y() + SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - SWORD_WIDTH / 2, weapon.Get_y() + SWORD_HEIGHT / 2 + 0,
	//				FlyingSword, true);
	//		else
	//			DrawModiGraph(
	//				weapon.Get_x() + SWORD_WIDTH / 2, weapon.Get_y() - SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - SWORD_WIDTH / 2, weapon.Get_y() - SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() - SWORD_WIDTH / 2, weapon.Get_y() + SWORD_HEIGHT / 2 + 0,
	//				weapon.Get_x() + SWORD_WIDTH / 2, weapon.Get_y() + SWORD_HEIGHT / 2 + 0,
	//				FlyingSword, true);
	//}

	//DrawFormatString(0, 0, RED, "P_state : %2d ,accept : %2d,bodyClock : %5d,center.y : %5d",stateFlag,acceptFlag,bodyClock,center.Get_y());
	//DrawFormatString(0, 0, RED, "P_state:%d,weaponFlag:%d,accept:%d", stateFlag, WeaponFlag,acceptFlag);
	

	return 0;
}