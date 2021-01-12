#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int N, ksize, py, px, idx = 0;
set<int> S;
vector<pair<int, int> > K;
int h[50][50], hh[50][50], vec[2500];
char map[50][50]; 
bool vis[50][50];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int bfsl(int low) {
	if (low > h[py][px]) return -1;
	int upp = h[py][px];
	queue<pair<int, int> > Q;
	Q.push({ py, px });
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) vis[i][j] = 0, hh[i][j] = 1e9;
	}
	hh[py][px] = upp;

	int cnt = 0;
	while (Q.size()) {
		int y = Q.front().first, x = Q.front().second;
		Q.pop();
		if (map[y][x] == 'K' && !vis[y][x]) vis[y][x] = 1, cnt++;
		
		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i], nx = x + dx[i], tp;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || h[ny][nx] < low) continue;
			
			if (hh[ny][nx] > (tp = max(hh[y][x], h[ny][nx]))) {
				hh[ny][nx] = tp;
				Q.push({ ny, nx });
			}
		}
	}
	if (cnt < ksize) return -1;
	
	for (auto& it : K) upp = max(upp, hh[it.first][it.second]);
	return upp;
}
int bfsu(int upp) {
	if (upp < h[py][px])	return -1;
	int low = h[py][px];
	queue<pair<int, int> > Q;
	Q.push({ py, px });
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) vis[i][j] = 0, hh[i][j] = -1;
	}
	hh[py][px] = low;

	int cnt = 0;
	while (Q.size()) {
		int y = Q.front().first;
		int x = Q.front().second; Q.pop();
		if (map[y][x] == 'K' && !vis[y][x]) vis[y][x] = 1, cnt++;
		
		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i], nx = x + dx[i], tp;
			if (ny < 0 || ny >= N || nx<0 || nx >= N || h[ny][nx]>upp) continue;
			
			if (hh[ny][nx] < (tp = min(hh[y][x], h[ny][nx]))) {
				hh[ny][nx] = tp;
				Q.push({ ny, nx });
			}
		}
	}
	if (cnt < ksize) return -1;

	for (auto& it : K) low = min(low, hh[it.first][it.second]);
	return low;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'P') py = i, px = j;
			else if (map[i][j] == 'K') K.push_back({ i, j }), ++ksize;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> h[i][j], S.insert(h[i][j]);
		}
	}
	for (auto iter : S) vec[idx++] = iter;
	
	int ANS = 1000000;
	for (int i = 0; i < idx;) {
		int upp = bfsl(vec[i]);
		if (upp == -1) break;
		int low = bfsu(upp);
		if (low == -1) break;
		ANS = min(ANS, upp - low);
		i = upper_bound(vec, vec + idx, low) - vec;
	}
	cout << ANS; return 0;
}