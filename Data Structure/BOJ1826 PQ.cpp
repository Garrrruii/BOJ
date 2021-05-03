#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, less<int>> PQ;
pair<int, int> OIL[10002];
int main() {
	int N, a, b, L, P;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &a, &b), OIL[i] = { a, b };
	sort(OIL + 1, OIL + N + 1);
	scanf("%d%d", &L, &P);
	OIL[N + 1] = { L,0 };

	int pos = 0;
	int ANS = 0;
	for (int i = 1; i <= N + 1; ++i) {
	//	printf("%2d %2d   ", OIL[i].first, OIL[i].second);
		PQ.push(OIL[i - 1].second);

		P -= (OIL[i].first - pos); pos = OIL[i].first;
	//	printf("P=%d ", P);
		while (P < 0  && !PQ.empty()) ANS++, P += PQ.top(), /*printf("+%d ", PQ.top()),*/ PQ.pop();
	//	printf("\n");
		if (P < 0) { printf("-1"); return 0; }
	}
	printf("%d", ANS); return 0;
}
/*
6
4 4
5 2
6 4
20 3
11 5
15 10
25 10
*/