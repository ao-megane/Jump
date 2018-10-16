#ifndef OBJH
#define OBJH
#include<math.h>
#include"Value.h"

class intDot {//int型の点
public:/*
	   Dot();
	   ~Dot();*/
	int Setx(int x);
	int Sety(int y);
	int Set(int x, int y);			//左上、右下
	int Getx();
	int Gety();

	void operator = (intDot d) {		//Dotの代入
		x = d.Getx();
		y = d.Gety();
	};
	intDot operator - (intDot d) {		//Dotの平行移動
		intDot a;
		a.x -= d.Getx();
		a.y -= d.Gety();
		return a;
	};
private:
	int x;
	int y;
};

class Dot {//double型の点
public:/*
	Dot();
	~Dot();*/
	double Setx(double x);
	double Sety(double y);
	double Set(double x, double y);	//左上、右下
	double Getx();
	double Gety();
	int Move(double x, double y);
	int Rotate(double thita);

	void operator = (Dot d) {		//Dotの代入
		x = d.Getx();
		y = d.Gety();
	};
	void operator -= (Dot d) {		//Dotの平行移動
		x -= d.Getx();
		y -= d.Gety();
	};
	Dot operator - (Dot d) {
		Dot a;
		a.Set(x - d.Getx(), y - d.Gety());
		return a;
	}
	void operator -= (double b){
		x -= b;
		y -= b;
	}
	Dot operator - (double d) {
		Dot a;
		a.Set(x - d, y - d);
		return a;
	}
	Dot operator + (Dot d) {		//Dotの平行移動
		Dot b;
		b.x = Getx() + d.Getx();
		b.y = Gety() + d.Gety();
		return b;
	};
	Dot operator - () {
		Dot b;
		b.x = -x;
		b.y = -y;
		return b;
	}


private:
	double x;
	double y;
};

class Circle {//方向付き円
public:
	int Set(int x, int y, double range, double dir);
	int Set(Dot a, double range, double dir);
	int SetDir(double thita);
	int MoveandTurn(double dx, double dy);
	int Move(double dx, double dy);
	int MoveandTurn(Dot a);
	int Move(Dot a);
	int Back(double dx, double dy);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetDir();
	double GetRadius();
	//int Updata();
	bool operator & (Circle a) {
		if (sqrt(
			(center.Getx() - a.GetDot().Getx())*(center.Getx() - a.GetDot().Getx()) +
			(center.Gety() - a.GetDot().Gety())*(center.Gety() - a.GetDot().Gety())
			)
			<= radius + a.GetRadius())
			return true;
		else
			return false;
	};

private:
	double radius;
	double dir;	//0~2PI
	Dot center;
};

class Square{//doubleDot2つ
public:
	int Set(Dot a, Dot b);
	int Set(Dot a, double w, double h);
	int SetLength(double x, double y, double w, double h);
	int Set(double a, double b, double c, double d);
	int Move(double x, double y);
	int Move(Dot a);
	Square GetMove(Dot a);
	int Rotate(double thita);
	int isHitSquare(Square a,Dot velocity);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:当たってない 
	int isHitSquare_tlp(Square a,Dot telepo, Dot Pcenter,Dot velocity);
	//int Getup();
	//int Getleft();
	//bool isHitCenter(double p_radius,double e_radius);
	Dot GetLU();
	Dot GetRD();
	Dot* GetLUAd();
	Dot* GetRDAd();
	bool GetisExist();
	bool* GetisExistAd();
	int Delete();
	//int Draw(int colorHandle,double circleradius);
	int testDraw(int colorHandle);
	void operator - (Dot a) {		//Squareのdot平行移動
		Set(LU - a, RD - a);
	};
	void operator + (Dot a) {
		Set(LU + a, RD + a);
	};
	void operator = (Square a) {
		Set(a.GetLU(), a.GetRD());
	};
	bool operator & (Square a) {	//あたり判定演算子　true で重なってる
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Getx() < a.GetLU().Getx() || LU.Getx() > a.RD.Getx() ||
			LU.Gety() > a.GetRD().Gety() || RD.Gety() < a.LU.Gety())
			return false;
		else
			return true;
	};
	bool operator & (Dot a) {	//あたり判定演算子　true で重なってる
		//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Getx() < a.Getx() || LU.Getx() > a.Getx() ||
			LU.Gety() > a.Gety() || RD.Gety() < a.Gety())
			return false;
		else
			return true;
	};

protected:
	Dot LU;
	Dot RD;
	bool isExist;
};

class imageSquare : public Square
{
public:
	int Setimage(int image);
	int Delete();
	int Draw();
	int Draw(bool isRight);
private:
	int image;
};

class intSquare : public Square
{
public:
	int Setvalue(int value);
	int GetValue();
	//int Delete();
	int operator = (intSquare a) {
		printfDx("intSquareの=は怪しい\n");
		*Square::GetLUAd() = a.Square::GetLU();
		*Square::GetRDAd() = a.Square::GetRD();
		value = a.GetValue();
		return 0;
	};
private:
	int value;
};

class SquareMng	
{
public:
	int Initialize();
	//int Born(Dot a, Dot b);
	int Add(double a[], int num);
	int Add(double a, double b, double c, double d);
	int Add(Square a);
	int Add(Dot a, Dot b);
	int Move(double x, double y);
	Square GetSquare(int num);
	double GetLanding(Square area);//プレイヤーが乗ってそうな四角のLU.Gety()を返す
	double GetUpLanding(Square area);
	double GetLeftLanding(Square area);
	double GetRightLanding(Square area);
	//double GetLanding_tlp(Square area);//テレポ先をどうはじくか
	//double GetUpLanding_tlp(Square area);
	//double GetLeftLanding_tlp(Square area);
	//double GetRightLanding_tlp(Square area);
	Dot SetTelepo(Dot center, Dot telepo, Square teleposqu);
	bool isAbleTelepo(Dot center, Dot telepo);
	int isHitSquareMng(SquareMng a);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:当たってない
	//int isHitSquareMng(SquareMng a,imageSquareMng b);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:当たってない
	double GetUP();
	int testDraw(int colorHandle);
	int Delete();
	SquareMng operator + (SquareMng b) {
		SquareMng a;
		a.Initialize();
		for (int i = 0; i < SQU_NUM; i++) {
			if (square[i].GetisExist()) {
				a.Add(square[i]);
			}
		}
		for (int i = 0; i < SQU_NUM; i++) {
			if (b.GetSquare(i).GetisExist()) {
				a.Add(b.GetSquare(i));
			}
		}
		return a;
	}
	bool operator & (Dot a) {
		for (int i = 0; i < SQU_NUM; i++) {
			if (square[i].GetisExist()) {
				if (square[i] & a)
					return true;
			}
		}
		return false;
	};
private:
	Square square[SQU_NUM];
};

class imageSquareMng : public SquareMng {
public:
	int SetWalls(int a[], int num, int stageflag, int square1_image, int square2_image, int square3_image, int square4_image);
	SquareMng GetSquareMng();
	int Add(double a,double b,double c,double d,int handle);
	int Setimage(int num, int handle);
	int SetPosi(int num, double a, double b, double c, double d);
	int Delete();
	int Draw();
	int Draw(bool isRight);
private:
	imageSquare square[SQU_NUM];
};

class intSquareMng{
public:
	//int SetWalls(int a[], int num, int stageflag, int square1_image, int square2_image, int square3_image);
	int Initialize();
	int isHitSquareMng(SquareMng a);
	SquareMng GetSquareMng();
	int Add(intSquare a);
	int Add(intSquareMng* a);
	int Add(double lux, double luy, double rdx, double rdy, int value);
	intSquare GetintSquare(int num);
	int testDraw(int colorhandle);
	int Delete();
	int operator & (Dot a) {
		for (int i = 0; i < SQU_NUM; i++) {
			if (square[i].GetisExist()) {
				if (square[i] & a)
					return square[i].GetValue();
			}
		}
		return false;
	};
private:
	intSquare square[SQU_NUM];
};


#endif // !OBJH
