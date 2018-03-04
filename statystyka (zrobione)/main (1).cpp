#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int pom[26];

double Alfabet[26] = {0.0};
double WszystkieLitery = 0.0;

bool DwieKolejneLitery(string s)
{
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] == s[i-1]) return true;
    }
    return false;
}

void LiczLitery(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        WszystkieLitery++;
        char litera = s[i];
        Alfabet[litera - 'A']++;
    }
}
int Spolgloski(string z)
{
    int s = 0;
    int dlCiag = 0;
    for(int i=0; i<z.length(); i++)
    {
        if (z[i]=='A' || z[i]=='E' || z[i]=='O' || z[i]=='U' || z[i]=='I' || z[i]=='Y')
            s = 0;
        else
            s++;
        if (s > dlCiag)
            dlCiag = s;
    }
    return dlCiag;
}


int main()
{

	int Zadanie1 = 0;
    int najdluzszyCiag = 0;
    int ilosc = 0;
	string Slowo ,pierwszy;
	fstream plik, wyniki;
	plik.open("tekst.txt", ios::in);
	wyniki.open("wyniki.txt", ios::out);
	if (plik.good())
	{
		for (int i = 0; i <= 1876; i++)
		{
			plik >> Slowo;
            int k = Spolgloski(Slowo);
            if (k>najdluzszyCiag)
            {
            najdluzszyCiag = k;
            ilosc = 1;
            pierwszy = Slowo;
        }
        else if (k==najdluzszyCiag)
            ilosc ++;

        if (DwieKolejneLitery(Slowo)) Zadanie1++;
			LiczLitery(Slowo);
		}

		wyniki << "73.1: " << Zadanie1 << endl;
		wyniki << "73.2: " << endl;
		for (int i = 0; i < 26; i++)
		{
			char litera = i + 'A';
			int IloscLiter = Alfabet[i];
			double procent = (Alfabet[i] * 100.0) / WszystkieLitery;
			wyniki << litera << ": " << IloscLiter << " (" << setprecision(2) << fixed << procent << "%)" << endl;
		}
		wyniki<<"73.3: \nNajdluzszy ciag: "<<najdluzszyCiag << endl;
        wyniki << "Znalezionych slow: " << ilosc << endl;
        wyniki << "Pierwsze z nich: " << pierwszy << endl;


	}
	else
		cout << "Blad otwarcia pliku." << endl;
    return 0;
}
