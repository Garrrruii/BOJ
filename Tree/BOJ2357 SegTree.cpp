#include <cstdio>
#include <algorithm>
#define INF 1000'000'001
using namespace std;

int segn[262145];
int segx[262145];
int x[100001], N, TWO;
pair<int, int> get(int a, int b, int right, int n) {
	//	printf("%2d %2d %2d %d\n", a, b, right, n);

	if (a == b) return { a,a };
	if (b == right && b - a + 1 == (1 << n)) {
		int idx = (a + TWO) >> n;
		return { segn[idx],segx[idx] };
	}

	int quad = 1 << (n - 2);
	int mid = right - (quad << 1);
	if (b <= mid) {
		int nmid = mid - quad;
		return get(a, b, mid, n - 1);
	}
	else if (a > mid) {
		return get(a, b, right, n - 1);
	}
	else {
		pair<int, int> p1 = get(a, mid, mid, n - 1);
		pair<int, int> p2 = get(mid + 1, b, right, n - 1);
		pair<int, int> R;
		R.first = (x[p1.first] < x[p2.first]) ? p1.first : p2.first;
		R.second = (x[p1.second] > x[p2.second]) ? p1.second : p2.second;
		return R;
	}
}
int main() {
	for (int i = 0; i < 166999; ++i) segn[i] = 0;
	for (int i = 0; i < 166999; ++i) segx[i] = 0;

	int M, a, b;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d", &x[i]);

	// Make SegTree
	TWO = 1;
	int idx, n = 0;
	while (N > TWO) TWO <<= 1, ++n;
	idx = TWO;
	for (int i = 1; i <= N; ++i, ++idx) segn[idx] = segx[idx] = i;

	x[0] = INF; idx = TWO;
	while (idx) {
		for (int i = idx; i < (idx << 1); i += 2)
			segn[i >> 1] = (x[segn[i]] < x[segn[i + 1]]) ? segn[i] : segn[i + 1];
		idx >>= 1;
	}
	x[0] = 0; idx = TWO;
	while (idx) {
		for (int i = idx; i < (idx << 1); i += 2)
			segx[i >> 1] = (x[segx[i]] > x[segx[i + 1]]) ? segx[i] : segx[i + 1];
		idx >>= 1;
	}

	// Get ANS
	while (M--) {
		scanf("%d%d", &a, &b);
		pair<int, int> ANS = get(a, b, TWO, n);
		printf("%d %d\n", x[ANS.first], x[ANS.second]);
	}
	return 0;
}
/*
12 5
75 30 100 38 50 51 52 20 81 5 6 91
1 10
3 5
6 9
8 10
2 11

//PRINT TREE
idx = 1;
while (idx < 16) {
	for(int i=idx;i<(idx<<1);++i) printf("%d,%d  ", segn[i],segx[i]);
	printf("\n");
	idx <<= 1;
}
*/