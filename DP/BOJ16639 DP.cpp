//adding parentheses 3
//16637~9 series
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;


int maxdp[10][10], mindp[10][10];

int main(void) { 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	string f;

	cin >> N; cin >> f; M = N / 2 + 1;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			maxdp[i][j] = INT_MIN; mindp[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < M; i++) maxdp[i][i] = mindp[i][i] = f[i * 2] - '0';
	
	for (int k = 1; k < M; ++k) { 
		for (int i = 0; i < M - k; ++i) { //calculate max.min i~k(=i+k) by i~a,b(=a+1)~j
			int j = i + k;
			for (int t = 1; t <= k; ++t) {
				int a = i + t - 1;
				int b = i + t;
				char op = f[a * 2 + 1];
				int res[4];
				
				if (op == '+') {
					res[0] = maxdp[i][a] + maxdp[b][j], res[1] = maxdp[i][a] + mindp[b][j];
					res[2] = mindp[i][a] + maxdp[b][j], res[3] = mindp[i][a] + mindp[b][j];
				}
				else if (op == '-') {
					res[0] = maxdp[i][a] - maxdp[b][j], res[1] = maxdp[i][a] - mindp[b][j];
					res[2] = mindp[i][a] - maxdp[b][j], res[3] = mindp[i][a] - mindp[b][j];
				}
				else {
					res[0] = maxdp[i][a] * maxdp[b][j], res[1] = maxdp[i][a] * mindp[b][j];
					res[2] = mindp[i][a] * maxdp[b][j], res[3] = mindp[i][a] * mindp[b][j];
				}
				sort(res, res + 4);

				maxdp[i][j] = max(maxdp[i][i + k], res[3]);
				mindp[i][j] = min(mindp[i][i + k], res[0]); 
			}
		}	
	} 

	cout << maxdp[0][M - 1] << "\n";  return 0;
}
