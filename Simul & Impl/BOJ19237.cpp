//adult shark
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
struct shark {
	int n, dir, y, x;

	bool operator < (const shark& A) {
		return n < A.n;
	}
};
vector<shark> S;
pair<int, int> sc[20][20];
int pos[20][20];
int ord[401][5][4];
int SEC = 0;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,-1,1,0,0 };

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp; scanf("%d", &tmp);
			if (tmp) {
				S.push_back({ tmp,0,i,j }); sc[i][j] = { K,tmp };
			}
		}
	}
	std::sort(S.begin(), S.end());

	for (int si = 0; si < M; si++) scanf("%d", &S[si].dir);
	for (int sh = 1; sh <= M; ++sh) {
		for (int d = 1; d < 5; ++d) {
			scanf("%d%d%d%d", &ord[sh][d][0], &ord[sh][d][1], &ord[sh][d][2], &ord[sh][d][3]);
		}
	}

	while (S.size() > 1 && SEC < 1001) {
		if (SEC == 1000) { SEC = -1; break; }
		SEC++;
		//상어 이동
		for (int si = 0; si < S.size(); ) {
			int s = S[si].n, d = S[si].dir;
			int y = S[si].y, x = S[si].x; pos[y][x] = 0;

			//printf("%d: {%d,%d}, dir=%d\n", s,x, y, d);
			
			int tary = -1, tarx, tard;
			for (int di = 0; di < 4; di++) {
				int nd = ord[s][d][di];
				int ny = y + dy[nd];
				int nx = x + dx[nd];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (!sc[ny][nx].first) { tary = ny, tarx = nx; tard = nd; break; }
				if (sc[ny][nx].second == s && tary < 0) tary = ny, tarx = nx, tard = nd;
			}
			//이동 가능하면 옮기고 아니면 지움
			//printf("\tmove {%d,%d}, newdir=%d ", tarx, tary, tard);
			if (pos[tary][tarx]) S.erase(S.begin() + si);
			else {
				pos[tary][tarx] = s; S[si] = { s,tard, tary, tarx };
				++si;
			}
		}
		//냄새 남은 시간--
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (sc[i][j].first) sc[i][j].first--;
			}
		}
		//새로운 냄새 기록
		for (int si = 0; si < S.size(); si++) sc[S[si].y][S[si].x] = { K,S[si].n };

		//printf("SEC=%d\n", SEC);
		//for (int i = 0; i < N; ++i) {
		//	for (int j = 0; j < N; ++j) printf("%d %d  ", sc[i][j].first, sc[i][j].second);
		//	printf("\n");
		//}
		//printf("\n");
	}
	printf("%d", SEC); return 0;
}