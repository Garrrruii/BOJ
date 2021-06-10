//finding number
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[100000];
bool findnum(long long tar, int l, int r) {
//	printf("left=%d,  right=%d \n", l, r);
	if (l == r) return (tar == a[r]);
	if (l > r) return (tar == a[l] || tar == a[r]);
	
	int mid = (l + r) / 2;

	if (a[mid] > tar) return findnum(tar, l, mid);
	else if (a[mid] < tar) return findnum(tar, mid + 1, r);
	else return true;
}
int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", &a[i]);
	sort(a, a + N);
//	for (int i = 0; i < N; ++i) printf("%lld ", a[i]);

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		long long num;
		scanf("%lld", &num);

		if (findnum(num, 0, N-1)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
/*
int main() {
	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	sort(a, a + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		if (binary_search(ar, ar+N, num)) printf("1\n");
		else printf("0\n");
	}
}
*/