// MD5:uHxEjBnacSWPsgleOcRjdg==
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