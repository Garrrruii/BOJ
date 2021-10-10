#include <iostream>
using namespace std;
char b[5][6];
bool som[5][5];
bool vis[5][5];
pair<int, int> a[7];
int frt, bck;
int bf(int i, int j, int k, int s) {
	if (i > 4) return 0;

	int ni, nj, ret = 0;
	if (j & 4) ni = i + 1, nj = 0;
	else ni = i, nj = j + 1;

	//i,j�� �� ��
	som[i][j] = true;
	if (k < 6) {
		ret += bf(ni, nj, k + 1, s + (b[i][j] == 'S' ? 1 : 0));
	}
	else {
		//������ �л��� ���, �پ��ִ��� Ȯ��
		for (int y = 0; y < 5; ++y) 
			for (int x = 0; x < 5; ++x) vis[y][x] = false;

		a[0] = { i,j }, vis[i][j]=true, frt = 0, bck = 1;
		while (frt < bck) {
			int y = a[frt].first;
			int x = a[frt].second; frt++;

			if (y && som[y - 1][x] && !vis[y - 1][x])
				vis[y - 1][x] = true, a[bck++] = { y - 1,x };
			if (y < 4 && som[y + 1][x] && !vis[y + 1][x])
				vis[y + 1][x] = true, a[bck++] = { y + 1,x };
			if (x && som[y][x - 1] && !vis[y][x - 1])
				vis[y][x - 1] = true, a[bck++] = { y,x - 1 };
			if (x < 4 && som[y][x + 1] && !vis[y][x + 1])
				vis[y][x + 1] = true, a[bck++] = { y,x + 1 };
		}
		//�پ��ְ� �̴ټ��İ� 4�� �̻� => +1		
		if (bck > 6 && s + (b[i][j] == 'S' ? 1 : 0) > 3) ret++;
	}
	som[i][j] = false;

	//�� �� ��
	ret += bf(ni, nj, k, s);

	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//7���� ������ �л�, �̴ټ��� �ּ� 4��
	//ĥ���ָ� �Ἲ�� �� �ִ� ����� ��?
	for (int i = 0; i < 5; ++i) cin >> b[i];

	cout << bf(0,0,0,0); return 0;
}
/*
YYYYY
SYSYS
YYYYY
YSYYS
YYYYY
2
*/