#include <iostream>
using namespace std;

int N, K, ord[10][10];
int B[20], C[20], bidx = 0, cidx = 0;

int won[3], A=0;
bool play(int player) {
	if (won[0] >= K) return true;
	else if (won[1] >= K || won[2] >= K) return false;

	int nxt, w;
	if (player == 1) {	
		for (int n = 1; n <= N; ++n) {
			if (A & (1 << n)) continue;

			if (ord[n][B[bidx]] > 1) w = 0, nxt = 2;	//A,C
			else w = 1, nxt = 3;						//B,C

			A |= (1 << n); bidx++; won[w]++;
			if (play(nxt)) return true;
			A &= (~(1 << n)); bidx--; won[w]--;
		}
	}
	else if (player == 2) {
		for (int n = 1; n <= N; ++n) {
			if (A & (1 << n)) continue;

			if (ord[n][C[cidx]] > 1) w = 0, nxt = 1;	//A,B
			else w = 2, nxt = 3;						//B,C

			A |= (1 << n); cidx++; won[w]++;
			if (play(nxt)) return true;
			A &= (~(1 << n)); cidx--; won[w]--;
		}
	}
	else {		
		if (ord[B[bidx]][C[cidx]] > 1) w = 1, nxt = 1;	//A,B
		else w = 2, nxt = 2;							//A,C

		bidx++; cidx++; won[w]++;
		if (play(nxt)) return true;
		bidx--; cidx--; won[w]--;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) 
		for (int j = 1; j <= N; ++j) cin >> ord[i][j];

	for (int i = 0; i < 20; ++i) cin >> B[i];
	for (int i = 0; i < 20; ++i) cin >> C[i];

	cout << (play(1) ? 1 : 0); return 0;
}
// 어차피 20회 넘게 게임할 일이 없음
// if (bidx == 20 || cidx == 20) return false;

// PRINT FOR DEBUG
//	for (int t = 0; t < tmp; ++t) cout << " ";
//	cout << player << ":\t" << won[0] << " " << won[1] << " " << won[2] << " winner=" << w;
//	cout << " Astate=" << A << " bid=" << bidx << " cid=" << cidx << "\n";
