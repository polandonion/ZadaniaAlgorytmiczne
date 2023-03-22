#include <iostream>

using namespace std;

int tab[100];

long long fib(short n) {
	if(tab[n] == 0) tab[n] = (fib(n - 1) + fib(n - 2));
	return tab[n];
}

void f(short n, string s) {
	if(n == 0) cout << s << endl;
	if(n >= 1) f(n - 1, s + "1 ");
	if(n >= 2) f(n - 2, s + "2 ");
}

int main() {
    tab[1] = 1;
    tab[2] = 2;
	short n;
	string s = "";
	cin >> n;
	cout << fib(n) << endl;
	f(n,s);
}
