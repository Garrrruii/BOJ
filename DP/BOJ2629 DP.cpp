#include <cstdio>
#include <vector>
using namespace std;

bool dp[15001];
vector<int> V;
int main() {
	int a[30];
	int N, M, vsize, w, nw;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

	for (int i = 0; i < N; ++i) {
		w = a[i];
		vsize = V.size();

		for (int j = 0; j < vsize; ++j) {
			nw = V[j] - w;
			if (nw < 0) nw *= (-1);
			if (!dp[nw]) V.push_back(nw), dp[nw] = true;
			nw = V[j] + w;
			if (!dp[nw]) V.push_back(nw), dp[nw] = true;
		}
		if (!dp[w]) V.push_back(w), dp[w] = true;
	}
	for (int v : V) printf("%d ", v);
	printf("\n");

	scanf("%d", &M);
	while (M--) {
		scanf("%d", &w);
		if (w <= 15000 && dp[w]) printf("Y ");
		else printf("N ");
	}

	return 0;
}
/*
5 1 1 3 4 11 => 1~20

*/