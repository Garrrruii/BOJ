//going down
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, a, b, c;
	int dp[6] = { 0, }, tmp[6] = { 0, };
	scanf("%d", &N);
	while (N--) {
		for (int k = 0; k < 6; ++k) tmp[k] = dp[k];
		scanf("%d%d%d", &a, &b, &c);

		dp[0] = a + min(tmp[0], tmp[1]);
		dp[1] = b + min(tmp[0], min(tmp[1], tmp[2]));
		dp[2] = c + min(tmp[1], tmp[2]);
		dp[3] = a + max(tmp[3], tmp[4]);
		dp[4] = b + max(tmp[3], max(tmp[4], tmp[5]));
		dp[5] = c + max(tmp[4], tmp[5]);
	}
	printf("%d %d", max(dp[3], max(dp[4], dp[5])), min(dp[0], min(dp[1], dp[2])));
	return 0;
}