#include <iostream>
#include <fstream>

using namespace std;

void szyfruj(string tekst,int A, int B)
{
    for(int i=0;i<tekst.length();i++){
    int pomocnicza = tekst[i]-'a';
    pomocnicza = (pomocnicza * A)+B;
    pomocnicza %= 26;
    tekst[i] = pomocnicza + 'a';
    }
    cout<< tekst<<endl;
}

int main()
{
    fstream plik, wynik;
    string tekst;
    plik.open("tekst.txt", ios::in);
    wynik.open("wynik.txt", ios::app);
   for (int i=0; i<805;i++){
    plik>>tekst;
    if(tekst.length()>=10){
    szyfruj(tekst,5,2);}
   }
    return 0;
}

