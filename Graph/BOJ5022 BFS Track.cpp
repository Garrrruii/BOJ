#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool vis[101][101];
int dir[101][101];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }; //0-1 2-3

int bfs(int x1, int y1, int x2, int y2) {
    // i,j에 도착한 방향 설정
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) dir[i][j] = -1;
    queue<pair<int, int>> Q;
    Q.push({ x1,y1 }); dir[x1][y1] = 5;
    
    int x, y, nx, ny;
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second; Q.pop();
        
        for (int d = 0; d < 4; ++d) {
            nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || dir[nx][ny] >= 0) continue;
            //앞에서 방문한 경로이거나 이번에 방문한 지점이면 continue

            dir[nx][ny] = d;
            if (nx == x2 && ny == y2) {
                //도착한 경우 현재 방문 표시 후 tracking
                vis[nx][ny] = true;
                int len = 0, d;
                while (dir[nx][ny] < 4) {
                    int d = dir[nx][ny];
                    nx -= dx[d], ny -= dy[d];
                    vis[nx][ny] = true, len++;
                }
                //tracking으로 방문 후 출발지에 도달하면 거리 return
                return len;
            }
            Q.push({ nx,ny });
        }
    }
    return 1000;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M; N++, M++;
    int x[4], y[4];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    cin >> x[2] >> y[2] >> x[3] >> y[3];
    int ANS = 1000;

    // B표시 후 A 탐색, B표시 해제 후 B 탐색
    for (int k = 2; k < 4; ++k) vis[x[k]][y[k]] = true;
    int tmp = bfs(x[0], y[0], x[1], y[1]);
    for (int k = 2; k < 4; ++k) vis[x[k]][y[k]] = false;
    tmp += bfs(x[2], y[2], x[3], y[3]);
    if (tmp < ANS) ANS = tmp;

    // A표시 후 B 탐색, A표시 해제 후 A 탐색
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) vis[i][j] = false;
    for (int k = 0; k < 2; ++k) vis[x[k]][y[k]] = true;
    tmp = bfs(x[2], y[2], x[3], y[3]);
    for (int k = 0; k < 2; ++k) vis[x[k]][y[k]] = false;
    tmp += bfs(x[0], y[0], x[1], y[1]);
    if (tmp < ANS) ANS = tmp;

    // Print
    if (ANS < 1000) cout << ANS;
    else cout << "IMPOSSIBLE";

    return 0;
}
