//LIS
//just find all LIS
//DP로는 어떻게 푸는 겨?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<int> a(N);

		for (int& i : a) cin >> i;
		
		vector<int> lis;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			lis = { -1 };
			for (int j = i; j < N; j++) {
				if (lis.back() < a[j]) lis.push_back(a[j]);
				else *lower_bound(lis.begin(), lis.end(), a[j]) = a[j];
				sum += (lis.size() - 1);
			}
		}
		cout << "Case #" << t << ": " << sum << "\n";
	}
	return 0;
}