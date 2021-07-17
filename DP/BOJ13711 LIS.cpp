#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int pos[100001];	//pos[i] a에서 i의 위치
int b[100001];		//b[i]	 bi의 a에서의 위치
vector<int> lcs;
int main() {
	int N, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &tmp), pos[tmp] = i;
	for (int i = 1; i <= N; ++i) scanf("%d", &tmp), b[i] = pos[tmp];
	/*int N = 100000;
	for (int i = 1; i <= N; ++i) pos[i] = i;
	for (int i = 1; i <= N; i += 2) b[i] = pos[i], b[i + 1] = pos[N + 1 - i];
	*///output:50000	

	lcs.push_back(b[1]);
	for (int i = 2; i <= N; ++i) {
		//b[i]보다 작은 수 중 가장 큰 수 위치+1
		//b[i]보다 큰 수 중 가장 작은 수 위치
		auto here = upper_bound(lcs.begin(), lcs.end(), b[i]);
		if (here == lcs.end()) lcs.push_back(b[i]);
		else *here = b[i];
	}
	//for (int l : lcs) printf("%d ", l);
	//printf("\n");
	printf("%d", lcs.size()); return 0;
}
/*
1 5 4 3 6 2
4 2 3 1 6 5

3 6 4 1 5 2 여기서 증가수열 찾으면
3 6
  4 5 
1 2
*/