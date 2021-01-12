//teaching
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int N, ANS = 0;
string word[50];
bool alph[26], teach[26];

void read(int idx, int count) {
	if (count == 0 || idx == 26) {

		int CNT = 0;
		for (int i = 0; i < N; ++i) {
			bool ava = true;
			for (int j = 4; j < (int)word[i].size() - 4; ++j) {
				if (!teach[word[i][j] - 'a']) { ava = false; break; }
			}
			if (ava) CNT++;
		}
		ANS = max(ANS, CNT);
	}
	else {
		bool ava = false;
		for (int i = idx; i < 26; ++i) {
			if (!alph[i] || teach[i]) continue;
			teach[i] = true; ava = true;
			read(i + 1, count - 1);
			teach[i] = false;
		}
		if (!ava) read(26, 0);
	}
}
int main() {
	int K;
	char c[5] = { 'a','n','t','i','c' };
	for (int i = 0; i < 5; ++i) teach[c[i] - 'a'] = true;

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> word[i];
		for (int j = 4; j < (int)word[i].size() - 4; ++j)
			alph[word[i][j] - 'a'] = true;
	}
	if (K < 5) { cout << 0; return 0; }
	else if (K == 5) read(26, 0);
	else if (K < 26) {
		bool ava = false;
		for (int i = 1; i < 26; ++i) {
			if (!alph[i] || teach[i]) continue;
			teach[i] = true; ava = true;
			read(i + 1, K - 6);
			teach[i] = false;
		}
		if (!ava) read(26, 0);
	}
	else if (K == 26) { cout << N; return 0; }

	cout << ANS; return 0;
}
/*
2 5
antatddatatica
antaadctica

2 7
antatddatatica
antaadctica

2 5
antattatatica
antaactica

2 7
antattatatica
antaactica

*/