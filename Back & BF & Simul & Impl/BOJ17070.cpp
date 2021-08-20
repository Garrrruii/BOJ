//moving pipe 1
//tried BFS but failed
//faster and easier with DP
//increase next from here (consider the direction you move)
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

bool h[16][16];
int N, inp;
int dp[3][16][16] = { 0, };

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inp);
			if (inp) h[i][j] = true;
		}
	}
	if (!h[0][2]) {
		dp[0][0][2]++;
		if (!h[1][1] && !h[1][2]) dp[2][1][2]++;
	}
	for (int k = 1; k < N - 2; k++) {
		for (int x = k + 1, y = 0; y < k; y++) {
			if (h[y][x]) continue;
			if (!h[y][x + 1]) dp[0][y][x + 1] += (dp[0][y][x] + dp[2][y][x]);
			if (!h[y + 1][x]) {
				dp[1][y + 1][x] += (dp[1][y][x] + dp[2][y][x]);
				if (!h[y + 1][x + 1] && !h[y][x + 1]) dp[2][y + 1][x + 1] += (dp[0][y][x] + dp[1][y][x] + dp[2][y][x]);
			}
		}
		for (int x = 1, y = k; x <= k + 1; x++) {
			if (h[y][x]) continue;
			if (!h[y][x + 1]) dp[0][y][x + 1] += (dp[0][y][x] + dp[2][y][x]);
			if (!h[y + 1][x]) {
				dp[1][y + 1][x] += (dp[1][y][x] + dp[2][y][x]);
				if (!h[y + 1][x + 1] && !h[y][x + 1]) dp[2][y + 1][x + 1] += (dp[0][y][x] + dp[1][y][x] + dp[2][y][x]);
			}
		}	
	}
	for (int x = 1, y = N - 2; x < N - 1; x++) {
		if (h[y][x]) continue;
		if (!h[y][x + 1]) dp[0][y][x + 1] += (dp[0][y][x] + dp[2][y][x]);
		if (!h[y + 1][x]) {
			dp[1][y + 1][x] += (dp[1][y][x] + dp[2][y][x]);
			if (!h[y + 1][x + 1] && !h[y][x + 1]) dp[2][y + 1][x + 1] += (dp[0][y][x] + dp[1][y][x] + dp[2][y][x]);
		}
	}
	for (int x = N - 1, y = 0; y < N - 1; y++) {
		if (!h[y][x] && !h[y+1][x]) dp[1][y + 1][x] += (dp[1][y][x] + dp[2][y][x]);
	}
	for (int x = 1, y = N - 1; x < N - 1; x++) {
		if (!h[y][x] && !h[y][x+1]) dp[0][y][x + 1] += (dp[0][y][x] + dp[2][y][x]);
	}
 /*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", dp[0][i][j]);
		}
		printf(" ");
		for (int j = 0; j < N; j++) {
			printf("%d ", dp[1][i][j]);
		}
		printf(" ");
		for (int j = 0; j < N; j++) {
			printf("%d ", dp[2][i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	printf("%d", dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1]); return 0;
}