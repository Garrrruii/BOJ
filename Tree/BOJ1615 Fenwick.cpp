#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> p[1999000];
long long fen[2001], N;
void upd(int idx) {
	while (idx <= N) {
		fen[idx]++; idx += (idx & -idx);
	}
}
long long sum(int idx) {
	long long res = 0;
	while (idx) {
		res += fen[idx]; idx -= (idx & -idx);
	}
	return res;
}
bool sortp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first < B.first;
}
int main() {
	int M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + M, sortp);
	long long ANS = 0;
	for (int i = 0; i < M; ++i) {
		ANS += (sum(N) - sum(p[i].second));
		upd(p[i].second);
	}
	printf("%lld", ANS);
	return 0;
}