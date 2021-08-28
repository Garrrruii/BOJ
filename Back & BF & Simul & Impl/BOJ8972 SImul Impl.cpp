#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int R, C, y, x;			//종수
	pair<int, int> A[10000];//미친 아두이노
	int asize = 1;
	int b[100][100] = { 0, };

	char row[101];
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> row;
		for (int j = 0; j < C; ++j) {
			if (row[j] == 'R') b[i][j] = asize, A[asize++] = { i,j };
			else if (row[j] == 'I') y = i, x = j;
		}
	}

	int di[9] = { 1,1,1,0,0,0,-1,-1,-1 };
	int dj[9] = { -1,0,1,-1,0,1,-1,0,1 };
	char d[101];
	cin >> d;

	int ad, tmp;
	for (int t = 0; d[t] > '0'; ++t) {
		//종수가 움직인다.
		y += di[d[t] - '1'], x += dj[d[t] - '1'];
		if (b[y][x] && A[b[y][x]].first >= 0) { cout << "kraj " << t + 1; return 0; }
		for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) b[i][j] = 0;

		//미친 아두이노가 종수 쪽으로 움직인다.
		for (int i = 1; i < asize; ++i) {
			if (A[i].first < 0) continue;
			
			ad = (y > A[i].first ? 0 : y == A[i].first ? 3 : 6)
				+ (x < A[i].second ? 0 : x == A[i].second ? 1 : 2);
			A[i].first += di[ad], A[i].second += dj[ad];
			if (A[i].first == y && A[i].second == x) { cout << "kraj " << t + 1; return 0; }

			if (!b[A[i].first][A[i].second]) b[A[i].first][A[i].second] = i;
			else {
				A[b[A[i].first][A[i].second]].first = -1;
				A[i].first = -1;
			}
		}
	}

	//게임 끝
	b[y][x] = -1;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (b[i][j] < 0) cout << "I";
			else if (!b[i][j] || A[b[i][j]].first < 0) cout << "."; //0이거나 폭파 아두이노 있음
			else cout << "R";
		}
		cout << "\n";
	}
	return 0;
}
/*

9 10
..........
.........R
..........
R.........
R...I.....
R.........
..........
.........R
....R.....
아래 순서대로 실행해보쇼
577
5774
57744
*/