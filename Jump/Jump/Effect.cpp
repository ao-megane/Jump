#include"Effect.h"

int Burn;

int tlp_appear[4];
int tlp_disappear[4];
int red_drawn_disappear[4];
int red_tank_haveS_disappear;
int red_tank_noS_disappear;
int blue_tank_haveS_disappear;
int blue_tank_noS_disappear;
int red_tank_haveS_junk[8];
int red_tank_noS_junk[8];
int blue_tank_haveS_junk[8];
int blue_tank_noS_junk[8];
int blue_drawn_disappear[4];
int blue_tank_disappear[8];
int expro[6];
int debri[4];
int reddebri[5];
int bluedebri[5];

int Effect::Set(int count, Dot a) {
	image.Delete();
	isExist = true;
	bodyClock = count;
	center = a;
	image.Add(center.Getx() - P_DRAW_WIDTH / 2.0, center.Gety() - P_DRAW_HEIGHT / 2.0, center.Getx() + P_DRAW_WIDTH / 2.0, center.Gety() + P_DRAW_HEIGHT / 2.0, 0);
	velocity.Set(0, 0);
	acceleration.Set(0, 0);
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

int playBurn() {
	PlaySoundMem(Burn, DX_PLAYTYPE_BACK);
	return 0;
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
int Drawn_disappear::Set(int count, Dot a, bool isright, int lev) {
	Effect::Set(count, a);
	isRight = isright;
	level = lev;
	return 0;
}
int Drawn_disappear::Update(int count) {
	for (int i = 0; i < 4; i++) {
		if ((count - bodyClock) % 4 < i) {
			if (level == 1) {
				image.Setimage(0, red_drawn_disappear[i]);
			}
			else if (level == 2) {
				image.Setimage(0, blue_drawn_disappear[i]);
			}
			break;
		}
	}
	if (count - bodyClock >= 300) isExist = false;
	
	acceleration.Set(0, GRAVITY*5);
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	if (velocity.Gety() > DRAWN_SPEED*100) velocity.Sety(DRAWN_SPEED*100);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0,center.Getx() - DRAWN_W_WIDTH / 2.0, center.Gety() - DRAWN_W_HEIGHT / 2.0,
		center.Getx() + DRAWN_W_WIDTH / 2.0, center.Gety() + DRAWN_W_HEIGHT / 2.0);
	return 0;
}
int Tank_disappear::Set(int count, Dot a, bool isright, int lev,bool haves) {
	Effect::Set(count, a);
	isRight = isright;
	level = lev;
	haveS = haves;

	double thita = GetRand() % 360;
	if (sin(thita * PI / 180.0) > 0)
		acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0)/3, P_JUMP_POWER * -sin(thita * PI / 180.0));
	else
		acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0)/3, P_JUMP_POWER * sin(thita * PI / 180.0));

	if (level == 1) {
		if (haveS) {
			image.Setimage(0, red_tank_haveS_disappear);
		}
		else {
			image.Setimage(0, red_tank_noS_disappear);
		}
	}
	else if (level == 2) {
		if (haveS) {
			image.Setimage(0, blue_tank_haveS_disappear);
		}
		else {
			image.Setimage(0, blue_tank_noS_disappear);
		}
	}

	return 0;
}
int Tank_disappear::Update(int count) {
	if (count - bodyClock >= 30000) isExist = false;
	
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - 128 / 2.0, center.Gety() - 128 / 2.0,
		center.Getx() + 128 / 2.0, center.Gety() + 128 / 2.0);

	acceleration.Set(0, GRAVITY*2);
	return 0;
}
int Tank_junk::Set(int count, Dot a, bool isright, int lev, bool haves) {
	Effect::Set(count, a);
	isRight = isright;
	level = lev;
	haveS = haves;
	
	return 0;
}
int Tank_junk::Update(int count) {
	for (int i = 0; i < 8; i++) {
		if ((count - bodyClock) % 8 < i) {
			if (level == 1) {
				if (haveS) {
					image.Setimage(0, red_tank_haveS_junk[i]);
				}
				else {
					image.Setimage(0, red_tank_noS_junk[i]);
				}
			}
			else if (level == 2) {
				if (haveS) {
					image.Setimage(0, blue_tank_haveS_junk[i]);
				}
				else {
					image.Setimage(0, blue_tank_noS_junk[i]);
				}
			}
			break;
		}
	}

	if (count - bodyClock >= 30000) isExist = false;
	image.SetPosi(0, center.Getx() - 192 / 2.0, center.Gety() - 192 / 2.0,
		center.Getx() + 192 / 2.0, center.Gety() + 192 / 2.0);

	return 0;
}
int Exprosion::Update(int count) {
	if (count - bodyClock == 0) {
		playBurn();
	}
	for (int i = 0; i < 6; i++) {
		if ((count - bodyClock) % 6 < i) {
			image.Setimage(0, expro[i]);
			break;
		}
	}

	if (count - bodyClock >= 6) isExist = false;

	//acceleration.Set(0, GRAVITY);
	//velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	//center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - 256 / 2.0, center.Gety() - 256 / 2.0,
		center.Getx() + 256 / 2.0, center.Gety() + 256 / 2.0);
	return 0;
}
int Debri::Update(int count) {
	acceleration.Set(0, GRAVITY);
	for (int i = 0; i < 4; i++) {
		if (count - bodyClock == 0) {//‰‰ñ‚È‚ç
			double thita = GetRand() % 360;
			if(sin(thita * PI / 180.0) > 0)
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			else
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			//printfDx("aaaaaaaaaa");
		}
		if ((count - bodyClock) % 4 < i) {
			image.Setimage(0, debri[i]);
			break;
		}
	}

	if (count - bodyClock >= 300) isExist = false;

	//acceleration.Move(0, GRAVITY);
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - 32 / 2.0, center.Gety() - 32 / 2.0,
		center.Getx() + 32 / 2.0, center.Gety() + 32 / 2.0);
	return 0;
}
int RedDebri::Update(int count) {
	acceleration.Set(0, GRAVITY);
	for (int i = 0; i < 5; i++) {
		if (count - bodyClock == 0) {//‰‰ñ‚È‚ç
			double thita = GetRand() % 360;
			if (sin(thita * PI / 180.0) > 0)
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			else
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			//printfDx("aaaaaaaaaa");
		}
		if ((count - bodyClock) % 5 < i) {
			image.Setimage(0, reddebri[i]);
			break;
		}
	}

	if (count - bodyClock >= 300) isExist = false;

	//acceleration.Move(0, GRAVITY);
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - 32 / 2.0, center.Gety() - 32 / 2.0,
		center.Getx() + 32 / 2.0, center.Gety() + 32 / 2.0);
	return 0;
}
int BlueDebri::Update(int count) {
	acceleration.Set(0, GRAVITY);
	for (int i = 0; i < 5; i++) {
		if (count - bodyClock == 0) {//‰‰ñ‚È‚ç
			double thita = GetRand() % 360;
			if (sin(thita * PI / 180.0) > 0)
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			else
				acceleration.Set(P_JUMP_POWER * cos(thita * PI / 180.0), P_JUMP_POWER * -sin(thita * PI / 180.0));
			//printfDx("aaaaaaaaaa");
		}
		if ((count - bodyClock) % 5 < i) {
			image.Setimage(0, bluedebri[i]);
			break;
		}
	}

	if (count - bodyClock >= 300) isExist = false;

	//acceleration.Move(0, GRAVITY);
	velocity.Move(acceleration.Getx(), acceleration.Gety());
	//if (velocity.Gety() > DRAWN_SPEED) velocity.Sety(DRAWN_SPEED);
	center.Move(velocity.Getx(), velocity.Gety());

	image.SetPosi(0, center.Getx() - 32 / 2.0, center.Gety() - 32 / 2.0,
		center.Getx() + 32 / 2.0, center.Gety() + 32 / 2.0);
	return 0;
}


Tlp_appear tlp_appe[4];
int Tlp_appearMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!tlp_appe[i].GetisExist()) {
			tlp_appe[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}
Tlp_disappear tlp_disappe[4];
int Tlp_disappearMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!tlp_disappe[i].GetisExist()) {
			tlp_disappe[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}
Drawn_disappear drawn_disappe[4];
int Drawn_disappearMngBorn(int count, Dot a,bool isright,int level) {
	for (int i = 0; i < 4; i++) {
		if (!drawn_disappe[i].GetisExist()) {
			drawn_disappe[i].Set(count, a, isright, level);
			return 0;
		}
	}
	return 0;
}
Tank_disappear tank_disappe[4];
int Tank_disappearMngBorn(int count, Dot a,bool isright,int level,bool haves) {
	for (int i = 0; i < 4; i++) {
		if (!tank_disappe[i].GetisExist()) {
			tank_disappe[i].Set(count, a,isright,level,haves);
			return 0;
		}
	}
	return 0;
}
Tank_junk tank_junk[4];
int Tank_junkMngBorn(int count, Dot a, bool isright, int level, bool haves) {
	for (int i = 0; i < 4; i++) {
		if (!tank_junk[i].GetisExist()) {
			tank_junk[i].Set(count, a, isright, level, haves);
			return 0;
		}
	}
	return 0;
}
Exprosion exprosion[4];
int ExprosionMngBorn(int count, Dot a) {
	for (int i = 0; i < 4; i++) {
		if (!exprosion[i].GetisExist()) {
			exprosion[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}
Debri debris[16];
int DebriMngBorn(int count, Dot a) {
	for (int i = 0; i < 16; i++) {
		if (!debris[i].GetisExist()) {
			debris[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}
RedDebri reddebris[16];
int RedDebriMngBorn(int count, Dot a) {
	for (int i = 0; i < 16; i++) {
		if (!reddebris[i].GetisExist()) {
			reddebris[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}
BlueDebri bluedebris[16];
int BlueDebriMngBorn(int count, Dot a) {
	for (int i = 0; i < 16; i++) {
		if (!bluedebris[i].GetisExist()) {
			bluedebris[i].Set(count, a);
			return 0;
		}
	}
	return 0;
}

int EffectMngInitialize() {
	Burn = LoadSoundMem("sounds/enemy/broken.wav");

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
		std::string a = "images/enemies/drawn/red/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		red_drawn_disappear[i] = LoadGraph(a.c_str());
	}
	/*for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/red/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		red_tank_disappear[i] = LoadGraph(a.c_str());
	}*/
	red_tank_haveS_disappear = LoadGraph("images/enemies/tank/red/shield/broken/junk.png");
	red_tank_noS_disappear = LoadGraph("images/enemies/tank/red/noshield/broken/junk.png");
	blue_tank_haveS_disappear = LoadGraph("images/enemies/tank/blue/shield/broken/junk.png");
	blue_tank_noS_disappear = LoadGraph("images/enemies/tank/blue/noshield/broken/junk.png");
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/drawn/blue/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		blue_drawn_disappear[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/blue/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		blue_tank_disappear[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 6; i++) {
		std::string a = "images/enemies/explo/explo/";
		a += std::to_string(i + 1);
		a += ".png";
		expro[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 4; i++) {
		std::string a = "images/enemies/explo/debri/";
		a += std::to_string(i + 1);
		a += ".png";
		debri[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 5; i++) {
		std::string a = "images/enemies/explo/reddebri/";
		a += std::to_string(i + 1);
		a += ".png";
		reddebri[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 5; i++) {
		std::string a = "images/enemies/explo/bluedebri/";
		a += std::to_string(i + 1);
		a += ".png";
		bluedebri[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/red/shield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		red_tank_haveS_junk[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/red/noshield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		red_tank_noS_junk[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/blue/shield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		blue_tank_haveS_junk[i] = LoadGraph(a.c_str());
	}
	for (int i = 0; i < 8; i++) {
		std::string a = "images/enemies/tank/blue/noshield/broken/";
		a += std::to_string(i + 1);
		a += ".png";
		blue_tank_noS_junk[i] = LoadGraph(a.c_str());
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
		if (exprosion[i].GetisExist()) {
			exprosion[i].Update(count);
		}
		if (tank_junk[i].GetisExist()) {
			tank_junk[i].Update(count);
		}
	}
	for (int i = 0; i < 16; i++) {
		if (debris[i].GetisExist()) {
			debris[i].Update(count);
		}
		if (reddebris[i].GetisExist()) {
			reddebris[i].Update(count);
		}
		if (bluedebris[i].GetisExist()) {
			bluedebris[i].Update(count);
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
		if (tank_junk[i].GetisExist()) {
			tank_junk[i].Effect::Delete();
		}
		if (exprosion[i].GetisExist()) {
			exprosion[i].Effect::Delete();
		}
	}
	for (int i = 0; i < 16; i++) {
		if (debris[i].GetisExist()) {
			debris[i].Effect::Delete();
		}
		if (reddebris[i].GetisExist()) {
			reddebris[i].Effect::Delete();
		}
		if (bluedebris[i].GetisExist()) {
			bluedebris[i].Effect::Delete();
		}
	}
	return 0;
}

int EffectMngDraw() {
	DrawGraph(100, 100, red_tank_haveS_junk[0], 1);
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
		if (tank_junk[i].GetisExist()) {
			tank_junk[i].Draw();
		}
		if (exprosion[i].GetisExist()) {
			exprosion[i].Draw();
		}
	}
	for (int i = 0; i < 16; i++) {
		if (debris[i].GetisExist()) {
			debris[i].Draw();
		}
		if (reddebris[i].GetisExist()) {
			reddebris[i].Draw();
		}
		if (bluedebris[i].GetisExist()) {
			bluedebris[i].Draw();
		}
	}
	return 0;
}
