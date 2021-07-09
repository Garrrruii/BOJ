#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> Q;
int main() {
	int dx[4] = { 1, -1, 0 ,0 };
	int dy[4] = { 0, 0, 1, -1 };
	int N, M, B[8][8]; //0:empty  1:wall  2:virus    64C3 = 41664
	int tmp;
	vector<pair<int, int>> E; E.reserve(62);
	vector<pair<int, int>> V; V.reserve(10);

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &tmp); B[i][j] = tmp;
			if (!tmp) E.push_back({ i,j });
			else if (tmp > 1) V.push_back({ i,j });
		}
	}

	int ans = 0;
	int ESIZE = E.size();
	int x1, x2, x3, y1, y2, y3;
	for (int i = 0; i < ESIZE; ++i) {
		x1 = E[i].second, y1 = E[i].first; B[y1][x1] = 1;
		for (int j = i + 1; j < ESIZE; ++j) {
			x2 = E[j].second, y2 = E[j].first; B[y2][x2] = 1;
			for (int k = j + 1; k < ESIZE; ++k) {
				x3 = E[k].second, y3 = E[k].first; B[y3][x3] = 1;
				// 1. Select i<j<k (make new wall)

				// 2. Visit virus zone
				for (pair<int, int> v : V) {
					Q.push(v);
					while (!Q.empty()) {
						int cx = Q.front().second;
						int cy = Q.front().first; Q.pop();

						for (int d = 0; d < 4; ++d) {
							int nx = cx + dx[d];
							if (nx < 0 || nx >= M) continue;
							int ny = cy + dy[d];
							if (ny < 0 || ny >= N || B[ny][nx]) continue;
						
							B[ny][nx] = 3, Q.push({ ny,nx });
						}
					}
				}

				// 3. Count safe cells
				tmp = 0;
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < M; ++j) {
						if (!B[i][j]) tmp++;
						else if (B[i][j] > 2) B[i][j] = 0;
					}
				}
				//	if(ans<tmp) printf("%d,%d  %d,%d  %d,%d  tmp=%d\n", x1, y1, x2, y2, x3, y3, tmp);
				if (ans < tmp) ans = tmp;

				// 4. Restoration
				B[y3][x3] = 0;
			}
			B[y2][x2] = 0;
		}
		B[y1][x1] = 0;
	}
	printf("%d", ans); return 0;
}