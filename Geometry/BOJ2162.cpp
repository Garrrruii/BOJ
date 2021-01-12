//line segment group
//BOJ17386 line intersect 1
//BOJ17387 line intersect 2
//how to shorten time..?
#include <cstdio>
#include <algorithm>
using namespace std;

struct segment {
	int x1, y1, x2, y2;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	long long tmp = ((long long)x1 * y2 + (long long)x2 * y3 + (long long)x3 * y1);
	tmp -= ((long long)y1 * x2 + (long long)y2 * x3 + (long long)y3 * x1);

	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}
int main() {
	int N, ax, ay, bx, by;
	int g[3000], cnt[3000] = { 0, };
	segment seg[3000];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &ax, &ay, &bx, &by);
		seg[i] = { ax,ay,bx,by }; g[i] = i;
		
		for (int j = 0; j < i; ++j) {
			if (g[i] == g[j]) continue;

			int cx = seg[j].x1, dx = seg[j].x2;
			int cy = seg[j].y1, dy = seg[j].y2;

			int abc = ccw(ax, ay, bx, by, cx, cy);
			int abd = ccw(ax, ay, bx, by, dx, dy);
			int cda = ccw(cx, cy, dx, dy, ax, ay);
			int cdb = ccw(cx, cy, dx, dy, bx, by);

			bool intersect;
			if ((!abc || !abd) && (!cda || !cdb)) {
				int a, b, c, d;
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
				intersect = (a <= d && c <= b) ? true : false;
			}
			else {
				intersect = (abc * abd <= 0 && cda * cdb <= 0) ? true : false;
			}
			
			if (intersect) { //union(i,j)
				int tar, group;
				if (g[i] < g[j]) tar = g[j], group = g[i];
				else tar = g[i], group = g[j];

				for (int k = tar; k <= i; ++k) if (g[k] == tar) g[k] = group;
			}
		}
	//	for (int j = 0; j <= i; ++j) printf("%d ", g[j]);
	//	printf("\n");
	}
	for (int i = 0; i < N; ++i) cnt[g[i]]++;
	int CNT = 0, MAX = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt[i]) MAX = max(cnt[i], MAX), CNT++;
	}
	printf("%d\n%d", CNT, MAX); return 0;
}

/*
7
5 5 9 9
6 6 9 9 
3 3 1 3
5 5 1 1
2 1 6 5
6 10 10 6
1 5 5 1
*/