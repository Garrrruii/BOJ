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
	1. 경사로를 만드는 중이다
		NH 와 높이가 같다 => Len++, 다 만들었는지 확인
		아니다 => return false
	2. 경사로 만드는 중 아님
		H-1이다 => 경사로를 만들자
		H이다 => 일단 넘어가자
		H+1이다 => H++하고 넘어가자
		차이가 2 이상 => return false
	*/

	bool slide[100][2] = { false, };//여기에 경사로가 있는가?
	int H = map[r][c];				//평지 높이
	int NH, len = 0;				//경사로 높이, 경사로 길이
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

	//1. 경사로가 없을 때 => 경사로 만들기 시작
	//2. 있는데 높이 다를 때 => 끝
	//3. 높이가 같을 때 => 경사로 이어서 만들기
	//   if 길이 다 되면 H 바꾸기
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