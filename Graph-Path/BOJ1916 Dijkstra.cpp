#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
bool operator<(pii A, pii B) {
	return A.second > B.second; //mean: B가 우선으로 나온다 = B.second가 작다
}

int dij[1001];
vector<pii> bus[1001];
priority_queue<pii> pq;

int main() {
	int N, M, A, B, s, e, c;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d", &s, &e, &c); bus[s].push_back({ e,c });
	}
	scanf("%d%d", &A, &B);

	for (int i = 1; i <= N; ++i) dij[i] = 1'0000'0001;
	dij[A] = 0, pq.push({ A,0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second; pq.pop();
		if (cost > dij[cur]) continue;

		for (pii nxt : bus[cur]) {
			int ncost = cost + nxt.second;
			if (ncost < dij[nxt.first]) dij[nxt.first] = ncost, pq.push({ nxt.first,ncost });
		}
	}
	printf("%d", dij[B]); return 0;
}