#include"Obj.h"
#include"Value.h"
#include<math.h>

int Dot::Set(double a, double b) {
	x = a;
	y = b;
	return 0;
}
int Dot::Setx(double a) {
	x = a;
	return 0;
}
int Dot::Sety(double a) {
	y = a;
	return 0;
}
int Dot::Getx() {
	return x;
}
int Dot::Gety() {
	return y;
}

/***************************************************************/

int Square::Set(Dot a, Dot b, Dot c, Dot d) {
	LU = a;
	RU = b;
	RD = c;
	LD = d;
	return 0;
}

Dot Square::GetLU() {
	return LU;
}
Dot Square::GetRU() {
	return RU;
}
Dot Square::GetRD() {
	return RD;
}
Dot Square::GetLD() {
	return LD;
}

/******************************************/
int Circle::Set(double a, double b, double c, double d) {
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
int Circle::Set(double a, double b) {
	center.Set(a, b);
	return 0;
}
int Circle::SetDir(double a) {
	dir = a;
	return 0;
}
int Circle::Move(double dx, double dy) {
	center.Setx(center.Getx() + dx);
	center.Sety(center.Gety() + dy);

	//if (dx > 0) dir = atan(dy / dx) /*+ PI*/;
	//else if (dx == 0 && dy >= 0)
	//	dir = 1 / 2 * PI;
	//else if (dx == 0 && dy <= 0)
	//	dir = 3 / 2 * PI;
	//else if (dx < 0) 
	//	dir = atan(dy / dx);
	if (dx == 0 && dy == 0) {
		return 0;
	}

	if (dx < 0) dir = atan(dy / dx) + PI;
	else if (dx == 0 && dy >= 0)
		dir = 3 / 2 * PI;
	else if (dx == 0 && dy <= 0)
		dir = PI / 2;
	else if (dx > 0) dir = atan(dy / dx);

	while (dir < 0) dir += 2 * PI;

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

