//fire
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define INF 5000000

queue<pair<int, pair<int, int>>> Q;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int T, W, H, X, Y;
string inp;
int fire[1000][1000];
bool vis[1000][1000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> T;
	while (T--) {
		memset(fire, 0, sizeof(fire));
		memset(vis, false, sizeof(vis));
		cin >> W >> H;
		for (int i = 0; i < H; ++i) {
			cin >> inp;
			for (int j = 0; j < W; ++j) {
				if (inp[j] == '*') fire[i][j] = 1, Q.push({ 1,{ i,j } });
				else if (inp[j] == '#') vis[i][j] = true;
				else if (inp[j] == '@') Y = i, X = j;
			}
		}

		while (!Q.empty()) {
			int sec = Q.front().first;
			int cx = Q.front().second.second; 
			int cy = Q.front().second.first; Q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
				if (fire[ny][nx] || vis[ny][nx]) continue;
				fire[ny][nx] = sec + 1; Q.push({ sec + 1,{ ny,nx } });
			}
		}

		int ANS = INF;
		Q.push({ 1,{Y,X} }); vis[Y][X] = true;
		while (!Q.empty()) {
			int sec = Q.front().first;
			int cx = Q.front().second.second;
			int cy = Q.front().second.first; Q.pop();
			//printf("(%d,%d) %dsec\n", cx, cy, sec);
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
					ANS = min(ANS, sec); continue;
				}
				if (vis[ny][nx] || (fire[ny][nx] && fire[ny][nx] <= sec + 1)) continue;
				vis[ny][nx] = true; Q.push({ sec + 1,{ ny,nx } });
			}
		}
		if (ANS < INF) cout << ANS << "\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
