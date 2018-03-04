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
    wynik << "Zadanie 72.2 " << endl;
    for(int i=0; i<200; i++)
    {
        string slowoA,slowoB ;
       plik >> slowoA >> slowoB;
        if (slowoA.length()<slowoB.length())
        {
        bool sprawdz = true;
        for(int j=0; j<slowoA.length(); j++)
            if (slowoA[j]!=slowoB[j])
                sprawdz = false;
        if (sprawdz)
        {
            wynik << slowoA << " " << slowoB << " ";
            for(int j=slowoA.length(); j<slowoB.length(); j++)
                wynik << slowoB[j];
                wynik<<endl;

        }}
    }
}
