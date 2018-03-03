#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "menu.h"
#include <algorithm>
using namespace std;
    bool compare(const Student &a,const Student &b)
 {
     return a.returnaverage()>b.returnaverage();
 }
bool comparemenu(const Menu &a,const Menu &b)
{
    return a.returnToPay()<b.returnToPay();
}
void Menu::ReadStudent(string fnamestudents,string fnamegrades)
{   fstream file;
    string line,help;
    int idn(-1);
    int i(0);
    file.open(fnamestudents,ios::in);
    if(file.good() == false)
    {
        cout<<"File opening error:"<<fnamestudents<<endl;
        exit(1);
    }

    while(!file.eof())
    {
        students.push_back(Student());
        line.clear();

        getline(file,line,'|');
        if(line.empty()==true)break;
        students[i].loadid(atoi(line.c_str()));

        getline(file,line,'|');
        students[i].loadname(line);

        getline(file,line,'|');
        students[i].loadsname(line);

        getline(file,line,'|');
        students[i].loadan(line);

        getline(file,line);
        students[i].loadyearOfstudy(atoi(line.c_str()));
        i++;
    }
    file.close();
    file.open(fnamegrades,ios::in);
    if(file.good() == false)
    {
        cout<<"File opening error:"<<fnamegrades<<endl;
        exit(2);
    }
    ///zakończenie;
    while(!file.eof())
    {

        line.clear();
        getline(file,line,'|');
        if(line.empty())break;
        idn=returnVposition(atoi(line.c_str()));

        if(idn==-1)
        {
            cout<<"Error: Wrong ID."<<endl;
            exit(2);
        }
        getline(file,line,'|');
        help=line;
        getline(file,line);
        students[idn].addtuple(atof(line.c_str()),help);
    }
    file.close();

}
void Menu::ReadWorkers(string fnameemployes,string fnamesalaries)
{
    fstream file;
    file.open(fnameemployes,ios::in);
    if(file.good()==false)
    {
        cout<<"File opening error:"<<fnameemployes<<endl;
        exit(3);
    }
    string id,n,sn,an,pos,r;
    int tp,iw(0),iaw(0);
    string help;
    while(!file.eof())
    {
        getline(file,id,'|');
        if(id.empty()==true)break;

        getline(file,n,'|');
        getline(file,sn,'|');
        getline(file,an,'|');
        getline(file,pos,'|');
        getline(file,r);
        if(r=="-")
        {
            workers.push_back(Acaworker());
            workers[iw].loadname(n);
            workers[iw].loadsname(sn);
            workers[iw].loadan(an);
            workers[iw].loadid(atoi(id.c_str()));
            workers[iw].loadpos(pos);
            iw++;
        }
        else
        {
            teachers.push_back(Acateacher());
            teachers[iaw].loadname(n);
            teachers[iaw].loadsname(sn);
            teachers[iaw].loadan(an);
            teachers[iaw].loadid(atoi(id.c_str()));
            teachers[iaw].loadpos(pos);
            teachers[iaw].loadrank(r);
            iaw++;
        }

    }
    file.close();

    file.open(fnamesalaries);
    if(file.good()==false)
    {
        cout<<"File opening error:"<<fnamesalaries<<endl;
        exit(4);
    }

    while(!file.eof())
    {
        getline(file,pos,'|');
        if(pos.empty())break;

        getline(file,help);
        tp=atoi(help.c_str());

        topay(tp,pos);
    }

}


int Menu::returnVposition(int id)
{
    for(int i(0);i<students.size();i++)
    {
        if(students[i].returnid()==id)return i;
    }
    return -1;

}

void Menu::topay(int topay, string pos)
{
     for(int i(0);i<teachers.size();i++)
    {
        if(teachers[i].returnpos()==pos)
        {
            teachers[i].loadtopay(topay);
        }
    }
      for(int i(0);i<workers.size();i++)
    {
        if(workers[i].returnpos()==pos)
        {
            workers[i].loadtopay(topay);
        }
    }

}
void Menu::scholarship()
{   string help;
    double suma(0);
    double counter=0;
    for(int i(0);i<students.size();i++)
    {
        for(int j(0);j<students[i].sizeofvtuple();j++)
        {
            suma+=students[i].getdoublefromtuples(j);
            counter++;
        }
        students[i].loadaverage((suma/counter));
        suma=0;
        counter=0;
    }
    sort(students.begin(),students.end(),compare);
    for(int i=0;i<(0.1*Student::returnnumberofstudent()) && students[i].returnaverage() >4.0;i++)
    {
        help="Stypendium za wyniki w nauce;<"+students[i].returnname()+"><"+students[i].returnsurname()+">";
        addtransaction(help,students[i].returnaccountnumber(),scholarshipvalue);
    }

}
void Menu::addworkers()
{
    string help;
    for(int i(0);i<workers.size();i++)
    {
        help="Wynagrodzenie;<"+workers[i].returnname()+"><"+workers[i].returnsurname()+">";
        addtransaction(help,workers[i].returnaccountnumber(),workers[i].returntopay());
    }
    for(int i(0);i<teachers.size();i++)
    {
        help="Wynagrodzenie;<"+teachers[i].returnpos()+"><"+teachers[i].returnname()+"><"+teachers[i].returnsurname()+">";
        addtransaction(help,teachers[i].returnaccountnumber(),teachers[i].returntopay());
    }
}
Menu::Menu(){};
Menu::Menu(string title, string an, int tp):title(title),accountnumber(an),ToPay(tp)
{};
void Menu::addtransaction(string title,string an, double tp)
{
    transaction.push_back(Menu(title,an,tp));
}
void Menu::entervalueofscholarship(double value)
{
    scholarshipvalue=value;
}
void Menu::transactiontofile(string fname)
{
    sort(transaction.begin(),transaction.end(),comparemenu);
    fstream file;
    file.open(fname,ios::out);
    if(file.good()==false)
    {
        cout<<"File opening error:"<<fname<<endl;
        exit(5);
    }
    for(int i(0);i<transaction.size();i++)
    {
        file<<transaction[i].accountnumber;
        file<<"|";
        file<<transaction[i].title;
        file<<"|";
        file<<transaction[i].ToPay;
        file<<'\n';
    }

}
double Menu::returnToPay()const
{
    return ToPay;
}
