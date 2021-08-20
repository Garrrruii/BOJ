#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> V;
int main() {
    int dy[4] = { 1,0,-1,0 };
    int dx[4] = { 0,1,0,-1 };

    int N, M, b[49][49];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) scanf("%d", &b[i][j]);
    }

    int d, s, x, y, ANS = 0;
    while (M--) {
        scanf("%d%d", &d, &s);

        // Blizard
        x = y = N >> 1;
        if (d == 1) {
            while (s--) --y, b[y][x] = 0;
        }
        else if (d == 2) {
            while (s--) ++y, b[y][x] = 0;
        }
        else if (d == 3) {
            while (s--) --x, b[y][x] = 0;
        }
        else {
            while (s--) ++x, b[y][x] = 0;
        }

        // Count Marvel
        x = y = (N >> 1) - 1;
        for (int K = 2; K < N; K += 2) {
            for (int dir = 0; dir < 4; ++dir) {
                for (int k = 0; k < K; ++k) {
                    x += dx[dir], y += dy[dir];
                    if (!b[y][x]) continue;

                    // 구슬 넣음
                    if (!V.empty() && b[y][x] == V.back().first) V.back().second++;
                    else V.push_back({ b[y][x],1 });
                }
            }
            --x, --y; //↖로 이동
        }

        // Pop
        int vsize = V.size(), vi = 0;
        while (1) {
            for (vi = vsize - 1; vi >= 0; --vi) {
                if (V[vi].second > 3) {
                    ANS += V[vi].first * V[vi].second;
                    V.erase(V.begin() + vi);
                }
            }
            if (vsize == V.size()) break;
            vsize = V.size();
            for (int vi = vsize - 2; vi >= 0; --vi) {
                if (V[vi + 1].first == V[vi].first) {
                    V[vi].second += V[vi + 1].second;
                    V.erase(V.begin() + vi + 1);
                }
            }
            vsize = V.size();
        }

        // Rearrange
        vsize = V.size(); vi = 0;
        x = y = (N >> 1) - 1;
        for (int K = 2; K < N; K += 2) {
            for (int dir = 0; dir < 4; ++dir) {
                for (int k = 0; k < K; k += 2) {
                    if (vi < vsize) {
                        x += dx[dir], y += dy[dir], b[y][x] = V[vi].second;
                        x += dx[dir], y += dy[dir], b[y][x] = V[vi].first; vi++;
                    }
                    else {
                        x += dx[dir], y += dy[dir], b[y][x] = 0;
                        x += dx[dir], y += dy[dir], b[y][x] = 0;
                    }
                }
            }
            --x, --y;
        }
        V.clear();
    }
    printf("%d", ANS); return 0;
}
/*
9 1
0 0 0 0 0 0 0 0 0
3 2 1 3 1 3 3 3 0
1 3 3 3 1 3 3 1 0
0 2 2 2 1 2 2 1 0
0 1 2 1 0 2 2 1 0
0 3 3 1 1 2 2 2 0
0 3 3 3 1 1 1 2 0
0 1 1 1 3 3 3 2 0
0 0 0 0 0 0 0 0 0
1 3
(97)
*/