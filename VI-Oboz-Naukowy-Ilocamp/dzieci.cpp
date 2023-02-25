/* Zadanie można rozwiązać w O(n)

Załóżmy, że dane wejściowe przedstawiają
pewien graf. Wczytując dane wejściowe zapiszmy
je do tablicy. Teraz przedstawmy nasz problem:
jeśli każde dziecko ma odwiedzić każde pole, to
oznacza, że musi istnieć droga łącząca wszystie
wierzchołki tego grafu, albo innymi słowy - musi
istnieć cykl obiegający wszystkie wierzchołki
grafu. Wystarczy podzielić ten graf na spójne
składowe (np. za pomocą algorytmu przeszukiwania
grafu w głąb DFS) i od ich ilości odjąć 1. To
będzie nasz ostateczny wynik, który należy wypisać
na standardowe wyjście. */

#include <iostream>

using namespace std;

int a[1000001];
bool v[1000001];

void dfs(int w) {
	v[w] = 1;
	if (!v[a[w]])
		dfs(a[w]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	int spo = 0;
	for (int i = 1; i <= n; i ++) {
		if (!v[i]) {
			dfs(i);
			spo ++;
		}
	}

	cout << spo - 1;
}
