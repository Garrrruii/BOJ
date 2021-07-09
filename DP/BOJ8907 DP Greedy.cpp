#include <cstdio>
using namespace std;

int main() {
	int red[1001];
	int T, N, ANS, tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		
		ANS = N * (N - 1) * (N - 2) / 3;
		for (int i = 0; i < N; ++i) red[i] = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				scanf("%d", &tmp);
				red[i] += tmp;
				red[j] += tmp;
			}
		}
		
		//red[i]	: i�� ����� ���� ������ ��
		//N-1-red[i]: i�� ����� �Ķ� ������ ��
		// *		: i�� ���������� �ϰ� �ش����� �ʴ� �ﰢ�� ��
		//�� ���ϸ� : �� �ش����� �ʴ� �ﰢ�� �� * 2
		//���� ANS	: �� �ﰢ�� �� * 2
		
		for (int i = 0; i < N; ++i) ANS -= red[i] * (N - 1 - red[i]);
		printf("%d\n", ANS >> 1);
	}
	return 0;
}
/* ��Ž => �翬�� �ð��ʰ���
int dp[1000][1000][2];
int e[1000];

	scanf("%d", &N);
	ANS = 0;
	for (int i = 1; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) dp[i][j][0] = dp[i][j][1] = 0;
	}
	for (int a = 0; a < N - 1; ++a) {
		for (int b = a + 1; b < N; ++b) {
			scanf("%d", &tmp); e[b] = tmp;
			ANS += dp[a][b][tmp];
			for (int c = a + 1; c < b; ++c) {
				if (tmp == e[c]) dp[c][b][tmp]++;
			}
		}
	}
	printf("%d\n", ANS);
*/