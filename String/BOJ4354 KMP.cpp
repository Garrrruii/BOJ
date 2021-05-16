#include <string>
#include <iostream>
using namespace std;

int pi[1000000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N = 0;
	int n = 0, a = 0;
	string S;
	while (1) {
		cin >> S;
		if (S == ".") return 0;
		if (S == "") { cout << 0 << "\n"; continue; }

		N = S.size();
		for (int i = 0; i < N; ++i) pi[i] = 0;

		for (int i = 1, j = 0; i < N; ++i) {
			while (j > 0 && S[i] != S[j]) j = pi[j - 1];
			if (S[i] == S[j]) pi[i] = ++j;
		}
		a = N - pi[N - 1];
		n = N / a;
		if (n * a == N) cout << n << "\n";
		else cout << 1 << "\n";
	}
}