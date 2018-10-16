#include"Obj.h"
#include"Value.h"
#include"Chore.h"
#include<math.h>

int intDot::Set(int a, int b) {
	x = a;
	y = b;
	return 0;
}
int intDot::Setx(int a) {
	x = a;
	return 0;
}
int intDot::Sety(int a) {
	y = a;
	return 0;
}

int intDot::Getx() {
	return x;
}

int intDot::Gety() {
	return y;
}

/***************************************************************/
double Dot::Set(double a, double b) {
	x = a;
	y = b;
	return 0;
}
double Dot::Setx(double a) {
	x = a;
	return 0;
}
double Dot::Sety(double a) {
	y = a;
	return 0;
}
int Dot::Move(double ax, double ay) {
	x += ax;
	y += ay;
	return 0;
}
int Dot::Rotate(double thita) {
	double decoi = x;
	//x = Rotate(x, y);
	printfDx("Dot::Rotate 未実装！！");
	return 0;
}
double Dot::Getx() {
	return x;
}
double Dot::Gety() {
	return y;
}

/***************************************************************/

int Square::Set(Dot a,Dot b) {
	LU = a;
	RD = b;
	isExist = true;
	return 0;
}
int Square::Set(Dot a, double w, double h) {
	LU.Set(a.Getx() - w / 2, a.Gety() - h / 2);
	RD.Set(a.Getx() + w / 2, a.Gety() + h / 2);
	isExist = true;
	return 0;
}
int Square::SetLength(double x,double y, double w, double h) {
	LU.Set(x, y);
	RD.Set(x + w, y + h);
	isExist = true;
	return 0;
}
int Square::Set(double a, double b, double c, double d) {
	LU.Set(a, b);
	RD.Set(c, d);
	isExist = true;
	return 0;
}
int Square::Move(double x, double y) {
	LU.Set(LU.Getx() + x, LU.Gety() + y);
	RD.Set(RD.Getx() + x, RD.Gety() + y);
	return 0;
}
int Square::Move(Dot a) {
	LU.Set(LU.Getx() + a.Getx(), LU.Gety() + a.Gety());
	RD.Set(RD.Getx() + a.Getx(), RD.Gety() + a.Gety());
	return 0;
}
Square Square::GetMove(Dot a) {
	Square b;
	b.Set(LU.Getx() + a.Getx(), LU.Gety() + a.Gety(), RD.Getx() + a.Getx(), RD.Gety() + a.Gety());
	return b;
}
int Square::Rotate(double thita) {
	LU = RotateDot(thita, LU);
	RD = RotateDot(thita, RD);
	return 0;
}

int Square::isHitSquare(Square a,Dot velocity) {//二辺接地が未実装 -> velocityで実装
	bool L = false, R = false, U = false, D = false;
	if (*this & a) {
		if (LU.Gety() <= a.GetLU().Gety() && a.GetLU().Gety() <= RD.Gety()) {//下でぶつかってる(触れている)
			D = true;
		}
		if (LU.Getx() <= a.GetRD().Getx() && a.GetRD().Getx() <= RD.Getx()) {//左でぶつかってる(触れている)
			L = true;
		}
		if (LU.Gety() <= a.GetRD().Gety() && a.GetRD().Gety() <= RD.Gety()) {//上でぶつかってる(触れている)
			U = true;
		}
		if (LU.Getx() <= a.GetLU().Getx() && a.GetLU().Getx() <= RD.Getx()) {//右でぶつかってる(触れている)
			R = true;
		}
	}
	//プレイヤースクエアが壁を読んだ状態,a=wall
	//足元で釣っかかるので，上に載った優先
	if (D && L) {
		if (a.GetRD().Getx() <= GetLU().Getx() - velocity.Getx()) return 8;
		return 6;
		/*if (a.GetLU().Gety() <= GetRD().Gety() - velocity.Gety()) return 6;
		return 8;*/
	}
	if (D && R) {
		if (a.GetLU().Getx() >= GetRD().Getx() - velocity.Getx()) return 4;
		return 6;
		/*if (a.GetLU().Gety() <= GetRD().Gety() - velocity.Gety()) return 6;
		return 4;*/
	}
	if (U && L) {
		if (a.GetRD().Gety() <= GetLU().Gety() - velocity.Gety()) return 2;
		return 8;
	}
	if (U && R) {
		if (a.GetRD().Gety() <= GetLU().Gety() - velocity.Gety()) return 2;
		return 4;
	}
	if (D) return 6;
	if (U) return 2;
	if (R) return 4;
	if (L) return 8;
	return 0;
}

int Square::isHitSquare_tlp(Square a, Dot telepo, Dot center,Dot velocity) {//二辺接地が未実装 -> velocityで実装
	//テレポ先の四角.ishitsquare_tlp(壁，テレポ先のドット，テレポ前の中心)
	bool L = false, R = false, U = false, D = false;
	Dot decoi = telepo - center;	//プレイヤーから見てどの方向へ飛ぶか
	Dot RU, LD;
	Square decoi_squ;
	decoi_squ = a;
	if (decoi_squ & telepo) {	//壁とテレポ先がぶつかれば
		if (decoi.Getx() > 0 && decoi.Gety() > 0) {//第1象限
			/*RU.Set(decoi_squ.GetRD().Getx(), decoi_squ.GetLU().Gety());
			LD.Set(decoi_squ.GetLU().Getx(), decoi_squ.GetRD().Gety());
			decoi_squ.Set(LD, RU);*/
		}
		if (decoi.Getx() < 0 && decoi.Gety() > 0) {//第2象限
			//なにもなし
		}
		if (decoi.Getx() < 0 && decoi.Gety() < 0) {//第3象限
			/*RU.Set(decoi_squ.GetRD().Getx(), decoi_squ.GetLU().Gety());
			LD.Set(decoi_squ.GetLU().Getx(), decoi_squ.GetRD().Gety());
			decoi_squ.Set(LD, RU);*/
		}
		if (decoi.Getx() > 0 && decoi.Gety() < 0) {//第4象限
			//なにもなし
		}
	}

	//プレイヤースクエアが壁を読んだ状態,a=wall
	//足元で釣っかかるので，上に載った優先
	if (*this & decoi_squ) {
		if (LU.Gety() <= decoi_squ.GetLU().Gety() && decoi_squ.GetLU().Gety() <= RD.Gety()) {//下でぶつかってる(触れている)
			D = true;
		}
		if (LU.Getx() <= decoi_squ.GetRD().Getx() && decoi_squ.GetRD().Getx() <= RD.Getx()) {//左でぶつかってる(触れている)
			L = true;
		}
		if (LU.Gety() <= decoi_squ.GetRD().Gety() && decoi_squ.GetRD().Gety() <= RD.Gety()) {//上でぶつかってる(触れている)
			U = true;
		}
		if (LU.Getx() <= decoi_squ.GetLU().Getx() && decoi_squ.GetLU().Getx() <= RD.Getx()) {//右でぶつかってる(触れている)
			R = true;
		}
	}
	//プレイヤースクエアが壁を読んだ状態,a=wall
	//足元で釣っかかるので，上に載った優先
	if (D && L) {
		if (decoi_squ.GetRD().Getx() <= GetLU().Getx() - velocity.Getx()) return 8;
		return 6;
		/*if (a.GetLU().Gety() <= GetRD().Gety() - velocity.Gety()) return 6;
		return 8;*/
	}
	if (D && R) {
		if (decoi_squ.GetLU().Getx() >= GetRD().Getx() - velocity.Getx()) return 4;
		return 6;
		/*if (a.GetLU().Gety() <= GetRD().Gety() - velocity.Gety()) return 6;
		return 4;*/
	}
	if (U && L) {
		if (decoi_squ.GetRD().Gety() <= GetLU().Gety() - velocity.Gety()) return 2;
		return 8;
	}
	if (U && R) {
		if (decoi_squ.GetRD().Gety() <= GetLU().Gety() - velocity.Gety()) return 2;
		return 4;
	}
	if (D) return 6;
	if (U) return 2;
	if (R) return 4;
	if (L) return 8;
	return 0;
}

int Square::testDraw(int handle) {
	DrawBox(Square::GetLU().Getx(), Square::GetLU().Gety(), Square::GetRD().Getx(), Square::GetRD().Gety(), handle, false);
	//DrawLine(LU.Getx(), LU.Gety(), RD.Getx(), RD.Gety(), handle, false);
	return 0;
}
int Square::Delete() {
	isExist = false;
	return 0;
}
//Dot decoi_obj[4];
//Dot center_obj;
//int Square::Draw(int handle,double circleradius) {
//	center_obj.Set(LU.Getx() - circleradius, (RD.Gety() - LU.Gety()) / 2 + LU.Gety());
//	decoi_obj[0] = LU;
//	decoi_obj[0] = RotateDot(dir, decoi_obj[0], center_obj);
//
//	decoi_obj[1].Setx(RD.Getx());
//	decoi_obj[1].Sety(LU.Gety());
//	decoi_obj[1] = RotateDot(dir, decoi_obj[1], center_obj);
//
//	decoi_obj[2] = RD;
//	decoi_obj[2] = RotateDot(dir, decoi_obj[2], center_obj);
//
//	decoi_obj[3].Setx(LU.Getx());
//	decoi_obj[3].Sety(RD.Gety());
//	decoi_obj[3] = RotateDot(dir, decoi_obj[3], center_obj);
//
//	DrawLineByDot(decoi_obj[0], decoi_obj[1], handle);
//	DrawLineByDot(decoi_obj[1], decoi_obj[2], handle);
//	DrawLineByDot(decoi_obj[2], decoi_obj[3], handle);
//	DrawLineByDot(decoi_obj[3], decoi_obj[0], handle);
//
//	return 0;
//}


Dot Square::GetLU() {
	return LU;
}
Dot Square::GetRD() {
	return RD;
}
Dot* Square::GetLUAd() {
	return &LU;
}
Dot* Square::GetRDAd() {
	return &RD;
}

bool Square::GetisExist() {
	return isExist;
}
bool* Square::GetisExistAd() {
	return &isExist;
}
//double decoidist_obj;
//bool Square::operator & (Circle a) {
//	//平行移動
//	decoi_obj[0] = LU - a.GetDot();
//	decoi_obj[1].Set(RD.Getx() - a.Getx(), LU.Gety() - a.Gety());
//	decoi_obj[2] = RD - a.GetDot();
//	decoi_obj[3].Set(LU.Getx() - a.Getx(), RD.Gety() - a.Gety());
//	//回転
//	decoi_obj[0] = RotateDot(-dir, decoi_obj[0]);
//	decoi_obj[1] = RotateDot(-dir, decoi_obj[1]);
//	decoi_obj[2] = RotateDot(-dir, decoi_obj[2]);
//	decoi_obj[3] = RotateDot(-dir, decoi_obj[3]);
//	
//	/*DrawLineByDot(decoi_obj[0], decoi_obj[1], RED);
//	DrawLineByDot(decoi_obj[1], decoi_obj[2], RED);
//	DrawLineByDot(decoi_obj[2], decoi_obj[3], RED);
//	DrawLineByDot(decoi_obj[3], decoi_obj[0], RED);*/
//
//	//点判定
//	decoidist_obj = 10000000;
//	for (int i = 0; i < 4; i++) {
//		if (CalcDistance(decoi_obj[i]) < decoidist_obj) {
//			decoidist_obj = CalcDistance(decoi_obj[i]);
//		}
//	}
//	if (decoidist_obj < a.GetRadius()) return true;	//内側に点がある
//	//辺判定
//	if (decoi_obj[0].Getx() * decoi_obj[1].Getx() && decoi_obj[0].Gety() * decoi_obj[3].Gety()) {//四角の中に〇がある
//		return true;
//	}
//	else if (decoi_obj[0].Getx() * decoi_obj[1].Getx()) {//y軸を跨げば
//		if (abs(decoi_obj[0].Gety()) < a.GetRadius()) return true;
//		if (abs(decoi_obj[2].Gety()) < a.GetRadius()) return true;
//	}else if (decoi_obj[0].Getx() * decoi_obj[3].Getx()) {//x軸を跨げば
//		if (abs(decoi_obj[0].Getx()) < a.GetRadius()) return true;
//		if (abs(decoi_obj[3].Getx()) < a.GetRadius()) return true;
//	}
//	return false;
//}

//Dot decoi_obj2[4];
//bool Square::isHitCenter(double Pradius,double Eradius) {
//	//描画してるやつを写す
//	center_obj.Set(LU.Getx() - Eradius, (RD.Gety() - LU.Gety()) / 2 + LU.Gety());
//	decoi_obj[0] = LU;
//	decoi_obj[0] = RotateDot(dir, decoi_obj[0], center_obj);
//
//	decoi_obj[1].Setx(RD.Getx());
//	decoi_obj[1].Sety(LU.Gety());
//	decoi_obj[1] = RotateDot(dir, decoi_obj[1], center_obj);
//
//	decoi_obj[2] = RD;
//	decoi_obj[2] = RotateDot(dir, decoi_obj[2], center_obj);
//
//	decoi_obj[3].Setx(LU.Getx());
//	decoi_obj[3].Sety(RD.Gety());
//	decoi_obj[3] = RotateDot(dir, decoi_obj[3], center_obj);
//
//	//回転　プレイヤー(画面中央)中心
//	center_obj.Set(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
//	decoi_obj[0] = RotateDot(-dir, decoi_obj[0], center_obj);
//	decoi_obj[1] = RotateDot(-dir, decoi_obj[1], center_obj);
//	decoi_obj[2] = RotateDot(-dir, decoi_obj[2], center_obj);
//	decoi_obj[3] = RotateDot(-dir, decoi_obj[3], center_obj);
//
//	int i;
//	bool flag = true;
//	for (i = 0; i < 4; i++) {
//		if(flag)
//		for (int j = 0; j < 4; j++) {
//			if (decoi_obj[i].Getx() < decoi_obj[j].Getx() && decoi_obj[i].Gety() < decoi_obj[j].Gety()) {
//				decoi_obj2[0] = decoi_obj[i];
//				flag = false;
//				break;
//			}
//		}
//	}
//	decoi_obj2[1] = decoi_obj[(i + 1) % 4];
//	decoi_obj2[2] = decoi_obj[(i + 2) % 4];
//	decoi_obj2[3] = decoi_obj[(i + 3) % 4];
//
//	//平行移動（原点に持っていく）
//	for (i = 0; i < 4; i++) {
//		decoi_obj2[i] = decoi_obj2[i] - center_obj;
//	}
//
//	//点判定
//	decoidist_obj = 10000000;
//	for (int i = 0; i < 4; i++) {
//		if (CalcDistance(decoi_obj2[i],center_obj) < decoidist_obj) {
//			decoidist_obj = CalcDistance(decoi_obj2[i],center_obj);
//		}
//	}
//	if (decoidist_obj < Pradius) {
//		//printfDx("INNNER!!");
//		return true;	//内側に点がある
//	}
//	
//	//辺判定
//	if (decoi_obj2[0].Getx() * decoi_obj2[1].Getx() < 0 && decoi_obj2[0].Gety() * decoi_obj2[3].Gety() < 0) {//四角の中に〇がある
//		//printfDx("OUTER!!");
//		return true;
//	}
//	else if (decoi_obj2[0].Getx() * decoi_obj2[1].Getx() < 0) {//y軸を跨げば
//		if (abs(decoi_obj2[0].Gety()) < Pradius) return true;
//		if (abs(decoi_obj2[2].Gety()) < Pradius) return true;
//	}
//	else if (decoi_obj2[0].Getx() * decoi_obj2[3].Getx() < 0) {//x軸を跨げば
//		if (abs(decoi_obj2[0].Getx()) < Pradius) return true;
//		if (abs(decoi_obj2[3].Getx()) < Pradius) return true;
//	}
//	return false;
//}

/******************************************/
int Circle::Set(int a, int b, double c, double d) {
	center.Setx(a);
	center.Sety(b);
	radius= c;
	dir = d;
	return 0;
}
int Circle::Set(Dot a, double b, double c) {
	center = a;
	radius = b;
	dir = c;
	return 0;
}
int Circle::SetDir(double a){
	dir = a;
	return 0;
}
int Circle::Move(double dx, double dy) {
	center.Setx(center.Getx() + dx);
	center.Sety(center.Gety() + dy);
	return 0;
}
int Circle::MoveandTurn(double dx, double dy) {
	if (dx == 0 && dy == 0) return 0;
	center.Setx(center.Getx() + dx);
	center.Sety(center.Gety() + dy);

	if (dx < 0) dir = atan(-dy / dx) + PI;
	else if (dx == 0 && -dy >= 0)
		dir = 1 / 2 * PI;
	else if (dx == 0 && -dy <= 0)
		dir = 3 / 2 * PI;
	else if (dx > 0) dir = atan(-dy / dx);

	while (dir < 0) dir += 2 * PI;

	return 0;
}
int Circle::Move(Dot a) {
	center.Setx(center.Getx() + a.Getx());
	center.Sety(center.Gety() + a.Gety());
	return 0;
}
int Circle::MoveandTurn(Dot a) {
	if (a.Getx() == 0 && a.Gety() == 0) {
		return 0;
	}

	center.Setx(center.Getx() + a.Getx());
	center.Sety(center.Gety() + a.Gety());

	if (a.Getx() < 0) dir = atan(-a.Gety() / a.Getx()) + PI;
	else if (a.Getx() == 0 && -a.Gety() >= 0)
		dir = 1 / 2 * PI;
	else if (a.Getx() == 0 && -a.Gety() <= 0)
		dir = 3 / 2 * PI;
	else if (a.Getx() > 0) dir = atan(-a.Gety() / a.Getx());

	while (dir < 0) dir += 2 * PI;

	return 0;
}
int Circle::Back(double dx, double dy) {
	center.Setx(center.Getx() - dx);
	center.Sety(center.Gety() - dy);
	return 0;
}
Dot Circle::GetDot() {
	return center;
}
int Circle::Getx() {
	return center.Getx();
}
int Circle::Gety() {
	return center.Gety();
}
double Circle::GetDir() {
	return dir;
}
double Circle::GetRadius() {
	return radius;
}

int SquareMng::Initialize() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Set(0, 0, 0, 0);
		square[i].Delete();
	}
	return 0;
}
//int imageSquareMng::Born(Dot a,Dot b) {
//	for (int i = 0; i < SQU_NUM; i++) {
//		if (!square[i].GetisExist()) {//存在しなければ
//			square[i].Set(a, b);
//			break;
//		}
//	}
//	return 0;
//}
int SquareMng::Add(double a[], int num) {//numはSQU_NUMより小さいこと,numは四角の数
	for (int i = 0; i < num; i++) {
		//square[i].Set(a[4 * i], a[4 * i + 1], a[4 * i + 2], a[4 * i + 3]);
		square[i].SetLength(a[4 * i], a[4 * i + 1], a[4 * i + 2], a[4 * i + 3]);
	}
	return 0;
}
int SquareMng::Add(double a,double b,double c,double d) {//numはSQU_NUMより小さいこと,numは四角の数
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].GetisExist()) {
			square[i].Set(a,b,c,d);
			//printfDx("%d", i);
			break;
		}
	}
	return 0;
}
int SquareMng::Add(Square a) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].GetisExist()) {
			square[i].Set(a.GetLU(), a.GetRD());
			//printfDx("%d", i);
			break;
		}
	}
	return 0;
}
int SquareMng::Add(Dot a,Dot b) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].GetisExist()) {
			square[i].Set(a, b);
			//printfDx("%d", i);
			break;
		}
	}
	return 0;
}
int SquareMng::Move(double x, double y) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {//存在すれば
			square[i].Move(x, y);
		}
	}
	return 0;
}
Square SquareMng::GetSquare(int num) {
	if (square[num].GetisExist()) {
	}
	else {
		//printfDx("GETSQUAREERROR!!\n");
	}
	return square[num];
}
int SquareMng::isHitSquareMng(SquareMng a) {//
	bool L = false, R = false, U = false, D = false;
	printfDx("未実装！！！！！");
	/*for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {
			for (int j = 0; j < SQU_NUM; j++) {
				switch(square[i].isHitSquare(a.GetSquare(j),velocity)) {
				case 0:
					break;
				case 1:
					L = true;
					U = true;
					break;
				case 2:
					U = true;
					break;
				case 3:
					R = true;
					U = true;
					break;
				case 4:
					R = true;
					break;
				case 5:
					R = true;
					D = true;
					break;
				case 6:
					D = true;
					break;
				case 7:
					L = true;
					D = true;
					break;
				case 8:
					L = true;
					break;
				}
			}
		}
	}
	if (D && L) return 7;
	if (D && R) return 5;
	if (D) return 6;
	if (U && L) return 1;
	if (U && R) return 3;
	if (U) return 2;
	if (R) return 4;
	if (L) return 8;*/
	return 0;
}

double SquareMng::GetUP() {
	double a=0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {
			if (square[i].GetLU().Gety() > a)
				a = square[i].GetLU().Gety();
		}
	}
	return a;
}
double SquareMng::GetLanding(Square area) {//areaはSquareMngのどこに着地するか
	double a = DISP_HEIGHT*2.0;
	int b = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//四角が存在して
			//printfDx("%d",i);
			if (!(square[i].GetLU().Getx() > area.GetRD().Getx()) && !(area.GetLU().Getx() > square[i].GetRD().Getx())) {	//横方向判定
				//printfDx("2");
				if (square[i].GetLU().Gety() + 60 >= area.GetRD().Gety()) {	//縦方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
					//printfDx("3");
					if (square[i].GetLU().Gety() + 60 - area.GetRD().Gety() < a) {//近いやつ
						//square[i].testDraw(RED);
						a = square[i].GetLU().Gety() + 60 - area.GetRD().Gety();
						b = i;
					}
				}
			}
		}
	}
	return square[b].GetLU().Gety();
}
double SquareMng::GetUpLanding(Square area) {
	double a = DISP_HEIGHT;
	int b = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//四角が存在して
			if (!(square[i].GetLU().Getx() > area.GetRD().Getx()) && !(area.GetLU().Getx() > square[i].GetRD().Getx())) {	//横方向判定
				if (square[i].GetRD().Gety() - 30 <= area.GetLU().Gety()) {	//縦方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
					if (area.GetLU().Gety() - square[i].GetRD().Gety() + 30 < a) {//近いやつ
						a = area.GetLU().Gety() - square[i].GetRD().Gety() + 30;
						b = i;
					}
				}
			}
		}
	}
	return square[b].GetRD().Gety();
}
double SquareMng::GetLeftLanding(Square area) {
	double a = DISP_WIDTH;
	int b = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//四角が存在して
			if (!(square[i].GetLU().Gety() > area.GetRD().Gety()) && !(area.GetLU().Gety() > square[i].GetRD().Gety())) {	//縦方向判定
				if (square[i].GetRD().Getx() - P_SPEED - 30 <= area.GetLU().Getx()) {	//横方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
					if (area.GetLU().Getx() - square[i].GetLU().Getx() + P_SPEED + 30 < a) {//近いやつ
						a = area.GetLU().Getx() - square[i].GetLU().Getx() + P_SPEED + 30;
						//square[i].testDraw(RED);
						b = i;
					}
				}
			}
		}
	}
	return square[b].GetRD().Getx();
}
double SquareMng::GetRightLanding(Square area) {
	double a = DISP_WIDTH;
	int b = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//四角が存在して
			if (!(square[i].GetLU().Gety() > area.GetRD().Gety()) && !(area.GetLU().Gety() > square[i].GetRD().Gety())) {	//縦方向判定
				if (square[i].GetLU().Getx() + P_SPEED + 0 >= area.GetRD().Getx()) {	//横方向判定,RDはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
					if (square[i].GetLU().Getx() + P_SPEED + 0 - area.GetRD().Getx() < a) {//近いやつ
						a = square[i].GetLU().Getx() + P_SPEED  + 0 - area.GetRD().Getx();
						//square[i].testDraw(RED);
b = i;
					}
				}
			}
		}
	}
	return square[b].GetLU().Getx();
}

//double SquareMng::GetLanding_tlp(Square area) {//areaはSquareMngのどこに着地するか
//	double a = DISP_HEIGHT * 2.0;
//	int b = 0;
//	for (int i = 0; i < SQU_NUM; i++) {
//		if (square[i].GetisExist()) {	//四角が存在して
//			if (!(square[i].GetLU().Getx() > area.GetRD().Getx()) && !(area.GetLU().Getx() > square[i].GetRD().Getx())) {	//横方向判定
//				if (square[i].GetLU().Gety() + 60 >= area.GetRD().Gety()) {	//縦方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
//					if (square[i].GetLU().Gety() + 60 - area.GetRD().Gety() < a) {//近いやつ
//						a = square[i].GetLU().Gety() + 60 - area.GetRD().Gety();
//						b = i;
//					}
//				}
//			}
//		}
//	}
//	return square[b].GetLU().Gety();
//}
//double SquareMng::GetUpLanding_tlp(Square area) {
//	double a = DISP_HEIGHT;
//	int b = 0;
//	for (int i = 0; i < SQU_NUM; i++) {
//		if (square[i].GetisExist()) {	//四角が存在して
//			if (!(square[i].GetLU().Getx() > area.GetRD().Getx()) && !(area.GetLU().Getx() > square[i].GetRD().Getx())) {	//横方向判定
//				if (square[i].GetRD().Gety() - 60 <= area.GetLU().Gety()) {	//縦方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
//					if (area.GetLU().Gety() - square[i].GetRD().Gety() + 60 < a) {//近いやつ
//						a = area.GetLU().Gety() - square[i].GetRD().Gety() + 60;
//						b = i;
//					}
//				}
//			}
//		}
//	}
//	return square[b].GetRD().Gety();
//}
//double SquareMng::GetLeftLanding_tlp(Square area) {
//	double a = DISP_WIDTH;
//	int b = 0;
//	for (int i = 0; i < SQU_NUM; i++) {
//		if (square[i].GetisExist()) {	//四角が存在して
//			if (!(square[i].GetLU().Gety() >= area.GetRD().Gety()) && !(area.GetLU().Gety() >= square[i].GetRD().Gety())) {	//縦方向判定
//				if (square[i].GetRD().Getx() - 60 <= area.GetLU().Getx()) {	//横方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
//					if (area.GetLU().Getx() - square[i].GetLU().Getx() + 60 < a) {//近いやつ
//						a = area.GetLU().Getx() - square[i].GetLU().Getx() + 60;
//						//square[i].testDraw(RED);
//						b = i;
//					}
//				}
//			}
//		}
//	}
//	return square[b].GetRD().Getx();
//}
//double SquareMng::GetRightLanding_tlp(Square area) {//壁がテレポ先を読んでる
//	double a = DISP_WIDTH;
//	int b = 0;
//	for (int i = 0; i < SQU_NUM; i++) {
//		if (square[i].GetisExist()) {	//四角が存在して
//			if (!(square[i].GetLU().Gety() >= area.GetRD().Gety()) && !(area.GetLU().Gety() >= square[i].GetRD().Gety())) {	//縦方向判定
//				if (square[i].GetLU().Getx() + 60 >= area.GetRD().Getx()) {	//横方向判定,RDはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
//					if (square[i].GetLU().Getx() + 60 - area.GetRD().Getx() < a) {//近いやつ
//						a = square[i].GetLU().Getx() + 60 - area.GetRD().Getx();
//						//square[i].testDraw(RED);
//						b = i;
//					}
//				}
//			}
//		}
//	}
//	//printfDx("RIGHT!!!\n");
//	return square[b].GetLU().Getx();
//	//return 0;
//}

Dot SquareMng::SetTelepo(Dot center, Dot telepo,Square teleposqu) {
	telepo.Move(3 * cos(CalcDir(center, telepo)), 3 * -sin(CalcDir(center, telepo)));//ちょっと戻す(故意にぶつけなおす)
	Square decoi;
	Dot kakashi;//return 用
	Dot oritelepo;
	oritelepo = telepo;
	kakashi = telepo;
	//testDraw(RED);

	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//存在すれば
			decoi = square[i].GetMove(-center);
			telepo = oritelepo;
			if ((telepo - center).Getx() >= 0 && (telepo - center).Gety() <= 0) {//第一象限
				telepo.Set(teleposqu.GetRD().Getx(), teleposqu.GetLU().Gety());
				if (decoi.GetRD().Getx() >= 0 && decoi.GetLU().Gety() <= 0) {//判定対象
					 //decoi.testDraw(RED);
					if ((telepo - center).Getx() >= decoi.GetLU().Getx() && (telepo - center).Gety() <= decoi.GetRD().Gety()) {//雑判定
						if (CalcDir(decoi.GetLU()) >= CalcDir(center, telepo) && (CalcDir(decoi.GetRD()) <= CalcDir(center, telepo) || CalcDir(decoi.GetRD()) > PI / 2.0)) {//角度まで見る
							//ぶつかってれば
							//printfDx("a");
							if (CalcDir(decoi.GetRD()) > PI / 2.0){//縦長対応
								//printfDx("e");
								if (kakashi.Getx() > square[i].GetLU().Getx() - P_WEAK_LU_Y)
									kakashi.Setx(square[i].GetLU().Getx() - P_WEAK_LU_Y);
							}
							else if (CalcDir(decoi.GetLU().Getx(), decoi.GetRD().Gety()) >= PI / 2.0) {//横長対応
								if (kakashi.Gety() < square[i].GetRD().Gety() + P_WEAK_LU_Y)
									kakashi.Sety(square[i].GetRD().Gety() + P_WEAK_LU_Y);
							}
							else if (CalcDir(decoi.GetLU().Getx(), decoi.GetRD().Gety()) >= CalcDir(center, telepo)) {
								if(kakashi.Gety() < square[i].GetRD().Gety() + P_WEAK_LU_Y)
									kakashi.Sety(square[i].GetRD().Gety() + P_WEAK_LU_Y);
							}
							else {
								//printfDx("f");
								if(kakashi.Getx() > square[i].GetLU().Getx() - P_WEAK_LU_Y)
									kakashi.Setx(square[i].GetLU().Getx() - P_WEAK_LU_Y);
							}
						}
					}
				}
			}
			else if ((telepo - center).Getx() <= 0 && (telepo - center).Gety() <= 0) {//第二象限
				if (decoi.GetLU().Getx() <= 0 && decoi.GetLU().Gety() <= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() <= decoi.GetRD().Getx() && (telepo - center).Gety() <= decoi.GetRD().Gety()) {//雑判定
						if (CalcDir(decoi.GetLU().Getx(), decoi.GetRD().Gety()) >= CalcDir(center, telepo) && CalcDir(decoi.GetRD().Getx(), decoi.GetLU().Gety()) <= CalcDir(center, telepo)) {//角度まで見る
							//ぶつかってれば
						}
					}
				}
			}
			else if ((telepo - center).Getx() <= 0 && (telepo - center).Gety() >= 0) {//第三象限
				if (decoi.GetLU().Getx() <= 0 && decoi.GetRD().Gety() >= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() <= decoi.GetRD().Getx() && (telepo - center).Gety() >= decoi.GetLU().Gety()) {//雑判定
						if (CalcDir(decoi.GetRD()) >= CalcDir(center, telepo) && CalcDir(decoi.GetLU()) <= CalcDir(center, telepo)) {//角度まで見る
							//ぶつかってれば

						}
					}
				}
			}
			else if ((telepo - center).Getx() >= 0 && (telepo - center).Gety() >= 0) {//第四象限
				telepo.Set(teleposqu.GetRD().Getx(), teleposqu.GetRD().Gety());
				if (decoi.GetRD().Getx() >= 0 && decoi.GetRD().Gety() >= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() >= decoi.GetLU().Getx() && (telepo - center).Gety() >= decoi.GetLU().Gety()) {//雑判定
						if ((CalcDir(decoi.GetRD().Getx(), decoi.GetLU().Gety()) >= CalcDir(center, telepo) || CalcDir(decoi.GetRD().Getx(), decoi.GetLU().Gety()) <= PI / 2.0) && CalcDir(decoi.GetLU().Getx(), decoi.GetRD().Gety()) <= CalcDir(center, telepo)) {//角度まで見る
							//ぶつかってれば
							if (CalcDir(decoi.GetLU()) <= PI / 2.0) {//縦長対応
								//printfDx("a");
								if (kakashi.Getx() > square[i].GetLU().Getx() - P_WEAK_LU_Y)
									kakashi.Setx(square[i].GetLU().Getx() - P_WEAK_LU_Y);
							}
							else if (CalcDir(decoi.GetLU()) <= 3.0 / 2.0 * PI) {//横長対応
								//printfDx("b");
								if (kakashi.Gety() > square[i].GetLU().Gety() - P_WEAK_LU_Y)
									kakashi.Sety(square[i].GetLU().Gety() - P_WEAK_LU_Y);
							}
							else if (CalcDir(decoi.GetLU()) <= CalcDir(center, telepo)) {
								//printfDx("c");
								if (kakashi.Gety() > square[i].GetLU().Gety() - P_WEAK_LU_Y)
									kakashi.Sety(square[i].GetLU().Gety() - P_WEAK_LU_Y);
							}
							else {
								//printfDx("d");
								if(kakashi.Getx() > square[i].GetLU().Getx() - P_WEAK_LU_Y)
									kakashi.Setx(square[i].GetLU().Getx() - P_WEAK_LU_Y);
							}
						}
					}
				}
			}
		}
	}
	//printfDx("出来る！！！！\n");
	kakashi.Move(-3 * cos(CalcDir(center, telepo)), -3 * -sin(CalcDir(center, telepo)));//ちょっと戻す(故意にぶつけなおす)を戻す
	return kakashi;
}

bool SquareMng::isAbleTelepo(Dot center, Dot telepo) {
	Square decoi;
	Dot RU, LD;
	//testDraw(RED);

	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//存在すれば
			//square[i].testDraw(RED);
			decoi = square[i].GetMove(-center);
			//decoi.testDraw(GREEN);

			if ((telepo - center).Getx() >= 0 && (telepo - center).Gety() <= 0) {//第一象限
				if (decoi.GetRD().Getx() >= 0 && decoi.GetLU().Gety() <= 0) {//判定対象
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() >= decoi.GetLU().Getx() && (telepo - center).Gety() <= decoi.GetRD().Gety()) {//雑判定
						if (CalcDir(decoi.GetLU()) >= CalcDir(center, telepo) && (CalcDir(decoi.GetRD()) <= CalcDir(center, telepo) || CalcDir(decoi.GetRD()) > PI/2.0)) {//角度まで見る
							return false;
						}
					}
				}
			}
			else if ((telepo - center).Getx() <= 0 && (telepo - center).Gety() <= 0) {//第二象限
				if (decoi.GetLU().Getx() <= 0 && decoi.GetLU().Gety() <= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() <= decoi.GetRD().Getx() && (telepo - center).Gety() <= decoi.GetRD().Gety()) {//雑判定
						if (CalcDir(decoi.GetLU().Getx(),decoi.GetRD().Gety()) >= CalcDir(center, telepo) && CalcDir(decoi.GetRD().Getx(),decoi.GetLU().Gety()) <= CalcDir(center, telepo)) {//角度まで見る
							return false;
						}
					}
				}
			}
			else if ((telepo - center).Getx() <= 0 && (telepo - center).Gety() >= 0) {//第三象限
				if (decoi.GetLU().Getx() <= 0 && decoi.GetRD().Gety() >= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() <= decoi.GetRD().Getx() && (telepo - center).Gety() >= decoi.GetLU().Gety()) {//雑判定
						if (CalcDir(decoi.GetRD()) >= CalcDir(center, telepo) && CalcDir(decoi.GetLU()) <= CalcDir(center, telepo)) {//角度まで見る
							return false;
						}
					}
				}
			}
			else if ((telepo - center).Getx() >= 0 && (telepo - center).Gety() >= 0) {//第四象限
				if (decoi.GetRD().Getx() >= 0 && decoi.GetRD().Gety() >= 0) {
					//decoi.testDraw(RED);
					if ((telepo - center).Getx() >= decoi.GetLU().Getx() && (telepo - center).Gety() >= decoi.GetLU().Gety()) {//雑判定
						if ((CalcDir(decoi.GetRD().Getx(),decoi.GetLU().Gety()) >= CalcDir(center, telepo) || CalcDir(decoi.GetRD().Getx(), decoi.GetLU().Gety()) <= PI/2.0)&& CalcDir(decoi.GetLU().Getx(),decoi.GetRD().Gety()) <= CalcDir(center, telepo)) {//角度まで見る
							return false;
						}
					}
				}
			}
		}
	}
	//printfDx("出来る！！！！\n");
	return true;
}

int SquareMng::testDraw(int handle) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {//存在すれば
			square[i].testDraw(handle);
		}
	}
	return 0;
}
int SquareMng::Delete() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Delete();
	}
	return 0;
}

/*----------------------------------------------*/
int imageSquare::Setimage(int handle) {
	image = handle;
	return 0;
}
int imageSquare::Delete() {
	isExist = false;
	return 0;
}
SquareMng imageSquareMng::GetSquareMng() {
	SquareMng a;
	a.Initialize();
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].Square::GetisExist()) {
			a.Add(square[i].Square::GetLU(), square[i].Square::GetRD());
		}
	}
	return a;
}

int imageSquare::Draw() {
	if (*Square::GetisExistAd()) {
		DrawModiGraph(
			Square::GetLU().Getx(), Square::GetLU().Gety(),
			Square::GetRD().Getx(), Square::GetLU().Gety(),
			Square::GetRD().Getx(), Square::GetRD().Gety(),
			Square::GetLU().Getx(), Square::GetRD().Gety(),
			image, true
		);
	}
	return 0;
}
int imageSquare::Draw(bool isRight) {
	if (*Square::GetisExistAd()) {
		if (isRight) {
			DrawModiGraph(
				Square::GetLU().Getx(), Square::GetLU().Gety(),
				Square::GetRD().Getx(), Square::GetLU().Gety(),
				Square::GetRD().Getx(), Square::GetRD().Gety(),
				Square::GetLU().Getx(), Square::GetRD().Gety(),
				image, true
			);
		}
		else {
			DrawModiGraph(
				Square::GetRD().Getx(), Square::GetLU().Gety(),
				Square::GetLU().Getx(), Square::GetLU().Gety(),
				Square::GetLU().Getx(), Square::GetRD().Gety(),
				Square::GetRD().Getx(), Square::GetRD().Gety(),
				image, true
			);
		}
	}
	return 0;
}


int intSquare::Setvalue(int a) {
	value = a;
	isExist = true;
	return 0;
}
int intSquare::GetValue() {
	return value;
}
//int intSquare::Delete() {
//	isExist = false;
//	return 0;
//}

/*---------------------------------------------------*/
int imageSquareMng::SetWalls(int a[], int num, int stageflag,int square1_image,int square2_image,int square3_image,int square4_image) {//壁をセットするためだけの関数，Jumpでしか使えないかも
	switch (stageflag+1)
	{
	case 1:
	case 2:
	case 3:
		for (int i = 0; i < num; i++) {
			switch (a[i*3+2])
			{
			case 1:
				square[i].Square::SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE1_WIDTH, SQUARE1_HEIGHT);
				//DrawBox(a[i * 3 + 0], a[i * 3 + 1], a[i * 3 + 0] + SQUARE1_WIDTH, a[i * 3 + 1] + SQUARE1_HEIGHT, RED, true);
				//printfDx("%3d,%3d,%3d,%3d\n", a[i * 3 + 0], a[i * 3 + 1], SQUARE1_WIDTH, SQUARE1_HEIGHT);
				square[i].Setimage(square1_image);
				break;
			case 2:
				square[i].SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE2_WIDTH, SQUARE2_HEIGHT);
				square[i].Setimage(square2_image);
				break;
			case 3:
				square[i].SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE3_WIDTH, SQUARE3_HEIGHT);
				square[i].Setimage(square3_image);
				break;
			case 4:
				square[i].SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE4_WIDTH, SQUARE4_HEIGHT);
				square[i].Setimage(square4_image);
				break;
			case 5:
				square[i].SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE5_WIDTH, SQUARE5_HEIGHT);
				break;
			case 6:
				square[i].SetLength(a[i * 3 + 0], a[i * 3 + 1], SQUARE6_WIDTH, SQUARE6_HEIGHT);
				break;
			default:
				break;
			}
			//printfDx("SET!");
		}
		/*for (int i = 0; i < num+10; i++) {
			if(square[i].Square::GetisExist())
				printfDx("%3f,%3f\n", square[i].Square::GetLU().Getx(), square[i].Square::GetLU().Gety());
		}*/
		break;
	default:
		break;
	}
	return 0;
}
int imageSquareMng::Add(double a, double b, double c, double d, int handle) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (!*square[i].Square::GetisExistAd()) {
			square[i].Set(a, b, c, d);
			square[i].Setimage(handle);
			//printfDx("%d", i);
			break;
		}
	}
	return 0;
}
int imageSquareMng::Setimage(int num, int handle) {
	square[num].Setimage(handle);
	return 0;
}
int imageSquareMng::SetPosi(int num, double a, double b, double c, double d) {
	square[num].Set(a,b,c,d);
	return 0;
}
int imageSquareMng::Delete() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Delete();
	}
	return 0;
}
int imageSquareMng::Draw() {
	for (int i = 0; i < SQU_NUM; i++) {
		if (*square[i].Square::GetisExistAd()) {//存在すれば
			//DrawLine(square[i].GetLU().Getx(), square[i].GetLU().Gety(), square[i].GetRD().Getx(), square[i].GetRD().Gety(), RED);
			square[i].Square::testDraw(GREEN);
			square[i].Draw();
		}
	}
	return 0;
}
int imageSquareMng::Draw(bool isRight) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].Square::GetisExist()) {//存在すれば
			square[i].Square::testDraw(GREEN);
			square[i].Draw(isRight);
		}
	}
	return 0;
}

int intSquareMng::Initialize() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Set(0, 0, 0, 0);
		square[i].Square::Delete();
	}
	return 0;
}
SquareMng intSquareMng::GetSquareMng() {
	SquareMng a;
	a.Initialize();
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].Square::GetisExist()) {
			a.Add(square[i].Square::GetLU(), square[i].Square::GetRD());
		}
	}
	return a;
}
intSquare intSquareMng::GetintSquare(int num) {
	//if (square[num].Square::GetisExist())
		return square[num];
	//return;
}
int intSquareMng::isHitSquareMng(SquareMng a) {
	int max = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].Square::GetisExist()) {
			for (int j = 0; j < SQU_NUM; j++) {
				if (a.GetSquare(j).GetisExist()) {//両方存在すれば
					if (square[i] & a.GetSquare(j)) {
						if (square[i].GetValue() > max) {
							max = square[i].GetValue();
						}
					}
				}
			}
		}
	}
	return max;
}

int intSquareMng::Add(intSquare a) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].Square::GetisExist()) {
			square[i].Square::Set(a.Square::GetLU(), a.Square::GetRD());
			square[i].Setvalue(a.GetValue());
		}
	}
	return 0;
}
int intSquareMng::Add(double lux, double luy, double rdx, double rdy, int value) {
	for (int i = 0; i < SQU_NUM; i++) {
		//printfDx("aaaaaaa");
		if (!square[i].Square::GetisExist()) {
			square[i].Square::Set(lux, luy, rdx, rdy);
			//printfDx("aaaaaaa");
			square[i].Setvalue(value);
			break;
		}
		else {
			//printfDx("bbbbbbb");
		}
	}
	return 0;
}
int intSquareMng::Add(intSquareMng* a) {
	int j = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].Square::GetisExist()) {
			for (; j < SQU_NUM; j++) {
				if(a->GetintSquare(j).Square::GetisExist())
					square[i] = a->GetintSquare(j);
			}
		}
	}
	return 0;
}
int intSquareMng::testDraw(int colorhandle) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {//存在すれば
			//DrawLine(square[i].Square::GetLU().Getx(), square[i].Square::GetLU().Gety(), square[i].Square::GetRD().Getx(), square[i].Square::GetRD().Gety(), RED);
			square[i].testDraw(colorhandle);
			//square[i].Draw();
		}
	}
	return 0;
}
int intSquareMng::Delete() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Delete();
	}
	return 0;
}