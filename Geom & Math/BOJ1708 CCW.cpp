#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	long long x, y, dx = 0, dy = 0;
};
point p[100000];
vector<point> v;
bool find_zero(point A, point B) {
	//point with max y, max x = starting point = p[0]
	if (A.y == B.y) return A.x > B.x;
	else return A.y > B.y;
}
bool sort_clockwise(point A, point B) {
	//sort points clockwise based on p[0],
	//if parallel, nearer first
	long long a = A.dx * B.dy - A.dy * B.dx;
	if (a == 0) return A.dx * A.dx < B.dx * B.dx;
	else return a < 0;
}
bool ccw(point O, point A, point B) {
	// OA X OB < 0 => clockwise
	if ((A.x - O.x) * (B.y - O.y) >= (A.y - O.y)* (B.x - O.x)) return true;
	else return false;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);

	// Sort points clockwise based on p[0](y max, x max)
	sort(p, p + N, find_zero);
	int x0 = p[0].x, y0 = p[0].y;
	for (int i = 1; i < N; ++i) p[i].dx = p[i].x - x0, p[i].dy = p[i].y - y0;
	sort(p + 1, p + N, sort_clockwise);

	// Find convex hull
	v.push_back(p[0]), v.push_back(p[1]);
	for (int i = 2; i < N; ++i) {
		while (v.size() > 1) {
			point sec = v.back(); v.pop_back();
			point fir = v.back();
			if (!ccw(fir, sec, p[i])) { v.push_back(sec); break; }
			//sec이 적합한지 아닌지 판정
		}
		v.push_back(p[i]);
	}
	
	printf("%d", v.size()); return 0;
}
/*
14
0 4 3 2 3 3 2 4 4 1 4 4 8 1
5 0 6 2 6 0 7 0 8 2 6 4 7 3

for (point ve : v)printf("%lld %lld  ", ve.x, ve.y);
printf("\n");
*/