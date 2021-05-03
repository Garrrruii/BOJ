#include <cstdio>
#include <cmath>
using namespace std;

int N, A, B;
bool vis[20];
int s[20][20];
int bf(int idx, int a) {
	if (idx == N) return abs(B - A);

	int addA = 0, addB = 0;
	int aa = 987654321, bb = 987654321;
	if (a) {
		vis[idx] = true;
		for (int i = 0; i < idx; ++i) {
			if (vis[i]) addA += s[i][idx] + s[idx][i];
		}
		A += addA;
		aa = bf(idx + 1, a - 1);
		A -= addA;
	}
	if (idx + a < N) {
		vis[idx] = false;
		for (int i = 0; i < idx; ++i) {
			if (!vis[i]) addB += s[i][idx] + s[idx][i];
		}
		B += addB;
		bb = bf(idx + 1, a);
		B -= addB;
	}
	return (aa < bb) ? aa : bb;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &s[i][j]);
	}
	int ANS = bf(0, N >> 1);
	printf("%d", ANS);
	return 0;
}