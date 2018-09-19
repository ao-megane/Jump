#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include<math.h>

int PWalk1;
int PWalk2;
int PWalk3;
int PWalk4;
int PWalk5;

int PRun1;
int PRun2;
int PRun3;
int PRun4;
int PRun5;

int PWalkW1;
int PWalkW2;
int PWalkW3;
int PWalkW4;
int PWalkW5;

int PRunW1;
int PRunW2;
int PRunW3;
int PRunW4;
int PRunW5;

int PJump1;
int PJump2;
int PJump3;
int PJump4;

int PAttacks1;
int PAttacks2;
int PAttacks3;

int PAttackw1;
int PAttackw2;
int PAttackw3;

int PAttackl1;
int PAttackl2;
int PAttackl3;

int FlyingSword;
int StuckingSword;

int Attack_w;
int Attack_s;
int Attack_l;
int PJump;
int PGet;

void Player::Initialize() {

	PWalk1 = LoadGraph("images/Player/walk/Resize/1.png");
	PWalk2 = LoadGraph("images/Player/walk/Resize/2.png");
	PWalk3 = LoadGraph("images/Player/walk/Resize/3.png");
	PWalk4 = LoadGraph("images/Player/walk/Resize/4.png");
	PWalk5 = LoadGraph("images/Player/walk/Resize/5.png");

	PRun1 = LoadGraph("images/Player/run/Resize/1.png");
	PRun2 = LoadGraph("images/Player/run/Resize/2.png");
	PRun3 = LoadGraph("images/Player/run/Resize/3.png");
	PRun4 = LoadGraph("images/Player/run/Resize/4.png");
	PRun5 = LoadGraph("images/Player/run/Resize/5.png");

	PWalkW1 = LoadGraph("images/Player/walksword/Resize/1.png");
	PWalkW2 = LoadGraph("images/Player/walksword/Resize/2.png");
	PWalkW3 = LoadGraph("images/Player/walksword/Resize/3.png");
	PWalkW4 = LoadGraph("images/Player/walksword/Resize/4.png");
	PWalkW5 = LoadGraph("images/Player/walksword/Resize/5.png");

	PRunW1 = LoadGraph("images/Player/runsword/Resize/1.png");
	PRunW2 = LoadGraph("images/Player/runsword/Resize/2.png");
	PRunW3 = LoadGraph("images/Player/runsword/Resize/3.png");
	PRunW4 = LoadGraph("images/Player/runsword/Resize/4.png");
	PRunW5 = LoadGraph("images/Player/runsword/Resize/5.png");

	PJump1 = LoadGraph("images/Player/Jump/Resize/1.png");
	PJump2 = LoadGraph("images/Player/Jump/Resize/2.png");
	PJump3 = LoadGraph("images/Player/Jump/Resize/3.png");
	PJump4 = LoadGraph("images/Player/Jump/Resize/4.png");

	PAttacks1 = LoadGraph("images/Player/Attack_s/Resize/1.png");
	PAttacks2 = LoadGraph("images/Player/Attack_s/Resize/2.png");
	PAttacks3 = LoadGraph("images/Player/Attack_s/Resize/3.png");

	PAttackw1 = LoadGraph("images/Player/Attack_w/Resize/1.png");
	PAttackw2 = LoadGraph("images/Player/Attack_w/Resize/2.png");
	PAttackw3 = LoadGraph("images/Player/Attack_w/Resize/3.png");

	PAttackl1 = LoadGraph("images/Player/attack_l/Resize/1.png");
	PAttackl2 = LoadGraph("images/Player/attack_l/Resize/2.png");
	PAttackl3 = LoadGraph("images/Player/attack_l/Resize/3.png");

	FlyingSword = LoadGraph("images/Player/attack_l/Resize/sword.png");
	StuckingSword = LoadGraph("images/Player/attack_l/Resize/sworddrop.png");;

	Attack_s = LoadSoundMem("music/knife2.wav");
	Attack_l = LoadSoundMem("music/knife.wav");
	Attack_w = LoadSoundMem("music/knife3.wav");
	PJump = LoadSoundMem("music/jump1.wav");
	PGet = LoadSoundMem("music/choice1.wav");

	//weakArea.Set(center, P_W_WIDTH, P_W_HEIGHT);
	attack = 0;
	Image = PWalk1;
	acceptFlag = 1;
	isRightFlag = 1;
	stateFlag = 0;
	bodyClock = 0;
	WeaponFlag = 1;
}

void Player::PlayAttack_l() {
	PlaySoundMem(Attack_l, DX_PLAYTYPE_BACK);
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
	Image = PWalk1;
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
	if(WeaponFlag == 0) Image = PWalk1;
	else if (WeaponFlag == 1) Image = PWalkW1;
}

void Player::UpdataStand(int count) {
	//center.Set(center.Get_x() - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
}

void Player::SetWalk() {
	stateFlag = 1;
	acceptFlag = 1;
	Image = PWalk1;
}
void Player::UpdataWalk(int count) {
	/*int speed = GROUND_SPEED;
	if (isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);*/
	int sum = 40;	//一周のフレーム数
	int num = 8;	//一周の画像数
	if (WeaponFlag == 0) {
		if (count % sum <= sum / num * 1) {
			Image = PWalk1;
		}
		else if (count % sum <= sum / num * 2) {
			Image = PWalk2;
		}
		else if (count % sum <= sum / num * 3) {
			Image = PWalk3;
		}
		else if (count % sum <= sum / num * 4) {
			Image = PWalk4;
		}
		else if (count % sum <= sum / num * 5) {
			Image = PWalk5;
		}
		else if (count % sum <= sum / num * 6) {
			Image = PWalk4;
		}
		else if (count % sum <= sum / num * 7) {
			Image = PWalk3;
		}
		else if (count % sum <= sum / num * 8) {
			Image = PWalk2;
		}
	}
	else {
		if (count % sum <= sum / num * 1) {
			Image = PWalkW1;
		}
		else if (count % sum <= sum / num * 2) {
			Image = PWalkW2;
		}
		else if (count % sum <= sum / num * 3) {
			Image = PWalkW3;
		}
		else if (count % sum <= sum / num * 4) {
			Image = PWalkW4;
		}
		else if (count % sum <= sum / num * 5) {
			Image = PWalkW5;
		}
		else if (count % sum <= sum / num * 6) {
			Image = PWalkW4;
		}
		else if (count % sum <= sum / num * 7) {
			Image = PWalkW3;
		}
		else if (count % sum <= sum / num * 8) {
			Image = PWalkW2;
		}
	}
}

void Player::SetDash() {
	stateFlag = 2;
	Image = PWalk1;
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
			Image = PRun1;
		}
		else if (count % sum <= sum / num * 2) {
			Image = PRun2;
		}
		else if (count % sum <= sum / num * 3) {
			Image = PRun3;
		}
		else if (count % sum <= sum / num * 4) {
			Image = PRun4;
		}
		else if (count % sum <= sum / num * 5) {
			Image = PRun5;
		}
		else if (count % sum <= sum / num * 6) {
			Image = PRun4;
		}
		else if (count % sum <= sum / num * 7) {
			Image = PRun3;
		}
		else if (count % sum <= sum / num * 8) {
			Image = PRun2;
		}
	}
	else {
		if (count % sum <= sum / num * 1) {
			Image = PRunW1;
		}
		else if (count % sum <= sum / num * 2) {
			Image = PRunW2;
		}
		else if (count % sum <= sum / num * 3) {
			Image = PRunW3;
		}
		else if (count % sum <= sum / num * 4) {
			Image = PRunW4;
		}
		else if (count % sum <= sum / num * 5) {
			Image = PRunW5;
		}
		else if (count % sum <= sum / num * 6) {
			Image = PRunW4;
		}
		else if (count % sum <= sum / num * 7) {
			Image = PRunW3;
		}
		else if (count % sum <= sum / num * 8) {
			Image = PRunW2;
		}
	}
}

void Player::SetJump() {
	stateFlag = 4;
	Image = PWalk1;
	acceptFlag = 1;	//空中制動
	PlayJump();
}
void Player::UpdataJump(int count,int flag) {
	//double height = DISP_HEIGHT * 0.3;//jumpの高さ
	//double sum = 50.0;	//モーションにかかるフレーム数
	//int num = 5;		//絵の枚数
	//double a =  -sin((count / PLAYER_JUMP_SUM)*PI) * height;//ほしい山
	//if (a > 0) a *= -1;
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

	//if (count % PLAYER_JUMP_SUMI <= PLAYER_JUMP_SUMI / PLAYER_JUMP_NUM * 1) {
	//	Image = PJump1;
	//}
	//else if (count % PLAYER_JUMP_SUMI <= PLAYER_JUMP_SUMI / PLAYER_JUMP_NUM * 2) {
	//	Image = PJump2;
	//}
	//else if (count % PLAYER_JUMP_SUMI <= PLAYER_JUMP_SUMI / PLAYER_JUMP_NUM * 3) {
	//	Image = PJump3;
	//}
	//else if (count % PLAYER_JUMP_SUMI <= PLAYER_JUMP_SUMI / PLAYER_JUMP_NUM * 4) {
	//	Image = PJump4;
	//}
	//
	//if (count >= PLAYER_JUMP_SUM) {
	//	stateFlag = 0;
	//	acceptFlag = 1;
	//	bodyClock = count;
	//}
}
void Player::SetPriJump() {
	stateFlag = 8;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
}
void Player::UpdataPriJump(int count) {
	if (count >= 15) {
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
}

void Player::SetAttack_w() {
	stateFlag = 6;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
}
void Player::UpdataAttack_w(int count) {
	Dot LU, RD;
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
		attackArea.Set(LU, RD);
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

	if (count == 0) Image = PAttackw1;
	if (count == 2) {
		Image = PAttackw2;
		PlayAttack_w();
	}
	if (count == 5) Image = PAttackw3;

}

void Player::SetAttack_s() {
	stateFlag = 5;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
}
void Player::UpdataAttack_s(int count) {
	Dot LU, RD;
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
		attackArea.Set(LU, RD);
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
	if (count == 0) Image = PAttacks1;
	if (count == 17) Image = PAttacks2;
	if (count == 19) Image = PAttacks3;
	if (count == 17)
		PlayAttack_s();
}

int dirKeeper;
void Player::SetAttack_l() {
	stateFlag = 7;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
	//WeaponFlag == 0 ? WeaponFlag = 1 : WeaponFlag = 0;
}
void Player::UpdataAttack_l(int count) {
	Dot LU, RD;
	/*if (isRightFlag) {
		LU.Set(center.Get_x() - SWORD_WIDTH / 2 + (count - 10) * 40, center.Get_y() - SWORD_HEIGHT / 2 );
		RD.Set(center.Get_x() + SWORD_WIDTH / 2 + (count - 10) * 40, center.Get_y() + SWORD_HEIGHT / 2 );
	}
	else {
		LU.Set(center.Get_x() - SWORD_WIDTH / 2 - (count - 10) * 40, center.Get_y() - SWORD_HEIGHT / 2 );
		RD.Set(center.Get_x() + SWORD_WIDTH / 2 - (count - 10) * 40, center.Get_y() + SWORD_HEIGHT / 2 );
	}*/

	if (count < 10) {//待機
		acceptFlag = 0;
		attack = 0;
	}
	else if (count < 40) {//攻撃
		attack = 60;
		attackArea.Set(LU, RD);
		//weapon.Set((LU.Get_x() + RD.Get_x()) / 2, (LU.Get_y() + RD.Get_y()) / 2);
		WeaponFlag = 0;
		dirKeeper = isRightFlag;
	}
	else if (count < 60) {//余韻
		
		//weapon.Set(weapon.Get_x(), GROUND_HEIGHT - SWORD_HEIGHT / 2);
		attack = 0;
	}
	else if (count >= 60) {//モーション終わり
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
	if (count < 7) Image = PAttackl1;
	else if (count < 9) Image = PAttackl2;
	else if (count < 10) Image = PAttackl3;
	else if (count < 60) Image = PWalk1;

	if (count == 10)
		PlayAttack_l();
}
Square Splayer;
Square Sweapon;
void Player::Updata(int count,int Key[]) {
	int flag = 4;//空中制御用フラグ
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

	if (X) {//姫ジャンプ
		/*if (stateFlag == 4) {
		IsJumping = bodyClock + 15;
		}
		else {
		IsJumping = 0;
		}
		if (stateFlag != 8)
		bodyClock = count;
		SetPriJump();*/
		PriJump = 1;
	}
	else {
		PriJump = 0;
	}
	
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
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X > 0) {//右歩き
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 1;
				isRightFlag = 1;
				/*if (stateFlag != 4)
					SetWalk();*/
			}
			if (THUMB_X <= -80) {//左ダッシュ
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count;
					SetDash();
				}
				flag = 2;
				isRightFlag = 0;
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X < 0) {//左歩き
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 3;
				isRightFlag = 0;
				/*if (stateFlag != 4)
					SetWalk();*/
			}
		}
	}

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
		UpdataJump(count - bodyClock, flag);
		break;
	case 5:
		UpdataAttack_s(count - bodyClock);
		break;
	case 6:
		UpdataAttack_w(count - bodyClock);
		break;
	case 7:
		UpdataAttack_l(count - bodyClock);
		break;
	case 8:
		UpdataPriJump(count - bodyClock);
		break;
	default:
		break;
	}

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
	//		Image,true);
	//else
	//	DrawModiGraph(
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() - P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() - P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		center.Get_x() + P_D_WIDTH / 2, center.Get_y() + P_D_HEIGHT / 2 + P_DIFF_H,
	//		Image, true);

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