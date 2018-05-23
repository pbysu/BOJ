#include<cstdio>
#include<queue>
#include <cstring>
using namespace std;
int t, n, r, c, er, ec;
bool visited[301][301];
int dr[] = { 1,2,2,1, -1,-2,-2,-1 };
int dc[] = { 2,1,-1,-2,-2,-1,1,2 };
typedef pair<int, int> pii;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(visited, false, sizeof(visited));
		queue<pii> q;
		scanf("%d%d%d%d", &r, &c, &er, &ec);

		q.push({ r,c });
		visited[r][c] = true;
		if (r == er && c == ec) {
			printf("0\n");
			continue;
		}
		int cnt = 0;
		bool jd = false;
		while (!q.empty()) {
			int sz = q.size();
			cnt++;

			for (int k = 0; k < sz; k++) {
				int tr = q.front().first;
				int tc = q.front().second;
				q.pop();
				for (int i = 0; i < 8; i++) {
					int ttr = tr + dr[i];
					int ttc = tc + dc[i];
					if (ttr >= 0 && ttr < n &&ttc>=0 && ttc < n && !visited[ttr][ttc]) {
						if (ttr == er && ttc == ec) {
							jd = true;
							break;
						}
						visited[ttr][ttc] = true;
						q.push({ ttr,ttc });
					}
				}
				if (jd)
					break;
			}
			if (jd)
				break;
		}

		printf("%d\n", cnt);
	}


	return 0;
}