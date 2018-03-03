#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Matrix
{
public:

    Matrix(int lwierszy,int lkolumn)
    {
        if(lwierszy <1 || lkolumn <1 )
        {
            cout<<"Blad"<<endl;
            exit(1);
        }
        wiersze=lwierszy;
        kolumny=lkolumn;
        int licznik(0);
        try
        {
            macierz=new double *[lwierszy];

            for(int i(0);i<lwierszy;i++)
            {
                licznik++;
                macierz[i]=new double[lkolumn];

            }
            cout<<"Udalo sie zarezerwowac pamiec"<<endl;
        }
        catch(bad_alloc & blad)
        {
            cout<<"Nie udalo sie zarezerwowac pamieci"<<endl;
            if(licznik==0)
            {
                delete [] macierz;
            }
            for(int i(0);i<licznik;i++)
            {
                delete [] macierz[i];
            }
            cout<<"Program konczy dzialanie."<<endl;
            exit(2);
        }
    }
    ~Matrix()
    {

        for(int i(0);i<wiersze;i++)
        {
            delete [] macierz[i];
        }
        delete [] macierz;
        macierz=0;
        cout<<"Destruktor usunal macierz"<<endl;
    }
    Matrix multiply(Matrix & macierz2)
    {
        if(kolumny!=macierz2.wiersze)
        {
            cout<<"Nie mozna wykonac mnozenia."<<endl;
            this->~Matrix();
            macierz2.~Matrix();
            exit(3);
        }
        Matrix macierz3(this->wiersze,macierz2.kolumny);

        //zerowanie macierzy-moze to byc osobna funkcja
        for(int i(0);i<wiersze;i++)
        {
            for(int j(0);j<macierz2.wypiszkolumny();j++)
            {
                macierz3.macierz[i][j]=0;
            }
        }
        //mnozenie
        for(int j(0);j<macierz2.wypiszkolumny();j++)
        {
            for(int i(0);i<wiersze;i++)
            {
                for(int k(0);k<kolumny;k++)
                {
                    macierz3.macierz[i][j]+=macierz[i][k]*macierz2.macierz[k][j];
                }
            }
        }
        return macierz3;
    }

    int wypiszkolumny()
    {
        return kolumny;
    }

    int wypiszwiersze()
    {
        return wiersze;
    }

    string toString()
    {
        stringstream proba;
        int maxwyraz;
        string pomoc;
        string String;
        int zapasowy;
        //wyznaczanie najdluszego stringa(maxwyraz)
        for(int i(0);i<wiersze;i++)
        {

            for(int j(0);j<kolumny;j++)
            {
                proba.str("");
                proba<<macierz[i][j];
                pomoc=proba.str();
                if(pomoc.length()>maxwyraz)
                {
                    maxwyraz=pomoc.length();
                }
            }
        }
        maxwyraz++;
        //zapisywanie
        for(int i(0);i<wiersze;i++)
        {

            for(int j(0);j<kolumny;j++)
            {
                proba.str("");
                proba<<macierz[i][j];
                pomoc=proba.str();
                zapasowy=String.length();
                String.insert(zapasowy,maxwyraz-pomoc.length(),' ');
                String=String+pomoc;

            }
            String+='\n';
        }
        return String;
    }
    double **macierz;
private:

    int kolumny,wiersze;

};
int main()
{
   Matrix A(2,2);
   Matrix B(2,3);
   A.macierz[0][0]=134;
   A.macierz[0][1]=2;
   A.macierz[1][0]=30;
   A.macierz[1][1]=4;


   B.macierz[0][1]=1;
   B.macierz[0][2]=3;
   B.macierz[1][0]=1;
   B.macierz[1][1]=1;
   B.macierz[1][2]=2;
   B.macierz[0][0]=2;

   cout<<(A.multiply(B)).toString();
    return 0;
}
