#include <iostream>
#include <cmath>
using namespace std;
double sqofdif(double a,double b)
{
    return ((a-b)*(a-b));
}

template <size_t N>
class Point
{
    virtual double distance(Point &a)=0;
};
template<>
class Point<2>
{
public:
    Point<2>(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    double distance(Point &point)
    {
        return sqrt(sqofdif(x,point.x)+sqofdif(y,point.y));
    }
    Point translate(double x,double y)
    {
        return Point(this->x+x,this->y+y);
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
protected:
    double x;
    double y;
};
template<>
class Point<3>: virtual public Point<2>
{
public:
    Point<3>(double x,double y,double z):Point<2>(x,y)
    {
        this->z=z;
    }
    double distance(Point &point)
    {
        return sqrt(sqofdif(x,point.x)+sqofdif(y,point.y)+sqofdif(z,point.z));
    }
    Point translate(double x,double y,double z)
    {
        return Point(this->x+x,this->y+y,this->z+z);
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return z;
    }
protected:
    double z;
};
template<>
class Point<4>:public Point<3>
{
public:
    Point<4>(double x,double y,double z, double w):Point<2>(x,y),Point<3>(x,y,z)
    {
        this->w=w;
    }
    double distance(Point &point)
    {
        return sqrt(sqofdif(x,point.x)+sqofdif(y,point.y)+sqofdif(z,point.z)+sqofdif(w,point.w));
    }
    Point translate(double x,double y,double z,double w)
    {
        return Point(this->x+x,this->y+y,this->z+z,this->w+w);
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return z;
    }
    double getW()
    {
        return w;
    }
private:
    double w;

};

int main()
{
    Point <3> point3d(2,4,6);
    Point <3> point3d2(12,14,16);
    cout<<point3d.distance(point3d2)<<endl;
    point3d=point3d2.translate(-1,-1,-6);
    cout<<"x:"<<point3d.getX()<<endl;
    cout<<"y:"<<point3d.getY()<<endl;
    cout<<"z:"<<point3d.getZ()<<endl;
    cout<<endl;
    Point <4> point4d(2,4,6,8);
    Point <4> point4d2(12,14,16,18);
    cout<<point4d2.distance(point4d)<<endl;
    point4d=point4d2.translate(8,6,4,2);
    cout<<"x:"<<point4d.getX()<<endl;
    cout<<"y:"<<point4d.getY()<<endl;
    cout<<"z:"<<point4d.getZ()<<endl;
    cout<<"w:"<<point4d.getW()<<endl;

    return 0;
}
