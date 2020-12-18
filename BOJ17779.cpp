//Gerrymandering 2
//시간 초과 각일 것 같음,, 어케 효율적으로 하냐
#include <cstdio>
#include <algorithm>
using namespace std;

int A[21][21];
int N,ANS=40000;

void gerrymandering(int x0, int y0) {
	for (int d1 = 1; d1 < y0; ++d1) {
		int D2 = N - max(y0, x0 + d1);
		for (int d2 = 1; d2 <= D2; ++d2) {
			int a[5] = { 0, 0, 0, 0, 0 };
			//printf("x: %d y: %d, d1: %d d2: %d =>", x0, y0, d1, d2);
			for (int y = 1; y <=N; ++y) {
				for (int x = 1; x <= N; ++x) {
					if (y<y0 && x <= x0 + d1 && y + x < y0 + x0) a[0] += A[y][x];
					else if (y <= y0 - d1 + d2 && y - x < y0 - x0 - 2 * d1) a[1] += A[y][x];
					else if (x < x0 + d2 && y - x > y0 - x0) a[2] += A[y][x];
					else if (y + x > y0 + x0 + 2 * d2) a[3] += A[y][x];
					else a[4] += A[y][x];
				}
			}
			//printf("%d %d %d %d %d => ", a[0], a[1], a[2], a[3], a[4]);
			sort(a, a + 5);
			ANS = min(ANS, a[4] - a[0]);
			//printf("%d ANS=%d\n", a[4] - a[0], ANS);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) scanf("%d", &A[i][j]);
	}

	for (int y = 2; y < N; ++y) {
		for (int x = 1; x < N - 1; ++x) gerrymandering(x, y);
	}
	printf("%d", ANS); return 0;
}