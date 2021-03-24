#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;

vector<pair<double, double>> v;
int main() {
	double R = 0, a, b;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &a, &b);
		double r = sqrt(a * a + b * b);

		if (r > R) v.clear(), v.push_back({ a,b }), R = r;
		else if (r == R) v.push_back({ a,b });
	}

	double ANS = 0, TMP;
	double fir = atan2(v[0].second, v[0].first) * 180 / 3.1415926535;

	double A = fir, B;
	for (int i = 1; i < v.size(); ++i) {
		B = atan2(v[i].second, v[i].first) * 180 / 3.1415926535;

		TMP = B - A + ((B <= A) ? 360 : 0);
		A = B;
		if (ANS < TMP) ANS = TMP;
	}
	TMP = fir - A + ((fir <= A) ? 360 : 0);
	if (ANS < TMP) ANS = TMP;

	printf("%.7f", ANS); return 0;
}
/*
3
-1 -1 1 -1 0 3 => (fir<A)·Î ÇÏ¸é 0³ª¿È
*/