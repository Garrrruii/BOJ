#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, unsigned int> piu;
piu P[300001];
unsigned int dp[300001][2];	//N logN

bool sortP(piu A, piu B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first < B.first;
}
int main() {
	int N, S, h, p;

	scanf("%d%d",&N,&S);
	for (int i = 1; i <= N; ++i) scanf("%d%u", &h, &p), P[i] = { h,p };
	sort(P, P+N+1,sortP);

	for (int i = 1; i <= N; ++i) {
		if (P[i].first < S) continue;
		
		auto low = upper_bound(P, P+i, pair<int,unsigned int>(P[i].first-S,1000));
		//we need 이하 중 최대, thus 초과 중 최소 보다 앞
		int j = low - P - 1;
		if (j < 0) j = 0;
		
		dp[i][0] = max(dp[j][0], dp[j][1]) + P[i].second;
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]); 
//		printf("%d, dp[%d] = %u %u \n", j,i,dp[i][0],dp[i][1]);
	}
	printf("%u", max(dp[N][0], dp[N][1])); return 0;
}
/*
6 4
15 8 8 23 10 10 17 20 20 7 26 8
(51)

7 4
8 5 14 2 19 2 15 1 20 6 10 3 17 5
(13)

6 5
2 5 6 1 12 4 10 7 5 6 8 2
(13)

	for (int i = 0; i <= N; ++i) printf("%2d ", P[i].first);
	printf("\n");
	for (int i = 0; i <= N; ++i) printf("%2u ", P[i].second);
	printf("\n\n");

	for (int i = 0; i <= N; ++i) printf("%2u ", dp[i][0]);
	printf("\n");
	for (int i = 0; i <= N; ++i) printf("%2u ", dp[i][1]);
	printf("\n\n");

*/