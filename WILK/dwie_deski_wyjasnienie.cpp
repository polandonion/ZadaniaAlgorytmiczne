    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    // des[i] - dlugosc i-tej deski
    int des[100001];
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0); cout.tie(0);
     
    	// n - ilosc desek, s - dlugosc poreczy
    	int n, s;
    	cin >> n >> s;
     
    	// wczytujemy dlugosci desek
    	for (int i = 1; i <= n; i ++)
    		cin >> des[i];
     
    	// sortujemy dlugosci desek, aby byc
    	// w stanie wyszukiwac binarnie
    	sort(des + 1, des + n + 1);
     
    	// pomysl jest taki: idziemy po wszystkich deskach
    	// po kolei (od najmniejszych) i patrzymy, czy
    	// dlugosc i-tej deski jest mniejsza od s. Jesli
    	// tak sie dzieje, to wyszukujemy binarnie dlugosc
    	// deski o rozmiarze roznicy s oraz deski[i]
    	for (int i = 1; i <= n; i ++) {
    		// jezeli znajde pierwsze takie wystapienie, to nie ma co szukac dalej
    		if (des[i] < s and binary_search(des + 1, des + n + 1, s - des[i]) == 1) {
    			// mni - mniejsza z tych liczb, wie - wieksza
    			int mni = min(des[i], s - des[i]);
    			int wie = max(des[i], s - des[i]);
     
    			cout << mni << ' ' << wie;
    			break;
    		}
    	}
    }
