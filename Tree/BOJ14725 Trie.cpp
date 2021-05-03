//Ant Burrow
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str[15005];			//str[idx] idx번째 노드
vector<int> child[15005];	//child[i] str[i]의 자식 노드의 인덱스

bool sortchild(int& A, int& B) {
	int i = 0;
	while (i < str[A].size() && i < str[B].size()) {
		if (str[A][i] != str[B][i]) return str[A][i] < str[B][i];
		i++;
	}
	return str[A].size() < str[B].size();
}
void dfs(int curidx, int depth) {
	for (int i = 0; i < depth; ++i) cout << "--";
	cout << str[curidx] << "\n";

	depth++;
	for (int nxtidx : child[curidx]) dfs(nxtidx, depth);
	return;
}
int main() {
	int N, K, idx = 1;
	string tmp;

	cin >> N;
	while (N--) {
		cin >> K;

		int par = 0;
		while (K--) {
			cin >> tmp;

			// par이 이미 tmp를 child로 가지고 있나
			bool newchild = true;
			for (int added : child[par]) {
				if (str[added] == tmp) {
					par = added; newchild = false; break;
				}
			}
			// 아니면 새로운 child 추가
			if (newchild) {
				child[par].push_back(idx);
				str[idx] = tmp; par = idx++;
			}
		}
	}
	for (int i = 0; i < idx; ++i) sort(child[i].begin(), child[i].end(), sortchild);
	for (int curidx : child[0]) dfs(curidx, 0);
	return 0;
}
/*
5
3 B A C
2 B D
2 A C
4 A B C D
3 A B D
*/