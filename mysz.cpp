#include <iostream>
#include <queue>

using namespace std;

struct Punkt2D {
	int x, y;
};

char plansza[1001][1001];
int X, Y, vis[1001][1001];
queue <Punkt2D> q;

void bfs(Punkt2D start) {
	q.push(start);
	vis[start.x][start.y] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x > 1 and plansza[x - 1][y] != 'x' and !vis[x - 1][y]) {
			q.push({x - 1, y});
			vis[x - 1][y] = vis[x][y] + 1;
		} // moge pojsc w lewo i vis[x - 1][y] nie jest juz najlepsze
		if (x < X and plansza[x + 1][y] != 'x' and !vis[x + 1][y]) {
			q.push({x + 1, y});
			vis[x + 1][y] = vis[x][y] + 1;
		} // analogicznie dla {x + 1, y}
		if (y > 1 and plansza[x][y - 1] != 'x' and !vis[x][y - 1]) {
			q.push({x, y - 1});
			vis[x][y - 1] = vis[x][y] + 1;
		} // tutaj w gore, czyli wierzcholek {x, y - 1}
		if (y < Y and plansza[x][y + 1] != 'x' and !vis[x][y + 1]) {
			q.push({x, y + 1});
			vis[x][y + 1] = vis[x][y] + 1;
		} // a tutaj w dol
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ilosc kolumn planszy (X) oraz jej wierszy (Y)
	cin >> X >> Y;

	// wspolrzedne wejscia (wej) oraz wyjscia (wyj)
	Punkt2D wej, wyj;
	for (int y = 1; y <= Y; y ++) {
		for (int x = 1; x <= X; x ++) {
			cin >> plansza[x][y];

			if (plansza[x][y] == 'w')
				wyj = {x, y};
			else if (plansza[x][y] == 'o')
				wej = {x, y};
		}
	}

	bfs(wej);

	if (vis[wyj.x][wyj.y] == 0)
		cout << "NIE";
	else
		cout << vis[wyj.x][wyj.y];
}