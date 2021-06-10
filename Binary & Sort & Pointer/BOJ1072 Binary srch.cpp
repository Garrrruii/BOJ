//game
#include <cstdio>
using namespace std;
//min cnt of game to change Z=Y/X
//if Z never change, -1
//binary search

long long X, Y, Z;
long long findk(long long l, long long r) {
//	printf("left=%lld right=%lld ", l, r);
	if (l >= r) {
//		printf("\n");
		long long tar = 100 * (Y + r) / (X + r);
		if (tar > Z) return r;

		tar = 100 * (Y + l) / (X + l);
		if (tar > Z) return l;
		else return -1;
	}
	long long mid = (l + r) / 2;
	long long tar = 100 * (Y + mid) / (X + mid);
//	printf(" => mid=%lld, tar=%lld\n", mid, tar);1
	if (tar <= Z) return findk(mid+1, r);
	else return findk(l, mid);
}
int main() {
	scanf("%lld%lld", &X, &Y);
	Z = 100 * Y / X;
	if (Z > 98) { printf("-1"); return 0; }

	printf("%lld", findk(1, X)); return 0;
}
/*
100 99 -1
1000000000 980000000 1000000000
200 100 5
*/