#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string S, K, T = "";
	cin >> S >> K;
	for (char s : S) if (s > '9') T += s;

	// T가 K를 포함하는가?
	int N = T.size(), M = K.size(); 

	vector<int> pi(M, 0);					// Get pi
	for (int i = 1, j = 0; i < M; ++i) {
		while (j > 0 && K[i] != K[j]) j = pi[j - 1];

		if (K[i] == K[j]) pi[i] = ++j;
	}
	
	for (int i = 0, j = 0; i < N; ++i) {	// KMP
		while (j > 0 && T[i] != K[j]) j = pi[j - 1];

		if (T[i] == K[j]) {
			if (j == M - 1) { cout << 1; return 0; }
			else j++;
		}
	}
	cout << 0; return 0;
}
/*
1q2w3e4r5t6y1q2wd3e41q2w3e4r5t6yr5ts6y
qwerty
*/