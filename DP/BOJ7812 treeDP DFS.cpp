#include <iostream>
#include <vector>
using namespace std;

bool vis[10000];
int N, cnum[10000];

typedef pair<int, int> pii;
vector<pii> E[10000];

pair<int,long long> dfs_tree(int cur) {
	vis[cur] = true;
	int child_num = 1;
	long long dist = 0;
	pair<int, long long> ret;

	for (pii e : E[cur]) {
		int nxt = e.first;
		if (vis[nxt]) continue;

		ret = dfs_tree(nxt);
		cnum[nxt] = ret.first;
		child_num += ret.first;
		dist += (1LL * e.second * ret.first + ret.second);
	}
	
	vis[cur] = false;
	return { child_num,dist };
}
long long dfs_dist(int cur, long long ans) {
	vis[cur] = true;
//	cout << ans << " at " << cur << "\n";

	long long rem = ans;
	for (pii e : E[cur]) {
		int nxt = e.first;
		if (vis[nxt]) continue;
	
		int cnt = N - (cnum[nxt] << 1);
		if (cnt > 0) continue;
		long long tmp = dfs_dist(nxt, rem + 1LL * e.second * cnt);
		ans = (ans < tmp) ? ans : tmp;
	}

//	cout << ans << " at " << cur << ": updated!\n";
	vis[cur] = false;
	return ans;
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
		cout << dfs_dist(0, dfs_tree(0).second) << "\n";

		for (int i = 0; i < N; ++i) cnum[i] = 0;
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