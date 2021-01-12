//recommending candidate
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int rec[100];
vector<pair<int, int>> can;	// stdID, order

bool sortcan(pair<int, int> A, pair<int, int> B) {
	if (rec[A.first] == rec[B.first]) return A.second > B.second;
	return rec[A.first] > rec[B.first];
}
int main() {
	int N, M, tmp;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &tmp);
        rec[tmp]++;
		
        if (rec[tmp]==1) {
			if (can.size() == N) {
				sort(can.begin(), can.end(), sortcan);
				rec[can.back().first] = 0; can.back()= { tmp,i };
			}
			else can.push_back({ tmp,i });
		}

//		for (auto a : can) printf("%d(%d) ", a.first, rec[a.first]);
//		printf("\n");
	}
	sort(can.begin(), can.end());
	for (auto a : can) printf("%d ", a.first);
	return 0;
}

/*
3 10
2 1 4 4 5 5 4 2 7 2
*/
