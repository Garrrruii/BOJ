#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int R, C, N, H;
	char b[100][101];
	bool left = true;
	
	bool vis[100][100], landed = true;
	queue<pair<int, int>> Q;
	vector<int> S[2][100];
	int col;
	
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; ++i) scanf("%s", &b[i]);
	scanf("%d", &N);
	while (N--) {
		// Input
		scanf("%d", &H); H = R - H;

		// Break Mineral
		if (left) {
			left = false; col = 0;
			while (col < C && b[H][col] == '.') col++;
			if (col == C) continue;
		}
		else {
			left = true; col = C - 1;
			while (col >= 0 && b[H][col] == '.') col-- ;
			if (col < 0) continue;
		}
		b[H][col] = '.';

		// Initiation
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) vis[i][j] = (b[i][j] == '.');
		for (int j = 0; j < C; ++j) S[0][j].clear();
		for (int j = 0; j < C; ++j) S[1][j].clear(), S[1][j].push_back(R);

		
		// Find Mineral Group
		for (int i = R - 1; i >= 0; --i) {
			for (int j = 0; j < C; ++j) {
				if (vis[i][j]) continue;
				landed = (i == R - 1);

				Q.push({ i,j }); vis[i][j] = true;
				while (!Q.empty()) {
					int ci = Q.front().first;
					int cj = Q.front().second; Q.pop();
					S[landed][cj].push_back(ci);

					// for ni=ci+di[d], nj=cj+dj[d]
					if (ci && !vis[ci - 1][cj]) Q.push({ ci - 1,cj }), vis[ci - 1][cj] = true;
					if (ci < R - 1 && !vis[ci + 1][cj]) Q.push({ ci + 1,cj }), vis[ci + 1][cj] = true;
					if (cj && !vis[ci][cj - 1]) Q.push({ ci,cj - 1 }), vis[ci][cj - 1] = true;
					if (cj < C - 1 && !vis[ci][cj + 1]) Q.push({ ci,cj + 1 }), vis[ci][cj + 1] = true;
				}
			}
		}
		for (int j = 0; j < C; ++j) sort(S[0][j].begin(), S[0][j].end(), greater<int>());
		for (int j = 0; j < C; ++j) sort(S[1][j].begin(), S[1][j].end());

		// Fall Down
		int down = R;
		for (int j = 0; j < C; ++j) {
			if (S[0][j].empty()) continue;

			for (int k = S[0][j].size() - 1; k; --k) {
				if (S[0][j][k] < S[0][j][k - 1] - 1) {
					int tmp = *(upper_bound(S[1][j].begin(), S[1][j].end(), S[0][j][k])) - S[0][j][k];
					down = min(down, tmp);
				}
			}
			int tmp = *(upper_bound(S[1][j].begin(), S[1][j].end(), S[0][j][0])) - S[0][j][0];
			down = min(down, tmp);
		}
		down--;

		for (int j = 0; j < C; ++j) {
			for (int ui : S[0][j]) b[ui + down][j] = 'x', b[ui][j] = '.';
		}

/*		for (int j = 0; j < C; ++j) {
			printf("\n[0]%d]: ", j);
			for (int i : S[0][j]) printf("%d ", i);
			printf("\t[1][%d]: ", j);
			for (int i : S[1][j]) printf("%d ", i);
		}
		printf("\n");
		
		for (int i = 0; i < R; ++i) printf("%s\n", b[i]);
		printf("\n");*/
	}
	for (int i = 0; i < R; ++i) printf("%s\n", b[i]);

}
/*
9 8
........
...xxx..
.xxx....
.x.x.xxx
.x.x...x
.x.xxx.x
.x.....x
.x.....x
.xxx...x
3 7 6 3

........  ........  ........
........  ........  ........
...xxx..  ...xxx..  ........
.xxx.xxx  .xxx.xx.  ...xxx..
.x.x...x  .x.x...x  .xxx.xxx
.x.x...x  .x.x...x  .x.x...x
.x.xxx.x  .x.xxx.x  .x.x...x
.x.....x  .x.....x  .x.xxx.x
.xxx...x  .xxx...x  .xxx...x
*/