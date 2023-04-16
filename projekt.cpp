#include<iostream>
#include<string>
using namespace std;

int main() {
    char arr[100]; //zmienna znakowa, ktora ma max 100 bitow
    cout<<"Podaj ciag: "; 
    cin.getline(arr, 100); //funkcja cout (podaj ciag) max 100 bitow
    char separator = ' '; //zmienna znakowa, ktora jest spacja
    int i = 0; // do obslugiwania petli while
	int minascii = 32; 
    int maxascii = 127;
    string s; 
    while (arr[i] != '\0') { // arr zdef w 6 lini a i w 10, != lewa strona nie jest rowna prawej stronie, czyli nie jest nullem(niczym)
        if (arr[i] != separator) { //jezeli nie jest spacja wrzuc do worka s, separator jest opisany w lini 9
            s += arr[i]; // s zmienna tymczasowa znakowa, przetrzymuje wszystko co jest miedzy spacjami (miedzy spacjami sa liczby naturalne), jak cos w tej zmiennej nie jest spacja to (+= dodaj do) worka s
        } else { //  inaczej
			int num = stoi(s); // stworz zmienna calkowita o nazwie num i wrzuc do niej konwersje stringa s na int (wazne dla lini 19)
			if (num <= minascii||num >= maxascii){ // jezeli zmienna num (w ktorej jest s) jest mniejsza rowna od 32 lub (||) wieksza rowna od 128 (linia 11 i 12 zdef) to w zakresie nie drukowalnym (bo drukowana tablica ascii zaczyna sie od 32 lini) to wyswietla sie w systemie szesnastkowym)
				cout <<"Dla ciagu: "<<s<<"Znak Ascii: \\"<< std::hex<<num << endl; //zmienia liczbe s z dziesietnej na szesnastkowa liczbe, (blabla: \\ <- reprezentacja slasha bo jeden to cudzyslow)
				s.clear(); // czyszczenie s 
			} else {
				char ch = num; //gdy liczba s jest z zakresu drukowalnego
				cout <<"Dla ciagu: "<<s<<" Znak Ascii: "<< ch << endl; //wyswietlenie znaku drukowalnego
				s.clear();
			}
        }
        i++; //po czyszczeniu s zwieksza i o 1 i wraca do lini 14

    }
	int num = stoi(s); // potrzebne poza petla bo po prostu w koncu trafimy na koniec stringa i dlatego musimy to co nazbieralismy w worku s rowniez wyswietlic
    if (num <= minascii||num >= maxascii){
		cout <<"Dla ciagu: "<<s<<" Znak Ascii: \\"<< std::hex<<num << endl;
		s.clear();
	} else {
		char ch = num;
		cout <<"Dla ciagu: "<<s<<" Znak Ascii: "<< ch << endl;
		s.clear();
	}
}