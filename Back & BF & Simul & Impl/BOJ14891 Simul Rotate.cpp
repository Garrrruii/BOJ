#include <iostream>
#include <queue>
using namespace std;
/*     0
     7   1
   6       2
     5   3
       4     */
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	char G[5][9]; //Gear
	int K, idx, dir;
	cin >> G[1] >> G[2] >> G[3] >> G[4];
	
	int d[5];
	cin >> K;
	while (K--) {
		cin >> idx >> dir;
		if (dir < 0) dir += 8;
		
		//Åé´Ï¹ÙÄû º° ¹æÇâ
		d[1] = d[2] = d[3] = d[4] = 0; d[idx] = dir;
		for (int i = idx - 1; i; --i) {
			if (G[i + 1][6] != G[i][2]) d[i] = 8 - d[i + 1];
			else break;
		}
		for (int i = idx + 1; i <= 4; ++i) {
			if (G[i - 1][2] != G[i][6]) d[i] = 8 - d[i - 1];
			else break;
		}
		
		//°¢ Åé´Ï¹ÙÄû È¸Àü
		for (int i = 1; i <= 4; ++i) {
			if (!d[i]) continue;

			for (int j = 0, k = d[i]; j < 8; ++j, ++k) {
				if (k & 8) k = 0;
				G[0][k] = G[i][j];
			}
			for (int j = 0; j < 8; ++j) G[i][j] = G[0][j];
		}

		//cout << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << "\n";
		//for (int i = 1; i <= 4; ++i) {
		//	for (int j = 0; j < 8; ++j) cout << G[i][j]; cout << "\n";
		//} cout << "\n";
	}

	int ANS = 0;
	for (int i = 1, j = 1; i <= 4; ++i, j <<= 1) if (G[i][0] == '1') ANS += j;
	cout << ANS; return 0;
}