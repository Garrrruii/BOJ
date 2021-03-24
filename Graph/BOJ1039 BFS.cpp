//exchange
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

//choose 1<=i<j<=M, swap a[i]&a[j], where a[0]!=0;
bool vis[900001];

int main() {
	int N, K, TEN = 1;
	scanf("%d%d", &N, &K);
	queue<int> Q; Q.push(N);

	while (N) N /= 10, TEN *= 10;
	TEN /= 10;

	while (K--) {
		int qsize = Q.size();
		for (int i = 0; i < 900001; ++i) vis[i] = false;

		printf("Q.size()=%d\n", qsize);
		if (!qsize) { printf("-1"); return 0; }

		while (qsize--) {
			int cur = Q.front(); Q.pop();
			
			for (int i = 10; i < TEN; i *= 10) {
				int a = (cur / i) % 10;
				for (int j = 1; j < i; j *= 10) {
					int b = (cur / j) % 10;
					int nex = cur - (i - j) * (a - b);
					if (vis[nex - TEN]) continue;
					Q.push(nex); vis[nex - TEN] = true; printf("%d ", nex);
				}
				printf("\n");
			}
			int a = cur / TEN;
			for (int j = 1; j < TEN; j *= 10) {
				int b = (cur / j) % 10;
				if (!b) continue;
				int nex = cur - (TEN - j) * (a - b);
				if (vis[nex - TEN]) continue;
				Q.push(nex); vis[nex - TEN] = true; printf("%d ", nex);
			}
		}
	}
	int MAX = -1;
	while (!Q.empty()) MAX = max(MAX, Q.front()), Q.pop();
	if (MAX < TEN) MAX = -1;
	printf("%d", MAX); return 0;
}
