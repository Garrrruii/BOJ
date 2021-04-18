#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool notp[1000001];
vector<long long> prime;
int main() {
	long long N;
	scanf("%lld", &N);

	// Find Prime <= Root(N)
	for (long long i = 2; i <= sqrt(N); ++i) {
		if (!notp[i]) {
			if (!(N % i)) prime.push_back(i);
			for (long long j = i * i; j <= 1000000; j += i) notp[j] = true;
		}
	}
	
	// Prime Factorization & Calculate Euler phi
	long long euler_phi = 1;
	for (long long p : prime) {
		int a = 0;
		while (!(N % p)) { a++, N /= p; }
		euler_phi *= ((p - 1) * pow(p, a - 1));
		//printf("%lld^%d, N=%lld\n", p, a, N);
	}
	if (N > 1) euler_phi *= (N - 1); //N must be a prime > Root(original N)

	printf("%lld\n", euler_phi);
	return 0;
}