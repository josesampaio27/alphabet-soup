#include "pch.h"
#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::~Point()
{
}

Point::Point(int mx, int my)
{
	x = mx;
	y = my;
}

bool Point::SetX(int mx)
{
	if (mx >= 0) {
		this->x = mx;
		return true;
	}
	else
		return false;
}

bool Point::SetY(int my)
{
	if (my >= 0) {
		this->y = my;
		return true;
	}
	else
		return false;
}

bool Point::IsValid()
{
	if ((x >= 0) && (y >= 0))
		return 1;
	else
		return 0;
}

bool Point::Ask2Set()
{
	cout << "Int. Valor de 'X':";
	cin >> x;
	cout << "Int. Valor de 'Y':";
	cin >> y;

	return IsValid();
}

void Point::Show()
{
	cout << endl << "X = " << GetX() << endl;
	cout << "Y = " << GetY() << endl;
}

bool Point:: operator == (const Point P) const
{
	if ((this->GetX() == P.GetX()) && (this->GetY() == P.GetY()))
		return true;
	else
		return false;
}
