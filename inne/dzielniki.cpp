#include <iostream>
#include <math.h>

using std::cin;
using std::cout;

void function(long long i, long long n) {
	if(n % i == 0) cout << i << '\n';
	if((i + 1) * (i + 1) <= n) function(i + 1, n);
	if(n % i == 0 and i * i < n) cout << n / i << '\n';
}

int main() {
	long long n;
	cin >> n;
	function(1, n);
}
