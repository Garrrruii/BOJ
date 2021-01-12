//balloon
#include <cstdio>
#include <vector>
#include <algorithm>
#define s second
#define f first
using namespace std;

//mindist to give balloons
//1 move 1 balloon

bool comp(pair<int, pair<int, int>>A, pair<int, pair<int, int>>B) {
	return A.s.s - A.s.f > B.s.s - B.s.f;
}
int main() {
	int N, A, B, k, da, db, ANS;
	while (1) {
		scanf("%d%d%d", &N, &A, &B);
		if (!N) return 0;
		ANS = 0;
		vector<pair<int, pair<int, int>>> a, b;
		for (int i = 0; i < N; ++i) {
			scanf("%d%d%d", &k, &da, &db);
			if (da < db) a.push_back({ k,{da,db} });
			else if (da > db) b.push_back({ k,{da,db} });
			else ANS += k * da;
		}
		sort(a.begin(), a.end(), comp); sort(b.begin(), b.end(), comp);

		int ai = 0, bi = b.size() - 1;
		int as = a.size();
		while (A && ai < as) {
			k = a[ai].f;
			if (A < k) ANS += (A * a[ai].s.f), a[ai].f -= A, A = 0;
			else ANS += (k * a[ai].s.f), A -= k, ai++;
		}
		while (ai < as) { ANS += (a[ai].f * a[ai].s.s); ai++; }
		while (B && bi >= 0) {
			k = b[bi].f;
			if (B < k) ANS += (B * b[bi].s.s), b[bi].f -= B, B = 0;
			else ANS += (k * b[bi].s.s), B -= k, bi--;
		}
		while (bi >= 0) { ANS += (b[bi].f * b[bi].s.f); bi--; }
		printf("%d\n", ANS);
	}
}