// MD5:SMyN1+xIITK4r387yCso7Q==
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