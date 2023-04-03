#include <iostream>
#include <algorithm>

using namespace std;

struct Pkt {
    int x, y;

    bool operator < (const Pkt pkt) const {
        if (x == pkt.x)
            return (y < pkt.y);
        return (x < pkt.x);
    }
};

Pkt arr[10000];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++)
        cin >> arr[i].x >> arr[i].y;

    sort(arr, arr + n);

    for (int i = 0; i < n; i ++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';
}