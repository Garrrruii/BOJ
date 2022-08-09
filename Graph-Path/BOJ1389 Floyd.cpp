#include <iostream>
using namespace std;

int N;
int M;
int friendDegree[101][101] = { 0, };

void processInputValue() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			friendDegree[i][j] = 0;
		}
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		friendDegree[a][b] = friendDegree[b][a] = 1;
	}
}
void getFriendDegree() {
	//floyd warshall
	for (int k = 1; k <= N; ++k) {
		for (int a = 1; a <= N; ++a) {
			if (!friendDegree[a][k]) {
				continue;
			}

			for (int b = 1; b <= N; ++b) {
				if (!friendDegree[k][b]) {
					continue;
				}

				int newDegree = friendDegree[a][k] + friendDegree[k][b];
				int originalDegree = friendDegree[a][b];

				if (!originalDegree || originalDegree > newDegree) {
					friendDegree[a][b] = newDegree;
					friendDegree[b][a] = newDegree;
				}
			}
		}
	}
}
int getAnswer() {
	int answer = 0;
	int minKevinBaconDegree = 987654321;
	for (int i = 1; i <= N; ++i) {
		int thiskevinBaconDegree = 0;

		for (int j = 1; j <= N; ++j) {
			thiskevinBaconDegree += friendDegree[i][j];
		}

		if (minKevinBaconDegree > thiskevinBaconDegree) {
			minKevinBaconDegree = thiskevinBaconDegree;
			answer = i;
		}
	}

	return answer;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	processInputValue();

	getFriendDegree();

	cout << getAnswer();
	
	return 0;
}
