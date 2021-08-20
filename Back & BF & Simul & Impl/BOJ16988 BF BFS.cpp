#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M, b[20][20] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) cin >> b[i][j];
	
	bool vis[20][20] = { false, };
	vector<pair<int, int>> R[101];	//round
	vector<pair<int, int>> S[101];	//stone
	int di[4] = { 0,0,1,-1 };
	int dj[4] = { 1,-1,0,0 }, cnt = 0; //count number of group

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (b[i][j] < 2 || vis[i][j]) continue;
			
			int si = 0;
			S[cnt].push_back({ i,j }); vis[i][j] = true;
			while (si < S[cnt].size()) {
				int ci = S[cnt][si].first;
				int cj = S[cnt][si].second; si++;
				
				for (int d = 0; d < 4; ++d) {
					int ni = ci + di[d], nj = cj + dj[d];
					if (ni < 0 || ni >= N || nj < 0 || nj >= M || vis[ni][nj]) continue;
					vis[ni][nj] = true;
					if (b[ni][nj] & 2) S[cnt].push_back({ ni,nj });
					else R[cnt].push_back({ ni,nj });
				}
			}
			for (pair<int, int> p : R[cnt]) vis[p.first][p.second] = false;
			cnt++;
			// S[cnt] cnt번째 돌 집합
			// R[cnt] S[cnt]에 인접한 돌 테두리 => R[i], R[j]는 겹칠 수 있음
		}
	}
	/*for (int i = 0; i < cnt; ++i) {
		for (pair<int, int> s : S[i]) cout << s.first << "," << s.second << " ";
		cout << "\n";
		for (pair<int, int> r : R[i]) cout << r.first << "," << r.second << " ";
		cout << "\n\n";
	}*/

	int ANS = 0, TMP = 0;
	for (int y1 = 0; y1 < N; ++y1) {
		for (int x1 = 0; x1 < M; ++x1) {
			if (b[y1][x1]) continue;
			b[y1][x1] = 1;

			for (int x2 = x1 + 1; x2 < M; ++x2) {
				if (b[y1][x2]) continue;
				b[y1][x2] = 1;
				
				TMP = 0;
				for (int i = 0; i < cnt; ++i) {
					bool ava = true;
					for (pair<int, int> p : R[i]) {
						if (!(b[p.first][p.second] & 1)) { ava = false; break; }
					}
					if (ava) TMP += S[i].size();
				}
				if (ANS < TMP) ANS = TMP;// , cout << x1 << "," << y1 << " " << x2 << "," << y1 << " " << TMP << "\n";

				b[y1][x2] = 0;
			}
			for (int y2 = y1 + 1; y2 < N; ++y2) {
				for (int x2 = 0; x2 < M; ++x2) {
					if (b[y2][x2]) continue;
					b[y2][x2] = 1;
					
					TMP = 0;
					for (int i = 0; i < cnt; ++i) {
						bool ava = true;
						for (pair<int, int> p : R[i]) {
							if (!(b[p.first][p.second] & 1)) { ava = false; break; }
						}
						if (ava) TMP += S[i].size();
					}
					if (ANS < TMP) ANS = TMP;// , cout << x1 << "," << y1 << " " << x2 << "," << y1 << " " << TMP << "\n";

					b[y2][x2] = 0;
				}
			}

			b[y1][x1] = 0;
		}
	}
	cout << ANS; return 0;
}