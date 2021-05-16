#include <cstdio>
using namespace std;

int num[22] = { 0,0,1,7,4,2,6,8,
				 10, 18, 22, 20, 28, 68, 88,
				108,188,200,208,288,688,888 };
int main() {
	int T, N;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);

		//MIN
		if (N < 22) printf("%d", num[N]);
		else{
			int M = (N - 1) / 7;
			if (!(N % 7)) for (int i = 0; i <= M; ++i) printf("8");
			else {
				printf("%d", num[N - (M - 2) * 7]);
				for (int i = 2; i < M; ++i) printf("8");
			}
		}
		printf(" ");
		
		//MAX
		printf("%d", ((N & 1) ? 7 : 1));
		for (int i = 1; i < (N >> 1); ++i) printf("1");
		printf("\n");
	}
	return 0;
}