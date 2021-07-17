#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int s, p, c;	//이모티콘 수, 복사한 이모티콘 수, 연산 수
};
bool operator<(node A, node B) {
	return A.c > B.c;
}

priority_queue<node> pq;
int cnt[1001][1001];

int main() {
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) cnt[i][j] = 987654321;
	}

	int S;
	scanf("%d", &S);

	int s, p, c, ns, np, nc;
	cnt[1][0] = 0; pq.push({ 1,0,0 });
	while (!pq.empty()) {
		s = pq.top().s;
		p = pq.top().p;
		c = pq.top().c; pq.pop();
		if (s == S) { printf("%d", c); return 0; }
		if (c > cnt[s][p]) continue;
		c++;

		// 클립보드 갱신	p->s
		if (c < cnt[s][s]) cnt[s][s] = c, pq.push({ s,s,c });

		// 붙여넣기			s->s+p
		ns = s + p;
		if (p && ns < 1001 && c < cnt[ns][p]) cnt[ns][p] = c, pq.push({ ns,p,c });

		// 삭제				s->s-1
		ns = s - 1;
		if (s && c < cnt[ns][p]) cnt[ns][p] = c, pq.push({ ns,p,c });
	}
/* 더 짧고 효율적인 코드

	int cnt[1001], S;

	scanf("%d", &S);
	for (int s = 2; s < 1001; s++) cnt[s] = s;

	for (int s = 2; s < 501; s++) {
		for (int n = 2; n < 1001; n++) {
			int ns = s * n;
			if (ns < 1001) cnt[ns] = cnt[ns] < (cnt[s] + n) ? cnt[ns] : (cnt[s] + n);
			//cnt[s]+n(복붙)와 비교, 더 작은 것
			if (n < 1000) cnt[n] = cnt[n] < (cnt[n + 1] + 1) ? cnt[n] : (cnt[n + 1] + 1);
			//cnt[n+1]-1cnt[n]와 비교, 더 작은 것
		}
	}
	printf("%d", cnt[S]);
*/
	return 0;
}