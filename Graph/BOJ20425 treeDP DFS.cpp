#include <iostream>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> ppiii;

bool vis[10000];
vector<ppiii> E[10000]; //{{who,cost},child_num}
int N;

pair<int,long long> dfs_tree(int cur,long long dist) {
	vis[cur] = true;
	int child_num = 1;
	pair<int, long long> ret;

	for (ppiii& e : E[cur]) {
		int nxt = e.first.first;
		if (vis[nxt]) continue;

		ret = dfs_tree(nxt, 0);
		e.second = ret.first;
		child_num += ret.first;
		dist += (1LL * e.second * e.first.second + ret.second);
	}
	
	vis[cur] = false;
	return { child_num,dist };
}
long long dfs_dist(int cur, long long ans) {
	vis[cur] = true;
//	cout << ans << " at " << cur << "\n";

	long long rem = ans;
	for (ppiii e : E[cur]) {
		int nxt = e.first.first;
		if (vis[nxt]) continue;
	
		int cnt = N - (e.second << 1);
		if (cnt > 0) continue;
		long long tmp = dfs_dist(nxt, rem + 1LL * e.first.second * cnt);
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
			E[a].push_back({ {b,c},0 });
			E[b].push_back({ {a,c},0 });
		}
		cout << dfs_dist(0, dfs_tree(0,0).second) << "\n";

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