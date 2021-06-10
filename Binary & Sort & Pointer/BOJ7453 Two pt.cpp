//4 integers st sum=0
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 4000 

int a[MAX], b[MAX], c[MAX], d[MAX];
int ab[MAX * MAX], cd[MAX * MAX];
int main() {
	int i, j, N, M;

	scanf("%d", &N); M = N * N;
	for (i = 0; i < N; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			ab[i * N + j] = a[i] + b[j], cd[i * N + j] = c[i] + d[j];
		}
	}
	sort(ab, ab + M); sort(cd, cd + M);
	
	long long cnt = 0;
	i = 0; j = M - 1;				//two pointer, binary search
	while (i < M && j >= 0) {		//find pair of ab+cd=0
		int tmp = ab[i] + cd[j];
		if (tmp > 0) j--;
		else if(tmp < 0) i++;
		else {
			int tar1 = ab[i], tar2 = cd[j];
			long long k1 = 1, k2 = 1;
			while (i + k1 < M && tar1 == ab[i + k1]) k1++;
			while (j - k2 >= 0 && tar2 == cd[j - k2]) k2++;
			cnt += k1 * k2;
			i += k1; j -= k2;
		}
	}
	printf("%lld", cnt); return 0;
}