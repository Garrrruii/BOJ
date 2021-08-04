#include <iostream>
#include <vector>
using namespace std;

bool vis[10000];
int N;
long long ANS = 0;
vector<pair<int, int>> E[10000]; //{who,cost}

long long dfs(int cur) {
	vis[cur] = true;
	int child_num = 1;

	for (pair<int, int> e : E[cur]) {
		if (vis[e.first]) continue;

		int cnt = dfs(e.first);
		child_num += cnt;
		ANS += 1LL * e.second * ((cnt << 1) < N ? cnt : N - cnt);
		// 중심 정점이 cur쪽인지 nxt(e.second)쪽인지 결정
	}

	vis[cur] = false;
	return child_num;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a, b, c;
	while (1) {
		cin >> N;
		if (!N) return 0;
		for (int i = 1; i < N; ++i) {
			cin >> a >> b >> c;
			E[a].push_back({ b,c });
			E[b].push_back({ a,c });
		}
		ANS = 0; dfs(0); cout << ANS << "\n";

		for (int i = 0; i < N; ++i) E[i].clear();
	}
}
/*
8
1 0 2 7 0 4 3 5 5 6 3 7
1 2 3 1 3 1 1 4 6
8
0 2 3 0 1 1 1 4 2 1 3 6
3 5 1 3 6 4 7 3 2
0
(32 38)
*/