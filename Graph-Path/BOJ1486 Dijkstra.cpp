#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
struct pqsort {
    bool operator()(pii A, pii B) {
        return A.second < B.second; //남은 시간이 많은 순
    }
};
priority_queue<pii, vector<pii>, pqsort> pq;
int main() {
    int dy[4] = { 0,0,1,-1 };
    int dx[4] = { 1,-1,0,0 };

    int N, M, T, D, m[25][25], up[25][25], dn[25][25];
    char tmp[26];

    scanf("%d%d%d%d", &N, &M, &T, &D);
    for (int i = 0; i < N; ++i) {
        scanf("%s", &tmp);
        for (int j = 0; j < M; ++j) {
            if ('A' <= tmp[j] && tmp[j] <= 'Z') m[i][j] = tmp[j] - 'A';
            else m[i][j] = tmp[j] - 'a' + 26;
        }
    }
    int ANS = 0, x, y, t, ny, nx, nt, here;

    //go up
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) up[i][j] = -1;
    };
    pq.push({ 0,D }); up[0][0] = D;
    while (!pq.empty()) {
        y = pq.top().first / 25;
        x = pq.top().first % 25;
        t = pq.top().second; pq.pop();
        if (t < up[y][x]) continue;
        
        here = m[y][x];
        for (int d = 0; d < 4; ++d) {
            ny = y + dy[d];
            nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            int diff = m[ny][nx] - here;
            
            if (-T <= diff && diff <= 0) nt = t - 1;
            else if (0 < diff && diff <= T) nt = t - diff * diff;
            else continue;
            if (nt > up[ny][nx]) up[ny][nx] = nt, pq.push({ ny * 25 + nx,nt });
        }
    }

    //go down
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) dn[i][j] = -D;
    };
    pq.push({ 0,0 }); dn[0][0] = 0;
    while (!pq.empty()) {
        y = pq.top().first / 25;
        x = pq.top().first % 25;
        t = pq.top().second; pq.pop();
        if (t < dn[y][x]) continue;

        here = m[y][x];
        for (int d = 0; d < 4; ++d) {
            ny = y + dy[d];
            nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            int diff = m[ny][nx] - here;

            if (-T <= diff && diff < 0) nt = t - diff * diff;
            else if (0 <= diff && diff <= T) nt = t - 1 ;
            else continue;
            if (nt > dn[ny][nx]) dn[ny][nx] = nt, pq.push({ ny * 25 + nx,nt });
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) if (up[i][j] + dn[i][j] >= 0 && ANS < m[i][j]) ANS = m[i][j];
    }
    printf("%d\n", ANS);

    return 0;
}
/*  for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) printf("%2d(%2d/%2d) ", m[i][j], up[i][j], dn[i][j]);
        printf("\n");
    }
*/