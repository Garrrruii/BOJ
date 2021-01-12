//num base 36
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int C[36][56];
bool sortdig(pair<int, int>A, pair<int, int>B) {
	if (A.first == B.first) {
		int idx = A.first;
		while (C[A.second][idx] == C[B.second][idx]) idx--;
		return C[A.second][idx] > C[B.second][idx];
	}
	return A.first > B.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K, ANS[56] = { 0, };
	vector<pair<int, int>> dig;

	/*	Get and Add numbers
	ex)	 AA		C[A]={ 1, 3, 0, ... } 
		 AB	=>	C[B]={ 1, 0, 1, ... }
		BAY		C[Y]={ 1, 0, 0, ... } */
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string tmp; cin >> tmp;
		for (int idx = 0, j = tmp.size() - 1; j >= 0; ++idx, --j) {
			int tard = (tmp[j] <= '9') ? tmp[j] - '0' : tmp[j] - 'A' + 10;
			C[tard][idx]++; ANS[idx] += tard;
		}
	}

	/*	Process C[][]
		C[A]={ 1, 3, 0, ...} => {25, 3,  2, ... } 75=2*36+3
		C[B]={ 1, 0, 1, ...} => {24, 0, 24, ... }
		C[Y]={ 1, 0, 0, ...} => { 2, 0,  0, ... } */
	for (int i = 0; i < 36; ++i) {
		int idx;
		for (idx = 0; idx < 50; ++idx) C[i][idx] *= (35 - i);
		for (idx = 0; idx < 55; ++idx) {
			if (C[i][idx] < 36) continue;
			C[i][idx + 1] += C[i][idx] / 36;
			C[i][idx] %= 36;
		}
		while (!C[i][idx] && idx > -1) idx--;
		if (idx > -1) dig.push_back({ idx,i });
	}
	dig.push_back({ 0,35 });
	sort(dig.begin(), dig.end(), sortdig);

	//for (int i = 0; i < dig.size(); ++i) {
	//	if (dig[i].second < 10) printf("%2d ", dig[i].second);
	//	else printf(" %c ", dig[i].second + 'A' - 10);
	//}
	//cout << "\n";
	//for (int i = 0; i < dig.size(); ++i) printf("%2d ", dig[i].first);
	//cout << "\n";

	/*	Add incregement and Process ANS */
	cin >> K;
	for (int i = 0; i < K; ++i) {
		for (int idx = 0; idx <= dig[i].first; ++idx) ANS[idx] += C[dig[i].second][idx];
	}
	int k = 0;
	while (k < 55) {
		ANS[k + 1] += ANS[k] / 36;
		ANS[k++] %= 36;
	}
	while (k >= 0 && !ANS[k]) k--;
	if (k < 0) cout << "0";	//...89% WA
	else {
		while (k >= 0) {
			if (ANS[k] < 10) cout << ANS[k--];
			else cout << (char)(ANS[k--] - 10 + 'A');
		}
	}
	return 0;
}

/*
4
WWWWW
HHHH
AAA
00

*/