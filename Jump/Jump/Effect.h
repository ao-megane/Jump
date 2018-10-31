#pragma once
#ifndef EFFECT_H
#define EFFECT_H
#include"Value.h"
#include"Chore.h"
#include"Obj.h"

class Effect
{
public:
	int Set(int count, Dot a);
	bool GetisExist();
	int Draw();
	int Delete();
	Effect();
	~Effect();

protected:
	bool isExist;
	int bodyClock;
	imageSquareMng image;
	Dot center;
	Dot velocity;
	Dot acceleration;
	bool isRight;
};

class Tlp_appear : public Effect {
public:
	int Update(int count);
private:
	//const int width = P_DRAW_WIDTH;
	//const int height = P_DRAW_HEIGHT;
};
class Tlp_disappear : public Effect {
public:
	int Update(int count);
private:
	//const int width = P_DRAW_WIDTH;
	//const int height = P_DRAW_HEIGHT;
};

class Drawn_disappear : public Effect {
public:
	int Update(int count);
	int Set(int count, Dot a, bool isright, int lev);
private:
	int level;
	
};

class Tank_disappear : public Effect {
public:
	int Update(int count);
private:
	bool isRight;
	bool haveS;
	int level;
	//Dot velocity;
	//Dot acceleration;
};

class Exprosion : public Effect {
public :
	int Update(int count);
private:
};

class Debri : public Effect {
public:
	int Update(int count);
private:
};
class RedDebri : public Effect {
public:
	int Update(int count);
private:
};
class BlueDebri : public Effect {
public:
	int Update(int count);
private:
};

int EffectMngInitialize();

int Tlp_appearMngBorn(int count, Dot center);
int Tlp_disappearMngBorn(int count, Dot center);
int Drawn_disappearMngBorn(int count, Dot a, bool isright, int level);
int Tank_disappearMngBorn(int count, Dot a, bool isright, int level);
int ExprosionMngBorn(int count, Dot a);
int DebriMngBorn(int count, Dot a);
int RedDebriMngBorn(int count, Dot a);
int BlueDebriMngBorn(int count, Dot a);

int EffectMngUpdate(int count);
int EffectMngDelete();
int EffectMngDraw();

#endif // !EFFECT_H
