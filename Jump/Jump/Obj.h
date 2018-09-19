#ifndef OBJH
#define OBJH
#include<math.h>

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
	double Set(double x, double y);			//左上、右下
	double Getx();
	double Gety();

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

class Square{//doubleDot2つ＋方向 中心は左の真ん中
public:
	int Set(Dot a, Dot b, double c);
	int Set(Dot a, Dot b);
	int Set(Dot a, int w, int h, double dir);
	int Set(int a, int b, int c, int d, double thita);
	int Getup();
	int Getleft();
	bool isHitCenter(double p_radius,double e_radius);
	Dot GetLU();
	Dot GetRD();
	int Draw(int colorHandle,double circleradius);
	void operator - (Dot a) {		//Squareのdot平行移動
		Set(LU - a, RD - a);
	};
	void operator - (int a) {		//Squareのx平行移動
		LU.Setx(LU.Getx() - a);
		RD.Setx(RD.Getx() - a);
	};
	bool operator & (Square a) {	//あたり判定演算子　true で重なってる
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Getx() < a.GetLU().Getx() || LU.Getx() > a.RD.Getx() ||
			LU.Gety() > a.GetRD().Gety() || RD.Gety() < a.LU.Gety())
			return false;
		else
			return true;
	};
	bool operator & (Circle a) ;

private:
	Dot LU;
	Dot RD;
	double dir;	//0~2PI
};



#endif // !OBJH
