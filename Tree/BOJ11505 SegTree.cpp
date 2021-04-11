#include <cstdio>
#include <algorithm>
#define P 1000'000'007
using namespace std;

long long seg[2097152];
int TWO;
long long get(int b, int c, int right, int n) {
	//printf("%2d %2d %2d %d\n", b, c, right, n);

	if (b == c) return seg[b + TWO - 1];
	if (c == right && c - b + 1 == (1 << n)) return seg[(c + TWO - 1) >> n];

	int mid = right - (1 << (n - 1));
	if (c <= mid) return get(b, c, mid, n - 1);
	else if (b > mid) return get(b, c, right, n - 1);
	else {
		long long A = get(b, mid, mid, n - 1);
		long long B = get(mid + 1, c, right, n - 1);
		return (A * B) % P;
	}
}
int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	int idx, n = 0;
	TWO = 1;
	while (N > TWO) TWO <<= 1, ++n;

	idx = TWO;
	while (N--) scanf("%lld", &seg[idx++]);
	for (; idx < (TWO << 1); ++idx) seg[idx] = 1;

	// Make SegTree
	idx = TWO;
	while (idx) {
		for (int i = idx; i < (idx << 1); i += 2) {
			seg[i >> 1] = (seg[i] * seg[i + 1]) % P;
		}
		idx >>= 1;
	}

	int a, b, c;
	while (M || K) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			M--; // Update Tree
			b += (TWO - 1); seg[b] = (long long)c;
			while (b > 1) {
				int j = (b & 1) ? b - 1 : b + 1;
				seg[b >> 1] = (seg[b] * seg[j]) % P; b >>= 1;
			}
		}
		else {
			K--; // Print ANS
			printf("%lld\n", get(b, c, TWO, n));
		}
	}
	return 0;
}
/* // Print Tree
	idx = 1;
	while (idx < 16) {
		for (int i = idx; i < (idx << 1); ++i) printf("%lld  ", seg[i]);
		printf("\n"); idx <<= 1;
	}
	printf("\n");
*/