#include <iostream>
using namespace std;
// ������ ����ϴ� = ������ �� ��ġ ������ ���̰� 1������ ���
// �̰� ���� �ߴµ�....!? �� same as BOJ1898 ���� ������ � �����ϱ�
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