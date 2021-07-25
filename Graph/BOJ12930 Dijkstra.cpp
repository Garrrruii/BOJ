//two weight
//dijkstra
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, i, j, ans, w1[20][20], w2[20][20];
bool chk[20][200][200];
vector<int> e[20];

struct dij {
	int v, w1, w2, c;
};
bool operator<(dij A, dij B) {
	return A.c > B.c;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	cin >> N; char tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp != '.') w1[i][j] = tmp - '0', e[i].push_back(j);
		}
	}for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp != '.') w2[i][j] = tmp - '0';
		}
	}
	
	priority_queue<dij> PQ; PQ.push({ 0,0,0,0 });
	dij cur;
	chk[0][0][0] = true;
	bool ava = false;
	while (!PQ.empty()) {
		cur = PQ.top(); PQ.pop();
		int now = cur.v;

		if (now == 1) { ava = true; break; }
		for (j = 0; j < e[now].size(); j++) {
			int nex = e[now][j];
			int new1 = cur.w1 + w1[now][nex], new2 = cur.w2 + w2[now][nex];
			int newc = new1 * new2;

			if (chk[nex][new1][new2]) continue;
			chk[nex][new1][new2] = true;
			PQ.push({ nex,new1,new2,newc });
		}
	}

	if (ava) cout << cur.c << "\n";
	else cout << "-1\n";

	return 0;
}

/*
4
..11
...3
1..2
132.
..17
...1
1..2
712.
*/