#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include "geometry.h"
using namespace std;


double suma(deque  <Triangle>);
double suma(vector <Prostokat>);
int main()
{

    Point A(0,0),B(0,3),C(4,3),D(4,0);
    Point E(6,3),F(8,3),G(8,1),H(6,1);
    Triangle tro(A,B,C),tro2(B,C,D),tro3(C,D,E);
    Prostokat pro(A,B,C,D), pro2(B,C,D,E), pro3(C,D,E,F);
/*
    deque <Triangle> trojkaty;
    trojkaty.push_back(tro);
    trojkaty.push_back(tro2);
    trojkaty.push_back(tro3);

    vector <Prostokat> prostokaty;
    prostokaty.push_back(pro);
    prostokaty.push_back(pro2);
    prostokaty.push_back(pro3);

    //cout<<"Suma obwodow trojkatow:"<<suma(trojkaty)<<endl;
    //cout<<"Suma obwodow prostokatow:"<<suma(prostokaty)<<endl;
*/
cout<<"Sizeof Triangle:"<<sizeof(Triangle)<<endl;
cout<<"Sizeof Rectangle:"<<sizeof(Prostokat)<<endl;
cout<<"Sizeof Point:"<<sizeof(Point)<<endl;
    return 0;
}




