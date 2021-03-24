//Changing the bus
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct bus {
    int x1, y1, x2, y2;
};
bus B[5001];

struct info {
    int s, e, n;    //start end num
};
vector<info> hor[100001], ver[100001];

int vis[5001], SX, SY, DX, DY;
queue<int> Q;
int bfs() {
    // STEP 1. 시작점을 포함하는 버스
    for (info b : ver[SX]) {
        if (b.s <= SY && SY <= b.e) vis[b.n] = 1, Q.push(b.n);
    }
    for (info b : hor[SY]) {
        if (b.s <= SX && SX <= b.e) vis[b.n] = 1, Q.push(b.n);
    }

    // STEP 2. BFS
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        int x1 = B[cur].x1, y1 = B[cur].y1;
        int x2 = B[cur].x2, y2 = B[cur].y2;

        if (y1 == y2) {
        //IF) Horizontal - 교차하는 Vertical or 겹치는 Horizontal
            if (y1 == DY && DX >= x1 && DX <= x2) return vis[cur];
            
            for (int x = x1; x <= x2; ++x)
                for (info b : ver[x]) {
                    if (vis[b.n] || y1 < b.s || y1 > b.e) continue;
                    
                    vis[b.n] = vis[cur] + 1; Q.push(b.n);
                }
            for (info b : hor[y1]) {
                if (vis[b.n] || x2 < b.s || x1 > b.e) continue;
                
                vis[b.n] = vis[cur] + 1; Q.push(b.n);
            }
        }
        else {          
        //IF) Horizontal - 교차하는 Horizontal or 겹치는 Vertical 
            if (x1 == DX && DY >= y1 && DY <= y2) return vis[cur];
            
            for (int y = y1; y <= y2; ++y) {
                for (info b : hor[y]) {
                    if (vis[b.n] || x1 < b.s || x1 > b.e) continue;

                    vis[b.n] = vis[cur] + 1; Q.push(b.n);
                }
            }
            for (info b : ver[x1]) {
                if (vis[b.n] || y2 < b.s || y1 > b.e) continue;

                vis[b.n] = vis[cur] + 1; Q.push(b.n);
            }
        }
    }
}
int main() {
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0, num, x1, y1, x2, y2; i < K; i++) {
        scanf("%d%d%d%d%d", &num, &x1, &y1, &x2, &y2);

        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        if (x1 == x2) ver[x1].push_back({ y1, y2, num });
        else if (y1 == y2) hor[y1].push_back({ x1, x2, num });

        B[num] = { x1, y1, x2, y2 };
    }
    scanf("%d%d%d%d", &SX, &SY, &DX, &DY);
    
    printf("%d", bfs());
    return 0;
}
