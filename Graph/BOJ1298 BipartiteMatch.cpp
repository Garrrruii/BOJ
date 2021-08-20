#include <iostream>
#include <vector>
using namespace std;

bool vis[101];
int own[101];			// own[i]: i�� ������ ���
vector<int> pick[101];  // pick[i]: i�� �� ��Ʈ��
bool dfs(int x) { //x�� ��Ʈ�ϰ� ��Ī�� �� �ִ°�?

	for (int p : pick[x]) {
		//x�� �� ��Ʈ�� p

		if (vis[p]) continue;
		vis[p] = true;
		//p�� �̹� Ž������ Ž������ ���� ���̸� Ȯ��

		if (!own[p] || dfs(own[p])) { own[p] = x; return true; }
		//p�� ������ ���ų� p�� ���� ������ �ٸ� ��Ʈ���� ���� �� ������ true
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