//Ant Burrow
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str[1001];
vector<int> child[1001];

bool comp(int A, int B) {
	int i = 0;
	while (i < str[A].size() && i < str[B].size()) {
		if (str[A][i] == str[B][i]) i++;
		else return str[A][i] < str[B][i];
	}
	return str[A].size() < str[B].size();
}
void dfs(int a, int cnt) {
	for (int i = 0; i < cnt; ++i) cout << "--";
	cout << str[a] << "\n";

	for (int i = 0; i < child[a].size(); ++i) dfs(child[a][i], cnt + 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K, idx = 1;
	string tmp;

	str[0] = "";

	cin >> N;
	while (N--) {
		cin >> K;

		int par = 0;
		while (K--) {
			cin >> tmp;

			if (child[par].empty()) {
				child[par].push_back(idx);
				str[idx] = tmp; par = idx; idx++;
			}
			else {
				bool newchild = true;
				for (int i = 0; i < child[par].size(); ++i) {
					if (str[child[par][i]] == tmp) {
						par = child[par][i]; newchild = false; break;
					}
				}
				if (newchild) {
					child[par].push_back(idx);
					str[idx] = tmp; par = idx; idx++;
				}
			}
		}
	}
	for (int i = 0; i < idx; ++i) {
		if (child[i].size() > 1) sort(child[i].begin(), child[i].end(), comp);
	}
	for (int i = 0; i < child[0].size(); ++i) dfs(child[0][i], 0);
	return 0;
}
/*
5
3 BANANA APPLE CANDY
2 BANANA APP
4 A B CUP D
3 A B CORN
2 A CAKE
A

--B
----CORN
----CUP
------D
--CAKE
BANANA
--APP
--APPLE
----CANDY
*/