#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> S;
	cin >> T;
	int ssize = S.size();
	while (ssize < T.size()) {
		if (T.back() == 'A') T.pop_back(); // T.erase(T.end() - 1);
		else {
			T.pop_back(); //T.erase(T.end()-1);
			reverse(T.begin(), T.end());
		}
		//cout << T << "\n";
	}
	cout << (S == T) ? 1 : 0;
	return 0;
}