#include <iostream>
#include <vector>
using namespace std;

vector<int> jr[100001];
int point[100001];
int dfs(int cur) {
	int ret = point[cur];
	for (int nxt : jr[cur]) ret += dfs(nxt);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M , q, id, w;

	cin >> N >> M >> id;
	for (int i = 2; i <= N; ++i) cin >> id, jr[id].push_back(i);

	while (M--) {
		cin >> q >> id;
		// 1 id w  id 직원이 직속 부하로부터 w만큼 칭찬 받음
		// 2 id    id 직원의 칭찬 점수를 출력
		if (q & 1) cin >> w, point[id] += w;
		else cout << dfs(id) << "\n";
	}
	return 0;
}