#include <bits/stdc++.h>

using namespace std;

unordered_map <char, vector <char>> m;
unordered_map <char, bool> vis;
stack <char> sta;

void topoSort(char c);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string a, b;
	cin >> a;

	while (cin >> b) {
		if (b == "#")
			break;

		for (int i = 0; i < min(a.size(), b.size()); i ++) {
			if (a[i] != b[i]) {
				if (find(m[a[i]].begin(), m[a[i]].end(), b[i]) == m[a[i]].end())
					m[a[i]].push_back(b[i]);
				break;
			}
		}

		a = b;
	}

	for (auto i = m.begin(); i != m.end(); i ++) {
		if (!vis[i -> first])
			topoSort(i -> first);
	}

	if (m.size() == 0) {
		cout << a[0];
		return 0;
	}

	while (!sta.empty()) {
		cout << sta.top();
		sta.pop();
	}
}

void topoSort(char c) {
	vis[c] = 1;

	for (char _c : m[c]) {
		if (!vis[_c]) 
			topoSort(_c);
	}

	sta.push(c);
}
