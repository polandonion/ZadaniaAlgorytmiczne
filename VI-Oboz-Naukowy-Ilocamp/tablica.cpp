#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001], b[1000001];
int pozA[1000001], pozB[1000001];
int sufA[1000001], sufB[1000001];
int zerA = 0, zerB = 0;
int jedA = 0, jedB = 0;
int wy = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] == 0) {
			zerA ++;
			pozA[zerA] = i;
		}
	}
	for (int i = 1; i <= m; i ++) {
		cin >> b[i];
		if (b[i] == 0) {
			zerB ++;
			pozB[zerB] = i;
		}
	}

	for (int i = n; i >= 1; i --) {
		if (a[i] == 1)
			jedA ++;
		sufA[i] = jedA;
	}
	for (int i = m; i >= 1; i --) {
		if (b[i] == 1)
			jedB ++;
		sufB[i] = jedB;
	}

	/*for (int i = 1; i <= zerA; i ++)
		cout << pozA[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= zerB; i ++)
		cout << pozB[i] << ' ';
	cout << '\n';

	for (int i = 1; i <= n; i ++)
		cout << sufA[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= m; i ++)
		cout << sufB[i] << ' ';*/

	for (int i = 1; i <= min(zerA, zerB); i ++)
		wy = max(wy, i + min(sufA[pozA[i] + 1], sufB[pozB[i] + 1]));
	cout << wy;
}