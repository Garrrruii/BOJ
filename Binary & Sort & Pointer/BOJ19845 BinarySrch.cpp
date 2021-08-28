#include <iostream>
using namespace std;
/*	���� 10^9ĭ, ���� Nĭ (x,y)
	�۸���� �پ��ִ� �� �����ϱ� ������ (1,y)~(ay,y)
	�߷� ���� ���� */
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q, a[250001];
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> a[i]; //i���� i���� �۸�
	
	int x, y;
	while (Q--) {
		cin >> x >> y;
		// (x,y)�� ������ ��ġ, �� ���� �۸� ���� ����?
		// y������ ���� �������� �۸� �ֳ� => �̺�Ž��
		// y���� x���� �����ʱ��� �� ���� �۸� �ֳ� => a[y],x ��

		if (a[y] < x) cout << "0\n";
		else {
			//  L=(y+L-y)					����: y���� L����
			//  ...                  
			//  y,x  ... a[y]=(x+a[y]-x)	����: x���� a[y]����
			
			int L = y, R = N, mid;
			while (L < R) {
				mid = (L + R + 1) >> 1;
				if (a[mid] >= x) L = mid; //mid�� x�� �۸� ����
				else R = mid - 1;
			}
			cout << a[y] - x + L - y + 1 << "\n";
		}
	}
	return 0;
}
