#include"Effect.h"

int tlp_appear[4];
int tlp_disappear[4];

int Effect::Set(int count, Dot a) {
	image.Delete();
	isExist = true;
	bodyClock = count;
	center = a;
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, 0);
	return 0;
}
bool Effect::GetisExist() {
	return isExist;
}
int Effect::Delete() {
	isExist = false;
	return 0;
}
int Effect::Draw() {
	if (isExist)
		image.Draw();
	return 0;
}
Effect::Effect() {
	isExist = false;
	bodyClock = 0;
}

Effect::~Effect(){
}



int Tlp_appear::Update(int count) {
	//count -= Effect::bodyClock;
	for (int i = 0; i < 4; i++) {
		if (count - bodyClock < i) {
			image.Setimage(0, tlp_appear[i]);
			break;
		}
	}
	if (count - bodyClock >= 4) isExist = false;
	return 0;
}
int Tlp_disappear::Update(int count) {
	//count -= Effect::bodyClock;
	for (int i = 0; i < 4; i++) {
		if (count - bodyClock < i) {
			image.Setimage(0, tlp_disappear[i]);
			break;
		}
	}
	if (count - bodyClock >= 4) isExist = false;
	return 0;
}


int EffectMngInitialize() {
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/telepo_anim/";
		a += std::to_string(i + 1);
		a += ".png";
		tlp_appear[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/player/telepo_anim/";
		a += std::to_string(i + 1);
		a += ".png";
		tlp_disappear[3-i] = LoadGraph(a.c_str());
	}
	return 0;
}


Tlp_appear tlp_appe[4];
int Tlp_appearMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!tlp_appe[i].GetisExist()) {
			tlp_appe[i].Set(count, a);
		}
	}
	return 0;
}
Tlp_disappear tlp_disappe[4];
int Tlp_disappearMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!tlp_disappe[i].GetisExist()) {
			tlp_disappe[i].Set(count, a);
		}
	}
	return 0;
}

int EffectMngUpdate(int count) {
	for (int i = 0; i < 4; i++) {
		if (tlp_appe[i].GetisExist()) {
			tlp_appe[i].Update(count);
		}
		if (tlp_disappe[i].GetisExist()) {
			tlp_disappe[i].Update(count);
		}
	}
	return 0;
}

int EffectMngDelete() {
	for (int i = 0; i < 4; i++) {
		if (tlp_appe[i].GetisExist()) {
			tlp_appe[i].Effect::Delete();
		}
		if (tlp_disappe[i].GetisExist()) {
			tlp_disappe[i].Effect::Delete();
		}
	}
	return 0;
}

int EffectMngDraw() {
	for (int i = 0; i < 4; i++) {
		if (tlp_appe[i].GetisExist()) {
			tlp_appe[i].Draw();
		}
		if (tlp_disappe[i].GetisExist()) {
			tlp_disappe[i].Draw();
		}
	}
	return 0;
}
