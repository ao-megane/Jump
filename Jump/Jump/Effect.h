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
private:
	Dot velocity;
	Dot acceleration;
};

int EffectMngInitialize();

int Tlp_appearMngBorn(int count, Dot center);
int Tlp_disappearMngBorn(int count, Dot center);
int Drawn_disappearMngBorn(int count, Dot a);

int EffectMngUpdate(int count);
int EffectMngDelete();
int EffectMngDraw();

#endif // !EFFECT_H
