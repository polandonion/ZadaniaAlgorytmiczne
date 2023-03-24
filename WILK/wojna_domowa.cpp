#include <bits/stdc++.h>

using namespace std;

void wczytaj();
void wczytaj_zapytanie();
void dfs1(int w);
void dfs2(int w);
void wypisz_stak();
void wyczysc_vis();

int n, k, ile = 0;
int vis[200001];
vector <int> v1[200001];
vector <int> v2[200001];
stack <int> stc;

int main() {
	cin >> n >> k;

	wczytaj();

	for (int i = 1; i <= n; i ++) {
		if (!vis[i])
			dfs1(i);
	}

	//wypisz_stak();
	wyczysc_vis();

	while (!stc.empty()) {
		int a = stc.top();

		if (!vis[a]) {
			ile ++;
			dfs2(a);
		}

		stc.pop();
	}
	cout << ile << '\n';

	cin >> k;

	wczytaj_zapytanie();

}

void wczytaj() {
	while (k --) {
		int a, b;
		cin >> a >> b;

		v1[a].push_back(b);
		v2[b].push_back(a);
	}
}

void dfs1(int w) {
	vis[w] = 1;
	
	//cout << w << ' ';

	for (int a : v1[w]) {
		if (!vis[a])
			dfs1(a);
	}

	stc.push(w);
}

void dfs2(int w) {
	vis[w] = ile;

	for (int a : v2[w]) {
		if (!vis[a])
			dfs2(a);
	}
}

void wypisz_stak() {
	while (!stc.empty()) {
		cout << stc.top() << ' ';
		stc.pop();
	}
}

void wyczysc_vis() {
	for (int i = 1; i <= n; i ++) {
		if (vis[i])
			vis[i] = 0;
	}
}

void wczytaj_zapytanie() {
	while (k --) {
		int a, b;
		cin >> a >> b;

		if (vis[a] == vis[b])
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}
