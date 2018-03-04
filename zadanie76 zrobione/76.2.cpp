#include <iostream>
#include <fstream>

using namespace std;
string napis;
int klucz[50];

string szyfr(string ciag){
    for(int i=0;i<50;i++){
    swap(ciag[i],ciag[klucz[i%15]-1]);
    }
   return ciag;
}

int main()
{
    fstream plik, wyniki;
    plik.open("szyfr2.txt", ios::in);
    wyniki.open("wynik.txt", ios::out);
    plik>>napis;
    for(int i=0;i<16;i++){
            plik>>klucz[i];
        }
    //cout<<klucz[0];
    wyniki<<szyfr(napis);
    return 0;
}
