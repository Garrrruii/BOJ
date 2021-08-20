#include <cstdio>
#include <vector>
using namespace std;

int N, root;
vector<pair<int, int>> adj[101];	// vertex count
int need[101];	//int need[101][101];
//bool vis[101];
 /*
void getans(int ver) {
	if (vis[ver]) return;

	vis[ver] = true;
	for (int i = 0; i < adj[ver].size(); ++i) {
		int middle = adj[ver][i].first;
		int how_many = adj[ver][i].second;
		getans(middle);
		for (int basic = 1; basic <= N; ++basic) {
			need[ver][basic] += need[middle][basic] * how_many;
		}
	}

	//printf("%d: ",ver);
	//for (int i = 0; i <= N; ++i) printf("%d ", need[ver][i]);
	//printf("\n");
	return;
} */

int main() {
	int M, x, y, k;
	int ind[101] = { 0, }; //ind=0 => root

	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d", &x, &y, &k);
		adj[y].push_back({ x,k }); ind[x]++;
	}

	int root = 0;
	for (int i = 1; i <= N; ++i) {
		if (adj[i].empty()) { root = i; break; }
	}
	
	//¾Æ ±ÍÂú³×,,,¤¾

	for (int i = 1; i <= N; ++i) {
		if (need[i]) printf("%d %d\n", i, need[i]);
	}
	//getans(root);
	//for (int i = 1; i <= N; ++i) {
	//	if (need[root][i]) printf("%d %d\n", i, need[root][i]);
	//}
	return 0;
}