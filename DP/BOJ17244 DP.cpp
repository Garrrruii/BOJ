#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M, K = 1;
	char tmp[51];
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	int map[51][51];
	bool vis[51][51];

	pair<int, int> X[6];
	int sx, sy, ex, ey;
	int dist[6][7] = { 0, };

	int dp[32][6];		//state, last taken
	int exit;

	scanf("%d%d", &N, &M);
	for (int y = 0; y < M; ++y) {
		scanf("%s", &tmp);
		for (int x = 0; x < N; ++x) {
			if (tmp[x] == '.') map[y][x] = -1;
			else if (tmp[x] == '#') map[y][x] = -2;
			else if (tmp[x] == 'X') map[y][x] = K, X[K++] = { x,y };
			else if (tmp[x] == 'S') sx = x, sy = y, map[y][x] = 0;
			else if (tmp[x] == 'E') ex = x, ey = y;
		}
	}
	X[0] = { sx,sy }, X[K] = { ex,ey }, map[ey][ex] = K;		//0 x1 x2 x3 ... 
	int all = (1 << (K-1)) - 1;

	//initiate
	for (int i = 1; i <= all; ++i) {
		for (int j = 0; j < K; ++j) dp[i][j] = 987654;
	}

	//Get Distance
	queue<pair<pair<int, int>, int>> P;
	for (int cur = 0; cur < K; ++cur) {
		for (int y = 0; y < M; ++y) {
			for (int x = 0; x < N; ++x) vis[y][x] = false;
		}

		P.push({ X[cur],0 }); vis[X[cur].second][X[cur].first] = true;
		while (!P.empty()) {
			int cx = P.front().first.first;
			int cy = P.front().first.second;
			int distance = P.front().second + 1; P.pop();

			for (int d = 0; d < 4; ++d) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[ny][nx]) continue;
				int nxt = map[ny][nx];
				if (nxt < -1) continue;

				if (nxt >= 0 && nxt!=cur) dist[cur][nxt] = distance;
				P.push({ {nx,ny},distance }); vis[ny][nx] = true;
			}
		}
	}
	if (K == 1) { printf("%d", dist[0][1]); return 0; }

	//Get DP
	for (int i = 1; i <= all; ++i) {
		for (int j = 1; j < K; ++j) vis[i][j] = false;
	}
	queue<pair<int, int>> Q;
	for (int k = 1; k < K; ++k) dp[1 << (k - 1)][k] = dist[0][k], Q.push({ 1 << (k - 1),k });
	for (int n = 2; n < K; ++n) {
		int qsize = Q.size();
		while (qsize--) {
			int curstate = Q.front().first;
			int cur = Q.front().second; Q.pop();
			int curdist = dp[curstate][cur];

			for (int nxt = 1; nxt < K; ++nxt) {
				if (nxt == cur || ( curstate & (1 << (nxt-1)))) continue;

				int nxtstate = curstate | (1 << (nxt-1));
				int nxtdist = curdist + dist[cur][nxt];
				dp[nxtstate][nxt] = (dp[nxtstate][nxt] < nxtdist) ? dp[nxtstate][nxt] : nxtdist;
				if (!vis[nxtstate][nxt]) Q.push({ nxtstate,nxt }), vis[nxtstate][nxt] = true;
			}
		}
	}

	//Get ANS
	int ANS = 987654;
	while (!Q.empty()) {
		int last = Q.front().second; Q.pop();
		int TMP = dp[all][last] + dist[last][K];
		ANS = (ANS < TMP) ? ANS : TMP;
	}

	printf("%d", ANS); return 0;
}

/*
7 6
#######
#SX..X#
#..####
#..X..#
#X..X.#
#####E#

	for (int i = 0; i < K; ++i) {
		for (int j = 0; j <= K; ++j) printf("%2d ", dist[i][j]);
		printf("\n");
	}printf("\n");

	for (int i = 1; i <= all; ++i) {
		printf("\n%2d: ", i);
		for (int j = 1; j < K; ++j) printf("%2d ", (dp[i][j] < 987650) ? dp[i][j] : 99);
	}
*/