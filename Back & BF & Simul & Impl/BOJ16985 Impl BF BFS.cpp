#include <iostream>
#include <queue>
using namespace std;
/*  3차원 미로 탈출
	5*5*5 
	주어진 판을 회전할 수 있으나 뒤집을 수는 없다.
	5개를 쌓는다(순서 마음대로)
	미로를 적은 이동 횟수로 탈출한 사람이 우승
	가장 적은 이동 횟수로 출구에 도달할 수 있게 만들었을 때 몇 번 이동을 해야하는가
*/
bool A[5][5][5][4];
bool B[5][5][5];
bool vis[5][5][5];
int dk[6] = { 1,-1,0,0,0,0 }, ANS = 987654;
int di[6] = { 0,0,1,-1,0,0 };
int dj[6] = { 0,0,0,0,1,-1 };
struct node {
	int k, i, j;
};
queue<node> Q;
void exit() {
	if (!B[0][0][0] || !B[4][4][4]) return;	//입출구 막힘

	while (!Q.empty()) Q.pop();				//Initiation
	for (int k = 0; k < 5; ++k)
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) vis[k][i][j] = false;

	int mov = 0, qsize = 1;
	Q.push({ 0,0,0 }); vis[0][0][0] = true;
	while (qsize && ANS > mov) {
		mov++;
		while (qsize--) {
			int k = Q.front().k;
			int i = Q.front().i;
			int j = Q.front().j; Q.pop();

			for (int d = 0; d < 6; ++d) {
				int nk = k + dk[d];
				int ni = i + di[d];
				int nj = j + dj[d];
				if (nk < 0 || ni < 0 || nj < 0 || nk > 4 || ni > 4 || nj > 4) continue;
				if (vis[nk][ni][nj] || !B[nk][ni][nj]) continue;
				Q.push({ nk,ni,nj }); vis[nk][ni][nj] = true;
			}
		}
		if (vis[4][4][4] && ANS > mov) { ANS = mov; return; }
		qsize = Q.size();
	}
	return;
}
void build(int kdx, int state) {
	if (ANS == 12) return;
	if (kdx == 5) exit();
	else {
		for (int k = 0; k < 5; ++k) {
			if (state & (1 << k)) continue;

			for (int r = 0; r < 4; ++r) {
				for (int i = 0; i < 5; ++i)
					for (int j = 0; j < 5; ++j) B[kdx][i][j] = A[k][i][j][r];
				build(kdx + 1, state | (1 << k));
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tmp;
	for (int k = 0; k < 5; ++k)
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) { 
				cin >> tmp;
				if (tmp) A[k][i][j][0] = true;
			}
	
/*	00 01 02 03 04
	10 11 12 13 14
	20 21 22 23 24
	30 31 32 33 34
	40 41 42 43 44	*/
	for (int k = 0; k < 5; ++k) {
		for (int x = 0; x < 4; ++x) {
			A[k][4 - x][0][1] = A[k][4][4 - x][2] = A[k][x][4][3] = A[k][0][x][0];
			A[k][4][4 - x][1] = A[k][x][4][2] = A[k][0][x][3] = A[k][4 - x][0][0];
			A[k][x][4][1] = A[k][0][x][2] = A[k][4 - x][0][3] = A[k][4][4 - x][0];
			A[k][0][x][1] = A[k][4 - x][0][2] = A[k][4][4 - x][3] = A[k][x][4][0];
		}
		for (int x = 1; x < 3; ++x) {
			A[k][4 - x][1][1] = A[k][3][4 - x][2] = A[k][x][3][3] = A[k][1][x][0];
			A[k][3][4 - x][1] = A[k][x][3][2] = A[k][1][x][3] = A[k][4 - x][1][0];
			A[k][x][3][1] = A[k][1][x][2] = A[k][4 - x][1][3] = A[k][3][4 - x][0];
			A[k][1][x][1] = A[k][4 - x][1][2] = A[k][3][4 - x][3] = A[k][x][3][0];
		}
		A[k][2][2][1] = A[k][2][2][2] = A[k][2][2][3] = A[k][2][2][0];
	}
	build(0, 0);
	if (ANS > 987653) cout << -1;
	else cout << ANS;
	return 0;
}
/*	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < 5; ++i) {
			for (int r = 0; r < 4; ++r) {
				for (int j = 0; j < 5; ++j) cout << (A[k][i][j][r] ? 1 : 0) << " ";
				cout << " | ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
*/