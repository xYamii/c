#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream plik, wynik;
    string haslo[200];
    int n = 200;
    plik.open("hasla.txt", ios::in);
    wynik.open("wynik3.txt", ios::app);
    wynik<<"Powtarzajace sie hasla: "<<endl;
   for (int i = 0; i<n; i++){
    plik>>haslo[i];
}
    for(int j=0; j<n-1; j++)
        for(int x=1; x<n;x++)
            if(haslo[x]<haslo[x-1]) swap(haslo[x],haslo[x-1]);

    for(int i = 1; i<n-1; i++){
        if(haslo[i]==haslo[i-1] || haslo[i]==haslo[i+1]) wynik<<haslo[i]<<endl;
        i++;
    }
return 0;
}
