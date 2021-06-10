//center of the outer triangle
#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		double ax, ay, bx, by, cx, cy;
		scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		
		double A = by - cy, B = -cy + ay, C = bx - ax;
		double a = bx - cx, b = -cx + ax, c = -by + ay;
		double s = (a * C - A * c) / (a * B - A * b);

		double x = bx - s * B;
		double y = by + s * b;
		printf("%.4f %.4f\n", x, y);
	}
	return 0;
}