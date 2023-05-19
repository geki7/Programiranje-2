// MD5:4ZhDMuKN2PrYAxORVH+mSg==// Verifikator 5.05// Program:Klase// Opis zadatka:Klase-test// Autor:Ivan Gadzic// Pocetno vrijeme:12/10/2021 12:01:05 PM// Završno vrijeme:12/10/2021 1:57:52 PM// Identifikatori:main,izbor,ctrokut,broj_unesenih,sifra_t,a,b,c,s,povrsina_trokuta,*p,*pok,*trokut,else,unos_t,trokut,cout,ispis_t,i,broj_unesenih>i,n,ispis// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include <cmath>,#include "cvrijeme.cc",// Uspješnih/neuspješnih prevodenja:50/29#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,11,13,16,20,26,27,36,40,41,51,66,69,79,80,88,95,99}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=17;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 17):" << endl; 
  for (f=1;f<=17;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include <cmath>
#include "cvrijeme.cc"
using namespace std;

class ctrokut{
  public: static int broj_unesenih;
      int sifra_t;
        float a, b, c;
    private: float s;
  public: float povrsina_trokuta(){TEST(1);
      s = (a+b+c)/2;
      if(sqrt(s*(s-a)*(s-b)*(s-c)) > 0){TEST(2);
        return sqrt(s*(s-a)*(s-b)*(s-c));
      }
      else{TEST(3);
        return -1;
      }
    };
    void unos_t(){TEST(4);
      cout << "Sifra trokuta: "; cin >> sifra_t;
      cout << "Stranica A: "; cin >> a;
      cout << "Stranica B: "; cin >> b;
      cout << "Stranica C: "; cin >> c;
    };
    void ispis_t(){TEST(5);
      if(povrsina_trokuta() != -1){TEST(6);
        cout << endl;
        cout << "Sifra trokuta: " << sifra_t << endl;
        cout << "Stranica A: " << a << endl;
        cout << "Stranica B: " << b << endl;
        cout << "Stranica C: " << c << endl;
        cout << "Povrsina trokuta je: " << povrsina_trokuta(); 
        cout << endl;
      }
      else{TEST(7);
        cout << "Tri stranice ne cine trokut..." << endl;
      }
    };
    void ispis(int i){TEST(8);
      if(povrsina_trokuta() != -1){TEST(9);
        cout << endl;
        cout << "Ovo je trokut..." << endl;
        cout << "Sifra trokuta: " << sifra_t << endl;
        cout << "Stranica A: " << a << endl;
        cout << "Stranica B: " << b << endl;
        cout << "Stranica C: " << c << endl;
        cout << "Povrsina trokuta je: " << povrsina_trokuta(); 
        cout << endl;
      }
      else{TEST(10);
        cout << endl;
        cout << "Ovo nije trokut..." << endl;
        cout << "Sifra trokuta: " << sifra_t << endl;
        cout << "Stranica A: " << a << endl;
        cout << "Stranica B: " << b << endl;
        cout << "Stranica C: " << c << endl;
      }
    };
};

int ctrokut::broj_unesenih;
ctrokut *trokut;
ctrokut *pok;

int main(){TEST(11);
  int izbor, n;
  ctrokut::broj_unesenih = 0;
  do{TEST(12);
    cout << endl;
    cout << "----Program----" << endl;
    cout << "1. Upis" << endl;
    cout << "2. Ispis" << endl;
    cout << "3. Upis polja" << endl;
    cout << "4. Ispis polja" << endl;
    cout << "9. Kraj programa" << endl;
    cout << "Vas odabir je: "; cin >> izbor;
    cout << endl;
    TEST(13); switch(izbor){
      case 1: if(!pok){TEST(14);
          cout << "Alokacije neuspjesna" << endl;
          pok = new ctrokut;
          cout << endl;
        }
        pok -> unos_t();
        break;
      case 2: pok -> ispis_t(); break;
      case 3: if(!trokut){TEST(15);
          cout << "Alokacija neuspjesna" << endl;
          cout << "Koliko mjesta zelite kreirati: "; cin >> n;
          trokut = new ctrokut[n];
          trokut[ctrokut::broj_unesenih].unos_t();
          ctrokut::broj_unesenih++;
         }
         else{TEST(16);
         trokut[ctrokut::broj_unesenih].unos_t();
         ctrokut::broj_unesenih++;
         } break;
      case 4: for(int i = 0; ctrokut::broj_unesenih>i; i++){TEST(17);
          trokut[i].ispis(i);
        };break;
      case 9: cout << "Kraj programa." << endl; break;
      default: 
        cout << "Krivi odabir... " << endl;
    };
  }while(izbor !=9);
  system("PAUSE");
}
  
  
  
  
    // Postoci testiranja:  100% 100% 100%// H1:544000000000000000000000000000025520000203330302000140000110021000004412541113234001000000000402454114000301101100405// H2:887000000000000000000000000000067664000634560736000650001603054000041146865455445000000000000107661656000126466650606// H3:000000000000000000000000000000000010000000000000000000000010000000000000000000000000000000000000000000000001000100100// H4:001000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000
