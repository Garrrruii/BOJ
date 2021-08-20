//new game
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//chess board N*N, K-pieces
//w, r, b
//1~Kth pieces, build up available, direction decided
//until 4-pieces builded
//if cell is w) move to cell
//			 r) move & reverse order
//			 b) move in reverse, again b) don't move, revese direction
//			 out of cell) same as blue

int dc[4] = { 1, -1, 0, 0 };
int dr[4] = { 0, 0, -1, 1 };
queue<int> q[12][12];
struct piece {
	int row, col, dir;
};
piece p[10];
bool ava = false;

void move(int mode, int k) {
	int r = p[k].row, c = p[k].col, d = p[k].dir;
	int nr = r + dr[d], nc = c + dc[d];

	if (mode == 1) {
	//	printf("%d move reverse:", k);
		stack<int> s;
		while (!q[r][c].empty()) {
			s.push(q[r][c].front()); q[r][c].pop();
		}
		while(!s.empty()){
			int tar = s.top(); s.pop();
			p[tar].row = nr, p[tar].col = nc; q[nr][nc].push(tar);
		}
	}
	else {
	//	printf("%d move in order:", k);
		while (!q[r][c].empty()) {
			int tar = q[r][c].front(); q[r][c].pop();
			p[tar].row = nr, p[tar].col = nc; q[nr][nc].push(tar);
		}
	}
	if (q[nr][nc].size() >= 4) ava = true;
	//printf("\n");
}
int main() {
	int N, K, b[12][12]; //0=w 1=r 2=b
	
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &b[i][j]);
	}
	for (int k = 0; k < K; ++k) {
		int r, c, d;
		scanf("%d%d%d", &r, &c, &d); r--, c--, d--;
		p[k] = { r, c, d }; q[r][c].push(k);
	}

	int T = 1;
	while (T < 1001) {
		for (int k = 0; k < K; ++k) {
			int r = p[k].row, c = p[k].col;
			if (q[r][c].front() != k) continue;

			int d = p[k].dir;
			int nr = r + dr[d], nc = c + dc[d];
			//printf("%d at (%d,%d) to (%d,%d)\n", d, r, c, nr, nc);

			if (nc < 0 || nc == N || nr < 0 || nr == N || b[nr][nc] == 2) {
				//printf("change dir 2\n");
				if (d % 2) d--, p[k].dir--;
				else d++, p[k].dir++;
				nr = r + dr[d], nc = c + dc[d];

				if (nc < 0 || nc == N || nr < 0 || nr == N || b[nr][nc] == 2) {
					//printf("change dir 2\n");
					if (d % 2) p[k].dir--;
					else p[k].dir++;
				}
				else if (b[nr][nc] == 1) move(1, k);
				else move(0, k);
			}
			else if (b[nr][nc] == 1) move(1, k);
			else move(0, k);

			/*
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) printf("%d ",q[i][j].size());
				printf("\n");
			}
			printf("\n");*/

			if (ava) { printf("%d", T); return 0; }
		}
		T++;
	}
	if (!ava) printf("-1"); return 0;
}