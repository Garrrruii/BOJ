//escape
//similar with BOJ5427 fire
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define INF 1000
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, pair<int, int>>> Q;
bool vis[50][50] = { false, };
int wat[50][50] = { 0, };

int main() {
	int R, C, sx, sy, tx, ty;
	string inp;

	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; ++i) {
		cin >> inp;
		for (int j = 0; j < C; ++j) {
			if (inp[j] == '*') Q.push({ 1, {i, j} }), wat[i][j] = 1;
			else if (inp[j] == 'X') vis[i][j] = true;
			else if (inp[j] == 'D') ty = i, tx = j, vis[i][j] = true;
			else if (inp[j] == 'S') sy = i, sx = j;
		}
	}

	while (!Q.empty()) {
		int m = Q.front().first;
		int cx = Q.front().second.second;
		int cy = Q.front().second.first; Q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (wat[ny][nx] || vis[ny][nx]) continue;
			wat[ny][nx] = m + 1; Q.push({ m + 1,{ny,nx} });
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) printf("%d ", wat[i][j]);
		printf("\n");
	}

	int ANS = INF;
	Q.push({ 1, {sy, sx} }); vis[sy][sx] = true;
	while (!Q.empty()) {
		int m = Q.front().first;
		int cx = Q.front().second.second;
		int cy = Q.front().second.first; Q.pop();
		printf("(%d,%d) %dmin\n", cx, cy, m);
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (ty == ny && tx == nx) {
				ANS = min(ANS, m); continue;
			}
			if (vis[ny][nx] || (wat[ny][nx] && wat[ny][nx] <= m + 1)) continue;
			vis[ny][nx] = true; Q.push({ m + 1,{ny,nx} });
		}
	}
	if (ANS < INF) printf("%d", ANS);
	else printf("KAKTUS");
	return 0;
}
