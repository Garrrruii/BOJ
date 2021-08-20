#include <cstdio>
using namespace std;

int K, X, Y;
int T[128][128];
int num = 0;

bool Rec(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++)
            if (T[i][j] != 0) return false;
    }
    return true;
}
void Tile(int x, int y, int n) {
    n >>= 1; ++num;
    if (Rec(x, y, n)) T[x + n - 1][y + n - 1] = num;
    if (Rec(x, y + n, n)) T[x + n - 1][y + n] = num;
    if (Rec(x + n, y, n)) T[x + n][y + n - 1] = num;
    if (Rec(x + n, y + n, n)) T[x + n][y + n] = num;
    if (n == 1) return;

    Tile(x, y, n);
    Tile(x + n, y, n);
    Tile(x, y + n, n);
    Tile(x + n, y + n, n);
}
int main() {
    scanf("%d%d%d", &K, &X, &Y);
    int N = 1 << K;

    T[Y - 1][X - 1] = -1;
    Tile(0, 0, N);

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) printf("%2d ", T[i][j]);
        printf("\n");
    }
    return 0;
}