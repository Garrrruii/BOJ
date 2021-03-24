#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int N, h;
	long long CNT = 0; //N<=500000
	stack<pair<int,int>> S;

	scanf("%d%d", &N, &h);
	
	S.push({ h,1 });
	for (int i = 1; i < N; ++i) {
		scanf("%d", &h);
		long long pop_cnt = 0;
		while (!S.empty() && S.top().first < h) {
			pop_cnt+=(long long)S.top().second, S.pop();
		}
		if (S.empty() || S.top().first > h) S.push({ h,1 });
		else CNT += (long long)S.top().second, S.top().second++;
		
		CNT += pop_cnt;
		if (S.size() > 1) CNT++;

	//	printf("h=%d, pop%d, CNT=%d\n", h, pop_cnt,CNT);
	}
	printf("%lld", CNT); return 0;
}
/*
9
5 4 2 2 1 2 3 5 2
5.1				  pop same size>1
5.1 4.1						1
5.1 4.1 2.1					1
5.1 4.1 2.2				1	1
5.1 4.1 2.2 1.1				1
5.1 4.1 2.3			1	2	1
5.1 4.1 3.1			3		1
5.2					2	1	0
5.2 2.1						1
*/