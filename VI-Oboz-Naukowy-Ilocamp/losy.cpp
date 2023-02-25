/* Zadanie można rozwiązać w O(n * g)

W tym zadaniu posłużymy się jedną z potężnych
technik algorytmicznych - programowania
dynamicznego.

dp[i] - minimalna liczba losów przegywających,
które musimy zakupić, aby mieć pewność, że
kupimy co najmniej i losów wygrywających.

Rozwiązanie tego zadania może złudząco
przypominać problem plecakowy i słusznie.
Analizując kolejne kosze z losami mamy dwie
możliwości: albo kosz ten okaże się opłacalny
albo nie. Jeśli nie to pozostawiamy wartość z
poprzednich modyfikacji, natomiast jeśli tak
to modyfikujemy tę wartość (oczywiście tylko
jeśli jest ona bardziej opłacalna).

Dla każdego kosza więc przechodzimy przez
dp[] od końca i sprawdzamy opłacalność.

Załóżmy, że przechodzimy przez pętlę for,
w której iteratorem jest zmienna i, która
przechodzi przez wszystkie kosze. W niej
zagnieżdzona jest kolejna pętla for z
iteratorem j, modyfikująca dp[j]. Posiadamy
też wiedzę nt. ile jest losów wygrywających
oraz przegrywających we wszystkich koszach.
Nazwijmy te tablice wyg[i] oraz prz[i]. Teraz
jeśli chcemy zdecydować się na zakup losów z
aktualnie sprawdzanego kosza, musimy porównać
dp[j] i dp[j - wyg[i]] + prz[i] oraz wybrać
bardziej opłacalną wartość. */
#include <iostream>

using ll = long long;
using namespace std;

struct Kosz {
	int wyg, prz;
};

Kosz a[10001];
ll dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, g;
	cin >> n >> g;

	for (int i = 1; i <= n; i ++)
		cin >> a[i].wyg >> a[i].prz;

	ll sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += (ll)a[i].wyg;

	if (sum < g) {
		cout << "NIE";
		return 0;
	}

	const ll INF = 1e12;
	for (int i = 1; i <= g; i ++)
		dp[i] = INF;

	for (int i = 1; i <= n; i ++)
		for (int j = g; j >= 1; j --)
				dp[j] = min(dp[j], (ll)a[i].prz + dp[max(0LL, (ll)j - a[i].wyg)]);

	cout << dp[g] + g;
}