//feel like upgraded ver of BOJ2535
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001][3];
int num[10001];
vector<int> e[10001];

void dfs(int cur) {
	// Get dp[cur]
	dp[cur][0] += num[cur];
	int diff = 987654;
	bool no_child_selected = true;

	for (int nxt : e[cur]) {
		if (dp[nxt][0]) continue;	//parent
		dfs(nxt);					//child

		// Select cur
		dp[cur][0] += max(dp[nxt][1],dp[nxt][2]);
		// Else
		if (dp[nxt][0] < dp[nxt][1]) {
			dp[cur][1] += dp[nxt][1];
			diff = min(diff, dp[nxt][1] - dp[nxt][0]);
		}
		else {
			dp[cur][1] += dp[nxt][0];
			no_child_selected = false;
		}
		if (dp[nxt][1] && dp[cur][2] >= 0) dp[cur][2] += dp[nxt][1];
		else dp[cur][2] = -1;
	}
	if (no_child_selected && diff < 987654) dp[cur][1] -= diff;
}
int main() {
	int N, a, b;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &num[i]);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b), e[b].push_back(a);
	}
	
	dfs(1); 
	/*for (int j = 0; j < 3; ++j) {
		for (int i = 1; i <= N; ++i) printf("%3d ", dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n", max(dp[1][0], dp[1][1])); return 0;
}
/*
7 1 3 4 1 2 2 7
1 2 2 3 4 3 4 5 6 2 6 7
(14)

14 10 6 1 4 1 9 6 7 1 3 12 5 6 6 
1 2 1 3 2 4 2 5 4 8 5 9 5 10 14 9
6 3 7 3 7 11 12 11 13 11
(52)

6 9 1 2 1 5 9
1 2 2 3 3 4 4 5 3 6
(23)
*/