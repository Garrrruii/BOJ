#include <iostream>
#include <vector>
using namespace std;

int up, down, vis[101], visnum;
vector<int> E[101][2];
void dfs(int cur) {
	down++; vis[cur] = visnum;
	for (int nxt : E[cur][0]) if (vis[nxt] < visnum) dfs(nxt);
}
void rdfs(int cur) {
	up++; vis[cur] = visnum;
	for (int nxt : E[cur][1]) if (vis[nxt] < visnum) rdfs(nxt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, a, b;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		E[b][0].push_back(a); //a<-b
		E[a][1].push_back(b); //a->b
	}
	for (int i = 1; i <= N; ++i) {
		up = down = 0;
		visnum++; dfs(i); visnum++; rdfs(i);
		cout << N - up - down + 1 << "\n";
	}
	return 0;
}