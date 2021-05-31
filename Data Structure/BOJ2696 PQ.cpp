#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> A;								//큰게 top
priority_queue<int, vector<int>, greater<int>> B;	//작은게 top
int main() {
	int T, N, a;
	scanf("%d", &T);
	while (T--) {
		while (!A.empty()) A.pop();
		while (!B.empty()) B.pop();
		scanf("%d", &N);
		printf("%d\n", 1+N >> 1);

		scanf("%d", &a); A.push(a); printf("%d ", a);
		for (int i = 2; i <= N; i += 2) {
			if(!(i%20)) printf("\n");

			scanf("%d", &a);
			if (A.top() > a) B.push(A.top()), A.pop(), A.push(a);
			else B.push(a);

			scanf("%d", &a);
			if (B.top() < a) A.push(B.top()), B.pop(), B.push(a);
			else A.push(a);
			printf("%d ", A.top());
		}
		printf("\n");
	}
}
/*
5
5 1 5 4 3 2
5 1 4 5 3 2
5 5 3 2 1 4
*/