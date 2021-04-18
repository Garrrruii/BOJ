#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[100001];
long long T[262145];
struct query {
	int k, i, j, ord;
	long long val;
};
vector<query> Q2;
vector<pair<int,int>> Q1;
bool sort_by_k(query A, query B) { return A.k < B.k; }
bool sort_by_ord(query A, query B) { return A.ord < B.ord; }

long long Build(int n, int s, int e) {
	if (s == e) T[n] = (long long)A[s];
	else {
		int m = (s + e) >> 1;
		T[n] = Build(n << 1, s, m) + Build((n << 1) + 1, m + 1, e);
	}
	return T[n];
}
long long Sum(int n, int s, int e, int i, int j) {
	if (s == i && e == j) return T[n];

	int m = (s + e) >> 1;
	if (j <= m) return Sum(n << 1, s, m, i, j);
	else if (i > m) return Sum((n << 1) + 1, m + 1, e, i, j);
	else return (Sum(n << 1, s, m, i, m) + Sum((n << 1) + 1, m + 1, e, m + 1, j));
}
void Update(int n, int s, int e, int idx, long long dif) {
	T[n] += dif;
	if (s == e) return;

	int m = (s + e) >> 1;
	if (idx <= m) Update(n << 1, s, m, idx, dif);
	else Update((n << 1) + 1, m + 1, e, idx, dif);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int ai = 1; ai <= N; ++ai) scanf("%d", &A[ai]);
	Build(1, 1, N);

	int M, q, k, i, j, ord = 0;
	long long v;
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d%d", &i, &v);
			Q1.push_back({ i,v });
		}
		else {
			scanf("%d%d%d", &k, &i, &j);
			Q2.push_back({ k - 1, i, j, ord++, 0 });
		}
	}
	sort(Q2.begin(), Q2.end(), sort_by_k);

	for (q = 0, ord = 0; q < Q2.size(); ++q) {
		while (Q2[q].k >= ord && ord < Q1.size()) {
			int pos = Q1[ord].first;
			long long dif = Q1[ord].second - (long long)A[pos];
			A[pos] = Q1[ord].second;
			Update(1, 1, N, pos, dif);
			ord++;
		}
		Q2[q].val = Sum(1, 1, N, Q2[q].i, Q2[q].j);
	}

	sort(Q2.begin(), Q2.end(), sort_by_ord);
	for (q = 0; q < Q2.size(); ++q) printf("%lld\n", Q2[q].val);
	return 0;
}
/*
5 1 2 3 4 5
10
1 2 5
2 0 1 3
2 1 1 3
1 4 2
2 0 2 5
2 1 2 5
2 2 2 5
1 1 2
2 3 1 1
2 3 1 5

k
0	1 2 3 4 5
1	1 5 3 4 5
2	1 5 3 2 5
3	2 5 3 2 5
*/