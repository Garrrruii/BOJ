#include <iostream>
#include <vector>
using namespace std;

bool vis[201];
int own[201];			// own[i]: i�� ���� ��
vector<int> pick[201];  // pick[i]: i�� �� ���
bool dfs(int x) { //x�� ��翡 �� �� �ֳ�?

	for (int p : pick[x]) { //x�� �� ��� p

		if (vis[p]) continue;
		vis[p] = true;
		//p�� �̹� Ž������ Ž������ ���� ���̸� Ȯ��

		if (!own[p] || dfs(own[p])) { own[p] = x; return true; }
		//p�� ����ų� p�� �Ұ� �ٸ� ���� �� �� ������ true
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, a, b, K;

	cin >> N >> M;
	for (a = 1; a <= N; ++a) {
		cin >> K;
		while (K--) cin >> b, pick[a].push_back(b);
	}
	
	a = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) vis[j] = false; //cycleó�� ������ ���� ���� �ʱ�ȭ
		if (dfs(i)) a++;
	}
	cout << a; return 0;
}
/*
7 6
2 1 6
1 1
1 1
2 2 3
3 1 2 3
2 2 3
2 3 6
(4)

5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2
(4)
*/