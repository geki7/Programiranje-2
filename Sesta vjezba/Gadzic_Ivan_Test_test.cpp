// MD5:+mJ/MV9NeHn1osk491ucAA==// Verifikator 5.05// Program:Test// Opis zadatka:Test// Autor:Ivan Gadzic// Pocetno vrijeme:11/29/2021 11:16:05 AM// Završno vrijeme:11/29/2021 1:10:18 PM// Identifikatori:main,izbor,dat,ind,tstudent,rb_zapisa,sifra_p,naziv_p[30],smjer[20],broj_P,tindeks,smjer,kreir_dat,kreirano,naziv_dat[30],naziv_ind[30],zelja,naziv_dat[],naziv_ind[],naziv_dat,naziv_ind,naziv_dat[20],naziv_ind[20],slog,dat[],ind[],unos,broj_p,brojac,*,pretraga,sifra,pronadjen,ukupno,ispis// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cstdlib>[B],#include <fstream>[B],#include <cstring>[B],#include <string.h>,#include "biblioteka_tel_imenik.cc" ,#include <time.h>[B],#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc" ,// Uspješnih/neuspješnih prevodenja:88/57#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,22,25,33,44,62,68,70,75,87,92,95,97,114,116,125}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=15;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 15):" << endl; 
  for (f=1;f<=15;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
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

void kreir_dat(){TEST(1);
  char zelja;
  cout << "Zelite li koristit vec odabrano ime (d/n): "; cin >> zelja;
  if(zelja == 'd' || zelja == 'D'){TEST(2);
    strcpy(naziv_dat, "predmeti.dat");
    strcpy(naziv_ind, "predmeti.ind");
    dat.open(naziv_dat, ios::out);
    dat.close();
    ind.open(naziv_ind, ios::out);
    ind.close();
  }
  else{TEST(3);
    cout << "Unesite naziv maticne dat: "; cin >> naziv_dat;
    dat.open(naziv_dat, ios::out);
    dat.close();
    cout << "Unesite naziv indeksne dat: "; cin >> naziv_ind;
    ind.open(naziv_ind, ios::out);
    ind.close();
  }
  cout << endl;
};

void unos(){TEST(4);
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

void pretraga(){TEST(5);
  dat.open(naziv_dat, ios::in | ios::binary);
  ind.open(naziv_ind, ios::in | ios::binary);
  int sifra;
  cout << "Unesite sifru predemta: "; cin >> sifra;
  bool pronadjen = false;
  while(1){TEST(6);
    ind.read((char *) &indeks, sizeof(indeks));
    if(ind.eof()){TEST(7);
      break;
    }
    dat.seekg(indeks.adresa);
    dat.read((char *) &slog, sizeof(slog));
    if(sifra == slog.sifra_p){TEST(8);
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
  if(!pronadjen){TEST(9);
    cout << "Predmet ne postoji." << endl;
  }
}

void ispis(){TEST(10);
  dat.open(naziv_dat, ios::in | ios::binary);
  ind.open(naziv_ind, ios::in | ios::binary);
  while(1){TEST(11);
    ind.read((char *) &indeks, sizeof(indeks));
    if(ind.eof()){TEST(12);
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

int main(){TEST(13);
  int izbor;
  do{TEST(14);
    cout << "----Program----" << endl;
    cout << "1. Kreiranje dat." << endl;
    cout << "2. Unos podatakau dat." << endl;
    cout << "3. Pretrazivanje." << endl;
    cout << "4. Ispis podataka." << endl;
    cout << "9. Izlaz iz programa. " << endl;
    cout << "Vas odabir je: "; cin >> izbor; 
    cout << endl; 
    TEST(15); switch(izbor){
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
  
    // Postoci testiranja:  100% 100% 100%// H1:64441245454341245300042200440340010123254040442002020022346300000000003625203130005526150530443354000444530543410010000000000// H2:88877753676540244000015400640560450412455060662000050057460300000000005748606630000066071141777876440788870786660030000000000// H3:00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000// H4:00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
