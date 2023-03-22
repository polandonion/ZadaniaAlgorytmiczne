/*
Rozwiązanie brutalne:

    Zauważmy, że najprostszym sposobem na zliczenie wszystkich par,
    których iloczyn jest większy od zadanej liczby, jest przejście
    pętlą po wszystkikch elementach i sprawdzeniu poprawności pary.

    Pseudokod rozwiązania brutalnego:

        zadeklaruj n, d, tab[]
        wczytaj n, d

        for i = 1, i <= n, i ++
            wczytaj tab[i]

        zadeklaruj wynik = 0
        for i = 1, i <= n, i ++
            for j = i + 1, j <= n, j ++
                if tab[i] * tab[j] > d
                    wynik ++
        wypisz wynik

    Niestety jest to metoda nioptymalna i działa w złożoności O(n^2).


Rozwiązanie wzorcowe:

    Aby łatwiej było zrozumieć ideę rozwiązania wzorcowego, przedstawię
    jego działanie na prostym przykładzie. Załóżmy, że mamy ciąg długo-
    ści 7 oraz liczbę d równą 6. Ciąg wygląda następująco: 1 3 5 6 2 6 9.

    Teraz posortujmy liczby niemalejąco: 1 2 3 5 6 6 9.

    I teraz omówmy 'serce' naszego algorytmu; idea jest następująca: jeśli
    rozpatrujemy ostatnią liczbę naszego ciągu (x) i znajdziemy pierwsze
    takie wystąpienie a_i w naszym posortowanym ciągu, że x * a_i > d, to
    do wyniku dodajemy odległość indeksów pomniejszony o jeden, gdyż x nie
    może być wymnożony z samym sobą. Po takiej operacji wystarczy ostawić
    nasz 'nowy koniec ciągu' na o jeden mniejszy od aktualnego ostatniego
    a początek na to pierwsze wystąpienie, które znaleźliśmy. Gdy początek
    minie koniec to nie ma co sprawdzać, a łączna największa liczba przejść
    początku oraz końca to właśnie n.

    Zademonstrujmy więc działanie naszego algorytmu na powyższym przykładzie:

        Do a_7, czyli liczby 9, można dopasować wszystkie liczby z naszego
        ciągu oprócz niej samej czyli 6 (wynik = 6, pocz = 1, kon = 7 - 1 = 6).
        a_6: 4 (wynik = 10, pocz = 2, kon = 6 - 1 = 5)
        a_5: 3 (wynik = 13, pocz = 2, kon = 4)
        a_4: 2 (wynik = 15, pocz = 3, kon = 3)

        Kończymy nasz algorytm, gdyż zdażyła się sytuacja, w której: pocz >= kon.
        Łączna liczba par, o które nas proszą w zadaniu to 15.

    Oczywiście ten algorytm działa tylko dla wartości d, które są dodatnie.
    Dla d = 0 odpowiedzieć można w O(1), gdyż wystarczy zauważyć, że mnożąc
    ze sobą wszystkie liczby ujemne otrzymamy liczbę dodatnią. Nie będzie
    również zaskoczenia, jeśli powiem, że mnożąc ze sobą wszystkie liczby
    dodatnie także uzyskamy iloczyn dodatni. Jeśli więc podczas wczytywania
    tablicy zliczylibyśmy ilość liczb ujemnnych oraz dodatnich (nazwijmy te
    zmienne uje oraz dod), to odpowiedzią byłaby liczba:
        
        uje * (uje - 1) / 2 + dod * (dod - 1) / 2

    ponieważ z definicji kombinatorycznych wiemy, że do uzyskania iloczynu
    potrzebujemy dwóch liczb, Jeśli jedną z liczb możemy wybrać na x sposobów
    to drugą już możemy wybrać na (x - 1) sposobów. Całość dzielimy przez 2,
    ponieważ chcemy uniknąć dublowania tych samych par.

    Dla d < 0 dodatkowo musimy zliczyć ilość zer oraz odpalić w podobny sposób
    algorytm dla d > 0 (tutaj spróbuj trochę pomyśleć sam). Przez odpaleniem
    tego algorytmu możemy dodać do wyniku takie liczby:

        uje * (uje - 1) / 2
        dod * (dod - 1) / 2
        zera * (zera - 1) / 2
        zera * (uje + dod)

    Całość działa w złożonoćsi O(n), co wystarcza do uzyskania 100% za to zadanie.
*/

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n, k;
	cin >> n >> k;

	// wczytywanie --------------
	for (int i = 1; i <= n; i ++)
		cin >> arr[i];


	// sortowanie -------------
	sort(arr + 1, arr + n + 1);


	// zliczanie ujemnych, zer i dodatnich
	long long uje = 0, zer = 0, dod = 0;
	for (int i = 1; i <= n; i ++) {
		uje += (arr[i] < 0);
		zer += (arr[i] == 0);
		dod += (arr[i] > 0);
	}
	// -----------------------------------


	// pierwszy dodatni i ostatni ujemny
	long long pd = 1, ou = n;
	while (pd <= n and arr[pd] <= 0)
		pd ++;
	while (ou >= 1 and arr[ou] >= 0)
		ou --;
	// ---------------------------------

	// obliczenia ------------------------
	long long wyn = 0;
	if (k == 0) {
		// dodatnie z dodatnimi i analogicznie ujemne
		wyn += (uje * (uje - 1)) / 2;
		wyn += (dod * (dod - 1)) / 2;
		// ------------------------------------------
	}

	else if (k > 0) {
		long long l = 1, r = n;
		long long _ou = ou, _pd = pd;

		while (l < ou) {
			while (_ou >= 1 and arr[l] * arr[_ou] <= k)
				_ou --;

			if (_ou >= l)
				wyn += _ou - l;
			l ++;
		}
		while (pd < r) {
			while (_pd <= n and arr[_pd] * arr[r] <= k)
				_pd ++;

			if (_pd <= r)
				wyn += r - _pd;
			r --;
		}
	}

	else {
		// to samo co dla k == 0, dodatkowo zera
		wyn += (uje * (uje - 1)) / 2;
		wyn += (dod * (dod - 1)) / 2;
		wyn += (zer * (zer - 1)) / 2;
		wyn += (zer * (uje + dod));
		// -------------------------------------

		long long l = 1, r = n;
		long long _ou = ou, _pd = pd;

		while (_pd <= r) {
			while (l <= _ou and arr[_pd] * arr[l] <= k)
				l ++;

			if (l <= _ou)
				wyn += _ou - l + 1;
			_pd ++;
		}
	}
	// -----------------------------------

	cout << wyn;
}
