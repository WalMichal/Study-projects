#ifndef GEOMETRY
#define GEOMETRY
#include <cmath>
class Polygon
{
    public:
    virtual double area()= 0;
    virtual bool hasGreatArea(Polygon *) = 0;
    virtual double perimiter() = 0;
};
class  Point
{
public:

	Point(Point &);
	Point();
	Point(double ,double );
	double distance(Point &);
private:
	double x;
	double y;

};

class Triangle;
class Rectangle;
class Rectangle :public virtual Polygon
{
public:
    Rectangle();
	Rectangle(Point , Point , Point , Point );
	double perimiter();
	double area();
	bool hasGreatArea(Polygon *);
protected:
    Point pa, pb, pc, pd;
};

class Triangle :public Polygon
{
public:
    Triangle(Point x,Point y,Point z);
	Triangle();
	double perimiter();
	double area();
	bool hasGreatArea(Polygon *);
protected:
    Point ta, tb, tc;
};

class Rhombus : public virtual Polygon
{
public:
    Rhombus();
    Rhombus(Point ,Point ,Point ,Point );
    double perimiter();
	double area();
	bool hasGreatArea(Polygon *);
private:
    Point ra, rb, rc, rd;
};
class Square : public Rhombus , public Rectangle
{
public:
    Square();
    Square(Point ,Point , Point ,Point );
    double perimiter();
	double area();
	bool hasGreatArea(Polygon *);
//protected:
    //Point sa, sb, sc, sd;
};
#endif // GEOMETRY
