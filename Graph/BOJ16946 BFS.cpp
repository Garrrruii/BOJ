#include <cstdio>
#include <queue>
using namespace std;
// 각각의 벽에 대해서
// 벽을 부쉈을 때 이동할 수 있는 칸의 개수를 센다.
// BFS + 아주 약간의 DP?

vector<int> area;
int idx[1000][1000];
char map[1000][1001];
queue<pair<int, int>> Q;
int main() {
	int N, M;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%s", &map[i]);
	area.push_back(0);

	// BFS
	int index = 1;
	int val = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == '1' || idx[i][j]) continue;

			val = 1; idx[i][j] = index; Q.push({ i,j });
			while (!Q.empty()) {
				int x = Q.front().second;
				int y = Q.front().first; Q.pop();
			
				for (int i = 0; i < 4;++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (map[ny][nx]=='1' || idx[ny][nx]) continue;

					val++; idx[ny][nx] = index; Q.push({ ny,nx });
				}
			}
			area.push_back(val); index++;
		}
	}

	// Find ANS
	int tmp[4] = { 0, };
	int val = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (idx[y][x]) continue;

			val = 1;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= M || ny < 0 | ny >= N) {tmp[i] = 0; continue; }
				tmp[i] = idx[ny][nx];
				for (int j = 0; j < i; ++j)
					if (tmp[i] == tmp[j]) { tmp[i] = 0; break; }
				val += area[tmp[i]];
			}
			map[y][x] = (char)('0' + val % 10);
		}
	}

	// Print ANS
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) printf("%c", map[i][j]);
		printf("\n");
	}
	return 0;
}
/*
for (int i = 0; i < N; ++i) {
	for (int j = 0; j < M; ++j) printf("%d", idx[i][j]);
	printf("\n");
}
printf("area: ");
for (int i : area) printf("%d ", i);
printf("\n");

*/