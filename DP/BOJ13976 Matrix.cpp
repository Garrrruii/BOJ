//tile2
#include <cstdio>
using namespace std;

long long DIV = 1000000007;
struct matrix {
	long long a, b, c, d;
};
long long addmod(long long A, long long B) {
	long long Amod = A % DIV;
	long long Bmod = B % DIV;
	if (!Amod) return Bmod;
	else if (!Bmod) return Amod;
	else if (Amod + Bmod <= Amod) return (Amod - DIV + Bmod) % DIV;
	else return (Amod + Bmod) % DIV;
}
matrix Apow(long long n) {
	printf("n=%d\n", n);
	if (n == 1) {
		matrix A = { 15, DIV-4, 4, DIV-1 };
		return A;
	}
	matrix tmp = Apow(n / 2);
	long long x[4];
	x[0] = addmod((tmp.a * tmp.a) % DIV,(tmp.b * tmp.c) % DIV);
	x[1] = (((tmp.a + tmp.d) % DIV) * tmp.b) % DIV;
	x[2] = (((tmp.a + tmp.d) % DIV) * tmp.c) % DIV;
	x[3] = addmod((tmp.d * tmp.d) % DIV,(tmp.b * tmp.c) % DIV);
	matrix res = { x[0],x[1],x[2],x[3] };
	printf("n=%d   %lld %lld %lld %lld \n", n, res.a, res.b, res.c, res.d);
	if (n % 2) {
		long long y[4];
		y[0] = addmod((15 * x[0]) % DIV,(4 * x[1]) % DIV);
		y[1] = (((DIV - 4) * x[0]) % DIV + x[1]) % DIV;
		y[2] = addmod((15 * x[2]) % DIV,(4 * x[3]) % DIV);
		y[3] = (((DIV - 4) * x[2]) % DIV + x[3]) % DIV;
		res = { y[0],y[1],y[2],y[3] };
	}
	printf("n=%d   %lld %lld %lld %lld \n", n, res.a, res.b, res.c, res.d);
	return res;
}
int main() {
	long long N; scanf("%lld", &N);
	if (N % 2) { printf("0"); return 0; }
	else if (N == 2) { printf("3"); return 0; }
	N /= 2;
	matrix X = Apow(N / 2);
	long long ans=(N%2)? addmod(3 * X.a,X.b): addmod(3 * X.c,X.d);

	printf("%lld", ans); return 0;
}

/*
12 2131
14 7953
16 29681
18 110771
20 413403
22 1542841
24 5757961
26 21489003
28 80198051
30 299303201
32 117014746
34 168755783
36 558008386
38 63277747
40 695102609
*/