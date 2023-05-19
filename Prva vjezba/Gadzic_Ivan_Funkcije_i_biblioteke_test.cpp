// MD5:EE11I/5LxO5BxxyOva4MUQ==// Verifikator 5.05// Program:Funkcije i biblioteke// Opis zadatka:Funkcije// Autor:Ivan Gadzic// Pocetno vrijeme:10/15/2021 12:28:57 PM// Završno vrijeme:10/15/2021 1:59:06 PM// Identifikatori:main,izbor,povrsina,a,b,x,y,trokut,c,k,s,polje,*rijec,i,struktura,tautor,sifra,prezime_ime[35],prosjek_coj,*autor_1,*autor_2,autor_2,autor_1,prosjek_ocj,cout// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",#include <cmath>,#include <iomanip>,#include <cstring>,// Uspješnih/neuspješnih prevodenja:79/20#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,8,11,15,36,39,42,45,50,52,57,65,67,75}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=13;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 13):" << endl; 
  for (f=1;f<=13;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "biblioteka_vrijeme.cc"

using namespace std;
void polje(){TEST(1);
  string *rijec;
  rijec = new string[4] {"Bicikli", "Monitor", "Radni stol", "Papir"};
  for(unsigned int i=0; i<4; i++){TEST(2);
    cout << rijec[i] << endl;
  }
}
void struktura(){TEST(3);
  struct tautor{
    int sifra;
    char prezime_ime[35];
    float prosjek_ocj;
  };
  tautor *autor_1, *autor_2;
  autor_1 = new tautor;
  autor_2 = new tautor; 
  
  autor_1->sifra = 529;
  strcpy(autor_1->prezime_ime, "Maric Marko");
  autor_1->prosjek_ocj = 4.35;
  
  memcpy(autor_2, autor_1, sizeof(tautor));
  
  cout << "Sifra: " << autor_2->sifra << endl;
  cout << "Prezime i ime: " << autor_2->prezime_ime << endl;
  cout << "Prosjecna ocjena: " << autor_2->prosjek_ocj << endl; 
}

void povrsina(){TEST(4);
  int a, b;
  cout << "Unesite a i b: "; cin >> a >> b;
  if(a<0){TEST(5);
    a = abs(a);
  }
  if(b<0){TEST(6);
    b = abs(b);
  }
  if(a>0 || b>0){TEST(7);
    cout << "Povrsina je: " << a*b << endl;
  }
}

void trokut(){TEST(8);
  float a, b, c, k, s;
  do{TEST(9);
    vrijeme_pocetak();
    cout << "Unesite stranicu a, b i c: "; cin >> a >> b >> c;
    s = (a+b+c)/2;
    k = sqrt((s*(s-a)*(s-b)*(s-c)));
    if(k>0){TEST(10);
      cout << "Povrsina trokuta je: " << fixed <<setprecision(2)<< k << endl;
    }
  }while(k<0);
  vrijeme_kraj();
  cout << "Vrijeme proteklo je: " << vrijeme_proteklo()/10 << endl;
}

int main(){TEST(11);
  int izbor;
  do{TEST(12);
    cout << "1. Polje" << endl;
    cout << "2. Funkcija" << endl;
    cout << "3. Struktura" << endl;
    cout << "4. Mjerenje vremena" << endl; 
    cout << "9. Izlaz iz programa" << endl;
    cout << "Vas odabir: "; 
    cin >> izbor;
    TEST(13); switch(izbor){
      case 1: polje(); break;
      case 2: povrsina(); break;
      case 3: struktura(); break;
      case 4: trokut(); break;
      default:
        cout << "Pogresan unos..." << endl;  
    }
  }while(izbor !=9);
  system("PAUSE");
}
  
    // Postoci testiranja:  100% 100% 100%// H1:5543221234604365552000501023640300010000001014001425100040050335154453000000020114010501101// H2:7885655656505567775000100035250400000000000066000347310050415767566674002000060136030641600// H3:0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000// H4:0000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000
