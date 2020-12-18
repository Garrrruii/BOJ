//Sejin's meeting
//calculate nCm = n!/(n-m)!m! <=> ANS (mod p)
//permat's little thm: a*(a^p-2) <=> 1(mod p)
#include <cstdio>
#include <algorithm>
using namespace std;

long long P = 1000000007;
long long pow(long long a, int k) {
	if (k == 1) return a;
	
	long long ra = pow(a, k / 2);
	//printf("%lld^%d=%lld\n", a, k/2, ra);
	if (k % 2) return (a * ((ra * ra) % P)) % P;
	else return (ra * ra) % P;
}
int main() {
	int N, M;
	scanf("%d%d", &N,&M);
	int K = N - M;
	if (M > K) swap(M, K);
	if (M == 1) { printf("%d", N); return 0; }

	long long A = 1, B = 1;
	for (int i = N; i > K; --i) { A *= i; A %= P; }
	for (int i = M; i > 1; --i) { B *= i; B %= P; }

	A *= pow(B, (int)P - 2); A %= P;
	printf("%lld", A); return 0;
}