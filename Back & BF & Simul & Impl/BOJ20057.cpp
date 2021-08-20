//wizard shark and tornado
//tlqjf ╧╧╬ъ
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, ANS = 0;
int map[499][499];
int x, y;
int a1, a2, a5, a7, a10, sand;

void move(int y, int x, int a) {
	if (!a) return;
	if (y < 0 || y >= N || x < 0 || x >= N) ANS += a;
	else map[y][x] += a;
}
void tornado(int k) { //dir=-1: аб, го  dir=1: ©Л, ╩С
	int x1, x2, x3, x4, y1, y2, y3, y4;
	for (int s = 0, dir = -1; s < 2; s++, k++, dir = 1) {
		for (int t = 0; t < k; t++) {
			x += dir;
			sand = map[y][x];
			if (!sand) continue;

			map[y][x] = 0; a10 = (int)(sand * 0.1);
			a1 = (int)(sand * 0.01); a7 = (int)(sand * 0.07);
			a5 = (int)(sand * 0.05); a2 = (int)(sand * 0.02);
			sand -= (a5 + 2 * (a1 + a2 + a7 + a10));

			x1 = x - dir; x2 = x + dir; x3 = x2 + dir;
			y1 = y + dir; y2 = y1 + dir; y3 = y - dir; y4 = y3 - dir;

			move(y2, x, a2);
			move(y1, x2, a10); move(y1, x, a7); move(y1, x1, a1);
			move(y, x2, sand); move(y, x3, a5);
			move(y3, x2, a10); move(y3, x, a7); move(y3, x1, a1);
			move(y4, x, a2);
		}
		for (int t = 0; t < k; t++) {
			y -= dir;

			sand = map[y][x];
			if (!sand) continue;

			map[y][x] = 0; a10 = (int)(sand * 0.1);
			a1 = (int)(sand * 0.01); a7 = (int)(sand * 0.07);
			a5 = (int)(sand * 0.05); a2 = (int)(sand * 0.02);
			sand -= (a5 + 2 * (a1 + a2 + a7 + a10));

			y1 = y + dir; y2 = y - dir; y3 = y2 - dir;
			x1 = x + dir; x2 = x1 + dir; x3 = x - dir; x4 = x3 - dir;

			move(y, x2, a2);
			move(y2, x1, a10); move(y, x1, a7); move(y1, x1, a1);
			move(y2, x, sand); move(y3, x, a5);
			move(y2, x3, a10); move(y, x3, a7); move(y1, x3, a1);
			move(y, x4, a2);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &map[i][j]);
	}

	M = N / 2;
	x = y = M;
	for (int k = 1; k < N; k += 2) tornado(k);

	while (x > 0) {
		x--;

		sand = map[0][x];
		if (!sand) continue;

		map[0][x] = 0;
		a10 = (int)(sand * 0.1);
		a1 = (int)(sand * 0.01); a7 = (int)(sand * 0.07);
		a5 = (int)(sand * 0.05); a2 = (int)(sand * 0.02);
		sand -= (a5 + 2 * (a1 + a2 + a7 + a10));

		map[1][x] += a7; map[1][x + 1] += a1; map[2][x] += a2;
		ANS += (a1 + a2 + a7 + a10);

		if (x > 1) {
			map[0][x - 1] += sand; map[0][x - 2] += a5;
			map[1][x - 1] += a10;
		}
		else if (x == 1) {
			map[0][0] += sand; ANS += a5;
			map[1][0] += a10;
		}
		else ANS += (sand + a5 + a10);
	}
	printf("%d\n", ANS);
	return 0;
}