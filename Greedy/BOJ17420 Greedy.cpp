#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	long long a, b;
};
node con[1000001];
bool sortcon(node A, node B) {
	return A.b < B.b;			//사용 일자가 빠른 순
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", &con[i].a);
	for (int i = 0; i < N; ++i) scanf("%lld", &con[i].b);
	sort(con, con + N, sortcon);
	
	long long ans = 0;
	long long prvA = -1;
	long long A = -1;
	long long B = -1;
	for (int i = 0; i < N; ++i) {
		long long tmp = 0;

		if (B == con[i].b) {
			if (con[i].a <= prvA || con[i].a < B) {
				tmp = ((max(B, prvA) - con[i].a - 1) / 30) + 1;
				ans += tmp;
			}
			A = max(A, con[i].a + tmp * 30);
			//printf("    %3lld->%4lld,            A=%4lld  +%lld\n",  con[i].a, con[i].a + 30 * tmp,A, tmp);
		}
		else {
			B = con[i].b;
			prvA = A;
			if (con[i].a < prvA || con[i].a < B) {
				tmp = ((max(B, prvA) - con[i].a - 1) / 30) + 1;
				ans += tmp;
			}
			A = con[i].a + tmp * 30;
			//printf("\n%3lld %3lld->%4lld, prvA=%4lld, A=%4lld  +%lld\n", con[i].b, con[i].a, con[i].a + 30 * tmp, prvA, A,tmp);
		}
		// Note that A + tmp*30 >= max(B,prvA)
		// therefore tmp = ceil( (max(B,prvA)-A)/30 )
	}
	printf("%lld", ans);
	return 0;
}
/*
5  10 20 30 40 50 50 40 30 20 10
(10)

4  15 45 50 10 60 30 40 20
(3)

4  0 39 10 8 90 40 60 60
(10)

2  30 0 20 30
(2)

4  24 29 3 2 25 30 30 30
(6)
*/