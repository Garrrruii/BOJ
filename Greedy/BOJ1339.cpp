//word math
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int N, val[26] = { 0, };
	string tmp;

	cin >> N;
	while (N--) {
		cin >> tmp;
		for (int j = tmp.size() - 1, ten = 1; j >= 0; j--, ten *= 10) {
			val[tmp[j] - 'A'] += ten;
		}
	}
	sort(val, val + 26);

	//	for (int i = 0; i < 26; ++i) cout << val[i] << " ";
	//	cout << "\n";

	int num = 9, ANS = 0;
	while (val[num + 16]) ANS += (val[num + 16] * num), num--;

	cout << ANS; return 0;
}
