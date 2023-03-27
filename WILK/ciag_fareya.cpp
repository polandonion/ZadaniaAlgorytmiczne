#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ulamek {
    int licznik, mianownik;

    bool operator < (const Ulamek &ulamek) const {
        return (licznik * ulamek.mianownik < mianownik * ulamek.licznik);
    }
};

vector <Ulamek> vec;

int nwd(int a, int b) {
    if (b == 0)
        return a;
    return nwd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (nwd(i, j) == 1)
                vec.push_back({i, j});
        }
    }

    sort(vec.begin(), vec.end());

    cout << "0/1 ";
    for (auto a : vec)
        cout << a.licznik << '/' << a.mianownik << ' ';
    cout << "1/1";
}
