#include <cstdio>
#include <queue>
using namespace std;

struct edge {
	int v, c;	 //vertex cost
};
vector<edge> E[10001];
vector<int> from[10001];
int maxcost[10001];
int ind[10001];
queue<int> Q;

int main() {
	int N, M, D, A, d, a, c;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &d, &a, &c);
		E[d].push_back({ a,c }); ind[a]++;
	}
	scanf("%d%d", &D, &A);

	// Get MaxCost & Departure Vertex
	Q.push(D);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		for (edge e : E[cur]) {
			int cost = maxcost[cur] + e.c;
			if (cost > maxcost[e.v]) maxcost[e.v] = cost, from[e.v].clear();
			if (cost == maxcost[e.v]) from[e.v].push_back(cur);

			ind[e.v]--;
			if (!ind[e.v]) Q.push(e.v);
		}
	}
	/*for (int i = 1; i <= N; ++i) {
		printf("%d: %2d, ", i, maxcost[i]);
		for (int v : from[i]) printf("%d ", v);
		printf("\n");
	}*/

	// Count Edges
	int CNT = 0;
	Q.push(A), ind[A] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		for (int v : from[cur]) {
			CNT++;
			if (!ind[v]) Q.push(v), ind[v] = 1;
			// count하는 위치
			// ind[v]=1(vis) 사용 주의
		}
	}
	printf("%d\n%d", maxcost[A], CNT); return 0;
}
/*
8 12
1 2 4 1 4 3 1 3 2 3 5 4
2 6 3 2 7 5 4 5 2 4 6 4
5 6 2 5 8 1 6 7 5 8 7 8
1 7
(15 4)
*/