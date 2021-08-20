#include <iostream>
using namespace std;
// 순열이 비슷하다 = 순열의 각 위치 수들의 차이가 1이하인 경우
// 이거 언제 했는데....!? ⇒ same as BOJ1898 이전 수열은 어떤 수열일까
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, a[50001] = { 0, }, pos[50001], tmp;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> tmp, pos[tmp] = i;
	
	for (int i = N - 1; i > 0; --i) {
		if (pos[i] < pos[i + 1]) a[pos[i]] = i, a[pos[i + 1]] = i + 1;
		else a[pos[i]] = i + 1, a[pos[i + 1]] = i, i--;
	}
	if (!a[pos[1]]) a[pos[1]] = 1;
	for (int i = 0; i < N; ++i) cout << a[i] << " ";
	return 0;
}