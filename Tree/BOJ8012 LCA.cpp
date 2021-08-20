#include <cstdio>
#include <queue>
using namespace std;


int par[30001][15];		//par[x][n] x의 2^n번째 부모
vector<int> e[30001];

int main() {
	int N, a, b;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b), e[b].push_back(a);
	}

	// BFS
	queue<int> Q;
	bool vis[30001] = { false, };
	int dep[30001] = { 0, };

	Q.push(1); vis[1] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int d = dep[cur] + 1;

		for (int nxt : e[cur]) {
			if (vis[nxt]) continue;

			par[nxt][0] = cur;
			for (int k = 1;; ++k) {
				par[nxt][k] = par[par[nxt][k - 1]][k - 1];
				if (!par[nxt][k]) break;
			}
			Q.push(nxt); vis[nxt] = true; dep[nxt] = d;
		}
	}

	int M, A, B, K, k, dist, ANS = 0;
	scanf("%d", &M); M--;
	scanf("%d", &B);
	while (M--) {
		scanf("%d", &A); // B -> A

		// Get Dist AB
		if (dep[A] > dep[B]) a = B, b = A;
		else a = A, b = B;

		K = dist = dep[b] - dep[a];
		
		// 1. Make Depth Same
		while (K) {
			k = 14;
			while ((1 << k) > K) k--;
			b = par[b][k]; K -= (1 << k);
		}

		// 2. Find LCA
		while (a != b) {
			k = 14;
			while (k && (par[a][k] == par[b][k])) k--;
			a = par[a][k], b = par[b][k];
			dist += (1 << (k + 1));
		}

		ANS += dist; B = A;
	}
	printf("%d", ANS); return 0;
}
/*
13
1 2 1 3 2 4 2 5 4 7 4 8 3 6
6 9 6 10 10 11 10 12 11 13
8
1 6 8 4 12 13 3 2
2+5+1+6+3+4+2 = 23
*/