//finding minimum
//pop front/back
//push only back (we don't need prev input of bigger value)
#include <cstdio>
#include <queue>
using namespace std;

//int d[5000000];
deque<pair<int, int>> M;
int main() {
	int N, L, tmp;
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		while (!M.empty() && M.front().second <= i - L) M.pop_front();	//sorted by i
		while (!M.empty() && M.back().first >= tmp) M.pop_back();		//sorted by value
		M.push_back({ tmp,i });

		//d[i] = M.front().first;
		//printf("%d,%d  %d,%d\n", M.front().first, M.front().second, M.back().first, M.back().second);

		printf("%d ", M.front().first);
	}
/*	for (int i = 0; i < N; ++i) {
		printf("%d ", d[i]);
		if (i % 10 == 9) printf("\n");
	}*/
	return 0;
}
/*
12 3
1 5 2 3 6 2 3 7 3 5 2 6

11 4
1 1000 2 3 4 5 6 1001 1002 1003 1004

100 10
83 -14 77 -15 93 35 6 -8 -51 -79 6 -73 -10 -41 3 26 40 -74 72 36
89 68 67 -71 82 0 -38 3 -33 35 9 98 -78 -42 -31 67 93 -44 89 -58
-71 73 -79 19 84 37 8 2 -15 70 -87 26 -9 80 56 -27 -38 70 96 -19
-5 25 -16 27 36 5 -54 29 13 -43 24 -5 82 45 -86 67 -66 64 -57 50
13 -22 -24 78 8 84 -37 -49 54 9 32 -40 -24 68 39 -18 -74 8 -6 39

*/

