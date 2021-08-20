#include <iostream>
#include <vector>
using namespace std;

int cnt, in[100001], out[100001], fen[100010];
vector<int> jr[100001];

void dfs(int cur) {
	//in[cur]  cur ���� ����
	//out[cur] cur Ž�� ���� ����
	//in[cur]<in[nxt]<out[nxt]<out[cur]

	in[cur] = ++cnt;
	for (int nxt : jr[cur]) dfs(nxt);
	out[cur] = cnt;
}
void upd_(int idx, int w) {
	while (idx < cnt) fen[idx] += w, idx += (idx & -idx);
}
int sum_(int idx) {
	int ret = 0;
	while (idx) ret += fen[idx], idx -= (idx & -idx);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, q, id, w;

	cin >> N >> M >> id;
	for (int i = 2; i <= N; ++i) cin >> id, jr[id].push_back(i);
	dfs(1); ++cnt; //in,out�� 1���� ����

	while (M--) {
		cin >> q >> id;
		// 1 id w  id ������ ���� ���Ϸκ��� w��ŭ Ī�� ����
		// 2 id    id ������ Ī�� ������ ���

		if (q & 1) cin >> w, upd_(in[id], w);
		else cout << sum_(out[id]) - sum_(in[id] - 1) << "\n";
		//in[id]~out[id]�� ��� => �� �ȿ� cur & �Ĺ� Ī�� ����� ����
	}
	return 0;
}