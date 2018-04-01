#include<iostream>
using namespace std;
int tmp;
int main() {
	int ans = 0;
	int x = 35238532;
	for (int i = 0; i < 7; i++){
		scanf("%d", &tmp);
		if (tmp % 2) {
			ans += tmp;
			x = x > tmp ? tmp : x;
		}
	}
	if (ans == 0)
		printf("-1");
	else
		printf("%d\n%d", ans, x);

	return 0;
}