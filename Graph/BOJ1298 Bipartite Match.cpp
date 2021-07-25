#include <iostream>
#include <vector>
using namespace std;

bool vis[101];
int own[101];			// own[i]: i를 가지는 사람
vector<int> pick[101];  // pick[i]: i가 고른 노트북
bool dfs(int x) { //x가 노트북과 매칭될 수 있는가?

	for (int p : pick[x]) {
		//x가 고른 노트북 p

		if (vis[p]) continue;
		vis[p] = true;
		//p가 이번 탐색에서 탐색되지 않은 곳이면 확인

		if (!own[p] || dfs(own[p])) { own[p] = x; return true; }
		//p의 주인이 없거나 p의 현재 주인이 다른 노트북을 가질 수 있으면 true
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, a, b;

	cin >> N >> M;
	while (M--) { cin >> a >> b; pick[a].push_back(b); }

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) vis[j] = false;
		if (dfs(i)) ans++;
	}
	printf("%d", ans); return 0;
}
/* Whyrano,,,,,,,,,,,,

7 12
1 1 2 1 3 1 4 2 5 1 5 2 5 3 4 3 6 2 6 3 7 3 1 7

5 11
1 2 1 5 2 2 2 3 2 4 3 1 3 5 4 1 4 2 4 5 5 2
*/