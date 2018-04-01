#include<cstdio>
#include<algorithm>
using namespace std;
long long x, y;
int main() {
	//freopen("input.txt", "r", stdin);
	while (scanf("%lld %lld", &x, &y) != EOF) {
		long long init = (y * 100) / x;
		if (init >= 99) {
			printf("-1\n");
			continue;
		}
		int left = 0;
		int right = 2000000001;
		int mid = 0;
		long long tmp;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (((y + mid) * 100) / (x + mid) > init) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}


		printf("%d\n", left);

	}

	return 0;
}