#include <cstdio>
using namespace std;

int main() {
	int N, K;
	long long D;
	scanf("%d%d%lld", &N, &K, &D);

	int r[10000][3];	//rule
	for (int k = 0; k < K; ++k) scanf("%d%d%d", &r[k][0], &r[k][1], &r[k][2]);

	int left = 1, right = N, mid = (1 + N) >> 1;
	while (left < right) {
		long long tmp = 0;
		for (int k = 0; k < K; ++k) {
			if (r[k][0] > mid) continue;
			if (r[k][1] < mid) tmp += (long long)(((r[k][1] - r[k][0]) / r[k][2]) + 1);
			else tmp += (long long)(((mid - r[k][0]) / r[k][2]) + 1);
			//if mid=130 (130-100)/10=3 +1
			//		     (130-110)/15=1 +1
			//if mid=160 (150-100)/10=5 +1
			//			 (150-110)/15=2 +1
		}
		//printf("%d %d sum[~%d]=%d\n", left, right, mid, tmp);
		if (tmp < D) left = mid + 1;
		else right = mid;
		mid = (left + right) >> 1;
	}
	printf("%d", mid); return 0;
}
// long long
// if you use sum[i], O(K*N)