#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//ゲーム開始時（画像ハンドル周辺）

	int Set(int stageflag);			//プレイ開始時（座標周辺）

	int SetStand(int count);		//stand状態に入る関数
	int SetDash(int count);
	int SetJump(int count);
	int SetAttack_s(int count);
	int SetAttack_w(int count);
	int SetAttack_air(int count);
	int SetTelepo(int count);
	int SetDamage(int count);
	//int SetAttack_air(int count);
	//int SetKunai(int count);

	int Update1(int count, int key[]);	//入力周辺の処理
	int Update2(SquareMng a,int count);	//壁周辺の処理
	//int Update2(SquareMng a,imageSquareMng b);	//壁周辺の処理

	int UpdateStand(int count);		//stand状態中の処理,アニメーションや攻撃力の設定
	int UpdateDash(int count);
	int UpdateJump(int count);
	int UpdateAttack_s(int count);
	int UpdateAttack_w(int count);
	int UpdateAttack_air(int count);
	int UpdateTelepo(int count);
	int UpdateDamage(int count);
	//int UpdateAttack_air(int count);
	//int UpdateKunai(int count);

	int Addtelepo();

	int PlayAttacks();	//効果音
	int PlayAttackw();
	int PlayAttackair();
	int PlayJump();
	int PlayTelepo();
	int StopAll();

	int GetStateFlag();
	int GetIsRightFlag();
	Dot GetCenter();
	bool Getismuteki(int count);
	intSquareMng GetAttackAreaMng();
	SquareMng GetWeakAreaMng();
	Dot weapon;
	int GetAttack();
	int Draw();
	int End();

private:
	Dot center;			//中心座標
	Dot acceleration;	//加速度
	Dot velocity;		//速度
	Dot telepo_back;	//0,0以外ならテレポ先
	Dot telepo;

	SquareMng weakAreaMng;	//被ダメ範囲
	intSquareMng attackAreaMng;	//与ダメ範囲
	imageSquareMng image;

	//int attack;		//現在の攻撃力
	int bodyClock;		//アニメーション用体内時計
	int mutekiClock;	//無艇判定用
	int telepoGauge;	//テレポゲージ，100で一回テレポできる．最大290，一秒で１回復
	bool isRightFlag;	//向いてる方向フラグ（0で左 1で右）
	bool acceptFlag;	//入力受付フラグ（1で受付）
	bool isAir;			//空中か否かのフラグ
	bool isTelepo;		//テレポ中か否かのフラグ
	//bool onSquare;	//四角の上にいるか否かのフラグ
	
	int stateFlag;		//現状態フラグ
	/*
	0 stand
	1 dash
	2 jump
	3 attack_strong
	4 attack_weak
	5 attack_air
	6 telepo
	7 damage
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