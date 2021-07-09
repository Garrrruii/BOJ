//#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int w[100001];
int par[100001];

int Find(int cur) {
	int old_par = par[cur];
	if (par[old_par] == old_par) return old_par;

	int new_par = Find(old_par);
	w[cur] += w[old_par];
	par[cur] = new_par;
	return new_par;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M, a, b, c;
	char q;

	while (1) {
		cin >> N >> M;// scanf("%d%d", &N, &M);
		if (!N) return 0;
		for (int i = 1; i <= N; ++i) par[i] = i, w[i] = 0;
		
		while (M--) {
			cin >> q >> a >> b;// scanf("%c",&q); scanf("%c%d%d", &q, &a, &b);
			int para = Find(a);
			int parb = Find(b);

			if (q == '!') {
				cin >> c;// scanf("%d", &c);

				if (para < parb) w[parb] += (w[a] + c - w[b]), par[parb] = para;
				else w[para] += (w[b] - c - w[a]), par[para] = parb;
			}
			else{
				if (para != parb) cout << "UNKNOWN\n";// printf("UNKNOWN\n");
				else cout << w[b] - w[a] << "\n";// printf("%d\n", w[b] - w[a]);
			}
		}
	}
}
/*
7 11
! 4 3 5
! 2 3 10
? 4 2
! 6 7 15
? 2 6
! 1 2 10
? 1 4
! 5 6 10
! 6 3 5
? 7 4
? 1 5
-5 UNKNOWN 15 -15 5
*/