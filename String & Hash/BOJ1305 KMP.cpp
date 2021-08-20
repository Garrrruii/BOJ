#include <string>
#include <iostream>
using namespace std;

int pi[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int L;
	string S;
	cin >> L >> S;
	
	//get pi
	for (int i = 1, j = 0; i < L; ++i) {
		while (j > 0 && S[i] != S[j]) j = pi[j - 1];
		if (S[i] == S[j]) pi[i] = ++j;
	}
	cout << L - pi[L - 1] << "\n";
	return 0;
}
/*
8
aabacaab
(5)

8
abaabaab
(3)

8
cabaabac
(7)
*/