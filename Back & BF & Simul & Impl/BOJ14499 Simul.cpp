#include <cstdio>
using namespace std;

int main() {
	int num[6];					// 주사위 면에 쓰인 수
	int topidx = 0;				// 현재 윗면 idx
	int dir[4] = { 2,3,1,4 };	// 현재 동서북남 idx

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	int N, M, x, y, K, d;
	int map[20][20];

	scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &map[i][j]);
	}
	
	while (K--) {
		scanf("%d", &d); d--;
		x += dx[d], y += dy[d];

		// Out of map
		if (x < 0 || x == N || y < 0 || y == M) {
			x -= dx[d], y -= dy[d]; continue;
		}

		// Change EWNS
		if (d == 0) {
			dir[0] = topidx, topidx = dir[1];
			dir[1] = 5 - dir[0];
		}
		else if (d == 1) {
			dir[1] = topidx, topidx = dir[0];
			dir[0] = 5 - dir[1];
		}
		else if (d == 2) {
			dir[2] = topidx, topidx = dir[3];
			dir[3] = 5 - dir[2];
		}
		else {
			dir[3] = topidx, topidx = dir[2];
			dir[2] = 5 - dir[3];
		}

		// Get Top of dice
		if (map[x][y]) num[5 - topidx] = map[x][y], map[x][y] = 0;
		else map[x][y] = num[5 - topidx];
		printf("%d\n", num[topidx]);
	}
	return 0;
}