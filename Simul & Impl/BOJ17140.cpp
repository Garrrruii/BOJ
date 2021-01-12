//2D array and operation
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int r0, c0, k0;
	scanf("%d%d%d", &r0, &c0, &k0); r0--; c0--;
	int A[100][100] = { 0, };
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) scanf("%d", &A[i][j]);
	}

	int R = 3, C = 3, T = 0;
	while (T < 101) {
		if (A[r0][c0] == k0) break;
		if (T == 100) { T = -1; break; }

		T++;
		if (R >= C) {
			//행 정렬
			int NC = 0;
			for (int r = 0; r < R; ++r) {
				int cnt[101] = { 0, };
				vector<pair<int, int>> v;
				for (int j = 0; j < C; ++j) if(A[r][j]) cnt[A[r][j]]++;
				for (int j = 0; j < 101; ++j) if (cnt[j]) v.push_back({ j,cnt[j] });
				sort(v.begin(), v.end(), comp);

				int idx = 0;
				int n = min(50, (int)v.size());
				for (int j = 0; j < n; ++j) {
					A[r][idx++] = v[j].first, A[r][idx++] = v[j].second;
				}
				if (idx > NC) NC = idx;
				while (idx < C) A[r][idx++] = 0;
			}
			C = NC;
		}
		else {
			//열 정렬
			int NR = 0;
			for (int c = 0; c < C; ++c) {
				int cnt[101] = { 0, };
				vector<pair<int, int>> v;
				for (int i = 0; i < R; ++i) if(A[i][c]) cnt[A[i][c]]++;
				for (int i = 0; i < 101; ++i) if (cnt[i]) v.push_back({ i,cnt[i] });
				sort(v.begin(), v.end(), comp);

				int idx = 0;
				int n = min(50, (int)v.size());
				for (int i = 0; i < n; ++i) {
					A[idx++][c] = v[i].first, A[idx++][c] = v[i].second;
				}
				if (idx > NR) NR = idx;
				while (idx < R) A[idx++][c] = 0;
			}
			R = NR;
		}/*
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) printf("%d ", A[i][j]);
			printf("\n");
		}
		printf("\n");*/
	}
	printf("%d", T);
	return 0;
}