///Michal Zadrozny grupa I3
///PROI Projekt 3.4
///nr indeksu 293177

#include <iostream>
#include<vector>
#include<unistd.h>
#include"crossword2.h"
using namespace std;

///lista inicjalizacyjna dla klasy Wyraz
Wyraz::Wyraz(unsigned int ii=0,unsigned int jj=0, unsigned int oo=0, unsigned int dll=0) : i(ii),j(jj),o(oo),dl(dll) {};

///wyswietlanie atrybutow obiektu Wyraz
ostream &operator<<(ostream &out, const Wyraz &w)
{
    out<<"i: "<<w.i<<"  j: "<<w.j<<"  o: "<<w.o<<"  dl: "<<w.dl<<endl;
    return out;
}

///pobieranie planszy
Plansza &operator>>(std::istream &in, Plansza &pl)
{
    vector<string> tab; ///vector przechowujacy kolejne wpisane linie
    string a; ///kolejne wpisywane linie
    cout<<"Podaj szablon krzyzowki: "<<endl;
    pl.m=0;
    pl.n=0;
    while(true)
    {
        getline(cin,a);
        if(a.length()>pl.m)pl.m=a.length(); ///ilosc kolumn to dlugosc najdluzszej linii
        if(a=="0") break; ///wpisanie 0 w nowej linii oznacza koniec diagramu
        else {tab.push_back(a);pl.n++;}
    }

    ///tablica prostokatna - uzupelnienie stringow do rownej dlugosci
    for(unsigned int i=0;i<pl.n;i++)
    {
        for(unsigned int j=0;j<pl.m-tab[i].length();j++)
        {
            tab[i]+='0';
        }
    }

    ///konwersja na string
    for(unsigned int i=0;i<pl.n;i++)
    {
        for(unsigned int j=0;j<pl.m;j++)
        {
            if(tab[i][j]=='X')
            pl.p+='.';
            else pl.p+='0';
        }
    }
    return pl;
}

///wyswietlanie planszy
ostream &operator<<(ostream &out, const Plansza &pl)
{
    if(pl.p!="Niemozliwe")
    {
        for(unsigned int i=0; i<pl.n; i++)
        {
            for(unsigned int j=0; j<pl.m; j++)
            {
                if(pl.p[i*pl.m+j]=='0')
                {
                    out<<' ';
                    continue;
                }
                out<<pl.p[i*pl.m+j];
            }
            out<<endl;
        }
        return out;
    }
    else
    {
        out<<pl.p;
        return out;
    }


}

///funkcja wstawia slowo do luki, zwraca nowa plansze z juz wstawionym slowem
Plansza Plansza::wstaw(string a, Plansza pl, Wyraz &w)
{
    Plansza temp=pl;
    if(w.o==0)///dla luk poziomych
    {
        for(unsigned int i=w.i*pl.m+w.j, j=0; j<a.length(); i++,j++)
        {
            temp.p[i]=a[j];
        }
    }
    if(w.o==1)///dla luk pionowych
    {
        for(unsigned int i=w.i*pl.m+w.j, j=0; j<a.length(); i=i+pl.m,j++)
        {
            temp.p[i]=a[j];
        }
    }
    return temp;
}

///funkcja sprawdza poprawnosc ewentualnego rozwiazania
///potrzebne gdy kilka slow jest takich samych
bool Plansza::valid(Plansza pl) const
{
    for(unsigned int i=0;i<pl.p.length();i++)
    {
        if(pl.p[i]=='.') return false; ///obecnosc nieuzupelnionych luk - nieprawidlowe rozwiazanie
    }
    return true;
}

///funkcja rekurencyjna szukajaca rozwiazania
///nr - poziom zaglebienia rekurencji
///test=1 - wyswietlanie planszy na kazdym poziomie rekurencji
Plansza Plansza::dopasuj(Plansza plansza,vector<Wyraz> &wyrazy,string slowa[],unsigned nr,int test)
{
    ///
    if(test==1)
    {
        cout<<"nr: "<<nr<<endl<<endl;
        cout<<plansza;
        sleep(1);
    }
    ///

    if(nr==wyrazy.size())///oznacza ze wpisalismy wszystkie wyrazy
    {
        if(valid(plansza)==true) return plansza;///udalo sie, zwroc plansze
        else
        {
            Plansza kom;
            kom.p="Niemozliwe";///szukaj dalej
            return kom;
        }
    }



    for(unsigned int i=0;i<wyrazy.size();i++) ///dla kazdego slowa podanego przez uzytkownika
    {
        if(czy_wstawic(slowa[nr],plansza,wyrazy[i])==true) ///znajdz luki gdzie dane slowo pasuje (jesli pasuje w kilku
        {                                                   ///miejscach funkcja wywola sie dla kazdego takiego przypadku, chyba ze wczesniej znajdzie rozwiazanie)
            Plansza temp=wstaw(slowa[nr],plansza,wyrazy[i]); ///wstaw slowo do luki
            Plansza r=dopasuj(temp, wyrazy, slowa, nr+1,test); ///WYWOLANIE REKURENCYJNE: wstawiaj kolejne slowa do planszy z juz wstawionym slowem, kolejny poziom rekurencji, rozpatrujemy nastepne slowo
            if(r.p!="Niemozliwe") return r; ///jesli dane uzupelnienie nie doprowadzilo do niepowodzenia to je zwroc na wyzszy poziom
        }
    }
    Plansza kom;
    kom.p="Niemozliwe";
    ///dla danej planszy nie ma miejsca gdzie pasowaloby aktualnie analizowane slowo - niepowodzenie
    return kom;

}

///funkcja odnajduje luki na planszy, zapisuje obiekty Wyraz do vectora
void znajdz_wyrazy(Plansza pl, vector<Wyraz> &wyrazy)
{
    vector<string> tab; ///vector przechowujacy kolejne wpisane linie

    for(unsigned i=0;i<pl.n;i++)
    {
        string a=""; ///kolejne wpisywane linie
        for(unsigned j=0;j<pl.m;j++)
        {
            a+=pl.p[i*pl.m+j];
        }

        tab.push_back(a);
    }
   ///wyszukiwanie wyrazow poziomo
    for(unsigned int i=0;i<pl.n;i++)
    {
        for(unsigned int j=0;j<pl.m-1;j++)
        {
            int x=0;
            if(tab[i][j]=='.' && tab[i][j+1]=='.') ///conajmniej dwa X pod rzad oznaczaja nowy wyraz
            {
                Wyraz w(i,j,0);
                while(j<pl.m && tab[i][j]=='.') {j++;x++;} ///dlugosc nowego wyrazu
                w.dl=x;
                wyrazy.push_back(w);
            }
        }
    }

    ///wyszukiwanie wyrazow pionowo
    for(unsigned int i=0;i<pl.m;i++)
    {

        for(unsigned int j=0;j<pl.n-1;j++)
        {
            if(tab[j][i]=='.' && tab[j+1][i]=='.') ///conajmniej dwa X pod rzad oznaczaja nowy wyraz
            {
                Wyraz w(j,i,1);
                int x=0;
                while(j<pl.n && tab[j][i]=='.') {j++;x++;} ///dlugosc nowego wyrazu
                w.dl=x;
                wyrazy.push_back(w);
            }
        }
    }

}

///funkcja pobiera od uzytkownika slowa do dopasowania
///ilosc wyrazow jest zgodna z iloscia luk do wypelnienia
void pobierz_wyrazy(string slowa[],unsigned z)
{
    for(unsigned int i=0;i<z;i++)
    {
        cout<<"Podaj slowo: ";
        cin>>slowa[i];
        for(unsigned j=0;j<slowa[i].length();j++) slowa[i][j]=toupper(slowa[i][j]); ///litery przeksztalcane na wielkie
    }
}

///funkcja sprawdza czy slowo mozna wstawic w luke
bool czy_wstawic(string a, Plansza pl, Wyraz w)
{
    if(a.length()==w.dl)///dlugosc musi sie zgadzac
    {
        if(w.o==0)///dla luk poziomych
        {
            for(unsigned int i=w.i*pl.m+w.j, j=0; j<a.length(); i++,j++)
            {
                if(pl.p[i]!='.' && pl.p[i]!=a[j]) return false;///luka pusta lub ta sama litera na krzyzujacej sie pozycji
            }
            return true;
        }
        if(w.o==1)///dla luk pionowych
        {
            for(unsigned int i=w.i*pl.m+w.j, j=0; j<a.length(); i=i+pl.m,j++)
            {
                if(pl.p[i]!='.' && pl.p[i]!=a[j]) return false;///luka pusta lub ta sama litera na krzyzujacej sie pozycji
            }
            return true;
        }
    }
    return false;
}

///funkcja obslugujaca diagram i slowa podane przez uzytkownika
void program()
{

    cout<<"Szablon krzyzowki powinien skladac sie \nz duzych liter X odzielonych innymi znakami \nAby zakonczyc szablon wpisz 0 w nowej linii "<<endl;
    //cout<<"\nX X \nXXXX\nX X \nXXXX\n0"<<endl<<endl;

    Plansza pl;
    cin>>pl;
    vector<Wyraz> wyrazy;
    znajdz_wyrazy(pl,wyrazy);
    string slowa[wyrazy.size()];
    pobierz_wyrazy(slowa,wyrazy.size());
    pl=pl.dopasuj(pl,wyrazy,slowa,0,0);
    cout<<endl<<"Wynik:"<<endl<<endl<<pl;
}
