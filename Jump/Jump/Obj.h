#ifndef OBJH
#define OBJH
#include<math.h>
#include"Value.h"

class intDot {//int�^�̓_
public:/*
	   Dot();
	   ~Dot();*/
	int Setx(int x);
	int Sety(int y);
	int Set(int x, int y);			//����A�E��
	int Getx();
	int Gety();

	void operator = (intDot d) {		//Dot�̑��
		x = d.Getx();
		y = d.Gety();
	};
	intDot operator - (intDot d) {		//Dot�̕��s�ړ�
		intDot a;
		a.x -= d.Getx();
		a.y -= d.Gety();
		return a;
	};
private:
	int x;
	int y;
};

class Dot {//double�^�̓_
public:/*
	Dot();
	~Dot();*/
	double Setx(double x);
	double Sety(double y);
	double Set(double x, double y);			//����A�E��
	double Getx();
	double Gety();
	int Move(double x, double y);

	void operator = (Dot d) {		//Dot�̑��
		x = d.Getx();
		y = d.Gety();
	};
	void operator -= (Dot d) {		//Dot�̕��s�ړ�
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
	Dot operator + (Dot d) {		//Dot�̕��s�ړ�
		Dot b;
		b.x = Getx() + d.Getx();
		b.y = Gety() + d.Gety();
		return b;
	};

private:
	double x;
	double y;
};

class Circle {//�����t���~
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

class Square{//doubleDot2��
public:
	int Set(Dot a, Dot b);
	int Set(Dot a, double w, double h);
	int SetLength(double x, double y, double w, double h);
	int Set(double a, double b, double c, double d);
	int Move(double x, double y);
	int isHitSquare(Square a);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:�������ĂȂ� 
	//int Getup();
	//int Getleft();
	//bool isHitCenter(double p_radius,double e_radius);
	Dot GetLU();
	Dot GetRD();
	bool GetisExist();
	int Delete();
	//int Draw(int colorHandle,double circleradius);
	int testDraw(int colorHandle);
	void operator - (Dot a) {		//Square��dot���s�ړ�
		Set(LU - a, RD - a);
	};
	void operator + (Dot a) {
		Set(LU + a, RD + a);
	};
	bool operator & (Square a) {	//�����蔻�艉�Z�q�@true �ŏd�Ȃ��Ă�
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return �������ĂȂ�
		if (RD.Getx() < a.GetLU().Getx() || LU.Getx() > a.RD.Getx() ||
			LU.Gety() > a.GetRD().Gety() || RD.Gety() < a.LU.Gety())
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
	int Draw();
private:
	int image;
};

class attackSquare : public Square
{
public:

private:
	int attack;
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
	double GetLanding(Square area);//�v���C���[������Ă����Ȏl�p��LU.Gety()��Ԃ�
	int isHitSquareMng(SquareMng a);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:�������ĂȂ�
	//int isHitSquareMng(SquareMng a,imageSquareMng b);//1:LU 2:U 3:RU 4:R 5:RD 6:D 7:LD 8:L 0:�������ĂȂ�
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
	
private:
	Square square[SQU_NUM];
};

class imageSquareMng : public SquareMng {
public:
	int SetWalls(int a[], int num, int stageflag, int square1_image, int square2_image, int square3_image);
	SquareMng GetSquareMng();
	int Draw();
private:
	imageSquare square[SQU_NUM];
};


#endif // !OBJH
