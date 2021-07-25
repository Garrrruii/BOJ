#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
// M원 이하로 사용하며 가장 빠른 길
// N 2~100
// M 0~10000
// K 0~10000
struct info {
	int v, c, d;
};
vector<info> adj[101];
int dp[101][10001];		//dp[위치][남은 돈]

struct sorting {
	bool operator()(info& A, info& B) {
		if (A.d == B.d) return A.c < B.c;	//돈 많이 남은 순
		return A.d > B.d;					//거리 가까운 순
	}
};
priority_queue<info, vector<info>, sorting> PQ;
int main() {
	int u, v, c, d;
	int T, N, M, K;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K); 
		for (int i = 1; i <= N; ++i) adj[i].clear();
		for (int j = 0; j <= M; ++j) dp[1][j] = 0;
		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j <= M; ++j) dp[i][j] = INF;
		}
		while (!PQ.empty()) PQ.pop();

		for (int i = 0; i < K; ++i) {
			scanf("%d%d%d%d", &u, &v, &c, &d);
			adj[u].push_back({ v,c,d });	//u->v, cost c, dist d
		}

		int ANS = INF;
		PQ.push({ 1,M,0 });
		while (!PQ.empty()) {
			int cur = PQ.top().v;
			int cost = PQ.top().c;
			int dist = PQ.top().d; PQ.pop();
			if (dist > ANS) break;

			if (cur == N) {
				if (ANS > dist) ANS = dist;
				continue;
			}
			if (dist > dp[cur][cost]) continue;

			for (info e : adj[cur]) {
				int nxt = e.v;
				int nxtcost = cost - e.c;		//남은 돈 X
				if (nxtcost < 0) continue;
				int nxtdist = dist + e.d;		//먼 길 굳이X
				if (nxtdist >= ANS) continue;
				if (nxtdist >= dp[nxt][nxtcost]) continue;

				// Optimization
				// nxt로 도착하는 경로 중 현재 구한 경로보다
				// 돈이 더 드는데 경로가 더 오래 걸린다? 
				// => 현재 구한 경로값으로 바꿔준다
				for (int c = nxtcost - 1; c >= 0; --c) {
					if (dp[nxt][c] <= nxtdist) break;
					dp[nxt][c] = nxtdist;
				}

				dp[nxt][nxtcost] = nxtdist;
				PQ.push({ nxt,nxtcost,nxtdist });
			}
		}
		if (ANS < INF) printf("%d\n", ANS);
		else printf("Poor KCM\n");
	}
	return 0;
}
/*
2
6 15 10
1 2 2 1 2 4 1 1
1 3 5 1 3 2 1 2
4 3 1 2 3 5 6 2
2 6 8 13 5 6 5 3
5 4 1 5 4 6 8 6
5 5 4
1 2 2 1
2 3 2 1
3 5 2 1
1 3 1 5

(8 6)
*/