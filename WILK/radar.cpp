#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pkt {
    long long x, y;

    bool operator < (const Pkt &pkt) const {
        if (x * pkt.y == pkt.x * y)
            return (x*x + y*y < pkt.x*pkt.x + pkt.y*pkt.y);
        return (x * pkt.y - pkt.x * y < 0);
    }
};

vector <Pkt> dol;
vector <Pkt> gor;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        long long x, y;
        cin >> x >> y;

        if (y < 0 or (y == 0 and x >= 0))
            dol.push_back({x, y});
        else
            gor.push_back({x, y});
    }

    sort(dol.begin(), dol.end());
    sort(gor.begin(), gor.end());

    for (auto a : dol)
        cout << a.x << ' ' << a.y << '\n';

    for (auto a : gor)
        cout << a.x << ' ' << a.y << '\n';
}