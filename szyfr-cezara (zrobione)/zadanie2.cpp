#include <iostream>
#include <fstream>

using namespace std;


string szyfr(string slowo,int klucz){
    int k=klucz;
    int n=k%26;
    for(int i=0;i<slowo.length();i++){
            if(slowo[i]-n < 'A'){
        slowo[i]=(char)(slowo[i]-n+26);
            }
        else
        slowo[i]=(char)(slowo[i]-n);
    }
    return slowo;

}

int main()
{
    fstream plik;
    int klucz;
    string slowa;
    plik.open("dane_6_2.txt",ios::in);
    for(int i=0;i<3000;i++){
        plik>>slowa;
        plik>>klucz;
        cout<<szyfr(slowa,klucz)<<endl;
    }

    return 0;
}
