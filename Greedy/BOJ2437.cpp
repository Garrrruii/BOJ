//scale
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	pair<int, int> w[1000];
	scanf("%d", &N);
	w[0] = { 0,0 };
	for (int i = 1; i <= N; ++i) scanf("%d", &w[i].first), w[i].second = w[i].first;
	sort(w, w + N + 1);
	for (int i = 1; i < N; ++i) {
		int W = w[i].first;
		for (int j = i + 1; j <= N; ++j) w[j].second += W;
	}
	for (int i = 1; i <= N; ++i) {
		if (w[i - 1].second + 1 < w[i].first) {
			printf("%d", w[i - 1].second + 1); return 0;
		}
	}
	printf("%d", w[N].second + 1); return 0;
}