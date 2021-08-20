#include <iostream>
#include <vector>
using namespace std;

int fen[500001];
int idx[500001][2], cnt;
vector<int> jr[500001];

void dfs(int cur) {
	idx[cur][0] = ++cnt;
	for (int nxt : jr[cur]) dfs(nxt);
	idx[cur][1] = cnt;
}
void upd_(int i, int j, int x) {
	while (i < cnt) fen[i] += x, i += (i & -i);
	while (j < cnt) fen[j] -= x, j += (j & -j);
}
int sum_(int i) {
	int ret = 0;
	while (i) ret += fen[i], i -= (i & -i);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a[500001];
	int N, M, i, x, sup;
	char q;
	cin >> N >> M >> a[1];
	for (i = 2; i <= N; ++i) cin >> a[i] >> sup, jr[sup].push_back(i);
	dfs(1); ++cnt;

	while (M--) {
		cin >> q >> i;
		if (q == 'p') {
			cin >> x;
			upd_(idx[i][0] + 1, idx[i][1] + 1, x);
		}
		else cout << a[i] + sum_(idx[i][0]) << "\n";
	}
	return 0;
}