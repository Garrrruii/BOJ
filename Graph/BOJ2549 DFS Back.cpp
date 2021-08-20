#include <cstdio>

int a[5][5], atmp[5], mov[9][3], mtmp[9][3], ANS = 8;
int extra[17] = { 0,5,5,5,1,5,5,2,2,5,3,5,3,4,5,5,4 };
/*int extra_move(int diff) { //= extra[diff]
	// diff: 답과의 차이
	// 현재 답과 틀린 개수에 따라 움직일 횟수가 정해짐
	// 따라서 diff에 따라 마저 움직일 횟수를 정한다.
	if (diff == 4) return 1;
	else if (diff == 7 || diff == 8) return 2;
	else if (diff == 10 || diff == 12) return 3;
	else if (diff == 13 || diff == 16) return 4;
	else return 5;
}*/
void rotate_tile(int idx, int k) {
	if (idx < 4) {
		for (int i = 0; i < 4; i++) atmp[(i + k) % 4] = a[idx][i];
		for (int i = 0; i < 4; i++) a[idx][i] = atmp[i];
	}
	else {
		for (int i = 0; i < 4; i++) atmp[(i + k) % 4] = a[i][idx % 4];
		for (int i = 0; i < 4; i++) a[i][idx % 4] = atmp[i];
	}
}
void dfs(int cnt) {
	int diff = 0;
	for (int i = 0, num = 1; i < 4; i++) { // 틀린 갯수를 구함
		for (int j = 0; j < 4; j++, num++) if (a[i][j] != num) diff++;
	}

	// 지금이 정답
	if (!diff) { 
		ANS = cnt;
		for (int i = 0; i < cnt; i++) {
			mov[i][0] = mtmp[i][0]; mov[i][1] = mtmp[i][1]; mov[i][2] = mtmp[i][2];
		}
		return;
	}

	// 현재 ANS가 더 나음 => 굳이 X
	if (cnt + extra[diff] >= ANS) return;
	
	// 움직일만 하다
	for (int i = 0; i < 8; i++) {         // i행(0~3)/i열(4~7) 선택
		for (int k = 1; k < 4; k++) {     // k칸 이동
			if (i < 4) mtmp[cnt][0] = 1, mtmp[cnt][1] = i + 1, mtmp[cnt][2] = k;
			else mtmp[cnt][0] = 2, mtmp[cnt][1] = i - 3, mtmp[cnt][2] = k;

			rotate_tile(i, k);
			dfs(cnt + 1);
			rotate_tile(i, 4 - k);
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) scanf("%d", &a[i][j]);
	}

	dfs(0);

	printf("%d\n", ANS);
	for (int i = 0; i < ANS; i++) printf("%d %d %d\n", mov[i][0], mov[i][1], mov[i][2]);
	
	return 0;
}