//pizza arrangement
//might be r1=r2
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	double r3 = (3 - 2 * sqrt(2)) / (3 + 2 * sqrt(2));
	while (T--) {
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);

		double a = (double)A, b = (double)B;
		double r0 =(a * b)/ (a + b + sqrt(a * a + b * b));
		double a1 = a - r0, d1 = sqrt(r0 * r0 + a1 * a1);
		double b1 = b - r0, d2 = sqrt(r0 * r0 + b1 * b1);
		double r1 = (d1 - r0) / (d1 + r0); r1 *= r1;
		double r2 = (d2 - r0) / (d2 + r0); r2 *= r2;

		//printf("%f, %f %f %f %f %f %f\n", r0, a1, d1, r1, b1, d2, r2);

		double ans = r0 * r0 * 3.1415926;
		double s1 = r1 * ans, s2 = r2 * ans, s3 = r3 * ans;
		K--;
		while (K--) {
			//printf("%f %f %f\n", s1, s2, s3);
			if (s1 >= s2 && s1 >= s3) ans = s1, s1 *= r1;
			else if (s2 >= s1 && s2 >= s3) ans = s2, s2 *= r2;
			else ans = s3, s3 *= r3;
		}
		printf("%.7f\n", ans);
	}
	return 0;
}