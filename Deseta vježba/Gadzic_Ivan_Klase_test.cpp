// MD5:/sf25A9qcIF99AfSBWrFMw==// Verifikator 5.05// Program:Klase// Opis zadatka:Klase // Autor:Ivan Gadzic// Pocetno vrijeme:1/14/2022 11:32:21 AM// Završno vrijeme:1/14/2022 1:29:08 PM// Identifikatori:main,izbor,cvrste_zapis,sifra_v,vsrste_r[20],ambalaza[10],unos,vrsta_r[20],cvrsta,*sljedeci,zapis,*lista_vrsta,sljedeci,*novi,*zadnji,zadnji,do,croba_zapis,red_b,sifra,naziv[20],croba,*zapis,*lista_robe,lista_robe,void,ispis,*tekuci,provjera,sifra_a,pretrati,pretrazi,sifra_robe// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <iostream>,#include <cstring>,// Uspješnih/neuspješnih prevodenja:58/29#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,10,15,26,30,33,40,43,49,51,52,68,73,84,89,92,99,102,108,110,111,122,126,136}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=23;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 23):" << endl; 
  for (f=1;f<=23;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include <cstring>
using namespace std;

class cvrste_zapis{
  public:
  int sifra_v;
  char vrsta_r[20];
  char ambalaza[10];
  void unos(){TEST(1);
    cout << "Sifra vrste robe: "; cin >> sifra_v;
    cout << "Vrsta robe: "; cin >> vrsta_r;
    cout << "Vrsta ambalaze: "; cin >> ambalaza; 
  };
  void ispis(){TEST(2);
    cout << "Sifra vrste robe: " << sifra_v << endl;
    cout << "Vrste robe: " << vrsta_r << endl;
    cout << "Vrsta ambalaze: " << ambalaza << endl;
  };
};

class cvrsta{
  cvrsta *sljedeci;
  public:
  cvrste_zapis zapis;
  cvrsta(){TEST(3);
    sljedeci = NULL;
    
  }
  void unos(){TEST(4);
    cvrsta *novi, *zadnji;
    zadnji = this;
    while(zadnji -> sljedeci){TEST(5);
      zadnji = zadnji -> sljedeci;
    };
    novi = new cvrsta;
    zadnji -> sljedeci = novi;
    novi -> zapis.unos();
  };
  void ispis(){TEST(6);
    cvrsta *tekuci = this -> sljedeci;
    cout << "--------------" << endl;
    while(tekuci){TEST(7);
      tekuci -> zapis.ispis();
      cout << "--------------" << endl;
      tekuci = tekuci -> sljedeci;
    };
  };
  void pretrazi(int sifra_a){TEST(8);
    cvrsta *tekuci = this -> sljedeci; 
    while(tekuci){TEST(9);
      if(sifra_a == tekuci -> zapis.sifra_v){TEST(10);
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
  void unos(){TEST(11);
    cout << "Redni broj robe: "; cin >> red_b;
    cout << "Sifra robe: "; cin >> sifra;
    cout << "Naziv robe: "; cin >> naziv;
  };
  void ispis(){TEST(12);
    cout << "Redni broj robe: " << red_b << endl;
    cout << "Sifra robe: " << sifra << endl;
    cout << "Naziv robe: " << naziv << endl;
  };
};

class croba{
  croba *sljedeci;
  public:
  croba_zapis *zapis;
  croba(){TEST(13);
    sljedeci = NULL;
    cout << "Konstruktor" << endl;
    zapis = new croba_zapis;
  };
  void unos(){TEST(14);
    croba *novi, *zadnji; 
    zadnji = this;
    while(zadnji -> sljedeci){TEST(15);
      zadnji = zadnji -> sljedeci;
    };
    novi = new croba;
    zadnji -> sljedeci = novi;
    novi -> zapis -> unos(); 
  };
  void ispis(){TEST(16);
    croba *tekuci = this -> sljedeci;
    cout << "--------------" << endl;
    while(tekuci){TEST(17);
      tekuci -> zapis -> ispis();
      cout << "--------------" << endl;
      tekuci = tekuci -> sljedeci;
    };
  };
  void pretrazi(int sifra_a){TEST(18);
    croba *tekuci = this -> sljedeci;
    while(tekuci){TEST(19);
      if(sifra_a == tekuci -> zapis -> sifra){TEST(20);
        tekuci -> zapis -> ispis();
        cout << "--------------" << endl;
      }
      tekuci = tekuci -> sljedeci;
    };
  }  
};

croba *lista_robe;

int main(){TEST(21);
  int izbor, sifra_a;
  lista_vrsta = new cvrsta;
  lista_robe = new croba;
  do{TEST(22);
    cout << endl;
    cout << "----Program----" << endl;
    cout << "1.Unos vrsta robe na kraj liste " << endl;
    cout << "2.Unos roba na kraj liste " << endl;
    cout << "3.Ispis vrsta robe i robe " << endl;
    cout << "4.Popis roba zadane vrste " << endl; 
    cout << "9. Kraj programa. " << endl;
    cout << "Vas odabir je: "; cin >> izbor;
    cout << endl;
    TEST(23); switch(izbor){
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
  
    // Postoci testiranja:  100% 100% 100% 100% 100%// H1:543500000000000000000000000000000000000000000000000000001554555024133332244152113323054115453241400044444043144115301000// H2:777600000000000000000000000000000000000000000000000000001767777066567756776586145646087606444754500077776066658567600000// H3:000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111100010000000000011000000000000// H4:000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000
