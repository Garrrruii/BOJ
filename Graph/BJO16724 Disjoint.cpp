#include <cstdio>
//#include <vector>
//#include <utility>
using namespace std;

//vector<pair<int, int>> v;  이거 없이도 할 수 있음.
int zone[1000][1000];
char map[1000][1001];
int main() {
	int N, M, ni, nj;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%s", &map[i]);

	int CNT = 0, NOW = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (zone[i][j]) continue;

			zone[i][j] = ++NOW;
			ni = i, nj = j;
			while (1) {
				switch (map[ni][nj]) {
				case 'D':ni++; break;
				case 'U':ni--; break;
				case 'R':nj++; break;
				case 'L':nj--; break;
				}

				if (zone[ni][nj]) {
					if (zone[ni][nj] == NOW) CNT++;
					break;
				}
				zone[ni][nj] = NOW;
			}
		}
	}
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) printf("%d ", zone[i][j]);
		printf("\n");
	}*/
	
	printf("%d", CNT); return 0;
}
/*
4 4
DRLD
DLLL
RRRU
RLRU
3
*/