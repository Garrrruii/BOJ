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
		// �ܺ� ���� ó�� bfs (Q)
		// ��� ���� ���� �ϳ��� ���������� bfs�� ������ ��
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

		// ���� �� �ִ� ġ�� ���̱�
		// ������ �� ���ƾ� �ϴϱ� for������ count�ϴ� �� ����
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

		// ���� �ٱ��� �´��� ���� Q�� ����
		// ���� �´��� �κ� ��� ã�ƾ� ��(�ϳ��� ã�Ҵٰ� �� �ƴ�)
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
