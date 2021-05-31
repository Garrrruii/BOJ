#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

bool vis[300][300];
int B[300][300];
queue<pii> Q;
queue<pair<pii,int>> Melt;
int main() {
	int di[4] = { 1, -1, 0, 0 };
	int dj[4] = { 0, 0, 1, -1 };

	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &B[i][j]);
	}

	int yrs = 0;
	int cnt = 0;
	while (1) {
		// ºùÇÏ ³ìÀ» ¾ç °è»ê & µ¢¾î¸® °³¼ö °è»ê
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (B[i][j] && !vis[i][j]) {
					if (!Melt.empty()) { printf("%d", yrs); return 0; }

					vis[i][j] = true; Q.push({ i,j });
					while (!Q.empty()) {
						int ii = Q.front().first;
						int jj = Q.front().second; Q.pop();

						cnt = 0;
						for (int d = 0; d < 4; ++d) {
							int ni = ii + di[d];
							int nj = jj + dj[d];
							if (!B[ni][nj]) cnt++;
							else if (!vis[ni][nj]) vis[ni][nj]=true, Q.push({ ni,nj });
						}
						Melt.push({ {ii,jj},cnt });
					}
				}
			}
		}
		if (Melt.empty()) break;

		// ºùÇÏ ³ìÀ½
		while (!Melt.empty()) {
			int ii = Melt.front().first.first;
			int jj = Melt.front().first.second;
			int cnt = Melt.front().second; Melt.pop();
			B[ii][jj] -= cnt;
			if (B[ii][jj] < 0) B[ii][jj] = 0;
			vis[ii][jj] = false;
		}
		yrs++;

		// DEBUG
/*		printf("\n%d yrs\n", yrs);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) printf("%d ", B[i][j]);

			printf("\n");
		}
		printf("\n");*/
	}
	printf("0"); return 0;
}
/*
5 7 
0 0 0 0 0 0 0 
0 8 7 5 6 7 0
0 9 3 5 0 5 0
0 3 7 0 6 5 0
0 0 0 0 0 0 0

5 5
0 0 0 0 0
0 3 3 3 0
0 3 2 3 0
0 3 3 3 0
0 0 0 0 0
*/