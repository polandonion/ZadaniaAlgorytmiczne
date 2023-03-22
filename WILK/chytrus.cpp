#include <iostream>

using namespace std;

int tab[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		tab[x] ++;
	}
	
	int mn = 1e6, mnIdx;
	for (int i = 1; i <= 1e6; i ++) {
		if (tab[i] != 0 and tab[i] <= mn) {
			mn = tab[i];
			mnIdx = i;
		}
	}
	
	cout << mnIdx;
}
