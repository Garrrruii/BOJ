#include <iostream>
#include <vector>
using namespace std;

int c[1001], N;
vector<int> e[1001];
bool vis[1001];
//int vis[1001];
bool dfs(int cur, int cost) {
	if (cur == N) return true;

	vis[cur] = true;
	//vis[cur] = cost;
	int ncost = 0;
	for (int nxt : e[cur]) {
		if (vis[nxt]) continue;
		if (c[nxt] < 0) {
			if (cost < -c[nxt]) continue;
			else ncost = cost + c[nxt];
		}
		else {
			if (cost < c[nxt]) ncost = c[nxt];
			else ncost = cost;
		}

		//if (ncost <= vis[nxt]) continue;
		if (dfs(nxt, ncost)) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tmp; e[0].push_back(1);
	char type;
	while (1) {
		cin >> N;
		if (!N) return 0;

		for (int i = 1; i <= N; ++i) e[i].clear();
		for (int i = 1; i <= N; ++i) {
			cin >> type >> tmp;
			c[i] = (type == 'T') ? -tmp : tmp;
			while (1) {
				cin >> tmp;
				if (!tmp) break;
				e[i].push_back(tmp);
			}
		}

		for (int i = 1; i <= N; ++i) vis[i] = false;
		//for (int i = 1; i <= N; ++i) vis[i] = -1;
		if (dfs(0, 0)) cout << "Yes\n";
		else cout << "No\n";
	}
}