    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    // cza[i] - predkosc i-tej czasteczki
    int cza[100001];
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0); cout.tie(0);
     
    	// n - ilosc czasteczek
    	int n;
    	cin >> n;
     
    	// wczytujemy kolejne predkosci czasteczek
    	for (int i = 1; i <= n; i ++)
    		cin >> cza[i];
     
    	// sortujemy cala tablice, aby wyszukiwanie
    	// binarne bylo mozliwe do zrealizowania
    	sort(cza + 1, cza + n + 1);
     
    	// m - ilosc odczytow
    	int m;
    	cin >> m;
     
    	for (int i = 1; i <= m; i ++) {
    		// x - predkosci, o ktore pyta Bajtazar
    		int x;
    		cin >> x;
     
    		// ilosc takich czasteczek mozna wyrazic za pomoca roznicy
    		// indeksu ostatniego wystapienia tego elementu i indeksu
    		// pierwszego takiego wystapienia
    		cout << upper_bound(cza + 1, cza + n + 1, x) - lower_bound(cza + 1, cza + n + 1, x);
    		cout << '\n';
    	}
    }
