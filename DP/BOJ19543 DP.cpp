#include <cstdio>
#include <queue>
using namespace std;

char idxs[200001];
char row[26][200001];
int main() {
	int N, M, K, idx;
	long long ANS = 0;
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 0; i < K; ++i) scanf("%s", row[i]);
	scanf("%s", &idxs);

	Q.push({ N - 1,M - 1 });
	int ANS = 1;
	

	printf("%lld", ANS);
	return 0;
}
// 무어 ㅑ시발?????????????? 존나 모르겠네
/* dp이지만 시간초과
	for (int j = 0; j < M; ++j) dp[j] = 1;
	for (int i = 0; i < N-1; ++i) {
		idx = idxs[i] - 'A';

		for (int j = 0; j < M; ++j) {
			if (row[idx][j] == 'R') dp[j + 1] += dp[j], dp[j] = 1;
			else dp[j]++;
		}
	}
	idx = idxs[N - 1] - 'A';
	for (int j = 0; j < M; ++j) {
		if (row[idx][j] == 'R') dp[j + 1] += dp[j];
	}
	ANS=dp[M-1];
	*/