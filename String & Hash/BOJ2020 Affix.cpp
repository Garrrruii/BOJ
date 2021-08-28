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

	// arr[i] = suffix���� ��, i��° suffix�� ���� �ε���
	//=> �� ���¿��� i��° suffix�� i+a��° suffix�� ��ġ�ϴ� prefix�� ������
	//   i ~ i+a��° suffix���� ��� �� prefix�� ����
	//   ��, �� prefix�� �����ϴ� substr�� a+1�� ����

	vii vec;
	for (int i = 0; i + m - 1 < n; ++i) {
		int len = 0, a = arr[i], b = arr[i + m - 1];
		while (a < n && b < n && str[a] == str[b]) ++len, ++a, ++b;
		if (len) vec.push_back({ arr[i], len });
	}
	sort(vec.begin(), vec.end(), sortstr2);
	for (pair<int, int> v : vec) cout<<v.first<<"\t"<<str.substr(v.first,v.second)<<"\n";
	cout<<"\n";

	// vec[*] = { i��° suffix ���� �ε���, m��° ������ suffix�� ��ġ�� ���� }
	//=> ������� vec�� ���Ҵ� k�� �̻� �����ϴ� substr�� ���� substr

	bool chk[1001] = { false, };		//substr(vec[j],len)�� �̹� �ô°�? �Ǵ� ����
	int cnt = 0, vsize = vec.size();
	string ans;
	for (int len = 0; len < n; ++len) {
		//���� len+1�� �κп��⼭�� ã��
		for (int j = 0; j < vsize; ++j) {
			if (len >= vec[j].second) continue;
			if (!chk[j] && j > 0 && len < vec[j - 1].second
			&& str[vec[j].first + len] == str[vec[j - 1].first + len]) continue;
			// ���� len+1 �� �Ǵ� substr�̰ų�
			// ���� ī��Ʈ �� �� �� �߿� ���� substr�̶� ���� �Ÿ� continue

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