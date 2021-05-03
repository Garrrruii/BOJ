#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;

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
					RES.a[i][j] += (a[i][k] * X.a[k][j]) % MOD;
					RES.a[i][j] %= MOD;
				}
			}
		}
		return RES;
	}
};
Matrix pow(Matrix X, long long n) {
	if (n == 1) return X;
	Matrix RES = pow(X, n >> 1);
	RES = RES * RES;
	if (n & 1) RES = RES * X;
	return RES;
}

int main() {
	long long n;
	scanf("%lld", &n);

	Matrix M(2);
	M.a[0][1] = M.a[1][0] = M.a[1][1] = 1;
	Matrix F = pow(M, n);
	printf("%lld", F.a[0][1]);
	return 0;
}