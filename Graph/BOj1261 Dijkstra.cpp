#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int y, x, cnt;
};
bool operator<(node A, node B) { //A보다 B가 우선
	return A.cnt > B.cnt;
}

priority_queue<node> pq;
char b[100][101];
int cnt[100][100];
int main() {
	int N, M;

	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i) scanf("%s", &b[i]);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cnt[i][j] = 987654321;
	}

	int y, x, c, ny, nx, nc;
	pq.push({ 0,0,0 }); cnt[0][0] = 0;
	while (!pq.empty()) {
		y = pq.top().y;
		x = pq.top().x;
		c = pq.top().cnt; pq.pop();
		if (c > cnt[y][x]) continue;
		//printf("\n[%d][%d] %d -> ", y, x, c);

		for (int d = 0; d < 4; ++d) {
			ny = y + "2011"[d] - '1';
			if (ny < 0 || ny >= N) continue;
			nx = x + "1120"[d] - '1';
			if (nx < 0 || nx >= M) continue;
			nc = c + ((b[ny][nx]=='1') ? 1 : 0);
			if (nc >= cnt[ny][nx]) continue;

			pq.push({ ny,nx,nc }); cnt[ny][nx] = nc;
		//	printf("[%d][%d] %d / ", ny, nx, nc);
		}
	}
/*	printf("\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) printf("%d ",cnt[i][j]);
		printf("\n");
	}*/
	printf("%d", cnt[N - 1][M - 1]); return 0;
}