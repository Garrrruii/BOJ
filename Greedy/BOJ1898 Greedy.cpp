#include <cstdio>
using namespace std;
// 다음을 만족하며 오름차순으로 가장 앞에 오는 수열 A는 무엇인가?
// 1. A는 1~n을 나열한 수열
// 2. |S[i]-A[i]| < 2

int pos[50001];
int A[50001];
int main() {
	int N, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &tmp), pos[tmp] = i;

	A[pos[N]] = N;
	for (int i = N - 1; i; --i) {
		if (pos[i + 1] < pos[i]) {
			A[pos[i + 1]] = i, A[pos[i]] = i + 1;
			pos[i] = 987654;
		}
		else A[pos[i]] = i;

		//for (int i = 0; i < N; ++i) printf("%d ", A[i]);
		//printf("\n");
	}
	for (int i = 0; i < N; ++i) printf("%d\n", A[i]);
	return 0;
}
/*
8 8 5 7 3 6 4 2 1
( 7 4 8 2 6 5 3 1 )

8 2 8 5 7 1 6 3 4
( 1 7 4 8 2 6 3 5 )

8 1 3 2 4 6 7 5 8
( 1 2 3 4 5 7 6 8 )

8 1 5 4 3 2 8 7 6
( 1 4 5 2 3 7 8 6 )

8 8 3 6 7 2 5 4 1
( 7 2 5 8 3 6 4 1 )
*/