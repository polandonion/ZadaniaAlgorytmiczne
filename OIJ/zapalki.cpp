#include <iostream>

using namespace std;

int tab[1000001];
// 1 - prawo, 0 - lewo
int lewoPref[1000002], prawSuf[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
		cin >> tab[i];
		
	int lew = 0;
	for (int i = 1; i <= n; i ++) {
		if (tab[i] == 0)
			lew ++;
		lewoPref[i] = lew;
	}
	
	int pra = 0;
	for (int i = n; i >= 1; i --) {
		if (tab[i] == 1)
			pra ++;
		prawSuf[i] = pra;
	}
	
	int mn = n;
	for (int i = 1; i <= n; i ++) {
		mn = min(mn, lewoPref[i - 1] + prawSuf[i + 1]);
	}
	
	cout << mn;
}
