#ifndef ENEMY_MNG
#define ENEMY_MNG
#include"Obj.h"

class Enemy
{
public:
	int Initialize();
	bool GetisExist();
	int Set(int x, int y);
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy);
	int SetHP(int hp);
	int JudgeWall(SquareMng walls,double speed);
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
	imageSquareMng imageMng;
	intSquareMng attackMng;
	SquareMng weakMng;
	int HP;
	//SquareMng searchArea;
	int stateFlag;
	/*
	0 stand
	1 serch
	2 attack(?)
	3 damage
	*/
};

class Drawn : public Enemy
{
public:
	int Updata(int count, Dot Pcenter, SquareMng walls);
	int SetDamage(int damage,int count);
	int UpdataDamage(int count);
	int Draw();
private:

};
class Tank : public Enemy {
public:
	int Set(int x, int y, bool haveShield);
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
	int Draw();
private:
	bool haveShield;
};

class Junk : public Enemy
{
public:
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
	int Draw();
private:

};
class BrittleWall : public Enemy
{
public:
	int Updata(int count, Dot Pcenter);
	int SetDamage(int damage, int count);
	int UpdataDamage(int count);
	int Draw();
private:

};


int EnemyMngInitialize();
int EnemyMngSet(int stageFlag);
int EnemyMngUpdata(int count, Dot Pcenter,SquareMng walls);
int EnemyMngDamage(intSquareMng pattack,int count);

SquareMng GetBriWall();

intSquare GetEAttackMng();

int EnemyMngDraw();


#endif // !ENEMY_MNG

