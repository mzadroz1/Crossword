///Michal Zadrozny grupa I3
///PROI Projekt 3.4
///nr indeksu 293177
#include <iostream>
#include<vector>
#include <cstdlib>
#include"crossword2.h"

using namespace std;

int main()
{
    cout<<"Michal Zadrozny grupa I3 \nPROI Projekt 3.4 \nnr indeksu 293177"<<endl<<endl;
    cout<<"Program wspomagajacy ukladanie krzyzowek"<<endl<<endl;

    ///MENU
    cout<<"Wybierz dzialanie: "<<endl;
    cout<<"[0] Uruchom program"<<endl;
    cout<<"[1] test1"<<endl;
    cout<<"[2] test2"<<endl;
    cout<<"[3] test3"<<endl;
    cout<<"[4] Zamknij"<<endl;

    int c;
    while(1)
    {
        cout<<endl<<endl<<"###########################"<<endl<<endl;

        cout<<"Wybierz dzialanie: ";
        while(!(cin>>c)) ///kontrola bledow
        {
            cout<<"Nieokreslona wartosc, sprobuj jeszcze raz: ";
            cout<<endl<<endl<<"###########################"<<endl<<endl;
            cout<<"Wybierz dzialanie: ";
            cin.clear(); ///usuwanie blednych danych ze strumienia
            cin.ignore(1000, '\n');
        }
        if(c<0 || c>4)
        {
            cout<<"Nieokreslona wartosc, sprobuj jeszcze raz:";    ///usuwanie blednych danych ze strumienia
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout<<endl;

    switch(c)
    {
        case 0: program(); break;
        case 1: test1(); break;
        case 2: test2(); break;
        case 3: test3(); break;
        case 4: exit(0);
        default: cout<<"Nieokreslona wartosc, sprobuj jeszcze raz"<<endl; break;

    }
    }

    return 0;
}
