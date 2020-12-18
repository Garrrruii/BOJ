// baby shark
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, tmp;
int S = 2, sy, sx;
int map[20][20];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, -1, 0, 1};

// 먹을 수 있는 물고기 1마리 => 먹으러 ㄲ
// 여러마리 => 가장 가까운, 가장 위, 가장 왼쪽
// 이동과 동시에 물고기를 먹는다

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp);			
			map[i][j] = tmp;
			if (tmp == 9) sy = i, sx = j;
		}
	}

	//현재 위치 sy, sx에서 가장 가까운 물고기 찾기
	int CNT = 0, ANS = 0;
	while (1) {
//		printf("%d,%d ->", sx, sy);

		bool vis[20][20] = { false, };
		queue<pair<int, int>> Q;
		Q.push({ sy,sx }); vis[sy][sx] = true;
		int tary = 21, tarx = 21;
		bool finding = true;
		int sec = 0;
		while (finding && !Q.empty()) {
//			printf("\t%d: ", sec);
			sec++;
			int qsize = Q.size();
			//같은 위치에 있는 물고기들 탐색중
			while (qsize--) {
				int y = Q.front().first;
				int x = Q.front().second; Q.pop();
				for (int d = 0; d < 4; ++d) {
					int ny = y + dy[d];
					if (ny < 0 || ny == N) continue;
					int nx = x + dx[d];
					if (nx<0 || nx == N || vis[ny][nx] || map[ny][nx]>S) continue;
					vis[ny][nx] = true;
//					printf("%d,%d ", nx, ny);
					if (map[ny][nx] > 0 && map[ny][nx] < S) {
						finding = false;
						if ((ny < tary) || (ny == tary && nx < tarx)) tary = ny, tarx = nx;
					}
					else if (finding) Q.push({ ny,nx });
				}
			}
//			printf("\n");
		}
		if (!finding) {
			map[sy][sx] = map[tary][tarx] = 0; CNT++;
			sy = tary; sx = tarx; ANS += sec;
			if (CNT == S) S++, CNT = 0;
		}
		else {
			printf("%d\n", ANS); return 0;
		}
	}
}