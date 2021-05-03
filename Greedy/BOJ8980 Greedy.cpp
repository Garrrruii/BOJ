#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> box[2001];
int main() {
	int N, M, C, a, b, c; 
	scanf("%d%d%d", &N, &C, &M);
	while(M--){
		scanf("%d%d%d", &a, &b, &c);
		box[a].push_back({ b, c });
	}
	for (int i = 1; i <= N; ++i) sort(box[i].begin(), box[i].end());
	
	int CAP = 0;
	int ANS = 0;
	int del[2001] = { 0, };
	for (int cur = 1; cur <= N; cur++) {
		ANS += del[cur];	//cur에 배달완료
		CAP -= del[cur];

		for (pair<int, int> b : box[cur]) {
			int nxt = b.first;
			int wei = b.second;
			int over = wei - (C - CAP);
			
			if (over <= 0) {
				CAP += wei, del[nxt] += wei; continue;
			}

			for (int far = N; far > nxt; far--) {
				if (del[far] >= over) {
					del[far] -= over; CAP -= over; over = 0; break;
					//far에 도착할 게 over보다 큼
					//=> 그거 over만큼 빼고 over=0 해줌
				}
				else {
					over -= del[far]; CAP -= del[far]; del[far] = 0;
					//far에 도착할 게 over보다 작음
					//=> 그거 다 빼고 over되는 양 줄여줌
				}
			}
			wei -= over;
			
			CAP += wei; del[nxt] += wei;
			
			//printf("+ %2d-%2d CAP:%3d\t", wei+over,over, CAP, ANS);
			//for (int i = 1; i <= N; ++i) printf("%2d ", del[i]);
		}
	}
	printf("%d",ANS);

	return 0;
}
/*
5 70 10
1 5 60 1 4 60 1 3 50 1 2 10
2 5 15 2 4 20 2 3 30
3 5 10 3 4 15
4 5 20
125
*/