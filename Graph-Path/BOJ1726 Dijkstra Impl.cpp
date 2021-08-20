#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int i, j, d, c;
};
bool operator<(node A, node B) {
	return A.c > B.c;
}

int main() {
	int N, M, tmp;
	int dij[100][100][4];

	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			dij[i][j][0] = dij[i][j][1] = dij[i][j][2] = dij[i][j][3] = 987654321;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp);
			if (tmp) dij[i][j][0] = dij[i][j][1] = dij[i][j][2] = dij[i][j][3] = -1;
		}
	}
	
	int Y, X, D;
	scanf("%d%d%d", &Y, &X, &D); Y--, X--, D--;
	priority_queue<node> pq;
	pq.push({ Y,X,D,0 }); dij[Y][X][D] = 0;

	scanf("%d%d%d", &Y, &X, &D); Y--, X--, D--;

	int turn[4][4] = { {0,2,1,1},{2,0,1,1},{1,1,0,2},{1,1,2,0} };
	int di[4] = { 0,0,1,-1 };
	int dj[4] = { 1,-1,0,0 };
	while (!pq.empty()) {
		int i = pq.top().i, j = pq.top().j;
		int d = pq.top().d, c = pq.top().c;  pq.pop(); 
		if (c > dij[i][j][d]) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int nd = (d + dir) % 4;
			int nc = c + turn[d][nd];
			if (dir && dij[i][j][nd] > nc) dij[i][j][nd] = nc, pq.push({ i,j,nd,nc });

			int ni = i, nj = j; nc++;
			for (int k = 0; k < 3; ++k) {
				ni += di[nd], nj += dj[nd];
				if (ni < 0 || ni >= M || nj < 0 || nj >= N || dij[ni][nj][nd] < 0) break;

				if (dij[ni][nj][nd] > nc) dij[ni][nj][nd] = nc, pq.push({ ni,nj,nd,nc });
			}
		}
		// 같은 방향, 1~3 전진
		// 다른 방향, 같은 자리 + 1~3 전진
		// 블록을 뚫고 갈 수 없으므로 break 
	}

/*	printf("\n         →                 ←                  ↓                  ↑\n");
	for (int i = 0; i < M; ++i) {
		for (int k = 0; k < 4; ++k) {
			for (int j = 0; j < N; ++j) {
				if (dij[i][j][k] < 987654321) printf("%2d ", dij[i][j][k]);
				else printf("-- ");
			}
			printf("  ");
		}
		printf("\n");
	}printf("\n");*/
	
	printf("%d", dij[Y][X][D]); return 0;
}