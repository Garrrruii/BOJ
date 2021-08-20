//byebye PM
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[51][51];

int main() {
	queue<pair<int, pair<int, int>>> Q;
	int dr[4] = { 0, 0, -1, 1 };
	int dc[4] = { -1, 1, 0, 0 };
	int r1 = -1, r2; //공기청정기
	int R, C, T, inp;
	scanf("%d%d%d", &R, &C, &T);

	for (int r = 1; r <= R; ++r) {
		scanf("%d", &inp); map[r][1] = inp;
		if (inp > 0) Q.push({ inp,{ r,1 } });
		else if (inp < 0 && r1 < 0) r1 = r, r2 = r + 1;
		for (int c = 2; c <= C; ++c) {
			scanf("%d", &inp); map[r][c] = inp;
			if (inp > 0) Q.push({ inp,{ r,c } });
		}
	}
	while (T--) {
		while (!Q.empty()) {
			int mov = Q.front().first / 5;
			if (!mov) { Q.pop(); continue; }
			int r = Q.front().second.first;
			int c = Q.front().second.second; Q.pop();

			for (int d = 0; d < 4; ++d) {
				int nr = r + dr[d], nc = c + dc[d];
				if (!nr || nr > R || !nc || nc > C) continue;
				if (nc == 1 && (nr == r1 || nr == r2)) continue;

				map[nr][nc] += mov; map[r][c] -= mov;
			}
		}
		for (int r = r1 - 1; r > 1; --r) map[r][1] = map[r - 1][1];
		for (int c = 1; c < C; ++c) map[1][c] = map[1][c + 1];
		for (int r = 1; r < r1; ++r) map[r][C] = map[r + 1][C];
		for (int c = C; c > 2; --c) map[r1][c] = map[r1][c - 1];
		map[r1][2] = 0;
		for (int r = r2 + 1; r < R; ++r) map[r][1] = map[r + 1][1];
		for (int c = 1; c < C; ++c) map[R][c] = map[R][c + 1];
		for (int r = R; r > r2; --r) map[r][C] = map[r - 1][C];
		for (int c = C; c > 2; --c) map[r2][c] = map[r2][c - 1];
		map[r2][2] = 0;

		for (int r = 1; r <= R; ++r) {
			for (int c = 1; c <= C; ++c) {
				if (map[r][c] > 0) Q.push({ map[r][c],{ r,c } });
			}
		}
	}

	//printf("\n");
	//for (int r = 1; r <= R; ++r) {
	//	for (int c = 1; c <= C; ++c) printf("%d ", map[r][c]);
	//	printf("\n");
	//}
	//printf("\n");

	int ANS = 0;
	while (!Q.empty()) ANS += Q.front().first, Q.pop();
	printf("%d", ANS); return 0;
}

