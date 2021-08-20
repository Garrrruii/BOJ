#include <iostream>
#include <cstdio>
#include <algorithm>
//long main street, rent house on main street
//location of house s.t. max(dist(house,fac)) is min

using namespace std;
int K, N, cnt, typ[100001]; //count by type
int MIN = 2e9, l, r;
pair<int, int> P[1000000];  //{pos,type}

int main() {
    scanf("%d%d", &K, &N);
    for (int i = 0; i < N; i++) scanf("%d%d", &P[i].first, &P[i].second);
    sort(P, P + N);
    //sort facilities by dist

    int ANS = 0;
    while (r < N) {
        if (!typ[P[r].second]) cnt++; //add type P[r].second
        typ[P[r].second]++;

        while (cnt == K) {            //K-types all exists in MIN, P[l]~P[r] facilities
            int dist = (P[r].first - P[l].first + 1) >> 1;
            if (dist < MIN) {         
                MIN = dist; ANS = P[r].first - dist;
            }
            typ[P[l].second]--;       //erase type P[l].second (since dist to P[l].first > MIN)
            if (!typ[P[l].second]) cnt--;
            l++;
        }
        r++;
    }
    printf("%d", ANS);
    return 0;
}
