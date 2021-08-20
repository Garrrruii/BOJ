#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int i, j, c;
};
bool operator<(node A, node B) {
	return A.c > B.c;
}

int main() {
	int T;
	scanf("%d", &T);

	vector<pair<int, int>> V; V.reserve(400);
	priority_queue<node> pq;
	int H, W, ai, aj, bi, bj;
	char b[100][101];
	int dij[100][100][3];
	
	while (T--) {
		// Input
		ai = -1;
		scanf("%d%d", &H, &W);
		for (int i = 0; i < H; ++i) {
			scanf("%s", &b[i]);
			for (int j = 0; j < W; ++j) {
				if (b[i][j] == '$') {
					if (ai < 0) ai = i, aj = j;
					else bi = i, bj = j;
				}
			}
		}

		// 테두리 중 벽이 아닌 곳 (죄수가 테두리에 있을 수도)
		V.clear();
		for (int j = 0; j < W; ++j) {
			if (b[0][j] != '*') V.push_back({ 0,j });
			if (b[H - 1][j] != '*') V.push_back({ H - 1,j });
		}
		for (int i = 1; i < H - 1; ++i) {
			if (b[i][0] != '*') V.push_back({ i,0 });
			if (b[i][W - 1] != '*') V.push_back({ i,W - 1 });
		}

		// Initiation
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) dij[i][j][0] = dij[i][j][1] = dij[i][j][2] = 9999;
		
		// BFS
		for (int k = 0; k < 3; ++k) {
			if (k == 0) dij[ai][aj][0] = 0, pq.push({ ai,aj,0 });
			else if (k == 1) dij[bi][bj][1] = 0, pq.push({ bi,bj,0 });
			else {
				for (pair<int, int> v : V) {
					int i = v.first, j = v.second;
					if (b[i][j] == '#') dij[i][j][2] = 1, pq.push({ i,j,1 });
					else dij[i][j][2] = 0, pq.push({ i,j,0 });
				}
			}

			while (!pq.empty()) {
				int i = pq.top().i;
				int j = pq.top().j;
				int c = pq.top().c; pq.pop();
				if (c > dij[i][j][k]) continue;

				for (int d = 0; d < 4; ++d) {
					int ni = i + "1102"[d] - '1';
					if (ni < 0 || ni >= H) continue;
					int nj = j + "0211"[d] - '1';
					if (nj < 0 || nj >= W || b[ni][nj] == '*') continue;
					
					int nc = c + (b[ni][nj] == '#' ? 1 : 0);
					if (nc < dij[ni][nj][k]) dij[ni][nj][k] = nc, pq.push({ ni,nj,nc });
				}
			}
		}

		// 두 죄수가 같은 문으로 나가는 경우
		int sum = 9999, tmp;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				tmp = dij[i][j][0] + dij[i][j][1] + dij[i][j][2];
				if (b[i][j] == '#') tmp -= 2;
				if (sum > tmp) sum = tmp;
			}
		}
		// 두 죄수가 다른 문으로 나가는 경우
		for (pair<int, int> v : V) {
			for (pair<int, int> w : V) {
				tmp = dij[v.first][v.second][0] + dij[w.first][w.second][1];
				if (sum > tmp) sum = tmp;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
/*
5 11
*#*********
*#*...*#.#*
*#*.*.*.*#*
*$$.*...*.*
*********#*

3 6
**#***
#$##$#
******

3 4
****
$.$*
****
*/