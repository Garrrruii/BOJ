#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	string str;
	cin >> n >> m >> k >> str;

	queue<vector<int>> Q;
	map<char, vector<int>> M;
	for (int i = 0; i < n; i++) M[str[i]].push_back(i);
	for (auto it = M.begin(); it != M.end(); it++) Q.push(it->second);

	string ans;
	int cnt = 0;
	int len = 1, qsize = Q.size();
	while (qsize) {
		while(qsize--) {
			vector<int> V = Q.front(); Q.pop();
			if ((int)V.size() < m) continue;
			//길이 len인 어떤 substr에 대한 벡터 V

			cnt++;
			if (cnt == k) ans = str.substr(V[0], len);
			//V[0]부터 길이 len = V[1]부터 길이 len = ...

			M.clear();
			for (int v : V) {
				if (v + len >= n) break;		//out of bound
				M[str[v + len]].push_back(v);	//substr(v,len+1)의 시작 인덱스 = v
			}
			for (auto it = M.begin(); it != M.end(); it++) Q.push(it->second);
			//길이 len+1인 substr에 대한 벡터 push
		}
		len++; qsize = Q.size();
	}
	cout << cnt << "\n" << ans;
	return 0;
}