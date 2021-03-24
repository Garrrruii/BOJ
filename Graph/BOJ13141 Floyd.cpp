#include <cstdio>
#include <algorithm>
using namespace std;

int e[201][201], E[201][201];
int main() {
	int N, M, a, b, c;

	// Get Input
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) e[i][j] = 987654321;
		e[i][i] = 0;
	}
	while (M--) {
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = min(e[a][b], c);
		E[a][b] = E[b][a] = max(E[a][b], c);
	}

	// Floyd-Warshall
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j)
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
		}
	}

	// Find Answer
	int ANS = 987654321, TMP;
	for (int n = 1; n <= N; ++n) {
		// Find max dist when we burn "n"

		// First I used Q but we dont need to.
		// time or burning E[i][j] = A + (E[i][j]-(A-B))/2 = (A+B+E[i][j])/2
		// where A=max(e[n][i],e[n][j]), B=min(e[n][i],e[n][j])
		// (can calculate without Q)
		TMP = 0;
		for (int i = 1; i <= N; ++i) {
			int eni = e[n][i];
			for (int j = i; j <= N; ++j) {
				if (!E[i][j]) continue;
				TMP = max(TMP, eni + e[n][j] + E[i][j]);
			}
		}
		ANS = min(ANS, TMP);
	}
	printf("%.1f", (double)ANS / 2.0);

	return 0;
}
/*
4 11
1 3 2 1 3 4 1 3 12
1 2 4 1 2 6 1 2 8
4 4 2 3 3 6
3 4 1 2 4 2 2 3 5
*/