#include <iostream>
#include <vector>
using namespace std;

int fen[100001];
int in[100001], out[100001], cnt;
vector<int> e[100001];
void dfs(int cur) {	//각 vertex의 in,out order 매기기
	in[cur] = ++cnt;
	for (int nxt : e[cur]) dfs(nxt);
	out[cur] = cnt;
}
void upd_(int i, int j, int x) { // update i~j-1 +x
	while (i < cnt) fen[i] += x, i += (i & -i);
	while (j < cnt) fen[j] -= x, j += (j & -j);
}
int sum_(int i) { // get sum of 1~i (0은 필요X, 사장은 상사가 없음)
	int ret = 0;
	while (i) ret += fen[i], i -= (i & -i);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, id;
	cin >> n >> m; cin >> id;
	for (int i = 2; i <= n; ++i) cin >> id, e[id].push_back(i);
	dfs(1); ++cnt;

	int q, w;
	while (m--) {
		cin >> q >> id;
		if (q & 1) cin >> w, upd_(in[id], out[id] + 1, w); //in[id]~out[id] +w
		else cout << sum_(in[id]) << "\n";
	}
	return 0;
}