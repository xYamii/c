#include <iostream>
#include <fstream>

using namespace std;
string napisy[6];
int klucz[50];

string szyfr(string ciag){
    for(int i=0;i<50;i++){
    swap(ciag[i],ciag[klucz[i]-1]);
    }
   return ciag;
}

int main()
{
    fstream plik, wyniki;
    plik.open("szyfr1.txt", ios::in);
    wyniki.open("wynik1.txt", ios::out);
    for(int i=0;i<6;i++){
            plik>>napisy[i];
        }
    for(int i=0;i<50;i++){
            plik>>klucz[i];
        }
   // cout<<klucz[0]<<endl;
    //cout<<napisy[0]<<endl;
    for(int j=0;j<6;j++){
    wyniki<<szyfr(napisy[j])<<endl;}
    return 0;
}
