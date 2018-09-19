#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	void Initialize();	//ゲーム開始時（画像ハンドル周辺）
	void PlayAttack_s();
	void PlayAttack_l();
	void PlayAttack_w();
	void PlayGet();
	void PlayJump();
	void Set(int levelFlag);			//プレイ開始時（座標周辺）
	void SetStand();		//privateをいじる関数
	void UpdataStand(int count);//ダッシュ中の座標やらをいじる関数
	void SetWalk();		
	void UpdataWalk(int count);
	void SetDash();
	void UpdataDash(int count);
	/*void SetGuard();
	void UpdataGuard(int count);*/
	void SetJump();
	void UpdataJump(int count,int flag);
	void SetPriJump();
	void UpdataPriJump(int count);
	void SetAttack_w();
	void UpdataAttack_w(int count);
	void SetAttack_s();
	void UpdataAttack_s(int count);
	void SetAttack_l();
	void UpdataAttack_l(int count);
	void Updata(int count,int key[]);
	int GetStateFlag();
	int GetIsRightFlag();
	Dot GetCenter();
	int WeaponFlag;
	Square GetAttackArea();
	Dot weapon;
	int GetAttack();
	int Draw();
	int PriJump;
	//int height;			//描画時のプレイヤー自体の高さ P_REAL_HEIGHT*P_RATIO
	//int width;
	int End();

private:
	Dot center;			//中心座標
	Square weakArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	//int jump;			
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int bodyClock;		//アニメーション用体内時計
	int IsJumping;		//jump中攻撃用flag
	int isRightFlag;	//向いてる方向フラグ（0で左 1で右）
	int acceptFlag;		//入力受付フラグ（1で受付）
	
	int stateFlag;		//現状態フラグ
	/*
	0 stand
	1 run
	2 dash
	3 guard
	4 jump
	5 attack_strong
	6 attack_weak
	7 attack_long
	8 princess_jump
	*/
	
};
//
//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}

#endif // !PLAYER_H