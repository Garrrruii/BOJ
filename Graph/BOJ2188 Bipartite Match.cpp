#include <iostream>
#include <vector>
using namespace std;

bool vis[201];
int own[201];			// own[i]: i에 들어가는 소
vector<int> pick[201];  // pick[i]: i가 고른 축사
bool dfs(int x) { //x가 축사에 들어갈 수 있나?

	for (int p : pick[x]) { //x가 고른 축사 p

		if (vis[p]) continue;
		vis[p] = true;
		//p가 이번 탐색에서 탐색되지 않은 곳이면 확인

		if (!own[p] || dfs(own[p])) { own[p] = x; return true; }
		//p가 비었거나 p의 소가 다른 축사로 갈 수 있으면 true
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
		for (int j = 1; j <= M; ++j) vis[j] = false; //cycle처리 때문에 시행 마다 초기화
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