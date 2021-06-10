#include <cstdio>
#include <queue>
using namespace std;
// 2^a <= A => a+1 자리 수
// 2^b >  B => b   자리 수
// 
// 43 => 101011
// 32 33 34 ... 43			: 43/32=1		  43-32*1+1
// 16 17 18 ~~~ 31			: 43/16=2	16*1	
//  8--15 24--31 40..43		: 43/8 =5	8*2 + 43-8*5+1
//  4--7  12--15 ...		: 43/4=10	4*5
//	2--3   6--7  ...		: 43/2=21	2*10 + 43-2*21+1
//  1 3 5 7 ... 43			:			(43+1)/2

long long f(long long N) {
	if (N < 2) return N;
	long long cnt = (N + 1) >> 1;	// 2^0

	long long k = 2;
	long long n = N;
	while (N >= k) {				// 2^1 ~
		n >>= 1;
		
		cnt += (k * (n / 2));
		if (n % 2) cnt += (N - k * n + 1);
		k <<= 1;
	}
	return cnt;
}
int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld", f(B) - f(A - 1));
	return 0;
}