//sqaure nono number
#include <cstdio>
using namespace std;

bool sq[1000001];

int main() {
	long long m, M;
	scanf("%lld%lld", &m, &M);

	for (long long i = 2; i * i <= M; i++) {
		long long i2 = i * i;
		long long tar = m / i2;
		tar *= i2;
		if (tar < m) tar += i2;
		for (long long j = tar; j <= M; j += i2) {
			sq[j - m] = true;
		}
	}
	int ANS = 0;
	for (int i = 0; i < M - m + 1; i++) {
		if (!sq[i]) ANS++;
	}
	printf("%d", ANS);

	return 0;
	/* RUNTIME ERROR
		long long m, M;
		long long sqM = sqrt(M);
		scanf("%lld%lld", &m, &M);

		for (long long i = 2; i <= sqrt(M); ++i) {
			long long i2 = i * i;
			long long tar = (m / i2) * i2;
			while (tar < m) tar += i2;
			for (long long j = tar; j <= M; j += i2) {
				sq[j - m] = true;
			}
		}
		int ANS = 0;
		for (int i = 0; i < M - m + 1; ++i) {
			if (!sq[i]) ANS++;
		}
		printf("%d", ANS); return 0;
	*/
}