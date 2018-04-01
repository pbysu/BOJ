#include<stdio.h>
struct {int first, second;}edge[200010];
typedef long long ll;
ll cnt;
int n, u, v, pos = 2;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d %d", &edge[i].first, &edge[i].second);
		++edge[i].first;
		++edge[i].second;
	}
	scanf("%lld", &cnt);
	while (1) {
		if (!edge[pos].first&& !edge[pos].second)break;
		else if (!edge[pos].first)pos = edge[pos].second;
		else if (!edge[pos].second)pos = edge[pos].first;
		else if (cnt & 1) pos = edge[pos].first,cnt = (cnt >> 1) + 1;
		else pos = edge[pos].second,cnt >>= 1;
	}
	printf("%d", pos-1);
	return 0;
}