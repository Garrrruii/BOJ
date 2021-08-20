//gostack
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

//NUM X: push X
//POP: pop top
//INV: change sign
//DUP: push X, twice
//SWP, ADD, SUB, MUL, DIV, MOD: operation btw first and second num

//ERROR: divide by 0, abs>10^9
// 13 div -4 = -3 = -(13 DIV 4)
//-13 div -4 =  3 =   13 DIV 4
//-13 mod  4 = -1 = -(13 MOD 4)
//-13 mod -4 = -1 = -(13 MOD 4)

string op[100000];
long long num[100000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int INF = 1000000000;

	while (1) {
		string tmp;
		int N, idx = 0;
		long long v;

		while (1) {
			cin >> op[idx];
			if (op[idx] == "NUM") cin >> num[idx];
			else if (op[idx] == "END") break;
			else if (op[idx] == "QUIT") return 0;
			idx++;
		}

		cin >> N;
		while (N--) {
			stack<long long> s;
			bool err = false;
			long long tmp1, tmp2;

			cin >> v; s.push(v);
			idx = 0;
			while (op[idx] != "END") {
				if (op[idx] == "NUM") s.push(num[idx]);
				else if (op[idx] == "POP") {
					if (s.empty()) { err = true; break; }
					s.pop();
				}
				else if (op[idx] == "INV") {
					if (s.empty()) { err = true; break; }
					tmp1 = s.top(), s.pop(), s.push(tmp1 * (-1));
				}
				else if (op[idx] == "DUP") {
					if (s.empty()) { err = true; break; }
					s.push(s.top());
				}
				else if (op[idx] == "SWP") {
					if (s.size() < 2) { err = true; break; }
					tmp1 = s.top(), s.pop(), tmp2 = s.top(), s.pop();
					s.push(tmp1), s.push(tmp2);
				}
				else {
					if (s.size() < 2) { err = true; break; }
					tmp1 = s.top(), s.pop(), tmp2 = s.top(), s.pop();

					long long res;
					if (op[idx] == "ADD") res = tmp2 + tmp1;
					else if (op[idx] == "SUB") res = tmp2 - tmp1;
					else if (op[idx] == "MUL") res = tmp2 * tmp1;
					else if (op[idx] == "DIV") {
						if (!tmp1) { err = true; break; }
						int cnt = 0;
						if (tmp1 < 0) tmp1 *= -1, cnt++;
						if (tmp2 < 0) tmp2 *= -1, cnt++;
						if (cnt == 1) res = -tmp2 / tmp1;
						else res = tmp2 / tmp1;
					}
					else { //MOD
						if (!tmp1) { err = true; break; }
						bool minus = false;
						if (tmp1 < 0) tmp1 *= -1;
						if (tmp2 < 0) tmp2 *= -1, minus = true;
						if (minus) res = -tmp2 % tmp1;
						else res = tmp2 % tmp1;
					}
					if (abs(res) > INF) { err = true; break; }
					else s.push(res);
				}
				idx++;
			}
			if (s.size() == 1 && !err) cout<<s.top()<<"\n";
			else cout<<"ERROR\n";
		}
		cout<<"\n";
	}
}