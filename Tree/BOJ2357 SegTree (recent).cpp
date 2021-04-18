#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> T[262145];
int x[100001];
pair<int, int> Build(int n, int s, int e) {
	if (s == e) T[n] = { x[s],x[s] };
	else {
		n <<= 1;
		int m = (s + e) / 2;
		pair<int, int> L = Build(n, s, m);
		pair<int, int> R = Build(n + 1, m + 1, e);
		n >>= 1;
		T[n] = { min(L.first, R.first),max(L.second, R.second) };
	}
	return T[n];
}
pair<int,int> Query(int n, int s, int e, int i, int j){
	if (s == i && e == j) return T[n];

	n <<= 1;
	int m = (s + e) / 2;
	if (j <= m) return Query(n, s, m, i, j);
	else if (i > m) return Query(n + 1, m + 1, e, i, j);
	else {
		pair<int, int> L = Query(n, s, m, i, m);
		pair<int, int> R = Query(n + 1, m + 1, e, m + 1, j);
		return { min(L.first,R.first),max(L.second,R.second) };
	}
}
int main() {
	int N, M, a, b;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d", &x[i]);

	Build(1, 1, N);

	while (M--) {
		scanf("%d%d", &a, &b);
		pair<int, int> ANS = Query(1, 1, N, a, b);
		printf("%d %d\n", ANS.first, ANS.second);
	}
	return 0;
}