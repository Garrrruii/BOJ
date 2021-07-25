#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct hist {
	vector<int> v;
};
map<string, hist> M[3];
int main() {
	int ans;
	string s(16, ' ');
	for (int i = 0; i < 16; ++i) scanf("%d", &ans), s[i] = ans - 1 + 'a';

	if (s == "abcdefghijklmnop") { printf("0"); return 0; }
	hist h, revh;
	M[0].insert({ s,h });
	M[1].insert({ "abcdefghijklmnop",h });

	char tmp;
	int A = 0, B = 1, C = 2;
	ans = 1;
	while (1) {
		for (auto it = M[A].begin(); it != M[A].end(); it++) {
			s = it->first;
			h = it->second;

			int i, j;
			if (h.v.empty()) i = j = 0;
			else if (h.v.back() < 200) i = ((h.v.back() - 100) / 10) << 2, j = 0;
			else i = 0, j = (h.v.back() - 200) / 10;

			h.v.push_back(0);

			for ( ; i < 16; i += 4) {
				h.v.back() = 10 * ((i >> 2) + 11);
				for (int k = 0; k < 3; ++k) {
					h.v.back()++;
					tmp = s[i + 3], s[i + 3] = s[i + 2];
					s[i + 2] = s[i + 1], s[i + 1] = s[i], s[i] = tmp;

					if (M[A].find(s) != M[A].end()) continue;

					auto tar = M[B].find(s);
					if (tar == M[B].end()) M[C].insert({ s,h });
					else {
						if (ans & 1) revh = tar->second;
						else revh = h, h = tar->second;

						printf("%d\n", ans);
						for (int idx = 0; idx < h.v.size(); ++idx) {
							int m = h.v[idx];
							printf("%d %d %d\n", m / 100, (m % 100) / 10, m % 10);
						}
						for (int idx = revh.v.size() - 1; idx >= 0; --idx) {
							int m = revh.v[idx];
							printf("%d %d %d\n", m / 100, (m % 100) / 10, 4 - (m % 10));
						}

						return 0;
					}
				}
				tmp = s[i + 3], s[i + 3] = s[i + 2];
				s[i + 2] = s[i + 1], s[i + 1] = s[i], s[i] = tmp;
			}
			for ( ; j < 4; ++j) {

				h.v.back() = 10 * (j + 21);
				for (int k = 0; k < 3; ++k) {
					h.v.back()++;
					tmp = s[j + 12], s[j + 12] = s[j + 8];
					s[j + 8] = s[j + 4], s[j + 4] = s[j], s[j] = tmp;

					if (M[A].find(s) != M[A].end()) continue;

					auto tar = M[B].find(s);
					if (tar == M[B].end()) M[C].insert({ s,h });
					else {
						if (ans & 1) revh = tar->second;
						else revh = h, h = tar->second;

						printf("%d\n", ans);
						for (int idx = 0; idx < h.v.size(); ++idx) {
							int m = h.v[idx];
							printf("%d %d %d\n", m / 100, (m % 100) / 10, m % 10);
						}
						for (int idx = revh.v.size() - 1; idx >= 0; --idx) {
							int m = revh.v[idx];
							printf("%d %d %d\n", m / 100, (m % 100) / 10, 4 - (m % 10));
						}

						return 0;
					}
				}
				tmp = s[j + 12], s[j + 12] = s[j + 8];
				s[j + 8] = s[j + 4], s[j + 4] = s[j], s[j] = tmp;
			}
		}
		M[A].clear();

		ans++;
		A++, A %= 3;
		B++, B %= 3;
		C++, C %= 3;
	}
}
/*
13 2 3 4
6 7 8 1
5 10 11 12
15 16 9 14
1 2 1 / 1 4 2 / 2 1 3

7 2 15 4
9 8 3 6
13 10 5 12
1 14 11 16
2 1 1 / 2 3 3 / 1 2 2

7 2 15 4
6 9 8 3
13 10 5 12
1 14 11 16
1 2 3 / 2 3 3 / 2 1 1 / 1 2 2
*/