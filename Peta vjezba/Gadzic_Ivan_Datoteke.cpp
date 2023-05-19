// MD5:/MKS1QB646EPLFY3pzYx1g==// Verifikator 5.05// Program:Datoteke// Opis zadatka:Datoteke_relativne// Autor:Ivan Gadzic// Pocetno vrijeme:11/19/2021 12:06:27 PM// Završno vrijeme:11/19/2021 2:04:08 PM// Identifikatori:main,izbor,tstudent,rb_zapisa,mat_br,prez_ime[30],ispiti,god_up,dat,prost_broj,prost,x,i,j,kreir_dat,vd,slog,*,int,dat.close,unos,slog1,rbz,do,while,1,dat.write,pret,nadjen,brojac,if,mat_br_st,ispis,vrijeme,slog.rb_zapisa// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cstdlib>[B],#include <fstream>[B],#include <cstring>[B],#include <cmath>,#include "biblioteka_tel_imenik.cc",#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:97/14#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct tstudent{
	int rb_zapisa;
	int mat_br;
	char prez_ime[30];
	int ispiti;
	int god_up;
};

int prost_broj;
fstream dat;

int prost(int x){
	int i, j, prost;
	for(i=x; i>1; i--){
		prost = 1;
		for(j=2; j<=sqrt(i); j++){
			if(i%j == 0){
				prost = 0;
				break;
			}
		};
		if(prost){
			return i;
		}
	};
	return 0;
};

void kreir_dat(int vd){
	tstudent slog;
	int i;
	slog.mat_br = 0;
	slog.prez_ime[0] = '\0';
	slog.ispiti = 0;
	slog.god_up = 0;
	prost_broj = prost(vd); 
	cout << "Prost broj : " << prost_broj << endl;
	dat.open("student.dat.", ios::out | ios::binary);
	for(i = 0; i<vd; i++){
		slog.rb_zapisa = i;
		dat.write((char *) &slog, sizeof(tstudent));
	};
	dat.close();
	dat.clear();
};

void unos(){
	tstudent slog, slog1;
	int rbz;
	cout << "Maticni broj studenta: "; cin >> slog.mat_br;
	cout << "Prezime i ime: "; unos(slog.prez_ime);
	cout << "Polozeni ispiti: "; cin >> slog.ispiti;
	cout << "Godina upisa: "; cin >> slog.god_up;
	rbz = slog.mat_br % prost_broj;
	dat.open("student.dat", ios::in | ios::out | ios::binary);
	dat.seekg(rbz*sizeof(tstudent));
	do{
		dat.read((char *) &slog1, sizeof(tstudent));
	}while(slog1.mat_br > 0);
	rbz = (dat.tellg()/sizeof(tstudent)) -1;
	dat.seekp(rbz*sizeof(tstudent));
	slog.rb_zapisa = slog1.rb_zapisa;
	dat.write((char *) &slog, sizeof(tstudent));
	dat.close();
	dat.clear();
};

void pret(int mat_br){
	tstudent slog;
	bool nadjen = false;
	int rbz;
	dat.open("student.dat", ios::in | ios::binary);
	rbz = mat_br % prost_broj;
	dat.seekg(rbz*sizeof(tstudent));
	do{
		dat.read((char *) &slog, sizeof(tstudent));
		if(slog.mat_br == mat_br){
			nadjen = true;
			cout << "Zapis broj : " << slog.rb_zapisa << endl;
			cout << "Maticni broj studenta: " << slog.mat_br << endl;
			cout << "Prezime i ime: " << slog.prez_ime << endl;
			cout << "Polozeni ispiti: " << slog.ispiti << endl;
			cout << "Godina upisa: " << slog.god_up << endl;
			break;
		}
	}while(slog.mat_br > 0);
	dat.close();
	dat.clear();
	if(!nadjen){
		cout << "Zapis nije pronaden..." << endl;
	}
};

void ispis(){
	tstudent slog;
	int brojac = 0, broj_praznih = 0;
	dat.open("student.dat", ios::in | ios::binary);
	while(1){
		dat.read((char *) &slog, sizeof(tstudent));
		if(dat.eof()){
			break;
		}
		if(slog.mat_br > 0){
			brojac++;
			cout << "Zapis broj : " << slog.rb_zapisa << endl;
			cout << "Maticni broj studenta: " << slog.mat_br << endl;
			cout << "Prezime i ime: " << slog.prez_ime << endl;
			cout << "Polozeni ispiti: " << slog.ispiti << endl;
			cout << "Godina upisa: " << slog.god_up << endl;
			cout << (dat.tellg()/sizeof(tstudent)) -1 << endl;

		}
		else{
			broj_praznih++;
		}
	};
	dat.close();
	dat.clear();
	cout << "Ukupan broj nepraznih zapisa je: " << brojac << endl;
	cout << "Ukupan broj praznih zapisa je: " << broj_praznih << endl;
};

int main(){
	int izbor, vd, mat_br_st, vrijeme;
	do{
		cout << "----Program----" << endl;
		cout << "1. Kreiranje dat. praznih zapisa i rac. prs br. " << endl;
		cout << "2. Unos pod. u rel. dat. " << endl; 
		cout << "3. Pretrazivanje dat." << endl;
		cout << "4. Statistika" << endl; 
		cout << "9. Izlaz iz programa." << endl;
		cout << "Vas izbor je : "; cin >> izbor; 
		switch(izbor){
			case 1: vrijeme_pocetak();
					do{
						cout << "Unesit broj: "; cin >> vd;
					}while(vd<100 || vd>1000 || vd==prost(vd));
					kreir_dat(vd);
					break; 
			case 2: unos(); break;
			case 3: cout << "Unesite maticni broj: "; cin >> mat_br_st;
					pret(mat_br_st);
					break;
			case 4: ispis();
					vrijeme_kraj();
					vrijeme = vrijeme_proteklo()/1000;
					cout << "Vrijeme proslo od pocetka upisa je: " << vrijeme << " sekundi." << endl;
					break;
			case 9: cout << "Kraj programa." << endl; break; 
			default: 
				cout << "Krivi izbor..." << endl; 
		};
	}while(izbor !=9);
	system("PAUSE");
}
  
  
  
