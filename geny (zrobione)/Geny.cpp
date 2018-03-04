#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string Genotypy[1000];

int IloscGenotypow[501];
int IloscGatunkow;
int NajwiekszaLiczbaOsobnikow;
void Zadanie1()
{
    for(int i=0; i<1000; i++)
    {
        string Genotyp = Genotypy[i];
        IloscGenotypow[Genotyp.length()]++;
    }

    for(int i=1; i<501; i++)
        if(IloscGenotypow[i]>0)
            IloscGatunkow++;

    for(int i=1; i<501; i++)
        if(NajwiekszaLiczbaOsobnikow < IloscGenotypow[i])
            NajwiekszaLiczbaOsobnikow = IloscGenotypow[i];
}

int IloscOsobnikowMaMutacje;
void Zadanie2()
{
    for(int i=0; i<1000; i++)
    {
        string Genotyp = Genotypy[i];
        bool CzyZnalezionoMutacje = false;
        while(CzyZnalezionoMutacje == false)
        {
            size_t PozAA = Genotyp.find("AA");
            if(PozAA == string::npos)
                break;
            size_t PozBB = Genotyp.find("BB");
            if(PozBB == string::npos)
                break;
            string Gen = Genotyp.substr(PozAA+2, PozBB - PozAA - 2);
            size_t PozMutacja = Gen.find("BCDDC");
            if(PozMutacja == string::npos)
                break;
            IloscOsobnikowMaMutacje++;
            CzyZnalezionoMutacje = true;
        }
    }
}

int NajwiekszaLiczbaGenow;
int NajdluzszyGen;
void Zadanie3()
{
    for(int i=0; i<1000; i++)
    {
        int LiczbaGenow = NajwiekszaLiczbaGenow, DlugoscGenu = NajdluzszyGen;
        string Genotyp = Genotypy[i];
        while(Genotyp.length() > 0)
        {
            size_t PozAA = Genotyp.find("AA");
            if(PozAA == string::npos)
                break;
            size_t PozBB = Genotyp.find("BB");
            if(PozBB == string::npos)
                break;
            string Gen = Genotyp.substr(PozAA, PozBB - PozAA);
            LiczbaGenow++;
            DlugoscGenu = Gen.length();
            Genotyp.erase(PozAA, PozBB - PozAA);
        }
        if(LiczbaGenow > NajwiekszaLiczbaGenow)
            NajwiekszaLiczbaGenow = LiczbaGenow;
        if(DlugoscGenu > NajdluzszyGen)
            NajdluzszyGen = DlugoscGenu;
    }
}


int LiczbaOdpornych = 0, LiczbaSilnieOdpornych = 0;
string CzescKodujaca(string genotyp)
{
    string Kod = "";
    bool CzyAA = false;
    int PozAA, PozBB;
    int i = 1;
    while(i<genotyp.length())
    {
        if(CzyAA)
        {
            if(genotyp[i-1]=='B' && genotyp[i]=='B')
            {
                PozBB = i;
                Kod += genotyp.substr(PozAA, PozBB - PozAA) + ";";
                CzyAA = false;
            }
        }
        else
        {
            if(genotyp[i-1]=='A' && genotyp[i]=='A')
            {
                CzyAA = true;
                PozAA = i-1;
            }
        }
        i++;
    }
    return Kod;
}
void Zadanie4()
{
    for(int i=0; i<1000; i++)
    {
        string Genotyp = Genotypy[i];
        string GenotypOdwrotnie = Genotyp;
        reverse(GenotypOdwrotnie.begin(), GenotypOdwrotnie.end());

        if(Genotyp == GenotypOdwrotnie)
        {
            LiczbaSilnieOdpornych++;
            continue;
        }
        if(CzescKodujaca(Genotyp) == CzescKodujaca(GenotypOdwrotnie))
            LiczbaOdpornych++;

    }
}

int main()
{
    fstream plik, wyniki;

    plik.open("dane_geny.txt", ios::in);
    wyniki.open("wyniki_gen.txt", ios::out);

    if(plik.good())
    {
        cout<<"Otwarto plik...\n";
        for(int i=0; i<1000; i++)
            plik>>Genotypy[i];
        plik.close();

        Zadanie1();
        wyniki<<"69.1:\nLiczba gatunkow: "<<IloscGatunkow<<"\nNajwieksza liczba osobnikow tego samego gatunku: "<<NajwiekszaLiczbaOsobnikow<<endl;
        cout<<"Wykonano zadanie 1\n";

        Zadanie2();
        wyniki<<"\n69.2:\nIlosc osobnikow: "<<IloscOsobnikowMaMutacje<<endl;
        cout<<"Wykonano zadanie 2\n";

        Zadanie3();
        wyniki<<"\n69.3:\nNajwieksza liczba genow: "<<NajwiekszaLiczbaGenow<<"\nNajwieksza dlugosc genu: "<<NajdluzszyGen<<endl;
        cout<<"Wykonano zadanie 3\n";

        Zadanie4();
        wyniki<<"\n69.3:\nLiczba genotypow odpornych: "<<LiczbaOdpornych<<"\nLiczba genotypow silnie odpornych: "<<LiczbaSilnieOdpornych<<endl;
        cout<<"Wykonano zadanie 4\n";

        wyniki.close();
    }
    else
        cout<<"Blad otwarcia pliku.\n";

    return 0;
}
