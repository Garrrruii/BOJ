#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> pi[2500];
int main() {
	int dp[2500], N = 2500;
	char s[2501];

	scanf("%s", &s);
	
	pi[0].push_back(0);
	for (int cur = 1; cur < 2500; ++cur) {
		if (s[cur] == '\0') {
			N = cur; break;
		}

		pi[cur].push_back(cur);
		if (s[cur] == s[cur - 1]) pi[cur].push_back(cur - 1);
		for (int prv : pi[cur - 1]) {
			if (s[cur] == s[prv - 1]) pi[cur].push_back(prv - 1);
		}

		//for (int p : pi[cur]) printf("%d ", p);
		//printf("\n");
	}
	dp[0] = 1;
	for (int cur = 1; cur < N; ++cur) {
		dp[cur] = cur + 1;
		for (int prv : pi[cur]) {
			if(prv) dp[cur] = min(dp[cur], dp[prv-1] + 1);
			else { dp[cur] = 1; break; }
		}
	}
	//for (int i = 0; i < N; ++i) printf("%d ", dp[i]);
	//printf("\n");

	printf("%d", dp[N - 1]); return 0;
}
/* example

CBCCABACCA
C B CCABACC A

ACCCBCCAABDBADD
A C CCBCC A ABDBA DD
*/