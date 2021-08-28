#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/*	N명 학생, 최대 각자 M개 블록
	바닥에서부터 쌓아올려 탑을 만들고자한다
	높이가 정확히 H인 탑을 만들 수 있는 경우의 수
	학생당 최대 1개의 블록*/

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string line, buf;
	int N, M, H;
	cin >> N >> M >> H; getline(cin, line);

	int dp[1001][2] = { 0, }, prv = 0, cur = 1, h;
	dp[0][prv] = dp[0][cur] = 1;//H=0인 경우는 한 가지밖에 없다.
	for (int i = 0, j = 0; i < N; ++i, j = 0) {
		getline(cin, line);
		istringstream ss(line);
		
		//dp[H][N]도 괜찮지만
		//dp[H][2]로도 가능. 입력 받으면서 해결.
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