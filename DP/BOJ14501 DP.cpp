#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int s, e, p;
};
int main() {
	int N, t, p, idx = 0;
	node T[15];

	scanf("%d", &N);
	for (int n = 0; n < N;) {
		scanf("%d%d", &t, &p);
		t += n; n++;
		if (t <= N) T[idx++] = { n, t, p };
	}
	
	int dp[16] = { 0, };
	for (int i = 0; i < idx; ++i) {
		int tmp = 0;
		for (int j = 0; j < T[i].s; ++j) tmp = (tmp > dp[j]) ? tmp : dp[j];
		tmp += T[i].p;
		if (dp[T[i].e] < tmp) dp[T[i].e] = tmp;
	}
	int ANS = 0;
	for (int n = 1; n <= N; ++n) ANS = (ANS > dp[n]) ? ANS : dp[n];
	printf("%d", ANS);
	return 0;
}