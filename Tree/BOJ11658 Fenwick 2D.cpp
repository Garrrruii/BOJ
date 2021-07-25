#include <iostream>
using namespace std;

int fen[1025][1025];
int a[1025][1025], N;
void upd_(int r0, int c0, int val) {
	int c;
	while (r0 <= N) {
		c = c0;
		while (c <= N) fen[r0][c] += val, c += (c & -c);
		r0 += (r0 & -r0);
	}
}
int sum_(int r1, int c1, int r2, int c2) {
	r1--, c1--;
	int ret = 0, c;
	while (r1) {
		c = c1;
		while (c) ret += fen[r1][c], c -= (c & -c);
		c = c2;
		while (c) ret -= fen[r1][c], c -= (c & -c);
		r1 -= (r1 & -r1);
	}
	while (r2) {
		c = c2;
		while (c) ret += fen[r2][c], c -= (c & -c);
		c = c1;
		while (c) ret -= fen[r2][c], c -= (c & -c);
		r2 -= (r2 & -r2);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> a[i][j], upd_(i, j, a[i][j]);
	}

	int w, x, y, c, d; //xÇà y¿­
	while (M--) {
		cin >> w >> x >> y >> c;
		if (!w) upd_(x, y, c - a[x][y]), a[x][y] = c;
		else cin >> d, cout << sum_(x, y, c, d) << "\n";
	}
	return 0;
}