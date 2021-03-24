#include <cstdio>
#include <vector>
using namespace std;

long long DIV = 1000000007;
struct Matrix {
	long long a[2][2];
	Matrix() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
	Matrix(long long x, long long y, long long z, long long w) {
		a[0][0] = x; a[0][1] = y;
		a[1][0] = z; a[1][1] = w;
	}
	Matrix operator *(const Matrix& X) {
		Matrix RES(0,0,0,0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					RES.a[i][j] += a[i][k] * X.a[k][j];
					while (RES.a[i][j] < 0) RES.a[i][j] += DIV;
					RES.a[i][j] %= DIV;
				}
			}
		}
		return RES;
	}
};
Matrix pow(Matrix X, long long n) {
	if (n == 0) {
		Matrix E(1, 0, 0, 1); return E;
	}
	if (n == 1) return X;
	Matrix RES = pow(X, n / 2);
	RES = RES * RES;
	if (n % 2) RES = RES * X;
	return RES;
}
int main() {
	long long N;
	scanf("%lld", &N);
	if (N % 2) printf("0");
	else {
		Matrix A(15, -4, 4, -1);
		N /= 2;
		Matrix M = pow(A, N/2);
		long long ANS = 0;
		if (N % 2) ANS = 3 * M.a[0][0] + M.a[0][1];
		else ANS = 3 * M.a[1][0] + M.a[1][1];
		while (ANS < 0) ANS += DIV;
		
		printf("%lld", ANS % DIV);
	}
	return 0;
}