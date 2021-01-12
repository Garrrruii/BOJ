// code nicely
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int N, tmp, a[1000] = { 0, };
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i) scanf("%d", &tmp), a[i] = tmp - a[i];

	int tar = a[0], ans = 0;
	for (int i = 1; i < N; ++i) {
		if (tar * a[i] < 0) ans += abs(tar);
		else if (abs(tar) > abs(a[i])) ans += abs(tar - a[i]);
		tar = a[i];
	}
	printf("%d", ans + abs(tar)); return 0;
}

/*
5
3 3 3 3 3 4 5 1 0 2
 
a[i] tar ans
  2   1   0
 -2   2  +2
 -3  -2  +1
 -1  -3  +2

3  3  3  3  3
1  1
   1  1        => 2
     -1 -1 -1  => 1
	 -2 -2     => 2
4  5  1  0  2
*/