#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 1000001
using namespace std;

struct road{
	int v, c;
};
vector<road> R[100001];
struct parent {
	int v, mn = INF, mx = 0;
};
parent P[100001][18];
int dep[100001];
queue<int> Q;

void GetP() {
	Q.push(1), dep[1] = 1;
	while (!Q.empty()) {
		int prv = Q.front(); Q.pop();

		for (road r : R[prv]) {
			if (dep[r.v]) continue;
			int cur = r.v; Q.push(cur);

			dep[cur] = dep[prv] + 1;
			P[cur][0] = { prv, r.c, r.c };
			for (int k = 0; k < 17; ++k) {
				if (!P[P[cur][k].v][k].v) break;

				P[cur][k + 1].v = P[P[cur][k].v][k].v;
				P[cur][k + 1].mn = min(P[cur][k].mn, P[P[cur][k].v][k].mn);
				P[cur][k + 1].mx = max(P[cur][k].mx, P[P[cur][k].v][k].mx);
			}
		}
	}
}
int main() {
	int N, K, a, b, c, d, e;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		R[a].push_back({ b,c }); R[b].push_back({ a,c });
	}

	GetP();
	/*for (int i = 2; i <= N; ++i) printf("   %2d  |", i);
	printf("\n");
	for (int k = 0; k < 3; ++k) {
		for (int i = 2; i <= N; ++i) printf(" %d %3d |", par[i][k].v, (par[i][k].mn == INF) ? 0 : par[i][k].mn);
		printf("\n");
		for (int i = 2; i <= N; ++i) printf("   %3d |", par[i][k].mx);
		printf("\n");
	}*/

	// Get ANS
	scanf("%d", &K);
	while (K--) {
		scanf("%d%d", &d, &e);

		int minn = INF;
		int maxx = 0;
		if (dep[d] > dep[e]) swap(d, e);
		for (int k = 17; k >= 0; --k) {
			if (dep[e] - dep[d] >= (1 << k)) {
				minn = min(minn, P[e][k].mn);
				maxx = max(maxx, P[e][k].mx);
				e = P[e][k].v;
			}
		}
		if (d != e) {
			for (int k = 17; k >= 0; --k) {
				if (P[d][k].v == P[e][k].v) continue;
				minn = min(minn, min(P[d][k].mn, P[e][k].mn));
				maxx = max(maxx, max(P[d][k].mx, P[e][k].mx));
				d = P[d][k].v, e = P[e][k].v;
			}
			minn = min(minn, min(P[d][0].mn, P[e][0].mn));
			maxx = max(maxx, max(P[d][0].mx, P[e][0].mx));
		}
		printf("%d %d\n", minn, maxx);
	}
	return 0;
}
/*
12
1 5 20 1 3 10 3 2 100 3 4 200 2 12 60
5 6 40 6 7 50 6 8 70 8 9 200 8 11 110 9 10 120
10
10 6
11 3
*/