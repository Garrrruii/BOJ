#include <cstdio>
using namespace std;

int a[250000];
int fen[65537];
void upd_(int aidx, int bidx) {	
	while (aidx < 65537) fen[aidx]++, aidx += (aidx & -aidx);
	while (bidx < 65537) fen[bidx]--, bidx += (bidx & -bidx);
}
int sum_(int idx) {
	int res = 0;
	while (idx) res += fen[idx], idx -= (idx & -idx);
	return res;
}
int main() {
	long long ANS = 0;
	int N, K, i = 0;
	scanf("%d%d", &N,&K);

	int M = (K + 1) >> 1;
	for (; i < K; ++i) scanf("%d", &a[i]), a[i]++, upd_(a[i], 65537);
	int left = 1, right = 65536, mid = 32768;
	while (left < right) {
		if (sum_(mid) < M) left = mid + 1;
		else right = mid;
		mid = (left + right) >> 1;
	}
	ANS += (long long)mid; //printf(" +%d\n", mid - 1);
	for (int j = 0; i < N; ++i, ++j) {
		scanf("%d", &a[i]), a[i]++, upd_(a[i], a[j]);

		left = 1, right = 65536, mid = 32768;
		while (left < right) {
			if (sum_(mid) < M) left = mid + 1;
			else right = mid;
			mid = (left + right) >> 1;
		}
		ANS += (long long)mid; //printf(" +%d\n", mid - 1);
	}
	ANS -= (long long)(N - K + 1);
	printf("%lld", ANS); return 0;
}
/*
22 7
4 3 9 5 3 6 0 2 8 4 7 9 3 8 5 7 5 9 8 3 1 1
89
*/