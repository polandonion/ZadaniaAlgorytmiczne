#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// alokacja pamieci na tablice
	int *tab = new int [n];


	// inny zapis wczytywania tablicy liczb
	for (int* i = tab; i != tab + n; i ++)
		cin >> *i;

	sort(tab, tab + n);

	int idx = n / 2;
	long long sum = 0;
	for(int i = 0; i < n; i ++)
		sum += abs((long long)tab[i] - tab[idx]);

	cout << sum;

	// zwalnianie pamieci
	delete [] tab;
}