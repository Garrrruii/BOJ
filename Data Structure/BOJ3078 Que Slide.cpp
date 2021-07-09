#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int i, a = 0;
	long long ANS = 0;
	int cnt[21] = { 0, };
	int N, K;
	string tmp;

	cin >> N >> K;
	for (i = 0; i <= K; ++i) {
		cin >> tmp; a = tmp.size();
		ANS += (long long)cnt[a]; Q.push(a); cnt[a]++;
	}
	for (; i < N; ++i) {
		a = Q.front(); cnt[a]--; Q.pop();

		cin >> tmp; a = tmp.size();
		ANS += (long long)cnt[a]; Q.push(a); cnt[a]++;
	}
	cout << ANS;
	return 0;
}
/*
(7) 9 5
(6) 9 3
QWERTYU
QWERT
QWERTY
ASDFG
ZXCVB
ASDFGH
POIUYTR
LKJHG
MNBVCXZ
*/