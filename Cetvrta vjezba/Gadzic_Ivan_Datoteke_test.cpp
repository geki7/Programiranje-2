// MD5:lvLukUN0usRhR6FiO5cfYQ==// Verifikator 5.05// Program:Datoteke// Opis zadatka:Datoteke// Autor:Ivan Gadzic// Pocetno vrijeme:11/12/2021 11:57:28 AM// Završno vrijeme:11/12/2021 1:51:25 PM// Identifikatori:main,izbor,tstudent,mat_br,prez_ime[30],god_up,ispiti,student,dat,unos_pod,jos,*,ispis_pod,pret,mtb,brojac,vrijeme,naziv_dat[20],jebemtiboga,*znakovni_niz,unosdat,*niz,kre_dat,naziv_dat[30],prim_kljuc,mt// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <ctime>[B],#include <iostream>[B],#include <fstream>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:73/19#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,18,21,26,33,36,51,53,55,62,70,73,75,78,86,93,95,97,109,111,119}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=20;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 20):" << endl; 
  for (f=1;f<=20;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
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

void kre_dat(){TEST(1);
  cout << "Naziv datoteke: "; cin >> naziv_dat;
  dat.open(naziv_dat, ios::in | ios::binary);
  if(!dat){TEST(2);
    dat.open(naziv_dat, ios::out | ios::binary);
    dat.close();
    dat.clear();
  }
  else{TEST(3);
    cout << "Datoteka vec postoji." << endl;
    dat.close();
    dat.clear();
  }
};

void unos_pod(){TEST(4);
  char jos;
  dat.open(naziv_dat, ios::out | ios::binary);
  do{TEST(5);
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

void prim_kljuc(int mt){TEST(6);
  dat.open(naziv_dat, ios::in | ios::binary);
  while(1){TEST(7);
    dat.read((char *) &student, sizeof(student));
    if(student.mat_br != mt){TEST(8);
      cout << "Maticni broj: "; cin >> student.mat_br;
      cout << "Prezime i ime: "; unos(student.prez_ime);
      cout << "Godina upisa: "; cin >> student.god_up;
      cout << "Polozeni ispiti: "; cin >> student.ispiti;
      dat.write((char *) &student, sizeof(student));
    }
    else{TEST(9);
      cout << "Kljuc vec postoji. " << endl;
    }
  };
  dat.close();
  dat.clear();
};

void pret(int mtb){TEST(10);
  int brojac = 0;
  dat.open(naziv_dat, ios::in | ios::binary);
  while(1){TEST(11);
    dat.read((char *) &student, sizeof(student));
    if(dat.eof()){TEST(12);
      break;
    };
    if(student.mat_br == mtb){TEST(13);
      cout << "Maticni broj: " << student.mat_br << endl;
      cout << "Prezime i ime: " << student.prez_ime << endl;
      cout << "Godina upisa: " << student.god_up << endl;
      cout << "Polozeni ispiti: " << student.ispiti << endl;
      brojac++;
    }
  };
  if(brojac == 0){TEST(14);
    cout << "Student s maticnim brojem nije pronaden." << endl;
  }
  dat.close();
  dat.clear();
};

void ispis_pod(){TEST(15);
  dat.open(naziv_dat, ios::in | ios::binary);
  while(1){TEST(16);
    dat.read((char *) &student, sizeof(student));
    if(dat.eof()){TEST(17);
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

int main(){TEST(18);
  int izbor, mtb, mt;
  do{TEST(19);
    cout << "----Program----" << endl;
    cout << "1. Unos podataka u datoteku." << endl;
    cout << "2. Provjera primarnog kljuca." << endl;
    cout << "3. Ispis sadrzaja cijele dat." << endl;
    cout << "4. Pretrazivanje." << endl;
    cout << "5. Kreiranje dat." << endl;
    cout << "Vas odabir je: "; cin >> izbor;
    TEST(20); switch(izbor){
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
  
    // Postoci testiranja:  100% 100% 100% 60%// H1:456300000000000000000000000000001343452354423444332100040410413535551112000003453401302013104363100000000// H2:788500000000000000000000000000006576886367875767646200470753526778653200000006747630600025007675100000000// H3:000000000000000000000000000000000000000000000010000100000000000000000000000000101000001000000010000000000// H4:000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
