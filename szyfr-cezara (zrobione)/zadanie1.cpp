#include <iostream>
#include <fstream>

using namespace std;

string slowa[200];

string szyfr(string slowo){
    int k=107;
    int n=k%26;
    for(int i=0;i<slowo.length();i++){
            if(slowo[i]+n > 'Z'){
        slowo[i]=(char)(slowo[i]+n-26);
            }
        else
        slowo[i]=(char)(slowo[i]+n);
    }
    cout<< slowo<<endl;

}

int main()
{
    fstream plik,wyniki;
    plik.open("dane_6_1.txt",ios::in);
    wyniki.open("wyniki_6_1.txt",ios::out);
    for(int i=0;i<100;i++){
        plik>>slowa[i];
        szyfr(slowa[i]);
    }

    return 0;
}
