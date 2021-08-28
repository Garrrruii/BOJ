#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/*	N�� �л�, �ִ� ���� M�� ���
	�ٴڿ������� �׾ƿ÷� ž�� ��������Ѵ�
	���̰� ��Ȯ�� H�� ž�� ���� �� �ִ� ����� ��
	�л��� �ִ� 1���� ���*/

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string line, buf;
	int N, M, H;
	cin >> N >> M >> H; getline(cin, line);

	int dp[1001][2] = { 0, }, prv = 0, cur = 1, h;
	dp[0][prv] = dp[0][cur] = 1;//H=0�� ���� �� �����ۿ� ����.
	for (int i = 0, j = 0; i < N; ++i, j = 0) {
		getline(cin, line);
		istringstream ss(line);
		
		//dp[H][N]�� ��������
		//dp[H][2]�ε� ����. �Է� �����鼭 �ذ�.
		while (getline(ss, buf, ' ')) {
			h = atoi(buf.c_str());

			for (int k = 0; k <= H; ++k) {
				if (k + h <= H) dp[k + h][cur] += (dp[k][prv] % 10007);
			}
		}

		for (int k = 0; k <= H; ++k) dp[k][prv] = dp[k][cur];
		prv ^= 1, cur ^= 1;
	}

	cout << dp[H][cur] % 10007; return 0;
}