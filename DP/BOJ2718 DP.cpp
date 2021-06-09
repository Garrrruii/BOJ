#include <cstdio>
using namespace std;

int dp[25];
int main() {
	int T, N;
	dp[0] = dp[1] = 1, dp[2] = 5;
	for (int n = 3; n < 25; ++n) {
		for (int i = n; i > 2; --i) dp[n] += dp[n - i] * ((i & 1) ? 2 : 3);
		dp[n] += dp[n - 2] * 4 + dp[n - 1];
//		printf("%d  ", dp[n]);
//		if (!(n % 10)) printf("\n");
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N); printf("%d\n", dp[N]);
	}
	return 0;
}
/*
Bn: 1 4 2 3 2 3 2 3.... 분리할 수 없는
An: 총 경우의 수

A5 = B5*A0 + B4*A1 + B3*A2 + B2*A3 + B1+A4
      2       3       2       4       1
A6 = B6*A0 + B5*A1 + B4*A2 + B3*A3 + B2*A4 + B1+A5
      3       2       3       2       4       1
*/