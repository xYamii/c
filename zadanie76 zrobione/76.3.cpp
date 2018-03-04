#include <iostream>
#include <fstream>

using namespace std;
string napis;
int klucz[6] ={6, 2, 4, 1, 5, 3};

string szyfr(string ciag){
    for(int i=49;i>=0;i--){
    swap(ciag[i],ciag[klucz[i%6]-1]);
    }
   return ciag;
}

int main()
{
    fstream plik, wyniki;
    plik.open("szyfr3.txt", ios::in);
    wyniki.open("wynik3.txt", ios::out);
    plik>>napis;
    //cout<<klucz[0];
    wyniki<<szyfr(napis);
    return 0;
}
