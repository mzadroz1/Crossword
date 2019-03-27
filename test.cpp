///Michal Zadrozny grupa I3
///PROI Projekt 3.4
///nr indeksu 293177

#include <iostream>
#include<vector>
#include<unistd.h>
#include"crossword2.h"
using namespace std;

void test1()
{
    Plansza pl;
    pl.p=".....00000.0.0000....00000.0.00000.0....00.0000000.00000";
    pl.m=8;
    pl.n=7;
    cout<<"Stworzono obiekt Plansza: "<<endl<<endl;
    sleep(1);
    cout<<"Wyswietlenie planszy: operator << "<<endl<<pl<<endl;

    cout<<"Atrybuty obiektu: "<<endl;
    cout<<"(przekonwertowana plansza) p= "<<pl.p<<endl;
    cout<<"(liczba kolumn)            m= "<<pl.m<<endl;
    cout<<"(liczba wierszy)           n= "<<pl.n<<endl<<endl;
    sleep(1);
    vector<Wyraz> wyrazy;
    znajdz_wyrazy(pl,wyrazy);
    cout<<"Stworzono wektor obiektow Wyraz: "<<endl<<endl;
    sleep(1);
    cout<<"Atrybuty obiektow: "<<endl;
    cout<<"i,j - wspolrzedne poczatku luki  o - orientacja  dl - dlugosc"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<wyrazy[i];
    }
    sleep(1);
    string slowa[]={"KOTEK","DOMEK","KURA","TORT","MIODZIO"};
    cout<<endl<<"Stworzono tablice slow"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<slowa[i]<<endl;
    }
    cout<<endl;
    sleep(1);
    cout<<"Funkcja szuka miejsca do wstawienia kolejnych slow"<<endl<<endl;
    pl=pl.dopasuj(pl,wyrazy,slowa,0,1);
    cout<<endl<<"Wynik: "<<endl<<endl<<pl;

}

void test2()
{
    Plansza pl;
pl.p="00000000000000000......0";
pl.p+="00000000000000000.000000";
pl.p+="00000000000000000.000000";
pl.p+="00000000000000000.000000";
pl.p+="00000000000000000.000000";
pl.p+="0000000000000........000";
pl.p+="00000000000000000.000000";
pl.p+="0000000000000000........";
pl.p+="00000000000000000.000000";
pl.p+=".00000000.000.000.000000";
pl.p+=".00000000.............00";
pl.p+=".00000000.000.0.0.00.000";
pl.p+="..........000.0.0000.000";
pl.p+=".00000000.000.0.0000.000";
pl.p+="000000000.000.0.0000.000";
pl.p+="............000.0000.000";
pl.p+="000000000.00000.0000.000";
pl.p+="00000......0000.0000.000";
pl.p+="00000000000000000000.000";
    pl.m=24;
    pl.n=19;
    cout<<"Stworzono obiekt Plansza: "<<endl<<endl;
    sleep(1);
    cout<<"Wyswietlenie planszy: operator << "<<endl<<pl<<endl;

    cout<<"Atrybuty obiektu: "<<endl;
    //cout<<"(przekonwertowana plansza) p= "<<pl.p<<endl;
    cout<<"(liczba kolumn)            m= "<<pl.m<<endl;
    cout<<"(liczba wierszy)           n= "<<pl.n<<endl<<endl;
    sleep(1);
    vector<Wyraz> wyrazy;
    znajdz_wyrazy(pl,wyrazy);
    cout<<"Stworzono wektor obiektow Wyraz: "<<endl<<endl;
    sleep(1);
    cout<<"Atrybuty obiektow: "<<endl;
    cout<<"i,j - wspolrzedne poczatku luki  o - orientacja  dl - dlugosc"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<wyrazy[i];
    }
    sleep(1);
    string slowa[]={"SUBTRACT","INTEGRAL","APPROXIMATELY","EQUIVALENT","INTERSECTION","EQUALS","DEGREE","DIFFERENTIAL","CUBED","FACTORIAL","COSINE","INFINITY","LOGARITHM"};
    cout<<endl<<"Stworzono tablice slow"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<slowa[i]<<endl;
    }
    cout<<endl;
    sleep(1);
    cout<<"Funkcja szuka miejsca do wstawienia kolejnych slow"<<endl<<endl;
    pl=pl.dopasuj(pl,wyrazy,slowa,0,1);
    cout<<endl<<"Wynik: "<<endl<<endl<<pl;

}

void test3()
{
    Plansza pl;
    pl.p="0.0.0.0.....0.0.0.....0.";
    pl.m=6;
    pl.n=4;
    cout<<"Stworzono obiekt Plansza: "<<endl<<endl;
    sleep(1);
    cout<<"Wyswietlenie planszy: operator << "<<endl<<pl<<endl;

    cout<<"Atrybuty obiektu: "<<endl;
    cout<<"(przekonwertowana plansza) p= "<<pl.p<<endl;
    cout<<"(liczba kolumn)            m= "<<pl.m<<endl;
    cout<<"(liczba wierszy)           n= "<<pl.n<<endl<<endl;
    sleep(1);
    vector<Wyraz> wyrazy;
    znajdz_wyrazy(pl,wyrazy);
    cout<<"Stworzono wektor obiektow Wyraz: "<<endl<<endl;
    sleep(1);
    cout<<"Atrybuty obiektow: "<<endl;
    cout<<"i,j - wspolrzedne poczatku luki  o - orientacja  dl - dlugosc"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<wyrazy[i];
    }
    sleep(1);
    string slowa[]={"SMAK","SKOK","ADAM","DOMEK","AMOR"};
    cout<<endl<<"Stworzono tablice slow"<<endl;
    for(unsigned i=0;i<wyrazy.size();i++)
    {
       cout<<slowa[i]<<endl;
    }
    cout<<endl;
    sleep(1);
    cout<<"Funkcja szuka miejsca do wstawienia kolejnych slow"<<endl<<endl;
    pl=pl.dopasuj(pl,wyrazy,slowa,0,1);
    cout<<endl<<"Wynik: "<<endl<<endl<<pl;

}

