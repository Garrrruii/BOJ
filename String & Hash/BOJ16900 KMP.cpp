#include <iostream>
#include <string>
#include <vector>
using namespace std;

int pi[500001] = { 0, };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S;
	int K;

	cin >> S >> K;
	int m = S.size();
	for (int i = 1, j = 0; i < m; ++i) {
		while (j > 0 && S[i] != S[j]) j = pi[j - 1];
		if (S[i] == S[j]) pi[i] = ++j;
	}
	long long repeat = (long long)m - (long long)pi[m - 1];
	cout << (long long)pi[m-1] + repeat * (long long)K << "\n";
	return 0;
}
/*
ada 3
001 => (3-2)+2*3
abc 2
000 => (3-3)+3*2
rr 5
01 => (2-1)+1*5
abcabcabca 3
0001231234 => (10-3)+3*3
*/
