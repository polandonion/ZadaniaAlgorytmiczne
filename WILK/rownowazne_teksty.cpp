#include <iostream>
#include <string>

using namespace std;

bool row(string a, string b) {
	if (a.size() % 2 == 1)
		return (a == b);
	
	string a1 = a.substr(0, a.size() / 2);
	string a2 = a.substr(a.size() / 2);
	
	string b1 = b.substr(0, b.size() / 2);
	string b2 = b.substr(b.size() / 2);
	
	return ((row(a1, b1) and row(a2, b2)) or (row(a1, b2) and row(a2, b1)));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	
	cout << (row(a, b) == 1 ? "TAK" : "NIE");
}