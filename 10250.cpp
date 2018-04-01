#include<iostream>
#include<algorithm>

using namespace std;
int tc;
int h, w,n;
int x, y;
int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d %d", &h, &w, &n);
		y = n % h;
		if (y == 0) y = h;
		printf("%d", y);

		x = n / h;

		if (n %h!=0)
			x= x + 1;

		if (x < 10)
			printf("0%d\n", x);
		else
			printf("%d\n", x);
	}

	return 0;
}