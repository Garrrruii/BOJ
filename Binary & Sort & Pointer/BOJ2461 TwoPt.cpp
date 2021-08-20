#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int a[1000][1000];
struct sortpq {
	bool operator()(pii A, pii B) {
		return A.first > B.first;
	}
};
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &a[i][j]);
		sort(a[i], a[i] + M);
	}
	
	priority_queue < pii, vector<pii>, sortpq> pq;
	int MAX = 0, ANS = 9876543210;
	int idx[1000] = { 0, };
	for (int i = 0; i < N; ++i) pq.push({ a[i][0],i }), MAX = max(MAX, a[i][0]);
	
	int n, m;
	while (1) {
		//printf("min=%2d of %d, MAX-min=%d\n", pq.top().first, pq.top().second, MAX - pq.top().first);
		ANS = min(ANS, MAX - pq.top().first);
		n = pq.top().second; pq.pop();
		m = ++idx[n];
		if (m >= M) break;

		pq.push({ a[n][m],n }), MAX = max(MAX, a[n][m]);
	}
	printf("%d", ANS); return 0;
}
/*
(2) 3 4
12 16 67 43  7 17 68 48  14 15 77 54

(3) 3 4
12 15 16 67  7 17 68 77  14 43 54 48

(example)
12 15 16 67  12    15    16 67
 7 17 68 77   7 17             68
14 43 48 54  14       43          48 54
			  7  5  3 28 27 50 25 20 14
*/