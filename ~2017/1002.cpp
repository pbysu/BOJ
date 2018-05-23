#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double r = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		int maxR = max(r1, r2);
		int minR = min(r1, r2);
		double sum = (double)(r1 + r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)printf("%d\n", -1);
			else printf("%d\n", 0);
		}
		else {
			if (r <= double(maxR)) {
				if (r + double(minR) >double(maxR))printf("%d\n", 2);
				else if (r + double(minR) < double(maxR))printf("%d\n", 0);
				else printf("%d\n", 1);
			}

			else {
				if (r > sum)printf("%d\n", 0);
				else if (r == sum)printf("%d\n", 1);
				else  printf("%d\n", 2);
			}
		}
	}

	return 0;
}