#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
dp[x][y][k][방향], k = 방향 전환 횟수

dp[x][y][k][가로]
= min of dp[x - 1][y][k][가로]     + 오른쪽[x - 1][y]
		 dp[x][y - 1][k - 1][세로] + 아래쪽[x][y - 1]

dp[x][y][k][세로]
= min of dp[x][y - 1][k][세로]     + 아래쪽[x][y - 1]
		 dp[x - 1][y][k - 1][가로] + 오른쪽[x - 1][y]
*/

int dp[101][101][210][2];	//dp[x][y][방향 전환 횟수][방향]
int go_r[101][100];			//go right
int go_d[100][101];			//go down

void solve() {
	// Initiation
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0][0] = dp[0][0][0][1] = 0;

	int M, N, L, G; //map, time, gas
	int ANS = 1e9 + 7;

	// Get Input
	scanf("%d%d%d%d", &M, &N, &L, &G);
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N - 1; ++j) scanf("%d", &go_r[i][j]);
	for (int i = 0; i < M - 1; ++i)
		for (int j = 0; j < N; ++j) scanf("%d", &go_d[i][j]);

	// Build DP
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 210; ++k) {
				if (i + 1 < M) {
					dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][0] + go_d[i][j]);
					dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][1] + go_d[i][j]);
				}
				if (j + 1 < N) {
					dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][1] + go_r[i][j]);
					dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], dp[i][j][k][0] + go_r[i][j]);
				}
			}
		}
	}

	// Find Ans
	for (int k = 0, tmp = (M + N - 2) * L; k < 210; ++k, ++tmp) {
		if (dp[M - 1][N - 1][k][0] <= G) ANS = min(ANS, tmp); //(M+N-2)*L + k
		if (dp[M - 1][N - 1][k][1] <= G) ANS = min(ANS, tmp);
	}
	if (ANS > 1e9) printf("-1\n");
	else printf("%d\n", ANS);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}