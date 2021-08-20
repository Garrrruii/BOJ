//K-th minimal path for each cities
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> E[1001];			//edges
priority_queue<int> D[1001];	//D[i]=(1->i) 경로 K개 먼 순서로 정렬

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, K, a, b, c;
	cin >> N >> M >> K;
	while (M--) cin >> a >> b >> c, E[a].push_back({ b, c });

	priority_queue<pii, vector<pii>, greater<>> PQ;
	PQ.push({ 1,0 }); D[1].push(0);

	int cur, cost, nxt, ncost;
	while (!PQ.empty()) { //cur(cost)->nxt(ncost)
		cur = PQ.top().first;
		cost = PQ.top().second; PQ.pop();
		if (D[cur].top() < cost) continue;

		for (int i = 0; i < E[cur].size(); i++) {
			nxt = E[cur][i].first;
			ncost = E[cur][i].second + cost;

			if (D[nxt].size() < K) {		//nxt로의 경로 K개까지만 저장
				D[nxt].push(ncost);
				PQ.push({ E[cur][i].first, ncost });
			}
			else if (D[nxt].top() > ncost) {//K개 있는데 top보다 ncost가 작음
				D[nxt].pop(); D[nxt].push(ncost);
				PQ.push({ E[cur][i].first, ncost });
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (D[i].size() == K) cout << D[i].top() << "\n";
		else cout << "-1\n";
	}
	return 0;
}