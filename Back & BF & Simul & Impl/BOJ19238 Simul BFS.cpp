#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define INF 987654
using namespace std;
// 항상 최단경로로 이동
// 1 현재 위치에서 거리가 가장 짧은 승객
// 2 행 번호 최소인 승객
// 3 열 번호 최소인 승객
// 한칸에 연료 1 소모
// 이동시키면 소모한 연료의 두 배 충전
//
// 모든 승객을 데려다 줄 수 있음 -> 남은 연료 양 출력
// else -> -1

queue<pair<int, int>> Q;
bool vis[21][21] = { false, };
int map[21][21], N;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

struct node {
	int r1, c1, r2, c2;
};
node P[401];
bool sortP(node A, node B) {
	if (A.r1 == B.r1) return A.c1 > B.c1;
	return A.r1 > B.r1;
}

// R,C에서 가장 먼저 태워야할 승객을 찾는다.
pair<int, int> Find_Pass(int R, int C) {
	if (map[R][C]) return { map[R][C],0 };

	memset(vis, false, sizeof(vis));
	while (!Q.empty()) Q.pop();
	
	int idx = 0;
	int dist = 0;

	Q.push({ R,C }), vis[R][C] = true;
	while (!Q.empty()) {
		dist++;
		int qsize = Q.size();
		while (qsize--) {
			int rr = Q.front().first;
			int cc = Q.front().second; Q.pop();

			for (int d = 0; d < 4; ++d) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (!nr || nr > N || !nc || nc > N) continue;
				if (map[nr][nc] < 0 || vis[nr][nc]) continue;

				if (!map[nr][nc]) Q.push({ nr,nc }), vis[nr][nc] = true;
				else idx = max(idx, map[nr][nc]);
			}
		}
		if (idx) return { idx,dist };
	}
	return { 0, 0 };
}
// idx 승객의 이동 거리를 구한다.
int Get_Dist(int idx) {
	memset(vis, false, sizeof(vis));
	while (!Q.empty()) Q.pop();

	int dist = 0;

	Q.push({ P[idx].r1,P[idx].c1 }), vis[P[idx].r1][P[idx].c1] = true;
	while (!Q.empty()) {
		dist++;
		int qsize = Q.size();
		while (qsize--) {
			int rr = Q.front().first;
			int cc = Q.front().second; Q.pop();

			for (int d = 0; d < 4; ++d) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (!nr || nr > N || !nc || nc > N) continue;
				if (map[nr][nc] < 0 || vis[nr][nc]) continue;

				if (nr == P[idx].r2 && nc == P[idx].c2) return dist;
				else Q.push({ nr,nc }), vis[nr][nc] = true;
			}
		}
	}
	return INF;
}
int main() {
	int M, F, tmp = 0;
	scanf("%d%d%d", &N, &M, &F);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) scanf("%d", &tmp), map[i][j] = -tmp;
	}

	int R, C;
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= M;++i) {
		scanf("%d%d%d%d", &P[i].r1, &P[i].c1, &P[i].r2, &P[i].c2);
	}
	sort(P + 1, P + M + 1, sortP);
	for (int i = 1; i <= M; ++i) map[P[i].r1][P[i].c1] = i;
	P[0] = { INF,INF };

	while(M--) {
		pair<int,int> p = Find_Pass(R, C);
		int idx = p.first;
		int dist = p.second;
		if (!idx || dist > F) { printf("-1"); return 0; }
		R = P[idx].r1, C = P[idx].c1, F -= dist;

		dist = Get_Dist(idx);
		if (dist > F) { printf("-1"); return 0; }
		map[R][C] = 0; 
		R = P[idx].r2, C = P[idx].c2, F += dist;
	}
	printf("%d", F);
	return 0;
}