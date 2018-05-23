#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int  n, m;
int save[2020][2020];
int par[100010];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

struct Pos {
	int r, c;
	Pos(int r, int c) : r(r), c(c) {}
	Pos() { r = c = 0; }
};
queue<Pos> q;
int find(int a) {
	if (par[a] == 0)return a;
	return par[a] = find(par[a]);
}
int sum = 1;
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[a] = find(b);
		sum++;
		return true;
	}
	else {
		return false;
	}
}
int solve() {
	int sz;
	int ret = 0;
	while (!q.empty()) {
		sz = q.size();
		ret++;
		for (int i = 0; i < sz; i++) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int tr = r + dr[j];
				int tc = c + dc[j];
				if (tr > 0 && tr <= n && tc > 0 && tc <= n) {
					if (save[tr][tc] == 0) {
						save[tr][tc] = save[r][c];
						q.push({ tr,tc });
						for (int pic = 0; pic < 4; pic++) {
							int ttr = tr + dr[pic];
							int ttc = tc + dc[pic];
							if (ttr > 0 && ttr <= n && ttc > 0 && ttc <= n) {
								if (save[ttr][ttc] != 0 && save[ttr][ttc] != save[tr][tc]) {
									merge(save[ttr][ttc], save[tr][tc]);
									if (sum == m)
										return ret;
								}
							}
						}
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	int cnt = 1;
	for (int r, c, i = 0; i < m; i++) {
		scanf("%d %d", &r, &c);
		save[r][c] = cnt++;
		for (int j = 0; j < 4; j++) {
			int tr = r + dr[j];
			int tc = c + dc[j];
			if (tc >= 1 && tc <= n && tr > 0 && tr <= n) {
				if (save[tr][tc] != 0) {
					merge(save[r][c], save[tr][tc]);
				}
			}
		}
		if (sum == m) {
			printf("0");
			return 0;
		}
		if (!save[r][c]) save[r][c] = cnt++;
		q.push({ r,c });
	}
	printf("%d\n", solve());
	return 0;
}