// same as BOJ 1509
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> pi[2000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int dp[2000];
	string S;
	cin >> S;
	int N = S.size();

	pi[0].push_back(0);
	for (int cur = 1; cur < N; ++cur) {
		pi[cur].push_back(cur);
		if (S[cur] == S[cur - 1]) pi[cur].push_back(cur - 1);
		for (int prv : pi[cur - 1]) {
			if (prv>0 && S[cur] == S[prv - 1]) pi[cur].push_back(prv - 1);
		}
	}

	dp[0] = 1;
	for (int cur = 1; cur < N; ++cur) {
		dp[cur] = cur + 1;
		for (int prv : pi[cur]) {
			if (prv) dp[cur] = min(dp[cur], dp[prv - 1] + 1);
			else { dp[cur] = 1; break; }
		}
	}

	cout << dp[N - 1]; return 0;
}