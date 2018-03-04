#include <iostream>
#include <fstream>

using namespace std;


string szyfr(string slowo1,string slowo2){
    int k=slowo1[0]-slowo2[0];
    if(k<0)k=k+26;

    bool zaszyfrowane = true;
    for(int i=1;i<slowo1.length();i++){
            int n=slowo1[i]-slowo2[i];
            if(n<0)n=n+26;
        if(k!=n){
        zaszyfrowane = false;}

    }
    if(zaszyfrowane!=true){
            cout<< slowo1<<endl;
        }

}

int main()
{
    fstream plik;
    string slowo1,slowo2;
    plik.open("dane_6_3.txt",ios::in);
    for(int i=0;i<3000;i++){
        plik>>slowo1;
        plik>>slowo2;
        szyfr(slowo1,slowo2);
    }

    return 0;
}
