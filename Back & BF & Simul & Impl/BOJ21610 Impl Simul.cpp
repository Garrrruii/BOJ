//마법사 상어와 비바라기
#include <cstdio>
#include <vector>
using namespace std;
//(0,0)~(N-1,N-1)

struct point {
	int i, j;
};
vector<point> C;	//cloud
int main() {
	int N, M, A[50][50], d, s;
	bool was_cloud[50][50] = { false, };

	scanf("%d%d", &N, &M);
	int di[9] = { 0,0,N - 1,N - 1,N - 1,0,1,1,1 };
	int dj[9] = { 0,N - 1,N - 1,0,1,1,1,0,N - 1 };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) scanf("%d", &A[i][j]);
	}

	//초기 구름 생성
	C.push_back({ N - 1,0 }); C.push_back({ N - 1,1 });
	C.push_back({ N - 2,0 }); C.push_back({ N - 2,1 });
	while (M--) {
		scanf("%d%d", &d, &s);
	
		for (point& c : C) {
			//구름 이동
			c.i += s * di[d], c.i %= N;
			c.j += s * dj[d], c.j %= N;
			
			//비 내림
			A[c.i][c.j]++;

			//구름 사라짐
			was_cloud[c.i][c.j] = true;
		}
		
		//물복사버그 시전
		for (point c : C) {
			int cnt = 0;
			for (int k = 0; k < 4; ++k) {
				int ni = c.i + "2200"[k] - '1';
				int nj = c.j + "0220"[k] - '1';
				if (0 <= ni && ni < N && 0 <= nj && nj < N && A[ni][nj]) cnt++;
			}
			A[c.i][c.j] += cnt;
		}

		//구름 생성
		C.clear();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!was_cloud[i][j] && A[i][j] > 1) A[i][j] -= 2, C.push_back({ i,j });
				was_cloud[i][j] = false;
			}
		}

/*		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) printf("%2d ",A[i][j]);
			printf("\n");
		}
		printf("\n"); */
	}

	int ANS = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) ANS += A[i][j];
	}
	printf("%d", ANS); return 0;
}