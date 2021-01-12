// teenager shark
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//물고기는 번호가 작은 순서부터 이동한다.
//이동가능: 빈칸, 다른물고기 있는 칸, 다른 물고기랑 위치 바꿈
//이동불가: 상어, 공간 경계
//방향이 이동할 수 있는 칸을 향할때까지 45도 반시계 회전, 없으면 이동X

//물고기 이동 끝 -> 상어 이동, 방향에 있는 칸으로, 한 번에 여러 개 칸
//물고기 있는 칸 -> 먹고 방향을 물고기 방향으로 바꿈
//지나가는 칸의 물고기는 먹지 않는다.
//물고기 없는 칸으로 못 움직인다
//이동할 수 있는 칸 없으면 집으로

int N, ANS = 0;
int sy = 0, sx = 0, dir = 0;
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
char debug[9] = { '0','^','2','<','4','_','6','>','8' };
struct input {
	int m[4][4];
};

void play(input M, vector<pair<int,pair<int,int>>> F,int SUM,int cnt) {

	for (int i = 1; i < 17; i++) {
		if (!F[i].first) continue;
		int d = F[i].first;
		int y = F[i].second.first;
		int x = F[i].second.second;
		int tar = 0;
		while (1) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx < 0 || nx>3 || ny < 0 || ny>3 || M.m[ny][nx] < 0) { 
				d = (d == 8) ? 1 : d + 1; continue;
			}
			
			tar = M.m[ny][nx];
			F[i] = { d,{ny,nx} }; M.m[ny][nx] = i; break;
		}
		if(tar>0) F[tar].second = { y,x };
		M.m[y][x] = tar;
	}/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; ++j) {
			if (M.m[i][j] == -1) printf("-1 %c  ", debug[F[0].first]);
			else if (M.m[i][j] == 0) printf(" 0 0  ");
			else printf("%2d %c  ", M.m[i][j], debug[F[M.m[i][j]].first]);
		}
		printf("\n");
	}*/
	
	int sd = F[0].first;
	int sy = F[0].second.first;
	int sx = F[0].second.second;
	int ny = sy, nx = sx;
	while (1) {
		ny += dy[sd]; nx += dx[sd];
		if (nx < 0 || nx>3 || ny < 0 || ny>3) {
			ANS = max(ANS, SUM); return;
		}

		int tarnum = M.m[ny][nx];
		if (tarnum == 0) continue;
		F[0] = F[tarnum];		 M.m[ny][nx] = -1; 
		F[tarnum] = { 0,{0,0} }; M.m[sy][sx] = 0;
		
		//printf("%d) eat %d\n\n", cnt,tarnum);
		play(M, F, SUM + tarnum, cnt + 1);

		F[tarnum] = F[0];		M.m[ny][nx] = tarnum;
		F[0] = { sd,{sy,sx} };	M.m[sy][sx] = -1;
	}
}
int main() {
	vector<pair<int, pair<int, int>>> fish(17);
	input map;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int tmp1, tmp2;
			scanf("%d%d", &tmp1, &tmp2);
			fish[tmp1] = { tmp2, {i,j} }; map.m[i][j] = tmp1;
		}
	}

	int tarnum = map.m[0][0]; 
	fish[0] = fish[tarnum]; map.m[0][0] = -1;
	fish[tarnum] = { 0,{0,0} }; 

	play(map,fish,tarnum,1);
	printf("%d\n", ANS); return 0;

}
