#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
	int idx;
	long long x, y, dx, dy;
};
point P[2000];
bool sortpt(point A, point B) {
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}
bool sort_clockwise(point A, point B) {
	long long tmp = A.dy * B.dx - B.dy * A.dx;
	if (tmp) return tmp > 0;
	return A.dx * A.dx + A.dy * A.dy > B.dx * B.dx + B.dy * B.dy;
}
int main() {
	int T, N, first = 1;
	long long xx, yy, dxx, dyy;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lld%lld", &xx, &yy), P[i] = { i,xx,yy,xx,yy };
		sort(P, P + N, sortpt);
		
		xx = P[0].x; yy = P[0].y;
		for (int i = 1; i < N; ++i) P[i].dx -= xx, P[i].dy -= yy;
		sort(P + 1, P + N, sort_clockwise);

		xx = P[1].dx, yy = P[1].dy; first = 2;
		while (P[first].dy * xx == yy * P[first].dx) first++;
		sort(P, P + first, sortpt);

		for (int i = 0; i < N; ++i) printf("%d ", P[i].idx);
		printf("\n");
	}
	return 0;
}

/*
21 4 0 1 1 5 1 9 1 2 2 7 2 3 3 6 3 1 4 4 4
9 4 0 5 2 5 5 5 7 5 2 6 4 6 1 7 8 7 3 8 5 8
(11 17 19 20 15 18 16 14 13 12 10 9 7 5 3 6 2 8 0 4 1)

15 0 2 0 6 2 0 2 2 1 4 1 8 3 5 5 6 5 2 6 0 7 1 7 5 7 8 6 1 9 4
(0 1 5 4 6 12 7 11 14 8 3 10 13 9 2)

14 6 6 2 0 4 0 3 1 6 1 7 1 1 2 4 2 6 3 0 4 5 4 1 5 3 5 2 6
(9 11 13 0 12 10 8 5 7 4 3 2 1 6)

13 1 0 2 1 1 2 0 3 2 3 3 3 0 4 1 4 1 5 2 5 0 6 3 6 2 7
(3 6 10 12 8 11 9 7 5 4 1 2 0)

8 2 0 1 1 0 2 0 4 2 4 0 3 3 2 1 2
(2 5 3 4 6 7 0 1)
*/