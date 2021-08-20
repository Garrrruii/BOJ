#include <iostream>
#include <algorithm>
using namespace std;

int N, dep[1 << 18], idx[1 << 18], cnt;
void dfs(int cur, int d) {
	if (cur > N) return;
	dep[cur] = d; d++;

	dfs(cur << 1, d);
	idx[cnt++] = cur;
	dfs((cur << 1) | 1, d);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	const int inf = 0x3f3f3f3f;
	long long a[1 << 18];

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	dfs(1, 0);
	// dep     a         idx
	//  0      1          4          
	//  1    2   3  →  2   6
	//  2   4 5 6 7    1 3 5 7   

	long long ANS = -inf;
	for (int i = 0; i <= dep[N]; i++) {			//깊이 i부터
		for (int j = i; j <= dep[N]; j++) {		//j까지의 최대 합
			long long TMP = -inf;
			for (int k = 0; k < N; k++) {
				if (dep[idx[k]] < i || j < dep[idx[k]]) continue;

				TMP = max(TMP + a[idx[k]], a[idx[k]]);
				ANS = max(ANS, TMP);
			}
		}
	}
	cout << ANS; return 0;
}