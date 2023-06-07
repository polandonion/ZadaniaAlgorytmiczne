#include <iostream>
#include <stack>

using namespace std;

stack <int> stos;
int wys[250000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x;
	for (int i = 0; i < n; i ++)
		cin >> x >> wys[i];

	int ile = 0;
	for (int i = 0; i < n; i ++) {
		while (stos.size() != 0 and stos.top() > wys[i])
			stos.pop();

		if (stos.size() == 0 or stos.top() < wys[i])
			stos.push(wys[i]), ile ++;
	}

	cout << ile;
}