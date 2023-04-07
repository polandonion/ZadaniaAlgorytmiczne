#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bus {
	int p, q;
};

vector <Bus> bus;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		int p, q;
		cin >> p >> q;

		bus.push_back({p, q});
	}

	sort(bus.begin(), bus.end(), [] (Bus A, Bus B) {
		if (A.p == B.p)
			return (A.q < B.q);
		return (A.p < B.p);
	});

	if (bus[0].p > 0) {
		cout << 0 << ' ' << 0;
		return 0;
	}

	int wyn = 1, akt = 0;
	while (n > 1 and akt < n and bus[akt].p == bus[akt + 1].p)
		akt ++;

	int nas;
	while (akt != n - 1) {
		int j = akt + 1;
		nas = akt;

		bool flag = false;
		while (j < n and bus[j].p <= bus[akt].q) {
			if (bus[j].q > bus[nas].q)
				flag = true;
			if (bus[j].q >= bus[nas].q)
				nas = j;

			j ++;
		}

		if (flag == false)
			break;

		wyn += flag;
		akt = nas;
	}

	cout << bus[akt].q << ' ' << wyn;
}