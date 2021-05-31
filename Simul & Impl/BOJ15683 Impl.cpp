#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int i, j, n, r;
};
vector<node> cctv;

vector<vector<int>> dir = { {}, {0}, {0,2}, {0,1}, {0,1,2}, {0,1,2,3} };
int R[6] = { 0,4,2,4,4,1 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N, M, K;
int B[8][8];
int choosedir(int k) {
	if (k == K) {
		for (node cc : cctv) {
			// cc.n	 cctv number
			// cc.r  cctv rotate dir
			// dir[cc.n][.]+cc.r = safe
			// make vis true where 1)cctv 2)wall 3)safe area

			for (int d : dir[cc.n]) {
				int didx = (d + cc.r) % 4;
				int x = cc.j + dx[didx], y = cc.i + dy[didx];
				while (0 <= x && x < M && 0 <= y && y < N && B[y][x]<6) {
					if(!B[y][x]) B[y][x] = -1;
					x += dx[didx], y += dy[didx];
				}
			}
		}

		int ret = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (!B[i][j]) ret++;
				else if (B[i][j] < 0) B[i][j] = 0;
			}
		}
		
		return ret;
	}

	int ret = choosedir(k + 1);
	for (int r = 1; r < R[cctv[k].n]; ++r) {
		cctv[k].r = r;
		int tmp = choosedir(k + 1);
		ret = (ret < tmp) ? ret : tmp;
	}
	cctv[k].r = 0;
	return ret;
}
int main() {
	int tmp;
	
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {		
		for (int j = 0; j < M; ++j) {
			scanf("%d", &tmp);
			B[i][j] = tmp;
			if (tmp && tmp < 6) cctv.push_back({ i,j,tmp,0 });
		}
	}
	K = cctv.size();

	printf("%d", choosedir(0)); return 0;
}
/*		for (node cc : cctv) printf("%d(%d) ", cc.n, cc.r);
		printf("\n");
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) printf("%2d ", B[i][j]);
			printf("\n");
		}
		printf("\n");
*/