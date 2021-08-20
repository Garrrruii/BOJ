//Alter
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long DIV = 1000000007;
	long long prv[5002] = { 0, }, cur[5002] = { 0, };
	int N, tmp;
	scanf("%d", &N);

	//ù ��° ����� 0 �ʰ� => �Ұ���
	scanf("%d", &tmp);
	if (tmp > 0) { printf("0"); return 0; }

	//0��° ��� ���� 0, ����� �� 1��
	prv[0] = 1;						
	for (int i = 1; i < N; ++i) {
		//i��° ��ܿ� ���Ͽ�
		scanf("%d", &tmp);
		if (tmp < 0) {				//������� => ���� h�� ����� �� ��� ����
			cur[0] = (prv[0] + prv[1]) % DIV;
			for (int h = 1; h <= min(N - i - 1, i); ++h) {
				cur[h] = (prv[h - 1] + (prv[h] + prv[h + 1]) % DIV) % DIV;
			}
		}							//���� tmp => ���� tmp�� ����� ���� ����
		else if (!tmp) cur[0] = (prv[0] + prv[1]) % DIV;
		else cur[tmp] = (prv[tmp - 1] + (prv[tmp] + prv[tmp + 1]) % DIV) % DIV;


		//i+1��° ��� ���� �ʱ�ȭ
		for (int h = 0; h < 5002; ++h) prv[h] = cur[h];
		for (int h = 0; h < 5002; ++h) cur[h] = 0;
	}
	//������ ����� ���̰� 0�� ����� ���� ���
	printf("%lld", prv[0]); return 0;
}