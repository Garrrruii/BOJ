#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N;
	bool b[50][50];
	int x = -1, y = 0, X = -1, Y = 0;
	bool ver = true, VER = true;

	cin >> N;
	string tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		for (int j = 0; j < N; ++j) {
			b[i][j] = (tmp[j] == '1') ? false : true;

			if (tmp[j] == 'B' && x < 0) {
				if (j < N - 1 && tmp[j + 1] == 'B') y = i, x = j + 1;
				else y = i + 1, x = j, ver = false;
			}
			else if (tmp[j] == 'E' && X < 0) {
				if (j < N - 1 && tmp[j + 1] == 'E') Y = i, X = j + 1;
				else Y = i + 1, X = j, VER = false;
			}
		}
	}
//	cout << "now:  " << y << "," << x << "," << (ver ? 1 : 0) << "\n";
//	cout << "goal: " << Y << "," << X << "," << (VER ? 1 : 0) << "\n";

	bool cost[50][50][2];//[y][x][0]: y,x,세로  [y][x][1]: y,x,가로
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cost[i][j][0] = cost[i][j][1] = false;
	}

	queue<pair<int, int>> Q;
	if (ver) Q.push({ y,x });
	else Q.push({ -y,-x });
	cost[y][x][ver] = true;

	int qsize = 1, ans = 0;
	while (qsize) {
		while (qsize--) {
			y = Q.front().first;
			x = Q.front().second; Q.pop();
			
			if (y < 0 || x < 0) {
				y *= (-1), x *= (-1);
				if (y == Y && x == X && !VER) { cout << ans; return 0; }

				int c = cost[y][x][0] + 1;
				bool tl = false, tr = false;

				// up & down
				if (y > 1 && b[y - 2][x])
					if (!cost[y - 1][x][0]) Q.push({ 1 - y,-x }), cost[y - 1][x][0] = true;
				if (y < N - 2 && b[y + 2][x])
					if (!cost[y + 1][x][0]) Q.push({ -1 - y,-x }), cost[y + 1][x][0] = true;

				// left & right & turn
				if (x && b[y - 1][x - 1] && b[y][x - 1] && b[y + 1][x - 1]) {
					tl = true;
					if (!cost[y][x - 1][0]) Q.push({ -y,1 - x }), cost[y][x - 1][0] = true;
				}
				if (x < N - 1 && b[y - 1][x + 1] && b[y][x + 1] && b[y + 1][x + 1]) {
					tr = true;
					if (!cost[y][x + 1][0]) Q.push({ -y,-1 - x }), cost[y][x + 1][0] = true;
				}
				if (tl && tr && !cost[y][x][1]) Q.push({ y,x }), cost[y][x][1] = true;
			}
			else {
				if (y == Y && x == X && VER) { cout << ans; return 0; }

				int c = cost[y][x][1] + 1;
				bool tu = false, td = false;

				// left & right
				if (x > 1 && b[y][x - 2])
					if (!cost[y][x - 1][1]) Q.push({ y,x - 1 }), cost[y][x - 1][1] = true;
				if (x < N - 2 && b[y][x + 2])
					if (!cost[y][x + 1][1]) Q.push({ y,x + 1 }), cost[y][x + 1][1] = true;

				// up & down & turn
				if (y && b[y - 1][x - 1] && b[y - 1][x] && b[y - 1][x + 1]) {
					tu = true;
					if (!cost[y - 1][x][1]) Q.push({ y - 1,x }), cost[y - 1][x][1] = true;
				}
				if (y < N - 1 && b[y + 1][x - 1] && b[y + 1][x] && b[y + 1][x + 1]) {
					td = true;
					if (!cost[y + 1][x][1]) Q.push({ y + 1,x }), cost[y + 1][x][1] = true;
				}
				if (tu && td && !cost[y][x][0]) Q.push({ -y,-x }), cost[y][x][0] = true;
			}
		}
		ans++; qsize = Q.size();
	}

	cout << 0; return 0;
}