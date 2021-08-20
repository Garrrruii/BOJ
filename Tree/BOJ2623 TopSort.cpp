//Music Program
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int ind[1001] = { 0, };
vector<int> adj[1001];

int main() {
	int N, M, T, prv, nxt;
	scanf("%d%d", &N, &M);
	for (int m = 0; m < M; ++m) {
		scanf("%d", &T);

		if (T) scanf("%d", &prv), T--;
		while (T--) {
			scanf("%d", &nxt);
			ind[prv]++; adj[nxt].push_back(prv); prv = nxt;
		}
	}
	stack<int> S;
	while (S.size() < N) {
		//for (int i = 1; i <= N; ++i) printf("%d ", ind[i]);
		//printf("\n");
		
		bool noleaf = true;
		for (int i = 1; i <= N; ++i) {
			if (!ind[i]) {
				ind[i] = -1; noleaf = false;
				for (int a : adj[i]) ind[a]--;
				S.push(i);
			}
		}
		if (noleaf) { printf("0"); return 0; }
	}
	while (!S.empty()) printf("%d\n", S.top()), S.pop();
	return 0;
}

/*
9 4
4 1 4 3 8
4 6 2 5 4
3 2 3 7
3 9 5 3
(6 2 1 9 5 4 3 8 7)

8 3
4 1 4 3 8
4 6 2 5 4
4 2 3 6 7

8 3
4 1 4 3 8
5 6 2 5 4 7
3 2 4 6
(0)
*/