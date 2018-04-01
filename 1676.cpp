#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int func(int num) {
	int ret = 0;
	if (num < 5)
		return 0;
	if (num % 5 != 0)
		return func(num - 1);
	int tmp = num;
	while (tmp%5== 0) {
		ret++;
		tmp /= 5;
	}
	ret += func(num - 5);
	return ret;
}
int main() {
	scanf("%d", &n);
	printf("%d", func(n));
	return 0;
}