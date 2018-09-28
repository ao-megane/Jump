#ifndef ENEMY_MNG
#define ENEMY_MNG
#include"Obj.h"

class Enemy
{
public:
	int Initialize();
	bool GetisExist();
	intSquareMng* GetAttackMngAd();
	Dot* GetcenterAd();
	imageSquareMng* GetimageMngAd();
	intSquareMng* GetattackMngAd();
	SquareMng* GetweakMngAd();
	SquareMng* GetsearchAreaAd();
	int End();
private:
	bool isExist;
	bool isRight;
	int bodyClock;
	Dot center;
	imageSquareMng imageMng;
	intSquareMng attackMng;
	SquareMng weakMng;
	SquareMng searchArea;
};

class Drawn : public Enemy
{
public:
	int Set(int x, int y, int serchLUx, int serchLUy, int serchRDx, int serchRDy);

	int Updata(int count,Dot Pcenter);
	int Draw();
private:

};

int EnemyMngInitialize();
int EnemyMngSet(int stageFlag);
int EnemyMngUpdata(int count, Dot Pcenter);

intSquare GetEAttackMng();

int EnemyMngDraw();


#endif // !ENEMY_MNG

