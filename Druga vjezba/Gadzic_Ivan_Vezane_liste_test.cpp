// MD5:lybkb+nqv9tTzx3E5PDmeA==// Verifikator 5.05// Program:Vezane liste// Opis zadatka:Vezane liste// Autor:Ivan Gadzic// Pocetno vrijeme:10/22/2021 12:12:25 PM// Završno vrijeme:10/22/2021 1:17:13 PM// Identifikatori:main,izbor,tinv,sifra_inv,naziv_inv[35],komada,*sljedeci,*lista,lista,dod_ele,*novi,*zadnji,zadnji,ispis_ele,*tekuci,pretrazivanje,brisanje,*brisi,tekuci,zbroj,zbroj// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:27/18#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,12,16,28,30,39,41,42,53,55,56,68,72,79}; 
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
#include "biblioteka_vrijeme.cc"
using namespace std;
int zbroj = 0;
struct tinv{
  int sifra_inv;
  char naziv_inv[35];
  int komada; 
  tinv *sljedeci;
};

void dod_ele(tinv *lista){TEST(1);
  tinv *novi, *zadnji;
  zadnji = lista;
  
  while(zadnji->sljedeci){TEST(2);
    zadnji = zadnji ->sljedeci;
  }
  novi = new tinv;
  zadnji -> sljedeci = novi;
  novi -> sljedeci = NULL; 
  cout << "Sifa inventara: "; cin >> novi ->sifra_inv;
  zbroj = zbroj + novi ->sifra_inv;
  cout << "Naziv inventara: "; unos(novi->naziv_inv);
  cout << "Broj komada: "; cin >> novi->komada; 
};

void ispis_ele(tinv *lista){TEST(3);
  tinv *tekuci = lista -> sljedeci;
  while(tekuci){TEST(4);
    cout << "Sifra inventara: " << tekuci ->sifra_inv << endl;
    cout << "Naziv inventara: " << tekuci ->naziv_inv << endl; 
    cout << "Broj komada: " << tekuci ->komada << endl;
    cout << "Vrijednost pokazivaca na sljedeci element: " << int ((size_t)tekuci->sljedeci) << endl; 
    tekuci = tekuci -> sljedeci; 
  };
};

void pretrazivanje(tinv *lista, int sifra_inv){TEST(5);
  tinv *tekuci = lista -> sljedeci; 
  while(tekuci){TEST(6);
    if(tekuci -> sifra_inv == sifra_inv){TEST(7);
      cout << "Sifra inventara: " << tekuci ->sifra_inv << endl;
      cout << "Naziv inventara: " << tekuci ->naziv_inv << endl; 
      cout << "Broj komada: " << tekuci ->komada << endl;
      return; 
    }
    tekuci = tekuci -> sljedeci; 
  };
  cout << "Element nije pronaden." << endl; 
};

void brisanje(tinv *lista, int sifra_inv){TEST(8);
  tinv *brisi = lista ->sljedeci, *prethodni = lista; 
  while(brisi){TEST(9);
    if(brisi->sifra_inv == sifra_inv){TEST(10);
      prethodni -> sljedeci = brisi ->sljedeci;
      delete brisi;
      cout << "Element je izbrisan iz vezane liste." << endl;
      return;
    }
    prethodni = brisi;
    brisi = brisi ->sljedeci;
  };
  cout << "Element za brisanje nije pronaden." << endl; 
};

int main(){TEST(11);
  int izbor, sifra_inv; 
  tinv *lista = new tinv;
  lista -> sljedeci = NULL;
  do{TEST(12);
    cout << "----PROGRAM----" << endl;
    cout << "1. Unos novog elementa vezane liste" << endl;
    cout << "2. Ispis sadrzaja vezane liste" << endl;
    cout << "3. Pretrazivanje vezane liste" << endl;
    cout << "4. Brisanje elemenata liste" << endl; 
    cout << "Vas odabir je: "; cin >> izbor; 
    TEST(13); switch(izbor){
      case 1: dod_ele(lista); break; 
      case 2: ispis_ele(lista);
          cout << "Zbroj : " << zbroj << endl; 
          break;
      case 3: cout << "Unesite sifru inventara: "; cin >> sifra_inv;
          pretrazivanje(lista, sifra_inv);
          break;
      case 4: cout << "Unesite sifru inventara za brisanje: "; cin >> sifra_inv;
          brisanje(lista, sifra_inv);
          break;
      default: 
        cout << "Krivi odabir." << endl;
    }
  }while(izbor !=9);
  system("PAUSE");
}  // Postoci testiranja:  100% 100% 100%// H1:555510243434314543446563013153406400032100444443000200200000020000// H2:888530676757757865777776047178717610350000566640000400300000040000// H3:000000000000000000001000000000000000000000000000000000000000000000// H4:000000000000000000000000000000000000000000000000000000000000000000
