#include <iostream>
#include <algorithm>

using namespace std;

string arr[10000];

bool cmp(const string &a, const string &b) {
    if (a.size() == b.size())
        return (a < b);
    return (a.size() < b.size());
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++)
        cin >> arr[i];

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i ++)
        cout << arr[i] << '\n';
}