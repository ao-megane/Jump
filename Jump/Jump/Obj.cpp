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
int Square::isHitSquare(Square a) {//二辺接地が未実装
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
	if (D && L) return 7;
	if (D && R) return 5;
	if (D) return 6;
	if (U && L) return 1;
	if (U && R) return 3;
	if (U) return 2;
	if (R) return 4;
	if (L) return 8;
	return 0;
}
int Square::testDraw(int handle) {
	DrawBox(LU.Getx(), LU.Gety(), RD.Getx(), RD.Gety(), handle, false);
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
bool Square::GetisExist() {
	return isExist;
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

int imageSquareMng::Initialize() {
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
int imageSquareMng::Born(double a[], int num) {//numはSQU_NUMより小さいこと,numは四角の数
	for (int i = 0; i < num; i++) {
		//square[i].Set(a[4 * i], a[4 * i + 1], a[4 * i + 2], a[4 * i + 3]);
		square[i].SetLength(a[4 * i], a[4 * i + 1], a[4 * i + 2], a[4 * i + 3]);
	}
	return 0;
}
int imageSquareMng::Born(double a,double b,double c,double d) {//numはSQU_NUMより小さいこと,numは四角の数
	for (int i = 0; i < SQU_NUM; i++) {
		if (!square[i].GetisExist()) {
			square[i].Set(a,b,c,d);
			//printfDx("%d", i);
			break;
		}
	}
	return 0;
}
int imageSquareMng::Move(double x, double y) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {//存在すれば
			square[i].Move(x, y);
		}
	}
	return 0;
}
Square imageSquareMng::GetSquare(int num) {
	if (square[num].GetisExist()) {
	}
	else {
		//printfDx("GETSQUAREERROR!!\n");
	}
	return square[num];
}
int imageSquareMng::isHitSquareMng(imageSquareMng a) {//
	bool L = false, R = false, U = false, D = false;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {
			for (int j = 0; j < SQU_NUM; j++) {
				switch(square[i].isHitSquare(a.GetSquare(j))) {
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
	if (L) return 8;
	return 0;
}
double imageSquareMng::GetUP() {
	double a=0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {
			if (square[i].GetLU().Gety() > a)
				a = square[i].GetLU().Gety();
		}
	}
	return a;
}
double imageSquareMng::GetLanding(Square area) {//areaはSquareMngのどこに着地するか
	double a = DISP_HEIGHT;
	int b = 0;
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {	//四角が存在して
			//printfDx("%d",i);
			if (!(square[i].GetLU().Getx() >= area.GetRD().Getx()) && !(area.GetLU().Getx() >= square[i].GetRD().Getx())) {	//横方向判定
				//printfDx("2");
				if (square[i].GetLU().Gety() >= area.GetLU().Gety()) {	//縦方向判定,LUはめりこみ対策，うまくいかなければ再考(RDからmarginでやるか)
					//printfDx("3");
					if (square[i].GetLU().Gety() - area.GetRD().Gety() < a) {//近いやつ
						//square[i].testDraw(RED);
						a = square[i].GetLU().Gety() - area.GetRD().Gety();
						b = i;
					}
				}
			}
		}
	}
	return square[b].GetLU().Gety();
}
int imageSquareMng::testDraw(int handle) {
	for (int i = 0; i < SQU_NUM; i++) {
		if (square[i].GetisExist()) {//存在すれば
			square[i].testDraw(handle);
		}
	}
	return 0;
}
int imageSquareMng::Delete() {
	for (int i = 0; i < SQU_NUM; i++) {
		square[i].Delete();
	}
	return 0;
}