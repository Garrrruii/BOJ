//Alter
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long DIV = 1000000007;
	long long prv[5002] = { 0, }, cur[5002] = { 0, };
	int N, tmp;
	scanf("%d", &N);

	//첫 번째 재단이 0 초과 => 불가능
	scanf("%d", &tmp);
	if (tmp > 0) { printf("0"); return 0; }

	//0번째 재단 높이 0, 경우의 수 1개
	prv[0] = 1;						
	for (int i = 1; i < N; ++i) {
		//i번째 재단에 대하여
		scanf("%d", &tmp);
		if (tmp < 0) {				//비어있음 => 높이 h일 경우의 수 모두 구함
			cur[0] = (prv[0] + prv[1]) % DIV;
			for (int h = 1; h <= min(N - i - 1, i); ++h) {
				cur[h] = (prv[h - 1] + (prv[h] + prv[h + 1]) % DIV) % DIV;
			}
		}							//높이 tmp => 높이 tmp인 경우의 수만 구함
		else if (!tmp) cur[0] = (prv[0] + prv[1]) % DIV;
		else cur[tmp] = (prv[tmp - 1] + (prv[tmp] + prv[tmp + 1]) % DIV) % DIV;


		//i+1번째 재단 위해 초기화
		for (int h = 0; h < 5002; ++h) prv[h] = cur[h];
		for (int h = 0; h < 5002; ++h) cur[h] = 0;
	}
	//마지막 재단의 높이가 0인 경우의 수를 출력
	printf("%lld", prv[0]); return 0;
}