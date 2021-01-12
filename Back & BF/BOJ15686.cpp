//chicken delivery
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int N, M, ANS = 987654321;
int b[50][50], dist[100][13] = { 0, };
vector<pair<int, int>> H, C;
int idx[13];

void delivery(int m, int k) {
	if (m==0) {
	//	for (int i = 0; i < M; ++i) printf("%d ", idx[i]);
	//	printf("\n");

		int val = 0;
		for (int h = 0; h < H.size(); ++h) {
			int r = H[h].first, c = H[h].second;
			int MINDIST = abs(r - C[idx[0]].first) + abs(c - C[idx[0]].second);
			for (int i = 1; i < M; ++i) {
				if (!dist[h][idx[i]]) dist[h][idx[i]] = abs(r - C[idx[i]].first) + abs(c - C[idx[i]].second);
				MINDIST = min(dist[h][idx[i]], MINDIST);
			}
			val += MINDIST;
		}
		ANS = min(ANS, val);
	}
	else {
		for (int i = k; i < C.size() - m + 1; ++i) {
			idx[M-m] = i; delivery(m - 1, i + 1);
		}
	}
}
int main() {

	int tmp;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp); b[i][j] = tmp;
			if (tmp == 1) H.push_back({ i,j });
			else if (tmp == 2) C.push_back({ i,j });
		}
	}

	for (int i = 0; i < C.size(); ++i) {
		idx[0] = i; delivery(M-1, i+1);
	}

	printf("%d", ANS); return 0;
}