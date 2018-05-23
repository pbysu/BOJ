#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, m;
typedef pair<int, int> pii;
pii pos[2];
pii target;
char arr[11][11];
int dr[] = { 0,0, 1,-1 };
int dc[] = { 1,-1,0,0 };
// 우, 좌,아래,위

int func(pii r, pii b, int dep, int ex) {
	if (dep > 11) return INF;
	if (b.first == target.first && b.second == target.second) {
		return INF;
	}
	if (r.first == target.first && r.second == target.second) {
		bool jd = true;		
		while (jd) {
			if (b.first == target.first && b.second == target.second) {
				return INF;
			}
			jd = false;
			b.first += dr[ex];
			b.second += dc[ex];
			if (b.first >= 0 && b.first < n && b.second >= 0 && b.second < m
				&& arr[b.first][b.second] == '.') {
				jd = true;
			}
		}
		return dep - 1;
	}
	int ret = INF;
	for (int i = 0; i < 4; i++) {
		int fp;
		if (i == 0) fp = r.second >= b.second ? 0 : 1;
		else if (i == 1) fp = r.second <= b.second ? 0 : 1;
		else if (i == 2) fp = r.first >= b.first ? 0 : 1;
		else if (i == 3) fp = r.first <= b.first ? 0 : 1;
		pii next, next1;
		if (fp == 0) next = r, next1 = b;
		else next = b, next1 = r;
		bool move = false;
		while (1) {
			next.first += dr[i];
			next.second += dc[i];
			if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m
				&& arr[next.first][next.second] == '.') {
				move = true;
				if (next.first == target.first && next.second == target.second) {
					break;
				}
			}
			else {
				next.first -= dr[i];
				next.second -= dc[i];
				break;
			}
		}
		while (1) {
			next1.first += dr[i];
			next1.second += dc[i];
			if (next1.first >= 0 && next1.first < n &&  next1.second>0 && next1.second < m
				&& arr[next1.first][next1.second] == '.'
				&& (next1.first != next.first || next1.second != next.second)) {
				move = true;
				if (next1.first == target.first && next1.second == target.second) break;
			}
			else {
				next1.first -= dr[i];
				next1.second -= dc[i];
				break;
			}
		}
		if (!move) continue;
		if (fp == 0)
			ret = min(ret, func(next, next1, dep + 1,i));
		else
			ret = min(ret, func(next1, next, dep + 1,i));
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'R')
				pos[0].first = i, pos[0].second = j, arr[i][j] = '.';
			else if (arr[i][j] == 'B')
				pos[1].first = i, pos[1].second = j, arr[i][j] = '.';
			else if (arr[i][j] == 'O')
				target.first = i, target.second = j, arr[i][j] = '.';
		}
	}
	int ans = func(pos[0], pos[1], 1,0);
	printf("%d", ans == INF ? -1 : ans);
	return 0;
}