#include <iostream>
#include <fstream>

using namespace std;

string szyfruj(string tekst,int A, int B)
{
    string wynik = tekst;
    for(int i=0;i<tekst.length();i++){
    int pomocnicza = wynik[i]-'a';
    pomocnicza = (pomocnicza * A)+B;
    pomocnicza %= 26;
    wynik[i] = pomocnicza + 'a';
    }
    return wynik;

}

int main()
{
    fstream plik, wynik;
    string tekst,zaszyfrowane;
    plik.open("probka.txt", ios::in);
   for (int i=0; i<5;i++){
    plik>>tekst;
    plik>>zaszyfrowane;
    bool znaleziono_1 = false;
    bool znaleziono_2 = false;
    for(int a = 0;a<=25 && !znaleziono_1;a++){
           for(int b = 0;b<=25 && !znaleziono_1;b++){
                if(szyfruj(tekst,a,b)==zaszyfrowane){
                    cout<<"Klucz szyfrujacy to : "<<a<<" i "<<b<<endl;
                    znaleziono_1 =true;
                }

    }
    }
    for(int a = 0;a<=25 && !znaleziono_2;a++){
           for(int b = 0;b<=25 && !znaleziono_2;b++){
                if(szyfruj(zaszyfrowane,a,b)==tekst){
                    cout<<"Klucz deszyfrujacy to : "<<a<<" i "<<b<<endl;
                    znaleziono_2 =true;
                }

    }
    }
}
    return 0;
}

