#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int R, C;
	cin >> R >> C;

	string tmp, s[1000]; //s[C]
	for (int j = 0; j < C; ++j) s[j] = "";
	for (int i = 0; i < R; ++i) {
		cin >> tmp;
		for (int j = 0; j < C; ++j) s[j] += tmp[j];
	}

	set<string> S;
	int left = 0, right = R - 1, mid;
	while (left < right) {
		S.clear();
		mid = (left + right + 1) >> 1;
//		cout << left << "," << right << " mid=" << mid << " yes=";

		bool yes = true;
		for (int j = 0; j < C; ++j) {
			tmp = s[j].substr(mid);
			if (S.find(tmp) != S.end()) { yes = false; break; }
			S.insert(tmp);
		}
//		cout << (yes ? 1 : 0) << "\n";

		if (yes) left = mid;//mid부터 끝까지 해도 서로 구분된다.
		else right = mid - 1;
	}
	cout << left; return 0;
}
/*
5 7
abcdefg
abcdefg
abcdefg
abcdefg
aaaaaaa
*/