#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	long long x, y, dx, dy;
	bool vis = false;
};
bool find_zero(point A, point B) {
	if (!A.vis && !B.vis) {
		if (A.x == B.x) return A.y > B.y;
		else return A.x > B.x;
	}
	if (A.vis) return false;
	else return true;
}
bool sort_clockwise(point A, point B) {
	return A.dx * B.dy < A.dy * B.dx;
}
bool ccw(point O, point A, point B) {
	if ((A.x - O.x) * (B.y - O.y) > (A.y - O.y)* (B.x - O.x)) return true;
	else return false;
}
int main() {
	point P, p[1000];
	int N;
	scanf("%d%lld%lld", &N, &P.x, &P.y);
	for (int i = 0; i < N; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);

	int ANS = 0;	//num of convex hull
	vector<int> v;
	while (N - v.size() > 2) {
		// Find Zero
		sort(p, p + N, find_zero);
		N -= v.size(); v.clear();

		// Sort Clockwise
		long long x0 = p[0].x, y0 = p[0].y; p[0].vis = true;
		for (int i = 1; i < N; ++i) {
			p[i].dx = p[i].x - x0; p[i].dy = p[i].y - y0;
		}
		sort(p + 1, p + N, sort_clockwise);

		// Find Convex Hull
		v.push_back(0), v.push_back(1);
		for (int i = 2; i < N; ++i) {
			while (v.size() > 1) {
				int sec = v.back(); v.pop_back();
				int fir = v.back();
				if (!ccw(p[fir], p[sec], p[i])) {
					v.push_back(sec); break;
				}
			}
			v.push_back(i);
		}

		// Check is P in Convex Hull
		for (int i = 1; i < v.size(); ++i) {
			if (ccw(P, p[v[i - 1]], p[v[i]])) { printf("%d", ANS); return 0; }
		}
		if (ccw(P, p[v.back()], p[v[0]])) { printf("%d", ANS); return 0; }

		// Available Convex Hull
		for (int ve : v) p[ve].vis = true;
		ANS++;
	}
	printf("%d", ANS); return 0;
}
/*
16 0 0
-2 4 -2 -2 0 -4 4 2 4 -2 1 2 -7 -3 2 -1
-4 5 5 6 -7 -1 -4 -6 -6 -4 2 -6 7 0 3 1
(2)

//		printf("\nSort\n");
//		for (int i = 0; i < maxsize; ++i) printf("%lld %lld  ", p[i].x, p[i].y);

//		printf("\nFind Convex Hull\n");
//		for (int ve : v) printf("%lld %lld  ", p[ve].x, p[ve].y);
//		printf("\n");
*/