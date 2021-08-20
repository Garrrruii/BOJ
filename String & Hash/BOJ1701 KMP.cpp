#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string S;
	cin >> S;
	int N = S.size();
	int ANS = 0;

	int pi[5000];
	for (int idx = 0; idx < N; ++idx) {
		if (N - idx < ANS) break;

		for (int j = idx; j < N; ++j) pi[j] = idx;
		for (int i = idx + 1, j = idx; i < N; ++i) {
			while (j > idx&& S[i] != S[j]) j = pi[j - 1];
			if (S[i] == S[j]) {
				pi[i] = ++j;
				ANS = max(ANS, pi[i] - idx);
				//¼¼»ó,, ¿©±â¸¦ pi[j]¶ó°í ¾¸ ¹ÌÃÆ³ªºÁ
			}
		}
		//for (int i = idx; i < N; ++i) cout << pi[i] - idx << " ";
		//cout << "\n";
	}
	cout << ANS; return 0;
}
/*
3 abcdabcabb
7 aaaabbbbaaabbbbb
8 abaabaabaabc
*/