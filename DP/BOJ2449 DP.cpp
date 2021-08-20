//Light Bulb
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[201][201], b[201];
int count(int A, int B) {
	if (dp[A][B] < 0) {
		int ANS = 5000;
		for (int i = A; i < B; i++) {
			ANS = min(ANS, count(A, i) + count(i + 1, B) + ((b[A] != b[i + 1]) ? 1 : 0));
			//i까지 A로 바꿈, B까지 i+1로 바꿈, A와 i+1이 같은가?
		}
		dp[A][B] = ANS;
	}
	return dp[A][B];
}
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", &b[i]);

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; ++i) dp[i][i] = 0;
	printf("%d", count(1, N));
	return 0;
}