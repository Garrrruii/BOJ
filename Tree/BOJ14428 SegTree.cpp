#include <cstdio>
using namespace std;
// 1 i v	Ai->v
// 2 i j	Ai~Aj, print minimal idx of minimal value
// idx: 1 2 3...

long long A[100001];	//Ai<=10^9
int T[262150];			//2^18

int Query(int n, int s, int e, int i, int j) {
	if (s == i && e == j) return T[n];

	n <<= 1;
	int m = (s + e) / 2;
	if (j <= m) return Query(n, s, m, i, j);
	else if (i > m) return Query(n + 1, m + 1, e, i, j);
	else {
		int L = Query(n, s, m, i, m);
		int R = Query(n + 1, m + 1, e, m + 1, j);
		return ((A[L] <= A[R]) ? L : R);
	}
}
void Update(int n, int s, int e, int idx) {
	if (s != e) {
		n <<= 1;
	
		int m = (s + e) / 2;
		if (idx <= m) Update(n, s, m, idx);
		else Update(n + 1, m + 1, e, idx);
		
		T[n >> 1] = (A[T[n]] <= A[T[n + 1]]) ? T[n] : T[n + 1];
	}
}
int Build(int n, int s, int e) {
	if (s == e) return T[n] = s;
	
	int m = (s + e) / 2;
	int L = Build(n << 1, s, m);
	int R = Build((n << 1) + 1, m + 1, e);
	T[n] = (A[L] <= A[R]) ? L : R;

	return T[n];
}
int main() {
	int N, M, q, i, j;
	long long v;

	scanf("%d", &N);
	for (int n = 1; n <= N; ++n) scanf("%lld", &A[n]);
	Build(1, 1, N);

	scanf("%d", &M);
	while (M--) {
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d%lld", &i, &v);
			A[i] = v, Update(1, 1, N, i);
		}
		else {
			scanf("%d%d", &i, &j);
			printf("%d\n", Query(1, 1, N, i, j));
		}
	}
	
	return 0;
}
/*
for (int i = 1; i <= N; ++i) printf("%lld ", A[i]);
printf("\n");
for (int t = 1; t < 16; t <<= 1) {
	for (int i = t; i < t << 1; ++i) printf("%d ", T[i]);
	printf("\n");
}
*/	