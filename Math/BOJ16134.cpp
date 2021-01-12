//combination
//=BOJ15791
//=BOJ13977
#include <cstdio>
#include <algorithm>
using namespace std;

long long P = 1000000007;
long long mod[4000001] = { 0, };
long long pow(long long a, int k) {
	if (k == 1) return a;

	long long ra = pow(a, k / 2);
	if (k % 2) return (a * ((ra * ra) % P)) % P;
	else return (ra * ra) % P;
}
int main() {
	mod[2] = 2;
	for (int i = 3; i < 10; ++i) mod[i] = mod[i - 1] * i;
	for (int i = 10; i < 4000001; ++i) mod[i] =mod[i-1]*i, mod[i] %= P;
	
	int M; scanf("%d", &M);
	while (M--) {
		int N, K1;
		scanf("%d%d", &N, &K1);
		int K2 = N - K1;
		if (K1 > K2) swap(K1, K2);
		if (K1 == 0) { printf("1\n"); continue; }
		if (K1 == 1) { printf("%d\n", N); continue; }

		long long A = mod[N], B = mod[K1], C=mod[K2];
		
		A *= pow(B, (int)P - 2); A %= P;
		A *= pow(C, (int)P - 2); A %= P;
		printf("%lld\n", A);
	}
	return 0;
}
/*
int main() {
	int N, R;
	scanf("%d%d", &N, &R);
	int K = N - R;
	if (R > K) swap(R, K);
	if (R == 0) { printf("1"); return 0; }
	if (R == 1) { printf("%d", N); return 0; }

	long long A = 1, B = 1;
	for (int i = N; i > K; --i) { A *= i; A %= P; }
	for (int i = R; i > 1; --i) { B *= i; B %= P; }

	A *= pow(B, (int)P - 2); A %= P;
	printf("%lld", A); return 0;
}*/