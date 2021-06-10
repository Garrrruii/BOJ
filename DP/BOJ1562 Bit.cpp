#include <cstdio>
#include <queue>
using namespace std;
//dp[숫자존재여부][끝난숫자]=계단수 개수

//long long dp[1024][10][101]; => 9316KB
long long dp[1024][10], tmp[1024][10];

int main() {
	bool vis[1024][10];
	queue<pair<int, int>> Q;
	long long DIV = 1e9;
	int N;

	scanf("%d", &N);
	if (N < 10) { printf("0"); return 0; }

	//for (int num = 1; num < 10; ++num) dp[1 << num][num][1] = 1, Q.push({ 1 << num,num });
	for (int num = 1; num < 10; ++num) dp[1 << num][num] = 1, Q.push({ 1 << num,num });

	for (int i = 2; i < N; ++i) {
		for (int j = 0; j < 1024; ++j) {
			for (int num = 0; num < 10; ++num) vis[j][num] = false, tmp[j][num] = 0;
		}

		int qsize = Q.size();
		while (qsize--) {
			int cur = Q.front().first;
			int num = Q.front().second; Q.pop();
			//long long add = dp[cur][num][i - 1];
			long long add = dp[cur][num];

			if (num) {
				int a = num - 1;
				int nxt = cur | (1 << a);
				tmp[nxt][a] += add;
				tmp[nxt][a] %= DIV;
				if (!vis[nxt][a]) Q.push({ nxt,a }), vis[nxt][a] = true;
			}
			if (num < 9) {
				int b = num + 1;
				int nxt = cur | (1 << b);
				tmp[nxt][b] += add;
				tmp[nxt][b] %= DIV;
				if (!vis[nxt][b]) Q.push({ nxt,b }), vis[nxt][b] = true;
			}
		}

		for (int j = 0; j < 1024; ++j) {
			for (int num = 0; num < 10; ++num) dp[j][num] = tmp[j][num];
		}
	}
	long long ANS = 0;
	while (!Q.empty()) {
		int cur = Q.front().first;
		int num = Q.front().second; Q.pop();
		long long add = dp[cur][num];

		if (num) {
			int nxt = cur | (1 << num - 1);
			if (nxt == 1023) ANS += add, ANS %= DIV;
		}
		if (num < 9) {
			int nxt = cur | (1 << num + 1);
			if (nxt == 1023) ANS += add, ANS %= DIV;
		}
	}
	printf("%lld", ANS); return 0;
}