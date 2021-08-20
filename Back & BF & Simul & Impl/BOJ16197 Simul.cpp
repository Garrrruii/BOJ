#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int main() {
	int N, M, ai = -1, aj, bi, bj;
	char b[20][21];
	int vis[20][20][20][20];

	// Input & Initiation
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &b[i]);
		for (int j = 0; j < M; ++j) {
			if (b[i][j] == 'o') {
				if (ai < 0) ai = i, aj = j;
				else bi = i, bj = j;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			for (int ii = 0; ii < N; ++ii)
				for (int jj = 0; jj < M; ++jj) vis[i][j][ii][jj] = false;
	
	// BFS
	int di[4] = { 0, 0, 1, -1 };
	int dj[4] = { 1, -1, 0, 0 };
	queue<pair<pii, pii>> Q;
	Q.push({ {ai,aj},{bi,bj} }); vis[ai][aj][bi][bj] = vis[bi][bj][ai][aj] = true;
	int ans = 0, qsize = 1;
	while (qsize && ans < 10) {
		ans++;
		while (qsize--) {
			ai = Q.front().first.first; aj = Q.front().first.second;
			bi = Q.front().second.first; bj = Q.front().second.second; Q.pop();
			
			// 1. 한 동전만 떨어지는 경우
			if ((!ai && bi) || (ai && !bi) || (!aj && bj) || (aj && !bj) ||
				(ai == N - 1 && bi < N - 1) || (ai < N - 1 && bi == N - 1) ||
				(aj == M - 1 && bj < M - 1) || (aj < M - 1 && bj == M - 1)) {
				printf("%d", ans); return 0;
			}

			int ni, nj, mi, mj;
			for (int d = 0l; d < 4; ++d) {
				ni = ai + di[d], nj = aj + dj[d];
				mi = bi + di[d], mj = bj + dj[d];

				// 2. 범위 이탈
				if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
				if (mi < 0 || mi >= N || mj < 0 || mj >= M) continue;
				
				// 3. 동전 위치 조정
				if (b[ni][nj] == '#') ni = ai, nj = aj;
				if (b[mi][mj] == '#') mi = bi, mj = bj;

				// 4. 이미 방문 or 두 동전이 겹쳐지는 경우
				if (vis[ni][nj][mi][mj] || (ni==mi && nj==mj)) continue;

				vis[ni][nj][mi][mj] = vis[mi][mj][ni][nj] = true, Q.push({ {ni,nj},{mi,mj} });
			}
		}
		qsize = Q.size();
	}
	printf("-1"); return 0;
}