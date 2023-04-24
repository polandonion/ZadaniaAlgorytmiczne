#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	string s = "";
	for (int i = 0; i < n; i ++) s += '1';
	for (int i = 0; i < n - 1; i ++) s += '0';
	cout << s;
}