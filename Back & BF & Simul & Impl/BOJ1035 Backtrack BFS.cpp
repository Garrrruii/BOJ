#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

bool b[5][5];
int p[5][2], N, ANS = 987654321;
//int solution으로 하는 것보다 void로 하는 게 훨 씬 빠 름
void solution(int n, int move_cnt) {
	if (n >= N) {
		queue<pair<int, int>> Q;
		bool vis[5][5] = { false, };
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (!b[i][j]) continue;

				int connected = 1;
				Q.push({ i,j }); vis[i][j] = true;
				while (!Q.empty()) {
					int y = Q.front().first;
					int x = Q.front().second; Q.pop();

					for (int d = 0; d < 4; ++d) {
						int ny = y + "1102"[d] - '1';
						int nx = x + "0211"[d] - '1';
						if (ny < 0 || ny > 4 || nx < 0 || nx > 4 || vis[ny][nx]) continue;
						if (b[ny][nx]) Q.push({ ny,nx }), vis[ny][nx]=true, connected++;
					}
				}
				if (connected == N && move_cnt < ANS) ANS = move_cnt;
				return;
			}
		}
	}

	int y = p[n][0], x = p[n][1]; n++;

	int nxt_move_cnt;
	b[y][x] = false;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (b[i][j]) continue;
			nxt_move_cnt = move_cnt + abs(y - i) + abs(x - j);
			if (nxt_move_cnt >= ANS) continue;

			b[i][j] = true;
			solution(n, nxt_move_cnt);
			b[i][j] = false;
		}
	}
	b[y][x] = true;
	return;
}
int main() {
	char board[6];
	for (int i = 0; i < 5; ++i) {
		cin >> board;
		for (int j = 0; j < 5; ++j)
			if (board[j] == '*') b[i][j]=true, p[N][0] = i, p[N][1] = j, N++;
	}

	solution(0, 0); 
	cout << ANS; return 0;
}