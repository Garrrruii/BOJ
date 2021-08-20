#include <iostream>
using namespace std;

int seg[300000];
int lazy[300000];
void Lazy(int n, int s, int e) {
	if (!(lazy[n] & 1)) return;

	seg[n] = (e - s + 1) - seg[n];
	if (s != e) {
		lazy[n << 1] += lazy[n];
		lazy[(n << 1) + 1] += lazy[n];
	}
	lazy[n] = 0;
}
void Upd(int L, int R, int n, int s, int e) {
	Lazy(n, s, e);
	if (R < s || e < L) return;
	
	n <<= 1;
	if (L <= s && e <= R) { // [s,e]in[L,R]
		if (s != e) { lazy[n]++; lazy[n + 1]++; }
		seg[n >> 1] = (e - s + 1) - seg[n >> 1];
	}
	else {
		int mid = (s + e) >> 1;
		Upd(L, R, n, s, mid); Upd(L, R, n + 1, mid + 1, e);
		seg[n >> 1] = seg[n] + seg[n + 1];
	}

}
int Sum(int L, int R, int n, int s, int e) {
	Lazy(n, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return seg[n];  // [s,e]in[L,R]

	int mid = (s + e) >> 1; n <<= 1;
	return Sum(L, R, n, s, mid) + Sum(L, R, n + 1, mid + 1, e);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, q, a, b;

	cin >> N >> M;
	while (M--) {
		cin >> q >> a >> b;
		if (q) cout << Sum(a, b, 1, 1, N) << "\n";
		else Upd(a, b, 1, 1, N);
	}
	return 0;
}