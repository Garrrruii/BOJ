#include <iostream>
#include <vector>
using namespace std;

int cnt, in[100001], out[100001], fen[100010];
vector<int> jr[100001];

void dfs(int cur) {
	//in[cur]  cur 도착 순서
	//out[cur] cur 탐색 종료 순서
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
	dfs(1); ++cnt; //in,out은 1부터 시작

	while (M--) {
		cin >> q >> id;
		// 1 id w  id 직원이 직속 부하로부터 w만큼 칭찬 받음
		// 2 id    id 직원의 칭찬 점수를 출력

		if (q & 1) cin >> w, upd_(in[id], w);
		else cout << sum_(out[id]) - sum_(in[id] - 1) << "\n";
		//in[id]~out[id]합 출력 => 이 안에 cur & 후배 칭찬 기록이 있음
	}
	return 0;
}