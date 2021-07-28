#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int c[101], N;
bool e[101][101];

int ord[101], num = 0, ans = 0;
bool fin[101];
stack<int> S;

int dfs(int cur) {
	ord[cur] = ++num;
	S.push(cur);

	int par = ord[cur];
	for (int nxt = 1; nxt <= N; ++nxt) {
		if (!e[cur][nxt]) continue;

		if (!ord[nxt]) par = min(par, dfs(nxt));		//�������� ���� ���̸� �湮�غ�
		else if (!fin[nxt]) par = min(par, ord[nxt]);	//�湮�� ���̸� par����
	}

	if (par == ord[cur]) {
		int cost = 987654321;
		//���� stack�� �ִ� �ֵ� �� cur���� scc�� �̷��.
		while (1) {
			int v = S.top(); S.pop();
			cost = min(cost, c[v]); fin[v] = true;
			if (v == cur) break;
		}
		ans += cost;
		//printf("+%d at %d\n", cost, cur);
	}
	return par;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	char in[101];
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> c[i];
	for (int i = 1; i <= N; ++i) {
		cin >> in;
		for (int j = 1; j <= N; ++j) if (in[j-1] == '1') e[i][j] = true;	
	}
		
	for (int i = 1; i <= N; ++i) if (!ord[i]) dfs(i);

	cout << ans; return 0;
}
/*
5
1 2 3 4 5
00011
10000
00010
00100
01000
(4)

7
5 2 3 4 1 2 3
0001100
1000000
0001011
0010000
0100000
0000000
0001000
(6)
*/