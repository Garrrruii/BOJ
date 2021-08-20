//monominodomino2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool G[6][4], B[4][6];
int N, n, S = 0;
void Erase(char board, int num) {
	if (board == 'G') {
		for (int r = num; r > 0; --r) {
			G[r][0] = G[r - 1][0]; G[r][1] = G[r - 1][1];
			G[r][2] = G[r - 1][2]; G[r][3] = G[r - 1][3];
		}
		G[0][0] = G[0][1] = G[0][2] = G[0][3] = false;
	}
	else {
		for (int c = num; c > 0; --c) {
			B[0][c] = B[0][c - 1]; B[1][c] = B[1][c - 1];
			B[2][c] = B[2][c - 1]; B[3][c] = B[3][c - 1];
		}
		B[0][0] = B[1][0] = B[2][0] = B[3][0] = false;
	}
}
void GetScore() {
	int gr = 5;
	while (gr > 1) {
		if (G[gr][0] && G[gr][1] && G[gr][2] && G[gr][3]) {
			S++; Erase('G', gr);
		}
		else gr--;
	}
	if (G[1][0] || G[1][1] || G[1][2] || G[1][3]) {
		if (G[0][0] || G[0][1] || G[0][2] || G[0][3]) {
			for (int r = 5; r > 1; --r) {
				G[r][0] = G[r - 2][0]; G[r][1] = G[r - 2][1];
				G[r][2] = G[r - 2][2]; G[r][3] = G[r - 2][3];
			}
			G[0][0] = G[0][1] = G[0][2] = G[0][3] = false;
			G[1][0] = G[1][1] = G[1][2] = G[1][3] = false;
		}
		else { Erase('G', 5); }
	}
	int bc = 5;
	while (bc > 1) {
		if (B[0][bc] && B[1][bc] && B[2][bc] && B[3][bc]) {
			S++; Erase('B', bc);
		}
		else bc--;
	}
	if (B[0][1] || B[1][1] || B[2][1] || B[3][1]) {
		if (B[0][0] || B[1][0] || B[2][0] || B[3][0]) {
			for (int c = 5; c > 1; --c) {
				B[0][c] = B[0][c - 2]; B[1][c] = B[1][c - 2];
				B[2][c] = B[2][c - 2]; B[3][c] = B[3][c - 2];
			}
			B[0][0] = B[1][0] = B[2][0] = B[3][0] = false;
			B[0][1] = B[1][1] = B[2][1] = B[3][1] = false;
		}
		else { Erase('B', 5); }
	}
}
void Put(int t, int r, int c) {
	int gx = 0, by = 0;
	// 1  2  33
	//    2
	if (t == 1) {
		while (gx < 5 && !G[gx + 1][c]) gx++;
		G[gx][c] = true;
		while (by < 5 && !B[r][by + 1]) by++;
		B[r][by] = true;
	}
	else if (t == 2) {
		while (gx < 5 && !G[gx + 1][c] && !G[gx + 1][c + 1]) gx++;
		G[gx][c] = G[gx][c + 1] = true;
		while (by < 4 && !B[r][by + 1] && !B[r][by + 2]) by++;
		B[r][by] = true, B[r][by + 1] = true;
	}
	else {
		while (gx < 4 && !G[gx + 1][c] && !G[gx + 2][c]) gx++;
		G[gx][c] = G[gx + 1][c] = true;
		while (by < 5 && !B[r][by + 1] && !B[r + 1][by + 1]) by++;
		B[r][by] = B[r + 1][by] = true;
	}
}
int main() {
	scanf("%d", &N);
	for (n = 1; n <= N; n++) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		Put(t, x, y);
		GetScore();
	}
	int CNT = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (G[i][j]) CNT++;
			if (B[j][i]) CNT++;
		}
	}
	printf("%d\n%d", S, CNT); return 0;
}