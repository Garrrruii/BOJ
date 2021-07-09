#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> P;

int main() {
	int N, M, T, K, x, y;
	scanf("%d%d%d%d", &N, &M, &T, &K);
	P.resize(T);
	for (int t = 0; t < T; ++t) scanf("%d%d", &x, &y), P[t] = { x,y };

	int ax = 0, ay = 0, tmp = 0, ANS = 0;
	for (pii p1 : P) {
		for (pii p2 : P) {
			x = (p1.first + K > N) ? N - K : p1.first;
			y = (p2.second + K > M) ? M - K : p2.second;

			tmp = 0;
			for (pii p : P) {
				if (x > p.first || p.first > x + K) continue;
				else if (y > p.second || p.second > y + K) continue;
				else tmp++;
			}
			if (ANS < tmp) ANS = tmp, ax = x, ay = y;
		}
	}

	printf("%d %d\n%d", ax, ay + K, ANS);
	return 0;
}
/*
10 7 16 4
1 2 1 7 2 4 3 2 3 5 3 6 5 3 5 6
6 4 6 7 7 7 7 6 8 5 8 1 9 4 9 2
*/