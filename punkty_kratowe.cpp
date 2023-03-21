#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Punkt {
	long long x, y;
};

// wie[] - tablica wierzcholkow wielokata
Punkt wie[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++)
		cin >> wie[i].x >> wie[i].y;

	int B = 0;
	for (int i = 0; i < n; i ++)
		B += __gcd(abs(wie[i].x - wie[(i + 1) % n].x),
				   abs(wie[i].y - wie[(i + 1) % n].y));

	long long P = 0;
	for (int i = 0; i < n; i ++)
		P += wie[i].x * wie[(i + 1) % n].y - wie[(i + 1) % n].x * wie[i].y;
	P = abs(P / 2);

	cout << P - B / 2 + 1;
}