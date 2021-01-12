//lock
#include <cstdio>
using namespace std;

int main() {
	int a[501], N, k1, k2, p, q, x, tmp;// , y;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);

	k1 = k2 = p = q = x = 0;//= y = 0;
	for (int i = 1; i < N; ++i) {
		if (a[i] == 1) x = i;

		tmp = a[i + 1] - a[i];
		if (tmp == 1 || tmp == -1 || tmp == N - 1 || tmp == 1 - N) continue;

		if (!p) p = i + 1;
		else if (!q) q = i;
	}
	if (!p && !q) p = 1, q = N;			//(87654321)
	else if (!q) q = p - 1, p = 1;		//4321)(8765
	if (!x) x = N;

	if (a[p] == a[p + 1] - 1 || (a[p] == N && a[p + 1] == 1)) {
		tmp = p, p = q + 1, q = tmp - 1;
		k2 = N - p + 1, p = 1, q += k2, x += k2;
		if (x > N) x -= N;
	}
	else k2 = N;
	//if:   654)8123(7 7)3456(218
	//else: 7(218)3456 4(765)8123

//	printf("p=%d q=%d x=%d\n", p, q, x);

	if (p <= x && x <= q) k1 = N - p - q + x + 1;
	else k1 = N - x + 1;
	//if:   7(218)3456 7)3456(218
	//else: 654)8123(7 4(765)8123

	printf("%d\n%d %d\n%d\n", k1, p, q, k2);
	return 0;
}

/*
8 7 2 1 8 3 4 5 6

8 4 7 6 5 8 1 2 3

8 6 5 4 8 1 2 3 7

8 7 3 4 5 6 2 1 8

8 8 7 6 5 4 3 2 1

8 4 3 2 1 8 7 6 5

0
*/