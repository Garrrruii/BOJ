#include <cstdio>
using namespace std;

int a[100001], N;
int fen[100001];
void upd_(int idx) {
	while (idx <= N) fen[idx]++, idx += (idx & -idx);
}
int sum_(int idx) {
	int ret = 0;
	while (idx) ret += fen[idx], idx -= (idx & -idx);
	return ret;
}
int main() {
	int front;
	scanf("%d%d", &N, &front);
	int left, right, mid = front + 1;
	a[mid] = 1, upd_(mid);

	for (int i = 2; i <= N; ++i) {
		scanf("%d", &front);

		left = front + 1; right = N;
		mid = (left + right) >> 1;
		while (left < right) {
			if (mid - sum_(mid) <= front) left = mid + 1;
			else right = mid;
			mid = (left + right) >> 1;
		}
		a[mid] = i, upd_(mid);
	}
	for (int i = 1; i <= N; ++i) printf("%d ", a[i]);
	return 0;
}
/*
1~mid 자리 mid개
1~mid 남은 자리 mid-sum(mid)개
1~mid까지 남은 자리가 front+1개인 가장 작은 mid를 찾아야 함
*/