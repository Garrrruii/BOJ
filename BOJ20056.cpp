//wizard shark and fireball
//using mult ( only check whose size>1 )
//그러나 근본적으로 시간을 줄이는 건 포기함
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int N, M, K;
struct fireball {
	int r, c, m, s, d;
};
vector<fireball> F;
vector<int> map[50][50]; //map[r][c]
vector<pair<int, int>> mult;

int dc[8] = { 0,1,1,1,0,-1,-1,-1 }; //c
int dr[8] = { -1,-1,0,1,1,1,0,-1 }; //r

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		int i1, i2, i3, i4, i5;
		scanf("%d%d%d%d%d", &i1, &i2, &i3, &i4, &i5);

		F.push_back({ i1-1,i2-1,i3,i4,i5 });
	}
	while (K--) {
		vector<int> map[50][50]; //map[r][c]
		mult.clear();

		//move fireball
		for (int i = 0; i < F.size();i++) {
			if (!F[i].m) continue;
			int dd = F[i].d, ss = F[i].s % N;
			int nr = (F[i].r + dr[dd] * ss + N) % N;
			int nc = (F[i].c + dc[dd] * ss + N) % N;
			F[i].r = nr; F[i].c = nc;
			map[nr][nc].push_back(i);
			if (map[nr][nc].size() == 2) mult.push_back({ nr,nc });
		}
//		for (int i = 0; i < F.size(); i++) printf("F[%d]= %d,%d %d %d %d\n", i, F[i].r, F[i].c, F[i].m, F[i].s, F[i].d);
//		printf("\n");

		//merge&split fireball
		for (int i = 0; i < mult.size(); i++) {
			int rr = mult[i].first, cc = mult[i].second;
			int num = map[rr][cc].size();
			bool even = false, odd = false;
			int summ = 0, sums = 0;

			for (int k = 0; k < num; k++) {
				int tar = map[rr][cc][k];
				summ += F[tar].m; sums += F[tar].s;
				if (F[tar].d % 2) odd = true;
				else even = true;
				F[tar].m = 0;
			}
			summ /= 5; sums /= num;
			if (!summ) continue;
			
			for (int k = (!even || !odd) ? 0 : 1; k < 8; k += 2) F.push_back({ rr,cc,summ,sums,k });
		}
	}
//	for (int i = 0; i < F.size(); i++) printf("F[%d]= %d,%d %d %d %d\n", i, F[i].r, F[i].c, F[i].m, F[i].s, F[i].d);

	int ANS = 0;
	for (int i = 0; i < F.size();i++) ANS += F[i].m;

	printf("%d\n", ANS); return 0;
}