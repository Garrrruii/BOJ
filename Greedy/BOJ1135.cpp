//news delivery
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//minsik call subord -> call subord -> ...

int N;
vector<int> lead[50];
int dp(int a) {
	if (lead[a].empty()) return 0;
	vector<int> tmp;
	int A = lead[a].size();
	for (int i = 0; i < A; ++i) {
		tmp.push_back(dp(lead[a][i]));
	}
	sort(tmp.rbegin(), tmp.rend());
	for (int i = 0; i < A; ++i) tmp[i] += (i + 1);
	sort(tmp.rbegin(), tmp.rend());
	return tmp[0];
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int tmp; scanf("%d", &tmp);
		if (tmp < 0) continue;
		lead[tmp].push_back(i);
	}
	printf("%d", dp(0));
	return 0;
}

/*
26
-1 0 1 1 1 2 2 2 3 3
4 4 0 0 0 14 15 16 17 18 18
13 13 13 22 23 23

ans: 7
*/