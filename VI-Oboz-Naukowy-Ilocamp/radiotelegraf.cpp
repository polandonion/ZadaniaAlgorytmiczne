/* Zadanie rozwiązać można w O(n * log n)

Zadanie to jest klasykiem wyszukiwania
binarnego po wyniku zaraz po zadaniu Tort
z V OIG (zachęcam do zrobienia). Zadanie,
jak już wspomniałem, można rozwiązać przy
pomocy algorytmu wyszuiwania binarnego po
wyniku. W naszym przypadku wynikiem będzie
długość podciągu naszego ciągu wejściowego.
Dodatkowo, należy zwrócić uwagę na to, że
zakres wyniku mieścił się będzie w przedziale
[1, n], bo gdy zmienna w jest zerem, to nadal
poziadamy spójne fragmenty ciągu, w których
wszystkie liczby mają taką samą wartość. Mowa
tutaj o pojedynczych elementach ciągu.

Częścią obliczniową programu będzie więc
funkcja typu bool, która zwróci true, gdy
ciąg o ustalonej długości jest poprawny.
Poprawny, w tym przypadku, oznacza taki,
którego długość da się uzyskać poprzez
zamianę pojedynczych elementów ciągu, lub
w ogóle ich nie podmieniając, i który jed-
nocześnie będzie spełniał warunki zadania.

Jak więc sprawdzić, czy ciąg o długości k
jest poprawny? Jedną z metod na sprawdzenie
poprawności jest 'przelecenie' po kolei
wszystkich spójnych fragmentów ciągu o dłu-
gości k i sprawdzeniu czy różnica k oraz
ilość liczb, które wystąpiły najczęściej
nie przekracza liczby w. Niestety funkcja
ta działać będzie w O(n ^ 2). Cały program
zadziała więc w czasie O(n ^ 2 * log n),
co niestety nie da nam 100%.

Kolejnym sposobem jest użycie hybrydy
multiseta oraz mapy. Za każdym razem
zwiększam ilość wystąpienia liczby o
indeksie głowy gąsienicy, i redukuję
ilość wystąpień liczby znajdującej się
pod indeksem równym ogonowi gąsienicy.
Dodatkowo przed i po każdej z tych ope-
racji aktualizuję multiseta i za każdym
razem sprawdzam poprawność aktualnego
fragmentu ciągu. To rozwiązanie działa
w złożoności O(n * log n * log n) i
także nie daje 100%. Oczywiście ten
algorytm można przyspieszać, np. zamiast
mapy użyć unordered_map, ale asymptotyczna
złożoność czasowa nadal będzie oscylować
w granicach O(n * log n * log n).

Ostatni sposób jest sposobem wzorcowym
i opiera się na tzw. skalowaniu elementów
tablicy. Zauważmy, że ilość różnych ele-
mentów ciągu nie przekracza 1e6, gdyż
sama ilość wszystkich wyrazów ciągu nie
przekracza tej wartości. Ta sztuczka
pomoże nam w zliczaniu elementów oraz w
pozbyciu się mapy, bo teraz odczytywanie
wartości ilości elementów o wartości x
działa w O(1), a nie w O(log n) jak do
tej pory miało to miejsce. Okej, mapa z
głowy, ale jak pozbyć się multiseta?
Wyżej wspomniałem o zliczaniu elementów
i nie bez sensu. Zauważmy, że tablica
przechowująca w ile[i] wartość ile liczb
występuje dokładnie i-razy pomoże nam w
określaniu dominanty badanego fragmentu.
W trakcie badania fragmentu ciągu należy
sprawdzić, czy w tablicy ile[] o indeksie
równym ilości wystąpień elementu na ogonie
gąsienicy jest równy 1 oraz czy ilość wys-
tąpień dominanty fragmentu jest równa temu
indeksowi. Jeśli tak, to liderem jest od
teraz liczba o 1 mniejszsa niż dotychczasowy
lider. Zwiększać wartość zmiennj lider bę-
dziemy wtedy, gdy ilość wystąpień elementu o
indeksie równym głowie gąsienicy przewyższy
wartość dotychczasową zmiennej lider. Całość
powinna działać w złożono ści O(n * log n). */

#include <iostream>
#include <algorithm>

using namespace std;

struct Element {
	int war, idx;

	bool operator < (Element &element) {
		if (war == element.war)
			return (idx < element.idx);
		return (war < element.war);
	}
};

Element a[1000001];
int n, k, b[1000001];
int wyst[1000001], ile[1000001];

bool pasuje(int x) {
	for (int i = 1; i <= n; i ++)
		ile[i] = 0, wyst[b[i]] = 0;

	int lider = 0;
	for (int i = 1; i <= x; i ++) {
		if (ile[wyst[b[i]]] != 0)
			ile[wyst[b[i]]] --;
		wyst[b[i]] ++;
		ile[wyst[b[i]]] ++;

		lider = max(lider, wyst[b[i]]);
	}

	if (x - lider <= k)
		return 1;

	for (int l = 1, r = x + 1; r <= n; l ++, r ++) {
		ile[wyst[b[r]]] --;
		wyst[b[r]] ++;
		ile[wyst[b[r]]] ++;

		if (wyst[b[r]] > lider)
			lider ++;


		if (ile[lider] == 1 and wyst[b[l]] == lider)
			lider --;

		ile[wyst[b[l]]] --;		
		wyst[b[l]] --;
		ile[wyst[b[l]]] ++;


		if (x - lider <= k)
			return 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i].war;
		a[i].idx = i;
	}

	sort(a + 1, a + n + 1);

	// skalowanie
	int j = 1;
	b[a[1].idx] = j;
	for (int i = 2; i <= n; i ++) {
		if (a[i].war == a[i - 1].war)
			b[a[i].idx] = b[a[i - 1].idx];
		else
		{
			j ++;
			b[a[i].idx] = j;
		}
	}

	// wyszukiwanie binarne po wyniku
	int l = 1, r = n;
	while (l < r) {
		int sr = (l + r + 1) / 2;

		if (pasuje(sr))
			l = sr;
		else
			r = sr - 1;
	}
	cout << l;
}