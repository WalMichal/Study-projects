#ifndef GEOMETRY
#define GEOMETRY
#include <cmath>
class  Point
{
public:

	Point(Point &);
	Point();
	Point(double ,double );
	double odleglosc(Point &);
private:
	double x;
	double y;

};

class Triangle;
class Prostokat;
class Prostokat
{
public:
    //Prostokat(const Prostokat &);
	Prostokat(Point , Point , Point , Point );
	double perimiter();
	double area();
	bool hasGreatArea(Prostokat &);
    bool hasGreatArea(Triangle &);
private:
    Point a, b, c, d;
};

class Triangle
{
public:
    Triangle(Point x,Point y,Point z);
	Triangle();
	double perimiter();
	double area();
	bool hasGreatArea(Prostokat &);
	bool hasGreatArea(Triangle &);
private:
    Point a, b, c;
};

#endif // GEOMETRY
