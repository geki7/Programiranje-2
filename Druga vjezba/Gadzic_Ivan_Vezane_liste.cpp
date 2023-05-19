// MD5:tMrAE86/rYFZSY+6GgMNGw==// Verifikator 5.05// Program:Vezane liste// Opis zadatka:Vezane liste// Autor:Ivan Gadzic// Pocetno vrijeme:10/22/2021 12:12:25 PM// Završno vrijeme:10/22/2021 1:13:42 PM// Identifikatori:main,izbor,tinv,sifra_inv,naziv_inv[35],komada,*sljedeci,*lista,lista,dod_ele,*novi,*zadnji,zadnji,ispis_ele,*tekuci,pretrazivanje,brisanje,*brisi,tekuci,zbroj,zbroj// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:26/18#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
int zbroj = 0;
struct tinv{
	int sifra_inv;
	char naziv_inv[35];
	int komada; 
	tinv *sljedeci;
};

void dod_ele(tinv *lista){
	tinv *novi, *zadnji;
	zadnji = lista;
	
	while(zadnji->sljedeci){
		zadnji = zadnji ->sljedeci;
	}
	novi = new tinv;
	zadnji -> sljedeci = novi;
	novi -> sljedeci = NULL; 
	cout << "Sifa inventara: "; cin >> novi ->sifra_inv;
	zbroj = zbroj + novi ->sifra_inv;
	cout << "Naziv inventara: "; unos(novi->naziv_inv);
	cout << "Broj komada: "; cin >> novi->komada; 
};

void ispis_ele(tinv *lista){
	tinv *tekuci = lista -> sljedeci;
	while(tekuci){
		cout << "Sifra inventara: " << tekuci ->sifra_inv << endl;
		cout << "Naziv inventara: " << tekuci ->naziv_inv << endl; 
		cout << "Broj komada: " << tekuci ->komada << endl;
		cout << "Vrijednost pokazivaca na sljedeci element: " << int ((size_t)tekuci->sljedeci) << endl; 
		tekuci = tekuci -> sljedeci; 
	};
};

void pretrazivanje(tinv *lista, int sifra_inv){
	tinv *tekuci = lista -> sljedeci; 
	while(tekuci){
		if(tekuci -> sifra_inv == sifra_inv){
			cout << "Sifra inventara: " << tekuci ->sifra_inv << endl;
			cout << "Naziv inventara: " << tekuci ->naziv_inv << endl; 
			cout << "Broj komada: " << tekuci ->komada << endl;
			return; 
		}
		tekuci = tekuci -> sljedeci; 
	};
	cout << "Element nije pronaden." << endl; 
};

void brisanje(tinv *lista, int sifra_inv){
	tinv *brisi = lista ->sljedeci, *prethodni = lista; 
	while(brisi){
		if(brisi->sifra_inv == sifra_inv){
			prethodni -> sljedeci = brisi ->sljedeci;
			delete brisi;
			cout << "Element je izbrisan iz vezane liste." << endl;
			return;
		}
		prethodni = brisi;
		brisi = brisi ->sljedeci;
	};
	cout << "Element za brisanje nije pronaden." << endl; 
};

int main(){
	int izbor, sifra_inv; 
	tinv *lista = new tinv;
	lista -> sljedeci = NULL;
	do{
		cout << "----PROGRAM----" << endl;
		cout << "1. Unos novog elementa vezane liste" << endl;
		cout << "2. Ispis sadrzaja vezane liste" << endl;
		cout << "3. Pretrazivanje vezane liste" << endl;
		cout << "4. Brisanje elemenata liste" << endl; 
		cout << "Vas odabir je: "; cin >> izbor; 
		switch(izbor){
			case 1: dod_ele(lista); break; 
			case 2: ispis_ele(lista);
					cout << "Zbroj : " << zbroj << endl; 
					break;
			case 3: cout << "Unesite sifru inventara: "; cin >> sifra_inv;
					pretrazivanje(lista, sifra_inv);
					break;
			case 4: cout << "Unesite sifru inventara za brisanje: "; cin >> sifra_inv;
					brisanje(lista, sifra_inv);
					break;
			default: 
				cout << "Krivi odabir." << endl;
		}
	}while(izbor !=9);
	system("PAUSE");
}
