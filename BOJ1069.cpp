//home
//dist=Q*D+R1=(Q+1)*D-R2
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int X, Y, D, T;
	scanf("%d%d%d%d", &X, &Y, &D, &T);
	double dist = sqrt(X * X + Y * Y);
	int Q = (int)dist / D;
	double R1 = dist - Q * D;
	double R2 = D - R1;
	double ANS = dist;
	if (Q) ANS = min(ANS, T * Q + min((double)T, R1));
	else ANS = min(ANS, T + min((double)T, R2));
		
	printf("%.11lf ", ANS);

	return 0;
}