//virus
//do KMP for forward subseq or backward subseq
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, K, M;
int a[100][1001];
bool kmp(int* s, int* t) {
	vector<int> res;
	int n = s[0];
	int m = K;

	//get pi
	vector<int> pi(m, 0);
	for (int i = 1, j = 0; i < m; ++i) {
		while (j > 0 && t[i] != t[j]) j = pi[j - 1];
		if (t[i] == t[j]) pi[i] = ++j;
	}

	//kmp
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j > 0 && s[i] != t[j]) j = pi[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) return true; //no need to keep kmp
			else j++;
		}
	}
	return false; //no any same subseq
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &M); a[i][0] = M;
		for (int j = 1; j <= M; ++j) scanf("%d", &a[i][j]);
	}
	for (int k = 1; k <= a[0][0] + 1 - K; ++k) {
		int forw[1000], backw[1000];
		for (int i = 0; i < K; ++i) {
			forw[i] = backw[K - 1 - i] = a[0][k + i];
		}
		int idx = 1;
		while (kmp(a[idx], forw) || kmp(a[idx],backw)) ++idx;
		if (idx == N) {
			printf("YES"); return 0;
		}
	}
	printf("NO"); return 0;
}