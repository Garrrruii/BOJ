#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
//dijkstra,,,도 아니고 그냥 BFS
//think a hypertube as a vertex
//add edge if intersect(hypertubes) exist

vector<int> in[100001];
bool adj[1000][1000];
bool vis[1000];
bool dest[1000];
queue<pair<int, int>> Q;	//dist, tubenum

int main() {
	int N, K, M, tmp;
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j) scanf("%d", &tmp), in[tmp].push_back(i);
	}
	if (N == 1) { printf("1"); return 0; }

	for (int n = 1; n <= N; ++n) {
		for (int i = 1; i < in[n].size(); ++i) {
			for (int j = 0; j < i; ++j) {
				adj[in[n][i]][in[n][j]] = adj[in[n][j]][in[n][i]] = true;
			}
		}
	}
	for (int tube : in[N]) dest[tube] = true;
	for (int tube : in[1]) vis[tube]=true, Q.push({ 2,tube });
	int ANS = 987654321;
	while (!Q.empty()) {
		int dist = Q.front().first;
		int cur = Q.front().second; Q.pop();
		//printf("cur=%d, dist=%d\n", cur, dist);

		if (dest[cur]) { ANS = dist; break; }
		
		dist++;
		for (int nex = 0; nex < M; ++nex) {
			if (!adj[cur][nex] || vis[nex]) continue;
			vis[nex] = dist; Q.push({ dist, nex });
		}
	}
	if (ANS > 987654320) printf("-1");
	else printf("%d", ANS);
	return 0;
}