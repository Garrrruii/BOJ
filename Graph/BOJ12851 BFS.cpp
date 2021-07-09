#include <cstdio>
#include <queue>
#define MAX 100'000
using namespace std;

queue<int> Q;
int dp[100001][2];
int main() {
	int N, K;
	scanf("%d%d", &N, &K);	//0<=N,K<=100'000
	
	for (int i = 0; i <= MAX; ++i) dp[i][0] = 987654321, dp[i][1] = 0;
	dp[N][0] = 0, dp[N][1] = 1; Q.push(N);

	int t = 0, qsize = 1;
	while (qsize && !dp[K][1]) {
		t++;
		while (qsize--) {
			int cur = Q.front(); Q.pop();
			int cnt = dp[cur][1];
			//printf("\ndp[%2d]= %d %d   ", cur, dp[cur][0], cnt);

			if (cur + 1 <= MAX && dp[cur + 1][0] >= t) {
				if (!dp[cur + 1][1]) Q.push(cur + 1);
				dp[cur + 1][0] = t, dp[cur + 1][1] += cnt; //printf("%2d ", cur + 1);
			}
			if (cur - 1 >= 0 && dp[cur - 1][0] >= t) {
				if (!dp[cur - 1][1]) Q.push(cur - 1);
				dp[cur - 1][0] = t, dp[cur - 1][1] += cnt; //printf("%2d ", cur - 1);
			}
			if ((cur << 1) <= MAX && dp[cur << 1][0] >= t) {
				if (!dp[cur << 1][1]) Q.push(cur << 1);
				dp[cur << 1][0] = t, dp[cur << 1][1] += cnt; //printf("%2d ", cur << 1);
			}
		}
		qsize = Q.size();
	}

	printf("%d\n%d", dp[K][0], dp[K][1]);
}
/*
8 48
48 24 12 6 7 8
10 30
30 15 14 13 12 10
12 100
12 24 25 50 100

*/