#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M, K, x, y, z;
	int b[10][10], a[10][10];
	map<int, int> T[10][10][2];
	int di[8] = { 1,1,1,0,-1,-1,-1,0 };
	int dj[8] = { -1,0,1,1,1,0,-1,-1 };
	int dead[10][10], baby_cnt[10][10];
	int cur = 0, nxt = 1;

	// Get Input
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j) cin >> a[i][j];
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j) b[i][j] = 5;
	while (M--) cin >> x >> y >> z, T[x-1][y-1][0].insert({ z,1 });

	
	while (K--) {
		// Initiation
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) 
				dead[i][j] = 0, baby_cnt[i][j] = 0, T[i][j][nxt].clear();
		
		// Grow & Dead
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (auto t = T[i][j][cur].begin(); t != T[i][j][cur].end(); t++) {
					int age = t->first;
					int total_cnt = t->second;
					int grow_cnt = min(b[i][j] / age, total_cnt);

					//먹은 양분, 죽은 양분 계산
					b[i][j] -= age * grow_cnt;
					dead[i][j] += ((age >> 1)* (total_cnt - grow_cnt));

					//자란 애들
					if (!grow_cnt) continue;
					T[i][j][nxt].insert({ age + 1 ,grow_cnt });

					//번식
					if (age % 5 < 4) continue;
					for (int d = 0; d < 8; ++d) {
						x = i + di[d], y = j + dj[d];
						if (x >= 0 && x < N && y >= 0 && y < N) baby_cnt[x][y]+=grow_cnt;
					}
				}
			}
		}

		// Add
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				//아기 나무 nxt에 추가
				if (baby_cnt[i][j]) T[i][j][nxt].insert({ 1,baby_cnt[i][j] });
				
				//죽은 나무 양분, 겨울 양분 b에 추가
				b[i][j] += dead[i][j] + a[i][j];
			}
		}

		// Next Turn
		cur = 1 - cur, nxt = 1 - nxt;

		// Print
		/*cout << "\nK=" << K << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cout << b[i][j] << " ";
			cout << "\n";
		}*/
	}

	// Count Answer
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (auto t = T[i][j][cur].begin(); t != T[i][j][cur].end(); t++) ans += t->second;
		}
	}
	cout << ans; return 0;
}