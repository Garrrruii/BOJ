#include <iostream>
using namespace std;

typedef long long ll;

ll af[1000001], N;
ll bf[1000001];
void upda(int i, ll n) {
	while (i <= N) af[i] += n, i += (i & -i);
}
ll suma(int i, int j) {
	ll ret = 0;
	while (i) ret -= af[i], i -= (i & -i);
	while (j) ret += af[j], j -= (j & -j);
	return ret;
}
void updb(int i, int j, ll n) {
	while (i <= N) bf[i] += n, i += (i & -i);
	while (j <= N) bf[j] -= n, j += (j & -j);
}
ll updb(int i) {
	ll ret = 0;
	while (i) ret += bf[i], i -= (i & -i);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int M, K, q, L, R;
	long long n;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) cin >> n, upda(i, n);
	while (M || K) {
		cin >> q >> L >> R;
		if (q & 1) {
			cin >> n; M--;
			updb(L, R + 1, n), upda(L, n * (-L + 1)), upda(R + 1, n * R);
		}
		else {
			ll s = suma(L - 1, R) + updb(R) * R - updb(L - 1) * (L - 1);
			cout << s << "\n"; K--;
		}
	}
	return 0;
}