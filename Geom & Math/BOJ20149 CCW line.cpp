//line intersect 3
#include <cstdio>
#include <algorithm>
using namespace std;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double tmp = x1 * y2 + x2 * y3 + x3 * y1;
	tmp -= (y1 * x2 + y2 * x3 + y3 * x1);

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}
int main() {
	double ax, bx, cx, dx, ay, by, cy, dy;
	bool intersect = false;

	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

	double abc = ccw(ax, ay, bx, by, cx, cy);
	double abd = ccw(ax, ay, bx, by, dx, dy);
	double cda = ccw(cx, cy, dx, dy, ax, ay);
	double cdb = ccw(cx, cy, dx, dy, bx, by);

	double tmp;
	if ((!abc || !abd) && (!cda || !cdb)) { //최소 세 점이 일직선상에 존재
		if (ax == bx) {
			if (ay > by) tmp = ay, ay = by, by = tmp;
			if (cy > dy) tmp = cy, cy = dy, dy = tmp;
			intersect = (ay <= dy && cy <= by);
		}
		else {
			if (ax > bx) tmp = ax, ax = bx, bx = tmp, tmp = ay, ay = by, by = tmp;
			if (cx > dx) tmp = cx, cx = dx, dx = tmp, tmp = cy, cy = dy, dy = tmp;
			intersect = (ax <= dx && cx <= bx);
		}
	}
	else intersect = (abc * abd <= 0 && cda * cdb <= 0);

	if (!intersect) { printf("0"); return 0; }

	double m1, m2, x, y;

	if (ax == bx) {
		if (cx == dx) {									//1: AB//CD//y-axis
			if (ay == dy) printf("1\n%f %f", ax, ay);
			else if (by == cy) printf("1\n%f %f", bx, by);
			else printf("1");
			return 0;
		}
		else {											//4: AB//y-axis
			m2 = (dy - cy) / (dx - cx);
			x = ax; y = m2 * (ax - cx) + cy;
		}
	}
	else if (cx == dx) {								//5: CD//y-axis
		m1 = (ay - by) / (ax - bx);
		x = cx; y = m1 * (cx - ax) + ay;
	}
	else {
		m1 = (ay - by) / (ax - bx);
		m2 = (dy - cy) / (dx - cx);
		if (m1 == m2) {									//2,3: AB//CD, not y-axis
			if (ax == dx) printf("1\n%.10f %.10f", ax, ay);
			else if (bx == cx) printf("1\n%.10f %.10f", bx, by);
			else printf("1");
			return 0;
		}
		else if (!m1) x = (ay - cy) / m2 + cx, y = ay;	//6: AB//x-axis
		else if (!m2) x = (cy - ay) / m1 + ax, y = cy;	//7: CD//x-axis
		else {											//8: intersect
			x = (m1 * ax - m2 * cx - ay + cy) / (m1 - m2);
			y = (ay / m1 - cy / m2 - ax + cx) / (1 / m1 - 1 / m2);
		}
	}
	printf("1\n%.10f %.10f", x, y);

	return 0;
}
/*
0	교차 X
1	교차 -- AB // CD -- // y-axis
2					 ┕ // x-axis
3					 ┕ // else
4		 ┕ else ------ AB // y-axis	
5					 ┕ CD // y-axis
6					 ┕ AB // x-axis
7					 ┕ CD // x-axis
8					 ┕ else
*/