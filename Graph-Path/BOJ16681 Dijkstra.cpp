#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, long long> pil;

struct pqsort {
	bool operator()(pil A, pil B) {
		return A.second > B.second;
	}
};
priority_queue<pil, vector<pil>, pqsort> pq;
vector<pil> e[100000];
int h[100000];
long long dij[100000][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, a, b;
	long long D, E, c;

	cin >> N >> M >> D >> E;
	for (int i = 0; i < N; ++i) cin >> h[i];
	while (M--) {
		cin >> a >> b >> c; a--, b--;
		if (h[a] < h[b]) e[a].push_back({ b,c });
		else if (h[a] > h[b]) e[b].push_back({ a,c });
	}

	for (int i = N - 2; i; --i) dij[i][0] = dij[i][1] = LLONG_MAX;
	dij[0][0] = dij[0][1] = 0;
	dij[N - 1][0] = dij[N - 1][1] = 0;

	for (int k = 0; k < 2; ++k) {
		pq.push({ (k ? (N - 1) : 0),0 });

		while (!pq.empty()) {
			a = pq.top().first;
			c = pq.top().second; pq.pop();
			if (c > dij[a][k]) continue;

			for (pil ed : e[a]) {
				b = ed.first;
				long long nc = c + ed.second;
				if (nc < dij[b][k]) dij[b][k] = nc, pq.push({ b,nc });
			}
		}
	}
	long long ANS = LLONG_MIN;
	for (int i = N - 2; i; --i) {
		if (dij[i][0] == LLONG_MAX || dij[i][1] == LLONG_MAX) continue;
		long long tmp = (long long)h[i] * E - (dij[i][0] + dij[i][1]) * D;
		if (ANS < tmp) ANS = tmp;
	}
	if (ANS > LLONG_MIN) cout << ANS;
	else cout << "Impossible";
	return 0;
}