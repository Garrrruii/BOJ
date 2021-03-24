//IQ Test
#include <cstdio>
using namespace std;
/* 2 2 => 2 2 2
 * 2 4 => 2 4 6 / 2 4 8 => A
 * 2 2 2 => 2 2 2 
 * 2 2 3 => B
 */
int main() {
	int N, x1, x2, x3;
	scanf("%d", &N);
	if (N < 3) { 
		if(N==1) printf("A");
		else {
			scanf("%d%d", &x1, &x2);
			if (x1 == x2) printf("%d",x1);
			else printf("A");
		}
		return 0;
	}
		
	scanf("%d%d%d", &x1, &x2, &x3);
	
	int a = (x2 == x1) ? 1 : ((x3 - x2) / (x2 - x1));
	if (a * (x2 - x1) != (x3 - x2)) { printf("B"); return 0; }
	int b = x3 - a * x2;

	x2 = x3;
	for (int i = 3; i < N; ++i) {
		scanf("%d", &x3);
		if (x3 != a * x2 + b) { printf("B"); return 0; }
		x2 = x3;
	}
	printf("%d", a * x3 + b); return 0;
}