#include<cstdio>
#include<cstring>
#define INF 1e9
using namespace std;
int l, r, m, a, b, v;

bool check(int cur) { return cur + a >= v ? true : false; }
int main() {
	scanf("%d %d %d", &a, &b, &v);
	l = 1; r = v;
	while (l < r) {
		m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m+1;
	}
	int tmp = a- b;
	int ans = l / tmp;
	if (l%tmp) ans++;
	printf("%d", ans + 1);
	return 0;
}