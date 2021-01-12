//the master of number sequence
//consider there is 0
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int A[100000];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, inp, ANS, pow;
        scanf("%d", &N);

        ANS = -2; pow = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &inp); A[i] = inp;
            ANS = max(inp, ANS);
        }

        int two = 0, neg = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) {
                two = 0; neg = 0; continue;
            }
            else if (A[i] < 0) ++neg;
            if (A[i] == 2 || A[i] == -2) ++two;

            if (neg % 2 == 0) {
                pow = max(pow, two); ANS = 1;
            }
        }
        two = 0; neg = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] == 0) {
                two = 0; neg = 0; continue;
            }
            else if (A[i] < 0) ++neg;
            if (A[i] == 2 || A[i] == -2) ++two;

            if (neg % 2 == 0) {
                pow = max(pow, two); ANS = 1;
            }
        }
        while (pow--) ANS = (ANS << 1) % 1000000007;

        printf("%lld\n", ANS);
    }
}