#include <cstdio>
using namespace std;

long long dp[1000001];
int main() {
	long long DIV = 1000000000;
	int N;
	scanf("%d", &N);
	dp[1] = 0, dp[2] = 1, dp[3] = 2;
	for (int i = 3; i < N; ++i) {
		dp[i + 1] = ((dp[i - 1] + dp[i]) * i) % DIV;
	}
	printf("%lld", dp[N]); return 0;
}