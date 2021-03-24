// book page
#include <cstdio>
using namespace std;

int main() {
	int N, digit = 0;
	int d[11] = { 0, }, a[11] = { 0, }, b[11] = { 0, };
	int cnt[10] = { 0, }, T = 1;

	scanf("%d", &N);
	if (N < 10) {
		printf("0 ");
		for (int i = 1; i <= N; ++i) printf("1 ");
		for (int i = N + 1; i < 10; ++i) printf("0 ");
		return 0;
	}

	while (N) {
		d[digit] = N % 10; N /= 10;
		a[digit] = N; digit++;
	}
	digit--;
	for (int i = 0; i < digit; ++i, T*=10) b[i + 1] = b[i] + d[i] * T;

	int num = 0;
	for (; num <= d[0]; ++num) cnt[num] += a[0] + 1;
	for (; num < 10; ++num) cnt[num] += a[0];
	cnt[0]--;

	T = 10;
	for (int i = 1; i < digit; ++i, T*=10) {
		int inc1 = T * (a[i] + 1);
		int inc2 = inc1 - T;
		num = 0;

		for (; num < d[i]; ++num) cnt[num] += inc1;
		for (; num < 10; ++num) cnt[num] += inc2;
		cnt[0] -= T;
		cnt[d[i]] += (b[i] + 1);
	}

	for (num = 1; num < d[digit]; ++num) cnt[num] += T;
	cnt[d[digit]] += b[digit] + 1;

	for (int num = 0; num < 10; ++num) printf("%d ", cnt[num]);
	return 0;
}
