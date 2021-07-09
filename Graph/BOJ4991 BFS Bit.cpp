#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int y, x, room;
};
queue<node> Q;
bool vis[20][20][1024];

int main() {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int W, H;
	char b[20][21];
	while (1) {
		scanf("%d%d", &W, &H);
		if (!W) return 0;

		while (!Q.empty()) Q.pop();
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
				for (int r = 0; r < 1024; ++r) vis[i][j][r] = false;

		int num = 0;
		for (int i = 0; i < H; ++i) {
			scanf("%s", &b[i]);
			for (int j = 0; j < W; ++j) {
				if (b[i][j] == 'o') Q.push({ i, j, 0 }), vis[i][j][0] = true;
				else if (b[i][j] == '*') b[i][j] = '0' + num, num++;
			}
		}
		if (!num) { printf("0\n"); break; }
		int dirty = (1 << num) - 1;
		//num	 num of dirty cels
		//dirty	 state (goal)
		//0~9	 -th dirty cell

		int qsize = 1, CNT = 0;
		while (dirty && qsize) {
			CNT++;
			while (dirty && qsize--) {
				int y = Q.front().y;
				int x = Q.front().x;
				int r = Q.front().room; Q.pop();
			
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d];
					if (nx < 0 || nx >= W) continue;
					int ny = y + dy[d];
					if (ny < 0 || ny >= H || b[ny][nx] == 'x') continue;

					if ('0' <= b[ny][nx] && b[ny][nx] <= '9') {
						int nr = r | (1 << (b[ny][nx] - '0'));
						if (nr == dirty) { printf("%d\n", CNT); dirty = 0; break; }
						if (!vis[ny][nx][nr]) Q.push({ ny,nx,nr }), vis[ny][nx][nr] = true;
					}
					else if (!vis[ny][nx][r]) Q.push({ ny,nx,r }), vis[ny][nx][r] = true;
				}
			}
			qsize = Q.size();
		}
		if(dirty) printf("-1\n");
	}
	return 0;
}