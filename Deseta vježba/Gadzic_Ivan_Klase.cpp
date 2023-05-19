// MD5:ZmRjrA1nLLjiD9mKyHWqYA==// Verifikator 5.05// Program:Klase// Opis zadatka:Klase // Autor:Ivan Gadzic// Pocetno vrijeme:1/14/2022 11:32:21 AM// Završno vrijeme:1/14/2022 1:28:58 PM// Identifikatori:main,izbor,cvrste_zapis,sifra_v,vsrste_r[20],ambalaza[10],unos,vrsta_r[20],cvrsta,*sljedeci,zapis,*lista_vrsta,sljedeci,*novi,*zadnji,zadnji,do,croba_zapis,red_b,sifra,naziv[20],croba,*zapis,*lista_robe,lista_robe,void,ispis,*tekuci,provjera,sifra_a,pretrati,pretrazi,sifra_robe// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <cstring>,// Uspješnih/neuspješnih prevodenja:57/29#include <iostream>
#include <cstring>
using namespace std;

class cvrste_zapis{
	public:
	int sifra_v;
	char vrsta_r[20];
	char ambalaza[10];
	void unos(){
		cout << "Sifra vrste robe: "; cin >> sifra_v;
		cout << "Vrsta robe: "; cin >> vrsta_r;
		cout << "Vrsta ambalaze: "; cin >> ambalaza; 
	};
	void ispis(){
		cout << "Sifra vrste robe: " << sifra_v << endl;
		cout << "Vrste robe: " << vrsta_r << endl;
		cout << "Vrsta ambalaze: " << ambalaza << endl;
	};
};

class cvrsta{
	cvrsta *sljedeci;
	public:
	cvrste_zapis zapis;
	cvrsta(){
		sljedeci = NULL;
		
	}
	void unos(){
		cvrsta *novi, *zadnji;
		zadnji = this;
		while(zadnji -> sljedeci){
			zadnji = zadnji -> sljedeci;
		};
		novi = new cvrsta;
		zadnji -> sljedeci = novi;
		novi -> zapis.unos();
	};
	void ispis(){
		cvrsta *tekuci = this -> sljedeci;
		cout << "--------------" << endl;
		while(tekuci){
			tekuci -> zapis.ispis();
			cout << "--------------" << endl;
			tekuci = tekuci -> sljedeci;
		};
	};
	void pretrazi(int sifra_a){
		cvrsta *tekuci = this -> sljedeci; 
		while(tekuci){
			if(sifra_a == tekuci -> zapis.sifra_v){
				tekuci -> zapis.ispis();
				cout << "--------------" << endl;
			}
			tekuci = tekuci -> sljedeci;
		};
	};
};

cvrsta *lista_vrsta;

class croba_zapis{
	public: 
	int red_b;
	int sifra;
	char naziv[20];
	void unos(){
		cout << "Redni broj robe: "; cin >> red_b;
		cout << "Sifra robe: "; cin >> sifra;
		cout << "Naziv robe: "; cin >> naziv;
	};
	void ispis(){
		cout << "Redni broj robe: " << red_b << endl;
		cout << "Sifra robe: " << sifra << endl;
		cout << "Naziv robe: " << naziv << endl;
	};
};

class croba{
	croba *sljedeci;
	public:
	croba_zapis *zapis;
	croba(){
		sljedeci = NULL;
		cout << "Konstruktor" << endl;
		zapis = new croba_zapis;
	};
	void unos(){
		croba *novi, *zadnji; 
		zadnji = this;
		while(zadnji -> sljedeci){
			zadnji = zadnji -> sljedeci;
		};
		novi = new croba;
		zadnji -> sljedeci = novi;
		novi -> zapis -> unos(); 
	};
	void ispis(){
		croba *tekuci = this -> sljedeci;
		cout << "--------------" << endl;
		while(tekuci){
			tekuci -> zapis -> ispis();
			cout << "--------------" << endl;
			tekuci = tekuci -> sljedeci;
		};
	};
	void pretrazi(int sifra_a){
		croba *tekuci = this -> sljedeci;
		while(tekuci){
			if(sifra_a == tekuci -> zapis -> sifra){
				tekuci -> zapis -> ispis();
				cout << "--------------" << endl;
			}
			tekuci = tekuci -> sljedeci;
		};
	}	
};

croba *lista_robe;

int main(){
	int izbor, sifra_a;
	lista_vrsta = new cvrsta;
	lista_robe = new croba;
	do{
		cout << endl;
		cout << "----Program----" << endl;
		cout << "1.Unos vrsta robe na kraj liste " << endl;
		cout << "2.Unos roba na kraj liste " << endl;
		cout << "3.Ispis vrsta robe i robe " << endl;
		cout << "4.Popis roba zadane vrste " << endl; 
		cout << "9. Kraj programa. " << endl;
		cout << "Vas odabir je: "; cin >> izbor;
		cout << endl;
		switch(izbor){
			case 1: lista_vrsta->unos(); break;
			case 2: lista_robe -> unos(); break;
			case 3: lista_vrsta->ispis(); 
				  lista_robe->ispis(); break;
			case 4: cout << "Unesite sifru robe: "; cin >> sifra_a;
				  lista_vrsta->pretrazi(sifra_a); 
  				  lista_robe -> pretrazi(sifra_a);
				  break;
			case 9: cout << "Kraj programa." << endl; break;
			default:
				cout << "Krivi odabir." << endl;
		};
	}while(izbor !=9);
	system("PAUSE");
}
  
  
