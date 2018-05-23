#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int tc, n, m;
	int u, v;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
		}
		printf("%d\n",n - 1);

	}
	return 0;
}