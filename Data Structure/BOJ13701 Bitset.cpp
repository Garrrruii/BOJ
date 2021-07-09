#include <iostream>
using namespace std;

unsigned int bit[1 << 20];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	unsigned int a, q, r;
	while (cin >> a) {
		q = a / 32;
		r = 1<<(a % 32);
		if (bit[q] & r) continue;
		
		bit[q] |= r; cout << a << " ";
	}
	return 0;
} 