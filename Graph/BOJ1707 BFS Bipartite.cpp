#include <cstdio>
#include <queue>
using namespace std;

int par[200001];
vector<int> e[200001];
queue<int> Q;
int main() {
	int K, V, E;

	scanf("%d", &K);
	while (K--) {
		int a, b;
		bool no_bipart = false;

		scanf("%d%d", &V, &E);
		while (E--) {
			scanf("%d%d", &a, &b);
			e[a].push_back(b), e[b].push_back(a);
		}

		for (int i = 1; !no_bipart && i <= V; ++i) {
			if (par[i]) continue;

			par[i] = 1; Q.push(i);
			while (!Q.empty()) {
				int cur = Q.front(); Q.pop();
				int in = par[cur];

				for (int v : e[cur]) {
					if (!par[v]) par[v] = -in, Q.push(v);
					else if (par[v] == in) { 
						no_bipart = true;
						while (!Q.empty()) Q.pop();
						break;
					}
				}
			}
		}
		if (no_bipart) printf("NO\n");
		else printf("YES\n");

		for (int i = 1; i <= V; ++i) e[i].clear();
		for (int i = 1; i <= V; ++i) par[i] = 0;
	}
	return 0;
}