#include "class.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
///Person
    void Person::loadid(int id)
    {
        ID=id;
    }
    void Person::loadtp(int tp)
    {
        topay=tp;
    }
    void Person::loadname(string n)
    {
        name=n;
    }
    void Person::loadsname(string sn)
    {
        surname=sn;
    }
    void Person::loadan(string an)
    {
        accountnumber=an;
    }
    void Person::loadtopay(int tp)
    {
        topay=tp;
    }
    int Person::returnid()
    {
        return ID;
    }
    string Person::returnname()
    {
        return name;
    }
    string Person::returnsurname()
    {
        return surname;
    }
    string Person::returnaccountnumber()
    {
        return accountnumber;
    }
    double Person::returntopay()
    {
        return topay;
    }
///Student
    Student::Student()
    {
        topay=0;
        numberofstudent++;
    }
    void Student::loadyearOfstudy(int year)
    {
        yearOfstudy=year;
    }
    void Student::addtuple(double grade,string subject)
    {
        tuples.push_back(make_tuple(subject,grade));
    }
    vector < tuple <string,double> > Student::returnvector()
    {
        return tuples;
    }
    double Student::getdoublefromtuples(int i)
    {
        return get<1>(tuples[i]);
    }
    void Student::loadaverage(double av)
    {
        average=av;
    }
    int Student::sizeofvtuple()
    {
        return tuples.size();
    }
    double Student::returntopays() const
    {
        return topay;
    }
     int Student::returnnumberofstudent()
    {
        return numberofstudent;
    }
    double Student::returnaverage() const
    {
        return average;
    }
///Acatecher
    Acateacher::Acateacher(){topay=0;}; ///topay w ka¿dym powinno byæ po 0;
    void Acateacher::loadrank(string r)
    {
        acarank=r;
    }
    void Acateacher::loadpos(string pos)
    {
        position=pos;
    }
    string Acateacher::returnpos()
    {
        return position;
    }

    Acaworker::Acaworker()
    {topay=0;};
    void Acaworker::loadpos(string pos)
    {
        position=pos;
    }
     string Acaworker::returnpos()
    {
        return position;
    }



