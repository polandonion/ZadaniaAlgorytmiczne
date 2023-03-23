#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
	int war, idx;

	bool operator < (const Element &element) const {
		if (war == element.war)
			return (idx < element.idx);
		return(war < element.war);
	}
};

int arr[1000000];
vector <Element> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		vec.push_back({arr[i], i});
	}

	sort(vec.begin(), vec.end());

	int mx = 1, r = 0;
	while (r < vec.size()) {
		if (r + 1 < vec.size() and vec[r].war == vec[r + 1].war) {
			int l = r, akt = 2;
			r = r + 1;
			while (r < vec.size()) {
				if (vec[r].idx - vec[l].idx + 1 - akt > m) {
					l ++;
					akt --;
				}
				else {
					mx = max(mx, min(m + akt, (int)vec.size()));
					r ++;
					akt ++;
				}

				if (l == r) {
					r ++;
					akt ++;
				}

				if (vec[r].war != vec[r - 1].war)
					break;
			}
		}
		else
			r ++;
	}
	cout << max(mx, min(m + 1, (int)vec.size()));
}
