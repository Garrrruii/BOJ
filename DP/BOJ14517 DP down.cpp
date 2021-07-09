#include <iostream>
#include <string>
using namespace std;

string S;
int dp[1000][1000];
int getdp(int a, int b) {
	if (a > b) return 0;
	if (dp[a][b]) return dp[a][b];
	
	int ret = getdp(a,b - 1) + 1;
	for (int i = a; i < b; ++i) {
		if (S[i] != S[b]) continue;
		ret += getdp(i + 1, b - 1) + 1;
		ret %= 10007;
	}
	dp[a][b] = ret;
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> S;
	int N = S.size();
	for (int i = 0; i < N; ++i) dp[i][i] = 1;
	for (int i = 1; i < N; ++i) dp[i-1][i] = (S[i - 1] == S[i]) ? 3 : 2;

	printf("%d\n", getdp(0, N - 1));
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) printf("%2d ", dp[i][j]);
//		printf("\n");
//	}

	return 0;
}
/*
xxyzyyz
18

xyxxyzy
25
*/