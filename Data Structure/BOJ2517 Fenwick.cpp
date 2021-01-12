//running
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
pair<int, int> v[500000];

int fen[500001];
void _upd(int idx, int num) {
	while (idx <= N) fen[idx] += num, idx += (idx & -idx);
}
int _sum(int idx) {
	int res = 0;
	while (idx > 0) res += fen[idx], idx -= (idx & -idx);
	return res;
}
bool sortv(pair<int, int> A, pair<int, int> B) {
	return A.second > B.second;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &v[i].second), v[i].first=i;
	sort(v, v + N,sortv);
	for (int i = 0; i < N; ++i) v[i].second = i+1;
	sort(v, v + N);

	for (int i = 0; i < N; ++i) {
		int a = v[i].second;	 //let val=v[i].second.second, then
		_upd(a, 1);				 //update cnt of v st second.second==val
		printf("%d\n", _sum(a)); //_sum(a): cnt of v st second.second>=val
	}
	return 0;
}