#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, tmp;
queue<pair<int, int>> Q;
bool vis[50][50];
int ANS = -1;
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, -0, -1, -1 };

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &tmp);
			if (tmp) vis[i][j]=true, Q.push({ i,j });
		}
	}
	while (!Q.empty()) {
		ANS++;
		//printf("ANS %d\t",ANS);
		int qsize = Q.size();
		while (qsize--) {
			int x = Q.front().second;
			int y = Q.front().first; Q.pop();
			//printf("%d,%d  ", y, x);

			for (int d = 0; d < 8; d++) {
				int nx = x + dx[d];
				if (nx < 0 || nx == M) continue;
				int ny = y + dy[d];
				if (ny < 0 || ny == N || vis[ny][nx]) continue;

				vis[ny][nx] = true; Q.push({ ny,nx });
			}
		}
		//printf("\n");
	}
	printf("%d\n", ANS); return 0;
}