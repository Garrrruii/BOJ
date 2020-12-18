//Trun the disc
#include <cstdio>
using namespace std;


int main() {
	int disc[50][50];
	int N, M, T;
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%d", &disc[i][j]);
	}
	
	int SUM, CNT = N * M;
	while (T--) {
		int x, d, k; scanf("%d%d%d", &x, &d, &k);
		if (!d) k = M - k;

		for (int i = x - 1; i < N; i += x) { 
			int tmp[50];
			for (int j = 0; j < M; ++j) tmp[j] = disc[i][(j + k) % M];
			for (int j = 0; j < M; ++j) disc[i][j] = tmp[j];
		}
		
		//인접한 수끼리 같은 것 => 있으면 지움, 없으면 평균보다 큰 수--, 작은 수++
		SUM = 0;
		bool ava = false;
		bool vis[50][50] = { false, };
		for (int j = 0; j < M; ++j) {
			if (!disc[0][j]) continue;
			if (disc[0][j] == disc[0][(j + 1) % M])
				vis[0][j] = vis[0][(j + 1) % M] = ava = true;
			SUM += disc[0][j];
		}
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (!disc[i][j]) continue;
				if (disc[i][j] == disc[i][(j + 1) % M])
					vis[i][j] = vis[i][(j + 1) % M] = ava = true;
				if (disc[i][j] == disc[i - 1][j])
					vis[i][j] = vis[i - 1][j] = ava = true;
				SUM += disc[i][j];
			}
		}

		/*printf("\nSUM=%d CNT=%d ava=%d", SUM, CNT, ava?1:0);
		printf("\nrotating\n");
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) printf("%d ", disc[i][j]);
			printf(" ");
			for (int j = 0; j < M; ++j) printf("%d ", vis[i][j]?1:0);
			printf("\n");
		}*/
		
		if (ava) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) if (vis[i][j]) disc[i][j] = 0, CNT--;
			}
		}
		else {
			if (!CNT) break;
			double MEAN = (double)SUM / CNT;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (!disc[i][j]) continue;
					if ((double)disc[i][j] < MEAN) disc[i][j]++;
					else if ((double)disc[i][j] > MEAN) disc[i][j]--;
				}
			}
		}

		/*printf("\n");
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) printf("%d ", disc[i][j]);
			printf("\n");
		}*/
	}
	SUM = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) SUM+=disc[i][j];
	}
	printf("%d", SUM); return 0;
}