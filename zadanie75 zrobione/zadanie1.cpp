#include <iostream>
#include <fstream>

using namespace std;

//string napisy[805];

void sprawdz(string napis){
    if(napis[napis.length()-1] == 'd' && napis[0] == 'd')
    {
        cout<<napis<<endl;
    }
}

int main()
{
    fstream plik,wynik;
    string napis;
    plik.open("tekst.txt",ios::in);

    for(int i=0;i<805;i++){
        plik>>napis;
        sprawdz(napis);
    }
    plik.close();
    return 0;
}
