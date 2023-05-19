// MD5:SMyN1+xIITK4r387yCso7Q==// Verifikator 5.05// Program:Sortiranje // Pocetno vrijeme: 12:11 (internetsko) Završno vrijeme: 13:41 Preostalo: 77 *// Opis zadatka:Bubble sort// Autor:Ivan Gadzic// Pocetno vrijeme:10/8/2021 12:11:10 PM// Završno vrijeme:10/8/2021 12:23:25 PM// Identifikatori:main,i,niz[10],bubbl_sort,*polje,duljina,tmp,j,bubble_sort// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,// Uspješnih/neuspješnih prevodenja:15/3#include <iostream>
using namespace std;

void bubble_sort(int *polje, int duljina) {
	int tmp, i;
	for (i = duljina -1; i>0; i--){
		for(int j = 0; j<i; j++){
			if(polje[j+1] < polje[j]){
				tmp = polje[j];
				polje[j] = polje[j+1];
				polje[j+1] = tmp;
			}
		}
	}
}

int main(){
	int i;  
	int niz[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	for(i = 0; i<10; i++){
		cout << niz[i] << " ";
	} 
	cout << "\nSoritiram ... " << endl;
	bubble_sort(niz, 10);
	for(i = 0; i<10; i++){
		cout << niz[i] << " "; 
	}
	cin >> i; 
	system("PAUSE");
}
