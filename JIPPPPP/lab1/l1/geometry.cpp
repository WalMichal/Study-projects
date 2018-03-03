#include "geometry.h"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
double suma(deque  <Triangle> kolejka)
{
    double sumapomoc(0);
    for(int i(0);i<kolejka.size();i++)
    {
        sumapomoc+=kolejka[i].perimiter();
    }
    return sumapomoc;
}
double suma(vector <Prostokat> wektor)
{
    double sumapomoc(0);
    int i(0);
    while(wektor.size()>i)
    {
        sumapomoc=wektor[i].perimiter()+sumapomoc;
        i++;
    }

    return sumapomoc;
}

Point::Point(Point &z)
	{
		x = z.x;
		y = z.y;
	}
Point::Point() {};
Point::Point(double x,double y)
	{
	    this->x=x;
	    this->y=y;
	}
double Point::odleglosc(Point &b)
{
	return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}
///
/*
    Prostokat::Prostokat(const Prostokat & pros)
    {
        a = pros.a;
        b = pros.b;
        c = pros.c;
        d = pros.d;
    }
    */

    Prostokat::Prostokat(Point w, Point x, Point y, Point z) :a(w), b(x), c(y), d(z)
	{}
    double Prostokat::perimiter()
	{
		return a.odleglosc(b) + b.odleglosc(c) + c.odleglosc(d) + d.odleglosc(a);
	}
	double Prostokat::area()
	{
		return a.odleglosc(b)*b.odleglosc(c);
	}
	bool Prostokat::hasGreatArea(Prostokat & Pros)
	{
		double porownanie = Pros.area() - area();
		if (porownanie >= 0) return 0;
		if (porownanie < 0) return 1;

	}
    bool Prostokat::hasGreatArea(Triangle & Troj)
	{
		double porownanie = Troj.area() - area();
		if (porownanie >= 0) return 0;
		if (porownanie < 0) return 1;

	}
///
    Triangle::Triangle(){};
    Triangle::Triangle(Point x,Point y,Point z):a(x),b(y),c(z)
		{}
/*    Triangle::Triangle(const Triangle &troj)
    {
        a = troj.a;
        b = troj.b;
        c = troj.c;
    }
    */
	double Triangle::perimiter()
	{
		return a.odleglosc(b) + b.odleglosc(c) + c.odleglosc(c);
	}
	double Triangle::area()
	{
		double polobwodu = perimiter() * 0.5;
		return sqrt(polobwodu * (polobwodu - a.odleglosc(b)) * (polobwodu - b.odleglosc(c)) * (polobwodu - c.odleglosc(a)));
	}
	bool Triangle::hasGreatArea(Prostokat &Pros)
	{
		double porownanie = area() - Pros.area();
		if (porownanie > 0) return 1;
		if (porownanie <= 0) return 0;
	}
/*	bool Triangle::hasGreatArea(Triangle &Troj)
	{
		double porownanie = area() - Troj.area();
		if (porownanie > 0) return 1;
		if (porownanie <= 0) return 0;
	}
*/
