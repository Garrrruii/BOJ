#include <cstdio>
using namespace std;

int par[51];
int find_(int a) {
	if (a == par[a]) return a;
	int para = find_(par[a]); par[a] = para;
	return para;
}
int main() {
	int N, M, K, a, b;
	bool know[51] = { false, };
	int party[51] = { 0, };

	scanf("%d%d%d", &N, &M, &K);
	if (!K) { printf("%d", M); return 0; }

	while (K--) scanf("%d", &a), know[a] = true;

	for (int i = 1; i <= N; ++i) par[i] = i;
	for (int m = 0; m < M; ++m) {
		scanf("%d", &K);
		if (!K) continue;
		int para, parb;
		
		scanf("%d", &para); K--;
		while (K--) {
			scanf("%d", &b);

			para = find_(para);
			parb = find_(b);
			if (know[para]) par[parb] = para, know[parb] = know[b] = true;
			else if (know[parb]) par[para] = parb, know[para] = true;
			else par[parb] = para; //union할 때 par끼리 함에 주의
		}
		party[m] = para;

/*		printf("par : ");
		for (int i = 1; i <= N; ++i) printf("%d ", par[i]);
		printf("\nknow: ");
		for (int i = 1; i <= N; ++i) printf("%d ", (know[i]?1:0));
		printf("\n\n");*/
	}

	int ANS = 0;
	for (int m = 0; m < M; ++m) {
		if (!know[find_(party[m])]) ANS++;
	}
	printf("%d", ANS);
	return 0;
}
/*
10 8
3 1 2 10
2 2 3
2 3 4
2 1 2 
2 6 7 
2 5 6
2 8 9
2 3 6
1 10
(1)
*/