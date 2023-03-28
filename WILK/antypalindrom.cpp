#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        string str;
        cin >> str;

        for (int l = 0, r = str.size() - 1; l < r; l ++, r --) {
            if (str[l] == str[r]) {
                if (l == 0) {
                    if (str[l] != '1')
                        str[l] = '1';
                    else {
                        if (str[r] != '0')
                            str[r] = '0';
                        else
                            str[r] ++;
                    }
                }
                else {
                    if (str[l] != '0')
                        str[l] = '0';
                    else {
                        if (str[r] != '0')
                            str[r] = '0';
                        else
                            str[r] ++;
                    }
                }
            }
        }
        cout << str << ' ';
    }
}