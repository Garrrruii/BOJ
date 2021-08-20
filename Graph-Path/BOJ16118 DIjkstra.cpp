#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, long long> pil;
struct pqsort {
	bool operator()(pil A, pil B) {
		return A.second > B.second;
	}
};
priority_queue<pil, vector<pil>, pqsort> pq;
vector<pil> E[4000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, a, b;
	long long c, dij[4000][3];

	cin >> N >> M;
	while (M--) {
		cin >> a >> b >> c; a--, b--, c <<= 1;
		E[a].push_back({ b,c }), E[b].push_back({ a,c });
	}

	dij[0][0] = dij[0][1] = 0; dij[0][2] = 999888777666;
	for (int i = 1; i < N; ++i) dij[i][0] = dij[i][1] = dij[i][2] = 999888777666;
	
	pq.push({ 0,0 });
	while (!pq.empty()) {
		a = pq.top().first;
		c = pq.top().second; pq.pop();
		if (c > dij[a][0]) continue;

		for (pil e : E[a]) {
			b = e.first;
			long long nc = c + e.second;
			if (nc < dij[b][0]) dij[b][0] = nc, pq.push({ b,nc });
		}
	}
	pq.push({ 0,0 });
	while (!pq.empty()) {
		a = pq.top().first;
		c = pq.top().second; pq.pop();

		if (c >= 0) {		//dij[1]: 1/2배 속도로 도착
			if (c > dij[a][1]) continue;

			for (pil e : E[a]) {
				b = e.first;
				long long nc = c + (e.second >> 1);
				if (nc < dij[b][2]) dij[b][2] = nc, pq.push({ b,-nc });
			}
		}
		else {				//dij[2]: 2배 속도로 도착
			if (-c > dij[a][2]) continue;

			for (pil e : E[a]) {
				b = e.first;
				long long nc = -c + (e.second << 1);
				if (nc < dij[b][1]) dij[b][1] = nc, pq.push({ b,nc });
			}
		}
	}
//	for (int i = 0; i < N; ++i) printf("%lld ", dij[i][0]); printf("\n");
//	for (int i = 0; i < N; ++i) printf("%lld ", dij[i][1]); printf("\n");
//	for (int i = 0; i < N; ++i) printf("%lld ", dij[i][2]); printf("\n");
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		if (dij[i][0] < dij[i][1] && dij[i][0] < dij[i][2]) ans++;
	}
	cout << ans; return 0;
}