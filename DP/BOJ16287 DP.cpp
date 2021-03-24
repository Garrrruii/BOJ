#include <cstdio>
using namespace std;
// 서로 다른 N개의 정수		4<=N<=5000
// 4개의 합 = W 가능?		10<=W<=799994
// 가능: YES  불가능: NO	1<=ai<=200000

int a[5000];
int w[400001];
int main() {
	int N, W;
	scanf("%d%d", &W, &N);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

	for (int i = 1; i < N - 1; ++i) {
		//j>i, check if W-a[i]+a[j] true
		for (int j = i + 1; j < N; ++j) {
			int ab = a[i] + a[j];
			if (ab > W || ab<W-400000) continue; //ab < W <= ab+400000
			if (w[W - ab]) {
				printf("YES"); return 0;
			}
		}
		//k<i, mark a[i]+a[k]
		for (int k = 0; k < i; ++k) {
			int ab = a[i] + a[k];
			if (ab < W) w[ab] = true;			//ab<=400000 or ab<=W
		}
	}
	printf("NO"); return 0;
}
/*
NOTE: a+b+c+d = W => a+b = W-(c+d)

10 1 4 6 2 8 5 (21)
	CHECK							MARK
1	 5(16) 7(14) 3(18) 9(12) 6(15)	11
4	10(11) 6(15) 12(9) 9(12)		14 5
6	 8(13) 14(7) 11(10)				16 7 10
2	10(11) => YES

*/