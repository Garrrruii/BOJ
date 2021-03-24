//Work
//==1516 Game Develop
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t[10001], mint[10001];
vector<int> adj[10001];		//pre-work
int revcnt[10001];			//cnt of work where i'm pre-work of them

int getmint(int cur) {
	if (!mint[cur]) {
		for (int pre : adj[cur]) mint[cur] = max(mint[cur], getmint(pre));
		mint[cur] += t[cur];
	}
	return mint[cur];
}
int main() {
	int N, M, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &t[i], &M);
		while (M--) {
			scanf("%d", &tmp);
			adj[i].push_back(tmp); revcnt[tmp]++;
		}
	}

	for (int i = 1; i <= N; ++i) {    // No pre-works
		if (!adj[i].size()) mint[i] = t[i];
	}

	int MIN = 0;
	for (int i = 1; i <= N; ++i) {    // NOT a pre-work of works
		if (!revcnt[i]) MIN = max(MIN, getmint(i));
	}
	printf("%d", MIN); return 0;
}
