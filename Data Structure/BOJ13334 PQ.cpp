#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct sort_pq {
	bool operator()(pair<int, int>& A, pair<int, int>& B) {
		if (A.second == B.second) return A.first > B.first;
		return A.second > B.second;
	}
};
priority_queue<int,vector<int>,greater<int>> Q;
priority_queue<pair<int, int>,vector<pair<int,int>>,sort_pq> PQ;
int main() {
	int N, a, b, tmp, D;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &a, &b);
		if (a > b) tmp = b, b = a, a = tmp;
		PQ.push({ a,b });
	}
	scanf("%d", &D);
	
	int ANS = 0;
	while (!PQ.empty()) {
		int s = PQ.top().first;
		int e = PQ.top().second; PQ.pop();
		if (e - s > D) continue;

		int ss = e - D;
		while (!Q.empty() && Q.top() < ss) Q.pop();
		Q.push(s);

//		printf("end=%d, start=%d\n", e, Q.top());
		ANS = (ANS > Q.size()) ? ANS : Q.size();
	}
	
	printf("%d", ANS); return 0;
}

/*
N=8, D=30
  PQ	Q
10 20	10
20 25	10 20
10 35	10 10 20
 5 40	continue
25 40	10 10 20 25 => ANS=4
25 45	20 25 25
30 60	30
40 60	30 40

*/