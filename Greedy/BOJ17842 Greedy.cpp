#include <cstdio>
using namespace std;

int e[200000];
int main() {
	int N, a, b;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) scanf("%d%d", &a, &b), e[a]++, e[b]++;

	int cnt = 1;
	for (int i = 0; i < N; ++i) if (e[i] == 1) cnt++;
	
	printf("%d", cnt>>1); return 0;
}
/*
12  0 2 1 2 2 3 2 8 3 4 3 5 3 6 3 7 3 11 7 9 10 7
(5)

13  0 1 5 1 4 1 3 1 2 1 2 6 6 7 7 12 6 8 11 8 10 8 9 8
(4)

15  0 1 1 2 3 2 4 2 5 2 6 2 5 7 11 7 10 7 7 8 7 9 10 12 10 13 13 14 14 15
(5)
*/