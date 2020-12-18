//Caesar Cipher
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int T;
string A, W, S;
vector<int> ans;
map<char, int> ord;
int pi[50000] = { 0, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans.clear();
		ord.clear();
		cin >> A >> W >> S;

		int a = A.size();
		for (int i = 0; i < a; i++) ord[A[i]] = i;

		int wlen = W.size();

		for (int i = 1, j = 0; i < wlen; i++) {
			while (j > 0 && W[i] != W[j]) j = pi[j - 1];
			if (W[i] == W[j]) pi[i] = ++j;
		}

		for (int k = 0; k < a; k++) {
			bool check = false;

			for (int i = 0, j = 0; i < (int)S.size(); i++) {
				char ordstr = A[(ord[S[i]] - k + a) % a];
				while (j > 0 && ordstr != W[j]) j = pi[j - 1];
				if (ordstr == W[j]) {
					if (j == wlen - 1) {
						if (check) { check = false; break; }
						check=true; j = pi[j];
					}
					else j++;
				}
			}
			if (check) ans.push_back(k);
		}

		if (ans.size() == 0) cout << "no solution\n";
		else if (ans.size() == 1) cout << "unique: " << ans[0] << "\n";
		else {
			cout << "ambiguous:";
			for (int i = 0; i < (int)ans.size(); i++) cout << " " << ans[i];
			cout << "\n";
		}

		for (int i = 0; i < wlen; i++) pi[i] = 0;
	}
	return 0;
}
