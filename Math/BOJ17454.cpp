//GOD
#include <cstdio>
using namespace std;

int main() {
	int A, B, C, D, E, F, T;
	scanf("%d", &T);
	while (T--) { 
		scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
		//  A B
		//C   D  (1) Cb+Ec > Aa+Fc => (E-F)c > Aa-Cb
		//E F    (2) Cb+Ec > Ba+Db => Ec > Ba+(D-C)b
		//
		//(1) E(F-E)c < -AEa+CEb
		//(2) E(F-E)c > B(F-E)a-(E-F)(D-C)b
		//
		// => {AE+B(F-E)}a < {CE+(E-F)(D-C)}b
		if (E >= F) printf("GOD\n");
		else {
			int X = A * E + (F - E) * B;
			int Y = C * E + (E - F) * (D - C);
			if ((Y < 0 && 0 < X) || (Y < 0 & !X) || (!Y && 0 < X)) printf("KDH\n");
			else printf("GOD\n");
		}
	}
	return 0;
}