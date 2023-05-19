// MD5:+7DZ+VR0SAbX2zEyZzyUPQ==// Verifikator 5.05// Program:Klase// Opis zadatka:Klase-test// Autor:Ivan Gadzic// Pocetno vrijeme:12/10/2021 12:01:05 PM// Završno vrijeme:12/10/2021 1:57:52 PM// Identifikatori:main,izbor,ctrokut,broj_unesenih,sifra_t,a,b,c,s,povrsina_trokuta,*p,*pok,*trokut,else,unos_t,trokut,cout,ispis_t,i,broj_unesenih>i,n,ispis// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cmath>,#include "cvrijeme.cc",// Uspješnih/neuspješnih prevodenja:50/29#include <iostream>
#include <cmath>
#include "cvrijeme.cc"
using namespace std;

class ctrokut{
	public: static int broj_unesenih;
		  int sifra_t;
  		  float a, b, c;
  	private: float s;
	public: float povrsina_trokuta(){
			s = (a+b+c)/2;
			if(sqrt(s*(s-a)*(s-b)*(s-c)) > 0){
				return sqrt(s*(s-a)*(s-b)*(s-c));
			}
			else{
				return -1;
			}
		};
		void unos_t(){
			cout << "Sifra trokuta: "; cin >> sifra_t;
			cout << "Stranica A: "; cin >> a;
			cout << "Stranica B: "; cin >> b;
			cout << "Stranica C: "; cin >> c;
		};
		void ispis_t(){
			if(povrsina_trokuta() != -1){
				cout << endl;
				cout << "Sifra trokuta: " << sifra_t << endl;
				cout << "Stranica A: " << a << endl;
				cout << "Stranica B: " << b << endl;
				cout << "Stranica C: " << c << endl;
				cout << "Povrsina trokuta je: " << povrsina_trokuta(); 
				cout << endl;
			}
			else{
				cout << "Tri stranice ne cine trokut..." << endl;
			}
		};
		void ispis(int i){
			if(povrsina_trokuta() != -1){
				cout << endl;
				cout << "Ovo je trokut..." << endl;
				cout << "Sifra trokuta: " << sifra_t << endl;
				cout << "Stranica A: " << a << endl;
				cout << "Stranica B: " << b << endl;
				cout << "Stranica C: " << c << endl;
				cout << "Povrsina trokuta je: " << povrsina_trokuta(); 
				cout << endl;
			}
			else{
				cout << endl;
				cout << "Ovo nije trokut..." << endl;
				cout << "Sifra trokuta: " << sifra_t << endl;
				cout << "Stranica A: " << a << endl;
				cout << "Stranica B: " << b << endl;
				cout << "Stranica C: " << c << endl;
			}
		};
};

int ctrokut::broj_unesenih;
ctrokut *trokut;
ctrokut *pok;

int main(){
	int izbor, n;
	ctrokut::broj_unesenih = 0;
	do{
		cout << endl;
		cout << "----Program----" << endl;
		cout << "1. Upis" << endl;
		cout << "2. Ispis" << endl;
		cout << "3. Upis polja" << endl;
		cout << "4. Ispis polja" << endl;
		cout << "9. Kraj programa" << endl;
		cout << "Vas odabir je: "; cin >> izbor;
		cout << endl;
		switch(izbor){
			case 1: if(!pok){
					cout << "Alokacije neuspjesna" << endl;
					pok = new ctrokut;
					cout << endl;
				}
				pok -> unos_t();
				break;
			case 2: pok -> ispis_t(); break;
			case 3: if(!trokut){
					cout << "Alokacija neuspjesna" << endl;
					cout << "Koliko mjesta zelite kreirati: "; cin >> n;
					trokut = new ctrokut[n];
					trokut[ctrokut::broj_unesenih].unos_t();
					ctrokut::broj_unesenih++;
				 }
 				else{
				 trokut[ctrokut::broj_unesenih].unos_t();
				 ctrokut::broj_unesenih++;
 				} break;
			case 4: for(int i = 0; ctrokut::broj_unesenih>i; i++){
					trokut[i].ispis(i);
				};break;
			case 9: cout << "Kraj programa." << endl; break;
			default: 
				cout << "Krivi odabir... " << endl;
		};
	}while(izbor !=9);
	system("PAUSE");
}
  
  
  
  
  
