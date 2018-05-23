#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int u, v, i = 0; i < n; i++) {
		scanf("%d %d", &u, &v);
		ans += u*v;
	}
	printf("%d", ans);
	return 0;
}