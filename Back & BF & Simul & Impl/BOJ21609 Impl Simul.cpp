#include <cstdio>
#include <vector>
using namespace std;

struct board {
	int b[20][20];
};
int N;
vector<pair<int, int>> G, tmp;
void PRINT(board B) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (B.b[i][j] < 9) printf("%2d ", B.b[i][j]);
			else printf(" . ");
		}
		printf("\n");
	}
	printf("\n");
}
void gravity(board* B) {
	int block;
	for (int j = 0; j < N; ++j) {
		int bottom = N - 1;
		for (int i = N - 1; i >= 0; --i) {
			if (B->b[i][j] > 5) continue;
			else if (B->b[i][j] < 0) bottom = i - 1;
			else {
				block = B->b[i][j]; B->b[i][j] = 9;
				B->b[bottom][j] = block; bottom--; //bottom이 작아져야 함
			}
		}
	}
}
void rotate(board* B) { //[i][j] -> [N-j-1][i]
	board A = *B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0, k = N - 1; j < N; ++j, --k) B->b[k][i] = A.b[i][j];
	}
}
int main() {
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	int M;
	board B;

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &B.b[i][j]);
	}

	int SCORE = 0;
	while (1) {
		//블록그룹 찾기
		int gi = -1, gj = -1, rnum = -1, tmp_rnum;
		int vis[20] = { 0, };
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (B.b[i][j] <= 0 || B.b[i][j]>5 || vis[i] & (1 << j)) continue;
				int color = B.b[i][j];

				//tmp 블록그룹 탐색
				tmp.clear();
				tmp.push_back({ i,j }); vis[i] |= (1 << j); tmp_rnum = 0;
				int idx = 0;
				while (idx < tmp.size()) {
					int y = tmp[idx].first;
					int x = tmp[idx].second;

					for (int d = 0; d < 4; ++d) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
						if (vis[ny] & (1 << nx) || B.b[ny][nx] < 0) continue;
						if (B.b[ny][nx] == color) tmp.push_back({ ny,nx }), vis[ny] |= (1 << nx);
						else if (!B.b[ny][nx]) tmp.push_back({ ny,nx }), vis[ny] |= (1 << nx), tmp_rnum++;
					}
					idx++;
				}
				for (pair<int, int> t : tmp) {
					if (!B.b[t.first][t.second]) vis[t.first] &= (~(1 << t.second));
				}
				if (tmp.size() < 2) continue;

				//G와 비교
				if (G.size() < tmp.size()) G = tmp, rnum = tmp_rnum, gi = i, gj = j;
				else if (G.size() == tmp.size()) {
					if (rnum < tmp_rnum) G = tmp, rnum = tmp_rnum, gi = i, gj = j;
					else if (rnum == tmp_rnum) {
						if (gi < i)  G = tmp, rnum = tmp_rnum, gi = i, gj = j;
						else if (gi == i && gj < j)  G = tmp, rnum = tmp_rnum, gi = i, gj = j;
					}
				}
			}
		}
		if(G.empty()) { printf("%d", SCORE); return 0; }

		// 블록그룹 블록 제거
		int cnt = G.size();
		SCORE += cnt * cnt;
		for (pair<int, int> g : G) B.b[g.first][g.second] = 9;
		G.clear();
		//PRINT(B);

		// 중력, 회전, 중력
		gravity(&B); //PRINT(B);
		rotate(&B);	 //PRINT(B);
		gravity(&B); //PRINT(B); printf("%d\n", SCORE);
	}
}