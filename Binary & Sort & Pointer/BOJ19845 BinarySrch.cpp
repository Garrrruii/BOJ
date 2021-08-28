#include <iostream>
using namespace std;
/*	가로 10^9칸, 세로 N칸 (x,y)
	넴모들은 붙어있는 걸 좋아하기 때문에 (1,y)~(ay,y)
	중력 영향 받음 */
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q, a[250001];
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> a[i]; //i층에 i마리 넴모
	
	int x, y;
	while (Q--) {
		cin >> x >> y;
		// (x,y)에 레이저 설치, 몇 마리 넴모 제거 가능?
		// y층부터 위로 몇층까지 넴모가 있나 => 이분탐색
		// y층에 x부터 오른쪽까지 몇 개의 넴모가 있나 => a[y],x 비교

		if (a[y] < x) cout << "0\n";
		else {
			//  L=(y+L-y)					세로: y부터 L까지
			//  ...                  
			//  y,x  ... a[y]=(x+a[y]-x)	가로: x부터 a[y]까지
			
			int L = y, R = N, mid;
			while (L < R) {
				mid = (L + R + 1) >> 1;
				if (a[mid] >= x) L = mid; //mid층 x에 넴모 있음
				else R = mid - 1;
			}
			cout << a[y] - x + L - y + 1 << "\n";
		}
	}
	return 0;
}
