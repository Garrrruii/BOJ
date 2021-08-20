//2x2x2 cube
#include <cstdio>
using namespace std;

int main() {
	int cube[24];
	int pair[3][2] = { {0,2},{1,5},{3,4} };
	int side[6][8] = { {4,5,16,17,20,21,12,13},{3,2,13,15, 8, 9,18,16},
					   {6,7,18,19,22,23,14,15},{2,0,21,23,10, 8, 6, 4},
					   {3,1,20,22,11, 9, 7, 5},{1,0,12,14,10,11,19,17} };
	for (int i = 0; i < 24; ++i) scanf("%d", &cube[i]);
	for (int i = 0; i < 3; ++i) {
		int face1 = pair[i][0], n = 4 * face1;
//		printf("\ncheck face1:%d\n", face1); 
		if (cube[n] != cube[n + 1] || cube[n] != cube[n + 2] || cube[n] != cube[n + 3]) continue;
		int face2 = pair[i][1], m = 4 * face2;
//		printf("check face2:%d\n", face2);
		if (cube[m] != cube[m + 1] || cube[m] != cube[m + 2] || cube[m] != cube[m + 3]) { printf("0"); return 0; }
		
		int s[4][2] = { 0, };
		for (int i = 0; i < 7; i += 2) {
//			printf("check side %d\n", i / 2);
			if (cube[side[face1][i]] != cube[side[face1][i + 1]]) { printf("0"); return 0; }
			if (cube[side[face2][i]] != cube[side[face2][i + 1]]) { printf("0"); return 0; }
			s[i / 2][0] = cube[side[face1][i]]; s[i / 2][1] = cube[side[face2][i]];
		}
//		for (int i = 0; i < 8; ++i) printf("%d ", cube[side[face1][i]]);
//		printf("\n");
//		for (int i = 0; i < 8; ++i) printf("%d ", cube[side[face2][i]]);
//		printf("\n");

		if ((s[0][0] == s[3][1] && s[1][0] == s[0][1] && s[2][0] == s[1][1] && s[3][0] == s[2][1])
			|| (s[0][0] == s[1][1] && s[1][0] == s[2][1] && s[2][0] == s[3][1] && s[3][0] == s[0][1])) {
			printf("1"); return 0;
		}
		else { printf("0"); return 0; }
	}
	printf("0"); return 0;
}
/* 1
6 2 6 2 2 1 2 1 1 3 1 3 4 4 4 4 5 5 5 5 6 3 6 3
5 3 5 3 2 5 2 5 6 2 6 2 4 4 4 4 1 1 1 1 6 3 6 3
4 4 1 1 6 6 6 6 3 3 2 2 3 4 3 4 2 1 2 1 5 5 5 5
1 1 1 1 2 2 3 3 6 6 6 6 5 5 2 2 3 3 4 4 4 4 5 5

  0
2 2 6 6 5 5 5 5 2 2 6 6 1 3 1 3 1 3 1 3 4 4 4 4
*/
