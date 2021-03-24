//17162 mod<=10^2, stack
//17163 mod<=10^9, stack, pq, segtree
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

//			0
//	   1		 2
//	3	 4    5		6

int seg[1 << 21];
stack<int> arr;
stack<int> idx[];
int main() {
	int mod, Q, query, num;
	scanf("%d%d", &Q, &mod);
	if (mod > Q) { printf("-1"); return 0; }

	while (Q--) {
		scanf("%d", &query);
		if (query == 1) {
			//PUSH
			scanf("%d", &num); num %= mod;

		}
		else if (query == 2) {
			//POP
			if (arr.empty()) continue;

		}
		else {
			//PRINT

		}
	}
	return 0;
}

//17162
/*
stack<int> arr, idx[100];

	if (query == 1) {
	//PUSH
		scanf("%d", &num); num %= mod;
		idx[num].push(arr.size()); arr.push(num);
	}
	else if (query == 2) {
	//POP
		if (arr.empty()) continue;
		idx[arr.top()].pop(); arr.pop();
	}
	else {
	//PRINT
		int minidx = arr.size();
		for (int i = 0; i < mod; ++i) {
			if (idx[i].empty()) { minidx = -1; break; }
			if (idx[i].top() < minidx) minidx = idx[i].top();
		}
		printf("%d\n", (minidx < 0) ? (-1) : (arr.size() - minidx));
	}
*/