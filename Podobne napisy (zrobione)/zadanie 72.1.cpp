#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    fstream plik, wynik;
    plik.open("napisy.txt", ios::in);
	wynik.open("wynik.txt", ios::out);

    int ilePar = 0;
    bool czyWypisano = false;
    for(int i=0; i<200; i++)
    {
        string napisA, napisB;
        plik >> napisA >> napisB;
        if (napisA.length()>=3*napisB.length() || napisA.length()*3 <= napisB.length())
        {
            ilePar++;
            if (!czyWypisano)
            {
                czyWypisano = true;
                wynik << "Pierwsza para: \n";
                wynik << napisA << " " << napisB << endl;
            }
        }
    }
    wynik << "Ilosc par " << endl;
    wynik << ilePar << endl;
}
