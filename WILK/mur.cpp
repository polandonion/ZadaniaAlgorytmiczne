#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pkt {
    long long x, y;

    bool operator < (const Pkt &pkt) const {
        if (x == pkt.x)
            return (y < pkt.y);
        return (x < pkt.x);
    }
};

vector <Pkt> pkt, otoczka;

long long ilo_wek(Pkt A, Pkt B, Pkt C) {
    return ((C.x-A.x)*(B.y-A.y) - (B.x-A.x)*(C.y-A.y));
}

void buduj_otoczke(int n) {
    otoczka.push_back(pkt[0]);
    otoczka.push_back(pkt[1]);

    int k = 1;
    for (int i = 2; i < n; i ++) {
        while (k > 0 and ilo_wek(otoczka[k - 1], otoczka[k], pkt[i]) > 0)
            k --, otoczka.pop_back();

        otoczka.push_back(pkt[i]);
        k ++;
    }

    for (int i = n - 2; i > 0; i --) {
        while (k > 0 and ilo_wek(otoczka[k - 1], otoczka[k], pkt[i]) > 0)
            k --, otoczka.pop_back();
        
        otoczka.push_back(pkt[i]);
        k ++;
    }

    while (k > 0 and ilo_wek(otoczka[k - 1], otoczka[k], pkt[0]) > 0)
            k --, otoczka.pop_back();

    cout << k + 1 << '\n';
    for (auto a : otoczka)
        cout << a.x << ' ' << a.y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        long long x, y;
        cin >> x >> y;

        pkt.push_back({x, y});
    }

    sort(pkt.begin(), pkt.end());

    buduj_otoczke(n);
}