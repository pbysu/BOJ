#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define even 1
#define odd 0
using namespace std;
int n, m, k;
typedef pair<pair<int, int>, int> pii;
queue <pii> q;
int dr[] = { 1,-1,1,-1 };
int dc[] = { 1,1,-1,-1 };
int check[1001][1001][2];
int oddCnt, evenCnt;
int total = 0;
int main() {
	memset(check, -1, sizeof(check));
	scanf("%d %d %d", &n, &m, &k);
	for (int r, c, i = 0; i < k; i++) {
		scanf("%d %d", &r, &c);
		q.push({ {r,c}, odd});
		check[r][c][odd] = odd;
		oddCnt++;
	}
	total = n*m;
	bool jd = false;
	int x = 0;
	while (q.size()) {
		x++;
		int siz = q.size();
		for (int i = 0; i < siz; i++) {
			int r = q.front().first.first;
			int c = q.front().first.second;
			int cur = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int tr = r + dr[j];
				int tc = c + dc[j];
				int tcur = cur ? 0 : 1;
				if (tr >= 1 && tr <= n && tc >= 1 && tc <= m && check[tr][tc][tcur] != tcur) {
					check[tr][tc][tcur] = tcur;
					if (tcur == even) evenCnt++;
					else oddCnt++;
					q.push({ {tr,tc}, tcur});
				}
			}
		}
	}
	if (evenCnt==total || oddCnt==total)
		printf("YES");
	else
		printf("NO");

	return 0;
}