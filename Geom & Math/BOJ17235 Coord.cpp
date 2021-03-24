//Good Pizza, Great Pizza
#include <cstdio>
using namespace std;
#define MAX 2000000001
#define MIN -2000000001

int main() {
	int N;
	long long mina = MAX, maxa = MIN, minb = MAX, maxb = MIN, x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", &x, &y);
		long long a = x - y;
		long long b = x + y;
		if (mina > a) mina = a;
		if (maxa < a) maxa = a;
		if (minb > b) minb = b;
		if (maxb < b) maxb = b;
	}
	long long L = (maxa - mina > maxb - minb) ? maxa - mina : maxb - minb;
	if (L % 2) printf("%.1Lf\n", ((long double)L / (long double)2) * (long double)L);
	else printf("%lld\n", (L / 2) * L);
	return 0;
}
/*
6
200000000 0
300000000 0
0 -100000000
100000000 100000000
100000000 300000000
-100000000 100000000

125000000000000000

*/