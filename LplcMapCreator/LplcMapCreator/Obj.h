#ifndef OBJ_H
#define OBJ_H

class Dot{//int型の点
public:/*
	Dot();
	~Dot();*/
	int Setx(double x);
	int Sety(double y);
	int Set(double x,double y);			//左上、右下
	int Getx();
	int Gety();
	
	void operator = (Dot d) {		//Dotの代入
		x = d.Getx();
		y = d.Gety();
	};		
	Dot operator - (Dot d) {		//Dotの平行移動
		Dot a;
		a.x -= d.Getx();
		a.y -= d.Gety();
		return a;
	};		
private:
	double x;
	double y;
};

class Square{//Dot四つ いらない…いらなくない？
public:
	int Set(Dot a, Dot b,Dot c,Dot d);
	Dot GetLU();
	Dot GetRU();
	Dot GetRD();
	Dot GetLD();

private:
	Dot LU;
	Dot RU;
	Dot RD;
	Dot LD;
};

class Circle {//方向付き円
public:
	int Set(double x, double y, double range, double dir);
	int Set(Dot a, double range, double dir);
	int Set(double x, double y);
	int SetDir(double dir);
	int Move(double dx, double dy);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetDir();
	double GetRadius();
	void operator = (Dot a) {
		center = a;
	}
	//int Updata();

private:
	double radius;
	double dir;	//0~2PI
	Dot center;
};


#endif // !OBJ_H
