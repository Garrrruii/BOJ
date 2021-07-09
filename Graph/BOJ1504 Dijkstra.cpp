#include <cstdio>
#include <queue>
#define INF 1987654321 //INF 200'000'000
using namespace std;

struct node {
	int v, s, c;	//vertex state cost
};
bool operator<(node A, node B) { //B ¿ì¼±
	return A.c > B.c;
}
priority_queue<node> pq;

unsigned int cost[801][4]; //0 1(A) 2(B) 3(A,B)
vector<pair<int, int>> e[801];
int main() {
	int N, E, A, B, tmp;
	scanf("%d%d", &N, &E);
	while (E--) {
		scanf("%d%d%d", &A, &B, &tmp);
		e[A].push_back({ B,tmp });
		e[B].push_back({ A,tmp });
	}
	scanf("%d%d", &A, &B);
	for (int v = 1; v <= N; ++v) cost[v][0] = cost[v][1] = cost[v][2] = cost[v][3] = INF;
	
	if(A==1) cost[1][1] = 0, pq.push({ 1,1,0 });
	else cost[1][0] = 0, pq.push({ 1,0,0 });

	while (!pq.empty()) {
		int cur = pq.top().v;
		int stt = pq.top().s;
		int cst = pq.top().c; pq.pop();
		if (cst > cost[cur][stt]) continue;
//		printf("\n%d (%d) %d -> ", cur, stt, cst);

		for (pair<int, int> ee : e[cur]) {
			int ncst = cst + ee.second;
			int nstt = stt;
			if (ee.first == A) nstt += (stt & 1) ? 0 : 1;
			else if (ee.first == B) nstt += (stt < 2) ? 2 : 0;

			if (cost[ee.first][nstt] > ncst) {
//				printf("%d ", ee.first);
				cost[ee.first][nstt] = ncst; pq.push({ ee.first,nstt,ncst });
			}
		}
	}
	if (cost[N][3] < INF) printf("%d", cost[N][3]);
	else printf("-1");
	return 0;
}
/*
6 11
1 2 3 1 3 5 1 6 4
2 3 3 2 4 1 2 6 5
3 4 1 3 5 6 3 6 1
4 5 10 5 6 2
2 5
(10)

3 3
1 3 20
1 2 15
2 3 6
1 3
(20)
*/