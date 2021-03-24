#include <cstdio>
#include <queue>
using namespace std;

char m[1001][1001];
int g[1001][1001];
/* void find(int r, int c, int k) {
	queue<pair<int, int>> Q;
	Q.push({ r,c }); g[r][c] = k;

	while (1) {
		if (m[r][c] == 'N') r--;
		else if (m[r][c] == 'S') r++;
		else if (m[r][c] == 'E') c++;
		else c--;

		if (g[r][c]) {
			int nk = g[r][c];
			if (nk == k) return;

			while (!Q.empty()) {
				g[Q.front().first][Q.front().second] = nk; Q.pop();
			}
			return;
		}
		else { g[r][c] = k; Q.push({ r,c }); }
	}
}*/
int main() {
	int N, M, cnt = 1;

	scanf("%d%d", &N,&M);
	for (int i = 0; i < N; ++i) scanf("%s", &m[i]);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (g[i][j]) continue;

			//find(i, j, cnt);
			int r = i, c = j;
			queue<pair<int, int>> Q;
			
			Q.push({ r,c }); g[r][c] = cnt;
			while (1) {
				if (m[r][c] == 'N') r--;
				else if (m[r][c] == 'S') r++;
				else if (m[r][c] == 'E') c++;
				else c--;

				if (g[r][c]) {
					int group = g[r][c];
					if (group == cnt) { cnt++; break; }

					while (!Q.empty()) {
						g[Q.front().first][Q.front().second] = group; Q.pop();
					}
					break;
				}
				else { g[r][c] = cnt; Q.push({ r,c }); }
			}
		}
	}
	printf("%d", cnt-1); return 0;
}
/*

5 5
SWWWW
SEWEN
SWSWN
SNEWN
ENEEN
*/