// MD5:tdz83JdoEWuf/bAvOQjpag==// Verifikator 5.05// Program:Datoteka// Opis zadatka:Datoteka s fiksnom velicinom zapisa// Autor:Ivan Gadzic// Pocetno vrijeme:10/8/2021 12:25:30 PM// Završno vrijeme:10/8/2021 12:47:03 PM// Identifikatori:main,izbor,tslog,mat_br,prez_ime[35],g_upisa,slog,dat,unos,jos,*,ispis// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,#include <fstream>,// Uspješnih/neuspješnih prevodenja:26/5#include <iostream>
#include <fstream>
using namespace std;

struct tslog{
	int mat_br;
	char prez_ime[35];
	int g_upisa; 
};

tslog slog;
fstream dat; 

void unos(){
	char jos = 'd';
	dat.open("podaci.dat", ios::out | ios::binary);
	while((jos == 'd') || (jos=='D')){
		cout << "Maticni broj: "; 
		cin >> slog.mat_br;
		cout << "Prezime i ime: "; 
		cin >> slog.prez_ime; 
		cout << "Godina upisa: ";
		cin >> slog.g_upisa; 
		dat.write ((char *) &slog,sizeof(slog));
		cout << "Hocete li jos upisivati (d/n) ?"; 
		cin >> jos;
	}
	dat.close();
	dat.clear();
};

void ispis(){
	dat.open("podaci.dat", ios::in | ios::binary);
	while(1){
		dat.read ((char *) &slog, sizeof(slog));
		if(dat.eof()) break;
		cout << "Maticni broj : " << slog.mat_br << endl;
		cout << "Prezime i ime: " << slog.prez_ime << endl;
		cout << "Godina upisa: " << slog.g_upisa << endl; 
		cout << endl; 
	};
	dat.close();
	dat.clear(); 
};


int main(){
	int izbor; 
	do{
		cout << endl; 
		cout << "Izaberite: " << endl << endl;
		cout << "1. Unos podataka u datoteku" << endl;
		cout << "2. Ispis podataka iz datoteke" << endl; 
		cout << "9. Izlaz iz programa" << endl; 
		cout << "Vas izbor: "; cin >> izbor; 
		switch(izbor){
			case 1: unos(); break;
			case 2: ispis(); break;
			default: 
				cout << "Pogresan unos..." << endl;
		}; 
	}while(izbor !=9);
	cout << "Kraj programa" << endl; 
	system("PAUSE");
}
