//game
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//move coin
//X where coin is
//choose dir
//move by X, dir, ignore H
//END if coin moves to H or out of board
//=> MAX CNT of moving?

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int N, M, b[50][50], dp[50][50];
bool vis[50][50];

int move(int r, int c) {
	if (!b[r][c] || dp[r][c]) return dp[r][c];
	vis[r][c] = true;
	cout << r << " " << c << "\n";

	int X = b[r][c];
	int cnt = 1;

	for (int d = 0; d < 4; ++d) {
		int nr = r + X * dr[d];
		int nc = c + X * dc[d];
		
		if (nr<0 || nr>=N || nc<0 || nc>=M) continue;

		cout << r << " " << c << ",d=" << d << ": " << nr << "," << nc << "\n";

		int next;
		if (!b[nr][nc]) next = 0;
		else if (vis[nr][nc]) {
			dp[r][c] = -1; vis[r][c] = false; return -1;
		}
		else next = move(nr, nc);
		
		if (next == -1) {
			dp[r][c] = -1; vis[r][c] = false; return -1;
		}
		else cnt = max(cnt,next+1);
	}
	dp[r][c] = cnt; vis[r][c] = false; return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string tmp; cin >> tmp;
		for (int j = 0; j < M; ++j)
			b[i][j] = (tmp[j] == 'H') ? 0 : tmp[j] - '0';
	}
	int ans = move(0, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << move(0,0); return 0;
}
