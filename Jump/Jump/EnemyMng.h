#ifndef ENEMY_MNG
#define ENEMY_MNG
#include"Obj.h"
#include"Effect.h"

class Enemy
{
public:
	int Initialize();
	bool GetisExist();
	int Set(int x, int y);
	int Set(int x, int y, double serchLUx, double serchLUy, double serchRDx, double serchRDy,int HP);
	int SetHP(int hp);
	int JudgeWall(SquareMng walls,double speed);
	int Draw();
	intSquareMng* GetattackMngAd();
	Dot* GetcenterAd();
	imageSquareMng* GetimageMngAd();
	SquareMng* GetweakMngAd();
	//SquareMng* GetsearchAreaAd();
	int End();
protected:
	bool isExist;
	bool isRight;
	int bodyClock;
	Dot center;
	Dot velocity;
	Dot acceleration;
	SquareMng search;
	imageSquareMng image;
	intSquareMng attackMng;
	SquareMng weakMng;
	int HP;
	int stateFlag;
	/*
	0 stand
	1 turn
	2 attack(?)
	3 damage
	4 broken
	*/
};

class Drawn : public Enemy{
public:
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int HP);
	int SetStand(int count);
	int SetTurn(int count);
	int SetDamage(int damage, int count);

	int Updata(int count, Dot Pcenter, SquareMng walls);
	int UpdataTurn(int count);
	int UpdataStand(int count,Dot Pcenter);//“®‚­‚±‚Æ‚Ì‚Ù‚¤‚ª‘½‚¢
	int UpdataDamage(int count);
	//int Draw();
private:

};
class Tank : public Enemy {
public:
	int Set(int x, int y, bool haveShield, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int HP);
	int SetStand(int count);
	int SetTurn(int count);
	int SetDamage(int damage, int count, Dot Pcenter);
	//int SetBroken(int count);
	
	int Updata(int count, Dot Pcenter,SquareMng walls);
	int UpdataTurn(int count);
	int UpdataStand(int count,Dot Pcenter);//“®‚­‚±‚Æ‚Ì‚Ù‚¤‚ª‘½‚¢
	int UpdataDamage(int count);
	//int Draw();
private:
	bool haveShield;
};

class Junk : public Enemy
{
public:
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy, int HP);
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
private:

};
class BrittleWall : public Enemy
{
public:
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy, int HP);
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
private:

};


int EnemyMngInitialize();
int EnemyMngSet(int stageFlag);
int EnemyMngUpdata(int count, Dot Pcenter,SquareMng walls);
int EnemyMngDamage(intSquareMng pattack,int count,Dot Pcenter);

SquareMng GetBriWall();

intSquare GetEAttackMng();

int EnemyMngDraw();


#endif // !ENEMY_MNG

