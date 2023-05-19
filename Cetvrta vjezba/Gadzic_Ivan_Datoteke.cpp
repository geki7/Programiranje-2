// MD5:BsOrdlZX+CJT0qZzflzY2Q==
#include <fstream>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct tstudent{
	int mat_br;
	char prez_ime[30];
	int god_up;
	int ispiti;
	double vrijeme;
};

tstudent student;
fstream dat;
char naziv_dat[30];

void kre_dat(){
	cout << "Naziv datoteke: "; cin >> naziv_dat;
	dat.open(naziv_dat, ios::in | ios::binary);
	if(!dat){
		dat.open(naziv_dat, ios::out | ios::binary);
		dat.close();
		dat.clear();
	}
	else{
		cout << "Datoteka vec postoji." << endl;
		dat.close();
		dat.clear();
	}
};

void unos_pod(){
	char jos;
	dat.open(naziv_dat, ios::out | ios::binary);
	do{
		vrijeme_pocetak();
		cout << "Maticni broj: "; cin >> student.mat_br;
		cout << "Prezime i ime: "; unos(student.prez_ime);
		cout << "Godina upisa: "; cin >> student.god_up;
		cout << "Polozeni ispiti: "; cin >> student.ispiti;
		vrijeme_kraj();
		student.vrijeme = vrijeme_proteklo()/1000;
		dat.write((char *) &student, sizeof(student));
		cout << "Zelite li jos upisati (d/n): "; cin >> jos;
	}while(jos == 'd' || jos == 'D');
	dat.close();
	dat.clear();
};

void prim_kljuc(int mt){
	dat.open(naziv_dat, ios::in | ios::binary);
	while(1){
		dat.read((char *) &student, sizeof(student));
		if(student.mat_br != mt){
			cout << "Maticni broj: "; cin >> student.mat_br;
			cout << "Prezime i ime: "; unos(student.prez_ime);
			cout << "Godina upisa: "; cin >> student.god_up;
			cout << "Polozeni ispiti: "; cin >> student.ispiti;
			dat.write((char *) &student, sizeof(student));
		}
		else{
			cout << "Kljuc vec postoji. " << endl;
		}
	};
	dat.close();
	dat.clear();
};

void pret(int mtb){
	int brojac = 0;
	dat.open(naziv_dat, ios::in | ios::binary);
	while(1){
		dat.read((char *) &student, sizeof(student));
		if(dat.eof()){
			break;
		};
		if(student.mat_br == mtb){
			cout << "Maticni broj: " << student.mat_br << endl;
			cout << "Prezime i ime: " << student.prez_ime << endl;
			cout << "Godina upisa: " << student.god_up << endl;
			cout << "Polozeni ispiti: " << student.ispiti << endl;
			brojac++;
		}
	};
	if(brojac == 0){
		cout << "Student s maticnim brojem nije pronaden." << endl;
	}
	dat.close();
	dat.clear();
};

void ispis_pod(){
	dat.open(naziv_dat, ios::in | ios::binary);
	while(1){
		dat.read((char *) &student, sizeof(student));
		if(dat.eof()){
			break;
		}
		cout << "Maticni broj: " << student.mat_br << endl;
		cout << "Prezime i ime: " << student.prez_ime << endl;
		cout << "Godina upisa: " << student.god_up << endl;
		cout << "Polozeni ispiti: " << student.ispiti << endl;
	};
	dat.close();
	dat.clear();
};

int main(){
	int izbor, mtb, mt;
	do{
		cout << "----Program----" << endl;
		cout << "1. Unos podataka u datoteku." << endl;
		cout << "2. Provjera primarnog kljuca." << endl;
		cout << "3. Ispis sadrzaja cijele dat." << endl;
		cout << "4. Pretrazivanje." << endl;
		cout << "5. Kreiranje dat." << endl;
		cout << "Vas odabir je: "; cin >> izbor;
		switch(izbor){
			case 1: unos_pod(); break;
			case 2: cout << "Unesite maticni broj: "; cin >> mt;
					prim_kljuc(mt); break;
			case 3: ispis_pod(); break;
			case 4: cout <<"Unesite maticni broj: "; cin >> mtb;
					pret(mtb); break;
			case 5: kre_dat();
			case 9: break;
			default: 
				cout << "Pogresan unos. " << endl;
		};
	}while(izbor !=9);
	system("PAUSE");
}
  
  