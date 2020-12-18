//이상한 전깃줄
//DP로 풀었는데 nlogn으로는 풀 수 없는 걸까
//존나 생각하기 싫다,,
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, tmp, a, b;
int A[2001], B[2001];
bool map[2001][2001];
int dp[2001][2001];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &tmp); A[tmp] = i;
	}
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &tmp); B[tmp] = i;
	}
	scanf("%d", &K);
	for (int k = 0; k < K; ++k) {
		scanf("%d%d", &a, &b);
		map[A[a]][B[b]] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1] + 1);
			}
			else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", K-dp[N][M]);
	return 0;
}
/*
7 6 1 2 3 4 5 6 7 1 2 3 4 5 6 13
2 1 1 2 4 2 2 3
3 3 5 3 2 4 3 4
5 4 4 5 6 5 5 6 7 6
*/