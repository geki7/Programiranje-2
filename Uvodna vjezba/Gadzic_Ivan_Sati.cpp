// MD5:uHxEjBnacSWPsgleOcRjdg==// Verifikator 5.05// Program:Sati// Pocetno vrijeme: 12:06 (internetsko) Završno vrijeme: 13:36 Preostalo: 87 *// Opis zadatka:Sati, minute, sekunde// Autor:Ivan Gadzic// Pocetno vrijeme:10/8/2021 12:06:09 PM// Završno vrijeme:10/8/2021 12:08:59 PM// Identifikatori:main,br_sec,min,hour,sec// IP:fe80::985f:5bf:7ab1:b56c%18 ( 5054 )// #:#include <iostream>,// Uspješnih/neuspješnih prevodenja:2/0#include <iostream>
using namespace std;


int main(){
	int br_sec, min, hour, sec;
	cout << "Unesi broj sekundi: "; 
	cin >> br_sec; 
	
	hour = br_sec / 3600; 
	min = br_sec % 3600 /60; 
	sec = br_sec - (hour * 3600)-(min *60);
	
	cout << hour << "h: " << min << "min: " << sec << "s" << endl;
	cin >> sec; 
	return 0;
	system("PAUSE");
}
