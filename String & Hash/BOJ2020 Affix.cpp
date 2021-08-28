#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int n;
string str;
bool sortstr(int A, int B) {
	return str.substr(A) < str.substr(B);
}
bool sortstr2(const pii& A, const pii& B) {
	return str.substr(A.first, A.second) < str.substr(B.first, B.second);
}
/*
vi suffixarray(){
	vi arr(n);
	for(int i=0;i<n;++i) arr[i]=i;
	sort(arr.begin(), arr.end(), cmp1);
	return arr;
}
int prefix(int a, int b) {
	int ret = 0;
	while (a < n && b < n && str[a] == str[b]) ++ret, ++a, ++b;
	return ret;
}
*/
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k >> str;

	vi arr(n);
	for (int i = 0; i < n; ++i)	arr[i] = i;
	sort(arr.begin(), arr.end(), sortstr);
	for (int v : arr)cout << str.substr(v) << "\n";
	cout<<"\n";

	// arr[i] = suffix정렬 후, i번째 suffix의 시작 인덱스
	//=> 이 상태에서 i번째 suffix와 i+a번째 suffix가 일치하는 prefix를 가지면
	//   i ~ i+a번째 suffix에서 모두 그 prefix가 등장
	//   즉, 그 prefix를 포함하는 substr이 a+1개 존재

	vii vec;
	for (int i = 0; i + m - 1 < n; ++i) {
		int len = 0, a = arr[i], b = arr[i + m - 1];
		while (a < n && b < n && str[a] == str[b]) ++len, ++a, ++b;
		if (len) vec.push_back({ arr[i], len });
	}
	sort(vec.begin(), vec.end(), sortstr2);
	for (pair<int, int> v : vec) cout<<v.first<<"\t"<<str.substr(v.first,v.second)<<"\n";
	cout<<"\n";

	// vec[*] = { i번째 suffix 시작 인덱스, m번째 떨어진 suffix와 겹치는 길이 }
	//=> 여기까지 vec의 원소는 k번 이상 등장하는 substr을 가진 substr

	bool chk[1001] = { false, };		//substr(vec[j],len)을 이미 셌는가? 판단 위함
	int cnt = 0, vsize = vec.size();
	string ans;
	for (int len = 0; len < n; ++len) {
		//길이 len+1인 부분염기서열 찾기
		for (int j = 0; j < vsize; ++j) {
			if (len >= vec[j].second) continue;
			if (!chk[j] && j > 0 && len < vec[j - 1].second
			&& str[vec[j].first + len] == str[vec[j - 1].first + len]) continue;
			// 길이 len+1 안 되는 substr이거나
			// 아직 카운트 안 한 거 중에 직전 substr이랑 같은 거면 continue

			cout << vec[j].first<<"\t"<<str.substr(vec[j].first, len + 1) << '\n';
			chk[j] = true, ++cnt;
			if (cnt == k) ans = str.substr(vec[j].first, len + 1);
		}
	}
	cout << cnt << "\n" << ans << "\n";
	return 0;
}
/*
12 2 7
TCTAGGATCGAT
  vec  :  count substr
3  A   : A
10 AT  :    AT
8  C   : C
5  G   : G
9  GAT :    GA  GAT
11 T   : T
2  T   :  
7  TC  :    TC
*/