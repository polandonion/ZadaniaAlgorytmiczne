#include "doblib.h"

int main() {
	long long n = inicjuj();

	long long l = 1, r = n;
	while (l + 1 < r) {
		long long sr = (l + r) / 2;

		if (sily(sr) == 1)
			l = sr;
		else
			r = sr;
	}

	odpowiedz(l);
}