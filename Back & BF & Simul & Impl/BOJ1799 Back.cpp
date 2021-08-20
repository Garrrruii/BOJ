#include <cstdio>
#include <vector>
using namespace std;

int N, ANS1 = 0, ANS2 = 0;
bool B[20];
vector<int> A[20];
void bishop(int n, int cnt) {
	if (n >= 2 * N) {
		//x+y=even or odd => solve in 2^10 * 2
		if (n == 2 * N) ANS1 = (ANS1 > cnt) ? ANS1 : cnt;
		else ANS2 = (ANS2 > cnt) ? ANS2 : cnt;
		return;
	}

	for (int b : A[n]) {
		if (!B[b]) {
			B[b] = true; bishop(n + 2, cnt + 1); B[b] = false;
		}
	}
	bishop(n + 2, cnt);
}
int main() {
	int tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp);
			if (tmp) A[i + j].push_back(i - j + N);
		}
	}
	bishop(0, 0); bishop(1, 0);
	printf("%d", ANS1+ANS2); return 0;
}