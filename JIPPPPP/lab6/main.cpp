#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include "geometry.h"
using namespace std;


double sum(vector  <Polygon *>);
//double sum(vector <Rectangle>);
int main()
{
    vector <Polygon *> vectorpolygon;
    Point A(0,0),B(0,2),C(2,2),D(2,0),E(4,2),F(4,0);
    Point G(0,1),H(-2,-3),I(-4,1),J(-2,5);
    Point K,L,M;
    Square sq(A,B,C,D);
    Triangle tr;
    double coordinate;
    try
    {
        cout<<"Enter coordinates of the triangle:"<<endl;
        cout<<"First point:"<<endl<<"  Point A:"<<endl<<"    x:";
        cin>>coordinate;
        K.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        K.entery(coordinate);
        cout<<"Second point:"<<endl<<"  Point B:"<<endl<<"    x:";
        cin>>coordinate;
        L.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        L.entery(coordinate);
        cout<<"Third point:"<<endl<<"  Point C:"<<endl<<"    x:";
        cin>>coordinate;
        M.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        M.entery(coordinate);
        tr=Triangle(K,L,M);
    }

    catch (string &error)
    {
        cout<<error<<endl;
        cout<<"Enter CORRECT! coordinates of the triangle:"<<endl;
        cout<<"First point:"<<endl<<"  Point A:"<<endl<<"    x:";
        cin>>coordinate;
        K.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        K.entery(coordinate);
        cout<<"Second point:"<<endl<<"  Point B:"<<endl<<"    x:";
        cin>>coordinate;
        L.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        L.entery(coordinate);
        cout<<"Third point:"<<endl<<"  Point C:"<<endl<<"    x:";
        cin>>coordinate;
        M.enterx(coordinate);
        cout<<"    y:";
        cin>>coordinate;
        M.entery(coordinate);
        tr=Triangle(K,L,M);

    }

    Rhombus rh(G,H,I,J);
    Rectangle pr(A,B,E,F);
    Polygon *ppol=&sq;
    cout<<"Square area:"<<ppol->area()<<endl;
    ppol=&rh;
    cout<<"Rhombus area:"<<ppol->area()<<endl;
    if(ppol->hasGreatArea(&sq))
    {
        cout<<"Rhombus has larger area than square."<<endl;
    }
    else cout<<"Square has larger area than rhombus."<<endl;
    ppol=&tr;
    vectorpolygon.push_back(ppol);
    cout<<"Traingle perimiter:"<<ppol->perimiter()<<endl;
    ppol=&sq;
    vectorpolygon.push_back(ppol);
    cout<<"Square perimiter:"<<ppol->perimiter()<<endl;
    cout<<"Sum Triangle and Square:"<<sum(vectorpolygon)<<endl<<endl;
    cout<<"Sizeof Triangle:"<<sizeof(Triangle)<<endl;
    cout<<"Sizeof Square:"<<sizeof(Square)<<endl;
    cout<<"Sizeof Rhombus:"<<sizeof(Rhombus)<<endl;
    cout<<"Sizeof Rectangle:"<<sizeof(Rectangle)<<endl;
    cout<<"Sizeof Polygon:"<<sizeof(Polygon)<<endl;
    cout<<"Sizeof Point:"<<sizeof(Point)<<endl;


    return 0;
}




