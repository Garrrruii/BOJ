//Elevator
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

pair<int, int> E[101];
vector<int> f[100001];
pair<int, int> dp[100001][101];

stack<pair<int, int>> S;
queue<int> Q;
int main() {
	int N, M, x, y, A, B, cnt = 0;

	// Get Input
	scanf("%d%d", &N, &M);
	for (int m = 1; m <= M; ++m) {
		scanf("%d%d", &x, &y);
		E[m] = { x,y };
		while (x <= N) f[x].push_back(m), x += y;
	}
	scanf("%d%d", &A, &B);
	if (f[A].empty() || f[B].empty()) { printf("-1"); return 0; }

	// Initiate
	for (int e : f[A]) dp[A][e] = { 1,0 };
	Q.push(A);

	// BFS and Get Ans
	bool arrived_at_B = false;
	while (!Q.empty()) {
		arrived_at_B = false;

		int curf = Q.front(); Q.pop();
		for (int cure : f[curf]) {
			cnt = dp[curf][cure].first;

			//cure로 갈 수 있는 층 nxtf
			int k = E[cure].second;
			for (int nxtf = E[cure].first; nxtf <= N; nxtf += k) {
				if (nxtf == curf || dp[nxtf][cure].first) continue;

				dp[nxtf][cure] = { cnt,curf };
				if (nxtf == B) {
					S.push({ B,cure }); arrived_at_B = true; break;
				}
				Q.push(nxtf);

				//nxtf에서 갈아탄 nxte
				for (int nxte : f[nxtf]) {
					if (nxtf == curf || dp[nxtf][nxte].first) continue;

					dp[nxtf][nxte] = { cnt + 1, curf };
				}
			}
			if (arrived_at_B) break;
		}
		if (arrived_at_B) break;
	}
	if (arrived_at_B) printf("%d\n", cnt);
	else { printf("-1"); return 0; }

	// Track Path
	cnt--;
	while (cnt) {
		int cur = S.top().first;
		int curelv = S.top().second;

		int prv = dp[cur][curelv].second;
		for (int elv : f[prv]) {
			if (elv == curelv) continue;

			if (dp[prv][elv].first == cnt) S.push({ prv,elv });
		}
		cnt--;
	}
	while (!S.empty()) printf("%d\n", S.top().second), S.pop();
	return 0;
}
/*
12 6
4 3 7 5 4 4 2 3 10 1 6 2
7 11
(2 1 5)

Initiate BFS: Q<-( 7,1)( 7,2)
( 7,1)-( 4,1) Q<-( 4,3)
	  -(10,1) Q<-(10,5)(10,6)
( 7,2)-(12,2) Q<-(12,3)(12,5)
( 4,3)-( 8,3) Q<-( 8,4)( 8,6)
	  -(12,3) Q<-(12,5)
(10,5)-(11,5) ANSWER

12 3
1 2 2 2 2 4
5 6
(-1)
*/