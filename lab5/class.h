#ifndef classes
#define classes
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
///wa¿ne: class.cpp
///WA¯NE konstruktor topay=0!!!
class Person
{
protected:
    int ID;
    double topay;
    string name;
    string surname;
    string accountnumber;
public:
    void loadid(int );
    void loadtp(int );
    void loadname(string );
    void loadsname(string );
    void loadan(string an);
    void loadtopay(int tp);
    int returnid();
    string returnname();
    string returnsurname();
    string returnaccountnumber();
    double returntopay();
};
class Student: public Person
{
public:
    Student();
    void loadyearOfstudy(int year);
    void addtuple(double grade,string subject);
    vector < tuple <string,double> > returnvector();
    double getdoublefromtuples(int i);
    void loadaverage(double av);
    int sizeofvtuple();
    double returntopays() const;
    static int returnnumberofstudent();
    double returnaverage() const;
protected:
    double average;
    static int numberofstudent;
    int yearOfstudy;
    vector < tuple <string,double> > tuples;

};
class Acateacher : public Person
{
public:
    Acateacher(); ///topay w ka¿dym powinno byæ po 0;
    void loadrank(string r);
    void loadpos(string pos);
    string returnpos();
protected:
    string position;
    string acarank;
};
class Acaworker : public Person
{
public:
    Acaworker();
    void loadpos(string pos);
    string returnpos();
protected:
    string position;
};

#endif
