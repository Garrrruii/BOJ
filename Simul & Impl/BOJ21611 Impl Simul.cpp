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
       
        // Pop and Move
        x = y = (N >> 1) - 1;
        for (int K = 2; K < N; K += 2) {
            for (int dir = 0; dir < 4; ++dir) {
                for (int k = 0; k < K; ++k) {
                    x += dx[dir], y += dy[dir];
                    if (!b[y][x]) continue;

                    if (!V.empty() && b[y][x] == V.back().first) V.back().second++;
                    else {
                        // 새로운 구슬 삽입, back의 개수가 4이상이면 pop, 한 번 더 확인
                        if (!V.empty() && V.back().second > 3) {
                            ANS += V.back().first * V.back().second; V.pop_back();

                            if (!V.empty() && b[y][x] == V.back().first) V.back().second++;
                            else V.push_back({ b[y][x],1 });
                        }
                        else V.push_back({ b[y][x],1 });
                    }
                }
            }
            --x, --y; //↖로 이동
        }

        // Rearrange
        int vsize = V.size(), vi = 0;
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

 /*     printf("\nRearrange Done:\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) printf("%d ", b[i][j]);
            printf("\n");
        }*/
    }
    printf("%d", ANS); return 0;
}