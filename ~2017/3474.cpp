#include<iostream>
using namespace std;
int t, tmp, ans;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &tmp);
		ans = 0;
		int num = tmp;
		while (tmp) {
			ans += tmp / 5;
			tmp /= 5;
		};
		printf("%d\n", ans);
	}
	return 0;
}