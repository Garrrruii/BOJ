//robot vaccum
//note that 1. go backward while we meet wall
//			2. clean cell only once
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int dc[4] = { 0, 1, 0, -1 };
	int dr[4] = { -1, 0, 1, 0 };
	int N, M, r, c, dir, inp;
	bool wall[50][50] = { false, };
	bool clean[50][50] = { false, };

	scanf("%d%d%d%d%d", &N, &M, &r, &c, &dir);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &inp);
			if (inp) wall[i][j] = true;
		}
	}

	int ANS = 1; clean[r][c] = true;
	while (1) {
		//printf("%d %d, dir=%d   ", c, r, dir);
		bool ava = false;
		int newdir = (dir) ? dir - 1 : 3;
		int k = 4;
		while (k--) {
			int nr = r + dr[newdir];
			int nc = c + dc[newdir];
			if (!clean[nr][nc] && !wall[nr][nc]) {
				ANS++; clean[nr][nc] = ava = true;
				r = nr, c = nc, dir = newdir; break;
			}
			newdir = (newdir) ? newdir - 1 : 3;
		}
		if (!ava) {
			r -= dr[dir]; c -= dc[dir];
			//printf("\n");
			if (wall[r][c]) break;
		}
	}
	printf("%d", ANS); return 0;
	
}