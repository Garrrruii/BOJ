#include <cstdio>
#include <vector>
#include <algorithm>
#define P 1000000007
using namespace std;

vector<int> e[500];
bool sortbysize(int A, int B) {
	return e[A].size() > e[B].size();
}
bool vis[500];
bool cyc[500];
long long fac[501];

long long dfs(int cur) {
	vis[cur] = true;
	if (e[cur].empty()) return 1;

	long long res;
	for (int nxt : e[cur]) {
		if (!vis[nxt]) {
			res = dfs(nxt);
			if (!cyc[cur] && cyc[nxt]) {
				res *= (long long)e[cur].size();
				res %= P;
				//printf("choose n1\tcur=%d, return %lld\n", cur, res);
				//cur -> cycle: cycle �� vertex ������ŭ ������� ��
			}
			else {
				//printf("in cycle\tcur=%d, return %lld\n", cur, res);
				//cycle ���ο� ����. �״�� return
			}
			return res;
		}
	}

	//��� nxt�� �̹� �湮�� ����
	int nxt = e[cur][0];
	if (cyc[nxt]) {
		//printf("choose n2\tcur=%d, return %d\n", cur, e[nxt].size());
		//cur -> cycle: cycle �� vertex ������ŭ ������� ��
		return (long long)e[cur].size();
	}
	else if (e[cur].size() == e[nxt].size()) {
		//printf("IS CYCLE\tcur=%d, return %lld\n", cur, fac[e[cur].size()]);
		//cycle�� ó���� ã��, ��� cycleǥ�� �� return factorial(num)
		cyc[cur] = true;
		for (int v : e[cur]) cyc[v] = true;
		return fac[e[cur].size()];
	}
	else {
		//printf("just,one\tcur=%d, return 1\n", cur);
		//������ �� �ϳ�����
		return 1;
	}
}
int main() {
	fac[0] = fac[1] = 1; fac[2] = 2;
	for (long long n = 3; n <= 500; ++n) fac[n] = (fac[n - 1] * n) % P;

	int N, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp);
			if (tmp && i!=j) e[i].push_back(j);
		}
	}
	for (int i = 0; i < N; ++i) {
		sort(e[i].begin(), e[i].end(), sortbysize);
	}

	long long ans = 1;
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) ans *= dfs(i), ans %= P;
	}
	printf("%lld", ans); return 0;
}