    #include <iostream> // cin / cout
    #include <algorithm> // min()
     
    using namespace std;
     
    // dzieci: 0 - dziewczynka, 1 - chlopiec
    bool dzi[1000001];
     
    // indeksy, na ktorych stoja kolejne dziewczynki
    int idx[1000001];
     
    int main() {
    	// linijki przyspieszajace
    	ios_base::sync_with_stdio(0);
    	cin.tie(0); cout.tie(0);
     
    	int n, k;
    	cin >> n >> k;
     
    	// wczytuje szereg dzieciakow
    	for (int i = 1; i <= n; i ++)
    		cin >> dzi[i];
     
    	// ileDzi - ile dziewczynek w szeregu
    	int ileDzi = 0;
    	for (int i = 1; i <= n; i ++) {
    		// jezeli napotkam dziewczynke, to zwiekszam ich
    		// ilosc oraz indeksowi rownemu ilosci dziewczynek
    		// przypisuje indeks tablicy dzieci
    		if (dzi[i] == 0) {
    			ileDzi ++;
    			idx[ileDzi] = i;
    		}
    	}
     
    	// jezeli mam niewystarczajaca liczbe dziewczynek
    	// to od razu wypisuje NIE
    	if (ileDzi < k)
    		cout << "NIE";
     
    	// w przeciwnym wypadku ide gasienica
    	else {
    		// ustawiam ogon (l) oraz glowe gasienicy (r)
    		// ponadto moim wyniekim jest narazie jakas
    		// bardzo ogromna liczbe, u mnie milion
    		int l = 1, r = k, ans = 1e6;
     
    		// dopoki nie brakuje mi jeszcze
    		// dziewczynek do sprawdzenia
    		while (r <= ileDzi) {
    			// zapisuje minimum z dotychczasowego wyniku
    			// oraz tego, ktory aktualnie sprawdzam
    			ans = min(ans, idx[r] - idx[l] + 1 - k);
     
    			// przesuwam zaworno ogon jak i
    			// glowe gasienicy o jeden
    			l ++;
    			r ++;
    		}
    		// wypisuje moje minimum
    		cout << ans;
    	}
    }
