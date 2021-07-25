#include <cstdio>

int a[5][5], atmp[5], mov[9][3], mtmp[9][3], ANS = 8;
int extra[17] = { 0,5,5,5,1,5,5,2,2,5,3,5,3,4,5,5,4 };
/*int extra_move(int diff) { //= extra[diff]
	// diff: ����� ����
	// ���� ��� Ʋ�� ������ ���� ������ Ƚ���� ������
	// ���� diff�� ���� ���� ������ Ƚ���� ���Ѵ�.
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
	for (int i = 0, num = 1; i < 4; i++) { // Ʋ�� ������ ����
		for (int j = 0; j < 4; j++, num++) if (a[i][j] != num) diff++;
	}

	// ������ ����
	if (!diff) { 
		ANS = cnt;
		for (int i = 0; i < cnt; i++) {
			mov[i][0] = mtmp[i][0]; mov[i][1] = mtmp[i][1]; mov[i][2] = mtmp[i][2];
		}
		return;
	}

	// ���� ANS�� �� ���� => ���� X
	if (cnt + extra[diff] >= ANS) return;
	
	// �����ϸ� �ϴ�
	for (int i = 0; i < 8; i++) {         // i��(0~3)/i��(4~7) ����
		for (int k = 1; k < 4; k++) {     // kĭ �̵�
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