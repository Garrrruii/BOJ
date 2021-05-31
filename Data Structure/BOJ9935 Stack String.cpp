#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string  s, t; // s:문자열 t:폭발문자열
stack<pair<int, int>> S;
vector<pair<int, int>> B; //bomb
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> s >> t;
	int ssize = s.size();
	int tsize = t.size();

	B.reserve(ssize);
	B.push_back({ 0,-1 });
	if (tsize == 1) {
		for (int j = 0; j < ssize; ++j) {
			if (s[j] != t[0]) continue;

			if (B.empty() || B.back().second < j - 1) B.push_back({ j,j });
			else B.back().second = j;
		}
	}
	else {
		for (int j = 0; j < ssize; ++j) {
			if (s[j] == t[0]) S.push({ j,1 });
			else if (S.empty()) continue;
			else if (s[j] == t[S.top().second]) {
				S.top().second++;

				if (S.top().second == tsize) {
					int i = S.top().first; S.pop();

					while (!B.empty() && B.back().first > i) B.pop_back();
					if (B.empty() || B.back().second < i - 1) B.push_back({ i, j });
					else B.back().second = j;
				}
			}
			else while(!S.empty()) S.pop();	//중간에 다른 문자열이 나오면 S를 reset해야 함
		}
	}
	if (B.back().second < ssize - 1) B.push_back({ ssize,0 });
	else B.back().second = ssize;

	for (pair<int, int> bb : B) cout << bb.first << " " << bb.second << "  ";
	cout << "\n";

	int bsize = B.size();
	if (bsize == 1) { cout << "FRULA"; return 0; }
	for (int b = 1; b < bsize; ++b) {
		//cout << B[b - 1].second+1 << " " << B[b].first << " ->  ";
		cout << s.substr(B[b - 1].second + 1, B[b].first - B[b - 1].second - 1);
	}
	return 0;
}
/*
ZXXXYXYZZYXYZZYXYZ
XYZ
(ZXY)

abacabcc
abc
(abacc)

pepeacpeachhapeachbanachpepeachachnakipeachwi
peach
(peabanachnakiwi)

applemangoyogurtsmoothie
o
(applemangygurtsmthie)
*/