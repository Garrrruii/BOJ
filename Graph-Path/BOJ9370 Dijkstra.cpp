#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int a, c;
};
bool operator<(node A, node B) {
	return A.c > B.c;
}
priority_queue<node> pq;

vector<node> E[2001];
int main() {
	int N, M, K, S, G, H;
	int a, b, c, x[100], dij[2001];

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d%d", &N, &M, &K, &S, &G, &H);

		for (int i = 1; i <= N; ++i) E[i].clear();
		for (int i = 1; i <= N; ++i) dij[i] = 2147483646;

		while (M--) {
			scanf("%d%d%d", &a, &b, &c); c <<= 1;
			if ((a == G && b == H) || (a == H && b == G)) c -= 1;
			E[a].push_back({ b,c });
			E[b].push_back({ a,c });
		}
		for (int i = 0; i < K; ++i) scanf("%d", &x[i]);
		sort(x, x + K);

		pq.push({ S,0 }); dij[S] = 0;
		while (!pq.empty()) {
			a = pq.top().a;
			c = pq.top().c; pq.pop();
			if (c < dij[a]) continue;

			for (node e : E[a]) {
				int nxt = e.a;
				int nc = c + e.c;
				if (nc < dij[nxt]) dij[nxt] = nc, pq.push({ nxt,nc });
			}
		}
		for (int i = 0; i < K; ++i) if (dij[x[i]] & 1) printf("%d ", x[i]);
		printf("\n");
	}
	return 0;
}
/*
input
2
6 10 5 1 2 5
1 2 2 1 4 9 1 5 8
2 3 3 2 4 6 2 5 3 2 6 8
3 4 2 4 5 2 5 6 1
2 3 4 5 6
6 10 5 1 2 5
1 2 2 1 4 9 1 5 8
2 3 3 2 4 6 2 5 3 2 6 8
3 4 2 4 5 2 5 6 6
2 3 4 5 6

output
4 5 6
4 5

*/