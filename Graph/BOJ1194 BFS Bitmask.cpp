#include <cstdio>
#include <queue>
using namespace std;
/*	���簢�� ��� �̷�
	.   �̵� O
	#   �̵� X
	a-f ����
	A-F ��
	0   ���� ��ġ
	1   �ⱸ
	�ν��̰� �̷θ� Ż���ϴ� �� �ɸ��� �̵�Ƚ���� �ּڰ�? => BFS
	(�ν� ��ġ, ���� �ִ� ����)
*/
struct node {
	int y, x, key;
};
queue<node> Q;
bool vis[50][50][1 << 7];

int main() {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	char b[50][51];
	int N, M;

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &b[i]);
		if (Q.empty()) {
			for (int j = 0; j < M; ++j) {
				if (b[i][j] == '0') Q.push({ i,j, 0 }), vis[i][j][0] = true;
			}
		}
	}

	int qsize = 1, CNT = 0;
	while (qsize) {
		CNT++;
		while (qsize--) {
			int y = Q.front().y;
			int x = Q.front().x;
			int k = Q.front().key; Q.pop();
			
			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				if (nx < 0 || nx >= M) continue;
				int ny = y + dy[d];
				if (ny < 0 || ny >= N || b[ny][nx] == '#') continue;

				if (b[ny][nx] == '1') { printf("%d", CNT); return 0; }

				// 1. ����
				if ('a' <= b[ny][nx] && b[ny][nx] <= 'f') {
					int nk = k | (1 << (b[ny][nx] - 'a'));
					if (!vis[ny][nx][nk]) Q.push({ ny,nx,nk }), vis[ny][nx][nk] = true;
				}
				// 2. ��
				else if ('A' <= b[ny][nx] && b[ny][nx] <= 'F') {
					if (k & (1 << (b[ny][nx] - 'A')) && !vis[ny][nx][k]) Q.push({ ny,nx,k }), vis[ny][nx][k] = true;
				}
				// 3. 0 or .
				else if (!vis[ny][nx][k]) Q.push({ ny,nx,k }), vis[ny][nx][k] = true;
			}
		}
		qsize = Q.size();
	}
	printf("-1"); return 0;
}