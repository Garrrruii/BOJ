#include <cstdio>
#include <queue>
#define INF 987654321
using namespace std;

struct node {
	int cnt, a, b;
};
queue<node> Q;
int map[11];
int ANS = INF;
void turnoff(int cnt, int row, int up, int a) {
	int b = map[row + 1];

	// 0        i        9
	// 0 1  i-1 i i+1  8 9
	// 0        i        9
	if (up & 1) a ^= 3, b ^= 1, cnt++;
	for (int A = 7, B = 2; B < 512; A <<= 1, B <<= 1) {
		if (up & B) a ^= A, b ^= B, cnt++;
	}
	if (up & 512) a ^= 768, b ^= 512, cnt++;

	if (row == 9) {
		if (a == 0) ANS = min(ANS, cnt);
	}
	else turnoff(cnt, row + 1, a, b);
}
void firstrow() {
	// 0 1  i-1 i i+1  8 9
	// 0        i        9
	Q.push({ 0,map[0],map[1] });
	Q.push({ 1,map[0] ^ 3,map[1] ^ 1 });

	int cnt, a, b;
	for (int A = 7, B = 2; B < 512; A <<= 1, B <<= 1) {
		int qsize = Q.size();
		while (qsize--) {
			a = Q.front().a; b = Q.front().b;
			cnt = Q.front().cnt; Q.pop();

			Q.push({ cnt,a,b });
			Q.push({ cnt + 1,a ^ A,b ^ B });
		}
	}

	while (!Q.empty()) {
		a = Q.front().a; b = Q.front().b;
		cnt = Q.front().cnt; Q.pop();

		turnoff(cnt, 1, a, b);
		turnoff(cnt + 1, 1, a ^ 768, b ^ 512);
	}
}
int main() {
	char inp[11];
	for (int i = 0; i < 10; ++i) {
		scanf("%s", &inp);
		for (int j = 0; j < 10; ++j) if (inp[j] == 'O') map[i] |= (1 << j);
	}
	firstrow();

	printf("%d", (ANS == INF) ? 0 : ANS);
	return 0;
}
/*
#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
#O######O#
#OO####OOO
O#######O#
6
*/