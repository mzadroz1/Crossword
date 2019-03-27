///Michal Zadrozny grupa I3
///PROI Projekt 3.4
///nr indeksu 293177

///klasa, ktorej obiekty przechowuja informacje o luce do uzupelnienia na planszy
class Wyraz
{
public:
    /// i,j - indeks poczatku luki na planszy
    /// o - orientacja: 1-pionowa, 0-pozioma
    /// dl- dlugosc luki
    unsigned int i,j,o,dl;
    ///konstruktor
    Wyraz(unsigned ,unsigned , unsigned , unsigned);
    ///wyswietlanie atrybutow obiektu
    friend std::ostream &operator<<(std::ostream &, const Wyraz &);
};

///klasa, ktorej obiekty przechowuja informacje o planszy
class Plansza
{
public:
    ///plansza przekonwertowana na string zlozony z 0(spacja) i .(miejsce do wpisania litery)
    std::string p;
    ///m - ilosc kolumn  n - ilosc wierszy
    unsigned m,n;

    ///pobieranie planszy
    friend Plansza &operator>>(std::istream &, Plansza &);

    ///wyswietlanie planszy
    friend std::ostream &operator<<(std::ostream &, const Plansza &);

    ///funkcja wstawia slowo do luki, zwraca nowa plansze z juz wstawionym slowem
    Plansza wstaw(std::string, Plansza, Wyraz &);

    ///funkcja rekurencyjna szukajaca rozwiazania
    ///nr - poziom zaglebienia rekurencji
    Plansza dopasuj(Plansza, std::vector<Wyraz> &,std::string [],unsigned,int);

    ///funkcja sprawdza poprawnosc ewentualnego rozwiazania
    ///potrzebne gdy kilka slow jest takich samych
    bool valid(Plansza) const;
};

///funkcja odnajduje luki na planszy, zapisuje obiekty Wyraz do vectora
void znajdz_wyrazy(Plansza, std::vector<Wyraz> &);


///funkcja pobiera od uzytkownika wyrazy do dopasowania
///ilosc wyrazow jest zgodna z iloscia luk do wypelnienia
void pobierz_wyrazy(std::string [],unsigned);

///funkcja sprawdza czy slowo mozna wstawic w luke
bool czy_wstawic(std::string , Plansza , Wyraz );


///funkcja obslugujaca diagram i slowa podane przez uzytkownika
void program();

///funkcje testujace
void test1();
void test2();
void test3();
