#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int d, w;
};
priority_queue<int,vector<int>,greater<int>> pq;
bool sortH(node A, node B) {
	return A.d < B.d;
}
int main() {
	node H[1000];
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &H[i].d, &H[i].w);
	}
	sort(H, H + N, sortH);
	for (int i = 0; i < N; ++i) {
		if (pq.size() < H[i].d) pq.push(H[i].w), printf("push %d\n", H[i].w);
		else if(pq.size()==H[i].d){
			if (pq.top() < H[i].w) {
				printf("push %d > top=%d\n", H[i].w, pq.top());
				pq.pop(); pq.push(H[i].w);
			}
		}
	}

	int ANS = 0;
	while (!pq.empty()) ANS += pq.top(), pq.pop();
	printf("%d", ANS); return 0;
}
/*
7
4 60 4 40 1 20 2 50
3 30 4 10 6 5

 1  2  3  4  4  4  6
20 50 30 60 40 10  5
20 50 30 60
pop         40 --  5 => 185
*/