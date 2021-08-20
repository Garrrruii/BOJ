//halloween cemetry
#include <cstdio>
#include <vector>
#define INF 98765432100
using namespace std;

typedef pair<int, long long> pil;

bool grave[900];
long long cost[900];
vector<pil> e[900];

int main() {
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	
	int W, H, G, E, x1, y1, x2, y2;
	long long t;
	
	while (1) {
		scanf("%d%d", &W, &H);
		if (!W) return 0;

		// Initialize
		for (int i = 0; i < H * W; ++i) grave[i] = false, cost[i] = INF, e[i].clear();
		cost[0] = 0;

		// Get Input
		scanf("%d", &G);
		while (G--) scanf("%d%d", &x1, &y1), grave[y1 * W + x1] = true;
		scanf("%d", &E);
		while (E--) {
			scanf("%d%d%d%d%lld", &x1, &y1, &x2, &y2, &t);
			e[y1 * W + x1].push_back({ y2 * W + x2,t });
		}
		
		// Add Edges
		for (int y = 0, from=0; y < H; ++y) {
			for (int x = 0; x < W; ++x, ++from) {
				if (grave[from] || e[from].size()) continue;

				for (int d = 0; d < 4; d++) {
					int ny = y + dy[d], nx = x + dx[d];
					if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
					if (grave[ny * W + nx]) continue;

					e[from].push_back({ ny * W + nx, 1 });
				}
			}
		}
		e[H * W - 1].clear();
		
		// Bellman-Ford
		for (int n = 1; n < H * W; ++n) {		//Repeat H*W-times
			for (int i = 0; i < H * W; ++i) {	//vertices(0 ~ H*W-1)
				if (cost[i] == INF) continue;	//unreachable

				for (pil edge : e[i]) {
					int nxt = edge.first;
					long long newcost = cost[i] + edge.second;
					if (newcost < cost[nxt]) cost[nxt] = newcost;
				}
			}
		}

		// Find minus cycle(=never)
		bool never = false;
		for (int i = 0; i < H * W; ++i) {
			if (cost[i] == INF) continue;

			for (int j = 0; j < e[i].size(); ++j) {
				if (cost[i] + e[i][j].second < cost[e[i][j].first]) {
					never = true; break;
				}
			}
			if (never) break;
		}

		// Print
		if (never) printf("Never\n"); 
		else if (cost[H * W - 1] == INF) printf("Impossible\n");
		else printf("%lld\n", cost[H * W - 1]);
	}
}
/*
5 5  11
0 1 0 2 0 3 1 1 1 2 1 3 2 1 2 2 2 3 3 1 3 2
1  0 4 1 0 -11
0 0
(8)

5 5  11
0 1 0 2 0 3 1 1 1 2 1 3 2 1 2 2 2 3 3 1 3 2
1  0 4 1 0 -13
0 0
(Never)


CHECK EDGES
for (int i = 0; i < H * W; ++i) {
			printf("i:%d ", i);
			for (int j = 0; j < e[i].size(); ++j)printf("%d(%d) ", e[i][j].first, e[i][j].second);
			printf("\n");
		}

CHECK COSTS
for (int i = 0; i < H * W; ++i) printf("%d ", cost[i]);
printf("\n");

*/
