#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	if (n != 3) {
		printf("Woof-meow-tweet-squeek");
		return 0;
	}
	for (int u,v, i = 0; i < n; i++) {
		scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);

		if (!((u == 1 && v == 3) || (u == 1 && v == 4) || (u == 3 && v == 4))) {
			printf("Woof-meow-tweet-squeek");
			return 0;
		}
	}
	printf("Wa-pa-pa-pa-pa-pa-pow!");
	return 0;
}