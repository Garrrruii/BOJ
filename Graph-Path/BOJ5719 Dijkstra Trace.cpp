//almost shortest path
//최단 경로에 포함되지 않는 도로로 이뤄진 최단 경로
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<>> P;	//dist, vertex
vector<pii> e[500];
vector<int> trace[500];
int dij[500];

void dijkstra(int S, bool tracing) {
	int cur, cost, nxt, newcost;
	P.push({ 0,S }); dij[S] = 0;
	while (!P.empty()) {
		cost = P.top().first;
		cur = P.top().second; P.pop();

		if (cost > dij[cur]) continue;

		for (pii nxt : e[cur]) {
			if (!nxt.first) continue;

			newcost = cost + nxt.first;

			if (newcost < dij[nxt.second]) {
				if (tracing) trace[nxt.second].clear(), trace[nxt.second].push_back(cur);
				dij[nxt.second] = newcost; P.push({ newcost,nxt.second });
			}
			else if (tracing && newcost == dij[nxt.second]) trace[nxt.second].push_back(cur);
		}
	}
}
int main() {
	int N, M, S, D, u, v, p;
	while (1) {
		scanf("%d%d", &N, &M);
		if (!N) return 0;

		for (int i = 0; i < N; ++i) e[i].clear(), trace[i].clear();

		scanf("%d%d", &S, &D);
		while (M--) scanf("%d%d%d", &u, &v, &p), e[u].push_back({ p,v });

		// First Dijkstra, trace the minimal path
		for (int i = 0; i < N; ++i) dij[i] = 987654321;
		dijkstra(S, true);

		// Erase edges in the minimal path
		bool vis[500] = { false, };
		queue<int> Q; Q.push(D); vis[D] = true;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();

			for (int pre : trace[cur]) {
				for (int i = 0; i < e[pre].size(); ++i)
					if (e[pre][i].second == cur) e[pre][i].first = 0;

				if (!vis[pre]) Q.push(pre), vis[pre] = true;
			}
		}

		// Second Dijkstra, just find cost of the minimal path
		for (int i = 0; i < N; ++i) dij[i] = 987654321;
		dijkstra(S, false);

		if (dij[D] > 987654320) printf("-1\n");
		else printf("%d\n", dij[D]);
	}
}