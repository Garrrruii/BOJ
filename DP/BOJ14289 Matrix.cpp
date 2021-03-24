//univ walk 2
#include <cstdio>
#include <vector>
using namespace std;
// n-vertices, m-edges (ai-bi)
// how many path of D-edges from 1 to 0

struct Matrix {
	int size;
	vector<vector<long long>> a;
	Matrix() { size = 0; }
	Matrix(int n) {
		size = n;
		a = vector<vector<long long>>(n, vector<long long>(n));
	}
	Matrix operator *(const Matrix& X) {
		Matrix RES(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					RES.a[i][j] += a[i][k] * X.a[k][j];
					RES.a[i][j] %= 1000000007;
				}
			}
		}
		return RES;
	}
};
Matrix pow(Matrix X, int n) {
	if (n == 1) return X;
	Matrix RES = pow(X, n / 2);
	RES = RES * RES;
	if (n % 2) RES = RES * X;
	return RES;
}
int main() {
	int N, M, D, a, b;
	scanf("%d%d", &N, &M);
	Matrix A(N);
	while (M--) {
		scanf("%d%d", &a, &b);
		A.a[a - 1][b - 1] = A.a[b - 1][a - 1] = 1;
	}
	scanf("%d", &D);
	Matrix ANS = pow(A, D);
	printf("%lld", ANS.a[0][0]); return 0;
}