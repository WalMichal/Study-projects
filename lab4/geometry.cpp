#include "geometry.h"
#include <iostream>
#include <vector>
#include <deque>
///Other:
using namespace std;
double sum(vector  <Polygon *> wector)
{
    double sumhelp(0);
    for(int i(0);i<wector.size();i++)
    {
        sumhelp+=wector[i]->perimiter();
    }
    return sumhelp;
}
/*
double sum(vector <Rectangle> wektor)
{
    double sumhelp(0);
    int i(0);
    while(wektor.size()>i)
    {
        sumhelp=wektor[i].perimiter()+sumhelp;
        i++;
    }

    return sumhelp;
}
*/
/// Point:
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
double Point::distance(Point &b)
{
	return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}
/// Rectangle:
    Rectangle::Rectangle(){};
    Rectangle::Rectangle(Point w, Point x, Point y, Point z) :pa(w), pb(x), pc(y), pd(z)
	{}
    double Rectangle::perimiter()
	{
		return pa.distance(pb) + pb.distance(pc) + pc.distance(pd) + pd.distance(pa);
	}
	double Rectangle::area()
	{
		return pa.distance(pb)*pb.distance(pc);
	}
	bool Rectangle::hasGreatArea(Polygon *Poly)
	{
		double porownanie = Poly->area() - area();
		if (porownanie >= 0) return 0;
		if (porownanie < 0) return 1;

	}
/// Triangle:
    Triangle::Triangle(){};
    Triangle::Triangle(Point x,Point y,Point z):ta(x),tb(y),tc(z)
		{}
	double Triangle::perimiter()
	{
		return ta.distance(tb) + tb.distance(tc) + tc.distance(ta);
	}
	double Triangle::area()
	{
		double polobwodu = perimiter() * 0.5;
		return sqrt(polobwodu * (polobwodu - ta.distance(tb)) * (polobwodu - tb.distance(tc)) * (polobwodu - tc.distance(ta)));
	}
	bool Triangle::hasGreatArea(Polygon *Poly)
	{
		double porownanie = area() - Poly->area();
		if (porownanie > 0) return 1;
		if (porownanie <= 0) return 0;
	}
    ///Square:
    Square::Square(){};
    Square::Square(Point a, Point b,Point c,Point d):
        Rectangle(a,b,c,d),Rhombus() {};
    double Square::perimiter()
    {
        return Rectangle::perimiter();
    }
    double Square::area()
    {
        return Rectangle::area();
    }
    bool Square::hasGreatArea(Polygon *Poly)
    {
        return Rectangle::hasGreatArea(Poly);
    }
    ///Rhombus
    Rhombus::Rhombus(){};
    Rhombus::Rhombus(Point a,Point b,Point c,Point d)
    {
        ra=a;
        rb=b;
        rc=c;
        rd=d;
    }
    bool Rhombus::hasGreatArea(Polygon *Poly)
    {
        double porownanie = area() - Poly->area();
		if (porownanie > 0) return 1;
		if (porownanie <= 0) return 0;
    }
    double Rhombus::perimiter()
    {
        return ra.distance(rb)+rb.distance(rc)+rc.distance(rd)+rd.distance(rc);
    }
    double Rhombus::area()
    {
        return ra.distance(rc)*rb.distance(rd)*0.5;
    }
