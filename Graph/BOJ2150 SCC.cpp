#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int num = 0, ord[100001];
bool fin[100001];
vector<int> e[100001];
vector<vector<int>> SCC;
stack<int> S;

bool sortscc(vector<int> A, vector<int> B) {
	return A[0] < B[0];
}
int DFS(int cur) {
	ord[cur] = ++num;
	S.push(cur);

	int par = ord[cur];
	for (int nxt : e[cur]) {
		if (!ord[nxt]) par = min(par, DFS(nxt));
		else if (!fin[nxt]) par = min(par, ord[nxt]);
	}
	// par: the minimal order of vertices connected to cur
	// !ord[nxt] not visited yet (nxt which might be connected to prv)
	// !fin[nxt] visited but not finished (prv which is connected to cur)
	// Assume: visit order: prv -> cur -> nxt

	if (par == ord[cur]) {
		vector<int> scc;
		while (1) {
			int v = S.top(); S.pop();
			scc.push_back(v); fin[v] = true;
			if (v == cur) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return par;
}
int main() {
	int V, E, u, v;
	scanf("%d%d", &V, &E);
	while (E--) {
		scanf("%d%d", &u, &v);
		if (u != v) e[u].push_back(v);
	}

	for (int i = 1; i <= V; ++i) if (!ord[i]) DFS(i);
	sort(SCC.begin(), SCC.end(),sortscc);

	printf("%d\n", SCC.size());
	for (vector<int> scc : SCC) {
		for (int v : scc) printf("%d ", v);
		printf("-1\n");
	}
	return 0;
}
/*
10 14
1 3 3 1 3 4 4 2 4 3 2 4 10 9
1 6 6 7 7 8 8 4 8 5 5 9 2 5

12 17
1 3 3 1 3 4 4 2 4 3 2 4 10 9 10 11 11 12 12 10
1 6 6 7 7 8 8 4 8 5 5 9 2 5
*/