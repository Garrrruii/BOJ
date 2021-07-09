#include <cstdio>
using namespace std;

long long P = 1000000007;
long long pow(long long A, int n) {
	if (n == 1) return A;
	long long tmp = pow(A, n >> 1);

	tmp *= tmp;
	tmp %= P;
	if (n & 1) return (tmp * A) % P;
	else return tmp;
}
int main() {
	int M;
	long long N, S, ANS = 0;

	scanf("%d", &M);
	while (M--) {
		scanf("%lld%lld", &N, &S);

		ANS += (S * pow(N, P - 2)) % P;
		ANS %= P;

	}
	printf("%lld", ANS);
}