#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int by, bx, ry, rx, dir;
};
queue<node> Q;

int main() {
	int N, M;
	char B[10][11];
	int dx[4] = { 1, -1, 0, 0 }; //right left down up
	int dy[4] = { 0, 0, 1, -1 };

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%s", &B[i]);

	node input;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (B[i][j] == 'B') input.by = i, input.bx = j, B[i][j] = '.';
			else if (B[i][j] == 'R') input.ry = i, input.rx = j, B[i][j] = '.';
		}
	}
	input.dir = -1;

	Q.push(input);	
	int cnt = 1;
	while (!Q.empty() && cnt <= 10) {
		int qsize = Q.size();
		while (qsize--) {
			node cur = Q.front(); Q.pop();
			
			for (int d = 0; d < 4; ++d) {
				// No need to move, continue
				if (d == cur.dir) continue;

				int by = cur.by, bx = cur.bx;
				int ry = cur.ry, rx = cur.rx;
				bool redfirst = true;

				// Decide what to move first
				if (!d && ry == by && rx < bx) redfirst = false;
				else if (d == 1 && ry == by && bx < rx) redfirst = false;
				else if (d == 2 && rx == bx && ry < by) redfirst = false;
				else if (d == 3 && rx == bx && by < ry) redfirst = false;

				if (redfirst) {
					// Move R
					while (B[ry][rx] == '.') ry += dy[d], rx += dx[d];
					if (B[ry][rx] == '#') ry -= dy[d], rx -= dx[d];
					else if (B[ry][rx] == 'O') rx = -1;

					// Move B
					while (1) {
						by += dy[d], bx += dx[d];
						if (B[by][bx] == '#' || (by == ry && bx == rx)) {
							by -= dy[d], bx -= dx[d]; break;
						}
						else if (B[by][bx] == 'O') {
							bx = -1; break;
						}
					}
					if (bx < 0) continue;
				}
				else {
					// Move B
					while (B[by][bx] == '.') by += dy[d], bx += dx[d];
					if (B[by][bx] == '#') by -= dy[d], bx -= dx[d];
					else if (B[by][bx] == 'O') continue;

					// Move R
					while (1) {
						ry += dy[d], rx += dx[d];
						if (B[ry][rx] == '#' || (ry == by && rx == bx)) {
							ry -= dy[d], rx -= dx[d]; break;
						}
						else if (B[ry][rx] == 'O') {
							rx = -1; break;
						}
					}
					
				}
				// No change, continue;
				if (rx == cur.rx && ry == cur.ry && bx == cur.bx && by == cur.by) continue;

				if (rx < 0) { printf("%d", cnt); return 0; }
				else Q.push({ by,bx,ry,rx,d });
			}
		}
		cnt++;
	}
	printf("-1"); return 0;
}
