#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int v, p;
};
vector<node> e[100001];
vector<int> up[100001]; //up[i] i까지 올라올 수 있었던 애들
bool vis[100001];
int power[100001];

void dfs(int cur) {
	vis[cur] = true;

	for (node nxt : e[cur]) {
		if (vis[nxt.v]) continue;

		power[nxt.v] -= nxt.p;
		if (power[nxt.v] >= 0) up[cur].push_back(nxt.v);
		else power[nxt.v] = nxt.v;

		dfs(nxt.v);
		for (int v : up[nxt.v]) {
			power[v] -= nxt.p;
			if (power[v] >= 0) up[cur].push_back(v);
			else power[v] = nxt.v;
		}
	}
}
int main() {
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &power[i]);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a].push_back({ b,c });
		e[b].push_back({ a,c });
	}

	dfs(1);
	power[1] = 1;
	for (int v : up[1]) power[v] = 1;

	for (int i = 1; i <= N; ++i) printf("%d\n", power[i]);
	return 0;
}
/*
9
10 5 30 40 10 25 60 40 70
2 1 10 2 3 25 2 4 15
4 5 10 4 6 5
7 5 30 8 5 20 8 9 15

1 2 2 1 4 2 2 4 1
*/