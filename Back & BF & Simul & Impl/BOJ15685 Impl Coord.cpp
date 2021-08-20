#include <cstdio>
#include <utility>
using namespace std;

int main() {
	int b[101][101] = { 0, };
	pair<int, int> c[10202];
	int N, X, Y, D, G;

	scanf("%d", &N);
	for (int n = 1; n <= N; ++n) {
		scanf("%d%d%d%d", &X, &Y, &D, &G);

		//버전0 드래곤 커브
		c[0] = { X,Y };
		c[1] = { X + "2101"[D] - '1',Y + "1012"[D] - '1' };
		b[X][Y] = b[c[1].first][c[1].second] = n;

		int A, B, clen = 2;
		while (G--) {
			//현재 버전의 드래콘 커브의 끝지점 (A,B)에 대해
			A = c[clen - 1].first;
			B = c[clen - 1].second;

			//점 c[clen-2]~c[0]을 90도 로테이션
			int j = clen, x, y;
			for (int i = clen - 2; i >= 0; --i) {
				x = A - c[i].second + B;
				y = B + c[i].first - A;
				if (b[x][y]==n) continue;
				//단순 bool로만 표시하면 안 됨. 이번 드래곤 커브에 속해있는지 판단해야

				b[x][y] = n; c[j] = { x,y }; j++;
			}
			clen = j;
		}
	}

	int ANS = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (b[i][j] && b[i][j + 1] && b[i + 1][j] && b[i + 1][j + 1]) ANS++;
		}
	}
	printf("%d", ANS); return 0;
}