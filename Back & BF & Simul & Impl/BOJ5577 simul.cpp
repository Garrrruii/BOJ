#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int ANS, N, Csize;
vector<pair<int,int>> C;

void Pang(int left,int right, int TMP) {	
	// Erase left and right while satisfying the condition
	while (left >= 0 && right < Csize && C[left].first==C[right].first) {
		int del = C[left].second + C[right].second;
		if (del < 4) break;

		TMP -= del; left--; right++;
	}

	ANS = (ANS < TMP) ? ANS : TMP;
}
int main() {
	int input;

	// Get Input
	scanf("%d", &N);
	scanf("%d", &input); C.push_back({ input,1 });
	for (int i = 1; i < N; ++i) {
		scanf("%d", &input);

		if (input == C.back().first) C.back().second++;
		else C.push_back({ input,1 });
	}
	Csize = C.size();
	
	// Special Case
	if (N < 4) { printf("%d", N); return 0; }

	// Pang!
	ANS = N;

	if (C[1].second > 2) {
		if (C[0].second == 1)
			ANS = N - 1 - C[1].second;
		else {
			C[0].second--;
			Pang(0, 2, N - 1 - C[1].second);
			C[0].second++;
		}
	}
	if (C[Csize - 2].second > 2) {
		int tmp;
		if (C.back().second == 1) {
			tmp = N - 1 - C[Csize - 2].second;
			ANS = (ANS < tmp) ? ANS : tmp;
		}
		else {
			C.back().second--;
			Pang(Csize - 3, Csize - 1, N - 1 - C[Csize - 2].second);
			C.back().second--;
		}
	}

	for (int i = 1; i < Csize - 1; ++i) {
		C[i].second--;
		if (!C[i].second) {
			if (C[i - 1].first == C[i + 1].first) {
				//i-1 i i+1
				int del = C[i - 1].second + 1 + C[i + 1].second;
				if (del > 3) Pang(i - 2, i + 2, N - del);
			}
			else {
				//i-1 i
				if (C[i - 1].second > 2) Pang(i - 2, i + 1, N - 1 - C[i - 1].second);
				//i i+1
				if (C[i + 1].second > 2) Pang(i - 1, i + 2, N - 1 - C[i + 1].second);
			}
		}
		else {
			//i-1
			if (C[i - 1].second > 2) Pang(i - 2, i, N - 1 - C[i - 1].second);
			//i+1
			if (C[i + 1].second > 2) Pang(i, i + 2, N - 1 - C[i + 1].second);
		}
		C[i].second++;
	}
	printf("%d", ANS); return 0;
}
/*
21
3 2 2 2 1 1 3 2 2 2 1 1 1 2 3 3 3 1 2 2 2 (4)
4
1 1 2 1 (0)
5
2 2 3 3 3 (1)
*/