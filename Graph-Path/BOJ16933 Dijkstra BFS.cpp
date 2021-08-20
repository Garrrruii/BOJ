#include <cstdio>
#include <queue>
using namespace std;
//BFS가 더 빠를 것임. 다익스트라로 푸니 너무 오래걸렸음
//문제는 BFS로 고친 코드가 틀림. WHY?

struct node {
	int y, x, k, day, cost;
};
bool operator<(node A, node B) {
	return B.cost < A.cost;
}
priority_queue<node> pq;

int dij[1000][1000][11][2]; //1:낮 0:밤
char b[1000][1001];
int main() {
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };

	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; ++i) scanf("%s", &b[i]);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k <= K; ++k) dij[i][j][k][0] = dij[i][j][k][1] = 987654321;
		}
	}

	dij[0][0][K][1] = 1, pq.push({ 0,0,K,1,1 });
	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int k = pq.top().k;
		int day = pq.top().day;
		int cost = pq.top().cost; pq.pop();
		if (dij[y][x][k][day] < cost) continue;
		if (y == N - 1 && x == M - 1) { printf("%d", cost); return 0; }

		cost++;
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			if (b[ny][nx] == '1') {			// 막힌 곳이고 k 남아있을 때
				if (!k) continue;			// 낮)지금 밤)내일 뚫으면 됨 => 뚫은 뒤는 무조건 밤

				int ncost = day ? cost : (cost + 1);
				if (dij[ny][nx][k - 1][0] <= ncost) continue;
				dij[ny][nx][k - 1][0] = ncost, pq.push({ ny,nx,k - 1,0,ncost });
			}
			else {							// 0이면 그냥 감
				if (dij[ny][nx][k][1 - day] <= cost) continue;
				dij[ny][nx][k][1 - day] = cost, pq.push({ ny,nx,k,1 - day,cost });
			}
		}
	}
	printf("-1"); return 0;
}
/*
8 6 2
001000
111110
111110
111110
111110
000000
011111
000000
(15)*/