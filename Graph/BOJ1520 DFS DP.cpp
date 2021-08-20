#include <iostream>
#include <queue> 
using namespace std;
//내리막길로만 이동하는 경로의 개수를 구하는 프로그램

int N, M, b[500][500], dp[500][500];//우좌상하
int di[4] = { 0,0,1,-1 }, dj[4] = { 1,-1,0,0 };
int dfs(int i, int j) {
	if (i == N - 1 && j == M - 1) return 1;
	if (dp[i][j]>=0) return dp[i][j];

	dp[i][j] = 0;
	int cnt = 0;
	//i,j에서 끝으로 가는 길의 개수
	for (int d = 0; d < 4; ++d) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		if (b[ni][nj] >= b[i][j]) continue;
		cnt += dfs(ni, nj);
	}
	dp[i][j] = cnt;
	return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> b[i][j];
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) dp[i][j] = -1;
	cout << dfs(0, 0); return 0;
}
/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 20 14 13
27 24 22 15 10
(6)
*/