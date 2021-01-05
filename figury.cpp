#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

class Figura
{
protected:
    double a;
    double b;

public:
    virtual double wypisz() = 0;
};

class Fig_2D :public Figura
{
protected:
    double pole;

public:
    virtual double Pole() { return pole; }
    virtual double wypisz()
    {
        cout << "\n\n Licze pole ... \n\n";
        return 0;
    }
};

class Fig_3D :public Figura
{
protected:
    double objetosc;

public:
    virtual double Objetosc() { return objetosc; };
    virtual double wypisz()
    {
        cout << "\n\n Licze objetosc ... \n\n";
        return 0;
    }
};

class Kolo : public Fig_2D
{
protected:
    double wypisz()
    {
        Fig_2D::wypisz();
        cout << "Wprowadz wartosc promienia: " << endl;
        cin >> a;
        pole = M_PI * a * a;
        cout << "Pole kola: " << pole << "\n";
        return pole;
    }
};

class Kwadrat : public Fig_2D
{
protected:
    double wypisz()
    {
        Fig_2D::wypisz();
        cout << "Wprowadz wartosc boku kwadratu: ";
        cin >> a;
        pole = a * a;
        cout << "Pole Kwadratu:  " << pole << endl;
        return pole;
    }
};

class Trojkat : public Fig_2D
{
protected:
    double wypisz()
    {
        Fig_2D::wypisz();
        cout << "Wprowadz wartosc podstawy trojkata: ";
        cin >> a;
        cout << "Wprowadz wartosc wysokosci trojkata: ";
        cin >> b;
        pole = 0.5 * a * b;
        cout << "Pole Trojkata:  " << pole << endl;
        return pole;
    }
};

class Prostokat : public Fig_2D
{
protected:
    double wypisz()
    {
        Fig_2D::wypisz();
        cout << "Wprowadz wartosc boku prostokata: ";
        cin >> a;
        cout << "Wprowadz wartosc drugiego boku prostoka: ";
        cin >> b;
        pole = a * b;
        cout << "Pole Prostokata :  " << pole << endl;
        return pole;
    }
};


class Szescian :public Fig_3D
{
protected:
    double wypisz()
    {
        Fig_3D::wypisz();
        cout << "Wprowadz wartosc boku szescianu: ";
        cin >> a;
        objetosc = a * a * a;
        cout << "Objetosc szescianu:  " << objetosc << endl;
        return objetosc;
    }
};

class Kula :public Fig_3D
{
protected:
    double wypisz()
    {
        Fig_3D::wypisz();
        cout << "Wprowadz wartosc promienia kuli: ";
        cin >> a;
        objetosc = 4.0 / 3 * M_PI * a * a * a;
        cout << "Objetosc Kuli:  " << objetosc << endl;
        return objetosc;
    }
};

class Stozek : public Fig_3D
{
protected:
    double wypisz()
    {
        Fig_3D::wypisz();
        cout << "Wprowadz wartosc promienia stozka: ";
        cin >> a;
        cout << "Wprowadz wartosc wysokosci stozka: ";
        cin >> b;
        objetosc = (a * a * b * M_PI) / 3;
        cout << "Objetosc Stozka:  " << objetosc << endl;
        return objetosc;
    }
};

class Walec : public Fig_3D
{
protected:
    double wypisz()
    {
        Fig_3D::wypisz();
        cout << "Wprowadz wartosc promienia walca: ";
        cin >> a;
        cout << "Wprowadz wartosc wysokosci walca: ";
        cin >> b;
        objetosc = (a * a * b * M_PI);
        cout << "Objetosc walca:  " << objetosc << endl;
        return objetosc;
    }
};

int main()
{
    int WYBOR;

    Figura* a;
    while (true)
    {
        
        std::cout << "Powrót do menu... ";
        Sleep(3000);
        std::cout << "\x1B[2J\x1B[H";
        
        cout << "1 Chce obliczyc pole" << endl;
        cout << "2 Chce obliczyc objetosc" << endl;
        cout << "3 EXIT" << endl;
        cin >> WYBOR;

        switch (WYBOR)
        {
        case 1:
            cout << "1 Oblicz pole Kola" << endl;
            cout << "2 Oblicz pole Kwadratu" << endl;
            cout << "3 Oblicz pole Trojkata" << endl;
            cout << "4 Oblicz pole Prostokata" << endl;
            cout << "5 POWROT DO GLOWNEGO MENU" << endl;
            cin >> WYBOR;

            switch (WYBOR)
            {
            case 1:
                a = new Kolo;
                a->wypisz();
                break;
            case 2:
                a = new Kwadrat;
                a->wypisz();
                break;
            case 3:
                a = new Trojkat;
                a->wypisz();
                break;
            case 4:
                a = new Prostokat;
                a->wypisz();
                break;
            case 5:
                break;
            default:
                cout << "ZLY WYBOR!!!";
                break;
            }
            break;
        case 2:
            cout << "1 Oblicz objetosc Szescian" << endl;
            cout << "2 Oblicz objetosc Kula" << endl;
            cout << "3 Oblicz objetosc Stozek" << endl;
            cout << "4 Oblicz objetosc Walec" << endl;
            cout << "5 POWROT DO GLOWNEGO MENU" << endl;
            cin >> WYBOR;

            switch (WYBOR)
            {
            case 1:
                a = new Szescian;
                a->wypisz();
                break;
            case 2:
                a = new Kula;
                a->wypisz();
                break;
            case 3:
                a = new Stozek;
                a->wypisz();
                break;
            case 4:
                a = new Walec;
                a->wypisz();
                break;
            case 5:
                break;
            default:
                cout << "ZLY WYBOR!!!";
                break;
            }
            break;
        }
    }
    return 0;
}