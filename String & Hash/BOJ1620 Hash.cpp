#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD 133337

typedef struct node {
	unsigned int hval;
	int idx;
};
vector<node> buck[MOD];

unsigned int getHashVal(string str) {
	unsigned int hval = 0;
	int idx = 0, ssize = str.size();
	while (idx < ssize) hval *= 101, hval += str[idx++];
	return hval;
}
int getIdx(string str) {
	unsigned int hval = getHashVal(str);
	for (node n : buck[hval % MOD]) {
		if (n.hval == hval) return n.idx;
	}
}
string pok[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < MOD; ++i) buck[i].reserve(0);

	int N, M;
	cin >> N >> M;

	unsigned int hval = 0;
	int idx;
	for (int i = 1; i <= N; ++i) {
		cin >> pok[i];
		hval = getHashVal(pok[i]);
		buck[hval % MOD].push_back({ hval,i });
	}

	string tmp;
	while (M--) {
		cin >> tmp;
		if (tmp[0] >= 'A') cout << getIdx(tmp) << "\n";
		else {
			idx = tmp[0] - '0';
			for (int j = 1; j < tmp.size(); ++j) idx *= 10, idx += tmp[j] - '0';
			cout << pok[idx] << "\n";
		}
	}

	return 0;
}