#include <cstdio>

using namespace std;

int n, arr[100009];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
        scanf("%d", (arr + i));

    long long wyn = 0;
    for (int i = 2; i <= n - 1; i ++) {
        int mniLew = 0, wiePra = 0;

        for (int j = i - 1; j >= 1; j --)
            mniLew += (arr[j] < arr[i]);
        for (int j = i + 1; j <= n; j ++)
            wiePra += (arr[j] > arr[i]);

        wyn += (long long)mniLew * wiePra;
    }

    printf("%lld", wyn);
}