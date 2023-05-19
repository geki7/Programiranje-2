// MD5:A+z02crAHhSxn+JG+257Qg==// Verifikator 5.05// Program:Datoteke// Opis zadatka:Datoteke_relativne// Autor:Ivan Gadzic// Pocetno vrijeme:11/19/2021 12:06:27 PM// Završno vrijeme:11/19/2021 2:04:08 PM// Identifikatori:main,izbor,tstudent,rb_zapisa,mat_br,prez_ime[30],ispiti,god_up,dat,prost_broj,prost,x,i,j,kreir_dat,vd,slog,*,int,dat.close,unos,slog1,rbz,do,while,1,dat.write,pret,nadjen,brojac,if,mat_br_st,ispis,vrijeme,slog.rb_zapisa// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cstdlib>[B],#include <fstream>[B],#include <cstring>[B],#include <cmath>,#include "biblioteka_tel_imenik.cc",#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:97/14#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,20,22,24,25,30,37,47,55,65,76,83,85,97,102,106,108,111,121,131,133,141,143}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=22;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 22):" << endl; 
  for (f=1;f<=22;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
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

int prost(int x){TEST(1);
  int i, j, prost;
  for(i=x; i>1; i--){TEST(2);
    prost = 1;
    for(j=2; j<=sqrt(i); j++){TEST(3);
      if(i%j == 0){TEST(4);
        prost = 0;
        break;
      }
    };
    if(prost){TEST(5);
      return i;
    }
  };
  return 0;
};

void kreir_dat(int vd){TEST(6);
  tstudent slog;
  int i;
  slog.mat_br = 0;
  slog.prez_ime[0] = '\0';
  slog.ispiti = 0;
  slog.god_up = 0;
  prost_broj = prost(vd); 
  cout << "Prost broj : " << prost_broj << endl;
  dat.open("student.dat.", ios::out | ios::binary);
  for(i = 0; i<vd; i++){TEST(7);
    slog.rb_zapisa = i;
    dat.write((char *) &slog, sizeof(tstudent));
  };
  dat.close();
  dat.clear();
};

void unos(){TEST(8);
  tstudent slog, slog1;
  int rbz;
  cout << "Maticni broj studenta: "; cin >> slog.mat_br;
  cout << "Prezime i ime: "; unos(slog.prez_ime);
  cout << "Polozeni ispiti: "; cin >> slog.ispiti;
  cout << "Godina upisa: "; cin >> slog.god_up;
  rbz = slog.mat_br % prost_broj;
  dat.open("student.dat", ios::in | ios::out | ios::binary);
  dat.seekg(rbz*sizeof(tstudent));
  do{TEST(9);
    dat.read((char *) &slog1, sizeof(tstudent));
  }while(slog1.mat_br > 0);
  rbz = (dat.tellg()/sizeof(tstudent)) -1;
  dat.seekp(rbz*sizeof(tstudent));
  slog.rb_zapisa = slog1.rb_zapisa;
  dat.write((char *) &slog, sizeof(tstudent));
  dat.close();
  dat.clear();
};

void pret(int mat_br){TEST(10);
  tstudent slog;
  bool nadjen = false;
  int rbz;
  dat.open("student.dat", ios::in | ios::binary);
  rbz = mat_br % prost_broj;
  dat.seekg(rbz*sizeof(tstudent));
  do{TEST(11);
    dat.read((char *) &slog, sizeof(tstudent));
    if(slog.mat_br == mat_br){TEST(12);
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
  if(!nadjen){TEST(13);
    cout << "Zapis nije pronaden..." << endl;
  }
};

void ispis(){TEST(14);
  tstudent slog;
  int brojac = 0, broj_praznih = 0;
  dat.open("student.dat", ios::in | ios::binary);
  while(1){TEST(15);
    dat.read((char *) &slog, sizeof(tstudent));
    if(dat.eof()){TEST(16);
      break;
    }
    if(slog.mat_br > 0){TEST(17);
      brojac++;
      cout << "Zapis broj : " << slog.rb_zapisa << endl;
      cout << "Maticni broj studenta: " << slog.mat_br << endl;
      cout << "Prezime i ime: " << slog.prez_ime << endl;
      cout << "Polozeni ispiti: " << slog.ispiti << endl;
      cout << "Godina upisa: " << slog.god_up << endl;
      cout << (dat.tellg()/sizeof(tstudent)) -1 << endl;

    }
    else{TEST(18);
      broj_praznih++;
    }
  };
  dat.close();
  dat.clear();
  cout << "Ukupan broj nepraznih zapisa je: " << brojac << endl;
  cout << "Ukupan broj praznih zapisa je: " << broj_praznih << endl;
};

int main(){TEST(19);
  int izbor, vd, mat_br_st, vrijeme;
  do{TEST(20);
    cout << "----Program----" << endl;
    cout << "1. Kreiranje dat. praznih zapisa i rac. prs br. " << endl;
    cout << "2. Unos pod. u rel. dat. " << endl; 
    cout << "3. Pretrazivanje dat." << endl;
    cout << "4. Statistika" << endl; 
    cout << "9. Izlaz iz programa." << endl;
    cout << "Vas izbor je : "; cin >> izbor; 
    TEST(21); switch(izbor){
      case 1: vrijeme_pocetak();
          do{TEST(22);
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
  
  
    // Postoci testiranja:  100% 100% 100% 100%// H1:46340000033454223544304445254324014454530610000004002452115303000000501000030340000010000000140032140440021003410200450// H2:78670000067666775765636658687767067777470530000006006765457503100000436300050470000040000000670310303410034003040500140// H3:00000000000000000000000000000000000011000000000000000001000000000000000000000000000010000000000000000000000000100000000// H4:00000000000000000000000000000000000000000000000000000000000001000000010000000000000000000000000000000000000000000000000
