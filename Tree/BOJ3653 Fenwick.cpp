#include <cstdio>
using namespace std;

int book[100001]; //book[i] i가 몇층에
int fen[200001];  //몇층에 책이 있다 (맨 위층이 1층)
void upd(int idx, bool plus) {
	if (plus) while (idx <= 200000) fen[idx]++, idx += (idx & -idx);
	else while (idx <= 200000) fen[idx]--, idx += (idx & -idx);
}
int sum(int idx) {
	int res = 0;
	while (idx) res += fen[idx], idx -= (idx & -idx);
	return res;
}
int main() {
	int T, N, M, booknum, pos, top;
	scanf("%d", &T);
	while (T--) {
		for (int i = 1; i <= 200000; ++i) fen[i] = 0;

		scanf("%d%d", &N, &M);
		top = 200001 - N;
		for (int i = 1; i <= N; ++i) book[i] = top + i - 1;
		for (int i = top; i <= 200000; ++i) upd(i, true);
		
		while(M--) {
			scanf("%d", &booknum);
			pos = book[booknum];

			printf("%d ", sum(pos-1));
			upd(pos, false); upd(--top, true);
			book[booknum] = top;
		}
		printf("\n");
	}
	return 0;
}