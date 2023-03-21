#include <iostream>

using namespace std;

struct Punkt {
	long long x, y;
};

bool po_obu_stronach(Punkt a, Punkt b, Punkt c, Punkt d) {
	return (((d.x - c.x) * (a.y - c.y) - (a.x - c.x) * (d.y - c.y)) *
			((d.x - c.x) * (b.y - c.y) - (b.x - c.x) * (d.y - c.y)) < 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Punkt a, b, c, d;

	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	if (po_obu_stronach(a, b, c, d) and po_obu_stronach(c, d, b, a))
		cout << "TAK";
	else
		cout << "NIE";
}