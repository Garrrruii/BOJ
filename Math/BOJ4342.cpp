//Euclid Game
//A man of choice wins.
#include <cstdio>
using namespace std;

int main() {
	while (1) {
		int A, B;
		scanf("%d%d", &A, &B);
		if (!A) return 0;
		
		int tmp;
		if (A < B) tmp = A, A = B, B = tmp;

		tmp = 1;
		while (1) {
			int Q = A / B;
			if (Q > 1) break;
			Q = A % B; A = B; B = Q;
			if (B == 0) break;
			tmp++;
		}

		if (tmp % 2) printf("A wins\n");
		else printf("B wins\n");
	}
}