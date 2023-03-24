#include <bits/stdc++.h>

using namespace std;

vector <int> v[1009];
queue <int> q;
int odw[1009];

int n, m;

void bfs(int a) {
	for (int i = 1; i <= n; i ++)
		odw[i] = 0;
	q.push(a);
	odw[a] = 1;
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int i = 0; i < v[a].size(); i ++) {
			if (!odw[v[a][i]]) {
				odw[v[a][i]] = odw[a] + 1;
				q.push(v[a][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> c;
	while (c --) {
		cin >> a >> b;
		bfs(a);
		cout << odw[b] - 1 << '\n';
	}
		
}
