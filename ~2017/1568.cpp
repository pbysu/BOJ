#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int num;
ull t, right, left, mid, ans;
ull sum(ull temp) {
	return (temp)*(temp + 1) / 2;
}
int main() {
	scanf("%llu", &num);
	ans = 0;
	while (num != 0) {
		right = num;
		left = 0;
		t = 0;
		while (left <= right) {
			mid = (left + right) >> 1;
			t = sum(mid);
			if (t > num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		ans += right;
		num -= sum(right);
	}
	printf("%llu\n", ans);
	return 0;
}