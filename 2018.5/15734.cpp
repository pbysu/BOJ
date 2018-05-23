#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int l, r, a;
	scanf("%d %d %d", &l, &r, &a);
	while (a > 0) {
		if (l > r)r++;
		else if (l < r) l++;
		else break;
		a--;
	}
	if (l != r) {
		printf("%d", min(l, r) * 2);
		return 0;
	}
	a /= 2;

	printf("%d", l + r + 2 * a);
}