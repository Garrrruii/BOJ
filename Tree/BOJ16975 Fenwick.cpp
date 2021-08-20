#include <iostream>
using namespace std;

int N;
long long fen[100001];
void upd(int i, int j, int n) {
	while (i <= N) fen[i] += n, i += (i & -i);
	while (j <= N) fen[j] -= n, j += (j & -j);
}
long long sum(int i) {
	long long ret = 0;
	while (i) ret += fen[i], i -= (i & -i);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long a[100001];
	int M, n, q, i, j, k;

	cin >> N;
	for (i = 1; i <= N; ++i) cin >> a[i];
	cin >> M;
	while (M--) {
		cin >> q;
		if (q & 1) {
			cin >> i >> j >> k; upd(i, j + 1, k);
		}
		else {
			cin >> i;
			cout << a[i] + sum(i) << "\n";
		}
	}
	return 0;
}