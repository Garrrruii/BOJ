#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int v;
	long long c;
};
bool operator<(node A, node B) {
	return A.c > B.c;
}
priority_queue<node> pq;

vector<node> E[1001];
pair<long long, int> dij[1001];
vector<int> ans;

int main() {
	int N, M, A, B, a, b;
	long long c;

	scanf("%d%d", &N, &M);
	for (a = 1; a <= N; ++a) dij[a].first = 98765432100;
	while (M--) {
		scanf("%d%d%lld", &a, &b, &c);
		E[a].push_back({ b,c });
	}
	scanf("%d%d", &A, &B);

	dij[A].first = 0;
	pq.push({ A,0 });
	while(!pq.empty()) {
		int cur = pq.top().v;
		c = pq.top().c; pq.pop();
		if (dij[cur].first < c) continue;
		if (cur == B) break;
		
		for (node e : E[cur]) {
			int nxt = e.v;
			long long nc = c + e.c;
			if (dij[nxt].first <= nc) continue;
			dij[nxt] = { nc,cur }; pq.push({ nxt,nc });
		}
	}

	b = B; ans.push_back(B);
	while (b != A) {
		b = dij[b].second; ans.push_back(b);
	}
	printf("%lld\n", dij[B].first);
	printf("%d\n", ans.size());
	for (a = ans.size() - 1; a >= 0; --a) printf("%d ", ans[a]);
	return 0;
}