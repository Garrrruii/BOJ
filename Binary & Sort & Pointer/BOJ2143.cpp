//sum of two array
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//1. I used PQ
//2. vector is faster

vector<int> A, B;
int main() {
	int a[1000], b[1000], N, M, T, tmp;

	scanf("%d%d%d", &T, &N, &a[0]); A.push_back(a[0]);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &tmp), a[i] = a[i - 1] + tmp, A.push_back(a[i]);
		for (int j = 0; j < i; ++j) A.push_back(a[i] - a[j]);
	}
	scanf("%d%d", &M, &b[0]); B.push_back(b[0]);
	for (int i = 1; i < M; ++i) {
		scanf("%d", &tmp), b[i] = b[i - 1] + tmp, B.push_back(b[i]);
		for (int j = 0; j < i; ++j) B.push_back(b[i] - b[j]);
	}
	sort(A.begin(), A.end()); sort(B.begin(), B.end());

	long long CNT = 0;
	int ai = A.size()-1, bi = 0;
	while (ai>=0 && bi<B.size()) {
		int aa = A[ai], bb = B[bi];
		int tmp = aa + bb;
		if (tmp < T) while (bi<B.size() && B[bi] == bb) bi++;
		else if (tmp > T) while (ai>=0 && A[ai] == aa) ai--;
		else {
			long long k1 = 0, k2 = 0;
			while (ai >=0 && A[ai] == aa) ai--, k1++;
			while (bi < B.size() && B[bi] == bb) bi++, k2++;
			//	printf("%d + %d, +%d\n", aa, bb, k1 * k2);
			CNT += (k1 * k2);
		}
	}
	printf("%lld", CNT);
}
/*
10
10
9 2 3 8 1 -3 2 4 9 1
10
3 5 3 3 6 7 2 3 1 0

42
*/