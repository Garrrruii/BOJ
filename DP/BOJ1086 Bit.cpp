#include <string>
#include <iostream>
using namespace std;

int N, K, FIN;
string s[15];
long long dp[32768][100];

long long GCD(long long A, long long B) {
	long long R = A % B;
	return (R == 0) ? B : GCD(B, R);
}
int GetMod_s(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = (res * 10 + ((int)(s[i] - '0'))) % K;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int num[15];
	int ten[51];

	cin >> N; FIN = (1 << N) - 1;
	for (int i = 0; i < N; ++i) cin >> s[i];
	cin >> K;
	for (int i = 0; i < N; ++i) {
		num[i] = GetMod_s(s[i]);
		dp[1 << i][num[i]]++;
	}
	ten[0] = 1;
	for (int i = 1; i < 51; ++i) ten[i] = (ten[i - 1] * 10) % K;

	for (int cur = 1; cur < FIN; ++cur) {
		for (int mod = 0; mod < K; ++mod) {
			if (!dp[cur][mod]) continue;

			for (int idx = 0; idx < N; ++idx) {
				if (cur & (1 << idx)) continue;

				int nxt = cur | (1 << idx);
				int newmod = (mod * ten[s[idx].size()] + num[idx]) % K;

				dp[nxt][newmod] += dp[cur][mod];
			}
		}
	}

	long long Total = 1;
	for (long long n = 2; n <= N; ++n) Total *= n;

	if (!dp[FIN][0]) cout << "0/1";
	else if (dp[FIN][0] == Total) cout << "1/1";
	else {
		long long gcd = GCD(Total, dp[FIN][0]);
		cout << (dp[FIN][0] / gcd) << "/" << (Total / gcd);
	}
	return 0;
}
/*
3
104
4
90
27

5
1
12
23
3
101
11
*/