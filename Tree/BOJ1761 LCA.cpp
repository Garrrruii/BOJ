#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
// N<=40000  M<=10000

int dep[40001];					  //depth of vertex
vector<pair<int,int>> adj[40001]; //vertex, distance
pair<int,int> par[40001][17];	  //par[i][k]: 2^k-th parent of i, distance

int main() {
	int N, M, a, b, c;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c }); adj[b].push_back({ a,c });
	}

	// Make Tree.
	// Let 1 be Root.
	queue<int> Q; Q.push(1); dep[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int nex_dep = dep[cur] + 1;

		for (int i = 0; i < adj[cur].size(); ++i) {
			int nex = adj[cur][i].first;
			if (dep[nex]) continue;
			Q.push(nex);
			dep[nex] = nex_dep;
			par[nex][0] = { cur,adj[cur][i].second };
		}
	}

	// Memo parents of each vertices
	for (int k = 1; k < 17; ++k) {
		for (int i = 2; i <= N; ++i) {
			pair<int, int> aa = par[i][k - 1];
			pair<int, int> bb = par[aa.first][k - 1];
			if (bb.first) par[i][k] = { bb.first, aa.second + bb.second };
		}
	}

	scanf("%d", &M);
	while (M--) {
		scanf("%d%d", &a, &b);
		if (dep[a] > dep[b]) { c = a; a = b; b = c; }

		int dist = 0;
		for (int k = 16; k >= 0; --k) {
			if (dep[b] - dep[a] >= (1 << k)) {
				dist += par[b][k].second;
				b = par[b][k].first;
//				printf("a=%d, b=%d, dist=%d\n", a, b, dist);
			}
		}
		if (a == b) printf("%d\n", dist);
		else {
			for (int k = 16; k >= 0; --k) {
				if (par[a][k].first != par[b][k].first) {
					dist += (par[a][k].second + par[b][k].second);
					a = par[a][k].first;
					b = par[b][k].first;
//					printf("a=%d, b=%d, dist=%d\n", a, b, dist);
				}
			}
			dist += (par[a][0].second + par[b][0].second);
			printf("%d\n", dist);
		}
	}
    return 0;
}
/*
13
1 2 10 2 3 2 6 2 1 6 7 3 3 9 4 1 5 30 11 5 5
4 1 20 12 4 40 10 4 10 10 8 10 8 13 10
5  1 8  12 13  9 7  3 13  7 5
(40 70 10 62 44)

4
2 1 2 2 3 3 4 2 1
1  2 4
(1)

15
1 2 1 1 3 1 2 4 1 3 7 1 6 2 1 12 5 1 14 7 1
3 8 1 4 9 1 2 5 1 5 11 1 7 13 1 10 4 1 11 15 1
6  6 11  10 9  2 6  7 6  8 13  8 15
(3 2 1 4 3 6)
*/
