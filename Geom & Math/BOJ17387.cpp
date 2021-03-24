//line intersect 1 & 2
#include <cstdio>
#include <algorithm>
using namespace std;


int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long tmp = x1 * y2 + x2 * y3 + x3 * y1;
	tmp -= (y1 * x2 + y2 * x3 + y3 * x1);

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}
int main() {
	long long ax, bx, cx, dx, ay, by, cy, dy;
	int ans = 0;

	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

	int abc = ccw(ax, ay, bx, by, cx, cy);
	int abd = ccw(ax, ay, bx, by, dx, dy);
	int cda = ccw(cx, cy, dx, dy, ax, ay);
	int cdb = ccw(cx, cy, dx, dy, bx, by);

	if ((!abc || !abd) && (!cda || !cdb)) {
		long long a, b, c, d;
		if (ax == bx) {
			if (ay > by) a = by, b = ay;
			else a = ay, b = by;
			if (cy > dy) c = dy, d = cy;
			else c = cy, d = dy;
		}
		else {
			if (ax > bx) a = bx, b = ax;
			else a = ax, b = bx;
			if (cx > dx) c = dx, d = cx;
			else c = cx, d = dx;
		}
		ans = (a <= d && c <= b) ? 1 : 0;
	}
	else {
		ans = (abc * abd <= 0 && cda * cdb <= 0) ? 1 : 0;
	}
	
	printf("%d", ans); return 0;
}