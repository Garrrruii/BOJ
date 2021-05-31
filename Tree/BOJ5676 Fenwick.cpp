#include <iostream>
using namespace std;

int X[100001], N;
int fenm[100001]; //음수의 개수
int fenz[100001]; //0의 개수
void upd(bool m, int idx, int a) {
	if (m) while (idx <= N) fenm[idx] += a, idx += (idx & -idx);
	else while (idx <= N) fenz[idx] += a, idx += (idx & -idx);
}
int sum(bool m, int idx) {
	int res = 0;
	if (m) while (idx > 0) res += fenm[idx], idx -= (idx & -idx);
	else  while (idx > 0) res += fenz[idx], idx -= (idx & -idx);
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int K, i, j, cntm, cntz;
	char f;
	while (cin >> N) {
		for (int i = 1; i <= N; ++i) fenm[i] = 0;
		for (int i = 1; i <= N; ++i) fenz[i] = 0;
		
		cin >> K;
		for (i = 1; i <= N; ++i) {
			cin >> j; X[i] = j;
			if (j < 0) upd(true, i, 1);
			else if (!j) upd(false, i, 1);
		}
		while (K--) {
			cin >> f >> i >> j;
			if (f == 'C') {
				//Change X[i]=j
				if (j > 0) {
					if (X[i] < 0) upd(true, i, -1);
					else if (!X[i]) upd(false, i, -1);
				}
				else if (j < 0) {
					if (X[i] > 0) upd(true, i, 1);
					else if (!X[i]) upd(true, i, 1), upd(false, i, -1);
				}
				else {
					if (X[i] > 0) upd(false, i, 1);
					else if (X[i] < 0) upd(false, i, 1), upd(true, i, -1);
				}
				X[i] = j;
			}
			else {
				//Print which Xi*...*Xj is among +/-/0
				cntm = sum(true, j) - sum(true, i - 1);
				cntz = sum(false, j) - sum(false, i - 1);

				if (cntz) cout << "0";
				else if (cntm & 1) cout << "-";
				else cout << "+";
			}
		}
		cout << "\n";
	}
	return 0;
}
//				if (cntz) tmp += "0";
//				else if (cntm & 1) tmp += "-";
//				else tmp += "+";
