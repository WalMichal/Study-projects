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
double dotproduct(double ax,double ay,double bx, double by)
{
    return (ax*bx)+(ay*by);
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
double Point::returnx()
{
    return x;
}
double Point::returny()
{
    return y;
}
void Point::enterx(double cx)
{
    x=cx;
}
void Point::entery(double cy)
{
    y=cy;
}
/// Rectangle:
    Rectangle::Rectangle(){};
    Rectangle::Rectangle(Point w, Point x, Point y, Point z) :pa(w), pb(x), pc(y), pd(z)
	{
        bool ifperpendicular = dotproduct(pa.returnx()-pb.returnx(),pa.returny()-pb.returny(),pa.returnx()-pd.returnx(),pa.returny()-pd.returny());
        bool ifperpendicular1 = dotproduct(pb.returnx()-pc.returnx(),pb.returny()-pc.returny(),pa.returnx()-pb.returnx(),pa.returny()-pb.returny());
        bool ifperpendicular2 = dotproduct(pc.returnx()-pd.returnx(),pc.returny()-pd.returny(),pb.returnx()-pc.returnx(),pb.returny()-pc.returny());
        if(ifperpendicular || ifperpendicular1 || ifperpendicular2)
        {
            throw string("This is not Rectangle.");
        }

	}
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
		{
		    bool ifsmaller  = ta.distance(tb)+tb.distance(tc)<=tc.distance(ta);
		    bool ifsmaller1 = tc.distance(ta)+tb.distance(tc)<=ta.distance(tb);
		    bool ifsmaller2 = ta.distance(tb)+tc.distance(ta)<=tb.distance(tc);
            if(ifsmaller || ifsmaller1 || ifsmaller2)
            {
                throw string("This is not Triangle.");
            }
		}
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
        Rectangle(a,b,c,d),Rhombus()
        {
        bool ifperpendicular  = dotproduct(pa.returnx()-pb.returnx(),pa.returny()-pb.returny(),pa.returnx()-pd.returnx(),pa.returny()-pd.returny());
        bool ifperpendicular1 = dotproduct(pb.returnx()-pc.returnx(),pb.returny()-pc.returny(),pa.returnx()-pb.returnx(),pa.returny()-pb.returny());
        bool ifperpendicular2 = dotproduct(pc.returnx()-pd.returnx(),pc.returny()-pd.returny(),pb.returnx()-pc.returnx(),pb.returny()-pc.returny());
        if(ifperpendicular || ifperpendicular1 || ifperpendicular2 || pa.distance(pb)-pb.distance(pc)|| pb.distance(pc)-pc.distance(pd))
        {
            throw string("This is not Square.");
        }
        }
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
    Rhombus::Rhombus(Point a,Point b,Point c,Point d):ra(a),rb(b),rc(c),rd(d)
    {
        bool ifperpendicular = dotproduct(ra.returnx()-rc.returnx(),ra.returny()-rc.returny(),rb.returnx()-rd.returnx(),rb.returny()-rd.returny());
        bool ifcenter = (ra.returnx()/2+rc.returnx()/2 != rb.returnx()/2+rd.returnx()/2 || ra.returny()/2 + rc.returny()/2 != rb.returny()/2 + rd.returny()/2);
        if(ifcenter || ifperpendicular)
        {
            throw string("This is not Rhombus.");
        }
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
