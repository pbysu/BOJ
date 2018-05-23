#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m, c;
int left = 1;
int right;
bool visited[220][22][22][22];
typedef pair<int, int> pii;
queue<pair<int, pii>> q;
int main() {
	scanf("%d %d", &n, &m);
	right = m;
	int tc = 0;
	q.push({ 0,{ left,right } });
	int minimum;
	int sibal;
	scanf("%d", &sibal);
	while ( sibal--) {
		scanf("%d", &c);
		minimum = 987654321;
		int sz = q.size();
		tc++;
		for (int i = 0; i < sz; i++) {
			int tl = q.front().second.first;
			int tr = q.front().second.second;
			int tcnt = q.front().first;
			q.pop();
			int ttl = c;
			int ttr = c+m-1;
			while (ttl<=c && ttr>=c) {
				if (ttr > n) {
					ttl--;
					ttr--;
					continue;
				}
				int ttcnt = tcnt + abs(ttl - tl);
				if (!visited[ttcnt][ttl][ttr][tc]) {
					q.push({ttcnt,{ ttl,ttr } });
					visited[ttcnt][ttl][ttr][tc] = true;
					minimum = min(ttcnt, minimum);
				}
				ttl--;
				ttr--;
			}
		}
	}

	printf("%d\n", minimum);
	return 0;
}