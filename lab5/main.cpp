#include <iostream>
#include "class.h"
#include "menu.h"
using namespace std;
int Student::numberofstudent=0;
int main()
{
    Menu PK;
    PK.ReadStudent("students.csv","grades.csv");
    PK.ReadWorkers("employes.csv","salaries.csv");
    PK.entervalueofscholarship(450);
    PK.scholarship();
    PK.addworkers();
    PK.transactiontofile("transaction.csv");

}
