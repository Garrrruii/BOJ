#include <cstdio>
#include <algorithm>
using namespace std;
//등차수열로 증가하도록
//합의 최댓값
//최대 3개 이상 밟아야
//존재X => 0

long long dp[3000][3000];
//dp[i][j] : ... aj ai 인수열 max sum
int main() {
	int N;//3000
	scanf("%d", &N);
	int a[3000];
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

	long long ANS = 0;
	// a1 a2 a3
	for (int i = 1; i < N; ++i) {	//a[j] a[i] nxt=> exist?
		int mid = a[i];
		for (int j = 0; j < i; ++j) {
			int nxt = mid + mid - a[j];
			auto low = lower_bound(a + i, a + N, nxt);
			if (*low != nxt) continue;

			long long TMP = (long long)mid * 3;
			dp[low-a][i] = TMP;
			if (ANS < TMP) ANS = TMP;
		}
	}
	// a4~
	for (int i = 1; i < N; ++i) {	// ... a[j] a[i] nxt=> exist?
		int mid = a[i];
		for (int j = 0; j < i; ++j) {
			if (!dp[i][j]) continue;

			int nxt = mid + mid - a[j];
			auto low = lower_bound(a + i, a + N, nxt);
			if (*low != nxt) continue;

			long long TMP = dp[i][j] + (long long)nxt;
			dp[low-a][i] = TMP;
			if (ANS < TMP) ANS = TMP;

		}
	}
	printf("%lld", ANS); return 0;
}
