#include <iostream>
using namespace std;

int N, R[16][16], a[16], A, ANS;
void game(int n, int dead, int night) {
	if (dead & (1 << A) || n == 1) {
		if (ANS < night) ANS = night;
		return;
	}

	if (n & 1) {//³·
		n--;
		int tar = -1;
		for (int i = 0; i < N; ++i) {
			if (dead & (1 << i)) continue;
			if (tar < 0 || a[tar] < a[i]) tar = i;
		}
		game(n, dead | (1 << tar), night);
	}
	else {//¹ã
		n--; night++;
		for (int i = 0; i < N; ++i) {
			if (dead & (1 << i) || i == A) continue;
			for (int j = 0; j < N; ++j) a[j] += R[i][j];
			game(n, dead | (1 << i), night);
			for (int j = 0; j < N; ++j) a[j] -= R[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) cin >> R[i][j];
	cin >> A;//ÀºÁø
	game(N, 0, 0);
	cout << ANS; return 0;
}