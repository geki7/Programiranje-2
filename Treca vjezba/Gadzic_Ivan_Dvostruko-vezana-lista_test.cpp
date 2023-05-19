// MD5:hW4/rl1m3Hnl/DDn4b/UXA==// Verifikator 5.05// Program:Dvostruko-vezana-lista// Opis zadatka:Dvostruko_vezana_lista// Autor:Ivan Gadzic// Pocetno vrijeme:10/29/2021 11:18:05 AM// Završno vrijeme:10/29/2021 1:30:21 PM// Identifikatori:main,izbor,tracunalo,sifra_r,naziv_r[20],proizvodac[20],god_p,trac,dod_ele,*sljedeci,*lista,*novi,*zadnji,lista,zadnji,*prethodni,novi,*tekuci,dod_ele_k,dod_ele_p,sljedeci,int,bris_ele,*brisi,brisi_ele,a,vrijeme// IP:fe80::b993:1665:dccd:c05f%10 ( 5054 )// #:#include <ctime>[B],#include <iostream>[B],#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevodenja:55/30#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,13,16,31,41,43,51,71,75,76,78,79,98,103,110}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=14;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 14):" << endl; 
  for (f=1;f<=14;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct trac{
  int sifra_r;
  char naziv_r[20];
  char proizvodac[20];
  int god_p;
  long vrijeme;
  trac *sljedeci;
  trac *prethodni;
};
void dod_ele_k(trac *lista){TEST(1);
  trac *novi, *zadnji;
  zadnji = lista;
  while(zadnji->sljedeci){TEST(2);
    zadnji = zadnji -> sljedeci;
  };
  novi = new trac;
  novi -> prethodni = zadnji; 
  novi -> sljedeci = NULL;
  zadnji -> sljedeci = novi;
  vrijeme_pocetak();
  cout << "Sifra racunala: "; cin >> novi -> sifra_r;
  cout << "Naziv racunala: "; unos(novi -> naziv_r);
  cout << "Naziv proizvodaca: "; unos(novi -> proizvodac); 
  cout << "Godina proizovodnje: "; cin >> novi -> god_p;
  vrijeme_kraj();
  novi -> vrijeme = vrijeme_proteklo()/1000;
  trac *tekuci = lista -> sljedeci;
  while(tekuci){TEST(3);
    cout << "Sifra racunala: " << tekuci -> sifra_r << endl;
    cout << "Naziv racunala: " << tekuci -> naziv_r << endl;
    cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
    cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
    cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
    tekuci = tekuci -> sljedeci;
  };
};

void dod_ele_p(trac *lista){TEST(4);
  trac *tekuci = lista -> sljedeci;
  while(tekuci){TEST(5);
    cout << "Sifra racunala: " << tekuci -> sifra_r << endl;
    cout << "Naziv racunala: " << tekuci -> naziv_r << endl;
    cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
    cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
    cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
    tekuci = tekuci -> sljedeci;
  };
  if(!lista -> sljedeci){TEST(6);
    dod_ele_k(lista);
    return;
  };
  trac *novi, *sljedeci;
  sljedeci = lista -> sljedeci;
  novi = new trac;
  novi -> prethodni = lista;
  novi -> sljedeci = sljedeci;
  lista -> sljedeci = novi;
  sljedeci -> prethodni = novi;
  vrijeme_pocetak();
  cout << "Sifra racunala: "; cin >> novi -> sifra_r;
  cout << "Naziv racunala: "; unos(novi -> naziv_r);
  cout << "Naziv proizvodaca: "; unos(novi -> proizvodac); 
  cout << "Godina proizovodnje: "; cin >> novi -> god_p;
  vrijeme_kraj();
  novi -> vrijeme = vrijeme_proteklo()/1000;
};

void brisi_ele(trac *lista, int sifra_r){TEST(7);
  char a;
  trac *brisi = lista -> sljedeci, *prethodni = lista;
  trac *tekuci = lista -> sljedeci; 
  while(brisi){TEST(8);
    if(brisi->sifra_r == sifra_r){TEST(9);
      cout << "Zelite li izbrisati listu d/n: "; cin >> a;
      if(a == 'D' || a == 'd'){TEST(10);
        while(tekuci){TEST(11);
          cout << "Sifra racunala: " <<  tekuci -> sifra_r << endl;
          cout << "Naziv racunala: " <<  tekuci -> naziv_r << endl;
          cout << "Naziv proizvodaca: " << tekuci -> proizvodac << endl;
          cout << "Godina proizvodnje: " << tekuci -> god_p << endl;
          cout << "Vrijeme proteklo: " << tekuci -> vrijeme << endl;
          prethodni -> sljedeci = brisi -> sljedeci;
          delete brisi;
          cout << "Element je izbirsan iz vezane liste." << endl;
          return;
        };
      };
    };
    prethodni = brisi;
    brisi = brisi -> sljedeci;
  };
  cout << "Element za brisanje u vezanoj listi nije pronaden." << endl;
};

int main(){TEST(12);
  int izbor, sifra_r;
  trac *lista = new trac;
  lista -> sljedeci = NULL;
  lista -> prethodni = NULL; 
  do{TEST(13);
    cout << "----Program----" << endl;
    cout << "1. Dodavanje elemenata na kraj dvoustrko vezane liste" << endl;
    cout << "2. Dodavanje elemenata na pocetak dvostruko vezane liste" << endl; 
    cout << "3. Brisanje cvora iz vezane liste" << endl;
    cout << "4. Binarno stablo" << endl; 
    cout << "Vas odabir je: "; cin >> izbor; 
    TEST(14); switch(izbor){
      case 1 : dod_ele_k(lista); break;
      case 2 : dod_ele_p(lista); break;
      case 3 : cout << "Unesite sifru racunala: "; cin >> sifra_r;
          brisi_ele(lista, sifra_r); break;
      case 4 : cout << "4" << endl; 
          break;
      default :
        cout << "Krivi odabir..." << endl; 
    }; 
  }while(izbor !=9);
  system("PAUSE");
}
    // Postoci testiranja:  100% 100% 100%// H1:4546300000000000000000000000000000000000000000000000000000000015416644344324104151033400104144254401010034004644000031500023545644362// H2:7887400000000000000000000000000000000000000000000000000000000057768867686557468560568000406687676001030056006574004467700060505387466// H3:0000000000000000000000000000000000000000000000000000000000000000000000000001000000000100000000000000000020000000000000000000000000000// H4:0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
