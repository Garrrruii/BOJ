#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> e[26];
int ind[26];
queue<int> Q;

string w[100];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 26; ++i) ind[i] = -1;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) w[i].reserve(11);
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
		for (char c : w[i]) ind[c - 'a'] = 0;
	}

	string prv = w[0];
	int plen = w[0].size(), clen;
	for (int i = 1; i < N; ++i) {
		string cur = w[i];
		clen = cur.size();

		int j = 0;
		while (j < plen && j < clen) {
			if (cur[j] != prv[j]) {
				//prv[j] <- cur[j]
				ind[prv[j] - 'a']++;
				e[cur[j] - 'a'].push_back(prv[j] - 'a');
				j = -1;
				break;
			}
			j++;
		}
		if (j > 0 && plen > clen) {
			cout << "!"; return 0;
			// 2 ab a	!
			// 2 ab ab	?
		}
		prv = cur; plen = clen;
	}

	//ind처리
	vector<char> ans;
	ans.reserve(26);
	for (int i = 0; i < 26; ++i) if (!ind[i]) Q.push(i);
	int qsize = Q.size();
	bool question = false;
	while (qsize) {
		if (qsize > 1) question = true;
		while (qsize--) {
			int cur = Q.front(); Q.pop();
			ans.push_back(cur + 'a');
			for (int nxt : e[cur]) {
				ind[nxt]--;
				if (!ind[nxt]) Q.push(nxt);
			}
		}
		qsize = Q.size();
	}

	//ind처리가 다 안 됨 => !
	for (int i = 0; i < 26; ++i) {
		if (ind[i] > 0) { cout << "!"; return 0; }
	}
	//처리가 다 됐지만 순서 모름 => ?
	if (question) cout << "?";
	//처리 다 됐고 순서 완벽
	else {
		for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
	}
	return 0;
}