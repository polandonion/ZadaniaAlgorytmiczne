#include <bits/stdc++.h>

using namespace std;

struct Fish{
	float wei, age;
	int id;
};

vector <Fish> v1, v2;
int dead[1000001];

bool f(Fish a, Fish b) {
	if (a.wei == b.wei)
		return (a.age < b.age);
	return (a.wei < b.wei);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++) {
		float a, b;
		cin >> a >> b;

		v1.push_back({a, b, i});
	}

	int day = 1;
	while (!v1.empty()) {
		sort(v1.begin(), v1.end(), f);

		int l = 0, r = v1.size() - 1;
		while (l < r) {
			dead[v1[l].id] = day;

			if (v1[r].wei >= v1[l].wei) {
				v1[r].wei += v1[l].wei / 2;
				v2.push_back(v1[r]);
			}
			else
				dead[v1[r].id] = day;

			l ++, r --;
		}
		if (l == r)
			dead[v1[l].id] = day;

		v1 = v2;
		v2.clear();

		day ++;
	}

	int q;
	cin >> q;

	while (q --) {
		int a, b;
		cin >> a >> b;

		if (dead[a] > b)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}
