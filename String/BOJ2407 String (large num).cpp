#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string C[101][101];
string add(string S, string T) {
	string res = "";
	int carry = 0;
	int sum = 1;
	for (int idx = 0; carry || idx < max(S.size(), T.size()); ++idx) {
		sum = carry;
		if (idx < S.size()) sum += S[idx] - '0';
		if (idx < T.size()) sum += T[idx] - '0';

		carry = sum / 10;
		res += (sum % 10 + '0');
		sum = 0;
	}

	return res;
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) C[i][0] = C[i][i] = "1";
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= min(m, i - 1); ++j) {
			//C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	reverse(C[n][m].begin(), C[n][m].end());
	cout << C[n][m]; return 0;
}