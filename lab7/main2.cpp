#include <iostream>
#include <cmath>
using namespace std;
template <int dim>
class Point
{
private:
	double coordinates[dim];
public:
	Point(double coordinates[])
	{
		for (int i(0); i < dim; i++)
		{
			this->coordinates[i] = coordinates[i];
		}
	}
	Point<dim> translate(double coordinates[dim])
	{
	    double coordinates_tab[dim];

		for (int i(0); i < dim; i++)
		{
		    coordinates_tab[i]=this->coordinates[i];
			coordinates_tab[i] += coordinates[i];
		}
		return Point(coordinates_tab);
	}
	double distance(Point<dim> &point)
	{
		double sum;
		for (int i(0); i < dim; i++)
		{
			sum += pow(point.coordinates[i] - coordinates[i],2);
		}
		return sqrt(sum);
	}
	void get_coordinates()
	{
		for (int i(0); i < dim; i++)
		{
			cout<<coordinates[i]<<",";
		}
	}
};

int main()
{
    double tab1[4]={2,4,6,8};
    double tab2[4]={12,14,16,18};
    double translatetab[4]={8,6,4,2};
    Point <3> point3d(tab1);
    Point <3> point3d2(tab2);
    cout<<point3d.distance(point3d2)<<endl;
    point3d=point3d2.translate(translatetab);
    point3d.get_coordinates();
    cout<<endl;

    Point <4> point4d(tab1);
    Point <4> point4d2(tab2);
    cout<<point4d2.distance(point4d)<<endl;
    point4d=point4d2.translate(translatetab);
    point4d.get_coordinates();
    return 0;
}
