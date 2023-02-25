/* Zadanie da się rozwiązać w O(n * log n)

To zadanie jest jednym z fajniejszych na
wyszukiwanie binarne. Zauważmy, że
zależy nam na sytuacji, w której, po
położeniu dowolnego szarego odważnika na
wyznaczonym polu, w równowadze stanie
szala stojąca jak najniżej.

Rozwiązanie brutalne:
Robimy n symulacji. W każdej kładziemy
dowolny inny szary odważnik i sprawdzamy
czy jakaś waga nie stanęła w równowadze.
Jeśli tak, to należy także sprawdzić, czy
posiadamy odważnik o masie dwukrotnie wię-
kszej od tego, który stanął w równowadze.
Wyszukać owy odważnik można zarówno liniowo
jak i binarnie. Niestety przespieszenie
O(n ^ 3) do O(n ^ 2 * log n) nadal nie
sprawi, że dostaniemy 100% za to zadanie,
bo wynik nie przekroczy 50%, ze względu
na ilość operacji, czyli de facto na czas.

Rozwiązanie wzorcowe:
W rozwiązaniu wzorcowym posłużymy się
sumami prefiksowymi policzonymi od
końca oraz wyszukiwaniem binarnym.
Sortujemy tablicę szarych odważników, a
następnie liczymy tablicę sum prefisowych
dla tablicy czarnych odważników, tyle, że
od końca. To sprawi, że będziemy mieli
dostęp w O(1) do informacji, którą w roz-
wiązaniu brutalnym wyszukiwaliśmy liniowo.
Niech pre[i] oznacza sumę odważników na
i-ostatnich szalkach. Więc np. wartość
pre[n] = cza[n], gdzie cza[] to tablica
czarnych odważników. pre[n - 1] = cza[n] +
cza[n - 1] itd. Tablicę pre[] obliczamy w
O(n). Teraz wystarczy przejść raz pętlą
po wszystkich szalkach i sprawdzić, czy
w tablicy szarych odważników występuje taki
o wartości równej cza[i] - pre[i + 1].
Dlaczego szukamy akurat takiej wartości?
Odpowiedź jest trywialna: jeśli znajdziemy
ową wartość, szalka o indeksie i stanie w
równowadze, a teraz wystarczy już wyszukać
binarnie, czy w tablicy szarych odważników
występuje odważnik o wadze dwukrotnie
większej od wagi czarnego odważnika stoją-
cego na szalce o indeksie i. Po poprawkach
złożoność czasowa wynosi O(n * log n), co
wystarcza do zdobycia 100% za to zadanie. */

#include <iostream>
#include <algorithm>

using namespace std;

long long cza[1000001], sza[1000001], pre[1000002];
int n;

bool znal(long long su) {
	int l = 1, r = n;
	while (l < r) {
		int sr = (l + r) / 2;

		if (sza[sr] == su)
			return 1;

		if (sza[sr] < su)
			l = sr + 1;
		else
			r = sr - 1;
	}

	return (sza[l] == su);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> cza[i];

	for (int i = 1; i <= n; i ++)
		cin >> sza[i];

	sort(sza + 1, sza + n + 1);

	for (int i = n; i > 1; i --)
		pre[i] = pre[i + 1] + cza[i];

	int wynik = n + 1;
	for (int i = 1; i < n; i ++)
		if (znal(cza[i] - pre[i + 1]) and znal(cza[i] * 2))
			wynik = min(wynik, i);

	cout << wynik;
}