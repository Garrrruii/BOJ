#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> e[1000001];
queue<int> Q;
stack<int> S;
bool vis[1000001];
int dp[1000001][2];
//dp[cur][0]=sum(dp[nxt][1])
//dp[cur][1] = sum(min(dp[nxt][0], dp[nxt][1])) + 1

int main() {
	int N, u, v;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
	}

	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop(); S.push(cur);
		vis[cur] = true;

		for (int nxt : e[cur]) {
			if (vis[nxt]) continue;
			Q.push(nxt);
		}
	}
	while (!S.empty()) {
		int cur = S.top(); S.pop();

		dp[cur][0] = 0, dp[cur][1] = 1;
		for (int nxt : e[cur]) {
			dp[cur][0] += dp[nxt][1];
			dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
		}
	}
	printf("%d", min(dp[1][0], dp[1][1]));
	return 0;
}
/*
12
1 2 1 3 10 11 2 5 10 12
2 6 4 7 4 8 9 1 1 4 9 10
(4)
*/