#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
//using namespace std;
namespace Math
{

class Matrix
{
public:
    Matrix(){};
    Matrix(Matrix &matrix)
    {
        int licznik=0;
        kolumny=matrix.kolumny;
        wiersze=matrix.wiersze;
        try
        {
            macierz=new double*[wiersze];
            for(int i(0);i<wiersze;i++)
            {
                licznik++;
                macierz[i]=new double[kolumny];
                for(int j(0);j<kolumny;j++)
                {
                macierz[i][j]=matrix.macierz[i][j];
                }
            }
        }

        catch(std::bad_alloc & blad)
        {
            std::cout<<"Nie udalo sie zarezerwowac pamieci"<<std::endl;
            if(licznik==0)
            {
                delete [] macierz;
            }
            for(int i(0);i<licznik;i++)
            {
                delete [] macierz[i];
            }
            std::cout<<"Program koñczy dzialanie."<<std::endl;
            exit(3);
        }
    }
    Matrix &operator=(Matrix &matrix)
    {
        kolumny=matrix.kolumny;
        wiersze=matrix.wiersze;
        int licznik=0;
        try
        {
            macierz=new double*[wiersze];
            for(int i(0);i<wiersze;i++)
            {
                licznik++;
                macierz[i]=new double[kolumny];
                for(int j(0);j<kolumny;j++)
                {
                macierz[i][j]=matrix.macierz[i][j];
                }
            }
        }

        catch(std::bad_alloc & blad)
        {
            std::cout<<"Nie udalo sie zarezerwowac pamieci"<<std::endl;
            if(licznik==0)
            {
                delete [] macierz;
            }
            for(int i(0);i<licznik;i++)
            {
                delete [] macierz[i];
            }
            std::cout<<"Program koñczy dzialanie."<<std::endl;
            exit(3);
        }
    }
    Matrix(int lwierszy,int lkolumn)
    {
        if(lwierszy <1 || lkolumn <1 )
        {
            std::cout<<"Blad"<<std::endl;
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
                for(int j(0);j<lkolumn;j++)
                {
                macierz[i][j]=rand()%10;
                }

            }
            std::cout<<"Udalo sie zarezerwowac pamiec"<<std::endl;
        }
        catch(std::bad_alloc & blad)
        {
            std::cout<<"Nie udalo sie zarezerwowac pamieci"<<std::endl;
            if(licznik==0)
            {
                delete [] macierz;
            }
            for(int i(0);i<licznik;i++)
            {
                delete [] macierz[i];
            }
            std::cout<<"Program konczy dzialanie."<<std::endl;
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
        std::cout<<"Destruktor usunal macierz"<<std::endl;
    }
    Matrix multiply(Matrix & macierz2)
    {
        if(kolumny!=macierz2.wiersze)
        {
            std::cout<<"Nie mozna wykonac mnozenia."<<std::endl;
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

    std::string toString()
    {
        std::stringstream proba;
        int maxwyraz=0;
        std::string pomoc="";
        std::string String="";
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
//double **macierz;
private:
    double **macierz;
    int kolumny,wiersze;

};
}
int main()
{
   srand(time(NULL));

   Math::Matrix A(2,2);
   Math::Matrix B(2,3);
   std::cout<<"Macierz A:"<<std::endl;
   std::cout<<A.toString()<<std::endl;
   std::cout<<"Macierz B:"<<std::endl;
   std::cout<<B.toString()<<std::endl;
   Math::Matrix C(B); //konstruktor kopiuj¹cy
   Math::Matrix D;
   D=A;               //operator przypisania

   std::cout<<(A.multiply(B)).toString()<<std::endl;
   std::cout<<(D.multiply(C)).toString()<<std::endl;

    return 0;
}
