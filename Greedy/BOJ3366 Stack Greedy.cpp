#include <cstdio>
#include <stack>
using namespace std;

stack<long long> S;
//vector<long long> V; vector is faster but use more memory
int main() {
	long long ans = 0, a;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &a);
		
		if (!S.empty() && S.top() <= a) {
			while (S.top() <= a) {
				S.pop();
				
				if (S.empty()) { ans += a; break; }
				else ans += (S.top() < a) ? S.top() : a;
			}
		}
		S.push(a);
		/*
		if (!V.empty() && V.back() <= a) {
			while (V.back() <= a) {
				V.pop_back();

				if (V.empty()) { ans += a; break; }
				else ans += (V.back() < a) ? V.back() : a;
			}
		}
		V.push_back(a); */
	}
	S.pop();
	while (!S.empty()) ans += S.top(), S.pop();
	/* for (int i = 0; i < V.size() - 1; ++i) ans += V[i]; */

	printf("%lld", ans);
	return 0;
}
/*
8 1 4 2 8 5 7 3 6		(44)
9 4 2 1 4 6 7 2 3 4		(37)
*/
