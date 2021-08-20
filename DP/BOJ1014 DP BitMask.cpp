#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10][1024];
int main() {
	int cnt[1024] = { 0, };
	for (int j = 0; j < 9; ++j) {
		for (int k = 3 << j; k < 1024; ++k)
			if (k & (1 << j) && k & (1 << (j + 1))) cnt[k] = -1;
	}
	for (int k = 1; k < 1024; ++k) {
		if (cnt[k] < 0) continue;
		for (int j = 0; j < 10; ++j) if (k & (1 << j)) cnt[k]++;
	}
	
	char tmp[11];
	int T, N, M;
	int b[10] = { 0, };
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i) {
			scanf("%s", &tmp);
			b[i] = 0;
			for (int j = 0; j < M; ++j) if (tmp[j] == 'x') b[i] |= (1 << j);
		}

		for (int k = 0; k < (1 << M); ++k) {
			if ((b[0] & k) || cnt[k] < 0) continue;
			dp[0][k] = cnt[k];
		}
		for (int i = 1; i < N; ++i) {
			for (int k = 0; k < (1 << M); ++k) {
				if ((b[i] & k) || cnt[k] < 0) continue;

				int upcnt = 0;
				for (int up = 0; up < (1 << M); ++up) {
					if (cnt[up | k] >= 0) upcnt = max(upcnt, dp[i - 1][up]);
				}
				dp[i][k] = cnt[k] + upcnt;
			}
		}
//		for (int k = 0; k < (1 << M); ++k) if (cnt[k] >= 0)  printf("%2d ", k);
//		printf("\n");
//		for (int i = 0; i < N; ++i) {
//			for (int k = 0; k < (1 << M); ++k) if (cnt[k] >= 0)  printf("%2d ", dp[i][k]);
//			printf("\n");
//		}

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int k = 0; k < (1 << M); ++k) ans = max(ans, dp[i][k]);
		}
		printf("%d\n", ans);

		//initialize
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < (1 << M); ++j) dp[i][j] = 0;
		}
	}
	return 0;
}
/*
6 6
....x.
..x...
.x....
..x...
......
x...x.'

x.x..x.
x....x.
.xx.x..
.xx.x..
.xx.x..
*/