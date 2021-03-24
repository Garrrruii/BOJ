#include <cstdio>
#include <cmath>
using namespace std;
//minimum of sum(vector in vector matching)

int N, p[2][20];
bool isend[20];
double ANS;
void vecmatch(int k, int s, int e) {
	//decide k to be starting point or ending point
	if (k == N) {
		double x = -(double)p[0][0], y = -(double)p[1][0];
		for (int i = 1; i < N; ++i) {
			if (isend[i]) x += (double)p[0][i], y += (double)p[1][i];
			else x -= (double)p[0][i], y -= (double)p[1][i];
		}
		double tmp = sqrt(x * x + y * y);
		if (ANS > tmp) ANS = tmp;
//		for (int i = 0; i < N; ++i) if (isend[i]) printf("%d ", i);
//		printf("=> %.7f\n", tmp);
	}
	else {
		if (e < N / 2) isend[k] = true, vecmatch(k + 1, s, e + 1);
		if (s < N / 2) isend[k] = false, vecmatch(k + 1, s + 1, e);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);

		for (int i = 0; i < N; ++i) scanf("%d%d", &p[0][i], &p[1][i]);
		ANS = 1987654321;
		vecmatch(1, 1, 0);
		printf("%.7f\n", ANS);
	}
	return 0;
}
