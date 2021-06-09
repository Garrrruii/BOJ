#include <cstdio>
#include <algorithm>
using namespace std;

int dp[751][751][2];	//¢Ø¢Ö
int main() {
	int R, C, k, ANS = 0;
	char row[751];

	scanf("%d%d", &R, &C);

	scanf("%s", &row);
	for (int j = 0; j < C; ++j)
		if (row[j]=='1') dp[0][j][0] = dp[0][j][1] = ANS = 1;
	for (int i = 1; i < R; ++i) {
		scanf("%s", &row);
		if (row[0] == '1') dp[i][0][0] = 1, dp[i][0][1] = dp[i - 1][1][1] + 1;
		for (int j = 1; j < C; ++j) {
			if (row[j]=='0') continue;
			
			dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
			dp[i][j][1] = dp[i - 1][j + 1][1] + 1;
			k = min(min(dp[i][j][0], dp[i][j][1]) - 1, min(i >> 1, min(j, C - j - 1)));
			
			while (k >= ANS) {
				if (dp[i - k][j - k][1] <= k || dp[i - k][j + k][0] <= k) k--;
				else {
				//	printf("(%d,%d), ans=%d\n", i, j, k + 1);
					ANS = k + 1; break;
				}
			}
		}
	}

/*	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) printf("%d %d  ", dp[i][j][0], dp[i][j][1]);
		printf("\n");
	}*/
	printf("%d", ANS); return 0;
}
/*
(4) 8 7
1010101
0101010
1010101
0101111
1011111
0101010
1111111
1111100

(4) 9 10
0000000000
0001010001
0010101011
0101010100
1010001001
0100000100
0010001010
0001010101
0000100010

(3) 6 18
000000000001010000
101010001000100000
010111110101010100
001000100010101000
010100010100010100
001010001000001000
*/