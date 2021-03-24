//math is fun
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
bool isp[32000];
vector<int> prime;

int main() {

	scanf("%d", &N);

	if (N < 3) { printf("%d",N); return 0; }

	for (int i = 2; i < 32000; ++i) {
		if (!isp[i]) {
			if (!(N % i)) prime.push_back(i);
			for (int j = i * i; j < 32000; j += i) isp[j] = true;
		}
	}

	int ANS = -1;
	
	for (int i = sqrt(N) + 1; i >= 1; --i) {
		if (N % i) continue;

		int x = N / i;
		int euler = x;
		for (auto p : prime) {
			if (x % p) continue;
			euler /= p; euler *= (p - 1);
		}
		if (euler == i) { ANS = x; break; }
	}
	printf("%d\n", ANS);

	return 0;
}
/*
1317120		1960
788810880	31603
18240600	4343
3604480		2816
*/
/*
존나 오래 걸림
int n = sqrt(N);
int m = N / prime[0];
for (int div = n; div <= m; ++div) {
	if (N % div) continue;

	int x = div;
	long long eulerval = (long long)N / x;
	long long eulertmp = 1;

	for (auto p : prime) {
		int pk = 1;
		while (!(x % p)) { x /= p, pk *= p; }

		eulertmp *= (pk - (pk / p));
		if (eulertmp > eulerval) break;

		if (x == 1) break;
	}
	//	printf("%d\n", (int)eulertmp);
	if (eulertmp == eulerval) { ANS = div; break; }
	else continue;
}*/