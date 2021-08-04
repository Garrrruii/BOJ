#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int N, M, x, y, a, b;
	vector<pair<int, int>> swt[100][100];
	bool on[100][100];
	int vis[100][100];

	scanf("%d%d", &N, &M);
	while (M--) scanf("%d%d%d%d", &x, &y, &a, &b), swt[y - 1][x - 1].push_back({ b - 1,a - 1 });

	//Initiation
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) on[i][j] = false;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) vis[i][j] = 0;

	int ANS = 1;
	queue<pair<int, int>> Q;
	int di[4] = { 1, -1, 0, 0 };
	int dj[4] = { 0, 0, 1, -1 };

	on[0][0] = true; vis[0][0] = 1; Q.push({ 0,0 });
	while (!Q.empty()) {
		int i = Q.front().first;
		int j = Q.front().second; Q.pop();
		
		for (pair<int, int> s : swt[i][j]) {
			if (!on[s.first][s.second]) on[s.first][s.second] = true, ANS++;
		}

		for (int d = 0; d < 4; ++d) {
			int ni = i + di[d], nj = j + dj[d];
			if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
			if (on[ni][nj] && vis[ni][nj] < ANS) vis[ni][nj] = ANS, Q.push({ ni,nj });
		}
	}
	printf("%d", ANS); return 0;
}