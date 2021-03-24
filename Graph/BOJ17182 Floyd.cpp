//Space probe
#include <cstdio>
#include <algorithm>
using namespace std;

int d[10][10];
int N, MAX = 987654321;
bool vis[10];
void comb(int ord, int v, int val) {
	if (MAX < val) return;
	if (ord == N) { MAX = val; return; }
	//for (int i = 0; i < ord; ++i) printf(" ");
	//printf("%d %d %d\n", ord, v, val);

	for (int j = 0; j < N; j++) {
		if (vis[j]) continue;
		vis[j] = true; comb(ord + 1, j, val + d[v][j]);  vis[j] = false;
	}
}
int main() {
	int sp;	scanf("%d%d", &N, &sp);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &d[i][j]);
	}

	for (int n = 0; n < N; ++n) {
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					int tmp = d[i][k] + d[k][j];
					if (d[i][j] > tmp) d[i][j] = tmp;
				}
			}
		}
	}
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < N; ++j) printf("%d ", d[i][j]);
	//	printf("\n");
	//}
	//printf("\n");

	vis[sp] = true;	comb(1, sp, 0);

	printf("%d", MAX); return 0;
}
