/* Zadanie można rozwiązać w O(h).

Zauważmy na początku pewną właściwość
naszego drzewka. Co druga piłka, spada
do prawego poddrzewa. W prawym poddrzewie
sprawa wygląda rekurencyjnie. Jeśli jakaś
piłka dostanie się do prawego poddrzewa, to
co druga piłka spadnie do prawego poddrzewa
naszego poddrzewa itd. Drogę na sam dół naszej
piłeczki można więc uzależnić (pośrednio) od
parzystości wejściowej liczby n.

Żeby rozwiązać to zadanie trzeba mieć także
trochę podstawowej wiedzy nt. drzew binarnych,
mianowicie jeśli wysokość drzewka wynosi h, to
ilość liści wynosi 2^h, oczywiście zakładając,
że piętra numerujemy od zera. Jeśli więc zdarzy
się sytuacja (a może się owa zdarzyć), że ilość
wrzuconych piłeczek (n) jest większa od ilości
liści (2^h), modulujemy n w taki sposób:
		n = n % (2^h)
Po tej operacji mamy pewność, że log n <= h.


Pseudokod wzorcowego rozwiązania:

zadeklaruj n, h, ile_lisci, pozycja_pilki
wczytaj n, h

ile_lisci = 2^h
pozycja_pilki = 0
n %= ile_lisci

dopóki ile_lisci != 1
	jeśli n mod 2 = 0
		pozycja_pilki += (ile_lisci / 2)
		n /= 2
	w przeciwnym razie
		n = (n / 2) + 1
	
	ile_lisci /= 2;
	
wypisz pozycja_pilki */

#include <iostream>

using namespace std;

int main() {
	int n, h;
	cin >> n >> h;

	int pos = 0, pol = (1 << h) / 2;
	n %= pol * 2;

	while (pol != 0) {
		if (n % 2 == 0) { // prawa polowa
			pos += pol;
			n /= 2;
		}

		else // lewa polowa
			n = n / 2 + 1;

		pol /= 2;
	}

	cout << pos;
}

