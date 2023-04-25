#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long p = 2137;
	long long q = 694202137;

	int n;
	cin >> n;

	string wzo;
	cin >> wzo;

	// wartosc, ktora bede odejmowal podczas przesuwania
	// podciagu podczas sprawdzania poprawnosci wzorca
	long long p1 = 1;
	for (int i = 1; i < wzo.size(); i ++)
		p1 = (p1 * p) % q;

	// obliczam hasz wzorca
	long long hash_wzo = 0;
	for (auto a : wzo)
		hash_wzo = (hash_wzo * p + (long long)a) % q;

	while (n --) {
		string str;
		cin >> str;

		long long hash_str = 0;
		for (int i = 0; i < wzo.size(); i ++)
			hash_str = (hash_str * p + (long long)str[i]) % q;

		if (hash_str == hash_wzo) {
			cout << "TAK\n";
			continue;
		}

		bool ok = 0;
		for (int i = wzo.size(); i < str.size(); i ++) {
			hash_str = ((hash_str - p1 * (long long)str[i - wzo.size()]) % q + q) % q;
			hash_str = (hash_str * p + (long long)str[i]) % q;

			if (hash_str == hash_wzo) {
				cout << "TAK\n";
				ok = 1;
				break;
			}
		}

		if (ok == 0)
			cout << "NIE\n";
	}
}