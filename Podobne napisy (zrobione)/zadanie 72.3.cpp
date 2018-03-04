#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string wynika[200];
    string wynikb[200];
    int x=0;
    fstream plik, wynik;
    string tekst1, tekst2, pom, pom2;
    int maxi = 0, j=0, dlugosc=0;
    plik.open("napisy.txt", ios::in);
    wynik.open("wynik.txt", ios::app);

   for (int i = 1; i<=200; i++){
          plik>>tekst1>>tekst2;
          pom = tekst1;
          pom2 = tekst2;
          for(int n=0; n<pom.length();n++){

            tekst1[n]=pom[pom.length()-1-n];

          }
          for(int n=0; n<pom2.length();n++){

            tekst2[n]=pom2[pom2.length()-1-n];

          }
          j = 0;
          dlugosc = 0;
         while(j<tekst1.length()-1 && j<tekst2.length()-1){
            if(tekst1[j]==tekst2[j]) {
            dlugosc++;
            j++;
            }
            else break;

         }
         if(dlugosc == maxi){
            wynika[x]=pom;
            wynikb[x]=pom2;
            x++;
         }
         if(dlugosc>maxi) {
                maxi = dlugosc;
                x = 0;
                wynika[x]=pom;
                wynikb[x]=pom2;
                x++;


         }

   }
    wynik<<"Najdluzsza wspolna koncowka: "<<maxi<<endl;
    for(int t=0; t<=x;t++){
        wynik<<wynika[t]<< " "<< wynikb[t]<<endl;
    }

    return 0;
}
