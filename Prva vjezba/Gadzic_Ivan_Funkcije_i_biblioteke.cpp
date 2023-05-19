// MD5:JPJm6KfDBzt21Jki5kOHGA==// Verifikator 5.05// Program:Funkcije i biblioteke// Opis zadatka:Funkcije// Autor:Ivan Gadzic// Pocetno vrijeme:10/15/2021 12:28:57 PM// Završno vrijeme:10/15/2021 1:59:52 PM// Identifikatori:main,izbor,povrsina,a,b,x,y,trokut,c,k,s,polje,*rijec,i,struktura,tautor,sifra,prezime_ime[35],prosjek_coj,*autor_1,*autor_2,autor_2,autor_1,prosjek_ocj,cout// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",#include <cmath>,#include <iomanip>,#include <cstring>,// Uspješnih/neuspješnih prevodenja:80/20#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "biblioteka_vrijeme.cc"

using namespace std;
void polje(){
	string *rijec;
	rijec = new string[4] {"Bicikli", "Monitor", "Radni stol", "Papir"};
	for(unsigned int i=0; i<4; i++){
		cout << rijec[i] << endl;
	}
}
void struktura(){
	struct tautor{
		int sifra;
		char prezime_ime[35];
		float prosjek_ocj;
	};
	tautor *autor_1, *autor_2;
	autor_1 = new tautor;
	autor_2 = new tautor; 
	
	autor_1->sifra = 529;
	strcpy(autor_1->prezime_ime, "Maric Marko");
	autor_1->prosjek_ocj = 4.35;
	
	memcpy(autor_2, autor_1, sizeof(tautor));
	
	cout << "Sifra: " << autor_2->sifra << endl;
	cout << "Prezime i ime: " << autor_2->prezime_ime << endl;
	cout << "Prosjecna ocjena: " << autor_2->prosjek_ocj << endl; 
}

void povrsina(){
	int a, b;
	cout << "Unesite a i b: "; cin >> a >> b;
	if(a<0){
		a = abs(a);
	}
	if(b<0){
		b = abs(b);
	}
	if(a>0 || b>0){
		cout << "Povrsina je: " << a*b << endl;
	}
}

void trokut(){
	float a, b, c, k, s;
	do{
		vrijeme_pocetak();
		cout << "Unesite stranicu a, b i c: "; cin >> a >> b >> c;
		s = (a+b+c)/2;
		k = sqrt((s*(s-a)*(s-b)*(s-c)));
		if(k>0){
			cout << "Povrsina trokuta je: " << fixed <<setprecision(2)<< k << endl;
		}
	}while(k<0);
	vrijeme_kraj();
	cout << "Vrijeme proteklo je: " << vrijeme_proteklo()/10 << "Desetinke sekunde" << endl;
}

int main(){
	int izbor;
	do{
		cout << "1. Polje" << endl;
		cout << "2. Funkcija" << endl;
		cout << "3. Struktura" << endl;
		cout << "4. Mjerenje vremena" << endl; 
		cout << "9. Izlaz iz programa" << endl;
		cout << "Vas odabir: "; 
		cin >> izbor;
		switch(izbor){
			case 1: polje(); break;
			case 2: povrsina(); break;
			case 3: struktura(); break;
			case 4: trokut(); break;
			default:
				cout << "Pogresan unos..." << endl;	
		}
	}while(izbor !=9);
	system("PAUSE");
}
  
  
