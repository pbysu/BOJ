#include<cstdio>
#define up 0
#define right 1
#define down 2
#define left 3
#define INF 1e9
using namespace std;
bool visited[501][501][4];
char in[501][501];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int n, m, r, c;
int func(int r, int c, int dir) {
	int ret = 0;
	visited[r][c][dir] = true;
	int tr = r + dr[dir];
	int tc = c + dc[dir];
	if (tr < n && tr >= 0 && tc >= 0 && tc < m) {
		if (in[tr][tc] == 'C')return ret;
		if (in[tr][tc] == '/') {
			if (dir == up) dir = right;
			else if (dir == right) dir = up;
			else if (dir == down) dir = left;
			else if (dir == left) dir = down;
		}
		else if (in[tr][tc] == '\\') {
			if (dir == up) dir = left;
			else if (dir == right) dir = down;
			else if (dir == down) dir = right;
			else if (dir == left) dir = up;
		}
		if (visited[tr][tc][dir] == true) {
			return INF;
		}
		ret = func(tr, tc, dir) + 1;
		visited[tr][tc][dir] = false;
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", in[i]);
	}
	scanf("%d %d", &r, &c);
	r--, c--;
	int ret = -1;
	int dir = -1;
	for (int i = 0; i < 4; i++) {
		int tmp = func(r, c, i) + 1;
		visited[r][c][i] = false;
		if (ret < tmp) {
			ret = tmp;
			dir = i;
		}
	}


	if (dir == 0) printf("U");
	else if (dir == 1) printf("R");
	else if (dir == 2)printf("D");
	else if (dir == 3)  printf("L");
	if (ret >= INF) {
		printf("\nVoyager\n");
	}
	else
		printf("\n%d", ret);

}