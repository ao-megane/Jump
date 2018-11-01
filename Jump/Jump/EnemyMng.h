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
	SquareMng GetweakMng();
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
	int mutekiClock;
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
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int level,bool isright);
	int SetStand(int count);
	int SetTurn(int count);
	int SetDamage(int damage, int count);

	int Updata(int count, Dot Pcenter, SquareMng walls);
	int UpdataTurn(int count);
	int UpdataStand(int count,Dot Pcenter);//ìÆÇ≠Ç±Ç∆ÇÃÇŸÇ§Ç™ëΩÇ¢
	int UpdataDamage(int count);
	//int Draw();
private:
	int level;
};
class Tank : public Enemy {
public:
	int Set(int x, int y, bool haveShield, int serchLUx, int serchLUy, int serchRDx, int serchRDy,int level,bool isright);
	int SetStand(int count);
	int SetTurn(int count);
	int SetDamage(int damage, int count, Dot Pcenter);
	//int SetBroken(int count);
	
	int Updata(int count, Dot Pcenter,SquareMng walls);
	int UpdataTurn(int count);
	int UpdataStand(int count,Dot Pcenter);//ìÆÇ≠Ç±Ç∆ÇÃÇŸÇ§Ç™ëΩÇ¢
	int UpdataDamage(int count);
	//int Draw();
private:
	bool haveShield;
	int level;
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
class DamageWall : public Enemy 
{
public:
	int Set(int x, int y,int clock, int HP);
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
private:
	int clock;//clockfñàÇ…èÛë‘Ç™êiÇﬁ
	int randam;//ÇøÇÂÇ¡Ç∆Ç∏ÇÁÇ∑
	int state;// 0 1 2 3(damage)
};


int EnemyMngInitialize();
int EnemyMngSet(int stageFlag);
int EnemyMngUpdata(int count, Dot Pcenter,SquareMng walls);
int EnemyMngDamage(intSquareMng pattack,int count,Dot Pcenter);

SquareMng GetBriWall();
SquareMng GetDamageWall();

intSquare GetEAttackMng();

int EnemyMngDraw();


#endif // !ENEMY_MNG

