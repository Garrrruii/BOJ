#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int inord[32001];
vector<int> e[32001];
priority_queue<int, vector<int>, greater<int>> PQ;
int main() {
	int N, M, A, B;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &A, &B);
		e[A].push_back(B); inord[B]++;
	}
	for (int i = 1; i <= N; ++i) if (!inord[i]) PQ.push(i);
	while (!PQ.empty()) {
		int cur = PQ.top(); PQ.pop();
		printf("%d ", cur);

		for (int nxt : e[cur]) {
			inord[nxt]--;
			if (!inord[nxt]) PQ.push(nxt);
		}
	}
	return 0;
}
/*
8 7
1 6 2 6 2 4 4 3 4 5 7 5 8 3
(1 2 4 6 7 5 8 3)

8 8
1 6 2 6 2 4 4 3 4 5 7 5 8 3 8 5
(1 2 4 6 7 8 3 5)
*/