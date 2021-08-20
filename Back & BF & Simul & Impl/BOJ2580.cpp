//sudoku
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[9][9];
bool chk[10][3][9] = { false, }, findans = false;
vector<pair<int, int>> zero;

void solve(int z) {
	if (z == zero.size()) {
		findans = true;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) printf("%d ", A[i][j]);
			printf("\n");
		}
		return;
	}
	else {
		for (int num = 1; num < 10; ++num) {
			int row = zero[z].first;
			int col = zero[z].second;
			int cell = (row / 3) * 3 + (col / 3);
			if (chk[num][0][row] || chk[num][1][col] || chk[num][2][cell]) continue;
			chk[num][0][row] = chk[num][1][col] = chk[num][2][cell] = true;
			A[row][col] = num; solve(z + 1);
			if(!findans) chk[num][0][row] = chk[num][1][col] = chk[num][2][cell] = false;
		}
	}
	
}
int main() {
	int tmp;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &tmp); A[i][j] = tmp;
			if (!tmp) zero.push_back({ i,j });
			else chk[tmp][0][i] = chk[tmp][1][j] = chk[tmp][2][(i / 3) * 3 + (j / 3)] = true;
		}
	}
	solve(0);
	return 0;
}