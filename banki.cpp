/* Rozwiązanie w O(n * log(a + b))

To zadanie jest nietypowe, gdyż
nie wymaga znajomości zaawansowanej
algorytmiki lub znajomości struktur
danych, a po prostu wymaga zauważania
pewnych zależności. Po narysowaniu
na kartce papieru kilku(nastu)
przykładów, wyraźnie widać, że dla
dwóch liczb a i b odpowiedzią będzie
a * b - (a + b), oczywiście tylko
gdy a i b są względnie pierwsze.

Twierdzenie Chickena McNuggeta, znane
również jako Problem z monetą Frobeniusa
stwierdza, że dla dowolnych dwóch
względnie pierwszych liczb całkowitych
m i n , największą liczbą całkowitą, której
nie można wyrazić w postaci a * m + b * n
dla nieujemnych liczb całkowitych a oraz b
jest mn − m − n */

#include <iostream>

using ll = long long;
using namespace std;

long long nwd(int a, int b) {
	if (b == 0)
		return a;
	return nwd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n --) {
		int a, b;
		cin >> a >> b;

		if (nwd(a, b) == 1) // jesli a i b sa wzglednie pierwsze
			cout << (ll)a * b - (a + b) << '\n';
		else
			cout << -1 << '\n';
	}
}