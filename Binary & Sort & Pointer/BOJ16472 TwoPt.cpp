#include <cstdio>
using namespace std;

char s[100001];
int main() {
	int N, cnt[26] = { 0, }, n = 0, ans = 0;
	
	scanf("%d", &N);
	scanf("%s", &s);

	int i = 0, j = 0;
	while (s[j] != '\0') {
		int cur = s[j] - 'a';
		
		if (!cnt[cur]) n++;
		cnt[cur]++;

		if (n > N) ans = (ans > j - i) ? ans : j - i;// , printf("%d-%d=%d, %d\n", j, i, j - i, ans);
		while (n > N) {
			int pre = s[i] - 'a';
			cnt[pre]--, i++;
			if (!cnt[pre]) n--;
		}
		j++;
	}
	if (n <= N) ans = (ans > j - i) ? ans : j - i;// , printf("%d-%d=%d, %d\n", j, i, j - i, ans);
	printf("%d", ans); return 0;
}