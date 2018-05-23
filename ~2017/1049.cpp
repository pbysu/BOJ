#include<cstdio>

struct {
	int group;
	int one;
}s[51];
int n, m, o, g, mg;
int main() {
	scanf("%d %d", &n, &m);
	o = 987654321;
	g = 987654321;
	mg = 987654321;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s[i].group, &s[i].one);
		g = g <= s[i].group ? g : s[i].group;
		o = o <= s[i].one ? o : s[i].one;
	}
	int k;
	if (n % 6 == 0) k = g*(n/6);
	else k = g*((n/6) + 1);
	int ans = g*(n / 6) + o*(n % 6);
	ans = k < ans ? k : ans;
	ans = ans > o*n ? o*n : ans;
	printf("%d", ans);
	return 0;
}