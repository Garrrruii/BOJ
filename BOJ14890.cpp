//slide
#include <cstdio>
#include <algorithm>
using namespace std;

int N, L, map[100][100];
bool check(int a, bool isrow) {
//	printf("\n\n%s %d\n", (isrow) ? "row" : "col", a);
	int r, c, dr, dc;
	if (isrow) r = a, c = 0, dr = 0, dc = 1;
	else r = 0, c = a, dr = 1, dc = 0;

	/*
	1. ���θ� ����� ���̴�
		NH �� ���̰� ���� => Len++, �� ��������� Ȯ��
		�ƴϴ� => return false
	2. ���� ����� �� �ƴ�
		H-1�̴� => ���θ� ������
		H�̴� => �ϴ� �Ѿ��
		H+1�̴� => H++�ϰ� �Ѿ��
		���̰� 2 �̻� => return false
	*/

	bool slide[100][2] = { false, };//���⿡ ���ΰ� �ִ°�?
	int H = map[r][c];				//���� ����
	int NH, len = 0;				//���� ����, ���� ����
	for (int i = r + dr, j = c + dc; i < N && j < N; i += dr, j += dc) {
//		printf("%d ", len);
		if (len) {
			if (map[i][j] != NH) return false;

			len++, slide[i][dc] = slide[j][dr] = true;
			if (len == L) H = NH, len = 0;// , printf("len=L (%d,%d) ", j, i);

		}
		else {
			if (map[i][j] == H - 1) {
				NH = H - 1, len++, slide[i][dc] = slide[j][dr] = true;
				if (len == L) len = 0, H = NH;// , printf("len=L (%d,%d) ", j, i);
			}
			else if (map[i][j] == H) continue;
			else if (map[i][j] == H + 1) H++;
			else return false;
		}
	}
//	printf("%d ", len);
	if (len) return false;
	
//	printf("\n");
	H = map[r + (N - 1) * dr][c + (N - 1) * dc];
	for (int i = r + (N - 2) * dr, j = c + (N - 2) * dc; i >= 0 && j >= 0; i -= dr, j -= dc) {
//		printf("%d ", len);
		if (len) {
			if (map[i][j] != NH) return false;
			if (slide[i][dc]&&slide[j][dr]) return false;

			len++;
			if (len == L) len = 0, H = NH;// , printf("len=L (%d,%d) ", j, i);
		}
		else {
			if (map[i][j] == H - 1) {
				if (slide[i][dc]&&slide[j][dr]) return false;

				NH = H - 1, len++;
				if (len == L) len = 0, H = NH;// , printf("len=L (%d,%d) ", j, i);
			}
			else if (map[i][j] == H + 1) H++;
			else continue;
		}
	}
//	printf("%d ", len);
	if (len) return false;

//	printf(" => DONE");
	return true;
}
int main() {
	scanf("%d%d", &N,&L);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &map[i][j]);
	}
	int ANS= 0;
	for (int a = 0; a < N; ++a) {
		if (check(a, true)) ANS++;
		if (check(a, false)) ANS++;
	}

	printf("%d", ANS);
}
/*bool ava = true;
bool slide[100] = { false, };
int H = map[i][0], NH, len = 0;
for (int j = 1; j < N; ++j) {
	if (map[i][j] == H || map[i][j] == H + 1) continue;
	if (map[i][j] > H + 1 || map[i][j] < H - 1) { ava = false; break; }

	//1. ���ΰ� ���� �� => ���� ����� ����
	//2. �ִµ� ���� �ٸ� �� => ��
	//3. ���̰� ���� �� => ���� �̾ �����
	//   if ���� �� �Ǹ� H �ٲٱ�
	if (!len) NH = map[i][j], len++, slide[j] = true;
	else if (map[i][j] != NH) { ava = false; break; }
	else{
		len++, slide[j] = true;
		if (len == L) H = NH, len = 0;
	}
}
if (len || !ava) continue;

H = map[i][N - 1];
for (int j = N - 2; j >= 0; --j) {
	if (map[i][j] < H + 1) continue;

	if (!len) {
		if (slide[j]) { ava = false; break; }
		else NH = map[i][j], len++;
	}
	else if(map[i][j]!=NH) {ava=false; break; }
	else {
		if (slide[j]) { ava = false; break; }
		else len++;
		if (len == L) H = NH, len = 0;
	}
}
if (len || !ava) continue;

ANS++;
}*/