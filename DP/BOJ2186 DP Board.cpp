#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int prv[100][100], cur[100][100];
	int N, M, K, ans;
	char b[100][101];
	string s;

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) cin >> b[i];
	cin >> s;
	int idx = s.size() - 1;

	//dp[*][*][idx]
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
		if (b[i][j] == s[idx]) prv[i][j] = 1;

	//dp[*][*][t-1] where t=idx~1
	int di[4] = { 1,-1,0,0 }, dj[4] = { 0,0,1,-1 };
	for (int t = idx; t; --t) {
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			if (b[i][j] != s[t - 1]) continue;

			ans = 0;
			for (int d = 0; d < 4; ++d) {
				int ni = i + K * di[d];
				int nj = j + K * dj[d];
				for (int k = K; k; --k, ni -= di[d], nj -= dj[d]) {
					if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
					if (b[ni][nj] == s[t]) ans += prv[ni][nj];
				}
			}
			cur[i][j] = ans;
		}
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
			prv[i][j] = cur[i][j];
	}

	ans = 0;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
		if (b[i][j] == s[0]) ans += cur[i][j];
	cout << ans; return 0;
}
/*
for (int i = 0; i < N; ++i) {
	for (int t = 0; t <= idx; ++t) {
		for (int j = 0; j < M; ++j) cout << dp[i][j][t] << " ";
		cout << "  ";
	}
	cout << "\n";
}
cout << '\n';

4 5 2
KAKTA
XEASK
YRWUT
ZBQPA
KAT

*/