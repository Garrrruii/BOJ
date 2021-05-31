#include <iostream>
#include <string>
#include <vector>
using namespace std;
// R 숫자 순서 뒤집
// D 첫번째 수 버림 (비어있는데 D => error)

string func; //p
string arr;	 //arr
vector<int> V;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T, num, left, right;
	bool error, front;

	cin >> T;
	while (T--) {
		cin >> func;
		cin >> right; right--; left = 0;
		cin >> arr;

		num = 0; V.clear();
		for (char a : arr) {
			if ('0' <= a && a <= '9') num *= 10, num += (a - '0');
			else if (num > 0) V.push_back(num), num = 0;
		}

		error = false; front = true;
		for (char f : func) {
			if (f == 'R') {
				if (front) front = false;
				else front = true;
			}
			else {
				if (left > right) { error = true; break; }

				if (front) left++;
				else right--;
			}
		}

		if (error) cout<<"error\n";
		else {
			if (left > right) cout << "[]\n";	//empty array
			else {
				cout << "[";
				if (front) {
					for (int i = left; i < right; ++i) cout << V[i] << ",";
					cout << V[right] << "]\n";
				}
				else {
					for (int i = right; i > left; --i) cout << V[i] << ",";
					cout << V[left] << "]\n";
				}
			}
		}
	}
	return 0;
}