#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector <long long> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long p = 2137;
	long long q = 694202137;

	int n;
	cin >> n;

	while (n --) {
		string str;
		cin >> str;

		long long hash = 0;
		for (auto a : str)
			hash = (hash * p + (long long)a) % q;

		vec.push_back(hash);
	}

	sort(vec.begin(), vec.end());
	vec.push_back(-1);

	int dl = 1, wyn = 0;

	for (int i = 1; i < vec.size(); i ++) {
		if (vec[i] == vec[i - 1])
			dl ++;

		else {
			wyn += dl * (dl - 1) / 2;
			dl = 1;
		}
	}
	cout << wyn;
}