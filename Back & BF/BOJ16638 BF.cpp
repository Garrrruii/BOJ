#include <cstdio>
#include <vector>
using namespace std;

int N;		//odd<20
char x[20];
bool brack[10];
long long ANS = -(1 << 31); //make MAX

void AddBracket(int n) {
    if (n >= N) {
        if (n == 1) { ANS = x[0] - '0'; return; }
        
        // Get v
        int idx = 0;
        long long TMP = 0;
        vector<long long> v;

        // 0 and 2
        if (brack[0]) {
            if (x[1] == '-') v.push_back((long long)(x[0] - x[2]));
            else v.push_back((long long)(x[0] - '0' + x[2] - '0'));
            idx = 4;
        }
        else v.push_back((long long)(x[0] - '0')), idx = 2;

        // idx and idx+2
        while (idx < N) {
            if (idx < N - 1 && brack[idx / 2]) {
                long long tmp;
                if (x[idx + 1] == '-') tmp = (long long)(x[idx] - x[idx + 2]);
                else tmp = (long long)(x[idx] - '0' + x[idx + 2] - '0');

                if (x[idx - 1] == '*') v.back() *= tmp;
                else if (x[idx - 1] == '+') v.push_back(tmp);
                else v.push_back(-tmp);

                idx += 4;
            }
            else {
                if (x[idx - 1] == '*') v.back() *= ((long long)(x[idx] - '0'));
                else if (x[idx - 1] == '+') v.push_back((long long)(x[idx] - '0'));
                else v.push_back(-(long long)(x[idx] - '0'));

                idx += 2;
            }
        }

        // Get TMP=sum(v) & Update ANS
        for (long long e : v) TMP += e;
        ANS = (ANS > TMP) ? ANS : TMP;

        // DEBUG
        //for (int i = 1; i < N; i += 2) printf("%d ", ((brack[i / 2]) ? i : 0));
        //printf(": ");
        //for (long long e : v) printf("%lld ", e);
        //printf("= %lld\n", TMP);
    }
    else {
        brack[n / 2] = true;
        for (int i = n + 4; i < N; i += 2) {
            if (x[i] != '*') AddBracket(i);
        }
        AddBracket(N);
        brack[n / 2] = false;
    }
    return;
}
int main() {
    scanf("%d%s", &N, &x);
    
    for (int i = 1; i < N; i += 2) {
        if (x[i] != '*') AddBracket(i);
    }
    AddBracket(N);
    printf("%lld", ANS);
    return 0;
}
/*
13
2+3*7+5+8-4*2 (68)
5
1*2-3 (-1)
*/