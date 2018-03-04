#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

bool same_cyfry( string pass )
{
	for ( int i = 0; i < pass.length(); i++ )
	{
		if( pass[i] < '0' || pass[i] > '9' )
			return false;
	}

	return true;
}

bool trudne_haslo( string pass )
{
	bool cyfra = false, mala = false, duza = false;

	for ( int i = 0; i < pass.length(); i++ )
	{
		if( pass[i] <= '9' && pass[i] >= '0' )
			cyfra = true;

		if( pass[i] <= 'z' && pass[i] >= 'a' )
			mala = true;

		if( pass[i] <= 'Z' && pass[i] >= 'A' )
			duza = true;
	}
	if (cyfra && mala && duza)
	return true;
}


int main()
{
    char a, b, c, d;
    int licznik = 0;
	string haslo, takieSamo;
	string tabHasla[200] = {};
	fstream plik, wyniki;
	plik.open("hasla.txt", ios::in);
	wyniki.open("wynik.txt", ios::out);

	int numeryczne = 0, trudne = 0;

	for ( int i = 0; i < 200; i++)
	{
		plik >> haslo;
		tabHasla[i]=haslo;

		if( same_cyfry(haslo) )
			numeryczne++;

		if( trudne_haslo(haslo) )
			trudne++;
	}

	sort(tabHasla, tabHasla+200);



	 wyniki<< "74.1 \n" << numeryczne << endl;
	 wyniki<< "74.2 \n";
	 sort(tabHasla,tabHasla+200);
	 	for ( int i = 1; i < 200; i++)
	{
		if( tabHasla[i] == tabHasla[i-1] )
		{
			takieSamo = tabHasla[i];
			wyniki << takieSamo << endl;
		}
	}
	wyniki << "74.3 \n";
	for (int z = 0; z<200; z++){
    haslo = tabHasla[z];
	if(haslo.length()>=4){
    for(int x=0;x<haslo.length()-3; x++){
            a = haslo[x];
            b = haslo[x+1];
            c = haslo[x+2];
            d = haslo[x+3];
     char ciag[4] = {a,b,c,d};

    for(int j=0; j<3; j++)
            for(int t=1; t<4; t++){
                if(ciag[t]<ciag[t-1]) swap(ciag[t],ciag[t-1]);}

                a = ciag[0];
                b = ciag[1];
                c = ciag[2];
                d = ciag[3];
        if(a+1==b && b+1==c && c+1==d)
    {
        licznik ++;
        break;
    }
    }
	}}
    wyniki<<"Liczba uzytkownikow posiadajacy haslo z 4 kolejnych znakow ASCII: "<<licznik<<endl;
	wyniki << "74.4 \n" << trudne << endl;
}
