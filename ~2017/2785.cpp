#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>>pq;

int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp); pq.push(tmp);
	}
	int siz, cur, gori = 0;
	while (1) {
		siz = pq.size();
		if (gori < siz - 1) {
			cur = pq.top();
			if (cur + gori <= siz - 2) {
				gori += cur;
				pq.pop();
			}
			else {
				gori = siz - 1;
			}
		}
		else
			break;
	}
	printf("%d", gori);
}