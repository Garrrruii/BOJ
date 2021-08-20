//Picture Exchange
#include <cstdio>
#include <queue>
using namespace std;
//1. Sell picture on price more or same than when you buy
//2. Cannot buy same picture again
//Max num of people who owned the picture?

// DFS => time
/*
int vis[15];
void dfs(int cur, int cnt, int cost) {
//		 owner, count, current cost
	for (int i = 0; i < cnt; ++i) printf(" ");
	printf("%d(cnt=%d, cost=%d)\n", cur,cnt,cost);

	bool ava = false;
	vis[cur] = true; cnt++;
	for (int nex = 1; nex < N; ++nex) {
		if (vis[nex] || p[cur][nex] < cost) continue;
		dfs(nex, cnt, p[cur][nex]);
		ava = true;
	}
	vis[cur] = false; cnt--;
	if (!ava && ANS < cnt) ANS = cnt;
} */

//DP+bitmasking
int N, ANS = 2;
int p[15][15];
int dp[15][32768]; //2^0 ~ 2^15
int finddp(int cur, int state) {
	if (dp[cur][state] >= 0) return dp[cur][state];
	if (dp[cur][state] == 10) return 10;

	int prvstate = state & (~(1 << cur));
	int curcost = 10;
	for (int prv = 1; prv < N; ++prv) {
		//아직 소유하지 않은 사람
		if (prv==cur || !(state & (1 << prv))) continue;

		//이전 금액이 더 비쌈
		int prvcost = finddp(prv, prvstate);
		int tmpcost = p[prv][cur];
		if (prvcost > tmpcost) continue;

		//cur이 가장 싸게 사는 가격
		if (curcost > tmpcost) curcost = tmpcost;
	}
	dp[cur][state] = curcost;
	
	if (curcost < 10) {
		int cnt = 0;
		for (int i = 0; i < N; ++i) cnt += ((state & (1 << i)) ? 1 : 0);
		if (ANS < cnt) ANS = cnt;
	}
	return curcost;
}
int main() {
	// Get input
	char tmp[16];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &tmp);
		for (int j = 0; j < N; ++j) {
			p[i][j] = (int)(tmp[j] - '0');
		}
	}

	// Initiate
	int fin = 0;
	for (int i = 0; i < N; ++i) {
		fin |= (1 << i);
		for (int j = 0; j < 32768; ++j) dp[i][j] = -1;
	}
	dp[0][1] = 0;
	for (int nxt = 1; nxt < N; ++nxt) dp[nxt][1 | (1 << nxt)] = p[0][nxt];

	// Get Answer
	for (int nxt = 1; nxt < N; ++nxt) finddp(nxt, fin);
	printf("%d", ANS); return 0;
}
/*
5
03112
10221
13051
12204
11430

print for debug
	printf("   ");
	for (int j = 2; j < fin; ++j) printf("%2d ", j);
	printf("\n");
	for (int i = 0; i < N; ++i) {
		printf("%d: ", i);
		for (int j = 2; j < fin; ++j) {
			if (dp[i][j] < 0) printf("   ");
			else printf("%2d ", dp[i][j]);
		}
		printf("\n");
	}
*/