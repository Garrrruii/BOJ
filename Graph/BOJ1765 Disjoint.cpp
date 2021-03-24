//choosing a cock-fight team
#include <cstdio>
using namespace std;
//my frnd's frnd  =my frnd
//my enemy's enemy=my frnd (NOT my FRND's enemy)
//frnd <=> same team
//how many team?

int N, t[1001];
void union_(int a, int b) {
	int tar, team;
	if (a == b) return;
	else if (a < b) team = a, tar = b;
	else team = b, tar = a;

	for (int n = 1; n <= N; ++n) if (t[n] == tar) t[n] = team;
}
int main() {
	int M, e[1001] = { 0, };
	bool ava[1001] = { false, };

	scanf("%d%d", &N, &M);
	for (int n = 1; n <= N; ++n) t[n] = n;
	for (int m = 0; m < M; ++m) {
		int p, q;
		char rel;
		scanf(" %c%d%d", &rel, &p, &q);

		if (rel == 'F') union_(t[p], t[q]);
		else {
			if (e[p]) union_(t[e[p]], t[q]);
			if (e[q]) union_(t[e[q]], t[p]);
			e[p] = q, e[q] = p;
		}
	}
	int CNT = 0;
	for (int n = 1; n <= N; ++n) {
		if (!ava[t[n]]) { CNT++; ava[t[n]] = true; }
	}
	printf("%d", CNT); return 0;
}
