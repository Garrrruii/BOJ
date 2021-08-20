#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Print how many times P appears in T
// & the indices of poisitons that P appears

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	int N = T.size(), M = P.size();

	// Get pi
	vector<int> pi(M, 0);
	for (int i = 1, j = 0; i < M; ++i) {
		while (j > 0 && P[i] != P[j]) j = pi[j - 1];

		if (P[i] == P[j]) pi[i] = ++j;
	}

	// KMP
	vector<int> idx;
	for (int i = 0, j = 0; i < N; ++i) {
		while (j > 0 && T[i] != P[j]) j = pi[j - 1];

		if (T[i] == P[j]) {
			//if (j == 0) cout<<"\n";
			//cout<<j<<" ";
			if (j == M - 1) idx.push_back(i - M + 2), j = pi[j];
			else j++;
		}
	}

	cout << idx.size() << "\n";
	for (int ans : idx) cout << ans << " ";
	return 0;
}
/*
ABC ABCDAB ABCDABCDABDE
ABCDABD
(1  16)

ABCACBCABCABCACBCABC
BCABC
(3  6 9 16)
*/