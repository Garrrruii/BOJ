//N-Queen
#include <cstdio>
#include <cmath>
using namespace std;

int N, CNT = 0;
int b[15];

void Nqueen(int k) { //put k-th queen
	if (k == N) { CNT++; return; }
	
	for (int col = 0; col < N; ++col) {
		bool ava = true;
		for (int i = 0; i < k; ++i) { //(i,b[i]) and (k,col)
			if (b[i] == col || abs(k - i) == abs(col - b[i])) { ava = false; break; }
		}
		if (ava) b[k] = col, Nqueen(k + 1);
	}
}
int main() {
	scanf("%d", &N);

	for(int col=0;col<N;++col) b[0]=col, Nqueen(1);
	printf("%d", CNT); return 0;
}