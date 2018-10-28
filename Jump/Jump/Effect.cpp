#include"Effect.h"

int tlp_appear[4];
int tlp_disappear[4];
int drawn_disappear[4];
int tank_disappear[8];

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
int Drawn_disappear::Update(int count) {
	for (int i = 0; i < 4; i++) {
		if ((count - bodyClock) % 4 < i) {
			image.Setimage(0, drawn_disappear[i]);
			break;
		}
	}
	if (count - bodyClock >= 300) isExist = false;
	
	acceleration.Set(0, GRAVITY);
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0,center.Getx() - DRAWN_W_WIDTH / 2.0, center.Gety() - DRAWN_W_HEIGHT / 2.0,
		center.Getx() + DRAWN_W_WIDTH / 2.0, center.Gety() + DRAWN_W_HEIGHT / 2.0);
	return 0;
}
int Tank_disappear::Update(int count) {
	for (int i = 0; i < 8; i++) {
		if ((count - bodyClock) % 8 < i) {
			image.Setimage(0, tank_disappear[i]);
			break;
		}
	}

	if (count - bodyClock >= 300) isExist = false;

	//acceleration.Set(0, GRAVITY);
	//velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	//center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - TANK_W_WIDTH / 2.0, center.Gety() - TANK_W_HEIGHT / 2.0,
		center.Getx() + TANK_W_WIDTH / 2.0, center.Gety() + TANK_W_HEIGHT / 2.0);
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
Drawn_disappear drawn_disappe[4];
int Drawn_disappearMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!drawn_disappe[i].GetisExist()) {
			drawn_disappe[i].Set(count, a);
		}
	}
	return 0;
}
Tank_disappear tank_disappe[4];
int Tank_disappearMngBorn(int count, Dot a) {
	for (int i = 0; i < 8; i++) {
		if (!tank_disappe[i].GetisExist()) {
			tank_disappe[i].Set(count, a);
		}
	}
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
		tlp_disappear[3 - i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/drawn/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		drawn_disappear[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		tank_disappear[i] = LoadGraph(a.c_str());
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
		if (drawn_disappe[i].GetisExist()) {
			drawn_disappe[i].Update(count);
		}
		if (tank_disappe[i].GetisExist()) {
			tank_disappe[i].Update(count);
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
		if (drawn_disappe[i].GetisExist()) {
			drawn_disappe[i].Effect::Delete();
		}
		if (tank_disappe[i].GetisExist()) {
			tank_disappe[i].Effect::Delete();
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
		if (drawn_disappe[i].GetisExist()) {
			drawn_disappe[i].Draw();
		}
		if (tank_disappe[i].GetisExist()) {
			tank_disappe[i].Draw();
		}
	}
	return 0;
}
