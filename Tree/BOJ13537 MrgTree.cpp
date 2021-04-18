#include <cstdio>
#include <vector>
#include <algorithm>
#define SIZE 262145
using namespace std;

typedef long long ll;

vector<ll> T[SIZE];
void Update(int n, int s, int e, int idx, ll val) {
	T[n].push_back(val);
	if (s == e) return;

	int m = (s + e) / 2;
	n <<= 1;
	if (idx <= m) Update(n, s, m, idx, val);
	else Update(n + 1, m + 1, e, idx, val);
}
int Query(int n, int s, int e, int i, int j, ll val) {
	if (i == s && e == j) {
		return (T[n].end() - upper_bound(T[n].begin(), T[n].end(), val));
	}
	int m = (s + e) / 2;
	n <<= 1;
	if (j <= m) return Query(n, s, m, i, j, val);
	else if (i > m) return Query(n + 1, m + 1, e, i, j, val);
	else return Query(n, s, m, i, m, val) + Query(n + 1, m + 1, e, m + 1, j, val);
}
int main() {
	int N, M, i, j;
	long long k;
	scanf("%d", &N);
	for (int idx = 1; idx <= N; ++idx) scanf("%lld", &k), Update(1, 1, N, idx, k);
	for (int num = 1; num < SIZE; ++num) sort(T[num].begin(), T[num].end());

	scanf("%d", &M);
	while (M--) {
		scanf("%d%d%lld", &i, &j, &k);
		printf("%d\n", Query(1, 1, N, i, j, k));
	}
	return 0;
}