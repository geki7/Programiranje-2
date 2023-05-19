// MD5:JKHdl7oDpC/P1aE3/pWHlQ==// Verifikator 5.05// Program:Test// Opis zadatka:Test// Autor:Ivan Gadzic// Pocetno vrijeme:11/29/2021 11:16:05 AM// Završno vrijeme:11/29/2021 1:10:14 PM// Identifikatori:main,izbor,dat,ind,tstudent,rb_zapisa,sifra_p,naziv_p[30],smjer[20],broj_P,tindeks,smjer,kreir_dat,kreirano,naziv_dat[30],naziv_ind[30],zelja,naziv_dat[],naziv_ind[],naziv_dat,naziv_ind,naziv_dat[20],naziv_ind[20],slog,dat[],ind[],unos,broj_p,brojac,*,pretraga,sifra,pronadjen,ukupno,ispis// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cstdlib>[B],#include <fstream>[B],#include <cstring>[B],#include <string.h>,#include "biblioteka_tel_imenik.cc" ,#include <time.h>[B],#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc" ,// Uspješnih/neuspješnih prevodenja:87/57#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc" 
using namespace std;
fstream dat, ind;

struct tstudent{
	int sifra_p;
	char naziv_p[30];
	char smjer[20];
	int broj_p;
};

tindeks indeks;
tstudent slog;
int brojac = 0;
int ukupno = 0;

char naziv_dat[20];
char naziv_ind[20];

void kreir_dat(){
	char zelja;
	cout << "Zelite li koristit vec odabrano ime (d/n): "; cin >> zelja;
	if(zelja == 'd' || zelja == 'D'){
		strcpy(naziv_dat, "predmeti.dat");
		strcpy(naziv_ind, "predmeti.ind");
		dat.open(naziv_dat, ios::out);
		dat.close();
		ind.open(naziv_ind, ios::out);
		ind.close();
	}
	else{
		cout << "Unesite naziv maticne dat: "; cin >> naziv_dat;
		dat.open(naziv_dat, ios::out);
		dat.close();
		cout << "Unesite naziv indeksne dat: "; cin >> naziv_ind;
		ind.open(naziv_ind, ios::out);
		ind.close();
	}
	cout << endl;
};

void unos(){
	cout << "Sifra predmeta: "; cin >> slog.sifra_p;
	cout << "Naziv predmeta: "; unos(slog.naziv_p);
	cout << "Naziv smjera: "; unos(slog.smjer);
	cout << "Broj prijava: "; cin >> slog.broj_p;
	indeks.kljuc = slog.sifra_p;
	indeks.adresa = brojac * sizeof(slog);
	dat.open(naziv_dat, ios::out | ios::app | ios::binary);
	dat.write((char *) &slog, sizeof(slog));
	dat.close(); dat.clear();
	ind.open(naziv_ind, ios::out | ios::app | ios::binary);
	ind.write((char *) &indeks, sizeof(indeks));
	ind.close(); ind.clear();
	brojac++;
	preslozi_indeks(naziv_ind, indeks);
	cout << endl;	
}

void pretraga(){
	dat.open(naziv_dat, ios::in | ios::binary);
	ind.open(naziv_ind, ios::in | ios::binary);
	int sifra;
	cout << "Unesite sifru predemta: "; cin >> sifra;
	bool pronadjen = false;
	while(1){
		ind.read((char *) &indeks, sizeof(indeks));
		if(ind.eof()){
			break;
		}
		dat.seekg(indeks.adresa);
		dat.read((char *) &slog, sizeof(slog));
		if(sifra == slog.sifra_p){
			pronadjen = true; 
			cout << "Sifra predmeta: " << slog.sifra_p << endl;
			cout << "Naziv predmeta: " << slog.naziv_p << endl;
			cout << "Smjer: " << slog.smjer << endl;
			cout << "Broj prijava: " << slog.broj_p << endl;
			cout << endl; 
			break;
		}
	};
	dat.close();
	ind.close();
	if(!pronadjen){
		cout << "Predmet ne postoji." << endl;
	}
}

void ispis(){
	dat.open(naziv_dat, ios::in | ios::binary);
	ind.open(naziv_ind, ios::in | ios::binary);
	while(1){
		ind.read((char *) &indeks, sizeof(indeks));
		if(ind.eof()){
			break;
		}
		ukupno++;
		dat.seekg(indeks.adresa);
		dat.read((char *) &slog, sizeof(slog));
		cout << "Sifra predmeta: " << slog.sifra_p << endl;
		cout << "Naziv predmeta: " << slog.naziv_p << endl;
		cout << "Smjer: " << slog.smjer << endl;
		cout << "Broj prijava: " << slog.broj_p << endl;
		cout << endl; 
	};
	dat.close();
	ind.close();
	cout << "Ukupan broj zapisa: " << ukupno << endl;
};

int main(){
	int izbor;
	do{
		cout << "----Program----" << endl;
		cout << "1. Kreiranje dat." << endl;
		cout << "2. Unos podatakau dat." << endl;
		cout << "3. Pretrazivanje." << endl;
		cout << "4. Ispis podataka." << endl;
		cout << "9. Izlaz iz programa. " << endl;
		cout << "Vas odabir je: "; cin >> izbor; 
		cout << endl; 
		switch(izbor){
			case 1: kreir_dat(); break;
			case 2: unos(); break;
			case 3: pretraga(); break;
			case 4: ispis(); break;
			case 9: cout << "Kraj programa." << endl; break;
			default: 
				cout << "Krivi odabir..." << endl;
		};
	}while(izbor !=9);
	system("PAUSE");
}
  
  
