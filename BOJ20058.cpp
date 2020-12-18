//wizard shark and firestorm
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int two[7] = { 1, 2, 4, 8, 16, 32, 64 };
int A[66][66] = { 0, };
int N, L, Q;
bool vis[66][66];
queue<pair<int, int>> q;

void rotate(int y, int x, int LL) {
	int K = LL - 1;
	int tmp;
	for (int m = 0; m < LL / 2; ++m, K-=2) {
		for (int i = 0; i < K; ++i) {
			tmp = A[y + m][x + m + i];
			A[y + m][x + m + i] = A[y + m + K - i][x + m];
			A[y + m + K - i][x + m] = A[y + m + K][x + m + K - i];
			A[y + m + K][x + m + K - i] = A[y + m + i][x + m + K];
			A[y + m + i][x + m + K] = tmp;
		}
	}
}
int main() {
	scanf("%d%d", &N,&Q);
	int NN = two[N];
	for (int i = 1; i <= NN; ++i) {
		for (int j = 1; j <= NN; ++j) scanf("%d", &A[i][j]);
	}
	while (Q--) {
		scanf("%d", &L);
		int LL = two[L];
		
		if (LL > 0) {
			for (int y = 1; y < NN; y += LL) {
				for (int x = 1; x < NN; x += LL) rotate(y, x, LL);
			}
		}
		
		//printf("\nrotate\n");
		//for (int i = 1; i <= NN; ++i) {
		//	for (int j = 1; j <= NN; ++j) printf("%d ", A[i][j]);
		//	printf("\n");
		//}

		for (int y = 1; y <= NN; ++y) {
			for (int x = 1; x <= NN; ++x) {
				if (!A[y][x]) continue;
				int CNT = ((A[y - 1][x]) ? 1 : 0) + ((A[y + 1][x]) ? 1 : 0)
					+ ((A[y][x - 1]) ? 1 : 0) + ((A[y][x + 1]) ? 1 : 0);
				if (CNT < 3) q.push({ y,x });
			}
		}
		while (!q.empty()) {
			A[q.front().first][q.front().second]--; q.pop();
		}

		//printf("\nmelt\n");
		//for (int i = 1; i <= NN; ++i) {
		//	for (int j = 1; j <= NN; ++j) printf("%d ", A[i][j]);
		//	printf("\n");
		//}
	}
	int SUM = 0, ANS = 0;
	for (int y = 1; y <= NN; ++y) {
		for (int x = 1; x <= NN; ++x) {
			if (!A[y][x]) continue;
			SUM += A[y][x];
			if (vis[y][x]) continue;
			int TMP = 1;
			q.push({ y,x }); vis[y][x] = true;
			while (!q.empty()) {
				int cy = q.front().first;
				int cx = q.front().second; q.pop();
				if (A[cy - 1][cx] && !vis[cy - 1][cx]) q.push({ cy - 1,cx }), vis[cy - 1][cx] = true, TMP++;
				if (A[cy + 1][cx] && !vis[cy + 1][cx]) q.push({ cy + 1,cx }), vis[cy + 1][cx] = true, TMP++;
				if (A[cy][cx - 1] && !vis[cy][cx - 1]) q.push({ cy,cx - 1 }), vis[cy][cx - 1] = true, TMP++;
				if (A[cy][cx + 1] && !vis[cy][cx + 1]) q.push({ cy,cx + 1 }), vis[cy][cx + 1] = true, TMP++;
			}
			ANS = max(ANS, TMP);
		}	
	}
	printf("%d\n%d", SUM, ANS); return 0;
}
