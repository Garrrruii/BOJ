#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> Q;
int B[100][100];
int main() {
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };

	int N, M, H = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &B[i][j]);
	}

	B[0][0] = -1, Q.push({ 0,0 });
	while (1) {
		// 외부 공기 처리 bfs (Q)
		// 모든 공기 공간 하나씩 들어와있으니 bfs만 돌리면 됨
		while (!Q.empty()) {
			int x = Q.front().second;
			int y = Q.front().first; Q.pop();

			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
				if (!B[ny][nx]) B[ny][nx] = -1, Q.push({ ny,nx });
			}
		}

		// 녹일 수 있는 치즈 녹이기
		// 어차피 다 돌아야 하니까 for문으로 count하는 게 나음
		bool nocheese = true;
		for (int i = 1; i < N - 1; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (B[i][j] <= 0) continue;
				nocheese = false;
				int cnt = (B[i - 1][j] < 0) ? 1 : 0;
				cnt += (B[i + 1][j] < 0) ? 1 : 0;
				cnt += (B[i][j - 1] < 0) ? 1 : 0;
				cnt += (B[i][j + 1] < 0) ? 1 : 0;
				if (cnt > 1) Q.push({ i,j });
			}
		}
		if (nocheese) { printf("%d", H); return 0; }
		while (!Q.empty()) B[Q.front().first][Q.front().second] = -1, Q.pop();

		// 새로 바깥과 맞닿은 공기 Q에 삽입
		// 새로 맞닿은 부분 모두 찾아야 함(하나만 찾았다고 끝 아님)
		for (int i = 1; i < N - 1; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (B[i][j]) continue;

				if (B[i - 1][j] < 0 || B[i + 1][j] < 0 ||
					B[i][j - 1] < 0 || B[i][j + 1] < 0) {
					B[i][j] = -1, Q.push({ i,j });
				}
			}
		}

		H++;
	}
	return 0;
}
/*
(6) 8 10
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 1 1 1 1 1 1 1 1 0
0 1 0 0 0 1 0 1 1 0
0 1 1 1 1 1 0 1 1 0
0 1 1 1 1 1 0 1 1 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0

(5) 8 10
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 1 1 1 0 1 0 1 1 0
0 1 0 0 0 1 0 1 1 0
0 1 1 1 0 1 0 1 1 0
0 0 1 1 1 1 0 1 1 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0
*/
