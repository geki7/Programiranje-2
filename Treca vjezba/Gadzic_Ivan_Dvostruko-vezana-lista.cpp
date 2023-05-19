// MD5:055g3EziaaaoaUE16bSLHw==// Verifikator 5.05// Program:Dvostruko-vezana-lista// Opis zadatka:Dvostruko_vezana_lista// Autor:Ivan Gadzic// Pocetno vrijeme:10/29/2021 11:18:05 AM// Završno vrijeme:10/29/2021 1:30:18 PM// Identifikatori:main,izbor,tracunalo,sifra_r,naziv_r[20],proizvodac[20],god_p,trac,dod_ele,*sljedeci,*lista,*novi,*zadnji,lista,zadnji,*prethodni,novi,*tekuci,dod_ele_k,dod_ele_p,sljedeci,int,bris_ele,*brisi,brisi_ele,a,vrijeme// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <ctime>[B],#include <iostream>[B],#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:54/30#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct trac{
	int sifra_r;
	char naziv_r[20];
	char proizvodac[20];
	int god_p;
	long vrijeme;
	trac *sljedeci;
	trac *prethodni;
};
void dod_ele_k(trac *lista){
	trac *novi, *zadnji;
	zadnji = lista;
	while(zadnji->sljedeci){
		zadnji = zadnji -> sljedeci;
	};
	novi = new trac;
	novi -> prethodni = zadnji; 
	novi -> sljedeci = NULL;
	zadnji -> sljedeci = novi;
	vrijeme_pocetak();
	cout << "Sifra racunala: "; cin >> novi -> sifra_r;
	cout << "Naziv racunala: "; unos(novi -> naziv_r);
	cout << "Naziv proizvodaca: "; unos(novi -> proizvodac); 
	cout << "Godina proizovodnje: "; cin >> novi -> god_p;
	vrijeme_kraj();
	novi -> vrijeme = vrijeme_proteklo()/1000;
	trac *tekuci = lista -> sljedeci;
	while(tekuci){
		cout << "Sifra racunala: " << tekuci -> sifra_r << endl;
		cout << "Naziv racunala: " << tekuci -> naziv_r << endl;
		cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
		cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
		cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
		tekuci = tekuci -> sljedeci;
	};
};

void dod_ele_p(trac *lista){
	trac *tekuci = lista -> sljedeci;
	while(tekuci){
		cout << "Sifra racunala: " << tekuci -> sifra_r << endl;
		cout << "Naziv racunala: " << tekuci -> naziv_r << endl;
		cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
		cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
		cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
		tekuci = tekuci -> sljedeci;
	};
	if(!lista -> sljedeci){
		dod_ele_k(lista);
		return;
	};
	trac *novi, *sljedeci;
	sljedeci = lista -> sljedeci;
	novi = new trac;
	novi -> prethodni = lista;
	novi -> sljedeci = sljedeci;
	lista -> sljedeci = novi;
	sljedeci -> prethodni = novi;
	vrijeme_pocetak();
	cout << "Sifra racunala: "; cin >> novi -> sifra_r;
	cout << "Naziv racunala: "; unos(novi -> naziv_r);
	cout << "Naziv proizvodaca: "; unos(novi -> proizvodac); 
	cout << "Godina proizovodnje: "; cin >> novi -> god_p;
	vrijeme_kraj();
	novi -> vrijeme = vrijeme_proteklo()/1000;
};

void brisi_ele(trac *lista, int sifra_r){
	char a;
	trac *brisi = lista -> sljedeci, *prethodni = lista;
	trac *tekuci = lista -> sljedeci; 
	while(brisi){
		if(brisi->sifra_r == sifra_r){
			cout << "Zelite li izbrisati listu d/n: "; cin >> a;
			if(a == 'D' || a == 'd'){
				while(tekuci){
					cout << "Sifra racunala: " <<  tekuci -> sifra_r << endl;
					cout << "Naziv racunala: " <<  tekuci -> naziv_r << endl;
					cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
					cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
					cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
					prethodni -> sljedeci = brisi -> sljedeci;
					delete brisi;
					cout << "Element je izbirsan iz vezane liste." << endl;
					return;
				};
			};
		};
		prethodni = brisi;
		brisi = brisi -> sljedeci;
	};
	cout << "Element za brisanje u vezanoj listi nije pronaden." << endl;
};

int main(){
	int izbor, sifra_r;
	trac *lista = new trac;
	lista -> sljedeci = NULL;
	lista -> prethodni = NULL; 
	do{
		cout << "----Program----" << endl;
		cout << "1. Dodavanje elemenata na kraj dvoustrko vezane liste" << endl;
		cout << "2. Dodavanje elemenata na pocetak dvostruko vezane liste" << endl; 
		cout << "3. Brisanje cvora iz vezane liste" << endl;
		cout << "4. Binarno stablo" << endl; 
		cout << "Vas odabir je: "; cin >> izbor; 
		switch(izbor){
			case 1 : dod_ele_k(lista); break;
			case 2 : dod_ele_p(lista); break;
			case 3 : cout << "Unesite sifru racunala: "; cin >> sifra_r;
					brisi_ele(lista, sifra_r); break;
			case 4 : cout << "4" << endl; 
					break;
			default :
				cout << "Krivi odabir..." << endl; 
		}; 
	}while(izbor !=9);
	system("PAUSE");
}
  
