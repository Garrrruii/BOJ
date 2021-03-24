#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, K;
	vector<int> v[20];

	scanf("%d%d", &N, &K);

	int a = 0, b = 0;
	while (N + K - 1 >= (1 << a)) a++;
	while (N - 1 >= (1 << b)) b++;
	
	if (a > b) {
		// 12 13 14 15 16 17 18 19 => 12 1 2 4
		//  3  4  5  6  7  8  9 10 =>  3 1 2 40
		// 12 13 14 => 12 2 1
		for (int n = 1; n < N; ++n) {
			int k = 0;
			while (n >= (1 << k)) {
				if (n & (1 << k)) v[k].push_back(n + 1);
				k++;
			}
		}
		printf("%d\n", b + 1);
		printf("%d %d\n", N, K);
		for (int i = 1; i <= N; ++i) printf("%d ", i);
		printf("\n");
	}
	else {
		// 2 3 4 5 6 7 => 1 2 4
		// 1 2 3 => 1 2
		for (int n = K; n < N + K; ++n) {
			int k = 0;
			while (n >= (1 << k)) {
				if (n & (1 << k)) v[k].push_back(n - K + 1);
				k++;
			}
		}
		printf("%d\n", a);
	}
	for (int k = 0;; ++k) {
		if (v[k].size()) {
			printf("%d %d\n", v[k].size(), (1 << k));
			for (int a : v[k]) printf("%d ", a);
			printf("\n");
		}
		else break;
	}

	return 0;
}