#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	char c;
	int k = 1;
	vector<node*> v = {};
	//vector<node>로 하면 뭔가 잘 안 되는데 why..?
};
vector<node*> root(0);
string s[100000];
int CNT = 0;

void dfs(node nod) {
	if (nod.k == 1) CNT++;
	else if (nod.k > nod.v[0]->k) {
		CNT += nod.k;
		for (node* child : nod.v) dfs(*child);
	}
	else dfs(*(nod.v[0]));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << fixed; cout.precision(2);

	int N;
	while (cin >> N) {
		for (int i = 0; i < N; ++i) cin >> s[i];
		sort(s, s + N);

		root.clear();
		vector<node*>* vec = &root;
		for (int i = 0; i < N; ++i) {
			vec = &root;

			for (char c : s[i]) {
				if (vec->empty() || vec->back()->c != c) {
					node* A = new node;
					A->c = c; vec->push_back(A); vec = &(A->v);
				}
				else {
					(vec->back()->k)++; vec = &(vec->back()->v);
				}
			}
		}

		CNT = 0;
		for (node* nod : root) dfs(*nod);
		double ans = (double)CNT / (double)N;
		cout << ans << "\n";
	}
	return 0;
}
/*
9
structures
string
structure
stress
stream
stand
star
stop
strength
(30/9 = 3.33)
*/