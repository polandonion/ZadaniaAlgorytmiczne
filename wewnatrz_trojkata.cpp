#include <iostream>

using namespace std;

struct Punkt {
	long long x, y;
};

Punkt abc[3], def[3];

bool wewnatrz(int idx) {
	bool znak = ((abc[1].x - abc[0].x) * (def[idx].y - abc[0].y) -
				 (def[idx].x - abc[0].x) * (abc[1].y - abc[0].y) >= 0);

	for (int i = 1; i < 3; i ++)
		if (((abc[(i + 1) % 3].x - abc[i].x) * (def[idx].y - abc[i].y) -
				 (def[idx].x - abc[i].x) * (abc[(i + 1) % 3].y - abc[i].y) >= 0) != znak)
			return 0;

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i ++)
		cin >> abc[i].x >> abc[i].y;
	for (int i = 0; i < 3; i ++)
		cin >> def[i].x >> def[i].y;

	bool war = 1;
	for (int i = 0; i < 3; i ++)
		if (!wewnatrz(i))
			war = 0;

	if (war)
		cout << "TAK";
	else
		cout << "NIE";
}